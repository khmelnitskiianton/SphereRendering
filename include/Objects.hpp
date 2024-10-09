#pragma once
#ifndef SPHERE_RENDERING_INCLUDE_OBJECTS_HPP
#define SPHERE_RENDERING_INCLUDE_OBJECTS_HPP

namespace GObjects {

  const int DEFAULT_CENTER_X = 0;
  const int DEFAULT_CENTER_Y = 0;
  const int DEFAULT_CENTER_Z = 0;
  const int DEFAULT_RADIUS = 1;

  class View {
    int z;

   public:
    View(int new_z = DEFAULT_CENTER_Z) : z(new_z) {}
    int GetZ() const {
      return z;
    }
  };

  class Light {
    int x;
    int y;
    int z;
    ColorRGBA::ColorVector light_color;

   public:
    Light(int new_x = DEFAULT_CENTER_X,
          int new_y = DEFAULT_CENTER_Y,
          int new_z = DEFAULT_CENTER_Z,
          ColorRGBA::ColorVector new_color = ColorRGBA::ColorWhite) :
        x(new_x),
        y(new_y), z(new_z), light_color(new_color) {}
    //=====================================
    int GetX() const {
      return x;
    }
    int GetY() const {
      return y;
    }
    int GetZ() const {
      return z;
    }
    ColorRGBA::ColorVector GetColor() const {
      return light_color;
    }
  };

  static const Light LightZero(0, 0, 0, ColorRGBA::ColorWhite);

  class Sphere {
    int x_c;
    int y_c;
    int r;
    View eye;
    ColorRGBA::ColorVector sphere_color;

   public:
    Sphere(int new_x = DEFAULT_CENTER_X,
           int new_y = DEFAULT_CENTER_Y,
           int radius = DEFAULT_RADIUS,
           int eye_height = DEFAULT_CENTER_Z,
           ColorRGBA::ColorVector new_color = ColorRGBA::ColorBlue);
    //Draw=================================
    void SphereDraw(GSystem::GraphicSystem &system, Light &light, double ambient_coeff);
    ColorRGBA::ColorVector ProcessLightColor(int pixel_x, int pixel_y, Light &light, double ambient_coeff);
    //=====================================
    void SetXC(int new_x_c) {
      x_c = new_x_c;
    }
    void SetYC(int new_y_c) {
      y_c = new_y_c;
    }
    //=====================================
    int GetXC() const {
      return x_c;
    }
    int GetYC() const {
      return y_c;
    }
    int GetR() const {
      return r;
    }
    ColorRGBA::ColorVector GetColor() const {
      return sphere_color;
    }
  };

}// namespace GObjects

#endif//SPHERE_RENDERING_INCLUDE_OBJECTS_HPP