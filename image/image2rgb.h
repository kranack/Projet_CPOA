#ifndef IMAGE2RGB_H
#define IMAGE2RGB_H

#include "vector.h"
#include "image2.h"

typedef Vector<unsigned char, 3> Vec3uc;

class Image2RGB : public Image2<Vec3uc>
{
public:
    Image2RGB();
    void saveToPPM(const std::string &fileName) const;
    void loadFromPPM(const std::string &fileName);
};

#endif // IMAGE2RGB_H
