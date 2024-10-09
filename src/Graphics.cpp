#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdlib.h>

#include "Vector.hpp"
#include "ColorVector.hpp"
#include "Graphics.hpp"
#include "Support.hpp"

namespace GSystem {

  GraphicSystem::GraphicSystem(int dry_width, int dry_height, const char *init_title, ColorRGBA::ColorVector init_bckg_color) {
    unsigned int clean_width = static_cast<unsigned int>(abs(dry_width));
    unsigned int clean_height = static_cast<unsigned int>(abs(dry_height));
    width = clean_width < MAX_WIDTH ? clean_width : MAX_WIDTH;
    height = clean_height < MAX_HEIGHT ? clean_height : MAX_HEIGHT;
    area = width * height;

    center_x = static_cast<int>(width / 2);
    center_y = static_cast<int>(height / 2);

    pixels = new uint8_t[area * 4] {};

    bckg_color = init_bckg_color;
    title = init_title;
  }

  GraphicSystem::~GraphicSystem() {
    delete[] pixels;
  }

  void GraphicSystem::Clear() {
    for (unsigned int i = 0; i < height; i++) {
      for (unsigned int j = 0; j < width; j++) {
        *(pixels + i * width + j + 0) = 0;
        *(pixels + i * width + j + 1) = 0;
        *(pixels + i * width + j + 2) = 0;
        *(pixels + i * width + j + 3) = 0;
      }
    }
    delete[] pixels;
    pixels = new uint8_t[area * 4] {};
  }

  void GraphicSystem::Resize(int new_width, int new_height) {
    unsigned int clean_width = static_cast<unsigned int>(abs(new_width));
    unsigned int clean_height = static_cast<unsigned int>(abs(new_height));
    width = (clean_width < MAX_WIDTH) ? clean_width : MAX_WIDTH;
    height = (clean_height < MAX_HEIGHT) ? clean_height : MAX_HEIGHT;
    area = width * height;

    std::cout << "new: " << width << " " << height << "\n";

    center_x = static_cast<int>(width / 2);
    center_y = static_cast<int>(height / 2);

    delete[] pixels;
    pixels = new uint8_t[area * 4] {};
  }

  void GraphicSystem::DrawPixelAbsolute(int pos_x, int pos_y, ColorRGBA::ColorVector pixel_color) {
    int max_x = int(width);
    int max_y = int(height);

    int shift_x = ((pos_x < (max_x - 1)) ? pos_x : max_x - 1);
    int shift_y = ((pos_y < (max_y - 1)) ? pos_y : max_y - 1);

    unsigned int correct_x = static_cast<unsigned int>((shift_x > 0) ? shift_x : 0);
    unsigned int correct_y = static_cast<unsigned int>((shift_y > 0) ? shift_y : 0);

    unsigned int absolute_shift = correct_y * width * 4 + correct_x * 4;

    //std::cout << "Corr: " << correct_x << " " << correct_y << " " << absolute_shift << " ";

    *(pixels + absolute_shift) = pixel_color.r;
    *(pixels + absolute_shift + 1) = pixel_color.g;
    *(pixels + absolute_shift + 2) = pixel_color.b;
    *(pixels + absolute_shift + 3) = pixel_color.a;

    //std::cout << " +" << "\n";
  }

  void GraphicSystem::DrawPixelRelatively(int pos_x, int pos_y, ColorRGBA::ColorVector pixel_color) {
    int rel_x = min(center_x, int(width) - center_x);
    int rel_y = min(center_y, int(height) - center_y);

    int shift_x = ((pos_x < rel_x) ? pos_x : rel_x);
    int shift_y = ((pos_y < rel_y) ? pos_y : rel_y);

    unsigned int abs_x = static_cast<unsigned int>(((int(center_x) + shift_x) > 0) ? (int(center_x) + shift_x) : 0);
    unsigned int abs_y = static_cast<unsigned int>(((int(center_y) + shift_y) > 0) ? (int(center_y) + shift_y) : 0);

    unsigned int correct_x = (abs_x < (height - 1)) ? abs_x : (height - 1);
    unsigned int correct_y = (abs_y < (width - 1)) ? abs_y : (width - 1);

    unsigned int absolute_shift = correct_y * width * 4 + correct_x * 4;

    //std::cerr << "Corr: " << correct_x << " " << correct_y << " " << absolute_shift << " ";

    *(pixels + absolute_shift) = pixel_color.r;
    *(pixels + absolute_shift + 1) = pixel_color.g;
    *(pixels + absolute_shift + 2) = pixel_color.b;
    *(pixels + absolute_shift + 3) = pixel_color.a;
  }

  void
  GraphicSystem::DrawVector(Vector2D::Vector2 &main_vector, Vector2D::Vector2 &begin_vector, ColorRGBA::ColorVector draw_color) {
    int x0 = center_x + (int) begin_vector.x;
    int y0 = center_y + (int) begin_vector.y;
    int x1 = center_x + (int) main_vector.x;
    int y1 = center_y + (int) main_vector.y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    while (true) {
      //std::cout << "DrawPixel " << x0 << " " << y0 << "\n";
      DrawPixelAbsolute(x0, y0, draw_color);
      // Check if the line has reached end point
      if (x0 == x1 && y0 == y1)
        break;

      int e2 = 2 * err;
      if (e2 > -dy) {
        err -= dy;
        x0 += sx;
      }
      if (e2 < dx) {
        err += dx;
        y0 += sy;
      }
    }
  }

}// namespace GSystem