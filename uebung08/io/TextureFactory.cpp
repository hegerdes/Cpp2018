#include "TextureFactory.hpp"
#include "BitmapReader.hpp"
#include "ReadJPG.hpp"
#include "ReadTIFF.hpp"
#include "ReadPPM.hpp"
#include "ReadTGA.hpp"

namespace asteroids
{
    TextureFactory::TextureFactory()
    {
        //new Instance
    }

    TextureFactory::~TextureFactory()
    {
        // for(std::map<std::string,Texture*>::iterator it=texturemap.begin();it!=texturemap.end(); it++)
        // {
        //     if(it->second)
        //     {
        //         delete it->second;
        //     }
        // }
    }

    TextureFactory& TextureFactory::getinstance()
    {
        static TextureFactory instance;
        return instance;
    }

    void TextureFactory::setBasePath(const std::string& base)
    {
        DIR* dir;
        dir = opendir(base.c_str());
        if(dir == NULL)
        {
            throw std::invalid_argument("BasePath does not exist");
        }
        else
        {
            m_basepath = base;
        }
        closedir(dir);
    }

    Texture* TextureFactory::getTexture(std::string& filename)
    {   

        //Look for texture in map
        auto search = texturemap.find(filename);
        if(search != texturemap.end())
        {
            std::cout << "Found texture in Factory" << std::endl;
            return search->second;
        }

        BitmapReader* read = 0;

        //Genarate new texture
        if(GetExtensionFromFileName(filename) == "jpg")
        {
            read = new ReadJPG(m_basepath + filename);
            
        }
        else if(GetExtensionFromFileName(filename) == "ppm")
        {
            read = new ReadPPM(m_basepath +filename);
            
        }
        else if(GetExtensionFromFileName(filename) == "tga")
        {
            read = new ReadTGA(m_basepath + filename);
        }
        else if(GetExtensionFromFileName(filename) == "tiff" || 
            GetExtensionFromFileName(filename) == "tif")
        {
            read = new ReadTIFF(m_basepath + filename);
        }
        else
        {
            cout << "TextureFactory: Unable to read file " << filename << "." << endl;
        }

        //Get Instance and put in map
        Texture* texture = new Texture(read->getPixels(),read->getWidth(),read->getHeight());
        texturemap[filename] = texture;
        return texture;

    }
} //asteroids