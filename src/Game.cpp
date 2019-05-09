#include "headers/Game.h"
#include <SFML/OpenGL.hpp>
#include "headers/Assets.h"
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <math.h> 
#include <iostream> 
#include "Draw.cpp"

void test(float);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    //GL settings
    sf::ContextSettings settings;
    
    settings.depthBits = 64;
    // settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
   
    this->window = new sf::RenderWindow(sf::VideoMode(3000, 1920, 64), "TheZeonTex");
    this->window->setVerticalSyncEnabled(true);
    this->window->setKeyRepeatEnabled(false);
    this->window->requestFocus();
    //window.setVerticalSyncEnabled(true);

 

     const sf::Glsl::Vec2 window_res((float)this->window->getSize().x, (float)this->window->getSize().y);
    //  shader.setUniform("iResolution", window_res);
    //  scene.Write(shader);

  //Create screen rectangle
  sf::RectangleShape rect;
  rect.setSize(window_res);
  rect.setPosition(0, 0);


    // @TODO: RESOLUTION SELECTION SCREEN
    const sf::Vector2i screen_center(3000/2, 1920/ 2);
    //const sf::Vector2i screen_center(resolution->width / 2, resolution->height / 2);

    // glEnable(GL_TEXTURE_2D);

        // Create a clock for measuring time elapsed
    sf::Clock clock;
	
    //prepare OpenGL surface for HSR
	// glClearDepth(1.f);
    // glClearColor(0.3f, 0.3f, 0.3f, 0.f);
    // glEnable(GL_DEPTH_TEST);
    // glDepthMask(GL_TRUE);
   // Configure the viewport (the same size as the window)
    glViewport(0, 0, this->window->getSize().x, this->window->getSize().y);

    //prepare OpenGL surface for HSR 
    // glClearDepth(1.f); 
    // glClearColor(0.3f, 0.3f, 0.3f, 0.f); //background colour
    // glEnable(GL_DEPTH_TEST); 
    // glDepthMask(GL_TRUE);
    //// Setup a perspective projection & Camera position 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 

	glMatrixMode(GL_MODELVIEW); // reset modelview matrix
	glLoadIdentity();


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
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //   
    //     // Apply some transformations 
        glMatrixMode(GL_MODELVIEW); 
        glLoadIdentity(); 
    
    static float ang=0.0;


		glRotatef(ang,1,0,0); //spin about x-axis
		glRotatef(ang*2,0,1,0);//spin about y-axis
		

		ang+=0.0314f;








glEnd();
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
    text.setFillColor(sf::Color::Blue);


           //    this->window->draw(text);


		Draw_Cuboid(.2,.5,0.50);

		glTranslatef(0,0.40,0);//move everyting after this line by 40 units along y-axis
		glRotatef(ang*5,0,0,1); //spin about z-axis

		Draw_Cuboid(-.0910,0.10,0.10);
		
		glTranslatef(0,0.10,0);//move everyting after this line by 40 units along y-axis

		glRotatef(ang*5,0,0,1); //spin about z-axis

    glTranslatef(-.5, -0.2, .002);

		Draw_Cuboid(0.10,0.17,0.17);


		glRotatef(ang*5,0,0,1); //spin about z-axis

		Draw_Cuboid(.0100,0.10,0.10);
		int i=0; 
		for (i = 1; i <= 5944; i++) 
        {
			Draw_Cuboid(.0100,0.10,0.10);

			test(ang/10);

		} 

        // this->window->clear(sf::Color::Cyan);
        this->window->pushGLStates();

        this->window->draw(text);
        this->window->popGLStates();
        this->window->setActive(true);
        // glDrawPixels(text);
         
}

void Game::run()
{
      sf::Clock clock;

  float smooth_fps = target_fps;
  float lag_ms = 0.0f;

 while (this->window->isOpen())
    {
        float mouse_wheel = 0.0f;

        
        this->update();
        this->render();
        this->window->display();

 
    }
}


void test(float ang) {

		glTranslatef(0.010,0.02,-0.010);//move everyting after this line by 40 units along y-axis
		glRotatef(ang*0.168,ang*0.168,-0,1); //spin about z-axis
		// glTranslatef(0.00,-0.10,0);//move everyting after this line by 40 units along y-axis

		// Triangle(0.010,0.010,0.010);
		Draw_Cuboid(0.10,0.10,0.10);


}
