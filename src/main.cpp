#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdlib.h>

#include "ColorVector.hpp"
#include "Graphics.hpp"
#include "Vector.hpp"
#include "rendering.hpp"

using namespace Vector3D;

int main(int argc, const char *argv[]) {
  //Set Window
  GraphicSystem system;
  system.SetTitle("Sphere");
  if (argc == 3) {
    system.Resize(atoi(argv[1]), atoi(argv[2]));
  }
  sf::Color();
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
    }
    //Clear
    sphere_win.clear(system.GetBckgColor());

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