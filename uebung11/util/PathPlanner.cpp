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

std::list<Vector3f > PathPlanner::getPath(Vector3f position, std::string s, std::string e)
{
    // TODO: Plan a path from s to e using the A* implementaion
    // of the Boost Graph Library. Add the positions of the 
    // visited nodes of the solution to this list.
    std::list<Vector3f > solutionPath;
    return solutionPath;
}


PathPlanner::PathPlanner (std::string mapfile) 
{
    using std::map;
    using std::cout;
    using std::endl;

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


    std::string readline;
	std::getline(mapfilestream, readline);
	int number_of_vertices;
	std::istringstream instring(readline);
	instring >> number_of_vertices;

    Graph g(number_of_vertices);

    //Read Nodes
    for (int i = 0; i < number_of_vertices; i++)
	{
		std::getline(mapfilestream, readline);
		std::string star_name;
		int x, y, z;
		std::istringstream instring(readline);
		instring >> star_name >> x >> y >> z;

        m_nodes.push_back(Vector3f(x,y,z));
        m_planatdir.insert(std::pair<std::string,int>(star_name, i));
	}

    //Read Edges
	for (std::string readline; std::getline(mapfilestream, readline);)
	{
		std::istringstream instring(readline);
		int start, end;
		instring >> start >> end;

		float distance = m_nodes[start].dist(m_nodes[end]);
        
		// graph_traits<Graph>::edge_descriptor e;
		// bool inserted;
		// boost::tie(e, inserted) = add_edge(start, end, g);
		// if (inserted)
		// {
		// 	distances[e] = distance;
		// }
	}


    print();
    
    // TODO: Parse file and build graph representation as 
    // for planning with BGL.

   
}

void PathPlanner::print()
{
    std::map<std::string,int>::iterator it;

    for(it = m_planatdir.begin(); it !=m_planatdir.end(); ++it)
    {
        std::cout << "Num: " << std::setw(2) << it->second << " Name: " 
            << std::left << std::setw(12) << it->first << " " << std::right 
            << std::setw(5) << std::endl;

            m_nodes[it->second].printVector();
    }


}
    
}
