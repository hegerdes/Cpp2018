#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

#define GL3_PROTOTYPES 1
#include <GL/glew.h>

namespace asteroids
{
    /**
    * @brief Interface class for all objects that support rendering.
    */
    class Renderable  
    { 
        public: 
            /**
             * @brief   Virtual function that exery extending class has to implement
             */
            virtual void render() = 0;
            
            /**
             * @brief   Set the Color object. Interfacefunctin
             * 
             * @param r float-value of read 
             * @param g float-value of green
             * @param b float-value of blue
             */
            virtual void setColor(float r, float g, float b) = 0; 
    };

}

#endif