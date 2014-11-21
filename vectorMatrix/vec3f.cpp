#include "vec3f.h"

Vec3f::Vec3f():
    V3F(0.0f)
{
}

Vec3f::Vec3f(float val1, float val2, float val3)
{
    m_data[0] = val1;
    m_data[1] = val2;
    m_data[2] = val3;
}


Vec3f::Vec3f(V3F &vec)
{
    for (int i=0; i<3; ++i)
    {
        m_data[i] = vec[i];
    }
}


float Vec3f::operator *(const Vec3f& vec) const
{
    float res = 0.0f;
    for (int i=0; i<3; ++i)
    {
        res += m_data[i] * vec[i];
    }
    return res;
}

Vec3f Vec3f::operator ^(const Vec3f& vec) const
{
    Vec3f res;
    res[0] = (m_data[1] * vec[2]) - (m_data[2] * vec[1]);
    res[1] = (m_data[2] * vec[0]) - (m_data[0] * vec[2]);
    res[2] = (m_data[0] * vec[1]) - (m_data[1] * vec[0]);

    return res;
}
