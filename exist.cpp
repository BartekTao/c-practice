#include <iostream>
#include <vector>

using namespace std;

int rows = 0, cols = 0;
bool helper(vector<vector<char>>& board, string word, int idx, int i, int j){
    if(j<0 || i==rows || j==cols || i<0){
        return false;        
    }
    if(word[idx] == board[i][j]){
        if(word.size()-1 == idx) return true;
        char temp = board[i][j];
        board[i][j] = '0';
        idx++;
        if(helper(board, word, idx, i, j-1) || helper(board, word, idx, i+1, j)
            ||helper(board, word, idx, i, j+1) || helper(board, word, idx, i-1, j)){
            return true;
        }

        //if all false 還原board => backtracking
        board[i][j] = temp;
        idx--;
        return false;
    }else{
        return false;
    }
}

bool exist(vector<vector<char>>& board, string word) {
    rows = board.size();
    cols = board[0].size();

    for(int i=0; i<rows;i++){
        for(int j=0;j<cols;j++){
            if(helper(board, word, 0, i, j)) 
                return true;
        }
    }
    return false;
}

