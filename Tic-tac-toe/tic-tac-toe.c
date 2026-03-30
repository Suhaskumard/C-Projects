#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ANSI Colors */
#define RED   "\033[1;31m"
#define BLUE  "\033[1;34m"
#define RESET "\033[0m"

#define HUMAN 'X'
#define AI 'O'
#define EMPTY ' '

char board[3][3];
int humanWins = 0, aiWins = 0, draws = 0;

/* ---------- FILE SAVE ---------- */
void saveLeaderboard() {
    FILE *fp = fopen("leaderboard.txt", "a");
    if (!fp) return;
    fprintf(fp, "Human:%d AI:%d Draws:%d\n", humanWins, aiWins, draws);
    fclose(fp);
}

/* ---------- BOARD ---------- */
void initBoard() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=EMPTY;
}

void printCell(char c){
    if(c==HUMAN) printf(RED " X " RESET);
    else if(c==AI) printf(BLUE " O " RESET);
    else printf("   ");
}

void printBoard(){
    printf("\n");
    for(int i=0;i<3;i++){
        printCell(board[i][0]); printf("|");
        printCell(board[i][1]); printf("|");
        printCell(board[i][2]); printf("\n");
        if(i<2) printf("---+---+---\n");
    }
}

/* ---------- GAME LOGIC ---------- */
int checkWin(char p){
    for(int i=0;i<3;i++){
        if(board[i][0]==p&&board[i][1]==p&&board[i][2]==p) return 1;
        if(board[0][i]==p&&board[1][i]==p&&board[2][i]==p) return 1;
    }
    if(board[0][0]==p&&board[1][1]==p&&board[2][2]==p) return 1;
    if(board[0][2]==p&&board[1][1]==p&&board[2][0]==p) return 1;
    return 0;
}

int isDraw(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==EMPTY) return 0;
    return 1;
}

/* ---------- MINIMAX ---------- */
int minimax(int depth,int isMax){
    if(checkWin(AI)) return 10-depth;
    if(checkWin(HUMAN)) return depth-10;
    if(isDraw()) return 0;

    if(isMax){
        int best=-1000;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==EMPTY){
                    board[i][j]=AI;
                    int score=minimax(depth+1,0);
                    board[i][j]=EMPTY;
                    if(score>best) best=score;
                }
        return best;
    } else {
        int best=1000;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==EMPTY){
                    board[i][j]=HUMAN;
                    int score=minimax(depth+1,1);
                    board[i][j]=EMPTY;
                    if(score<best) best=score;
                }
        return best;
    }
}

void bestMove(){
    int bestScore=-1000,r=-1,c=-1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==EMPTY){
                board[i][j]=AI;
                int score=minimax(0,0);
                board[i][j]=EMPTY;
                if(score>bestScore){
                    bestScore=score;
                    r=i; c=j;
                }
            }
    board[r][c]=AI;
}

/* ---------- MOVES ---------- */
void humanMove(){
    int pos;
    while(1){
        printf("Enter position (1-9): ");
        scanf("%d",&pos);
        if(pos<1||pos>9) continue;
        int r=(pos-1)/3,c=(pos-1)%3;
        if(board[r][c]!=EMPTY) continue;
        board[r][c]=HUMAN;
        break;
    }
}

/* ---------- MATCH ---------- */
int playMatch(){
    initBoard();
    while(1){
        printBoard();
        humanMove();

        if(checkWin(HUMAN)){ printBoard(); return 1; }
        if(isDraw()){ printBoard(); return 0; }

        bestMove();
        if(checkWin(AI)){ printBoard(); return -1; }
        if(isDraw()){ printBoard(); return 0; }
    }
}

/* ---------- TOURNAMENT ---------- */
void tournament(){
    int rounds;
    printf("Enter number of rounds: ");
    scanf("%d",&rounds);

    humanWins=aiWins=draws=0;

    for(int i=1;i<=rounds;i++){
        printf("\n=== ROUND %d ===\n",i);
        int r=playMatch();
        if(r==1) humanWins++;
        else if(r==-1) aiWins++;
        else draws++;
    }

    printf("\n🏆 FINAL SCORE\nHuman:%d AI:%d Draws:%d\n",
           humanWins,aiWins,draws);

    saveLeaderboard();
}

/* ---------- MAIN ---------- */
int main(){
    srand(time(NULL));
    printf("🎮 TIC TAC TOE (UNBEATABLE AI)\n");
    tournament();
    printf("\nResults saved to leaderboard.txt\n");
    return 0;
}