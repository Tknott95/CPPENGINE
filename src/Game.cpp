#include "headers/Game.h"
#include <SFML/OpenGL.hpp>
#include "headers/Assets.h"
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <math.h> 
#include <iostream> 

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

void Draw_Cuboid(float,float,float);

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
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080, 32), "TheZeonTex");
    this->window->setVerticalSyncEnabled(true);
    this->window->setKeyRepeatEnabled(false);
    this->window->requestFocus();
    //window.setVerticalSyncEnabled(true);

    //GL settings
    sf::ContextSettings settings;
    
    // settings.depthBits = 24;
    // settings.stencilBits = 8;
    // settings.antialiasingLevel = 4;
    // settings.majorVersion = 3;
    // settings.minorVersion = 0;


    // @TODO: RESOLUTION SELECTION SCREEN
    const sf::Vector2i screen_center(1920 / 2, 1080/ 2);
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

    // Setup a perspective projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}


void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;

    //fH = tan( (fovY / 2) / 180 * pi ) * zNear;
    fH = tan( fovY / 360 * pi ) * zNear;
    fW = fH * aspect;

    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
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
    
// Apply some transformations
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();






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
    text.setFillColor(sf::Color::Magenta);

     
    float vertices[] = {
     0.0f,  0.5f, // Vertex 1 (X, Y)
     0.5f, -0.5f, // Vertex 2 (X, Y)
    -0.5f, -0.5f  // Vertex 3 (X, Y)
} ;
    
        glDrawBuffer(1);
      

        // this->window->clear(sf::Color::Cyan);
        
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



void cube()
{
    // glBegin(GL_QUADS);      // Draw The Cube Using quads
    
    // glColor3f(0.0f,1.0f,0.0f);  // Color Green
    // glNormal3f(0.f, 1.f, 0.f);
    // glVertex3f( 1.0f, 1.0f,-1.0f);  // Top Right Of The Quad (Top)
    // glNormal3f(0.f, 1.f, 0.f);
    // glVertex3f(-1.0f, 1.0f,-1.0f);  // Top Left Of The Quad (Top)
    // glNormal3f(0.f, 1.f, 0.f);
    // glVertex3f(-1.0f, 1.0f, 1.0f);  // Bottom Left Of The Quad (Top)
    // glNormal3f(0.f, 1.f, 0.f);
    // glVertex3f( 1.0f, 1.0f, 1.0f);  // Bottom Right Of The Quad (Top)
    
    // glColor3f(1.0f,0.5f,0.0f);  // Color Orange
    // glNormal3f(0.f, -1.f, 0.f);
    // glVertex3f( 1.0f,-1.0f, 1.0f);  // Top Right Of The Quad (Bottom)
    // glNormal3f(0.f, -1.f, 0.f);
    // glVertex3f(-1.0f,-1.0f, 1.0f);  // Top Left Of The Quad (Bottom)
    // glNormal3f(0.f, -1.f, 0.f);
    // glVertex3f(-1.0f,-1.0f,-1.0f);  // Bottom Left Of The Quad (Bottom)
    // glNormal3f(0.f, -1.f, 0.f);
    // glVertex3f( 1.0f,-1.0f,-1.0f);  // Bottom Right Of The Quad (Bottom)
    
    // glColor3f(1.0f, 0.0f, 0.0f);    // Color Red
    // glNormal3f(0.f, 0.f, 1.f);
    // glVertex3f( 1.0f, 1.0f, 1.0f);  // Top Right Of The Quad (Front)
    // glNormal3f(0.f, 0.f, 1.f);
    // glVertex3f(-1.0f, 1.0f, 1.0f);  // Top Left Of The Quad (Front)
    // glNormal3f(0.f, 0.f, 1.f);
    // glVertex3f(-1.0f,-1.0f, 1.0f);  // Bottom Left Of The Quad (Front)
    // glNormal3f(0.f, 0.f, 1.f);
    // glVertex3f( 1.0f,-1.0f, 1.0f);  // Bottom Right Of The Quad (Front)
    
    // glColor3f(1.0f, 1.0f, 0.0f);    // Color Yellow
    // glNormal3f(0.f, 0.f, -1.f);
    // glVertex3f( 1.0f,-1.0f,-1.0f);  // Top Right Of The Quad (Back)
    // glNormal3f(0.f, 0.f, -1.f);
    // glVertex3f(-1.0f,-1.0f,-1.0f);  // Top Left Of The Quad (Back)
    // glNormal3f(0.f, 0.f, -1.f);
    // glVertex3f(-1.0f, 1.0f,-1.0f);  // Bottom Left Of The Quad (Back)
    // glNormal3f(0.f, 0.f, -1.f);
    // glVertex3f( 1.0f, 1.0f,-1.0f);  // Bottom Right Of The Quad (Back)
    
    // glColor3f(0.0f, 0.0f, 1.0f);    // Color Blue
    // glNormal3f(-1.f, 0.f, 0.f);
    // glVertex3f(-1.0f, 1.0f, 1.0f);  // Top Right Of The Quad (Left)
    // glNormal3f(-1.f, 0.f, 0.f);
    // glVertex3f(-1.0f, 1.0f,-1.0f);  // Top Left Of The Quad (Left)
    // glNormal3f(-1.f, 0.f, 0.f);
    // glVertex3f(-1.0f,-1.0f,-1.0f);  // Bottom Left Of The Quad (Left)
    // glNormal3f(-1.f, 0.f, 0.f);
    // glVertex3f(-1.0f,-1.0f, 1.0f);  // Bottom Right Of The Quad (Left)
    
    // glColor3f(1.0f, 0.0f, 1.0f);    // Color Violet
    // glNormal3f(1.f, 0.f, 0.f);
    // glVertex3f( 1.0f, 1.0f,-1.0f);  // Top Right Of The Quad (Right)
    // glNormal3f(1.f, 0.f, 0.f);
    // glVertex3f( 1.0f, 1.0f, 1.0f);  // Top Left Of The Quad (Right)
    // glNormal3f(1.f, 0.f, 0.f);
    // glVertex3f( 1.0f,-1.0f, 1.0f);  // Bottom Left Of The Quad (Right)
    // glNormal3f(1.f, 0.f, 0.f);
    // glVertex3f( 1.0f,-1.0f,-1.0f);  // Bottom Right Of The Quad (Right)
    
    // glEnd();          // End Drawing The Cube
}

