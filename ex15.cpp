#include<iostream>
#include<vector>
using namespace std;
void remainingElements(string s,string &answer,int &carry){
                  int sum = 0;
                  int sizeofS = s.size()-1;

                  while(sizeofS >= 0){
                     int value = s.at(sizeofS) - '0';
                     sum = value+carry;
                     
                     switch (sum){
                     case 0:
                        carry = 0;
                        answer.push_back('0');
                        break;
                     case 1:
                        carry = 0;
                        answer.push_back('1');
                        break;
                     case 2:
                        carry = 1;
                        answer.push_back('0');
                        break;
                     }

                     sizeofS--;
                     s.pop_back();
                  }

}
string addTwoBinaryStrings(string s1,string s2){
                  int sizeofS1 = s1.size()-1;
                  int sizeofS2 = s2.size()-1;
                  int sum,carry = 0;
                  string answer;

                  while(sizeofS1 >= 0 && sizeofS2 >= 0){
                     int firstValue = s1.at(sizeofS1) - '0';
                     int secondValue = s2.at(sizeofS2) - '0';

                     sum = firstValue + secondValue + carry ; 
                     
                     switch (sum){
                     case 0:
                        carry = 0;
                        answer.push_back('0');
                        break;
                     case 1:
                        carry = 0;
                        answer.push_back('1');
                        break;
                     case 2:
                        carry = 1;
                        answer.push_back('0');
                        break;
                     case 3:
                        carry = 1;
                        answer.push_back('1');
                        break;
                     }

                     sizeofS1--;
                     sizeofS2--;
                     s1.pop_back();
                     s2.pop_back();
                  }

                  if(sizeofS1 >= 0 || sizeofS2 >= 0){
                     if(sizeofS1 >= 0) remainingElements(s1,answer,carry);
                     if(sizeofS2 >= 0) remainingElements(s2,answer,carry);
                  }

                  if(carry != 0)
                     answer.push_back('1');

                  reverse(answer.begin(),answer.end());
                  return answer;
}

int main(){
                  string s1 = "100";
                  string s2 = "1111";

                  string answer = addTwoBinaryStrings(s1,s2);
                  cout<<answer;

                  return 0;
}