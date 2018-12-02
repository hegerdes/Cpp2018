#include "Rectangle.hpp"

namespace asteroids
{

Rectangle::Rectangle(MainWindow* _mainWin, float x, float y, float w, float h):Renderable2D(_mainWin)
{
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
}

void Rectangle::render()
{
    Renderable2D::prerender();

    glBegin(GL_LINE_LOOP);
    glVertex2d(m_x, m_y);
    glVertex2d(m_x + m_w, m_y);
    glVertex2d(m_x + m_w, m_y + m_h);
    glVertex2d(m_x, m_y + m_h);
    glEnd();

    Renderable2D::postrender();
}


}// namespace asteroids

