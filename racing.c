#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int shoulder = 0;
int elbow = 0;

double radian = 0;
double lookX = 5;
double lookY = 0;
double lookZ = 5;

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

   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum(-100, 100, -100, 100, 0.99999, 20);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      case 's':
         shoulder = (shoulder + 5)%360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder = (shoulder - 5)%360;
         glutPostRedisplay();
         break;
      case 'e':
         elbow = (elbow + 5)%360;
         glutPostRedisplay();
         break;
      case 'E':
         elbow = (elbow - 5)%360;
         glutPostRedisplay();
         break;
   }
}


/*void timer(int v)*/
/*{*/
    /*fprintf(stderr, "timer");*/

    /*lookY = 5*cos(radian);*/
    /*lookZ = 5*sin(radian);*/
    /*radian += M_PI/6;*/
    /*if (radian >= 2*M_PI) radian -= 2*M_PI;*/
    /*glutPostRedisplay();*/
    /*glutTimerFunc(50, timer, 0);*/
/*}*/

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
   /*glutTimerFunc(50, timer, 0);*/
   glutMainLoop();
   return 0;
}
