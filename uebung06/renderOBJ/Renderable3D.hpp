#ifndef __RENDERABLE3D_HPP__
#define __RENDERABLE3D_HPP__

#include "Renderable.hpp"

namespace asteroids
{

/**
 * @brief Base class for al 3D renderable objects
 * 
 */
class Renderable3D : public Renderable 
{ 
    public: 
        /**
         * @brief Construct a new Renderable 3D object
         * 
         */
        // Renderable3D();

        /// Renders the object     
        virtual void render() = 0; 

        /// Sets the current rendering color     
        virtual void setColor(float r, float g, float b) = 0;

        float color[3] = {1.0,1.0,1.0};
};

}// namespace asteroids

#endif