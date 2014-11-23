#include "matrix33f.h"

Matrix33f::Matrix33f():
    m_size(3)
{
    m_matrix[0] = Vec3f();
    m_matrix[1] = Vec3f();
    m_matrix[2] = Vec3f();
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

void Matrix33f::setTranslation(const Vec2f &vec)
{
    m_matrix[0] = Vec3f(1.0f, 0.0f, 0.0f);
    m_matrix[1] = Vec3f(0.0f, 1.0f, 0.0f);
    m_matrix[2] = Vec3f(vec[0], vec[1], 1.0f);
}

Vec3f Matrix33f::applyTranslation(const Matrix33f &matrix, const Vec2f &vec)
{
    this->setTranslation(vec);
    Vec3f vector = Vec3f();
    /*vector[0] = m_matrix[0][0] * matrix[0][0] +
            m_matrix[0][1] * matrix[0][1] +
            m_matrix[0][2] * matrix[0][2];
    vector[1] = m_matrix[1][0] * matrix[1][0] +
            m_matrix[1][1] * matrix[1][1] +
            m_matrix[1][2] * matrix[1][2];
    vector[2] = m_matrix[2][0] * matrix[2][0] +
            m_matrix[2][1] * matrix[2][1] +
            m_matrix[2][2] * matrix[2][2];*/
    vector[0] = m_matrix[0][0] * matrix[0][0] +
                m_matrix[1][0] * matrix[0][1] +
                m_matrix[2][0] * matrix[0][2];
        vector[1] = m_matrix[0][1] * matrix[1][0] +
                m_matrix[1][1] * matrix[1][1] +
                m_matrix[2][1] * matrix[1][2];
        vector[2] = m_matrix[0][2] * matrix[2][0] +
                m_matrix[1][2] * matrix[2][1] +
                m_matrix[2][2] * matrix[2][2];

    return vector;
}

