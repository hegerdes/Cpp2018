#ifndef TEXTUREFACTORY_HPP_
#define TEXTUREFACTORY_HPP_

#include <map>
#include <string>
#include <dirent.h>
#include <stdexcept>
#include "../rendering/Texture.hpp"
#include "../util/Util.hpp"

namespace asteroids
{
class TextureFactory
{
    public:

    enum FileType 
    {
	    JPG,
	    TGA,
	    TIFF,
	    PPM
    };

        /**
         * @brief   Static function to get the one instance of
         *          TextureFacrory
         * 
         * @return  Reference to TextureFactory 
         */
        static TextureFactory& getinstance();

        /**
         * @brief Set the Base Path object
         * 
         * @param base Path to textures
         */
        void setBasePath(const std::string& base);

        /**
         * @brief Get the Texture object
         * 
         * @param filename 
         * @return Texture* 
         */
        Texture* getTexture(std::string& filename);

    private:
    
        /**
         * @brief Construct a new Texture Factory object
         */
        TextureFactory();

        /**
         * @brief Destroy the Texture Factory object
         */
        virtual ~TextureFactory();

        ///Path to Basefolder
        std::string m_basepath = "";

        ///Map for Textures
        std::map<std::string,Texture*> texturemap;

        ///Pointer to the one instance
        static TextureFactory* p_instance;

};

}

#endif