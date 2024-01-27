#include<iostream>
#include<vector>

using namespace std;

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
     vector<double> monsterTime;
     for(int i = 0; i < dist.size() ; i++){
          monsterTime.push_back(dist[i] * 1.00/speed[i]);
     }
     sort(monsterTime.begin(), monsterTime.end());
     reverse(monsterTime.begin(), monsterTime.end());
     int currentAvailable = 0, answer = 0;
     while(monsterTime.size() != 0){
          if(currentAvailable >= monsterTime.back()) break;
          currentAvailable++;
          answer++;
          monsterTime.pop_back();
     }
     return answer;
}

int main(){
     vector<int> dist = {3,3,5,7,7};
     vector<int> speed = {1,1,4,2,2};
     int answer = eliminateMaximum(dist, speed);
     return 0;
}