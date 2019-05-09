#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include "Draw.cpp"
  
 
 
  
////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

void test(float);


int main() 
{ 
    // Create the main window 
    sf::RenderWindow App(sf::VideoMode(3000, 1920, 64), "SFML OpenGL"); 

    int width=600,height=600;
    // Create a clock for measuring time elapsed     
    sf::Clock Clock; 
      
    //prepare OpenGL surface for HSR 
    glClearDepth(1.f); 
    glClearColor(0.3f, 0.3f, 0.3f, 0.f); //background colour
    glEnable(GL_DEPTH_TEST); 
    glDepthMask(GL_TRUE); 
   
    //// Setup a perspective projection & Camera position 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
     
    //set up a 3D Perspective View volume
    //gluPerspective(90.f, 1.f, 1.f, 10.0f);//fov, aspect, zNear, zFar 
 
    //set up a  orthographic projection same size as window
    //this means the vertex coordinates are in pixel space
    //glOrtho(0,800,0,600,0,100); // use pixel coordinates
    
	
	
   
	//glMatrixMode(GL_PROJECTION); // reset projection matrix
	//glLoadIdentity();

	//calculate new prespective and aspect ratio
	//gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,1.0f,1000.0f);

	glMatrixMode(GL_MODELVIEW); // reset modelview matrix
	glLoadIdentity();


    // Start game loop 
    while (App.isOpen()) 
    { 
        // Process events 
        sf::Event Event; 
        while (App.pollEvent(Event)) 
        { 
            // Close window : exit 
            if (Event.type == sf::Event::Closed) 
                App.close(); 
   
            // Escape key : exit 
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape)) 
                App.close(); 
             
    
        } 
           
        //Prepare for drawing 
        // Clear color and depth buffer 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   
        // Apply some transformations 
        glMatrixMode(GL_MODELVIEW); 
        glLoadIdentity(); 
        //glScaled(0.5,0.5,0.5); 

		// glTranslatef(0,0,-1); //push back 10 units from camera
		// gluLookAt(	0,0,100,// camera position
		// 			0,0,0, //look at this point
		// 			0,1,1); //camera up

		static float ang=0.0;


		glRotatef(ang,1,0,0); //spin about x-axis
		glRotatef(ang*2,0,1,0);//spin about y-axis
		

		ang+=0.01f;

		// Draw_Cuboid(0.2,0.35,0.50);

		// glTranslatef(0,0.40,0);//move everyting after this line by 40 units along y-axis
		// glRotatef(ang*5,0,0,1); //spin about z-axis

		// Draw_Cuboid(0.10,0.10,0.10);
		
		// glTranslatef(0,0.10,0);//move everyting after this line by 40 units along y-axis

		// glRotatef(ang*5,0,0,1); //spin about z-axis

		// Draw_Cuboid(0.10,0.10,0.10);

		// glTranslatef(0,0.10,0);//move everyting after this line by 40 units along y-axis

		// glRotatef(ang*5,0,0,1); //spin about z-axis

		// Draw_Cuboid(0.10,0.10,0.10);
		int i=0; 
		for (i = 1; i <= 11400; i++) 
        {
			
			test(ang*10);
		} 

		for (i = 1; i <= 1400; i++) 
        {
		    glTranslatef(0.0314/i,0.007,0.014);
			Draw_Cuboid(0.10,0.10,0.10);
			//st(ang*3);
		} 

        App.display(); 
    } 
   
    return EXIT_SUCCESS; 
}

void test(float ang) {
		glTranslatef(0.010,0.010,-0.0);//move everyting after this line by 40 units along y-axis
		glRotatef(ang*1.168,0,-0,1); //spin about z-axis
		// glTranslatef(0.00,-0.10,0);//move everyting after this line by 40 units along y-axis

		Draw_Cuboid(0.10,0.10,0.10);
}

