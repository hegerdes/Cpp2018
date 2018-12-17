#ifndef TRIANGLEMESHFACTORY_HPP_
#define TRIANGLEMESHFACTORY_HPP_

#include <string>
#include <dirent.h>
#include <stdexcept>
#include "../rendering/TriangleMesh.hpp"
#include "../util/Util.hpp"
#include "ReadPLY.hpp"
#include "Read3DS.hpp"
#include "MeshReader.hpp"

namespace asteroids
{
class TriangleMeshFactory
{
    public:
        /**
         * @brief   Static function to get the one instance of
         *          TriangleMeshFactory    
         * 
         * @return  Reference to TriangleMeshFactory& 
         */
        static TriangleMeshFactory& getinstance();

        /**
         * @brief Set the Base Path object
         * 
         * @param base Path to textures
         */
        void setBasePath(const std::string& base);

        /**
         * @brief Get the Mesh object
         * 
         * @param filename Path ot wanted mesh
         * @return TriangleMeshFactory* 
         */
        TriangleMesh* getMesh(const std::string& filename) const;

    private:
        ///Saves the BasePath
        std::string m_basepath = "";

        /**
         * @brief Construct a new Triangle Mesh Factory object
         */
        TriangleMeshFactory();

        /**
         * @brief Destroy the Triangle Mesh Factory object
         */
        ~TriangleMeshFactory();

};

}

#endif