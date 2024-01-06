#include<iostream>
#include<vector>
#include<map>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
     int totalSize = 0;
     for(int i = 0 ; i < wall[0].size() ; i++){
          totalSize += wall[0][i];
     }
     unordered_map<int, int> everyBrick;
     for(int i = 0 ; i < wall.size() ; i++){
          int currentWall = 1, currentBrick = 0;
          int j = 0;
          while(currentWall < totalSize){
               currentBrick +=  currentBrick < currentWall && j < wall[0].size() ? wall[i][j++] : 0;
               everyBrick[currentWall] += currentBrick != currentWall ? 1 : 0;
               currentWall++;
          }
     }
     int answer = INT_MIN;
     for(auto it : everyBrick){
          answer = min(answer, it.second);
     }
     return answer != INT_MIN ? answer : wall.size();  
}

int main(){
     vector<vector<int> > input = {
        {1, 2, 2, 1},
        {3, 1, 2},
        {1, 3, 2},
        {2, 4},
        {3, 1, 2},
        {1, 3, 1, 1}
    };
    int answer = leastBricks(input);
    return 0;
}