void Draw_Cuboid(float width,float height,float depth){
		// points of a cube
	static GLfloat points[][3]={	{1.0f,1.0f,1.0f},
									{1.0f,1.0f,0.0f},
									{0.0f,1.0f,0.0f},
									{0.0f,1.0f,1.0f},
									{1.0f,0.0f,1.0f},
									{1.0f,0.0f,0.0f},
									{0.0f,0.0f,0.0f},
									{0.0f,0.0f,1.0f}};

		//GLfloat normal[3];
		glPushMatrix();	
		glScalef(width,height,depth);
		glTranslatef(-0.5,-0.5,-0.5);
		glBegin(GL_QUADS);
		//top 
		
		//NormalVector(points[0],points[1],points[2],normal);
		//glNormal3fv(normal);
		glColor3d(1.0,1.0,1.0);
		glVertex3fv(points[0]); glVertex3fv(points[1]); glVertex3fv(points[2]); glVertex3fv(points[3]);
		
		//front
		//NormalVector(points[0],points[3],points[7],normal);
		//glNormal3fv(normal);
		glColor3d(1.0,0.0,1.0);
		glVertex3fv(points[0]); glVertex3fv(points[3]); glVertex3fv(points[7]); glVertex3fv(points[4]);

		//back
		//NormalVector(points[1],points[5],points[6],normal);
		//glNormal3fv(normal);
		glColor3d(1.0,1.0,0.0);
		glVertex3fv(points[1]); glVertex3fv(points[5]); glVertex3fv(points[6]); glVertex3fv(points[2]);

		//left
		//NormalVector(points[3],points[2],points[6],normal);
		//glNormal3fv(normal);
		glColor3d(0.0,1.0,0.0);
		glVertex3fv(points[3]); glVertex3fv(points[2]); glVertex3fv(points[6]); glVertex3fv(points[7]);

		//right
		//NormalVector(points[1],points[0],points[4],normal);
		//glNormal3fv(normal);
		glColor3d(0.0,0.0,1.0);
		glVertex3fv(points[1]); glVertex3fv(points[0]); glVertex3fv(points[4]); glVertex3fv(points[5]);

		//bottom
		//NormalVector(points[4],points[7],points[6],normal);
		//glNormal3fv(normal);
		glColor3d(1.0,0.0,0.0);
		glVertex3fv(points[4]); glVertex3fv(points[7]); glVertex3fv(points[6]); glVertex3fv(points[5]);

	glEnd();
	glPopMatrix();
}