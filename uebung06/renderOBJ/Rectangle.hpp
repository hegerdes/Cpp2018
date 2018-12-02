#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Renderable2D.hpp"

namespace asteroids
{

class MainWindow;
class Rectangle : public Renderable2D 
{ 
    public: 
        /// Constructor     
        Rectangle(MainWindow* _mainWin, float x, float y, float w, float h); 

        /// Renders the object     
        void render(); 

    private:
        float m_x;

        float m_y; 

        float m_w; 

        float m_h;

        //TODO?
};
    
}// namespace asteroids

#endif