#include <stdio.h>
#include <stdlib.h>

void Chess(int i, int j, int size, int *chessBoard) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            *(chessBoard + row * size + col) = 0;
        }
    }

    int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                       {2, 1},   {1, 2},   {-1, 2}, {-2, 1}};

    for (int move = 0; move < 8; move++) {
        int new_i = i + moves[move][0];
        int new_j = j + moves[move][1];

        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            *(chessBoard + new_i * size + new_j) = 1;
        }
    }

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", *(chessBoard + row * size + col));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    int *chessBoard = (int *)malloc(8 * 8 * sizeof(int));
    Chess(i, j, 8, chessBoard);
    free(chessBoard);
    return 0;
}
