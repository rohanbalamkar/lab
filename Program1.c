#include <GL/glut.h>

#include <iostream>

using namespace std;

// Bresenham's line drawing algorithm

void drawLine(int x0, int y0, int x1, int y1) {

 int dx = abs(x1 - x0);

 int dy = abs(y1 - y0);

 int sx = (x0 < x1) ? 1 : -1;

 int sy = (y0 < y1) ? 1 : -1;

 int err = dx - dy;

 while (true) {

 glBegin(GL_POINTS);

 glVertex2i(x0, y0);

 glEnd();

 if (x0 == x1 && y0 == y1) break;

 int e2 = 2 * err;

 if (e2 > -dy) {

 err -= dy;

 x0 += sx;

 }

 if (e2 < dx) {

 err += dx;

 y0 += sy;

 }

 }

}
// OpenGL display callback

void display() {

 int x1, x2, y1, y2;

 cout << "Enter coordinates for x1 and y1" << endl;

 cin >> x1 >> y1;

 cout << "Enter coordinates for x2 and y2" << endl;

 cin >> x2 >> y2;

 glClear(GL_COLOR_BUFFER_BIT);

 // Draw line using Bresenham's algorithm

 glColor3f(1.0f, 1.0f, 1.0f);

 drawLine(x1, y1, x2, y2);

 glFlush();

}

// OpenGL initialization

void initializeOpenGL(int argc, char** argv) {

 glutInit(&argc, argv);

 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

 glutInitWindowSize(800, 600);

 glutCreateWindow("Bresenham's Line Algorithm");

 glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

 glMatrixMode(GL_PROJECTION);

 glLoadIdentity();

 gluOrtho2D(0, 800, 0, 600);

 glutDisplayFunc(display);

}

// Main function

int main(int argc, char** argv) {

 initializeOpenGL(argc, argv);

 glutMainLoop();
 return 0;
}
