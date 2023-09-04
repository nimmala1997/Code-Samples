#include<iostream>
#include<vector>

using namespace std;

void getAllCombinations(int currentIndex, vector<int> &A, int B , vector<int> &currentCombination, int currentCombinationSum, vector<vector<int> > &answer){
    if(currentCombinationSum == B){
        answer.push_back(currentCombination);
        return;
    }
    if(currentCombinationSum > B || currentIndex == A.size()){
        return;
    }
    for(int i = currentIndex; i < A.size(); i++){
        if(i > currentIndex && A[i] == A[i-1]) continue;
        currentCombination.push_back(A.at(i));
        getAllCombinations(currentIndex + 1 , A, B, currentCombination, currentCombinationSum + A.at(i), answer);
        currentCombination.pop_back();
    }
}
vector<vector<int> > combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int> > answer;
    vector<int> currentCombination;
    int currentCombinationSum = 0;
    getAllCombinations(0, A, B, currentCombination, currentCombinationSum, answer);
    return answer;
}

int main() {
     vector<int> input = {1,2,1};
     int B = 4;
     auto answer = combinationSum(input, B);
     return 0;
}