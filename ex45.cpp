#include<iostream>
#include<string>

using namespace std;

bool compare(unordered_map<char,int> myMapA, unordered_map<char,int> myMapB){
    for(auto it : myMapA){
        if(myMapB[it.first] != it.second)
            return false;
    }
    return true;
}

int solve(string A, string B) {
    unordered_map<char,int> myMapA,myMapB;
    for(int i = 0 ; i < A.size() ; i++){
        myMapA[A.at(i)]++;
    }
    int i = 0, aSize = A.size() - 1;
    int count = 0;
    for(int j = 0 ; j < B.size() ; j++){
        if(j >= aSize){
            if(j > aSize){
                myMapB[B.at(i)]--;
                myMapB[B.at(j)]++;
                i++;
                count += compare(myMapA,myMapB) ? 1 : 0 ;
            }
            else{
                myMapB[B.at(j)]++;
                count += compare(myMapA,myMapB) ? 1 : 0 ;
            }
        }
        else{
            myMapB[B.at(j)]++;
        }
    }
    return count;
}

int main(){
   string s1 = "pccdpeeooadeocdoacddapacaecb" ;
   string s2 = "p";
   int answer = solve(s2, s1);
   return 0;
}