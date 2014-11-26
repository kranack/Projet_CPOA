#ifndef VEC3F_H
#define VEC3F_H

#include "vector.h"

typedef Vector<float,3> V3F;

class Vec3f: public V3F
{
public:
    Vec3f();
    Vec3f(float val1, float val2, float val3);
    Vec3f(V3F& vec);
    Vec3f operator *(const Vec3f& vec) const;
    float operator *(const float val) const;
    Vec3f operator ^(const Vec3f& vec) const;
    //Vec3f& operator =(const Vec3f& vec);
};

#endif // VEC3F_H
