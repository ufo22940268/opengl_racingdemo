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

typedef struct {
    int x;
    int y;
    int color;

    /*
     * vx, vy refers to the vector of the dot. every time updates
     * dots just need to add the vx and vy to x and y
     */
    int vx;
    int vy;
} dot;

struct linked_node_s {
    dot *dot;
    struct linked_node_s *next;
}; 
typedef struct linked_node_s linked_node;
