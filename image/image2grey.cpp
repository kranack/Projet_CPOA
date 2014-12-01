#include "image2grey.h"

Image2grey::Image2grey() :
    Image2<unsigned char>()
{
}


void Image2grey::saveToPGM(const std::string &fileName) const
{
    std::ofstream file(fileName.c_str(), std::ios::out | std::ios::trunc);

    file << "P2" << std::endl;
    file << this->getWidth() << " " << this->getHeight() << std::endl;
    file << "255" << std::endl;

    for (unsigned int y = 0; y < this->getHeight(); y++){
        for (unsigned int x = 0; x < this->getWidth(); x++){
            if (x) file << " ";
            file << std::to_string(getPixel(x,y));
        }
        file << std::endl;
    }

    file.close();
}


void Image2grey::loadFromPGM(const std::string &fileName)
{
    std::ifstream file(fileName.c_str(), std::ios::in);
    if (!file.is_open()){
        std::cout << "Error while opening the file " << fileName << std::endl;
        return;
    }

    std::string magicWord;
    file >> magicWord ;

    if (magicWord != "P2"){
        std::cout << "Error while reading the file : Unknown format." << std::endl;
        file.close();
        return;
    }

    unsigned int width;
    unsigned int height;
    file >> width >> height;

    setSize(width, height);

    unsigned int maxValue;
    file >> maxValue;

    for (unsigned int y = 0; y < this->getHeight(); y++){
        for (unsigned int x = 0; x < this->getWidth(); x++){
            unsigned int pixel;
            file >> pixel;
            this->setPixel(x,y, pixel * 255 / maxValue);
        }
    }

    file.close();
}
