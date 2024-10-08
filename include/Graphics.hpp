#pragma once
#ifndef SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP
  #define SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP

const unsigned int DEFAULT_HEIGHT = 600;
const unsigned int DEFAULT_WIDTH = 600;
const unsigned int MAX_HEIGHT = 1000;
const unsigned int MAX_WIDTH = 1000;

const int DEFAULT_CENTER_X = 0;
const int DEFAULT_CENTER_Y = 0;
const int DEFAULT_RADIUS = 1;

class GraphicSystem {
 public:
  GraphicSystem(int dry_width = DEFAULT_WIDTH,
                int dry_height = DEFAULT_HEIGHT,
                const char *sphere_name = "Title",
                sf::Color bckg_color = sf::Color::White);
  ~GraphicSystem();

  //ChangeParams
  void SetBckColor(sf::Color new_bckg_color) {
    bckg_color = new_bckg_color;
  }
  void SetTitle(const char *new_title) {
    title = new_title;
  }
  //Draw
  void Clear();
  void Resize(int new_width, int new_height);
  void DrawPixelAbsolute(int pos_x, int pos_y, sf::Color pixel_color);
  void DrawPixelRelatively(int pos_x, int pos_y, sf::Color pixel_color);
  void DrawVector(Vector2D::Vector2 &main_vector, Vector2D::Vector2 &begin_vector, sf::Color draw_color);
  //GetParams================================================
  sf::Color GetBckgColor() const {
    return bckg_color;
  }
  unsigned int GetWidth() const {
    return width;
  }
  unsigned int GetHeight() const {
    return height;
  }
  const char *GetTitle() const {
    return title;
  }
  uint8_t *GetPixelsPtr() const {
    return sphere_pixels;
  }
  unsigned int GetArea() const {
    return area;
  }
  int GetCenterX() const {
    return center_x;
  }
  int GetCenterY() const {
    return center_y;
  }
  //Private==================================================
 private:
  unsigned int width;
  unsigned int height;
  unsigned int area;
  int center_x;
  int center_y;
  uint8_t *sphere_pixels = nullptr;
  //Help
  sf::Color bckg_color;
  const char *title = nullptr;
};

class Sphere {
 public:
  //=====================================
  Sphere(int new_x = DEFAULT_CENTER_X,
         int new_y = DEFAULT_CENTER_Y,
         int radius = DEFAULT_RADIUS,
         sf::Color new_color = sf::Color::Blue);
  //Draw=================================
  void SphereDraw(GraphicSystem &system);
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
  //=====================================
 private:
  int x_c;
  int y_c;
  int r;
  sf::Color sphere_color;
};

#endif//SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP