#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include "PathPlanner.hpp"

using namespace boost;

namespace asteroids
{

// heuristic for graph
template<class Graph, class CostType, class LocMap>
class distance_heuristic : public astar_heuristic<Graph, CostType>
{
public:
	typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
	distance_heuristic(LocMap l, Vertex goal) :
		m_location(l), m_goal(goal)
	{
	}
	CostType operator()(Vertex u)
	{   
        //Calls Vector3f dist
        return m_location[m_goal].dist(m_location[u]);
	}
private:
	LocMap m_location;
	Vertex m_goal;
};

//For goal found
struct found_goal {};

//Terminate if goal found
template<class Vertex>
class star_graph_visitor: public boost::default_astar_visitor
{
public:
	star_graph_visitor(Vertex goal):m_goal(goal)
	{
	}

    template <class Graph>
    void examine_vertex(Vertex u, Graph& g) 
    {
        if(u == m_goal)
        {
          throw found_goal();
        }
    }
    
private:
	Vertex m_goal;
};

std::list<Vector3f > PathPlanner::getPath(Vector3f position, std::string s, std::string e)
{

    int start = m_planat_dir.at(s);
    int goal = m_planat_dir.at(e);

    std::cout << "Start: " << start << " " << s << "\n" << "End: " << goal << " " << e << std::endl;

    typedef Graph::vertex_descriptor vertex;

    std::vector<Graph::vertex_descriptor> p(num_vertices(g));
    std::vector<float> d(num_vertices(g));

    try {
      //call astar named parameter interface
        astar_search(g, start, distance_heuristic<Graph, float, std::vector<Vector3f> >
            (m_nodes, goal),
            predecessor_map(&p[0]).distance_map(&d[0]).
            visitor(star_graph_visitor<vertex>(goal)));
    
    
    } catch(found_goal fg)
    {
        std::cout << "Found Goal" << std::endl; 
        std::list<Vector3f> shortest_path;
        for(vertex v = goal;; v = p[v]) {
            shortest_path.push_front(v);
            if(p[v] == v)
            {
                break;
            }
      }
      return shortest_path;
    }

    //If there is no solution
    std::cout << "Found no Goal" << std::endl;
    std::list<Vector3f > solutionPath;
    solutionPath.push_front(position);
    return solutionPath;
}


PathPlanner::PathPlanner (std::string mapfile) 
{
    using std::map;

    try
    {

        //Filepointer
        filesystem::path fileName(mapfile);
        filesystem::ifstream mapfilestream(fileName);

        //Check file
        if (!mapfilestream)
        {
            std::cerr << "No map file" << std::endl;
            //Exception?
            return;
        }

        //Get number of elements
        std::string readline;
        std::getline(mapfilestream, readline);
        int number_of_vertices;
        std::istringstream instring(readline);
        instring >> number_of_vertices;

        Graph g(number_of_vertices);

        typedef property_map<Graph, edge_weight_t>::type star_dist_map_t;
        star_dist_map_t star_dist = get(edge_weight, g);

        typedef graph_traits <Graph>::vertex_descriptor Vertex;
        typedef std::map <std::string, Vertex> NameVertexMap;
        NameVertexMap stars;

        //Read Nodes
        for (int i = 0; i < number_of_vertices; i++)
        {
            std::getline(mapfilestream, readline);
            std::string strname;
            int x, y, z;
            std::istringstream instring(readline);
            instring >> strname >> x >> y >> z;

            //star_name[i] = strname;
            m_nodes.push_back(Vector3f(x,y,z));
            m_planat_dir.insert(std::pair<std::string,int>(strname, i));
        }

        //Read Edges
        for (std::string readline; std::getline(mapfilestream, readline);)
        {
            std::istringstream instring(readline);
            int start, end;
            instring >> start >> end;

            float distance = m_nodes[start].dist(m_nodes[end]);
            std::cout << "Distance: " << distance << std::endl;

            //graph_traits<Graph>::edge_descriptor e;
            Graph::edge_descriptor e;

            bool inserted;
            boost::tie(e, inserted) = add_edge(start, end, g);
            if (inserted)
            {
                //lstd::cout << "Füge Edge ein" << std::endl;
                star_dist[e] = distance;
            }
        }

    }
    catch (filesystem::filesystem_error &e)
    {
        std::cout << "Can not read form PathFile" << std::endl;
        //throw std::ios_base::failure("Unable to read file");
    }
}

void PathPlanner::print()
{
    std::map<std::string,int>::iterator it;

    for(it = m_planat_dir.begin(); it !=m_planat_dir.end(); ++it)
    {
        std::cout << "Num: " << std::setw(2) << it->second << " Name: " 
            << std::left << std::setw(12) << it->first << " " << std::right 
            << std::setw(5) << std::endl;

            m_nodes[it->second].printVector();
    }
}
    
}
