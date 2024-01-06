#include<iostream>
#include<string>
using namespace std;

vector<int> flip(string A) {
                vector<int> answer;
                int maxCount = 0,flag = 0,tempCount = 0,startIndex;
                for(int i = 0 ; i < A.size() ; i++){
                        if(A.at(i) == '0' && flag == 0){
                            flag = 1;
                            answer.push_back(i);
                            answer.push_back(i);
                            startIndex = i;
                            tempCount++;
                            maxCount++;
                        }
                        else{
                            if(flag == 1){
                                if(A.at(i) == '0') tempCount++;
                                if(A.at(i) == '1') tempCount--;
                            }
                            cout<<tempCount<<"-";
                            if (flag == 1 && tempCount == 1) startIndex = i;
                            if (flag == 1 && tempCount > maxCount) {

                                answer.at(0) = startIndex;
                                answer.at(1) = i;
                                maxCount = tempCount;
                            }
                        }
                }
                return answer;
}

int main(){
                string s1 = "110011";
                vector<int> answer = flip(s1);
}
