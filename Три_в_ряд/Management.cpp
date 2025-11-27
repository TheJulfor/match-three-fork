#include <vector>
#include <random>
#include "Management_Header.h"


void win_comb(std::vector<std::vector<char>>& board) {
    for (int i = 0; i<8;i++) {
        for (int j = 0; j<8;j++) {
            if (j>1){
                if ( (board[i][j]=='X' || board[i][j]=='1') && (board[i][j-1]=='X' || board[i][j-1]=='1') && (board[i][j-2]=='X' || board[i][j-2]=='1')) {
                    board[i][j]='1';
                    board[i][j-1]='1';
                    board[i][j-2]='1';
                }
                if ( (board[i][j]=='O' || board[i][j]=='2') && (board[i][j-1]=='O' || board[i][j-1]=='2') && (board[i][j-2]=='O' || board[i][j-2]=='2')) {
                    board[i][j]='2';
                    board[i][j-1]='2';
                    board[i][j-2]='2';
                }
                if ( (board[i][j]=='#' || board[i][j]=='3') && (board[i][j-1]=='#' || board[i][j-1]=='3') && (board[i][j-2]=='#' || board[i][j-2]=='3')) {
                    board[i][j]='3';
                    board[i][j-1]='3';
                    board[i][j-2]='3';
                }
                if ( (board[i][j]=='$' || board[i][j]=='4') && (board[i][j-1]=='$' || board[i][j-1]=='4') && (board[i][j-2]=='$' || board[i][j-2]=='4')) {
                    board[i][j]='4';
                    board[i][j-1]='4';
                    board[i][j-2]='4';
                }
            }
            if (i>1) {
                if ( (board[i][j]=='X' || board[i][j]=='1') && (board[i-1][j]=='X' || board[i-1][j]=='1') && (board[i-2][j]=='X' || board[i-2][j]=='1')) {
                    board[i][j]='1';
                    board[i-1][j]='1';
                    board[i-2][j]='1';
                }
                if ( (board[i][j]=='O' || board[i][j]=='2') && (board[i-1][j]=='O' || board[i-1][j]=='2') && (board[i-2][j]=='O' || board[i-2][j]=='2')) {
                    board[i][j]='2';
                    board[i-1][j]='2';
                    board[i-2][j]='2';
                }
                if ( (board[i][j]=='#' || board[i][j]=='3') && (board[i-1][j]=='#' || board[i-1][j]=='3') && (board[i-2][j]=='#' || board[i-2][j]=='3')) {
                    board[i][j]='3';
                    board[i-1][j]='3';
                    board[i-2][j]='3';
                }
                if ( (board[i][j]=='$' || board[i][j]=='4') && (board[i-1][j]=='$' || board[i-1][j]=='4') && (board[i-2][j]=='$' || board[i-2][j]=='4')) {
                    board[i][j]='4';
                    board[i-1][j]='4';
                    board[i-2][j]='4';
                }
            }
        }
    }
}

int number_of_winning_cells(std::vector<std::vector<char>> board) {
    int count=0;
    for (int i = 0 ;i<8;i++) {
        for (int j = 0;j<8;j++) {
            if (board[i][j]=='1' || board[i][j]=='2' || board[i][j]=='3' || board[i][j]=='4') {
                count++;
            }
        }
    }
    return count;
}

void generation_of_new_cells(std::vector<std::vector<char>>& board, bool& gen) {
    while (number_of_winning_cells(board)!=0) {
        std::vector<char> symbols2 = {'X', 'O', '#', '$'};
        for (int i = 7; i>=0; i--) {
            for (int j = 7; j>=0; j--) {
                if (board[i][j]=='1' || board[i][j]=='2' || board[i][j]=='3' || board[i][j]=='4') {
                    gen = 0;
                    if (i==0) {
                        int tmp_ind=rand()%4;
                        board[i][j]=symbols2[tmp_ind];

                    }
                    else {
                        std::swap(board[i][j],board[i-1][j]);
                    }
                }
            }
        }
    }
}