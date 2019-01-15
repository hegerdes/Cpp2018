#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <list>
#include <map>
#include <vector>
#include <iomanip>
#include "math/Vector.hpp"
#include "SharedArray.hpp"


namespace asteroids
{


class PathPlanner {
  public:
    /**
     * @brief Initialzes tha pathfinder with a filename, which contains information about the graph
     * 
     * @param mapfile   A file containing the representation of an graph
     *                  used for navigatuib
     */
    PathPlanner (std::string mapfile);

    /**
     * @brief Calculates a shortest path with the A*-Algorithm
     * 
     * @param position Startposition of the ship
     * @param s Start of the path
     * @param e End of the path
     * 
     * @return A shortest path from s to e
     */

    std::list<Vector3f> getPath(Vector3f position, std::string s, std::string e);

    /**
     * @brief Prints the file content to stdout
     * 
     */
    void print();

  private:

    //Number of Planets
    int m_numofindices;

    //Store tupel for faces
    std::vector<int> m_faces;

    //store vertex
    std::vector<int> m_vertex;

    //Map to match the Names to a Index
    std::map<std::string,int> m_planatdir;




  
};

}//astorids



#endif
