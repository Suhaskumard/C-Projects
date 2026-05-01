#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

int gameOver = 0;
int score = 0;

int pacX = 1, pacY = 1;
int ghostX = 25, ghostY = 15;
int foodX, foodY;

char dir = 'd';

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void generateFood()
{
    foodX = rand() % (WIDTH - 2) + 1;
    foodY = rand() % (HEIGHT - 2) + 1;
}

void drawBorder()
{
    for (int i = 0; i < WIDTH; i++)
    {
        gotoxy(i, 0);
        printf("#");
        gotoxy(i, HEIGHT - 1);
        printf("#");
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        gotoxy(0, i);
        printf("#");
        gotoxy(WIDTH - 1, i);
        printf("#");
    }
}

void draw()
{
    // Clear screen before redrawing
    system("cls");

    gotoxy(0, 0);

    for (int i = 1; i < HEIGHT - 1; i++)
    {
        for (int j = 1; j < WIDTH - 1; j++)
        {
            gotoxy(j, i);

            if (i == pacY && j == pacX)
                printf("C");
            else if (i == ghostY && j == ghostX)
                printf("G");
            else if (i == foodY && j == foodX)
                printf(".");
            else
                printf(" ");
        }
    }

    drawBorder();

    gotoxy(0, HEIGHT);
    printf("Score: %d   ", score);
    gotoxy(0, HEIGHT + 1);
    printf("Use W A S D | X = Exit");
}

void input()
{
    if (_kbhit())
    {
        char ch = _getch();

        if (ch == 'w' || ch == 'W') dir = 'w';
        if (ch == 's' || ch == 'S') dir = 's';
        if (ch == 'a' || ch == 'A') dir = 'a';
        if (ch == 'd' || ch == 'D') dir = 'd';
        if (ch == 'x' || ch == 'X') gameOver = 1;
    }
}

void movePacman()
{
    if (dir == 'w' && pacY > 1) pacY--;
    if (dir == 's' && pacY < HEIGHT - 2) pacY++;
    if (dir == 'a' && pacX > 1) pacX--;
    if (dir == 'd' && pacX < WIDTH - 2) pacX++;
}

void moveGhost()
{
    // Move ghost every 2nd frame to slow it down
    static int moveCounter = 0;
    moveCounter++;
    if (moveCounter % 2 != 0) return;

    // Add some randomness to ghost movement (70% toward player, 30% random)
    int moveTowardPlayer = rand() % 10;

    if (moveTowardPlayer < 7) {
        // Move toward player (optimal path)
        if (ghostX < pacX) ghostX++;
        else if (ghostX > pacX) ghostX--;

        if (ghostY < pacY) ghostY++;
        else if (ghostY > pacY) ghostY--;
    } else {
        // Random movement
        int randDir = rand() % 4;
        if (randDir == 0 && ghostX < WIDTH - 2) ghostX++;
        else if (randDir == 1 && ghostX > 1) ghostX--;
        else if (randDir == 2 && ghostY < HEIGHT - 2) ghostY++;
        else if (randDir == 3 && ghostY > 1) ghostY--;
    }
}

void logic()
{
    movePacman();

    if (pacX == foodX && pacY == foodY)
    {
        score += 10;
        generateFood();
    }

    moveGhost();

    if (pacX == ghostX && pacY == ghostY)
        gameOver = 1;
}

int main()
{
    srand(time(0));
    hideCursor();
    generateFood();

    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(150);
    }

    gotoxy(0, HEIGHT + 3);
    printf("GAME OVER! Final Score: %d\n", score);

    return 0;
}
