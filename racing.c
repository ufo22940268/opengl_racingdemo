#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

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

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   drawTrack();

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

void moveCamera(int key)
{
   //TODO implement. 
}

void specialDown(int key, int x, int y)
{
    if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN
            || key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT) {
        moveCamera(key);
    }
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
       case 27:
           exit(0);
           break;
   }
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
   glutSpecialFunc(specialDown);
   glutMainLoop();
   return 0;
}
