#include<iostream>
#include<vector>

using namespace std;

void allPermutations(int count, vector<bool> presentValues, vector<int> input, vector<vector<int> > &answer, vector<int> currentCombination){
    if(count == input.size()){
        answer.push_back(currentCombination);
        currentCombination.clear();
        return;
    }

    for(int i = 0 ; i < input.size() ; i++){
        if(presentValues[i]) continue;
        currentCombination.push_back(input[i]);
        presentValues[i] = true;
        allPermutations(count + 1, presentValues, input, answer, currentCombination);
        currentCombination.pop_back();
        presentValues[i] = false;
    }
}

vector<vector<int> > permute(vector<int> &A) {
    vector<vector<int> > answer;
    vector<bool> presentValues(A.size(), false);
    vector<int> currentCombination;
    allPermutations(0, presentValues, A, answer, currentCombination);
    return answer;
}

int main(){
     vector<int> input = {1,2,3};
     auto answer = permute(input);
     return 0;
}