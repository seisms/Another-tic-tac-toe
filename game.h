#define SPACES 3

typedef struct cell{
    char placed;
    bool is_used;
}cell;

typedef struct{
    bool winpath;
    int rowA, colA;
    int rowB, colB;
    int rowC, colC;
}winning;

void game_init();
int gameloop();
void printboard();
int wintie();
