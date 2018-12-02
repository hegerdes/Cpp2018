#ifndef __RENDERABLE2D_HPP__
#define __RENDERABLE2D_HPP__

#include "Renderable.hpp"

namespace asteroids
{

class MainWindow;

class Renderable2D : public Renderable 
{ 
    public:

        /**
         * @brief Construct a new Renderable 2D object
         * 
         * @param mainWindow Pointer the MainWindow for dimensions
         */
        Renderable2D(MainWindow* mainWindow); 

        /**
         * @brief   Context change form 3D to 2D.
         *          Accsessable for subclasses
         */
        void prerender();

        /**
         * @brief   Context change form 2D to 3D.
         *          Accsessable for subclasses
         */
        void postrender();

        /**
         * @brief Virtual function for subclasses
         * 
         */
        virtual void render() = 0; 

        /**
         * @brief Set the Color object
         * 
         * @param r Value for red
         * @param g Value for green
         * @param b Value for blue
         */
        void setColor(float r, float g, float b);

    protected:

        /**
         * @brief Get the Color R object
         * 
         * @return float of red
         */
        inline float getColorR(){return color2D[0];}

        /**
         * @brief Get the Color G object
         * 
         * @return float of green
         */
        inline float getColorG(){return color2D[1];}

        /**
         * @brief Get the Color B object
         * 
         * @return float blue
         */
        inline float getColorB(){return color2D[2];}
        
    private:
        MainWindow* m_window;

        float color2D[3] = {1.0,0.0,0.0};
};

}// namespace asteroids

#endif