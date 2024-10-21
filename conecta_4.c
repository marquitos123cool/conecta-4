/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define ROWS 6
#define COLS 7

void printBoard(char board[ROWS][COLS]);
int dropPiece(char board[ROWS][COLS], int col, char piece);
int checkWin(char board[ROWS][COLS], char piece);

int main() {
    char board[ROWS][COLS];
    int currentPlayer = 1;  // 1 for Player 1 ('X'), 2 for Player 2 ('O')
    int column, row, moves = 0;
    char piece;

    // Initialize the board with empty spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    while (1) {
        printBoard(board);
        piece = (currentPlayer == 1) ? 'X' : 'O';
        printf("Player %d (%c), choose a column (0-6): ", currentPlayer, piece);
        scanf("%d", &column);

        if (column < 0 || column >= COLS) {
            printf("Invalid column. Please try again.\n");
            continue;
        }

        row = dropPiece(board, column, piece);
        if (row == -1) {
            printf("Column is full. Please choose another column.\n");
            continue;
        }

        moves++;
        if (checkWin(board, piece)) {
            printBoard(board);
            printf("Player %d (%c) wins!\n", currentPlayer, piece);
            break;
        }

        if (moves == ROWS * COLS) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}

void printBoard(char board[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
    for (int j = 0; j < COLS; j++) {
        printf("  %d ", j);
    }
    printf("\n\n");
}

int dropPiece(char board[ROWS][COLS], int col, char piece) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = piece;
            return i;
        }
    }
    return -1;
}

int checkWin(char board[ROWS][COLS], char piece) {
    // Check horizontal, vertical, and diagonal lines for a win
    // Horizontal check
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == piece && board[i][j + 1] == piece &&
                board[i][j + 2] == piece && board[i][j + 3] == piece) {
                return 1;
            }
        }
    }

    // Vertical check
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == piece && board[i + 1][j] == piece &&
                board[i + 2][j] == piece && board[i + 3][j] == piece) {
                return 1;
            }
        }
    }

    // Diagonal check (\ direction)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == piece && board[i + 1][j + 1] == piece &&
                board[i + 2][j + 2] == piece && board[i + 3][j + 3] == piece) {
                return 1;
            }
        }
    }

    // Diagonal check (/ direction)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 3; j < COLS; j++) {
            if (board[i][j] == piece && board[i + 1][j - 1] == piece &&
                board[i + 2][j - 2] == piece && board[i + 3][j - 3] == piece) {
                return 1;
            }
        }
    }

    return 0;
}
