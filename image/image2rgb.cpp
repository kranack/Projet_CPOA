#include "image2rgb.h"

Image2RGB::Image2RGB() :
    Image2<Vec3uc>()
{
}

void Image2RGB::saveToPPM(const std::string &fileName) const
{
    std::ofstream file(fileName, std::ios::out | std::ios::trunc);

    file << "P3" << std::endl;
    file << this->getWidth() << " " << this->getHeight() << std::endl;
    file << "255" << std::endl;

    for (unsigned int y = 0; y < this->getHeight(); y++){
        for (unsigned int x = 0; x < this->getWidth(); x++){
            if (x) file << "\t";

            const Vec3uc & pixel = getPixel(x,y);
            file << std::to_string(pixel[0]) << " " << std::to_string(pixel[1]) << " " << std::to_string(pixel[2]);
        }
        file << std::endl;
    }
    file.close();
}


void Image2RGB::loadFromPPM(const std::string &fileName)
{
    std::ifstream file(fileName, std::ios::in);
        if (!file.is_open()){
            std::cout << "Error while opening the file " << fileName << std::endl;
            return;
        }

        std::string magicWord;
        file >> magicWord ;

        if (magicWord != "P3"){
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

        for (unsigned int y = 0; y < this -> getHeight(); y++){
            for (unsigned int x = 0; x < this -> getWidth(); x++){
                unsigned int pixelR;
                unsigned int pixelG;
                unsigned int pixelB;

                file >> pixelR >> pixelG >> pixelB;
                setPixel(x,y, Vec3uc(pixelR * 255 / maxValue,
                             pixelG * 255 / maxValue,
                             pixelB * 255 / maxValue));
            }
        }

        file.close();
}
