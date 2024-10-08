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
#include "rendering.hpp"

void Update(GSystem::GraphicSystem &system) {
  //std::cout << sphere.GetCenterX() << " " << sphere.GetCenterY();
  Vector2D::Vector2 begin {0, 0};
  Vector2D::Vector2 end {400, 400};
  system.DrawVector(begin, end, ColorRGBA::SFMLColorToColorVector(sf::Color::Red));
  system.DrawPixelAbsolute(30, 30, ColorRGBA::SFMLColorToColorVector(sf::Color::Black));
  system.DrawPixelRelatively(30, 30, ColorRGBA::SFMLColorToColorVector(sf::Color::Black));
  GObjects::Sphere sphere(0, 0, 500, ColorRGBA::ColorGreen);
  GObjects::Light light(200, 200, 600, ColorRGBA::ColorWhite);
  GObjects::Light light1(-200, -200, 600, ColorRGBA::ColorWhite);
  sphere.SphereDraw(system, light, 0.2);
  sphere.SphereDraw(system, light1, 0.2);
}