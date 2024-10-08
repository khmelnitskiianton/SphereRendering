#pragma once
#ifndef SPHERE_RENDERING_COLOR_VECTOR_HPP
  #define SPHERE_RENDERING_COLOR_VECTOR_HPP

#include "Vector.hpp"

namespace ColorRGBA {

  // 8 bits integer types
  typedef signed char Int8;
  typedef unsigned char Uint8;

  // 16 bits integer types
  typedef signed short Int16;
  typedef unsigned short Uint16;

  // 32 bits integer types
  typedef signed int Int32;
  typedef unsigned int Uint32;

  // 64 bits integer types
  #if defined(_MSC_VER)
  typedef signed __int64 Int64;
  typedef unsigned __int64 Uint64;
  #else
  typedef signed long long Int64;
  typedef unsigned long long Uint64;
  #endif

  class ColorVector {
   public:
    //Constructors
    ColorVector(Uint8 new_r = 0, Uint8 new_g = 0, Uint8 new_b = 0, Uint8 new_a = UINT8_MAX);
    ColorVector(const ColorVector &new_vector);           //copy constructor
    ColorVector &operator=(const ColorVector &new_vector);//copy assignment

    sf::Color ColorVectorToSFMLColor();
    Vector3D::Vector3 ColorVectorToVector3();

    void SetAlphaChannel(Uint8 new_a) {
      a = new_a;
    }
    Uint8 GetAlphaChannel() {
      return a;
    }
    //Data
    Uint8 r;///< Red component
    Uint8 g;///< Green component
    Uint8 b;///< Blue component
    Uint8 a;///< Alpha (opacity) component
    //Static color
  };

  ColorVector Vector3ToColorVector(const Vector3D::Vector3 &a);
  ColorVector SFMLColorToColorVector(const sf::Color &color);
  ColorVector MultByElement(const ColorVector &a, const ColorVector &b);

  //Operators
  ColorVector operator+(const ColorVector &a, const ColorVector &b);
  ColorVector operator-(const ColorVector &a, const ColorVector &b);

  ColorVector operator*(const ColorVector &a, const double &scalar);
  ColorVector operator*(const double &scalar, const ColorVector &a);

  ColorVector &operator+=(ColorVector &a, const ColorVector &b);
  ColorVector &operator-=(ColorVector &a, const ColorVector &b);
  ColorVector &operator*=(ColorVector &a, const double &scalar);

  bool operator==(const ColorVector &a, const ColorVector &b);
  bool operator!=(const ColorVector &a, const ColorVector &b);

  ColorVector operator-(const ColorVector &a);

  std::ostream &operator<<(std::ostream &output, const ColorVector &out_color);
  std::istream &operator>>(std::istream &input, ColorVector &in_color);

  static const ColorVector ColorBlack(0, 0, 0, 255);
  static const ColorVector ColorWhite(255, 255, 255, 255);
  static const ColorVector ColorBlue(0, 0, 255, 255);
  static const ColorVector ColorRed(255, 0, 0, 255);
  static const ColorVector ColorGreen(0, 255, 0, 255);
}//namespace ColorRGBA

#endif//SPHERE_RENDERING_COLOR_VECTOR_HPP