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

   float mod_specular[]  = {1, 1, 1, 1};
   float mod_position[]  = {10, 10, 10, 0};

   glMaterialfv(GL_FRONT, GL_SPECULAR, mod_specular);
   glMaterialf(GL_FRONT, GL_SHININESS, 128);
   glLightfv(GL_LIGHT0, GL_POSITION, mod_position); 
   
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
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
    glutSolidTeapot(1);

    glTranslatef(4, 0, 0);
    glutSolidSphere(1, 20, 20);
    glPopMatrix();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
   //glFrustum(-3, 3, -3*(w/h), 3*(w/h), 0.99999, 300);
   gluPerspective(60, 1, 0.9, 20);
   
   //Orthographic seems more easy to imagine.
   //glOrtho(-3, 3, -3, 3, -10, 10);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0, 0, 15, 0, 0, 0, 0, 1, 0);
}

double toRadians(int degree)
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
       case 'i':
           angleV += 5;
           angleV %= 360;
           break;
       case 'k':
           angleV -= 5;
           angleV %= 360;
           break;

       case 27:
           exit(0);
           return;
   }

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(eyeX, eyeY, 15, eyeX - sin(toRadians(angleH)), eyeY - sin(toRadians(angleV)), 0, 0, 1, 0);
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
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
