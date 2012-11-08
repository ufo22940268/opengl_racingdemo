#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#define PLANE_SIZE 3
#define MOVE_SIZE 3
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define MAX_DOTS_COUNT 200
#define TEST_DOTS_COUNT 5

#define REFRESH_INTERVAL 50

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

float toRadians(int degree);
void drawCircle(float r);
void drawPlane();
void movePlane(float x, float y);
void movePlaneInDirection(char key);

void updateDots();
