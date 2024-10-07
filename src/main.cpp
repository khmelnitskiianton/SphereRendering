#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <cmath>

#include "Vector.hpp"
#include "Graphics.hpp"
#include "ColorVector.hpp"

#include "rendering.hpp"

using namespace Vector3D;

int main(int argc, const char *argv[]) {
  //Set Window
  Sphere sphere;
  if (argc == 3) {
    sphere.Resize(atoi(argv[1]), atoi(argv[2]));
  }

  //Init SFML Window
  sf::RenderWindow sphere_win(sf::VideoMode(sphere.win_info.GetWidth(), sphere.win_info.GetHeight()), sphere.win_info.GetTitle());
  
  sf::Texture sphere_texture;
  sf::Sprite sphere_sprite;

  sphere_texture.create(sphere.win_info.GetHeight(), sphere.win_info.GetWidth());

  sphere_texture.update(sphere.GetPixelsPtr());
  sphere_sprite.setTexture(sphere_texture);

  while (sphere_win.isOpen()) {
    sf::Event event;
    while (sphere_win.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        sphere_win.close();
    }
    //Clear
    sphere_win.clear(sphere.win_info.GetBckgColor());

    //Rendering Sphere  
    Update(sphere);

    //Update Sprite
    sphere_texture.update(sphere.GetPixelsPtr());
    sphere_sprite.setTexture(sphere_texture);
    sphere_win.draw(sphere_sprite);

    //Display
    sphere_win.display();
  }
  return 0;
}