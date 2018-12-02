#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "Renderable2D.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

namespace asteroids
{

class Circle : public Renderable2D 
{ 
    public: 
        /**
         * @brief Construct a new Circle object
         * 
         * @param _mainWindow   Pointer to a MainWindow for high and wigth
         * @param x Absult x-value for position
         * @param y Absult y-value for position
         * @param radius    Radius of the Circle
         * @param segments  
         */
        Circle(MainWindow* _mainWindow, float x, float y, float radius, int segments); 

        /**
         * @brief Renders a Circle
         * 
         */
        virtual void render(); 

    private:
        // Position x
        float m_x; 

        //Position y
        float m_y; 

        //Radius
        float m_radius; 

        int m_segments;
};

}

#endif