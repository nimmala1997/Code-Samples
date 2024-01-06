#include<iostream>
#include<string>
#include<map>

using namespace std;

void printAll(string &input, int index, string &answer, vector<bool> &isVisited) {
     if(index == input.size()){
          cout<<answer<<endl;
          return;
     }
     vector<bool> isVisitedIndex(26, false);
     for(int i = 0 ; i < input.size() ; i++) {
          char current = input.at(i);
          int currentIndex = current - 97;
          if (isVisited[i] == false && isVisitedIndex[currentIndex] == 0) {
               isVisited[i] = true;
               isVisitedIndex[currentIndex] = true;
               answer[index] = current;
               printAll(input, index+1, answer, isVisited);
               isVisited[i] = false; 
          }
     }
}
int main() {
     string input = "aba";
     vector<bool> isVisited(input.size(), false);
     string answer = "aba";
     printAll(input, 0, answer, isVisited);
     return 0;
}