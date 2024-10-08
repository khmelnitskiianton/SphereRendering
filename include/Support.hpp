#pragma once
#ifndef SPHERE_RENDERING_COLOR_SUPPORT_HPP
  #define SPHERE_RENDERING_COLOR_SUPPORT_HPP

int compare_doubles(double x, double y);
int min(int x, int y);
int max(int x, int y);
ColorRGBA::Uint8 Uint8OverflowInt(int x);
ColorRGBA::Uint8 Uint8OverflowDouble(double x);

#endif//SPHERE_RENDERING_COLOR_SUPPORT_HPP