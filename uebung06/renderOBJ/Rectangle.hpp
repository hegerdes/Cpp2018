#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Renderable2D.hpp"

namespace asteroids
{

class MainWindow;
class Rectangle : public Renderable2D 
{ 
    public: 
        /**
         * @brief Construct a new Rectangle object
         * 
         * @param _mainWin Pointer to MainWindow for high and wigh
         * @param x Position x
         * @param y Position y
         * @param w wigh of the Rectangle
         * @param h hight of the Rectange
         */
        Rectangle(MainWindow* _mainWin, float x, float y, float w, float h); 

        /**
         * @brief Renders a Rectange
         * 
         */
        void render(); 

    private:
        // Position x
        float m_x;

        // Position y
        float m_y; 

        // wigh
        float m_w; 

        // high
        float m_h;
};
    
}// namespace asteroids

#endif