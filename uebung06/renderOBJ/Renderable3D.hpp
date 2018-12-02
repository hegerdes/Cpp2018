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
         * @brief Virtual function for sub class
         * 
         */
        virtual void render() = 0; 

        /**
         * @brief   Set the Color object. Interfacefunctin
         * 
         * @param r float-value of read 
         * @param g float-value of green
         * @param b float-value of blue
         */   
        void setColor(float r, float g, float b);

    protected:
        /**
         * @brief Get the Color R object
         * 
         * @return float for Color value
         */
        inline float getColorR(){return color3D[0];}

        /**
         * @brief Get the Color G object
         * 
         * @return float for Color value
         */
        inline float getColorG(){return color3D[1];}

        /**
         * @brief Get the Color B object
         * 
         * @return float for Color value
         */
        inline float getColorB(){return color3D[2];}

    private:

        //Save the color value. Default: whites
        float color3D[3] = {1.0f,1.0f,1.0f};
};

}// namespace asteroids

#endif