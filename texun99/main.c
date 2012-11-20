#include <string.h>
#include "util.h"

int updateCount;
int gameStatus = STATUS_NORMAL;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void drawRecord()
{
    glRasterPos2f(-10, -10);
    char status[] = {"hongbosb"};
    int i;
    for (i = 0; i < strlen(status); i ++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, status[i]);
    }
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   drawPlane();
   drawDots();

   if (gameStatus == STATUS_FINISHED) {
       drawRecord();
   }

   glFlush();
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
       case 27:
           exit(0);
           break;
   }

   if (isControllerKey(key)) {
       controlPlane(key);
   }
}

//TODO Reset key status.
void reset() 
{
}

void keyboardUp(unsigned char key, int x, int y)
{
   if (isControllerKey(key)) {
       controlPlaneRelease(key);
   }
}

void viewTimer(int value)
{

    //When collision happens, just stop animation.
    //TODO Display a game report data. such as lasting time, reputation.
    if (isCollision()) {
        gameStatus = STATUS_FINISHED;
    } else {
        updateDots();
    }

    glutPostRedisplay();
    glutTimerFunc(REFRESH_INTERVAL, viewTimer, 0);
}

void dataTimer(int value)
{
    if (gameStatus == STATUS_NORMAL) {
        updateTimeData();
    }
    glutTimerFunc(UPDATE_DATA_INTERVAL, dataTimer, 0);
}

void moveTimer(int value) 
{
    if (gameStatus == STATUS_NORMAL) {
        movePlaneInDirection(getPlaneDirection());
    }
    glutTimerFunc(MOVE_INTERVAL, moveTimer, 0);
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
   glutKeyboardUpFunc(keyboardUp);
   glutIgnoreKeyRepeat(1);

   glutTimerFunc(REFRESH_INTERVAL, viewTimer, 0);
   glutTimerFunc(UPDATE_DATA_INTERVAL, dataTimer, 0);
   glutTimerFunc(MOVE_INTERVAL, moveTimer, 0);

   glutMainLoop();
   return 0;
}
