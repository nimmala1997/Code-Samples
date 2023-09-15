#include<iostream>
#include<vector>

using namespace std;

void updategroups(int firstValue, int secondValue, vector<int> &groups){
    if(groups[firstValue] == firstValue){
        if(secondValue != groups[secondValue]) updategroups(groups[firstValue], groups[secondValue], groups);
        groups[secondValue] = firstValue;
        return;
    }
    else{
        updategroups(groups[firstValue], firstValue, groups);
        if(secondValue != groups[secondValue]) updategroups(groups[firstValue], groups[secondValue], groups);
        groups[secondValue] = groups[firstValue];
    }
}

int solve(int A, vector<int> &B, vector<vector<int> > &C, int D) {
    vector<int> groups(A+1, 0);
    for(int i = 1 ; i <= A ; i++){
        groups[i] = i;
    }
    for(int i = 0 ; i < C.size() ; i++){
        updategroups(C[i][0], C[i][1], groups);
    }
    for(int i = 1 ; i < C.size() ; i++){
        updategroups(i, groups[i], groups);
    }
    vector<int> groupSum(A+1, 0);
    for(int i = 1 ; i <= A ; i++){
        int currentValue = B[i-1];
        groupSum[groups[i]] += currentValue;
    }
    int answer = 0;
    for(int i = 1 ; i <= A ; i++){
        answer += groupSum[i] >= D ? 1 : 0;
    }
    return answer;
}

int main(){
     vector<int> B = {7,5,7,3,9,4,4,6,3,1,4,8,7,6};
     vector<vector<int>> C = {
        {1, 2},
        {2, 6},
        {2, 7},
        {4, 13},
        {5, 8},
        {5, 13},
        {6, 12},
        {7, 10},
        {10, 14},
        {13, 14}
     };
     int answer = solve(14, B, C, 2);
     return 0;
}