#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <fstream>

#include "PathPlanner.hpp"

namespace asteroids
{

std::list<Vector<float> > PathPlanner::getPath(Vector<float> position, std::string s, std::string e)
{
    // TODO: Plan a path from s to e using the A* implementaion
    // of the Boost Graph Library. Add the positions of the 
    // visited nodes of the solution to this list.
    std::list<Vector<float> > solutionPath;

    return solutionPath;
}


PathPlanner::PathPlanner (std::string mapfile) 
{
    using std::string;
    using std::map;
    using std::cout;
    using std::endl;
/* 
    //Open File
    FILE* fp = fopen(mapfile.c_str(), "r");

    if(fp == NULL)
    {
        cout << "PathPlanner: Unable to open file " << mapfile << endl;
    }

    char line[100];
	if(fgets(line, sizeof(line), fp) == NULL)
	{
		cout << "PathPlanner: Error reading line from file" << endl;
	}

    m_numofindices = atoi(line);

    cout << "PathPlanner: Num of elements " << m_numofindices << endl;

    fclose(fp);

    */ 

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
            //std::cout << word << std::endl;
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
    //print();

    // for(map<string,int>::iterator it = m_planatdir.begin(); it !=m_planatdir.end(); ++it)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    // for(std::vector<int>::iterator it = m_vertex.begin(); it !=m_vertex.end(); ++it)
    // {
    //     cout << *it << endl; 
    // }

    // for(std::vector<int>::iterator it = m_faces.begin(); it !=m_faces.end(); ++it)
    // {
    //     cout << *it << endl; 
    // }

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
