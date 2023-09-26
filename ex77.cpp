#include<iostream>
#include<queue>
#include<set>
#include<map>
#include<vector>

using namespace std;

vector<int> solve(int A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E, vector<int> &F) {
    unordered_map<int, vector<int> > levelWiseNodes;
    for(int i = 0 ; i < B.size() ; i++){
        levelWiseNodes[B[i]].push_back(C[i]);
        levelWiseNodes[C[i]].push_back(B[i]);
    }
    vector<bool> isVisited(A+1, false);
    queue<int> levelQueues;
    levelQueues.push(1);
    levelQueues.push(-1);
    int level = 1;
    vector<set<int> > levelWise(A+1);
    levelWise[0].insert(D[0]);
    while(!levelQueues.empty()){
        int root = levelQueues.front();
        levelQueues.pop();
        if(root != -1){
            if(isVisited[root]) continue;
            isVisited[root] = true;
            for(int i = 0 ; i < levelWiseNodes[root].size() ; i++){
                if(isVisited[levelWiseNodes[root][i]]) continue;
                levelQueues.push(levelWiseNodes[root][i]);
                levelWise[level].insert(D[levelWiseNodes[root][i] - 1]);
            }
        }
        else{
            if(!levelQueues.empty()) levelQueues.push(-1);
            level++;
        }
    }
    level--;
    vector<int> answer;
    for(int i = 0 ; i < E.size() ; i++){
        int currentLevel = E[i] % level;
        auto minElement = levelWise[currentLevel].lower_bound(F[i]);
        if(minElement != levelWise[currentLevel].end()){
            answer.push_back(*minElement);
        }
        else answer.push_back(-1);
    }
    return answer;
}

int main(){
     int A = 3;
     vector<int> B = {1, 2};
     vector<int> C = {3, 1};
     vector<int> D = {7, 5 , 27};
     vector<int> E = {1,10,1};
     vector<int> F = {29,6,26};
     auto answr = solve(A , B , C, D , E , F);
}