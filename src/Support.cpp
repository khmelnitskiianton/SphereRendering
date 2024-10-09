#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdint>
#include <stdlib.h>

#include "ColorVector.hpp"
#include "Support.hpp"

static const double EPSILON = 1e-5;

int compare_doubles(double x, double y) {
  if (abs(x - y) < EPSILON)
    return 0;
  if (x > y)
    return 1;
  return -1;
}

int min(int x, int y) {
  return (x < y) ? x : y;
}

int max(int x, int y) {
  return (x < y) ? y : x;
}

ColorRGBA::Uint8 Uint8OverflowInt(int x) {
  if (x > (int) (UINT8_MAX))
    return UINT8_MAX;
  if (x < 0)
    return 0;
  return (ColorRGBA::Uint8) x;
}

ColorRGBA::Uint8 Uint8OverflowDouble(double x) {
  int int_x = (int) x;
  if (int_x > (int) (UINT8_MAX))
    return UINT8_MAX;
  if (int_x < 0)
    return 0;
  return (ColorRGBA::Uint8) int_x;
}