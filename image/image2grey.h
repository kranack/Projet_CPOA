#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H

#include <iostream>
#include <string>
#include <fstream>
#include "image2.h"

class Image2grey : public Image2<unsigned char>
{
public:
    Image2grey();
    void saveToPGM(const std::string &fileName) const;
    void loadFromPGM(const std::string &fileName);
};

#endif // IMAGE2GREY_H
