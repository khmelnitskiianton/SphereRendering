#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdlib.h>

#include "Vector.hpp"
#include "Support.hpp"

namespace Vector3D {

  Vector3::Vector3(vec3_el new_x, vec3_el new_y, vec3_el new_z) : x(new_x), y(new_y), z(new_z) {}

  Vector3::Vector3(const Vector3 &new_vector)//copy constructor
  {
    x = new_vector.x;
    y = new_vector.y;
    z = new_vector.z;
  }

  Vector3 &Vector3::operator=(const Vector3 &new_vector)//copy assignment
  {
    if (this != &new_vector) {
      x = new_vector.x;
      y = new_vector.y;
      z = new_vector.z;
    }
    return *this;
  }

  vec3_el Length(const Vector3 &a) {
    return static_cast<vec3_el>(std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
  }

  Vector3 Normal(const Vector3 &a) {
    return a / Length(a);
  }

  Vector3 MultByElement(const Vector3 &a, const Vector3 &b) {
    return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
  }

  //Base
  Vector3 operator+(const Vector3 &a, const Vector3 &b) {
    return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
  }
  Vector3 operator-(const Vector3 &a, const Vector3 &b) {
    return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
  }
  vec3_el operator*(const Vector3 &a, const Vector3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  //Multiply by scalar
  Vector3 operator*(const Vector3 &a, const vec3_el &scalar) {
    return Vector3(a.x * scalar, a.y * scalar, a.z * scalar);
  }
  Vector3 operator*(const vec3_el &scalar, const Vector3 &a) {
    return a * scalar;
  }
  Vector3 operator/(const Vector3 &a, const vec3_el &scalar) {
    return Vector3(a.x / scalar, a.y / scalar, a.z / scalar);
  }

  //References
  Vector3 &operator+=(Vector3 &a, const Vector3 &b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
  }
  Vector3 &operator-=(Vector3 &a, const Vector3 &b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
  }
  Vector3 &operator*=(Vector3 &a, const vec3_el &scalar) {
    a.x *= scalar;
    a.y *= scalar;
    a.z *= scalar;
    return a;
  }
  Vector3 &operator/=(Vector3 &a, const vec3_el &scalar) {
    a.x /= scalar;
    a.y /= scalar;
    a.z /= scalar;
    return a;
  }
  //Bool
  bool operator==(const Vector3 &a, const Vector3 &b) {
    return (!compare_doubles(a.x, b.x)) && (!compare_doubles(a.y, b.y)) && (!compare_doubles(a.z, b.z));
  }
  bool operator!=(const Vector3 &a, const Vector3 &b) {
    return (compare_doubles(a.x, b.x)) || (compare_doubles(a.y, b.y)) || (compare_doubles(a.z, b.z));
  }

  //Unary
  Vector3 operator-(const Vector3 &a) {
    return Vector3(a.x * (-1), a.y * (-1), a.z * (-1));
  }

  //Output
  std::istream &operator>>(std::istream &input, Vector3 &a) {
    vec3_el x, y, z;
    input >> x >> y >> z;
    if (input) {
      a.x = x;
      a.y = y;
      a.z = z;
    }
    return input;
  }
  std::ostream &operator<<(std::ostream &output, const Vector3 &a) {
    output << a.x << " " << a.y << " " << a.z;
    return output;
  }

};// namespace Vector3D

//=======================================================================================
//=======================================================================================

namespace Vector2D {

  Vector2::Vector2(vec2_el new_x, vec2_el new_y, System system) : x(new_x), y(new_y), system(system) {}

  Vector2::Vector2(const Vector2 &new_vector)//copy constructor
  {
    x = new_vector.x;
    y = new_vector.y;
    system = new_vector.system;
  }

  Vector2 &Vector2::operator=(const Vector2 &new_vector)//copy assignment
  {
    if (this != &new_vector) {
      x = new_vector.x;
      y = new_vector.y;
      system = new_vector.system;
    }
    return *this;
  }

  vec2_el Length(const Vector2 &a) {
    if (a.system == Cartesian)
      return static_cast<vec2_el>(std::sqrt(a.x * a.x + a.y * a.y));
    if (a.system == Polar)
      return a.y;
    return 0;
  }

  Vector2 Normal(const Vector2 &a) {
    return a / Length(a);
  }

  Vector2 MultByElement(const Vector2 &a, const Vector2 &b) {
    return Vector2(a.x * b.x, a.y * b.y);
  }

  Vector2 CartesianToPolar(const Vector2 &a) {
    if (a.system == Cartesian)
      return Vector2(Length(a), acos(a.x / Length(a)), Polar);
    return Vector2(0, 0, Polar);
  }

  Vector2 PolarToCartesian(const Vector2 &a) {
    if (a.system == Polar)
      return Vector2(a.x * cos(a.y), a.x * sin(a.y));
    return Vector2(0, 0);
  }

  //Base
  Vector2 operator+(const Vector2 &a, const Vector2 &b) {
    return Vector2(a.x + b.x, a.y + b.y, a.system);
  }
  Vector2 operator-(const Vector2 &a, const Vector2 &b) {
    return Vector2(a.x - b.x, a.y - b.y, a.system);
  }
  vec2_el operator*(const Vector2 &a, const Vector2 &b) {
    if (a.system == Cartesian)
      return a.x * b.x + a.y * b.y;
    if (a.system == Polar)
      return static_cast<vec2_el>(a.x * b.x * cos(b.y - a.y));
    return 0;
  }

  //Multiply by scalar
  Vector2 operator*(const Vector2 &a, const vec2_el &scalar) {
    if (a.system == Cartesian)
      return Vector2(a.x * scalar, a.y * scalar);
    if (a.system == Polar)
      return Vector2(a.x * scalar, a.y, Polar);
    return Vector2(0, 0);
  }
  Vector2 operator*(const vec2_el &scalar, const Vector2 &a) {
    return a * scalar;
  }
  Vector2 operator/(const Vector2 &a, const vec2_el &scalar) {
    if (a.system == Cartesian)
      return Vector2(a.x / scalar, a.y / scalar);
    if (a.system == Polar)
      return Vector2(a.x / scalar, a.y, Polar);
    return Vector2(0, 0);
  }

  //References
  Vector2 &operator+=(Vector2 &a, const Vector2 &b) {
    a.x += b.x;
    a.y += b.y;
    return a;
  }
  Vector2 &operator-=(Vector2 &a, const Vector2 &b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
  }
  Vector2 &operator*=(Vector2 &a, const vec2_el &scalar) {
    a.x *= scalar;
    a.y *= scalar;
    return a;
  }
  Vector2 &operator/=(Vector2 &a, const vec2_el &scalar) {
    a.x /= scalar;
    a.y /= scalar;
    return a;
  }
  //Bool
  bool operator==(const Vector2 &a, const Vector2 &b) {
    return (!compare_doubles(a.x, b.x)) && (!compare_doubles(a.y, b.y));
  }
  bool operator!=(const Vector2 &a, const Vector2 &b) {
    return (compare_doubles(a.x, b.x)) || (compare_doubles(a.y, b.y));
  }

  //Unary
  Vector2 operator-(const Vector2 &a) {
    if (a.system == Cartesian)
      return Vector2(a.x * (-1), a.y * (-1));
    if (a.system == Polar)
      return Vector2(a.x, a.y + M_PI, Polar);
    return Vector2(0, 0);
  }

  //Output
  std::istream &operator>>(std::istream &input, Vector2 &a) {
    vec2_el x, y;
    input >> x >> y;
    if (input) {
      a.x = x;
      a.y = y;
    }
    return input;
  }
  std::ostream &operator<<(std::ostream &output, const Vector2 &a) {
    output << a.x << " " << a.y;
    return output;
  }

};// namespace Vector2D