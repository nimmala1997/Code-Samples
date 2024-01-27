#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<pair<int, int>, int> TripleIntPair;

class sortRows{
public:
    bool operator()(TripleIntPair pair1, TripleIntPair pair2){
        return pair1.second > pair2.second;
    }
};

int solve(vector<vector<int> > &A, int B) {
    priority_queue<TripleIntPair, vector<TripleIntPair>, sortRows> rowWiseMinQueue;
    for(int i = 0 ; i < A.size() ; i++){
        rowWiseMinQueue.push({{i,0}, A[i][0]});
    }
    while(!rowWiseMinQueue.empty() && B != 1){
        auto currentMinElement = rowWiseMinQueue.top();
        rowWiseMinQueue.pop();
        B--;
        int nextElement = currentMinElement.first.second + 1;
        if(nextElement < A[0].size()){
            rowWiseMinQueue.push({{currentMinElement.first.first, nextElement}, A[currentMinElement.first.first][nextElement]});
        }
    }
    return rowWiseMinQueue.top().second; 
}

int main(){
     vector<vector<int> > A = {{1, 3}, {4, 5}};
     int answer = solve(A, 4);
     return 0;
}