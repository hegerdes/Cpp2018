/*
 *  AsteoridField.cpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "AsteroidField.hpp"
#include "Asteroid.hpp"
#include "../math/Randomizer.hpp"
#include "../math/Vector.hpp"
namespace asteroids
{

AsteroidField::AsteroidField(int quantity, const std::string& filename, float rangemax, float sizemin, float sizemax)
{
	//Get instances
	Randomizer* randominst = Randomizer::instance();
	TriangleMeshFactory& triangleinst = TriangleMeshFactory::getinstance();

 	//Generate asteroids
	for(int i = 0; i < quantity; i++)
	{
		std::cout << "Genarate Asteroid " << i << filename << " at " << std::endl;
		randominst->getRandomVertex(2).printVector();

		TexturedMesh* textmesh = (TexturedMesh*)(triangleinst.getMesh(filename));
		m_asteroids.push_back(new Asteroid(textmesh, randominst->getRandomVertex(500), 
		randominst->getRandomNumber(0, 0.5)));

	   /// TODO: Get mesh from class TriangleMeshFactory and add new DONE Except its just one asteroid
	   /// Asteroid to internal list DONE
	}
}

AsteroidField::~AsteroidField()
{
	for(Asteroid* a : m_asteroids)
	{
		if(a)
		{
			delete a;
		}
	}
	//m_asteroids.for_each(delete Asteroid);
	
}

void AsteroidField::render()
{
	for(auto& t : m_asteroids)
	{
		t->render();
	}

}

} // namespace asteroids
