#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdlib.h>

#include "Graphics.hpp"
#include "Vector.hpp"
#include "rendering.hpp"

void Update(GraphicSystem &system) {
  //std::cout << sphere.GetCenterX() << " " << sphere.GetCenterY();
  Vector2D::Vector2 begin {0, 0};
  Vector2D::Vector2 end {-100, 100};
  system.DrawVector(begin, end, sf::Color::Red);
  system.DrawPixelAbsolute(30, 30, sf::Color::Black);
  system.DrawPixelRelatively(30, 30, sf::Color::Black);
  Sphere sphere(30, 30, 50);
  sphere.SphereDraw(system);
}
