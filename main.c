#include <ncurses.h>
#include <stdbool.h>
#include <assert.h>

#define ESC 27
#define UP 'w'
#define DOWN 's'
#define WIDTH 10
#define HEIGHT LINES
#define X 0
#define Y 0

typedef enum EVENT {
    EVENT_UNKNOWN = -1,
    EVENT_ESC = 0,
    EVENT_UP = 1,
    EVENT_DOWN = 2
} EVENT;

EVENT get_input();
void update_game_data(EVENT event);
void render_game(WINDOW* window);
WINDOW * init_game();
void cleanup();

struct PONG_OBJECT {
    int x;
    int y;
    int player_num; // player one, left, 0.  player two, right, 1
};

int main()
{
    WINDOW *game_window = init_game();

    bool game_is_still_running = true;
    while (game_is_still_running) {
        EVENT event = get_input();
        if (event == EVENT_ESC) {
            game_is_still_running = false;
            continue;
        }

        update_game_data(event);

        render_game(game_window);
    }

    cleanup();
}

void render_game(WINDOW* window)
{
    move(5, 5);
    waddch(window, '$');
    wrefresh(window);
}

void update_game_data(EVENT event)
{
}

EVENT get_input()
{
    int input_value = getch();
    if (input_value == ESC) {
        return EVENT_ESC;
    } else if (UP) { // up key
        return EVENT_UP;
    } else if (DOWN) { //down key
        return EVENT_DOWN;
    } else {
        return EVENT_UNKNOWN;
    }
}

WINDOW *init_game()
{
    initscr();
    cbreak();
    noecho();
    WINDOW * win = newwin(HEIGHT, WIDTH, Y, X);
    return win;
}

void cleanup()
{
    endwin();
}

