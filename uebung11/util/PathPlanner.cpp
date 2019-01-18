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
    using std::string;
    using std::map;
    using std::cout;
    using std::endl;

    // filesystem::path fileName(mapfile);
	// filesystem::ifstream mapfilestream(fileName);

    // if (!mapfilestream)
	// {
	// 	std::cerr << "No map file" << std::endl;
	// 	//Exception?
    //     return;
	// }

    // string readline;
	// std::getline(mapfilestream, readline);
	// int number_of_vertices;
	// std::istringstream instring(readline);
	// instring >> number_of_vertices;

    // for (int i = 0; i < number_of_vertices; i++)
	// {
	// 	std::getline(mapfilestream, readline);
	// 	std::string star_name;
	// 	float x, y, z;
	// 	std::istringstream instring(readline);
	// 	instring >> name >> x >> y >> z;
	// 	// star_name[i] = name;
	// 	// indexByName[name] = i;
	// 	// positions[i]=Vertex3d(x,y,z);
	// }


    //Will be replces by boost functions but works by now
    
    //Using streams to read
    std::fstream mapstream;
    mapstream.open(mapfile);

    string word;
    mapstream >> word;

    m_numofindices = std::stoi(word);

    //Output the number of planets
    cout << "PathPlanner: Num of elements " << m_numofindices << endl;
    
    int count = 0;
    int numplanet = 0;
    //Parse File
    while(mapstream >> word)
    {
        if(numplanet < m_numofindices)
        {
            //For names of the planet
            if(count % 4 == 0)
            {
                m_planatdir.insert(std::pair<string,int>(word, numplanet));
                numplanet++;
            }
            else
            {   //Position of the planet x,y,z
                m_vertex.push_back(std::stoi(word));
                
            }
            count++;
        }
        else
        {   
            //Path between planets
            m_faces.push_back(std::stoi(word));
        }
    }
    
    print();



    mapstream.close();
    
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
            << std::setw(5) << m_vertex[it->second * 3] << std::setw(5) << " " 
            << m_vertex[it->second * 3 +1] << " " << std::setw(5) 
            << m_vertex[it->second * 3 +2] << std::endl;
    }


}
    
}
