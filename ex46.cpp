#include<iostream>
#include<string>

using namespace std;

int solve(string A, string B) {
    if (A.size() != B.size()) return 0;
    unordered_map<char, char> myMap;
    for(int i = 0 ; i < A.size() ; i++){
        if(myMap.count(A.at(i)) > 0){
            A.at(i) = myMap[A.at(i)];
        }
        else{
            myMap[A.at(i)] = B.at(i);
            A.at(i) = B.at(i);
        }
    }
    cout<<A;
    return A == B;
}

int main(){
   string s1 = "cvv";
   string s2 = "xyx";
   int answer = solve(s1, s2);
   return 0;
}