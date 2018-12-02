#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "Renderable3D.hpp"
#include "../Vector.hpp"

namespace asteroids
{

class Sphere: public Renderable3D 
{ 
    public:     
        /**      
         * @brief Construct a new Sphere object      
         *       
         * @param position      Initial position of the sphere      
         * @param radius        Radius      
         * @param numSides      Number of horizontal intersections      
         * @param numStack      Number of vertical intersections      
         */     
        Sphere(const Vector& position, float radius, int numSides = 10, int numStacks = 10);          

        // Renders the sphere at the given position     
        void render();

        void setColor(float r, float g, float b);

        /**
         * @brief Destroy the Sphere object
         */
        ~Sphere();
        
    private:
        Vector m_position;

        float m_radius;

        int m_numSides;

        int m_numStacks;

        //TODO?
};

}

#endif