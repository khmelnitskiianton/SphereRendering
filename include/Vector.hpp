#pragma once
#ifndef SPHERE_RENDERING_VECTOR_HPP
  #define SPHERE_RENDERING_VECTOR_HPP

namespace Vector3D {

  typedef int vec3_el;

  //Class Vector3
  class Vector3 {
   public:
    //Constructors
    Vector3(vec3_el new_x = vec3_el(), vec3_el new_y = vec3_el(), vec3_el new_z = vec3_el());
    Vector3(const Vector3 &new_vector);           //copy constructor
    Vector3 &operator=(const Vector3 &new_vector);//copy assignment
                                                  //Data
    vec3_el x;
    vec3_el y;
    vec3_el z;
  };

  vec3_el Length(const Vector3 &a);
  Vector3 Normal(const Vector3 &a);

  //Operators
  Vector3 operator+(const Vector3 &a, const Vector3 &b);
  Vector3 operator-(const Vector3 &a, const Vector3 &b);
  vec3_el operator*(const Vector3 &a, const Vector3 &b);

  Vector3 operator*(const Vector3 &a, const vec3_el &scalar);
  Vector3 operator*(const vec3_el &scalar, const Vector3 &a);
  Vector3 operator/(const Vector3 &a, const vec3_el &scalar);

  Vector3 &operator+=(Vector3 &a, const Vector3 &b);
  Vector3 &operator-=(Vector3 &a, const Vector3 &b);
  Vector3 &operator*=(Vector3 &a, const vec3_el &scalar);
  Vector3 &operator/=(Vector3 &a, const vec3_el &scalar);

  bool operator==(const Vector3 &a, const Vector3 &b);
  bool operator!=(const Vector3 &a, const Vector3 &b);

  Vector3 operator-(const Vector3 &a);

  std::istream &operator>>(std::istream &input, Vector3 &a);
  std::ostream &operator<<(std::ostream &output, const Vector3 &a);

  static const Vector3 Zero3(0, 0, 0);
};// namespace Vector3D

namespace Vector2D {

  enum System { Cartesian = 0, Polar };

  typedef double vec2_el;

  //Class Vector2
  class Vector2 {
   public:
    vec2_el x;
    vec2_el y;
    System system;
    //Constructors
    Vector2(vec2_el new_x = vec2_el(), vec2_el new_y = vec2_el(), System system = System(0));
    Vector2(const Vector2 &new_vector);           //copy constructor
    Vector2 &operator=(const Vector2 &new_vector);//copy assignment
  };

  vec2_el Length(const Vector2 &a);
  Vector2 Normal(const Vector2 &a);
  Vector2 CartesianToPolar(const Vector2 &a);
  Vector2 PolarToCartesian(const Vector2 &a);

  //Operators
  Vector2 operator+(const Vector2 &a, const Vector2 &b);
  Vector2 operator-(const Vector2 &a, const Vector2 &b);
  vec2_el operator*(const Vector2 &a, const Vector2 &b);

  Vector2 operator*(const Vector2 &a, const vec2_el &scalar);
  Vector2 operator*(const vec2_el &scalar, const Vector2 &a);
  Vector2 operator/(const Vector2 &a, const vec2_el &scalar);

  Vector2 &operator+=(Vector2 &a, const Vector2 &b);
  Vector2 &operator-=(Vector2 &a, const Vector2 &b);
  Vector2 &operator*=(Vector2 &a, const vec2_el &scalar);
  Vector2 &operator/=(Vector2 &a, const vec2_el &scalar);

  bool operator==(const Vector2 &a, const Vector2 &b);
  bool operator!=(const Vector2 &a, const Vector2 &b);

  Vector2 operator-(const Vector2 &a);

  std::istream &operator>>(std::istream &input, Vector2 &a);
  std::ostream &operator<<(std::ostream &output, const Vector2 &a);

  static const Vector2 Zero2(0, 0);
};// namespace Vector2D

#endif//SPHERE_RENDERING_VECTOR_HPP