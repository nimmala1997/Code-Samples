#include<iostream>
#include<vector>

using namespace std;

bool checkValidElement(vector<vector<char> > &A, int rowOfElement, int columnOfElement) {
    for(int i = 0 ; i < 9 ; i++){
        if(i != columnOfElement && A[rowOfElement][i] == A[rowOfElement][columnOfElement]) return false;
        if(i != rowOfElement && A[i][columnOfElement] == A[rowOfElement][columnOfElement]) return false;
    }
    int startRow = (rowOfElement/3) * 3;
    int startColumn = (columnOfElement/3) * 3;
    for(int i = startRow ; i < startRow + 3 ; i++){
        for(int j = startColumn ; j < startColumn+3 ; j++){
            if(i == rowOfElement && j == columnOfElement)
               continue;
            if( && A[i][j] == A[rowOfElement][columnOfElement])
                return false;
        }
    }
    return true;
}

bool fillSudoku(int count, vector<vector<char> > &A){
    if(count == 81){
        return true;
    }
    int rowOfElement = count/9 ;
    int columnOfElement = count%9 ;
    if(A[rowOfElement][columnOfElement] != '.') 
       return fillSudoku(count+1, A);
    for(int i = 1 ; i <= 9 ; ++i) {
        A[rowOfElement][columnOfElement] = '0' + i;
        if(checkValidElement(A, rowOfElement, columnOfElement) && fillSudoku(count+1, A) ){
            return true;
        }
        A[rowOfElement][columnOfElement] = '.';
    }
    return false;
}

void solveSudoku(vector<vector<char> > &A) {
    bool answer = fillSudoku(0, A);
}

int main() {
     vector<vector<char>> sudoku = {
          {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
     };
     solveSudoku(sudoku);
     return 0;
}