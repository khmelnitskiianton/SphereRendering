#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdlib.h>

#include "ColorVector.hpp"
#include "Graphics.hpp"
#include "Objects.hpp"
#include "Vector.hpp"

namespace GObjects {

  Sphere::Sphere(int new_x, int new_y, int radius, ColorRGBA::ColorVector new_color) :
      x_c(new_x), y_c(new_y), r(radius), sphere_color(new_color) {}

  void Sphere::SphereDraw(GSystem::GraphicSystem &system, Light &light, double ambient_coeff) {
    // Midpoint Circle Algorithm
    int x = r;
    int y = 0;
    int p = 1 - r;// Initial decision parameter

    while (x >= y) {
      for (int i = x_c - x; i <= x_c + x; i++) {
        //std::cout << "I = x_c - x: " << i << "\n";
        system.DrawPixelRelatively(i, y_c + y, ProcessLightColor(i, y_c + y, light, ambient_coeff));
        system.DrawPixelRelatively(i, y_c - y, ProcessLightColor(i, y_c - y, light, ambient_coeff));
      }
      for (int i = x_c - y; i <= x_c + y; i++) {
        system.DrawPixelRelatively(i, y_c + x, ProcessLightColor(i, y_c + x, light, ambient_coeff));
        system.DrawPixelRelatively(i, y_c - x, ProcessLightColor(i, y_c - x, light, ambient_coeff));
      }
      y++;
      // Update decision parameter based on midpoint circle algorithm rules
      if (p <= 0) {
        p += 2 * y + 1;
      } else {
        x--;
        p += 2 * y - 2 * x + 1;
      }
    }
  }

  ColorRGBA::ColorVector Sphere::ProcessLightColor(int pixel_x, int pixel_y, Light &light, double ambient_coeff) {
    //Lambert Diffusion Lightning
    //Vector from center of sphere to edge
    int pixel_rel_x = pixel_x;
    int pixel_rel_y = pixel_y;
    double radius_2d = sqrt(pixel_rel_x * pixel_rel_x + pixel_rel_y * pixel_rel_y);
    //std::cout << "DICK: " << pixel_x << " " << pixel_y << "\n";
    int pixel_rel_z = (int) (sqrt(abs(r * r - radius_2d * radius_2d)));
    //std::cout << "SUCK: " << (pixel_rel_x * pixel_rel_x + pixel_rel_y * pixel_rel_y) << "\n";
    //std::cout << "Pixel_rel " << pixel_rel_x << " " << pixel_rel_y <<  " " << pixel_rel_z << "\n";

    Vector3D::Vector3 center_to_edge(-pixel_rel_x, -pixel_rel_y, -pixel_rel_z);
    //Vector from light to edge
    int pixel_light_x = pixel_x - light.GetX();
    int pixel_light_y = pixel_y - light.GetY();
    int pixel_light_z = pixel_rel_z - light.GetZ();

    //std::cout << "Pixel_light " << pixel_light_x << " " << pixel_light_y <<  " " << pixel_light_z << "\n";

    Vector3D::Vector3 light_to_edge(pixel_light_x, pixel_light_y, pixel_light_z);

    //std::cout << "Light_to_edge: " << light_to_edge << "\n";
    //std::cout << "center_to_edge: " << center_to_edge << "\n";

    double cos_sphere_light = (center_to_edge * light_to_edge) /
                              (Vector3D::Length(center_to_edge) * Vector3D::Length(light_to_edge));// scalar multiplier
    if (cos_sphere_light <= 0)
      cos_sphere_light = 0;

    //std::cout << "Cos: " << cos_sphere_light << "\n";
    //std::cout << "Sphere: " << sphere_color << "\n";
    //std::cout << "Light " << light.GetColor() << "\n";

    //std::cout << "Mult " << ColorRGBA::MultByElement(sphere_color, light.GetColor()) << "\n";

    ColorRGBA::ColorVector result_color =
        ColorRGBA::MultByElement(sphere_color, light.GetColor()) * (cos_sphere_light + ambient_coeff);

    //std::cout << "Result: " << result_color << "\n";

    return result_color;
  }

}// namespace GObjects