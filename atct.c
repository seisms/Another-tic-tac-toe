#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "game.h"

cell game_board[SPACES][SPACES];

static winning paths[] = {
    {true,    0,0,    0,1,    0,2},
    {true,    1,0,    1,1,    1,2}, /*horizontal paths*/
    {true,    2,0,    2,1,    2,2},

    {true,    0,0,    1,0,    2,0},
    {true,    0,1,    1,1,    2,1}, /*vertical paths*/
    {true,    0,2,    1,2,    2,2},

    {true,    0,0,    1,1,    2,2}, /*left-to-right diagonal*/
    {true,    0,2,    1,1,    2,0}, /*right-to-left diagonal*/

    /*dumb illegal winning paths go here*/

    {true,    0,0,    1,1,    0,2}, /*upper zig-zag*/
    {true,    2,0,    1,1,    2,2}, /*lower zig-zag*/

    {false,    0,0,    0,0,    0,0},
};


void game_init(){
    for(int i=0; i<SPACES;i++)
        for(int j=0; j<SPACES; j++){
            game_board[i][j].is_used = false;
            game_board[i][j].placed= ' ';
        }
}

int gameloop(){
    int turn=0, n;
    char c;
    do{
        int x, y;
        c = (turn%2==0) ? 'X' : 'O';
        printboard();
        printf("\nturn: %d\n\n",turn);
        printf("PLAYER %c: Choose X and Y coordinates ",c);
        do{
            scanf("%d",&x); scanf("%d",&y);
            if(game_board[x][y].is_used)
                printf("Placement used. Try again! ");
        }while((x<0 || x>2 || y<0 || y>2) || game_board[x][y].is_used);
        game_board[x][y].placed=c; game_board[x][y].is_used=true; /*takes the coordinates for the current player*/
        turn++;
        system("clear");
        n = wintie();
    }while(!n && turn <= 9); 
    if(!n){ /*ugly way of checking for a tie*/
        system("clear");
        printboard();
        printf("It's a tie! Play again? (y/n) ");
        scanf(" %c", &c);
        if(c == 'y'){
            game_init();
            turn = 0;
        }
        else 
            return 0;
    }
    c = (n == 1) ? 'X' : 'O';
    printboard();
    printf("Player %c won! Play again? (y/n) ", c);
    scanf(" %c", &c);
    return (c == 'y') ? 1 : 0;
}

void printboard(){
    printf("  ");
    for(int i = 0; i<SPACES; i++)
        printf(" %d", i);
    printf("\n");
    for(int i = 0; i<SPACES; i++){
        printf("%d |", i);
        for(int j=0; j<SPACES; j++){
            printf("%c ",game_board[i][j].placed);
        }
        printf("|\n");
    }
    
}

int wintie(){
    for(winning *p = paths; p->winpath;p++){
        char a = game_board[p->rowA][p->colA].placed;
        char b = game_board[p->rowB][p->colB].placed;
        char c = game_board[p->rowC][p->colC].placed;

        if(a == b && b == c && a != ' ')
            return (a == 'X') ? 1 : -1;
    }
    return 0;
}

int main(){
    int n;
    do{
        game_init();
        system("clear");
        n = gameloop();
    }while(n);
    return EXIT_SUCCESS;
}

