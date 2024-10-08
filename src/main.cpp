#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdlib.h>

#include "ColorVector.hpp"
#include "Graphics.hpp"
#include "rendering.hpp"

using namespace Vector3D;

int main(int argc, const char *argv[]) {
  //Set Window
  GSystem::GraphicSystem system;
  system.SetTitle("Sphere");
  if (argc == 3) {
    system.Resize(atoi(argv[1]), atoi(argv[2]));
  }
  //Init SFML Window
  sf::RenderWindow sphere_win(sf::VideoMode(system.GetWidth(), system.GetHeight()), system.GetTitle());

  sf::Texture sphere_texture;
  sf::Sprite sphere_sprite;

  sphere_texture.create(system.GetHeight(), system.GetWidth());

  sphere_texture.update(system.GetPixelsPtr());
  sphere_sprite.setTexture(sphere_texture);

  while (sphere_win.isOpen()) {
    sf::Event event;
    while (sphere_win.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        sphere_win.close();
      if (event.key.code == sf::Keyboard::Escape) {
        std::cout << "Escape key pressed - closing window" << std::endl;
        sphere_win.close();
      }
      // Window resized event
      if (event.type == sf::Event::Resized) {
          system.Resize((int)event.size.width, (int)event.size.height);
      }
      //Keys
      if (event.type == sf::Event::KeyPressed) {
        // Check specific keys
        if (event.key.code == sf::Keyboard::W) {
            std::cout << "W key pressed" << std::endl;
        }
        if (event.key.code == sf::Keyboard::A) {
            std::cout << "A key pressed" << std::endl;
        }
        if (event.key.code == sf::Keyboard::S) {
            std::cout << "S key pressed" << std::endl;
        }
        if (event.key.code == sf::Keyboard::D) {
            std::cout << "D key pressed" << std::endl;
        }
      }
    }

    //Clear
    sphere_win.clear(system.GetBckgColor().ColorVectorToSFMLColor());

    //Rendering Sphere
    Update(system);

    //Update Sprite
    sphere_texture.update(system.GetPixelsPtr());
    sphere_sprite.setTexture(sphere_texture);
    sphere_win.draw(sphere_sprite);

    //Display
    sphere_win.display();
  }
  return 0;
}