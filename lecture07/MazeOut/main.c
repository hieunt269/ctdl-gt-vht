//
//  main.c
//  MazeOut
//
//  Created by TungDT on 7/28/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define WALL    1
#define START   2
#define END     3
#define VISITED -1
#define TRUE    1
#define FALSE   0

int* stack = NULL;
int top = -1;
int stack_size = 100;

int** get_maze(char* input_file, int* rows, int* cols, int* x_start, int* y_start, int *x_end, int* y_end);
void find_exit(int** maze, int rows, int cols, int x_start, int y_start, int x_end, int y_end);
void print_maze(int** maze, int rows, int cols);
int move_next(int** maze, int rows, int cols, int* x_curr, int* y_curr);
int valid_move(int** maze, int rows, int cols, int x_curr, int y_curr);
int is_out(int** maze, int x_curr, int y_curr);
void clear_maze(int** maze, int cols);
void print_exit_path(void);

int main(int argc, const char * argv[])
{
    int n, m, x_start, y_start, x_end, y_end;
    int** maze = get_maze("input.txt", &n, &m, &x_start, &y_start, &x_end, &y_end);
    print_maze(maze, n, m);
    init_stack();
    find_exit(maze, n, m, x_start, y_start, x_end, y_end);
    if (!is_empty()) print_exit_path();
    print_maze(maze, n, m);
    clear_maze(maze, n);
    
    return 0;
}

int** get_maze(char* input_file, int* rowsize, int* colsize, int* x_start, int* y_start, int *x_end, int* y_end)
{
    FILE* f = fopen(input_file, "r");
    if (f == NULL)
    {
        printf("File not found!\n");
        exit(0);
    }
    fscanf(f, "%d", rowsize);
    fscanf(f, "%d", colsize);
    int** maze = (int**) malloc((*rowsize) * sizeof(int*));
    for (int i = 0; i < *rowsize; i++)
    {
        maze[i] = (int*) malloc((*colsize) * sizeof(int));
        for (int j = 0; j < *colsize; j++)
        {
            fscanf(f, "%d", &maze[i][j]);
            if (maze[i][j] == START)
            {
                *x_start = i; *y_start = j;
            }
            else if (maze[i][j] == END)
            {
                *x_end = i; *y_end = j;
            }
        }
    }
    return maze;
}
void find_exit(int** maze, int rows, int cols, int x_start, int y_start, int x_end, int y_end)
{
//    Push start position
//    Set current position to start
//    While not found exit position
//          If cannot move next from current position
//              If cannot go back (stack empty) then no way out
//              Else go back by pop the last position
//          Else
//              Push current position
//              Check if current position is exit then stop searching
    stack.push(x_start);
    stack.push(y_start);

    while(!is_out(maze, x_start, y_start))
    {
        if (!move_next(maze, rows, cols, &x_start, &y_start))
        {
            y_start = pop();            
            x_start = pop();            
        }
        else
        {
            maze[x_start][y_start] = VISITED;
            push(x_start);
            push(y_start);

        }
    }


}

void print_maze(int** maze, int rows, int cols)
{
    printf("\n~~~~ MAZE~~~~~\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%3d ", maze[i][j]);
        printf("\n");
    }
    printf("\n");
}

int is_out(int** maze, int x_curr, int y_curr)
{
    return maze[x_curr][y_curr] == END;
}

int valid_move(int** maze, int rows, int cols, int x_curr, int y_curr)
{
    // TODO: check if x_curr, y_curr is a valid move (within maze, not visited or wall)
    int ret = FALSE;
    if (0 < x_curr < rows && 0 < y_curr < cols || *maze[x_curr][y_curr] != 1 || maze[x_curr][y_curr] != VISITED){
        ret = TRUE;
    }

    return ret;
}
int try_up(int** maze, int rows, int cols, int* x_curr, int* y_curr)
{
    // TODO: Using valid move to try go up from current position
    int ret = FALSE;

    if (valid_move(maze, rows, cols, *x_curr, *y_curr - 1))
    {
        *y_curr = *y_curr - 1;
        ret = TRUE;
    }

    return ret;
}
int try_right(int** maze, int rows, int cols, int* x_curr, int* y_curr)
{
    // TODO: Using valid move to try go right from current position
    int ret = FALSE;

    if (valid_move(maze, rows, cols, *x_curr + 1, *y_curr))
    {
        *x_curr = *x_curr + 1
        ret = TRUE;
    }

    return ret;
}
int try_down(int** maze, int rows, int cols, int* x_curr, int* y_curr)
{
    // TODO: Using valid move to try go down from current position
    int ret = FALSE;

    if (valid_move(maze, rows, cols, *x_curr, *y_curr + 1))
    {
        *y_curr = *y_curr + 1;
        ret = TRUE;
    }

    return ret;
}
int try_left(int** maze, int rows, int cols, int* x_curr, int* y_curr)
{
    // TODO: Using valid move to try go left from current position
    int ret = FALSE;

    if (valid_move(maze, rows, cols, *x_curr - 1, *y_curr))
    {
        *x_curr = *x_curr - 1;
        ret = TRUE;
    }

    return ret;
}
int move_next(int** maze, int rows, int cols, int* x_curr, int* y_curr)
{
    if (try_up   (maze, rows, cols, x_curr, y_curr)) return TRUE;
    if (try_right(maze, rows, cols, x_curr, y_curr)) return TRUE;
    if (try_down (maze, rows, cols, x_curr, y_curr)) return TRUE;
    if (try_left (maze, rows, cols, x_curr, y_curr)) return TRUE;
    
    return FALSE;
}

void clear_maze(int** maze, int rows)
{
    for (int i = 0; i < rows; i++) free(maze[i]);
    free(maze);
}

void print_exit_path()
{
    printf("Exit path: ");
    while (!is_empty())
    {
        int y = pop();
        int x = pop();
        printf("(%d, %d) ", x, y);
    }
}
