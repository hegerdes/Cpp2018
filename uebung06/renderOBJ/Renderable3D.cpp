#include "Renderable3D.hpp"


namespace asteroids
{

void Renderable3D::setColor(float r, float g, float b)
{
    color3D[0] = r;
    color3D[1] = g;
    color3D[2] = b;
}
        
}