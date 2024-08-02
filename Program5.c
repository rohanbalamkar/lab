#include "stdafx.h"

#include <GL/glut.h>

#include <stdio.h>

// Global variables

int width = 800;

int height = 600;

GLfloat rotationX = 0.0f;

GLfloat rotationY = 0.0f;

GLfloat scale = 1.0f;

// Function to draw a cube

void drawCube() {

 glBegin(GL_QUADS);

 // Front face

 glColor3f(1.0f, 0.0f, 0.0f); // Red

 glVertex3f(-0.5f, -0.5f, 0.5f);

 glVertex3f(0.5f, -0.5f, 0.5f);

 glVertex3f(0.5f, 0.5f, 0.5f);

 glVertex3f(-0.5f, 0.5f, 0.5f);

 // Back face

 glColor3f(0.0f, 1.0f, 0.0f); // Green

 glVertex3f(-0.5f, -0.5f, -0.5f);

 glVertex3f(-0.5f, 0.5f, -0.5f);

 glVertex3f(0.5f, 0.5f, -0.5f);

 glVertex3f(0.5f, -0.5f, -0.5f);

 // Top face

 glColor3f(0.0f, 0.0f, 1.0f); // Blue

 glVertex3f(-0.5f, 0.5f, -0.5f);

 glVertex3f(-0.5f, 0.5f, 0.5f);

 glVertex3f(0.5f, 0.5f, 0.5f);

 glVertex3f(0.5f, 0.5f, -0.5f);

 // Bottom face

 glColor3f(1.0f, 1.0f, 0.0f); // Yellow

 glVertex3f(-0.5f, -0.5f, -0.5f);

 glVertex3f(0.5f, -0.5f, -0.5f);

 glVertex3f(0.5f, -0.5f, 0.5f);

 glVertex3f(-0.5f, -0.5f, 0.5f);
// Right face

 glColor3f(1.0f, 0.0f, 1.0f); // Magenta

 glVertex3f(0.5f, -0.5f, -0.5f);

 glVertex3f(0.5f, 0.5f, -0.5f);

 glVertex3f(0.5f, 0.5f, 0.5f);

 glVertex3f(0.5f, -0.5f, 0.5f);

 // Left face

 glColor3f(0.0f, 1.0f, 1.0f); // Cyan

 glVertex3f(-0.5f, -0.5f, -0.5f);

 glVertex3f(-0.5f, -0.5f, 0.5f);

 glVertex3f(-0.5f, 0.5f, 0.5f);

 glVertex3f(-0.5f, 0.5f, -0.5f);

 glEnd();

}

// Function to handle display

void display() {

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 glMatrixMode(GL_MODELVIEW);

 glLoadIdentity();

 // Apply transformations

 glTranslatef(0.0f, 0.0f, -3.0f);

 glRotatef(rotationX, 1.0f, 0.0f, 0.0f);

 glRotatef(rotationY, 0.0f, 1.0f, 0.0f);

 glScalef(scale, scale, scale);

 // Draw cube

 drawCube();

 glutSwapBuffers();

}

// Function to handle keyboard events

void keyboard(unsigned char key, int x, int y) {

 switch (key) {

 case 'x':

 rotationX += 5.0f;

 break;

 case 'X':

 rotationX -= 5.0f;

 break;
 case 'y':

 rotationY += 5.0f;

 break;

 case 'Y':

 rotationY -= 5.0f;

 break;

 case '+':

 scale += 0.1f;

 break;

 case '-':

 if (scale > 0.1f)

 scale -= 0.1f;

 break;

 case 27: // Escape key to exit

 exit(0);

 break;

 }

 glutPostRedisplay(); // Trigger a redraw

}

// Function to initialize OpenGL

void initializeOpenGL(int argc, char** argv) {

 glutInit(&argc, argv);

 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowSize(width, height);

 glutCreateWindow("Geometric Operations in 3D");

 glEnable(GL_DEPTH_TEST);

 glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background

 glMatrixMode(GL_PROJECTION);

 glLoadIdentity();

 gluPerspective(45.0f, (float)width / (float)height, 1.0f, 100.0f);

 glutDisplayFunc(display);

 glutKeyboardFunc(keyboard);

}

// Main function

int main(int argc, char** argv) {

 initializeOpenGL(argc, argv);

 glutMainLoop();

 return 0;

}
