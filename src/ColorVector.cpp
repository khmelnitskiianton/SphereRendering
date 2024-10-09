#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdlib.h>

#include "Vector.hpp"
#include "ColorVector.hpp"
#include "Support.hpp"

namespace ColorRGBA {

  ColorVector::ColorVector(Uint8 new_r, Uint8 new_g, Uint8 new_b, Uint8 new_a) : r(new_r), g(new_g), b(new_b), a(new_a) {}

  ColorVector::ColorVector(const ColorVector &new_vector) {//copy constructor
    r = new_vector.r;
    g = new_vector.g;
    b = new_vector.b;
    a = new_vector.a;
  }

  ColorVector &ColorVector::operator=(const ColorVector &new_vector)//copy assignment
  {
    if (this != &new_vector) {
      r = new_vector.r;
      g = new_vector.g;
      b = new_vector.b;
      a = new_vector.a;
    }
    return *this;
  }
  //Convert
  sf::Color ColorVector::ColorVectorToSFMLColor() {
    return sf::Color(r, g, b, a);
  }
  Vector3D::Vector3 ColorVector::ColorVectorToVector3() {
    return Vector3D::Vector3(r, g, b);
  }
  ColorVector SFMLColorToColorVector(const sf::Color &color) {
    return ColorVector(color.r, color.g, color.b, color.a);
  }
  ColorVector Vector3ToColorVector(const Vector3D::Vector3 &a) {
    return ColorVector(Uint8OverflowDouble(a.x), Uint8OverflowDouble(a.y), Uint8OverflowDouble(a.z), UINT8_MAX);
  }
  ColorVector MultByElement(const ColorVector &a, const ColorVector &b) {
    ColorVector ColorVector((Uint8) (int(a.r) * int(b.r) / UINT8_MAX),
                            (Uint8) (int(a.g) * int(b.g) / UINT8_MAX),
                            (Uint8) (int(a.b) * int(b.b) / UINT8_MAX),
                            UINT8_MAX);
    //std::cout << (Uint8)(int(a.r) * int(b.r) / UINT8_MAX);
    return ColorVector;
  }

  //Base
  ColorVector operator+(const ColorVector &a, const ColorVector &b) {
    return ColorVector(a.r + b.r, a.g + b.g, a.b + b.b);
  }
  ColorVector operator-(const ColorVector &a, const ColorVector &b) {
    return ColorVector(a.r - b.r, a.g - b.g, a.b - b.b);
  }

  //Multiply by scalar
  ColorVector operator*(const ColorVector &a, const double &scalar) {
    return ColorVector(Uint8OverflowDouble(double(a.r) * scalar),
                       Uint8OverflowDouble(double(a.g) * scalar),
                       Uint8OverflowDouble(double(a.b) * scalar),
                       UINT8_MAX);
  }
  ColorVector operator*(const double &scalar, const ColorVector &a) {
    return a * scalar;
  }

  //References
  ColorVector &operator+=(ColorVector &a, const ColorVector &b) {
    a.r += b.r;
    a.g += b.g;
    a.b += b.b;
    return a;
  }
  ColorVector &operator-=(ColorVector &a, const ColorVector &b) {
    a.r -= b.r;
    a.g -= b.g;
    a.b -= b.b;
    return a;
  }
  ColorVector &operator*=(ColorVector &a, const double &scalar) {
    a.r = Uint8OverflowDouble(double(a.r) * scalar);
    a.g = Uint8OverflowDouble(double(a.g) * scalar);
    a.b = Uint8OverflowDouble(double(a.b) * scalar);
    return a;
  }
  //Bool
  bool operator==(const ColorVector &a, const ColorVector &b) {
    return (a.r == b.r) && (a.g == b.g) && (a.b == b.b) && (a.a == b.a);
  }
  bool operator!=(const ColorVector &a, const ColorVector &b) {
    return (a.r != b.r) || (a.g != b.g) || (a.b != b.b) || (a.a != b.a);
  }

  //Output
  std::istream &operator>>(std::istream &input, ColorVector &in_color) {
    Uint8 r, g, b, a;
    input >> r >> g >> b >> a;
    if (input) {
      in_color.r = r;
      in_color.g = g;
      in_color.b = b;
      in_color.a = a;
    }
    return input;
  }
  std::ostream &operator<<(std::ostream &output, const ColorVector &out_color) {
    return output << static_cast<unsigned int>(out_color.r) << " " << static_cast<unsigned int>(out_color.g) << " "
                  << static_cast<unsigned int>(out_color.b) << " " << static_cast<unsigned int>(out_color.a);
  }

}//namespace ColorRGBA