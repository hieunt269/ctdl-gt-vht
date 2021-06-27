//
//  main.c
//  LinkedListStack
//
//  Created by TungDT on 7/26/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "stack.h"
#include <time.h>

#define BOARD_SIZE 3
#define VALID   0
#define INVALID 1

int play_game(int board[][BOARD_SIZE], move** moves);
void draw_board(int board[][BOARD_SIZE], move* moves);
position player_move(int board[][BOARD_SIZE]);
position computer_move(int board[][BOARD_SIZE]);
int is_undo(position p);
void undo(move** moves);
int is_over(int board[][BOARD_SIZE]);
int invalid_move(int x, int y, int board[][BOARD_SIZE]);
int three_consecutive(int board[][BOARD_SIZE], char c);
int is_full(int board[][BOARD_SIZE]);
void print_hline(int length);


int main(int argc, const char * argv[])
{
    int board[BOARD_SIZE][BOARD_SIZE];
    move* moves = NULL;
    draw_board(board, moves);
    time_t t;
    srand((unsigned) time(&t));
    
    int game_over = 0;
    while (!game_over)
    {
        game_over = play_game(board, &moves);
        
    }
    clear_stack(&moves);
    return 0;
}
int play_game(int board[][BOARD_SIZE], move** moves)
{
    int game_over = 0;
    // TODO
    return game_over;
}
void undo(move** moves)
{
    // TODO
}

int is_over(int board[][BOARD_SIZE])
{
    // TODO: Check if player / computer wins or draw game
}

void draw_board(int board[][BOARD_SIZE], move* moves)
{
    position* pos = to_array(moves);

    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = ' ';
    
    for (int i = 0; i < get_size(moves); i++)
        board[pos[i].x][pos[i].y] = pos[i].c;
    
    printf("Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        print_hline(BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++)
            printf("|%c", board[i][j]);
        printf("|\n");
    }
    print_hline(BOARD_SIZE);
    
    free(pos);
}
position player_move(int board[][BOARD_SIZE])
{
    int x = -2, y = -2;
    int invalid = INVALID;
    while (invalid)
    {
        printf("Player move: ");
        fflush(stdin);
        scanf("%d", &x);
        scanf("%d", &y);
        invalid = invalid_move(x, y, board);
        if (invalid) printf("Invalid move!\n");
    }
    position pos = {x, y, 'X'};
    return pos;
}
position computer_move(int board[][BOARD_SIZE])
{
    int x = -2, y = -2;
    printf("Computer move: ");
    
    while (invalid_move(x, y, board))
    {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
    }
    printf("%d %d\n", x, y);
    position pos = {x, y, 'O'};
    return pos;
}

int invalid_move(int x, int y, int board[][BOARD_SIZE])
{
    if (x == -1 && y == -1) return VALID; // undo
    if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE) return INVALID;
    if (board[x][y] != ' ') return INVALID; // already taken
    return VALID;
}

int is_undo(position p)
{
    return p.x == -1 && p.y == -1;
}

int three_consecutive(int board[][BOARD_SIZE], char c)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return 1;
    }
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return 1;
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return 1;
    return 0;
}

int is_full(int board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

void print_hline(int length)
{
    printf("+");
    for (int i = 0; i < length; i++)
    {
        printf("-+");
    }
    printf("\n");
}
