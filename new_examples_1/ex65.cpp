#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> solve(vector<int> &A) {
    priority_queue<int, vector<int>, greater<int> > myQueue;
    int product = 1;
    vector<int> answer;
    for(int i = 0 ; i < A.size() ; i++){
        if(i >= 2){
            if(i != 2 && A[i] > myQueue.top()){
                product = (product/ myQueue.top()) * A[i];
                myQueue.pop();
                myQueue.push(A[i]);
            }
            if(i == 2) product *= A[i];
            answer.push_back(product);
            continue;
        }
        myQueue.push(A[i]);
        product = product*A[i];
        answer.push_back(-1);
    }
    return answer;
}

int main(){
     vector<int> input = {1,2,3,4,5,6};
     auto answer = solve(input);
     return 0;
}