#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class CompareAvailableTasks{
public:
    bool operator()(vector<int> v1, vector<int> v2){
        return v1[1] > v2[1];
    }
};

class CompareRemainingTasks{
public:
    bool operator()(vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] > v2[0];
    }
};


vector<int> getOrder(vector<vector<int>>& tasks) {
     priority_queue<vector<int> , vector<vector<int>> ,CompareAvailableTasks> availableTasks;
     priority_queue<vector<int>, vector<vector<int>> , CompareRemainingTasks> remainingTasks;
     vector<int> answer;
     int currentTime = 1;
     for(int i = 0 ; i < tasks.size() ; i++){
          tasks[i].push_back(i);
          remainingTasks.push(tasks[i]);
     }
     availableTasks.push(remainingTasks.top());
     remainingTasks.pop();
     while(!availableTasks.empty()){
          answer.push_back(availableTasks.top()[2]);
          currentTime = max(currentTime, availableTasks.top()[0]);
          currentTime += availableTasks.top()[1];
          availableTasks.pop();
          if(availableTasks.empty() && !remainingTasks.empty() && remainingTasks.top()[0] > currentTime){
               availableTasks.push(remainingTasks.top());
               remainingTasks.pop();
               continue;
          }
          while(!remainingTasks.empty() && currentTime >= remainingTasks.top()[0]){
               availableTasks.push(remainingTasks.top());
               remainingTasks.pop();
          }
     }
     return answer;
}

int main(){
     vector<vector<int> > input = {
        {19, 13}, {16, 9}, {21, 10}, {32, 25}, {37, 4}, {49, 24}, {2, 15},
        {38, 41}, {37, 34}, {33, 6}, {45, 4}, {18, 18}, {46, 39}, {12, 24}
    };
    auto answer = getOrder(input);
    return 0;
}