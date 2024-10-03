#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

const unsigned int DEFAULT_HEIGHT = 400;
const unsigned int DEFAULT_WIDTH = 400;

typedef struct WindowSettings {
  unsigned int width = DEFAULT_WIDTH;
  unsigned int height = DEFAULT_HEIGHT;
  const char* title;
} WindowSettings_t;

int main(int argc, const char *argv[]) {
  WindowSettings_t sphere_info_window = {.title = "Pseudo 3D Sphere"}; 
  if (argc == 3)
  {
    sphere_info_window.width = static_cast<unsigned int>(atoi(argv[1]));
    sphere_info_window.height = static_cast<unsigned int>(atoi(argv[2]));
  }
  
  std::cout << sphere_info_window.width << "\n";
  std::cout << sphere_info_window.height << "\n";

  sf::RenderWindow sphere_window(sf::VideoMode(sphere_info_window.width, sphere_info_window.height), "Sphere Rendering!");

  while (sphere_window.isOpen()) {
    sf::Event event;
    while (sphere_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        sphere_window.close();
    }

    sphere_window.clear();
    sphere_window.display();
  }

  return 0;
}