#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool compare(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0];
}

int solve(vector<vector<int> > &A) {
     sort(A.begin(), A.end(), compare);
     map<int, int> endTime;
     for(int i = 0 ; i < A.size() ; i++){
          if(endTime.size() == 0){
               endTime[A[i][1]]++;
          }
          else{
               auto it = endTime.upper_bound(A[i][0]);
               if(it != endTime.begin()){
                    --it;
                    if(it->second == 1) endTime.erase(it);
                    else it->second--;
               }
               endTime[A[i][1]]++;
          }
     }
     int answer = 0;
     for(auto it : endTime){
          answer += it.second;
     }
     return answer;
}


int main(){
     vector<vector<int> > input = {{0,14},{5,9},{6,25},{12,19},{13,19}};
     int answer = solve(input);
     return 0;
}