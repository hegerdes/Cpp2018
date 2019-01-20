#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include "PathPlanner.hpp"

using namespace boost;

namespace asteroids
{

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
};

std::list<Vector3f > PathPlanner::getPath(Vector3f position, std::string s, std::string e)
{

    int start = m_planat_dir.at(s);
    int end = m_planat_dir.at(e);

    std::cout << "StartNum " << start << " EndNum " << end << std::endl;

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


    //Graph setup
    typedef adjacency_list <vecS, vecS, undirectedS, property < vertex_name_t,
    std::string >, property < edge_name_t, std::string > > Graph;

    Graph g(number_of_vertices);
	
    typedef property_map<Graph,vertex_name_t>::type star_name_map;
    star_name_map star_name = get(vertex_name, g);

    typedef property_map<Graph, edge_name_t>::type star_dist_map;
    star_dist_map star_dist = get(edge_name, g);

    typedef graph_traits < Graph >::vertex_descriptor Vertex;
    typedef std::map <std::string, Vertex> NameVertexMap;
    NameVertexMap stars;

    //Read Nodes
    for (int i = 0; i < number_of_vertices; i++)
	{
		std::getline(mapfilestream, readline);
		std::string star_name;
		int x, y, z;
		std::istringstream instring(readline);
		instring >> star_name >> x >> y >> z;

        m_nodes.push_back(Vector3f(x,y,z));
        m_planat_dir.insert(std::pair<std::string,int>(star_name, i));
	}

    //Read Edges
	for (std::string readline; std::getline(mapfilestream, readline);)
	{
		std::istringstream instring(readline);
		int start, end;
		instring >> start >> end;

		float distance = m_nodes[start].dist(m_nodes[end]);

        graph_traits<Graph>::edge_descriptor e;

		bool inserted;
		boost::tie(e, inserted) = add_edge(start, end, g);
		if (inserted)
		{
            //lstd::cout << "Füge Edge ein" << std::endl;
            star_dist[e] = distance;
		}
	}

    print();
   
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
