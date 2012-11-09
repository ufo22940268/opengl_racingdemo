#include <stdlib.h>
#include "util.h"

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   drawPlane();
   drawDots();

   glColor3f (1.0, 0, 0);

   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho (-100, 100, -100, 100, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity();             /* clear the matrix */
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
       case KEY_UP:
           movePlaneInDirection(KEY_UP);
           glutPostRedisplay();
           break;
       case KEY_DOWN:
           movePlaneInDirection(KEY_DOWN);
           glutPostRedisplay();
           break;
       case KEY_LEFT:
           movePlaneInDirection(KEY_LEFT);
           glutPostRedisplay();
           break;
       case KEY_RIGHT:
           movePlaneInDirection(KEY_RIGHT);
           glutPostRedisplay();
           break;
       case 27:
           exit(0);
           break;
   }
}

void timer(int value)
{
    updateDots();
    glutPostRedisplay();
    glutTimerFunc(REFRESH_INTERVAL, timer, 0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_WIDTH, WINDOW_HEIGHT); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(REFRESH_INTERVAL, timer, 0);
   glutMainLoop();
   return 0;
}
