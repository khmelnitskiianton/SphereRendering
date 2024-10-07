#include <cstdint>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sys/types.h>

#include "ColorVector.hpp"

namespace ColorRGBA {

ColorVector::ColorVector(Uint8 new_r, Uint8 new_g, Uint8 new_b, Uint8 new_a) 
    : r(new_r), 
      g(new_g), 
      b(new_b), 
      a(new_a) {}

ColorVector::ColorVector(const ColorVector& new_vector) { //copy constructor 
    r = new_vector.r;
    g = new_vector.g;
    b = new_vector.b;
    a = new_vector.a;
}

ColorVector& ColorVector::operator= (const ColorVector& new_vector) //copy assignment
{
    if (this != &new_vector)
    {
        r = new_vector.r;
        g = new_vector.g;
        b = new_vector.b;
        a = new_vector.a;
    }
    return *this;
}

//Base
ColorVector operator+ (const ColorVector& a, const ColorVector& b) {
    return ColorVector(a.r+b.r, a.g+b.g, a.b+b.b, a.a+b.a);
} 
ColorVector operator- (const ColorVector& a, const ColorVector& b) {
    return ColorVector(a.r-b.r, a.g-b.g, a.b-b.b, a.a-b.a);
}
ColorVector operator* (const ColorVector& a, const ColorVector& b) {
    return ColorVector(a.r*b.r, a.g*b.g, a.b*b.b, a.a*b.a);
} 
ColorVector operator/ (const ColorVector& a, const ColorVector& b) {
    return ColorVector(a.r/b.r, a.g/b.g, a.b/b.b, a.a/b.a);
} 


//Multiply by scalar
ColorVector operator* (const ColorVector& a, const Uint8& scalar){
    return ColorVector(a.r*scalar, a.g*scalar, a.b*scalar, a.a*scalar);
}
ColorVector operator* (const Uint8& scalar, const ColorVector& a) {
    return ColorVector(a.r*scalar, a.g*scalar, a.b*scalar, a.a*scalar);
}
ColorVector operator/ (const ColorVector& a, const Uint8& scalar) {
    return ColorVector(a.r/scalar, a.g/scalar, a.b/scalar, a.a/scalar);
}

//References
ColorVector& operator+= (ColorVector& a, const ColorVector& b) {
    a.r += b.r;
    a.g += b.g;
    a.b += b.b;
    a.a += b.a;
    return a;
} 
ColorVector& operator-= (ColorVector& a, const ColorVector& b) {
    a.r -= b.r;
    a.g -= b.g;
    a.b -= b.b;
    a.a -= b.a;
    return a;
} 
ColorVector& operator*= (ColorVector& a, const ColorVector& b) {
    a.r *= b.r;
    a.g *= b.g;
    a.b *= b.b;
    a.a += b.a;
    return a;
} 
ColorVector& operator*= (ColorVector& a, const Uint8& scalar) {
    a.r *= scalar;
    a.g *= scalar;
    a.b *= scalar;
    a.a *= scalar;
    return a;
} 
ColorVector& operator/= (ColorVector& a, const ColorVector& b) {
    a.r /= b.r;
    a.g /= b.g;
    a.b /= b.b;
    a.a /= b.a;
    return a;
} 
ColorVector& operator/= (ColorVector& a, const Uint8& scalar) {
    a.r /= scalar;
    a.g /= scalar;
    a.b /= scalar;
    a.a /= scalar;
    return a;
} 
//Bool
bool operator== (const ColorVector& a, const ColorVector& b) {
    return (a.r == b.r) && (a.g == b.g) && (a.b == b.b) && (a.a == b.a);
}
bool operator!= (const ColorVector& a, const ColorVector& b) {
    return (a.r != b.r) || (a.g != b.g) || (a.b != b.b) || (a.a != b.a);
}

//Output
std::istream& operator>> (std::istream& input, ColorVector& in_color)
{
    Uint8 r,g,b,a;
    input >> r >> g >> b >> a;
    if (input){
        in_color.r = r;
        in_color.g = g;
        in_color.b = b;
        in_color.a = a;
    }
    return input;
}
std::ostream& operator<< (std::ostream& output, const ColorVector& out_color)
{
    output << out_color.r << " " << out_color.g << " " << out_color.b << " " << out_color.b;
    return output;
}

} //namespace ColorRGBA