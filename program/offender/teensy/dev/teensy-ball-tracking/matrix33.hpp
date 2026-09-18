#pragma once

#include <Arduino.h>
#include <math.h>

class Vec3{
  public:
    float x, y, z;
    Vec3() : x(0.0f), y(0.0f), z(0.0f){}
    Vec3(float vec_x, float vec_y, float vec_z) : x(vec_x), y(vec_y), z(vec_z){}

    float& operator[](int i){
      return (i==0) ? x : (i==1) ? y : z;
    }
    const float& operator[](int i) const{
      return (i==0) ? x : (i==1) ? y : z;
    }

    Vec3& operator+=(const Vec3& v);
    Vec3& operator-=(const Vec3& v);
    Vec3& operator*=(const float f);
    Vec3& operator/=(const float f);
    Vec3& operator=(const Vec3& v);

    void set(float vec_x, float vec_y, float vec_z);
    void clear();
    float len() const;
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

    static Matrix33 rotX(float deg){
      double c = cos(deg / 180.0f * 3.14159265);
      double s = sin(deg / 180.0f * 3.14159265);

      return Matrix33(
        1, 0, 0,
        0, c, -s,
        0, s, c);
    }

    static Matrix33 rotY(float deg){
      double c = cos(deg / 180.0f * 3.14159265);
      double s = sin(deg / 180.0f * 3.14159265);

      return Matrix33(
        c, 0, s,
        0, 1, 0,
        -s, 0, c);
    }

    static Matrix33 rotZ(float deg){
      double c = cos(deg / 180.0f * 3.14159265);
      double s = sin(deg / 180.0f * 3.14159265);

      return Matrix33(
        c, -s, 0,
        s, c, 0,
        0, 0, 1);
    }
};

Matrix33 operator+(const Matrix33& m1, const Matrix33& m2);
Matrix33 operator-(const Matrix33& m1, const Matrix33& m2);
Matrix33 operator*(const Matrix33& m1, const Matrix33& m2);
Matrix33 operator*(const Matrix33& m, const float f);
Vec3 operator*(const Matrix33& m, const Vec3& v);