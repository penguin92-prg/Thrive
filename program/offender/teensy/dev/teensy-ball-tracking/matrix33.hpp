#pragma once

#include <Arduino.h>

class Vec3{
  public:
    float x1, x2, x3;
    Vec3() : x1(0.0f), x2(0.0f), x3(0.0f){}
    Vec3(float vec_x1, float vec_x2, float vec_x3) : x1(vec_x1), x2(vec_x2), x3(vec_x3){}

    float& operator[](int i){
      return (i==0) ? x1 : (i==1) ? x2 : x3;
    }
    const float& operator[](int i) const{
      return (i==0) ? x1 : (i==1) ? x2 : x3;
    }

    Vec3& operator+=(const Vec3& v);
    Vec3& operator-=(const Vec3& v);
    Vec3& operator*=(const float f);
    Vec3& operator/=(const float f);
    Vec3& operator=(const Vec3& v);

    void set(float vec_x1, float vec_x2, float vec_x3);
    void clear();
};

Vec3 operator+(const Vec3& v1, const Vec3& v2);
Vec3 operator-(const Vec3& v1, const Vec3& v2);
Vec3 operator*(const Vec3& v1, const float f);
Vec3 operator*(const float f, const Vec3& v);

class Matrix33{
  public:
    Vec3 v1, v2, v3;
    Matrix33() : v1(), v2(), v3(){}
    Matrix33(const Vec3 matrix_v1, const Vec3 matrix_v2, const Vec3 matrix_v3) : v1(matrix_v1), v2(matrix_v2), v3(matrix_v3){}
    Matrix33(
      float m00, float m01, float m02,
      float m10, float m11, float m12,
      float m20, float m21, float m22)
    : v1(m00, m01, m02), v2(m10, m11, m12), v3(m20, m21, m22){}
    
    Vec3& operator[](int i){
      return (i==0) ? v1 : (i==1) ? v2 : v3;
    }
    const Vec3& operator[](int i) const{
      return (i==0) ? v1 : (i==1) ? v2 : v3;
    }

    Matrix33& operator+=(const Matrix33& matrix);
    Matrix33& operator-=(const Matrix33& matrix);
    Matrix33& operator*=(const Matrix33& matrix);
    Matrix33& operator*=(const float f);

    void set(Vec3 matrix_v1, Vec3 matrix_v2, Vec3 matrix_v3);
    void clear();

    static Matrix33 identity(){
      return Matrix33(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);
    }
};

Matrix33 operator+(const Matrix33& m1, const Matrix33& m2);
Matrix33 operator-(const Matrix33& m1, const Matrix33& m2);
Matrix33 operator*(const Matrix33& m1, const Matrix33& m2);
Vec3 operator*(const Matrix33& m, const Vec3& v);