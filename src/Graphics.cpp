#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include <cmath>

#include "Vector.hpp"
#include "Graphics.hpp"

//=======================================================================================
//=======================================================================================

WindowSettings::WindowSettings(int dry_width, int dry_height, const char* init_title, sf::Color init_bckg_color)
{
  unsigned int clean_width  = static_cast<unsigned int>(abs(dry_width));
  unsigned int clean_height = static_cast<unsigned int>(abs(dry_height));
  width  = clean_width  < MAX_WIDTH  ? clean_width  : MAX_WIDTH;
  height = clean_height < MAX_HEIGHT ? clean_height : MAX_HEIGHT;

  bckg_color = init_bckg_color;
  title = init_title;
}


void WindowSettings::SetWidth(int new_width) { 
    unsigned int clean_width = static_cast<unsigned int>(abs(new_width));
    width = clean_width  < MAX_WIDTH  ? clean_width  : MAX_WIDTH;
}
void WindowSettings::SetHeight(int new_height) { 
    unsigned int clean_height = static_cast<unsigned int>(abs(new_height));
    height = clean_height  < MAX_HEIGHT  ? clean_height  : MAX_HEIGHT;
}

//=======================================================================================
//=======================================================================================

Sphere::Sphere(int dry_width, int dry_height, const char* sphere_name, sf::Color bckg_color) 
    : win_info( dry_width, dry_height, sphere_name, bckg_color) {
  area = win_info.GetWidth() * win_info.GetHeight();
  center_x = static_cast<int>(win_info.GetWidth()  / 2);
  center_y = static_cast<int>(win_info.GetHeight() / 2);
  sphere_pixels = new uint8_t[area * 4]{};
}

Sphere::Sphere(const Sphere& s)
{
    area = s.GetArea();
    center_x = s.GetCenterX();
    center_y = s.GetCenterY();
    sphere_pixels = new uint8_t[area * 4]{};
    const uint8_t* src_pixels_ptr = s.GetPixelsPtr();
    for(unsigned int i = 0; i < (area * 4); i++)
    {
        sphere_pixels[i] = src_pixels_ptr[i];
    }
}

Sphere::~Sphere() { delete[] sphere_pixels; }

void Sphere::Resize(int new_width, int new_height)
{
    win_info.SetWidth(new_width);
    win_info.SetHeight(new_height);
    area = win_info.GetWidth() * win_info.GetHeight();
    center_x = static_cast<int>(win_info.GetWidth()  / 2);
    center_y = static_cast<int>(win_info.GetHeight() / 2);
    sphere_pixels = new uint8_t[area * 4]{};
}

void Sphere::DrawPixel(int pos_x, int pos_y, sf::Color pixel_color) {
  int max_x = int(win_info.GetWidth());
  int max_y = int(win_info.GetHeight());
  
  int shift_x = ((pos_x < max_x)  ? pos_x : max_x);
  int shift_y = ((pos_y < max_y) ? pos_y : max_y);
  
  unsigned int correct_x = static_cast<unsigned int>((shift_x > 0) ? shift_x : 0);
  unsigned int correct_y = static_cast<unsigned int>((shift_y > 0) ? shift_y : 0);

  unsigned int absolute_shift = correct_y * (win_info.GetWidth()) * 4 + correct_x * 4;

  *(sphere_pixels + absolute_shift)     = pixel_color.r;
  *(sphere_pixels + absolute_shift + 1) = pixel_color.g;
  *(sphere_pixels + absolute_shift + 2) = pixel_color.b;
  *(sphere_pixels + absolute_shift + 3) = pixel_color.a;
}

void Sphere::DrawVector(Vector2D::Vector2& main_vector, Vector2D::Vector2& begin_vector, sf::Color draw_color)
{
    int x0 = center_x + (int)begin_vector.x;
    int y0 = center_y + (int)begin_vector.y;
    int x1 = center_x + (int)main_vector.x;
    int y1 = center_y + (int)main_vector.y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    while(true)
    {
        //std::cout << "DrawPixel " << x0 << " " << y0 << "\n"; 
        DrawPixel(x0, y0, draw_color);
        // Check if the line has reached end point
        if (x0 == x1 && y0 == y1) break;

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