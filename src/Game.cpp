#include "headers/Game.h"
#include <SFML/OpenGL.hpp>
#include "headers/Assets.h"
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>

// CONSTANTS
static const float mouse_sensitivity = 0.005f;
static const float wheel_sensitivity = 0.2f;
static const float music_vol = 75.0f;
static const float target_fps = 60.0f;

// GAME MODES
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


// MOUSE FUNCTIONS
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

// GAME FUNCTIONS
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "TheZeonTex");
    this->window->setVerticalSyncEnabled(true);
    this->window->setKeyRepeatEnabled(false);
    this->window->requestFocus();
    //window.setVerticalSyncEnabled(true);

    //window.setActive(true);
    //GL settings
    sf::ContextSettings settings;
    
    settings.majorVersion = 2;
    settings.minorVersion = 0;

    // @TODO: RESOLUTION SELECTION SCREEN
    const sf::Vector2i screen_center(1920 / 2, 1080/ 2);
    //const sf::Vector2i screen_center(resolution->width / 2, resolution->height / 2);

    glEnable(GL_TEXTURE_2D);

        // Create a clock for measuring time elapsed
    sf::Clock Clock;
	
    //prepare OpenGL surface for HSR
	glClearDepth(1.f);
    glClearColor(0.3f, 0.3f, 0.3f, 0.f);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    //// Setup a perspective projection & Camera position
    glMatrixMode(GL_PROJECTION);


    
}

Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

void Game::updateSFML()
{
      while (this->window->pollEvent(this->sfEvent))
        {
            switch (this->sfEvent.type)
            {
              case sf::Event::Closed:
                this->window->close();
                break;

              case sf::Event::Resized:
                glViewport(0, 0, this->sfEvent.size.width, this->sfEvent.size.height);
                break;

              case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                  this->window->close();
                  break;
                }
                break;
            
              case sf::Event::LostFocus:
                 if (game_mode == PLAYING) {
                //   PauseGame(window, scene);
                  break;
                 }
                 break;
            
              default:
                break;
            }
        }
}

void Game::update()
{
    this->updateSFML();
}

void Game::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    sf::Font font;
    if (!font.loadFromFile(Orbitron_Bold_ttf)) {
      // ERROR_MSG("Unable to load font");
      return;
    }
    //Load the mono font
    sf::Font font_mono;
    if (!font_mono.loadFromFile(Inconsolata_Bold_ttf)) {
      // ERROR_MSG("Unable to load mono font");
      return;
    }

    sf::Text text("the TEX SFML", font, 100);


    sf::CircleShape shape(100.f);
    
    shape.setFillColor(sf::Color::Blue);
    text.setFillColor(sf::Color::Magenta);


        this->window->clear(sf::Color::Cyan);
        this->window->draw(shape);
        this->window->draw(text);
 
        this->window->display();
         
}

void Game::run()
{
  float smooth_fps = target_fps;
  float lag_ms = 0.0f;
 while (this->window->isOpen())
    {
        float mouse_wheel = 0.0f;
        this->update();
        this->render();
 
    }
}
