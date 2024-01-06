#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class sortProfit{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
};

bool sortCars(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

int solve(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> allCars;
    for(int i = 0 ; i < A.size() ; i++){
        allCars.push_back({A[i], B[i]});
    }
    sort(allCars.begin(), allCars.end(), sortCars);
    priority_queue<pair<int, int>, vector<pair<int, int>>, sortProfit> minQueue;
    int answer = 0;
    int currentTime = 0;
    for(int i = 0 ; i < allCars.size() ; i++){
        if(currentTime < allCars[i].first){
            answer += allCars[i].second;
            minQueue.push(allCars[i]);
            currentTime++;
            continue;
        }
        if(allCars[i].first == currentTime && allCars[i].second > minQueue.top().second){
            answer -= minQueue.top().second - allCars[i].second;
            minQueue.pop();
            minQueue.push(allCars[i]);
        }
    }
    return answer;
}

int main(){
     vector<int> time = {1, 3, 2, 3, 3};
     vector<int> profit = {5, 6, 1, 3, 9};

     int answer = solve(time, profit);
     return 0;
}