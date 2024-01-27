#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isValidCombination(const vector<int> &currentPositions, const int &currentPosition, const int A){
    int currentSize = currentPositions.size();
    for(int i = 0 ; i < currentSize; i++){
        if(currentPosition == currentPositions[i]) return false;
        int rightSide = currentPositions[i] + currentSize - i;
        if(rightSide < A && rightSide == currentPosition) return false;
        int leftSide = currentPositions[i] - currentSize + i;
        if(leftSide >= 0 && leftSide == currentPosition) return false;
    }
    return true;
}

void getValidPositions(vector<string> currentCombination, vector<int> currentPositions, const int A, vector<vector<string> > &answer){
    if(currentCombination.size() == A){
        answer.push_back(currentCombination);
        return;
    }
    string current(A, '.');
    for(int i = 0 ; i < A ; i++){
        current[i] = 'Q';
        if(isValidCombination(currentPositions, i, A)) {  
            currentCombination.push_back(current);
            currentPositions.push_back(i);
            getValidPositions(currentCombination, currentPositions, A, answer);
            currentPositions.pop_back();
            currentCombination.pop_back();
        }
        current[i] = '.';
    }
}

vector<vector<string> > solveNQueens(int A) {
    vector<string> currentCombination;
    vector<int> currentPositions;
    vector<vector<string> > answer;
    getValidPositions(currentCombination, currentPositions, A, answer);
    return answer;
}

int main(){
     int A = 4;
     auto answer = solveNQueens(A);
     return 0;
}