#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> solve(int A, vector<vector<int> > &B) {
    vector<int> inDegree(A+1, 0);
    vector<vector<int> > graph(A+1);
    for(int i = 0 ; i < B.size() ; i++){
        graph[B[i][0]].push_back(B[i][1]);
        inDegree[B[i][1]]++;
    }
    queue<int> nodesQueue;
    vector<int> answer;
    for(int i = 1 ; i <= A ; i++){
        if(inDegree[i] == 0){
            nodesQueue.push(i);
            answer.push_back(i);
        }
        sort(graph[i].begin(), graph[i].end());
    }
    while(!nodesQueue.empty()){
        int currentNode = nodesQueue.front();
        nodesQueue.pop();
        for(auto subNode : graph[currentNode]){
            inDegree[subNode]--;
            if(inDegree[subNode] == 0) nodesQueue.push(subNode);
        }
    }
    for(int i = 1 ; i <= A ; i++){
        if(inDegree[i] != 0){
            answer.clear();
            return answer;
        }
    }
    return answer;
}

int main(){
     vector<vector<int> > input = {
        {6, 3},
        {6, 1},
        {5, 1},
        {5, 2},
        {3, 4},
        {4, 2}
    };
    auto answer = solve(6, input);
    return 0;
}