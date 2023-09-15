#include<iostream>
#include<vector>

using namespace std;

bool isPossible(int possibleDays, vector<int> &bloomDay, int m , int k){
     int i = 0 , j = 0;
     int count = 0 ;
     while(j < bloomDay.size()){
          i = bloomDay[j] <= possibleDays ? 0 : j+1;
          if(j-i == k-1) {
               i = j+1;
               count++;
          }
          j++;
     }
     return count >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
     if(m*k > bloomDay.size()) return -1;
     int minimumDays = INT_MAX;
     int maximumDays = INT_MIN;
     for(int i = 0 ; i < bloomDay.size() ; i++){
          minimumDays = min(minimumDays, bloomDay[i]);
          maximumDays = max(maximumDays, bloomDay[i]);
     }
     int possibleDays, answer = INT_MAX;
     while(minimumDays <= maximumDays){
          possibleDays = minimumDays + (maximumDays-minimumDays)/2 ;
          if(isPossible(possibleDays, bloomDay, m , k)){
               answer = min(answer, possibleDays);
               maximumDays = possibleDays - 1;
          }
          else{
               minimumDays = possibleDays + 1;
          }
     }
     return answer;
}

int main(){
     vector<int> bloomDays = {1, 10, 3, 2, 10};
     int answer = minDays(bloomDays, 3, 1);
     return 0;
}