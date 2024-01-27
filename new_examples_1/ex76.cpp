#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void updateGroups(int firstValue, int secondValue, vector<int> &groups){
    if(groups[firstValue] == firstValue){
        if(secondValue != groups[secondValue]) updateGroups(groups[firstValue], groups[secondValue], groups);
        groups[secondValue] = groups[firstValue];
        return;
    }
    else{
        updateGroups(groups[firstValue], firstValue, groups);
        if(secondValue != groups[secondValue]) updateGroups(groups[firstValue], groups[secondValue], groups);
        groups[secondValue] = groups[firstValue];
    }
}

void DSU(vector<vector<int> > &B, vector<int> &groups){
    for(int i = 0 ; i < B.size() ; i++){
        updateGroups(B[i][0], B[i][1], groups);
    }
    for(int i = 0 ; i < B.size() ; i++){
        updateGroups(B[i][0], B[i][1], groups);
    }
}

int solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    vector<int> groups(A+1, 0);
    for(int i = 0 ; i < B.size() ; i++){
        groups[B[i][0]] = 1;
        groups[B[i][1]] = 1;
    }
    for(int i = 0 ; i < C.size() ; i++){
        if(groups[C[i][0]] == 1 || groups[C[i][1]] == 1) return 0;
        groups[C[i][0]] = 2;
        groups[C[i][1]] = 2;
    }
    for(int i = 1 ; i < groups.size() ; i++){
        groups[i] = i;
    }
    DSU(B, groups);
    DSU(C, groups);
    unordered_set<int> allUniqueGroups;
    int answer = 1;
    for(int i = 1 ; i < groups.size() ; i++){
        if(allUniqueGroups.count(groups[i]) == 0){
            answer *= 2;
        }
        allUniqueGroups.insert(groups[i]);
    }
    return answer;
}

int main(){
     vector<vector<int> > B = {
        {1, 5},
        {4, 6},
        {18, 3},
        {4, 5},
        {15, 9},
        {15, 4}
     };
     vector<vector<int> > C = {
        {13, 20},
        {7, 20},
        {8, 19},
        {13, 7},
        {13, 8},
        {2, 19}
     };

     int answer = solve(20, B, C);
     return 0;

}