#ifndef VEC2F_H
#define VEC2F_H

#include "vector.h"

typedef Vector<float,2> V2F;

class Vec2f: public V2F
{
public:
    Vec2f();
    Vec2f(V2F& vec);
    float operator *(const Vec2f& vec) const;
};

#endif // VEC2F_H
