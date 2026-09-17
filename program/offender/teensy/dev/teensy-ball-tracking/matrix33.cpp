#include <math.h>

#include "matrix33.hpp"

Vec3 operator+(const Vec3& v1, const Vec3& v2){
  Vec3 v;
  v.x1 = v1.x1 + v2.x1;
  v.x2 = v1.x2 + v2.x2;
  v.x3 = v1.x3 + v2.x3;
  return v;
}

Vec3 operator-(const Vec3& v1, const Vec3& v2){
  Vec3 v;
  v.x1 = v1.x1 - v2.x1;
  v.x2 = v1.x2 - v2.x2;
  v.x3 = v1.x3 - v2.x3;
  return v;
}

Vec3 operator*(const Vec3& v, const float f){
  Vec3 r;
  r.x1 = v.x1 * f;
  r.x2 = v.x2 * f;
  r.x3 = v.x3 * f;
  return r;
}

Vec3 operator*(const float f, const Vec3& v){
  Vec3 r;
  r.x1 = f * v.x1;
  r.x2 = f * v.x2;
  r.x3 = f * v.x3;
  return r;
}

Vec3& Vec3::operator+=(const Vec3& v){
  x1 += v.x1;
  x2 += v.x2;
  x3 += v.x3;
  return *this;
}

Vec3& Vec3::operator-=(const Vec3& v){
  x1 -= v.x1;
  x2 -= v.x2;
  x3 -= v.x3;
  return *this;
}

Vec3& Vec3::operator*=(const float f){
  x1 *= f;
  x2 *= f;
  x3 *= f;
  return *this;
}

Vec3& Vec3::operator/=(const float f){
  x1 /= f;
  x2 /= f;
  x3 /= f;
  return *this;
}

Vec3& Vec3::operator=(const Vec3& v){
  x1 = v.x1;
  x2 = v.x2;
  x3 = v.x3;
  return *this;
}


void Vec3::set(float vec_x1, float vec_x2, float vec_x3){
  x1 = vec_x1;
  x2 = vec_x2;
  x3 = vec_x3;
  return;
}

void Vec2::clear(){
  x1 = 0.0f;
  x2 = 0.0f;
  x3 = 0.0f;
  return;
}

Matrix33 operator+(const Matrix33& m1, const Matrix33& m2){
  return Matrix33(m1.v1+m2.v1, m1.v2+m2.v2, m1.v3+m2.v3);
}

Matrix33 operator-(const Matrix33& m1, const Matrix33& m2) {
  return Matrix33(m1.v1-m2.v1, m1.v2-m2.v2, m1.v3-m2.v3);
}

Vec3 operator*(const Matrix33& m, const Vec3& v) {
  return Vec3(
    m.v1.x1 * v.x1 + m.v1.x2 * v.x2 + m.v1.x3 * v.x3,
    m.v2.x1 * v.x1 + m.v2.x2 * v.x2 + m.v2.x3 * v.x3,
    m.v3.x1 * v.x1 + m.v3.x2 * v.x2 + m.v3.x3 * v.x3
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