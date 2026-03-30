#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int gameOver, pauseGame = 0;
int x, y, fruitX, fruitY, score, highScore = 0;
int tailX[100], tailY[100];
int nTail;
int speed = 100;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

// Load high score
void loadHighScore() {
    FILE *f = fopen("highscore.txt", "r");
    if (f != NULL) {
        fscanf(f, "%d", &highScore);
        fclose(f);
    }
}

// Save high score
void saveHighScore() {
    FILE *f = fopen("highscore.txt", "w");
    if (f != NULL) {
        fprintf(f, "%d", highScore);
        fclose(f);
    }
}

void setup() {
    gameOver = 0;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;
    loadHighScore();
}

void draw() {
    system("cls");

    printf("Score: %d | High Score: %d\n", score, highScore);

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            if (j == 0) printf("#");

            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if (!print) printf(" ");
            }

            if (j == WIDTH - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    if (pauseGame)
        printf("PAUSED - Press R to Resume\n");
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': dir = LEFT; break;
        case 'd': dir = RIGHT; break;
        case 'w': dir = UP; break;
        case 's': dir = DOWN; break;
        case 'x': gameOver = 1; break;
        case 'p': pauseGame = 1; break;
        case 'r': pauseGame = 0; break;
        }
    }
}

void logic() {
    if (pauseGame) return;

    int prevX = tailX[0], prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT: x--; break;
    case RIGHT: x++; break;
    case UP: y--; break;
    case DOWN: y++; break;
    }

    // Wall wrap
    if (x >= WIDTH) x = 0;
    else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0;
    else if (y < 0) y = HEIGHT - 1;

    // Tail collision
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    // Eat fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;

        // Increase difficulty
        if (speed > 50)
            speed -= 5;
    }
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(speed);
    }

    if (score > highScore) {
        highScore = score;
        saveHighScore();
    }

    printf("\nGame Over! Final Score = %d\n", score);
    printf("High Score = %d\n", highScore);

    return 0;
}