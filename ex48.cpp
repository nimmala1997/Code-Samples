#include<iostream>
#include<queue>
#include<string>
using namespace std;

string solve(string A) {
    unordered_map<char, int> myMap;
    queue<char> charQueue;
    string answer = string(1,A.at(0));
    myMap[A.at(0)]++;
    for(int i = 1 ; i < A.size() ; i++){
        char firstValue = charQueue.front();
        myMap[A.at(i)]++;
        while(!charQueue.empty() && (myMap[charQueue.front()] > 1 || A.at(i) == charQueue.front())){
            charQueue.pop();
        }
        charQueue.push(A.at(i));
        answer += !charQueue.empty() ? string(1, charQueue.front()) : "#";
    }
    return answer;
}

int main(){
   string s1 = "gu";
   string answer = solve(s1);
   return 0; 
}