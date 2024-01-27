#include<iostream>
#include<vector>

using namespace std;

void updateCurrentStack(vector<int> &currentStack, int negativeValue){
     if(currentStack.size() == 0 || currentStack.back() < 0) {
          currentStack.push_back(negativeValue);
          return;
     }
     while(currentStack.size() > 0 && currentStack.back() < abs(negativeValue)){
          currentStack.pop_back();
     }
     if(currentStack.size() == 0 || currentStack.back() < 0) {
          currentStack.push_back(negativeValue);
          return;
     }
     if(currentStack.back() == abs(negativeValue)) currentStack.pop_back();
}

vector<int> asteroidCollision(vector<int>& asteroids) {
     vector<int> currentStack;
     for(int i = 0 ; i < asteroids.size() ; i++){
          if(asteroids[i] > 0){
               currentStack.push_back(asteroids[i]);
          }
          else{
               updateCurrentStack(currentStack, asteroids[i]);
          }
     }
     return currentStack;
}

int main(){
     vector<int> input = {-2, -2, 1, -2};
     auto answer = asteroidCollision(input);
     return 0;
}