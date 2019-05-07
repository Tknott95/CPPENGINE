#include "headers/Game.h"
#include <SFML/OpenGL.hpp>
#include "headers/Assets.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "TheZeonTex");
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


        this->window->clear();
        this->window->draw(shape);
        this->window->draw(text);

        this->window->display();
         
}

void Game::run()
{
 while (this->window->isOpen())
    {
        this->update();
        this->render();
 
    }
}
