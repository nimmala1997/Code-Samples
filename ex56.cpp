#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std ;

class carsTimeComparator {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

bool compareVector(pair<int, int>p1, pair<int, int>p2){
    return p1.first < p2.first;
}

int solve(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> allCars;
    for(int i = 0 ; i < A.size() ; i++) {
        pair<int, int> carTime;
        carTime.first = A.at(i);
        carTime.second = B.at(i);
        allCars.push_back(carTime);
    }
    sort(allCars.begin(), allCars.end(), compareVector);
    priority_queue<pair<int,int>, vector<pair<int, int>>, carsTimeComparator > minQueue;
    int maximumSum = 0, currentTime = 1 ;
    for(int i = 0 ; i < allCars.size() ; i++) {
        if(allCars[i].first <= currentTime) {
            maximumSum += allCars[i].second;
            currentTime++;
            minQueue.push(allCars[i]);
            continue;
        }
        if(allCars[i].first == currentTime-1 && minQueue.top().second < allCars[i].second) {
            maximumSum -= minQueue.top().second;
            minQueue.pop();
            maximumSum += allCars[i].second;
            minQueue.push(allCars[i]);
            currentTime++;
        }
    }
    return maximumSum;
}

int main() {
     vector<int> A = {1,3,2,3,3};
     vector<int> B  = {5,6,1,3,9};
     int answer = solve(A, B);
     return 0 ;
}