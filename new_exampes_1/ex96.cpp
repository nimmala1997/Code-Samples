#include<iostream>
#include<string>
#include<stack>

using namespace std;

void updateResponse(string& response, string& encodedString, int currentK) {
     while (currentK > 0) {
          response += encodedString;
          currentK--;
     }
}

void updateStack(stack<string> &st){
     string encodedString = "";
     while(st.top() != "["){
          encodedString = st.top() + encodedString;
          st.pop();
     }
     st.pop();
     int currentK = stoi(st.top());
     st.pop();
     string updatedString = "";
     updateResponse(updatedString, encodedString, currentK);
     st.push(updatedString);
}

string decodeString(string s) {
     string emptyString, response = "";
     stack<string> st;
     for (int i = 0; i < s.size(); i++) {
          if(s[i] != ']'){
               st.push(emptyString+s[i]);

          }
          else updateStack(st);
     }
     if(st.size() == 1) return st.top(); 
     while(!st.empty()){
          response = st.top() + response;
          st.pop();
     }
     return response;
}

int main(){
     string input = "2[abc]3[cd]ef";
     string answer = decodeString(input);
     return 0;
}