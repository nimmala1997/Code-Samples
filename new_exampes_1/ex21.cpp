#include<iostream>
using namespace std;
void arrangeArray(vector<int> &A){
                int size = A.size();
                for(int i = 0 ; i < size ; i++)
                    A.at(i) *= size;
                for(int i = 0  ; i < size ;  i++){
                    A.at(i) += A.at((A.at(i)/size))/size;
                }
                for(int i = 0  ; i < size ; i++)
                    A.at(i) = A.at(i)%size;
}
int main(){
                int arr[] = {1,2,0};
                vector<int> answer;
                for(int i = 0 ; i < 3 ; i++)
                    answer.push_back(arr[i]);
                arrangeArray(answer);
                return 0;
}