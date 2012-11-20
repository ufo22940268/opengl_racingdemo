#define   PLANE_SIZE             3
#define   MOVE_SIZE              3
#define   WINDOW_WIDTH           500
#define   WINDOW_HEIGHT          500
#define   MAX_DOTS_COUNT         200
#define   TEST_DOTS_COUNT        5


#define   SPEED_UNIT             2
#define   DOT_UNIT               2

#define   UPDATE_DATA_INTERVAL   3000
#define   REFRESH_INTERVAL       50

/**
 * Game status.
 */
#define   STATUS_NORMAL          0
#define   STATUS_FINISHED        1

#define   KEY_UP                 'w'
#define   KEY_DOWN               's'
#define   KEY_LEFT               'a'
#define   KEY_RIGHT              'd'

#define   FLAG_VOID              0x0000
#define   FLAG_LEFT              0x0001
#define   FLAG_UP                0x0010
#define   FLAG_RIGHT             0x0100
#define   FLAG_DOWN              0x1000

#define   DIRECTION_LEFT         0
#define   DIRECTION_UP           1
#define   DIRECTION_RIGHT        2
#define   DIRECTION_DOWN         3
#define   DIRECTION_LEFT_UP      4
#define   DIRECTION_LEFT_DOWN    5
#define   DIRECTION_RIGHT_UP     6
#define   DIRECTION_RIGHT_DOWN   7
#define   DIRECTION_VOID         8

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
