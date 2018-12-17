#include "TriangleMeshFactory.hpp"

namespace asteroids
{

TriangleMeshFactory::TriangleMeshFactory()
{
    //New TriangleMeshFactory 
}

TriangleMeshFactory::~TriangleMeshFactory()
{
    //Do nothing 
}

TriangleMeshFactory& TriangleMeshFactory::getinstance()
{
    static TriangleMeshFactory instance;
    return instance;
}

void TriangleMeshFactory::setBasePath(const std::string& base)
{
    DIR* dir;
    dir = opendir(base.c_str());
    
    if(dir == NULL)
    {
        throw std::invalid_argument("BasePath does not exist");
    }
    else
    {
        m_basepath = base;
    }
    closedir(dir);
}

TriangleMesh* TriangleMeshFactory::getMesh(const std::string& filename) const
{
    MeshReader* mreader;

    if(GetExtensionFromFileName(filename) == "ply")
    {
        mreader = new ReadPLY(m_basepath + filename);
        return mreader->getMesh();
    }
    else if(GetExtensionFromFileName(filename) == "3ds")
    {
        mreader = new Read3DS(m_basepath + filename);
        return mreader->getMesh();
        
    }

    return NULL;
}

}