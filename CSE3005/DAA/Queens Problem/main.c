//
//  main.c
//  Queens Problem
//
//  Created by Swarup Ghosh on 27/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

void show_board(bool **board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j]) printf(" Q ");
            else printf(" 0 ");
        }
        printf("\n");
    }
}

bool safe(bool **board, int row, int col) {
    int i, j;
  
    for (i = 0; i < col; i++) if (board[row][i]) return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--) if (board[i][j]) return false;
  
    return true;
}

bool solve_nq_until(bool **board, int col) {
    if (col >= N) return true;
    
    for (int i = 0; i < N; i++) {
        if (safe(board, i, col)) {
            board[i][col] = true;
            if (solve_nq_until(board, col + 1)) return true;
            board[i][col] = false; // BACKTRACK
        }
    }
    
    return false;
}

bool solve() {
    bool **board = malloc(N * sizeof(bool*));
    int i;
    for(i = 0; i < N; i++) {
        board[i] = calloc(N, sizeof(bool));
    }
  
    if (solve_nq_until(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
  
    show_board(board);
    return true;
}

int main() {
    printf("%d Queen's Problem Solution.\n", N);
    solve();
    printf("\n");
    return 0;
}
