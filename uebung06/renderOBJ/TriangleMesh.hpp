/*
 *  TriangleMesh.hpp
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#ifndef __TriangleMesh_HPP__
#define __TriangleMesh_HPP__

#include <string>

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "../Quaternion.hpp"
#include "Renderable3D.hpp"

namespace asteroids
{

/**
 * @brief A struct to represent a simple 3D TriangleMesh 
 * 
 */
class TriangleMesh : public Renderable3D 
{
public:

    enum ACTION{ACCEL, STRAFE, LIFT, YAW, PITCH, ROLL};

    TriangleMesh();

    /**
     * @brief Construct a new TriangleMesh object from another instance
     * 
     * @param other         Instance to clone
     */
    TriangleMesh(const TriangleMesh& other);

    /**
     * @brief Construct a new TriangleMesh object from the given PLY file
     * 
     * @param filename      A .ply file containing the TriangleMesh definition
     */
    TriangleMesh(const std::string& filename);

    /**
	 * @brief   Contructs a triangle mesh from given buffers
	 * @param indexBuffer indexbuffer
	 * @param vertexBuffer vertexbuffer
	 * @param numFaces number of faces
	 * @param numVertices number of vertices
	 */
	TriangleMesh(int* indexBuffer, float* vertexBuffer, int numFaces, int numVertices);

    /**
	 * @brief   Rotates a triangle mesh at the given axis with the given speed
	 * @param axis axis to rotate
	 * @param speed speed of rotation
	 */
	void rotate(ACTION axis, float speed);

	/**
	 * @brief   Moves a triangle mesh at the given axis with the given speed
	 * @param axis axis to move
	 * @param speed speed of movement
	 */
	void move(ACTION axis, float speed);

    /**
     * @brief Prints general information (number of vertices and faces) 
     *        to stdout.
     * 
     */
    void printTriangleMeshInformation();

    /**
     * @brief Prints the contends of the internal buffers to stdout.
     * 
     */
    void printBuffers();

    /**
     * @brief Renders the TriangleMesh
     * 
     */
    void render();

    /**
     * @brief Destroys the TriangleMesh object
     * 
     */
    virtual ~TriangleMesh();

protected:

    void initTransformations();

    /**
	 * @brief Computes the 4x4 transformation matrix for 
     * this object (needed for OpenGL)
	 */
	void computeMatrix();

    /// Number of vertices
    int         m_numVertices;

    /// Number of faces
    int         m_numFaces;

    /// Vertexbuffer
    float*      m_vertexBuffer;

    /// Indexbuffer
    int*        m_indexBuffer;

    /// X axis of local coordinate system
    Vector      m_xAxis;

    /// Y axis of local coordinate system
    Vector      m_yAxis;

    /// Z axus of local coordinate system
    Vector      m_zAxis;

    /// Transformation matrix
    Matrix      m_transformation;

    /// Current rotation
    Quaternion  m_rotation;

    /// Current position
    Vector      m_position;
};

} // namespace asteroids

#endif
