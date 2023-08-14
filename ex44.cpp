#include<iostream>
#include<string>
#include<stack>

using namespace std;

string solve(string A) {
    char removedChar = '-';
    stack<char> charStack;
    charStack.push('/');
    for(int i = 0; i < A.size() ; i++){
        if(A.at(i) != removedChar){
            if(removedChar == charStack.top()){
                charStack.pop();
                removedChar = A.at(i);
            }
            if(A.at(i) == charStack.top()){
                charStack.pop();
                removedChar = A.at(i);
                continue;
            }
            charStack.push(A.at(i));
        }
        else{
         removedChar = A.at(i);
        }
    }
    string answer;
    while(charStack.top() != '/'){
        answer.push_back(charStack.top());
        charStack.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main(){
   string A = "abba";
   string answer = solve(A);
   return 0;
}