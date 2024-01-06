#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<char> getCharacters(int digit){
     switch(digit){
          case '2':
               return vector<char> {'a', 'b', 'c'};
          case '3':
               return vector<char> {'d', 'e', 'f'};
          case '4':
               return vector<char> {'g', 'h', 'i'};
          case '5':
               return vector<char> {'j', 'k', 'l'};
          case '6':
               return vector<char> {'m', 'n', 'o'};
          case '7':
               return vector<char> {'p','q','r','s'};
          case '8':
               return vector<char> {'t','u', 'v'};
          case '9':
               return vector<char> {'w', 'x','y','z'};
          default:
               return vector<char> {};
     }
}

vector<string> letterCombinations(string digits) {
     vector<string> answer;
     vector<string> updatedAnswer;
     string empty = "";
     answer.push_back(empty);
     for(int i = digits.size() - 1; i >= 0; i--) {
          auto Characters = getCharacters(digits[i]- '0');
          for(string previous : answer){
               for(auto ch : Characters){
               updatedAnswer.push_back(ch + previous);
               }
          }
          answer.clear();
          answer = updatedAnswer;
          updatedAnswer.clear();
     }
     return answer;
}

int main(){
     string digits = "23";
     auto answer = letterCombinations(digits);
     return 0;
}