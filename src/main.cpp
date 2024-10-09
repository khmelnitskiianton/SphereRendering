#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdlib.h>

#include "ColorVector.hpp"
#include "Graphics.hpp"
#include "Objects.hpp"

void WindowRendering(GSystem::GraphicSystem &system);

int main(int argc, const char *argv[]) {
  //Set Window
  GSystem::GraphicSystem system;
  system.SetTitle("Sphere");
  if (argc == 3) {
    system.Resize(atoi(argv[1]), atoi(argv[2]));
  }
  WindowRendering(system);
  return 0;
}

void WindowRendering(GSystem::GraphicSystem &system) {
  //Init SFML Window
  sf::RenderWindow sphere_win(sf::VideoMode(system.GetWidth(), system.GetHeight()), system.GetTitle());
  sf::Texture sphere_texture;
  sf::Sprite sphere_sprite;
  sphere_texture.create(system.GetHeight(), system.GetWidth());
  sphere_texture.update(system.GetPixelsPtr());
  sphere_sprite.setTexture(sphere_texture);

  GObjects::Sphere sphere(0, 0, 200, 0, ColorRGBA::ColorGreen);
  GObjects::Light light(100, 100, 300, ColorRGBA::ColorWhite);

  while (sphere_win.isOpen()) {
    sf::Event event;
    while (sphere_win.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        sphere_win.close();
      if (event.key.code == sf::Keyboard::Escape) {
        std::cerr << "Escape key pressed - closing window" << std::endl;
        sphere_win.close();
      }
      //Keys
      if (event.type == sf::Event::KeyPressed) {
        // Check specific keys
        if (event.key.code == sf::Keyboard::W) {
          sphere.SetYC(sphere.GetYC() - 1);
        }
        if (event.key.code == sf::Keyboard::A) {
          sphere.SetXC(sphere.GetXC() - 1);
        }
        if (event.key.code == sf::Keyboard::S) {
          sphere.SetYC(sphere.GetYC() + 1);
        }
        if (event.key.code == sf::Keyboard::D) {
          sphere.SetXC(sphere.GetXC() + 1);
        }
      }
    }
    //Clear
    sphere_win.clear(system.GetBckgColor().ColorVectorToSFMLColor());
    //Rendering Sphere
    system.Clear();
    sphere.SphereDraw(system, light, 0.3);
    //Update Sprite
    sphere_texture.update(system.GetPixelsPtr());
    sphere_sprite.setTexture(sphere_texture);
    sphere_win.draw(sphere_sprite);
    //Display
    sphere_win.display();
  }
}