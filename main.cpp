#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include <stdio.h>
#include "Kula_wektor.hpp"

#define ilosc 500
// angle of rotation for the camera direction
float angle = 0.0f;
bool stop=false;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

Kula_wektor kule[ilosc];
// XZ position of the camera
float x=0.0f, z=50.0f, y=1.0f;


float length_x=15.0f, length_y=10.0f, length_z=10.0f;
float radius=0.20f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;
float distance = 0.14f;

struct pos{
 float x;
 float y;
 float z;
 //wektor 1- w gore -2 w dol -3 w lewo -4 w prawo  -5 lewo gora -6 lewo dol -7
 int wektor;
 float r;

}posistion_table[ilosc];



void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void drawSphere() {

	glColor3f(0.0f, 1.0f, 0.0f);

// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(kule[0].getRadius(),20,20);


}

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}


void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}








void renderScene(void) {

	if (deltaMove)
		computePos(deltaMove);
    if (deltaAngle)
        computeDir(deltaAngle);
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, y, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
    glVertex3f( length_x, length_y, length_z );
    glVertex3f( length_x, - length_y, length_z );

    glVertex3f( length_x, - length_y, length_z );
    glVertex3f( length_x, - length_y, - length_z );

    glVertex3f( length_x, - length_y, - length_z );
    glVertex3f( length_x, length_y, - length_z );

    glVertex3f( length_x, length_y, - length_z );
    glVertex3f( length_x, length_y, length_z );

    glVertex3f( - length_x, length_y, length_z );
    glVertex3f( - length_x, - length_y, length_z );

    glVertex3f( - length_x, - length_y, length_z );
    glVertex3f( - length_x, - length_y, - length_z );

    glVertex3f( - length_x, - length_y, - length_z );
    glVertex3f( - length_x, length_y, - length_z );

    glVertex3f( - length_x, length_y, - length_z );
    glVertex3f( - length_x, length_y, length_z );

    glVertex3f( length_x, length_y, length_z );
    glVertex3f( - length_x, length_y, length_z );

    glVertex3f( length_x, - length_y, length_z );
    glVertex3f( - length_x, - length_y, length_z );

    glVertex3f( length_x, - length_y, - length_z );
    glVertex3f( - length_x, - length_y, - length_z );

    glVertex3f( length_x, length_y, - length_z );
    glVertex3f( - length_x, length_y, - length_z );
glEnd();






/*Draw spheres

	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++) {
                for(int z=-3; z < 3; z++) {
                     glPushMatrix();
                     glTranslatef(i*2.0,z*2.0,j * 2.0);
                     drawSphere();
                     glPopMatrix();
               }
		}
        glutSwapBuffers();

 */
 if (stop==false){
	for(int i = 0; i < ilosc; i++){
                     glPushMatrix();
                     glTranslatef(kule[i].getX(),kule[i].getY(),kule[i].getZ());
                     drawSphere();
                     glPopMatrix();
                     //posistion_table[i][1]=posistion_table[i][1]+0.01;
                     //printf("i %d: X %f  Y %f  Z%f \n",i,kule[i].getX(),kule[i].getY(),kule[i].getZ());
                     for (int j=0; j< ilosc; j++){
                        if (j!=i) kule[i].calculate_colision(kule[j]);
                     }
                     kule[i].calc_edge(length_x,length_y,length_z);


		}
        glutSwapBuffers();
 }

}



void processNormalKeys(unsigned char key, int xx, int yy) {

        if (key == 27)
              exit(0);
        if (key == '+'){y=y-0.02f;}
        if (key == '-'){y=y+0.02f;}
        if (key == 32){ if (stop==false) {stop=true;} else {stop=false;}  }

}

void pressKey(int key, int xx, int yy) {

       switch (key) {
             case GLUT_KEY_UP : deltaMove = 0.5f; break;
             case GLUT_KEY_DOWN : deltaMove = -0.5f;  break;
             case GLUT_KEY_RIGHT: deltaAngle = 0.01f;   break;
             case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
       }
}

void releaseKey(int key, int x, int y) {

        switch (key) {
             case GLUT_KEY_UP :
             case GLUT_KEY_DOWN : deltaMove = 0;break;
             case GLUT_KEY_LEFT :
            case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
        }
}

void mouseMove(int x, int y) {

         // this will only be true when the left button is down
         if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void fill_posistions(){
    printf("posistion table \n");

                  /*
                     kule[0].setX(10.0);
                     kule[0].setY(5.0);
                     kule[0].setZ(0);

                     kule[0].setDirX(-0.001);
                     kule[0].setDirY(0);
                     kule[0].setDirZ(0);
                     kule[0].setRadius(radius);
                     kule[0].showPos();


                     kule[1].setX(-10.0);
                     kule[1].setY(5.0);
                     kule[1].setZ(0);

                     kule[1].setDirX(0.001);
                     kule[1].setDirY(0);
                     kule[1].setDirZ(0);
                     kule[1].setRadius(radius);
                     kule[1].showPos();

            */



    for(int i = 0; i < ilosc; i++){
                     kule[i].setX((rand()%(int)(2*length_x))-length_x);
                     kule[i].setY((rand()%(int)(2*length_y))-length_y);
                     kule[i].setZ((rand()%(int)(2*length_z))-length_z);


                     kule[i].setDirX(((1.0*rand()/RAND_MAX) *2.0-1.0)/10);
                     kule[i].setDirY(((1.0*rand()/RAND_MAX) *2.0-1.0)/10);
                     kule[i].setDirZ(((1.0*rand()/RAND_MAX) *2.0-1.0)/10);
                     kule[i].setRadius(radius);
                     kule[i].showPos();
                     //printf("wektor %d \n", posistion_table[i].wektor);
                    // printf(" [%f] , [%f], [%f]", posistion_table[i][0],posistion_table[i][1],posistion_table[i][2]);

		}
  //  printf("\n");
}


int main(int argc, char **argv) {
    srand(time(NULL));
    fill_posistions();
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Symulacja gazu");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	//glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	// here are the two new functions
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
