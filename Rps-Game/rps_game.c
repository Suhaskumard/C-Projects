#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------- ANSI COLORS ---------- */
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m" 
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

#define MOVES 5
#define SCORE_FILE "score.txt"

/* ---------- MOVE NAMES ---------- */
const char *moves[MOVES] = {
    "Rock", "Paper", "Scissors", "Lizard", "Spock"
};

/* ---------- RULE MATRIX ----------
   1  = win
  -1  = loss
   0  = draw
*/ 
int rules[MOVES][MOVES] = {
/*          R   P   S   L   Sp */
 /* Rock */ { 0, -1,  1,  1, -1 },
 /* Paper*/ { 1,  0, -1, -1,  1 },
 /* Scis */ {-1,  1,  0,  1, -1 },
 /* Liza */ {-1,  1, -1,  0,  1 },
 /* Spok */ { 1, -1,  1, -1,  0 }
};

/* ---------- STRUCT ---------- */
typedef struct {
    int wins, losses, draws;
    int streak, maxStreak;
    int moveCount[MOVES];
} Stats;

/* ---------- FUNCTION DECLARATIONS ---------- */
void playGame(int rounds, int difficulty, Stats *s);
int getPlayerMoveTimed();
int getComputerMove(int difficulty, Stats s);
void showStats(Stats s);
void saveStats(Stats s);
Stats loadStats();

/* ---------- MAIN ---------- */
int main() {
    srand(time(NULL));
    Stats stats = loadStats();
    int choice;

    do {
        printf(CYAN "\n=== ADVANCED ROCK PAPER SCISSORS ===\n" RESET);
        printf("1. Play Game\n");
        printf("2. View Statistics\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int rounds, diff;
            printf("\n1. Best of 3\n2. Best of 5\nChoice: ");
            scanf("%d", &rounds);
            rounds = (rounds == 1) ? 3 : 5;

            printf("Difficulty (1-Easy 2-Medium 3-Hard): ");
            scanf("%d", &diff);

            playGame(rounds, diff, &stats);
        }
        else if (choice == 2) {
            showStats(stats);
        }

    } while (choice != 3);

    saveStats(stats);
    printf(GREEN "\nStats saved. Goodbye!\n" RESET);
    return 0;
}

/* ---------- GAME LOGIC ---------- */
void playGame(int rounds, int difficulty, Stats *s) {
    int playerScore = 0, aiScore = 0;
    int winNeed = rounds / 2 + 1;

    while (playerScore < winNeed && aiScore < winNeed) {
        int pMove = getPlayerMoveTimed();
        int cMove = getComputerMove(difficulty, *s);

        if (pMove == -1) {
            printf(RED "Time out! You lose the round.\n" RESET);
            aiScore++;
            s->streak = 0;
            continue;
        }

        s->moveCount[pMove]++;
        printf("\nYou: %s | Computer: %s\n", moves[pMove], moves[cMove]);

        int result = rules[pMove][cMove];
        if (result == 1) {
            printf(GREEN "You win the round!\n" RESET);
            playerScore++;
            s->wins++;
            s->streak++;
            if (s->streak > s->maxStreak)
                s->maxStreak = s->streak;
        }
        else if (result == -1) {
            printf(RED "Computer wins the round!\n" RESET);
            aiScore++;
            s->losses++;
            s->streak = 0;
        }
        else {
            printf(YELLOW "Draw!\n" RESET);
            s->draws++;
        }

        printf("Score → You %d | AI %d\n", playerScore, aiScore);
    }

    if (playerScore > aiScore)
        printf(GREEN "\n🏆 YOU WON THE MATCH!\n" RESET);
    else
        printf(RED "\n💀 COMPUTER WON THE MATCH!\n" RESET);
}

/* ---------- PLAYER INPUT (TIMED) ---------- */
int getPlayerMoveTimed() {
    time_t start = time(NULL);
    int move;

    printf("\nChoose move:\n");
    printf("1. Rock  2. Paper  3. Scissors  4. Lizard  5. Spock\n");
    printf("Choice: ");
    scanf("%d", &move);

    if (difftime(time(NULL), start) > 5)
        return -1;

    if (move < 1 || move > 5)
        return getPlayerMoveTimed();

    return move - 1;
}

/* ---------- AI ---------- */
int getComputerMove(int difficulty, Stats s) {
    if (difficulty == 1)
        return rand() % MOVES;

    int maxMove = 0;
    for (int i = 1; i < MOVES; i++)
        if (s.moveCount[i] > s.moveCount[maxMove])
            maxMove = i;

    if (difficulty == 3) {
        for (int i = 0; i < MOVES; i++)
            if (rules[i][maxMove] == 1)
                return i;
    }

    return rand() % MOVES;
}

/* ---------- STATS ---------- */
void showStats(Stats s) {
    printf(CYAN "\n--- PLAYER STATISTICS ---\n" RESET);
    printf("Wins: %d\n", s.wins);
    printf("Losses: %d\n", s.losses);
    printf("Draws: %d\n", s.draws);
    printf("Max Win Streak: %d\n", s.maxStreak);

    printf("\nMove Usage:\n");
    for (int i = 0; i < MOVES; i++)
        printf("%s: %d\n", moves[i], s.moveCount[i]);
}

/* ---------- FILE HANDLING ---------- */
void saveStats(Stats s) {
    FILE *fp = fopen(SCORE_FILE, "w");
    if (!fp) return;

    fprintf(fp, "%d %d %d %d\n",
            s.wins, s.losses, s.draws, s.maxStreak);

    for (int i = 0; i < MOVES; i++)
        fprintf(fp, "%d ", s.moveCount[i]);

    fclose(fp);
}

Stats loadStats() {
    Stats s = {0};
    FILE *fp = fopen(SCORE_FILE, "r");

    if (fp) {
        fscanf(fp, "%d %d %d %d",
               &s.wins, &s.losses, &s.draws, &s.maxStreak);
        for (int i = 0; i < MOVES; i++)
            fscanf(fp, "%d", &s.moveCount[i]);
        fclose(fp);
    }
    return s;
}
