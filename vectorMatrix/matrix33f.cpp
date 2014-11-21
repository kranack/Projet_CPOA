#include "matrix33f.h"

Matrix33f::Matrix33f():
    m_size(3)
{
    m_matrix[0] = Vec3f(1.0f, 0.0f, 0.0f);
    m_matrix[1] = Vec3f(0.0f, 1.0f, 0.0f);
    m_matrix[2] = Vec3f(0.0f, 0.0f, 1.0f);
}

Matrix33f::Matrix33f(const Vec3f& vec1, const Vec3f& vec2, const Vec3f& vec3) :
    m_size(3)
{
    m_matrix[0] = vec1;
    m_matrix[1] = vec2;
    m_matrix[2] = vec3;
}

Vec3f &Matrix33f::operator [](int val)
{
    assert(val < m_size);
    return m_matrix[val];
}

const Vec3f &Matrix33f::operator [](int val) const
{
    assert(val < m_size);
    return m_matrix[val];
}

Matrix33f Matrix33f::setTranslation(const Vec2f &vec)
{
    Matrix33f res = Matrix33f(Vec3f(1.0f, 0.0f, 0.0f), Vec3f(0.0f, 1.0f, 0.0f),
                    Vec3f(vec[0], vec[1], 1.0f));

    return res;
}

Vec3f Matrix33f::applyTranslation(const Vec2f &vec)
{
    Vec3f vector = Vec3f(vec[0], vec[1], 1.0f);
    for (int i=0; i<2; ++i)
    {
        vector[i] *= m_matrix[i] * vector;
    }

    return vector;
}
