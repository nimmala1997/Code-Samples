#include<iostream>
#include<vector>
#include<set>

using namespace std;

void createAdjacentList(vector<vector<int> > &adjList, const vector<vector<int> > &input){
    for(int i = 0 ; i < input.size() ; i++){
        adjList[input[i][0]].push_back(input[i][1]);
    }
}

bool dfs(vector<vector<int> > &adjList, int startNode, set<int> currentCycle, vector<bool> &isVisited){
    for(auto allNodes : adjList[startNode]){
        if(isVisited[allNodes]) continue;
        if(currentCycle.count(allNodes) > 0) return true;
        currentCycle.insert(allNodes);
        isVisited[allNodes] = true;
        if(dfs(adjList, allNodes, currentCycle, isVisited)) return true;
        currentCycle.erase(allNodes);
    }
    return false;
}

int solve(int A, vector<vector<int> > &B) {
    vector<vector<int> > adjList(A+1);
    createAdjacentList(adjList, B);
    set<int> currentCycle;
    vector<bool> isVisited(A+1, false);
    for(int i = 1 ; i < A+1; i++){
        currentCycle.insert(i);
        if(isVisited[i] == false && dfs(adjList, i, currentCycle, isVisited)){
            return true;
        }
        currentCycle.erase(i);
    }
    return false;
}

int main(){
     vector<vector<int>> result = {
        {1, 3},
        {2, 3},
        {3, 2}
    };
    bool answer = solve(3, result);
    return 0;
}