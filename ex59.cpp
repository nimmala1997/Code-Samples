#include<iostream>
#include<vector>

using namespace std ;

void findTheNumber(vector<int> &A, int currentIndex, int &numberOfSquareArrays, vector<int> currentArray, vector<bool> &isVisited){
    if(currentIndex >= 2) {
        int sqrtOfTwoNumbers = sqrt(currentArray[currentIndex - 1] + currentArray[currentIndex - 2]);
        if(sqrtOfTwoNumbers * sqrtOfTwoNumbers != currentArray[currentIndex - 1] + currentArray[currentIndex - 2])
            return ;
    }
    if(currentIndex == A.size()) {
          numberOfSquareArrays++;
               return ;
    }
    unordered_map<int, int> myMap;
    for(int i = 0 ; i < A.size() ; i++){
        if(isVisited.at(i) == false && myMap[A.at(i)] == 0) {
            isVisited.at(i) = true;
            myMap[A.at(i)]++;
            currentArray[currentIndex] = A.at(i);
            findTheNumber(A, currentIndex + 1, numberOfSquareArrays, currentArray, isVisited);
            isVisited.at(i) = false;
        }
    }
}

int solve(vector<int> &A) {
    int numberOfSquareArrays = 0 ;
    vector<int> currentArray(A.size());
    vector<bool> isVisited(A.size(), false);
    findTheNumber(A, 0, numberOfSquareArrays, currentArray, isVisited);
    return numberOfSquareArrays;
}

int main() {
     vector<int> A = {1, 17, 8};
     int answer = solve(A);
     return 0;
}