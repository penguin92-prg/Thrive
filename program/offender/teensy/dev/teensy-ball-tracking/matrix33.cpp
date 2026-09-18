#include <math.h>

#include "matrix33.hpp"

Vec3 operator+(const Vec3& v1, const Vec3& v2){
  Vec3 v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  v.z = v1.z + v2.z;
  return v;
}

Vec3 operator-(const Vec3& v1, const Vec3& v2){
  Vec3 v;
  v.x = v1.x - v2.x;
  v.y = v1.y - v2.y;
  v.z = v1.z - v2.z;
  return v;
}

Vec3 operator*(const Vec3& v, const float f){
  Vec3 r;
  r.x = v.x * f;
  r.y = v.y * f;
  r.z = v.z * f;
  return r;
}

Vec3 operator*(const float f, const Vec3& v){
  Vec3 r;
  r.x = f * v.x;
  r.y = f * v.y;
  r.z = f * v.z;
  return r;
}

Vec3& Vec3::operator+=(const Vec3& v){
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

Vec3& Vec3::operator-=(const Vec3& v){
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

Vec3& Vec3::operator*=(const float f){
  x *= f;
  y *= f;
  z *= f;
  return *this;
}

Vec3& Vec3::operator/=(const float f){
  x /= f;
  y /= f;
  z /= f;
  return *this;
}

Vec3& Vec3::operator=(const Vec3& v){
  x = v.x;
  y = v.y;
  z = v.z;
  return *this;
}


void Vec3::set(float vec_x, float vec_y, float vec_z){
  x = vec_x;
  y = vec_y;
  z = vec_z;
  return;
}

void Vec3::clear(){
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
  return;
}

float Vec3::len() const{
  return sqrt(x*x + y*y + z*z);
}

Matrix33 operator+(const Matrix33& m1, const Matrix33& m2){
  return Matrix33(m1.v1+m2.v1, m1.v2+m2.v2, m1.v3+m2.v3);
}

Matrix33 operator-(const Matrix33& m1, const Matrix33& m2) {
  return Matrix33(m1.v1-m2.v1, m1.v2-m2.v2, m1.v3-m2.v3);
}

Matrix33 operator*(const Matrix33& m, const float f){
  return Matrix33(m.v1*f, m.v2*f, m.v3*f);
}

Vec3 operator*(const Matrix33& m, const Vec3& v) {
  return Vec3(
    m.v1.x * v.x + m.v1.y * v.y + m.v1.z * v.z,
    m.v2.x * v.x + m.v2.y * v.y + m.v2.z * v.z,
    m.v3.x * v.x + m.v3.y * v.y + m.v3.z * v.z
  );
}

Matrix33 operator*(const Matrix33& m1, const Matrix33& m2) {
  Matrix33 result;
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      result[r][c] = m1[r][0]*m2[0][c] + m1[r][1]*m2[1][c] + m1[r][2]*m2[2][c];
    }
  }
  return result;
}