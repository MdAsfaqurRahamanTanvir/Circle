#include <GL/glut.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
int x,y,r;
void circle(int x,int y) {
 glColor3f(1.0, 1.0, 0.0);
 glPointSize(4.0);

 r = y;
 float p = 1 - r;
 glBegin(GL_POINTS);
 while (x != y)
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
  glVertex2i(x, y);
  glVertex2i(-x, y);
  glVertex2i(x, -y);
  glVertex2i(-x, -y);

  glVertex2i(y, x);
  glVertex2i(-y, x);
  glVertex2i(y, -x);
  glVertex2i(-y, -x);

 }
 glEnd();
 glFlush();
}

void readInput()
{



     printf("\nEnter the value of x: ");
    scanf("%d",&x);
     printf("\nEnter the value of y: ");
    scanf("%d",&y);


}
void Display(void)
{
    //static int i=1;



    circle(x,y);
}

int main(int argc, char ** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Circle Drawing");

 glClearColor(1.0, 0.0, 1.0, 1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-250, 250, -250, 250);
 glMatrixMode(GL_PROJECTION);
 glViewport(0, 0, 500, 500);

readInput();
 glutDisplayFunc(Display);
 glutMainLoop();
 return 0;
}
