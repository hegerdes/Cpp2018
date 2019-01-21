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

<<<<<<< HEAD
template <class Graph, class CostType, class Map>
class distance_heuristic : public astar_heuristic<Graph, CostType>
{
public:
  typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
  distance_heuristic(Map m, Vertex target): m_map(m), m_target(target) {}

  CostType operator()(Vertex u)
  {
    CostType dx = m_map[m_target].x - m_map[u].x;
    CostType dy = m_map[m_target].y - m_map[u].y;
    CostType dz = m_map[m_target].z - m_map[u].z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
  }

private:
  Map m_map;

  Vertex m_target;
};


struct found_goal {};

template <class Vertex>
class star_graph_visitor : public boost::default_astar_visitor
{
public:
  star_graph_visitor(Vertex goal) : m_target(goal) {}

  template <class Graph>
  void examine_vertex(Vertex u, Graph& g) {
    if(u == m_target)
    {
      throw found_goal();
    }
  }

private:
  Vertex m_target;
=======
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
>>>>>>> 105fc58b2e9a8e909e866bdb769f92e4dc85db03
};

std::list<Vector3f > PathPlanner::getPath(Vector3f position, std::string s, std::string e)
{

    int start = m_planat_dir.at(s);
    int goal = m_planat_dir.at(e);

    std::cout << "Start: " << start << " " << s << "\n" << "End: " << goal << " " << e << std::endl;

    typedef Graph::vertex_descriptor vertex;

    std::vector<Graph::vertex_descriptor> p(num_vertices(g));
    std::vector<float> d(num_vertices(g));

<<<<<<< HEAD
    std::list<Vector3f > solutionPath;

    //Graph setup
    typedef adjacency_list <vecS, vecS, undirectedS, property < vertex_name_t,
    std::string >, property < edge_name_t, std::string > > Graph;

    Graph g(m_numofindices);

    typedef graph_traits < Graph >::vertex_descriptor Vertex;

    std::vector<Graph::vertex_descriptor> p(num_vertices(g));
    std::vector<float> d(num_vertices(g));

    try 
    {
        astar_search(g, start,
            distance_heuristic<Graph, float, std::map<std::string,int> > (m_planat_dir, end),
            predecessor_map(make_iterator_property_map(p.begin(), get(vertex_index, g))).
            distance_map(make_iterator_property_map(d.begin(), get(vertex_index, g))).
            visitor(star_graph_visitor<Vertex>(end)));
        
        /*  same as above (for testing other calls of astar_search) */
        /*
        astar_search(g, start,
            distance_heuristic<Graph, float, std::map<std::string,int> > (m_planat_dir, end),
            predecessor_map(make_iterator_property_map(p.begin(), get(vertex_index, g))).
            distance_map(make_iterator_property_map(d.begin(), get(vertex_index, g))).
            visitor(star_graph_visitor<Vertex>(end)));
        */
    } 
    catch(found_goal fg) 
    { 
        for(Vertex v = end;; v = p[v]) 
        {
            solutionPath.push_front(v);
            if(p[v] == v)
            {
                break;
            }
        }
        std::cout << "Found a path from " << start << "to" << end << "!" << std::endl;
        return solutionPath;
    }
    
    std::cout << "Couldn't find a path from " << start << "to" << end << "!" << std::endl;
=======
    std::cout << "Vor search" << std::endl;

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
    }

    //If there is no solution
    std::cout << "Found no Goal" << std::endl;
    std::list<Vector3f > solutionPath;
    solutionPath.push_front(position);
>>>>>>> 105fc58b2e9a8e909e866bdb769f92e4dc85db03
    return solutionPath;
}


PathPlanner::PathPlanner (std::string mapfile) 
{
    using std::map;

    //Filepointer
    filesystem::path fileName(mapfile);
	filesystem::ifstream mapfilestream(fileName);

    std::cout << fileName << std::endl;

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
