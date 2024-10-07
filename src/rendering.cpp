#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include <cmath>

#include "ColorVector.hpp"
#include "Vector.hpp"
#include "Graphics.hpp"

#include "rendering.hpp"

void Update(Sphere& sphere) {
    //std::cout << sphere.GetCenterX() << " " << sphere.GetCenterY();
    Vector2D::Vector2 begin{0,0};
    Vector2D::Vector2 end{-100,100};
    sphere.DrawVector(begin, end, sf::Color::Red);
}