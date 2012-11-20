#define PLANE_SIZE 3
#define MOVE_SIZE 3
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define MAX_DOTS_COUNT 200
#define TEST_DOTS_COUNT 5


#define SPEED_UNIT 2
#define DOT_UNIT 2

#define UPDATE_DATA_INTERVAL 3000
#define REFRESH_INTERVAL 50

/**
 * Game status.
 */
#define STATUS_NORMAL 0
#define STATUS_FINISHED 1

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

#define FLY_SPEED 5

typedef struct {
    int x;
    int y;
    int color;

    //The angle determined the vector of dot. So it must
    //assumed that the way dot flys will point to the (0, 0).
    float angle;
} dot;

struct linked_node_s {
    dot *dot;
    struct linked_node_s *next;
}; 
typedef struct linked_node_s linked_node;
