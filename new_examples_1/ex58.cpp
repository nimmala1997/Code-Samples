#include<iostream>
#include<vector>
#include<map>
using namespace std;

void getAllPermutations(vector<int> A, int currentIndex, vector<int> currentArray, unordered_map<int, int> isVisited, vector<vector<int> > &answer) {
    if(currentIndex == A.size()){
        answer.push_back(currentArray);
        return;
    }
    vector<int> isCurrentElementVisited(11, 0);
    for(int i = 0 ; i < A.size() ; i++) {
        if(isVisited[A.at(i)] == 0 && isCurrentElementVisited[A.at(i)] == 0){
            isVisited[A.at(i)]++;
            isCurrentElementVisited[A.at(i)]++;
            currentArray[currentIndex] = A.at(i);
            getAllPermutations(A, currentIndex + 1, currentArray, isVisited, answer);
            isVisited[A.at(i)]--;
        }
    }
}

vector<vector<int> > permute(vector<int> &A) {
    vector<vector<int> > answer ;
    unordered_map<int, int> isVisited;
    vector<int> currentArray(A.size());
    getAllPermutations(A, 0, currentArray, isVisited, answer);
    return answer;
}

int main(){
     vector<int> input = {1,2,1};
     auto answer = permute(input);
     return 0;
}