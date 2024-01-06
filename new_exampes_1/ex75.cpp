#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int solve(int A, vector<vector<int> > &B, int C, int D) {
    vector<int> answer(2*A , INT_MAX);
    answer[C] = 0;
    vector<bool> isVisted(2*A, false);
    int dummyNode = A;
    unordered_map<int, vector<int> > graph;
    for(int i = 0 ; i < B.size() ; i++){
        if(B[i][2] == 1){
            graph[B[i][0]].push_back(B[i][1]);
            graph[B[i][1]].push_back(B[i][0]);
        }
        else{
            graph[B[i][0]].push_back(dummyNode);
            graph[dummyNode].push_back(B[i][0]);
            graph[dummyNode].push_back(B[i][1]);
            graph[B[i][1]].push_back(dummyNode);
            dummyNode++;
        }
    }
    
    queue<int> bfs;
    bfs.push(C);
    while(!bfs.empty()){
        int front = bfs.front();
        bfs.pop();
        if(isVisted[front]) continue;
        isVisted[front] = true;
        int currentWeight = answer[front];
        for(int i = 0 ; i < graph[front].size() ; i++){
            int childNode = graph[front][i];
            if(currentWeight + 1 < answer[childNode]) answer[childNode] = 1 + currentWeight;
            if(isVisted[childNode] == false) bfs.push(childNode);
        }
    }
    return answer[D] != INT_MAX ? answer[D] : -1;
}

int main(){
     vector<vector<int> > input = {
        {2, 5, 1},
        {1, 3, 1},
        {0, 5, 2},
        {0, 2, 2},
        {1, 4, 1},
        {0, 1, 1}
    };
    auto answer = solve(6, input, 3,2);
}