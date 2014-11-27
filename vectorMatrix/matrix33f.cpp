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

Matrix33f &Matrix33f::operator *=(const Matrix33f &matrix)
{
    m_matrix[0] *= matrix[0];
    m_matrix[1] *= matrix[1];
    m_matrix[2] *= matrix[2];

    return *this;
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

Matrix33f &Matrix33f::applyTranslation(const Vec2f &vec)
{
    Matrix33f matrix = Matrix33f();
    matrix.setTranslation(vec);
    std::cout << "matrix : {" << matrix[0] << ", " << matrix[1]
              << ", " << matrix[2] << "}" << std::endl;
    m_matrix[0] *= matrix[0];
    m_matrix[1] *= matrix[1];
    m_matrix[2] += m_matrix[2] * matrix[2];
    m_matrix[2][2] = 1.0f;
    return *this;
}

void Matrix33f::setRotation(const float angle)
{
    float _cos = cosf(angle*M_PI/180);
    float _sin = sinf(angle*M_PI/180);
    m_matrix[0] = Vec3f(_cos, -_sin, 0.0f);
    m_matrix[1] = Vec3f(_sin, _cos, 0.0f);
    m_matrix[2] = Vec3f(0.0f, 0.0f, 1.0f);
}

Matrix33f &Matrix33f::applyRotation(const float angle)
{
    Matrix33f matrix = Matrix33f();
    matrix.setRotation(angle);
    std::cout << "matrix : {" << matrix[0] << ", " << matrix[1]
              << ", " << matrix[2] << "}" << std::endl;
    m_matrix[0] *= matrix[0];
    m_matrix[1] *= matrix[1];
    m_matrix[2] *= matrix[2];

    return *this;
}

void Matrix33f::setHomothetie(const Vec2f &vec)
{
    m_matrix[0] = Vec3f(vec[0], 0.0f, 0.0f);
    m_matrix[1] = Vec3f(0.0f, vec[1], 0.0f);
    m_matrix[2] = Vec3f(0.0f, 0.0f, 1.0f);
}

Matrix33f &Matrix33f::applyHomothetie(const Vec2f &vec)
{
    Matrix33f matrix = Matrix33f();
    matrix.setHomothetie(vec);

    return *this;
}

Matrix33f Matrix33f::operator *(const Vec3f &vec)
{
    Matrix33f matrix = Matrix33f();

    matrix[0] = m_matrix[0] * vec;
    matrix[1] = m_matrix[1] * vec;
    matrix[2] = m_matrix[2] * vec;

    return matrix;
}

Vec2f Matrix33f::applyTransformation(const Vec2f &vec)
{
    Vec2f res = Vec2f();

    res[0] = vec[0] * m_matrix[0][0] + vec[0] * m_matrix[1][0] + m_matrix[2][0];
    res[1] = vec[1] * m_matrix[0][1] + vec[1] * m_matrix[1][1] + m_matrix[2][1];

    return res;
}



