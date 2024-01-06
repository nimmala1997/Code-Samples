#include<iostream>
#include<vector>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
     if(p1.first == p2.first) return p1.second < p2.second;
     return p1.first < p2.first;
}

int bestTeamScore(vector<int>& scores, vector<int>& ages) {
     vector<pair<int, int>> players;
     int n = scores.size();
     for (int i=0; i<n; i++) {
          players.push_back({ages[i], scores[i]});
     }
     sort(players.begin(), players.end(), compare);
     int answer = 0;
     vector<int> dp(n);
     for(int i = n-1 ; i >= 0 ; i--){
          dp[i] = players[i].second;
          for(int j = i+1 ; j < n ; j++){
               dp[i] += players[j].second > players[i].second ? dp[j] : 0;
          }
          answer = max(answer, dp[i]);
     }
     return answer;
}

int main(){
    vector<int> scores = {1,3,5,10,15};
    vector<int> ages = {1,2,3,4,5};
    auto answer = bestTeamScore(scores, ages);
    return 0;
}