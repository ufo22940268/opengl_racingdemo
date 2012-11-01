#include <math.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>

double eyeX = 0;
double eyeY = 0;

int angleH = 0;
int angleV = 0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
}

void drawRect(int width, int height)
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(-width/2, height/2);
    glVertex2i(width/2, height/2);
    glVertex2i(width/2, -height/2);
    glVertex2i(-width/2, -height/2);
    glEnd();
}

void drawOuterRect()
{
    drawRect(160, 120);
}

void drawInnerRect()
{
    drawRect(140, 100);
}

void drawTrack() 
{
    glPushMatrix();
    drawOuterRect();
    drawInnerRect();
    glPopMatrix();
}

void drawTestBox()
{
    glPushMatrix();
    //glutWireCube(80);
    glutWireSphere(80, 20, 20);
    glPopMatrix();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   //drawTrack();
   drawTestBox();

   glFlush();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum(-100, 100, -100, 100, 0.99999, 300);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0, 0, 1, 1, 0, 1, 0, 0, 1);
}

double toDegree(int degree)
{
    return degree*M_PI/180;
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
       case 'w':
           eyeX += 5;
           break;
       case 's':
           eyeX -= 5;
           break;
       case 'a':
           eyeY -= 5;
           break;
       case 'd':
           eyeY += 5;
           break;

       case 'j':
           angleH += 5;
           angleH %= 360;
           break;
       case 'l':
           angleH -= 5;
           angleH %= 360;
           break;

       case 27:
           exit(0);
           return;
   }

   glLoadIdentity();
   gluLookAt(eyeX, eyeY, 100, eyeX + cos(toDegree(angleH)), eyeY + sin(toDegree(angleH)), 100, 0, 0, 1);
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
