#include <SFML/Graphics.hpp>
#include "headers/Assets.h"
#include <SFML/OpenGL.hpp>
#include "headers/Game.h"
#include "Game.cpp"

//Constants
static const float mouse_sensitivity = 0.005f;
static const float wheel_sensitivity = 0.2f;
static const float music_vol = 75.0f;
static const float target_fps = 60.0f;

//Game modes
enum GameMode {
  MAIN_MENU,
  PLAYING,
  PAUSED,
  SCREEN_SAVER,
  CONTROLS,
  LEVELS,
  CREDITS,
  MIDPOINT
};


//Global variables
static sf::Vector2i mouse_pos;
static bool all_keys[sf::Keyboard::KeyCount] = { 0 };
static bool mouse_clicked = false;
static bool show_cheats = false;
static GameMode game_mode = MAIN_MENU;


void LockMouse(sf::RenderWindow& window) {
  window.setMouseCursorVisible(false);
  const sf::Vector2u size = window.getSize();
  mouse_pos = sf::Vector2i(size.x / 2, size.y / 2);
  sf::Mouse::setPosition(mouse_pos);
}
void UnlockMouse(sf::RenderWindow& window) {
  window.setMouseCursorVisible(true);
}

// void PauseGame(sf::RenderWindow& window, Scene& scene) {
//   game_mode = PAUSED;
//   scene.GetCurMusic().setVolume(GetVol());
//   UnlockMouse(window);
//   scene.SetExposure(0.5f);
// }

int windowInit()
{
 //Load the font   
  Game game;
  game.run();
  return 0;
}

int main()
{
  windowInit();
}
