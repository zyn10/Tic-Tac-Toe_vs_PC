//
//  game.c
//  game
//
//  Created by 👻 on 02/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

char board[3][3];
//=================================================
//======        G R E E T   U S E R        ========
//=================================================
void greetUser(void)
{   char Name[20];
    printf("\nEnter your name = ");
    scanf("%s",Name);
    
    printf("\nHello %s ... lets have Fun",Name);
    printf("\n%s      =>  'x'",Name);
    printf("\nComputer  =>  'o'");
    
}
//=================================================
//======  I N I T I A L I Z E   B O A R D  ========
//=================================================
void initializeBoard(void)
{
    int i=0;
    int j=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            board[i][j]='-';
        }
    }
}
//=================================================
//======      P R I N  T   B O A R D       ========
//=================================================
void PrintBoard(void){
    printf("\n\n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);

    printf("     |     |     \n\n");
}

//=================================================
//======      P L A Y E R    M O V E       ========
//=================================================
void PlayerMove(void){
    int col=0;
    int row=0;
    int check=0;

    while (check==0)
    {
        int check2=0;//----------> for range checking if the row & col is in between 1 and 3
        while(check2==0)
        {
        printf("\nEnter X,Y cordinates for your move: ");
        scanf("%d,%d", &row,&col);
            row=row-1;
            col=col-1;
            if((row>2 || row < 0)||(col>2 || col < 0))
            {
                printf("INVALID Coordinate");
                printf("Enter Again between 1 and 3");
                //if invalid input user will jump to enter the row  again
                check2=0;
            }
            else
            {
                check2=1;
            }
        }
        if (board [row][col]== '-' && ((board [row][col]!= 'x')||(board [row][col]!= 'o' ) ))
        {
            board[row][col]='x';
            check=1;
        }
        else
        {
            printf("INVALID INPUT \n:=> ALready placed...    ");
            printf("Enter Again");
            //if invalid input user will jump to enter the row &coloumn again
            check=0;
        }
    }
}
//=================================================
//======  C O M P U T E R    M O V E       ========
//=================================================
void PCMove(void){
    int check=0;
    while (check==0)
    {
        
        int randomX = rand()% 3;
        int randomY = rand()% 3;
        if (board [randomX][randomY]== '-' && ((board [randomX][randomY]!= 'x')||(board [randomX][randomY]!= 'o' ) ))
        {
            board[randomX][randomY]='o';
            check=1;
        }
        else
        {
            check=0;
        }
    }
}
// ====================================
// ========= Draw   CONTIONS ==========
// ====================================
int drawCheck(void) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if (board[i][j] == '-') {
        return 0;
      }
    }
  }
  return 20;
}

//=================================================
//======  C H E C K      W I N N E R       ========
//=================================================
int WinCheck(void){
    int gameWon=0;
    // ====================================
    // ========= Player WIN CONTIONS ======
    // ====================================
    if(board[0][0]=='x'&&board[0][1]=='x'&&board[0][2]=='x')
    {
        printf("Hurray YOU WIN\n");
        gameWon=5;
        }
    else if(board[1][0]=='x'&&board[1][1]=='x'&&board[1][2]=='x')
    {
        printf("Hurray YOU WIN\n");
        gameWon=5;
        }
    else if(board[2][0]=='x'&&board[2][1]=='x'&&board[2][2]=='x')
    {
        printf("Hurray YOU WIN\n");
        gameWon=5;
        }
    else if(board[0][0]=='x'&&board[1][1]=='x'&&board[2][2]=='x')
    {
        printf("Hurray YOU WIN\n");
        gameWon=5;
        }
    else if(board[2][0]=='x'&&board[1][1]=='x'&&board[0][2]=='x')
    {
        printf("Hurray YOU WIN\n");
        gameWon=5;
        }
    else if(board[0][0]=='x'&&board[1][0]=='x'&&board[2][0]=='x')
    {
        printf("Hurray YOU WIN\n");
        gameWon=5;
        }
    else if(board[0][1]=='x'&&board[1][1]=='x'&&board[2][1]=='x')
    {
        printf("Hurray YOU WIN\n");
        gameWon=5;
        }
    else if(board[0][2]=='x'&&board[1][2]=='x'&&board[2][2]=='x')
    {
        printf("Hurray YOU WIN\n");
        gameWon=5;
        }
    
   // ====================================
   // ========= PC WIN CONTIONS ==========
   // ====================================
    else if(board[0][0]=='o'&&board[0][1]=='o'&&board[0][2]=='o')
    {
        printf("PC WIN's\n");
        gameWon=1;
        }
    else if(board[1][0]=='o'&&board[1][1]=='o'&&board[1][2]=='o')
    {
        printf("PC WIN's\n");
        gameWon=1;
        
    }
    else if(board[2][0]=='o'&&board[2][1]=='o'&&board[2][2]=='o')
    {
        printf("PC WIN's\n");
        gameWon=1;
        }
    else if(board[0][0]=='o'&&board[1][1]=='o'&&board[2][2]=='o')
    {
        printf("PC WIN's\n");
        gameWon=1;
        }
    else if(board[2][0]=='o'&&board[1][1]=='o'&&board[0][2]=='o')
    {
        printf("PC WIN's\n");
        gameWon=1;
        }
    else if(board[0][0]=='o'&&board[1][0]=='o'&&board[2][0]=='o')
    {
        printf("PC WIN's\n");
        gameWon=1;
        }
    else if(board[0][1]=='o'&&board[1][1]=='o'&&board[2][1]=='o')
    {
        printf("PC WIN's\n");
        gameWon=1;
        }
    else if(board[0][2]=='o'&&board[1][2]=='o'&&board[2][2]=='o')
    {
        printf("PC WIN's\n");
        gameWon=1;
        }
    else{
        gameWon=4;
    }
    
    return gameWon;
}


int main(int argc, const char * argv[])
{
    srand(time(NULL));//for Random Number when PC Function is fired
    
    printf("\t\t\t========================\n");
    printf("\t\t\t Welcome to Tic-Tac-Toe");
    printf("\n\t\t\t========================\n");
    
    
    greetUser();
    
    
    char choice='y';
    int winorLose=10;//------->none of the player is won
    
    do
    {   initializeBoard();
        PrintBoard();

        while(1){
        PlayerMove();
        PrintBoard();
        winorLose=WinCheck();
        if(winorLose==5)//------>Player won
        {
            break;
        }
        winorLose=drawCheck();
        if(winorLose==20)//------>PC won
        {
            printf("Draw Draw..");
            break;
        }
        PCMove();
        PrintBoard();
        winorLose=WinCheck();
        if(winorLose==1)//------>PC won
        {
        break;
        }
       
            
    }
        printf("Do you want to play again (y/n)");
        scanf("%s",&choice);
       
    }
    while (choice=='y');
    
    return 0;
}
