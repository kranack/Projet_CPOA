#ifndef MATRIX33F_H
#define MATRIX33F_H

#include "vec2f.h"
#include "vec3f.h"

class Matrix33f
{
protected:
    Vec3f m_matrix[3];
    int m_size;

public:
    Matrix33f();
    Matrix33f(const Vec3f& vec1, const Vec3f& vec2, const Vec3f& vec3);
    const Vec3f &operator [](int val) const;
    Vec3f& operator [](int val);
    void inverse();
    void setTranslation(const Vec2f& vec);
    Matrix33f &applyTranslation(const Vec2f &vec);
    void setRotation(Vec3f& vec);
    Vec3f applyRotation();
    void setHomothetie(Vec3f& vec);
    Vec3f applyHomothetie();
};

#endif // MATRIX33F_H
