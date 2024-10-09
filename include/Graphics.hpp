#pragma once
#ifndef SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP
#define SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP

namespace GSystem {

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
                  ColorRGBA::ColorVector bckg_color = ColorRGBA::ColorWhite);
    ~GraphicSystem();

    //ChangeParams
    void SetBckColor(ColorRGBA::ColorVector new_bckg_color) {
      bckg_color = new_bckg_color;
    }
    void SetTitle(const char *new_title) {
      title = new_title;
    }
    //Draw
    void Clear();
    void Resize(int new_width, int new_height);
    void DrawPixelAbsolute(int pos_x, int pos_y, ColorRGBA::ColorVector pixel_color);
    void DrawPixelRelatively(int pos_x, int pos_y, ColorRGBA::ColorVector pixel_color);
    void DrawVector(Vector2D::Vector2 &main_vector, Vector2D::Vector2 &begin_vector, ColorRGBA::ColorVector draw_color);
    //GetParams================================================
    ColorRGBA::ColorVector GetBckgColor() const {
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

    ColorRGBA::ColorVector bckg_color;
    const char *title = nullptr;
  };

}// namespace GSystem

#endif//SPHERE_RENDERING_INCLUDE_GRAPHICS_HPP