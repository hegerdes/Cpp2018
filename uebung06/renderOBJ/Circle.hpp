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
        /// Constructor     
        Circle(MainWindow* _mainWindow, float x, float y, float radius, int segments); 

        /// Renders the object     
        virtual void render(); 

    private:
        float m_x; 

        float m_y; 

        float m_radius; 

        int m_segments;

        //TODO?
};

}

#endif