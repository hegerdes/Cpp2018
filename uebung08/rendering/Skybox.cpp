/*
 *  Skybox.cpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */
#include "Skybox.hpp"

namespace asteroids
{


Skybox::Skybox(int width, string files[6])
    : m_width(width)
{
    // Create textures
    m_textures = new Texture*[6];
    for(int i = 0; i < 6; i++)
    {
        m_textures[i] = nullptr;
        // TODO: Delete nullptr initialization.
        // Get textures from factory and save 
        // each of them in the array m_textures.
    }
}

Skybox::~Skybox()
{
    if(m_textures)
    {
    	for(int i = 0; i < 6; i++)
    	{
    		if(m_textures[i])
    		{
    			delete m_textures[i];
    		}
    	}
    	delete[] m_textures;
    	m_textures = 0;
    }
}


void Skybox::render(Camera& cam)
{
    // Enable/Disable features

    glPushMatrix();
    glPushAttrib(GL_ENABLE_BIT);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);

    cam.applyRotationOnly();

    // Set color
    glColor3f(1.0f, 1.0f, 1.0f);

    float pos = 0.5f * m_width;
    // Render right quad
    if(m_textures[3])
    {
        m_textures[3]->bind();
        glBegin(GL_QUADS);
        glTexCoord2f(1, 1); glVertex3f(  pos, -pos,  pos );
        glTexCoord2f(1, 0); glVertex3f(  pos, -pos, -pos );
        glTexCoord2f(0, 0); glVertex3f(  pos,  pos, -pos );
        glTexCoord2f(0, 1); glVertex3f(  pos,  pos,  pos );
        glEnd();
    }

    // Render rear quad
    if(m_textures[0]) 
    {
        m_textures[0]->bind();
        glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f(  -pos, -pos, -pos );
        glTexCoord2f(1, 1); glVertex3f(   pos, -pos, -pos );
        glTexCoord2f(1, 0); glVertex3f(   pos,  pos, -pos );
        glTexCoord2f(0, 0); glVertex3f(  -pos,  pos, -pos );
        glEnd();
    }

    // Render the front quad
    if(m_textures[2])
    {
        m_textures[2]->bind();
        glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f( -pos, -pos,  pos );
        glTexCoord2f(1, 1); glVertex3f(  pos, -pos,  pos );
        glTexCoord2f(1, 0); glVertex3f(  pos,  pos,  pos );
        glTexCoord2f(0, 0); glVertex3f( -pos,  pos,  pos );
        glEnd();
    }

    // Render the left quad
    if(m_textures[1])
    {
        m_textures[1]->bind();
        glBegin(GL_QUADS);
        glTexCoord2f(1, 1); glVertex3f( -pos, -pos, -pos );
        glTexCoord2f(0, 1); glVertex3f( -pos, -pos,  pos );
        glTexCoord2f(0, 0); glVertex3f( -pos,  pos,  pos );
        glTexCoord2f(1, 0); glVertex3f( -pos,  pos, -pos );
        glEnd();
    }

    // Render the top quad
    if(m_textures[4])
    {
        m_textures[4]->bind();
        glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f( -pos,  pos, -pos );
        glTexCoord2f(0, 0); glVertex3f( -pos,  pos,  pos );
        glTexCoord2f(1, 0); glVertex3f(  pos,  pos,  pos );
        glTexCoord2f(1, 1); glVertex3f(  pos,  pos, -pos );
        glEnd();
    }

    // Render the bottom quad
    if(m_textures[5])
    {
        m_textures[5]->bind();
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -pos, -pos, -pos );
        glTexCoord2f(0, 1); glVertex3f( -pos, -pos,  pos );
        glTexCoord2f(1, 1); glVertex3f(  pos, -pos,  pos );
        glTexCoord2f(1, 0); glVertex3f(  pos, -pos, -pos );
        glEnd();
    }

   glPopAttrib();
   glPopMatrix();
}

}
