#include<iostream>
#include<string>
#include<set>
using namespace std;

int findNearestIndex(set<int> nearestOnes, set<int> ::iterator it, int index){
    if(it == nearestOnes.end()) return *prev(it);
    if(it != nearestOnes.end() && abs(index - *it) < abs(index - *prev(it))){
        cout<<"  "<<endl;
        return *it;
    }
    else return *prev(it);
}

vector<int> solve(string A, vector<vector<int> > &B) {
    set<int> nearestOnes;
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == '1') nearestOnes.insert(i);
    }
    vector<int> answer;
    for(int i = 0 ; i < B.size() ; i++){
        if(B[i][0] == 1){
            int index = B[i][1] - 1;
            if(A[index] == '1'){
                nearestOnes.erase(index);
                A[index] = '0';
            }
            else{
                nearestOnes.insert(index);
                A[index] = '1';
            }
        }
        else{
            int index = B[i][1] - 1;
            auto nearestIndex = nearestOnes.lower_bound(index);
            if(nearestIndex != nearestOnes.begin()){
                int nearestOneIndex = findNearestIndex(nearestOnes, nearestIndex, index);
                answer.push_back(nearestOneIndex+1);
            }
            else{
                answer.push_back(*nearestIndex+1);
            }
        }
    }
    return answer;
}

int main() {
     string s1 = "100000";
     vector<vector<int> > input = {{2, 3}, {1,4}};
     auto answer = solve(s1, input);
     return 0;
}