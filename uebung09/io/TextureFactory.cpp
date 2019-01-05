/*
 *  TextureFactory.cpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "TextureFactory.hpp"
#include "ReadPPM.hpp"
#include "ReadTGA.hpp"
#include "ReadJPG.hpp"
#include "BitmapReader.hpp"
#include "../util/shared_array.hpp"

#include <iostream>
using std::cout;
using std::endl;

namespace asteroids
{

std::map<string, Texture*> TextureFactory::m_loadedTextures;

string TextureFactory::m_basePath;

TextureFactory::TextureFactory()
{
    // TODO Auto-generated constructor stub

}

TextureFactory::~TextureFactory()
{
    // TODO Auto-generated destructor stub
}

TextureFactory& TextureFactory::instance()
{
    // Just crate one instance
    static TextureFactory instance;
    return instance;
}

void TextureFactory::setBasePath(const string& base)
{
	m_basePath = base;
}

Texture* TextureFactory::getTexture(const string& filename) 
{
    // A texture object
    
    
    Texture* tex = 0;

    string tex_filename = m_basePath + filename;

    std::map<string, Texture*>::iterator it = m_loadedTextures.find(tex_filename);
    if(it == m_loadedTextures.end())
    {
        // Texture data
        int width = 0;
        int height = 0;
        unsigned char* data = 0;
        BitmapReader* reader = 0;

        // Get file extension
        if(filename.substr(filename.find_last_of(".") + 1) == "ppm")
        {
            reader = new ReadPPM(tex_filename);
        }
        else if(filename.substr(filename.find_last_of(".") + 1) == "tga")
        {
            reader = new ReadTGA(tex_filename);
        }
        else if(filename.substr(filename.find_last_of(".") + 1) == "jpg")
        {
            reader = new ReadJPG(tex_filename);
        }

        if(reader)
        {
            data = reader->getPixels();
            width = reader->getWidth();
            height = reader->getHeight();
        }

        // Check data and create new texture if possible
        if(data != 0 && width != 0 && height != 0)
        {
            tex = new Texture(data, width, height);
            m_loadedTextures[tex_filename] = tex;
        }
        else
        {
            cout << "TextureFactory: Unable to read file " << tex_filename << "." << endl;
        }

        
        
        delete reader;
        return tex;
    }
    else
    {
        return m_loadedTextures[tex_filename];
    }

   
}

}

