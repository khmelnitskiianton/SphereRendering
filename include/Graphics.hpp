#pragma once

#include "Vector.hpp"
#ifndef SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP
#define SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP

const unsigned int DEFAULT_HEIGHT = 400;
const unsigned int DEFAULT_WIDTH = 400;

const unsigned int MAX_HEIGHT = 1000;
const unsigned int MAX_WIDTH  = 1000;

struct WindowSettings {
//Constructor
  WindowSettings(int dry_width = DEFAULT_WIDTH, int dry_height =  DEFAULT_HEIGHT, const char* init_title = "Title", sf::Color init_bckg_color = sf::Color::White);
//ChangeParams
  void SetWidth(int new_width);
  void SetHeight(int new_height);

  void SetBckColor(sf::Color new_bckg_color) { bckg_color = new_bckg_color; }
  void SetTitle(const char* new_title) { title = new_title; }
//GetParams================================================
  sf::Color    GetBckgColor() const { return bckg_color;}  
  unsigned int GetWidth()     const { return width;     }
  unsigned int GetHeight()    const { return height;    }
  const char*  GetTitle()     const { return title;     }
//Private==================================================
private: 
  unsigned int width;
  unsigned int height;
  const char *title = nullptr;
  sf::Color bckg_color;
};

class Sphere {
public:
  WindowSettings win_info;
//=====================================
  Sphere(int dry_width = DEFAULT_WIDTH, int dry_height = DEFAULT_HEIGHT, const char* sphere_name = "Sphere", sf::Color bckg_color = sf::Color::White);
  Sphere(const Sphere& s);
  Sphere& operator= (const Sphere& s);
  ~Sphere();
//=====================================
  void Resize(int new_width, int new_height);
  void DrawPixel(int pos_x, int pos_y, sf::Color pixel_color);
  void DrawVector(Vector2D::Vector2& main_vector, Vector2D::Vector2& begin_vector, sf::Color draw_color);
//=====================================
  uint8_t* GetPixelsPtr() const { return sphere_pixels; }
  unsigned int GetArea() const { return area; }
  int GetCenterX() const { return center_x; }
  int GetCenterY() const { return center_y; }
//=====================================
private:
  int center_x;
  int center_y;
  unsigned int area;
  uint8_t* sphere_pixels = nullptr;
};



#endif //SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP