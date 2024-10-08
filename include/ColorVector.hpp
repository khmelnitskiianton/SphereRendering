#pragma once
#ifndef SPHERE_RENDERING_COLOR_VECTOR_HPP
  #define SPHERE_RENDERING_COLOR_VECTOR_HPP

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
    ColorVector(Uint8 new_r = Uint8(), Uint8 new_g = Uint8(), Uint8 new_b = Uint8(), Uint8 new_a = Uint8());
    ColorVector(const ColorVector &new_vector);           //copy constructor
    ColorVector &operator=(const ColorVector &new_vector);//copy assignment

    sf::Color ColorVectorToSFMLColor(const ColorVector &color);
    ColorVector SFMLColorToColorVector(const sf::Color &color);
    //Data
    Uint8 r;///< Red component
    Uint8 g;///< Green component
    Uint8 b;///< Blue component
    Uint8 a;///< Alpha (opacity) component
    //Static color
  };

  //Operators
  ColorVector operator+(const ColorVector &a, const ColorVector &b);
  ColorVector operator-(const ColorVector &a, const ColorVector &b);
  ColorVector operator*(const ColorVector &a, const ColorVector &b);
  ColorVector operator/(const ColorVector &a, const ColorVector &b);

  ColorVector operator*(const ColorVector &a, const Uint8 &scalar);
  ColorVector operator*(const Uint8 &scalar, const ColorVector &a);
  ColorVector operator/(const ColorVector &a, const Uint8 &scalar);

  ColorVector &operator+=(ColorVector &a, const ColorVector &b);
  ColorVector &operator-=(ColorVector &a, const ColorVector &b);
  ColorVector &operator*=(ColorVector &a, const ColorVector &b);
  ColorVector &operator*=(ColorVector &a, const Uint8 &scalar);
  ColorVector &operator/=(ColorVector &a, const ColorVector &b);
  ColorVector &operator/=(ColorVector &a, const Uint8 &scalar);

  bool operator==(const ColorVector &a, const ColorVector &b);
  bool operator!=(const ColorVector &a, const ColorVector &b);

  ColorVector operator-(const ColorVector &a);

  std::istream &operator>>(std::istream &input, ColorVector &in_color);
  std::ostream &operator<<(std::ostream &output, const ColorVector &out_color);

  static const ColorVector Blue(0, 0, 255, 255);
}//namespace ColorRGBA

#endif//SPHERE_RENDERING_COLOR_VECTOR_HPP