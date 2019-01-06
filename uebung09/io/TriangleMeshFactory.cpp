/*
 * TraingleMeshFactory.cpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */
#include <iostream>
using std::cout;
using std::endl;

#include "TriangleMeshFactory.hpp"

#include "io/Read3DS.hpp"
#include "io/ReadPLY.hpp"
#include "io/ReadOBJ.hpp"

namespace asteroids
{

using MeshReaderPtr = shared_array<MeshReader>;
using PlyReaderPtr = shared_array<ReadPLY>;
using DSReaderPtr = shared_array<Read3DS>;
using OBJReaderPtr = shared_array<ReadOBJ>;
using TriMeshPtr = shared_array<TriangleMesh>;

TriangleMesh* TriangleMeshFactory::getMesh(const string &filename) const
{
    // A mesh pointer and MeshIO pointer
    //MeshReaderPtr io;
    TriMeshPtr mesh;

    // Get file extension
    if(filename.substr(filename.find_last_of(".") + 1) == "ply")
    {
        PlyReaderPtr io = new ReadPLY(filename);
        mesh = io->getMesh();
    }
    else if(filename.substr(filename.find_last_of(".") + 1) == "3ds")
    {
        DSReaderPtr io = new Read3DS(filename);
        mesh = io->getMesh();
    }
    else if(filename.substr(filename.find_last_of(".") + 1) == "obj")
    {
        OBJReaderPtr io = new ReadOBJ(filename);
        mesh = io->getMesh();
    }
    

    return mesh.get();
}

TriangleMeshFactory& TriangleMeshFactory::instance()
{
    // Just crate on instance
    static TriangleMeshFactory instance;
    return instance;
}

}
