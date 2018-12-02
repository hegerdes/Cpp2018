#include "Renderable2D.hpp"
#include "../MainWindow.hpp"

namespace asteroids
{
     
Renderable2D::Renderable2D(MainWindow* mainWindow)
{
    m_window = mainWindow;
} 
     
void Renderable2D::prerender()
{
    // Enter modelview mode and save current view     
    // matrix. Set transformation to indentity to      
    // 'undo' current look at transformation     
    glMatrixMode(GL_MODELVIEW);     
    glPushMatrix();     
    glLoadIdentity();

    // Enter projection mode and set ortho projection     
    // according to current window size     
    glMatrixMode(GL_PROJECTION);     
    glPushMatrix();     
    glLoadIdentity();     
    glOrtho(0.0f, m_window->width(), m_window->height(), 0.0f, -10.0f, 10.0f);
    
}
     
void Renderable2D::postrender()
{
    // Delete current ortho projection, enter model     
    // view mode and restore previous look at matrix      
    glPopMatrix();      
    glMatrixMode(GL_MODELVIEW);         
    glPopMatrix(); 
}

void Renderable2D::setColor(float r, float g, float b)
{
    color2D[0] = r;
    color2D[1] = g;
    color2D[2] = b;
}

}// namespace asteroids