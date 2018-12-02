#ifndef __RENDERABLE2D_HPP__
#define __RENDERABLE2D_HPP__

#include "Renderable.hpp"

namespace asteroids
{

class MainWindow;

class Renderable2D : public Renderable 
{ 
    public:

        /// Constructor     
        Renderable2D(MainWindow* mainWindow); 

        //Method to call in subclasses at the beginning of render()
        void prerender();

        //Method to call in subclasses at the end of render()
        void postrender();

        /// Renders the object     
        virtual void render() = 0; 

        /// Sets the current rendering color     
        void setColor(float r, float g, float b); 
        
    private: //maybe protected
        MainWindow* m_window;

        //TODO?
};

}// namespace asteroids

#endif