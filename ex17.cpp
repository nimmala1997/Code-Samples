#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > matrixSum(vector<vector<int> > matrix){
                                vector<vector<int> > answer;
                                for(int i = 0 ; i < matrix.size();i++){
                                    vector<int> oneD;
                                    int temp = 0;
                                    for(int j = 0 ; j < matrix[0].size() ;j++){
                                        temp += matrix[i][j];
                                        oneD.push_back(temp);
                                    }
                                    answer.push_back(oneD);
                                    oneD.clear();
                                }
                                for(int j = 0 ; j < matrix[0].size(); j++){
                                    for(int i = 1 ; i < matrix.size(); i++){
                                        answer.at(i).at(j) += answer.at(i-1).at(j);
                                    }
                               }
                                return answer;
}
int subMatrixSum(int a1, int b1 , int a2, int b2, vector<vector<int> > prefixSum){
                                if(a1 == 0 && b1 == 0){ return prefixSum[a2][b2];}
                                if(a1 == 0) {return prefixSum[a2][b2]-prefixSum[a2][b1-1];}
                                if(b1 == 0) {return prefixSum[a2][b2]-prefixSum[a1-1][b2];}
                                return prefixSum[a2][b2]+prefixSum[a1-1][b1-1]-prefixSum[a1-1][b2]-prefixSum[a2][b1-1];
}
vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
                                vector<vector<int> >prefixSum = matrixSum(A);
                                vector<int> queriesSum;
                                for(int i = 0 ; i < B.size() ;i++){
                                    int a1 = B.at(i)-1, b1 = C.at(i)-1;
                                    int a2 = D.at(i)-1, b2 = E.at(i)-1;
                                    queriesSum.push_back(subMatrixSum(a1, b1, a2, b2, prefixSum));
                                }
                                return queriesSum;
}
int main(){
                                 vector<int> oneD(1,1);
                                 vector<vector<int> > matrix(1,oneD);
                                 vector<int> B(1,1), C(1,1), D(1,1), E(1,1);
                                 vector<int> answer = solve(matrix, B, C, D, E);
                                 for(int i = 0 ; i < answer.size() ; i++)
                                    cout<<answer.at(i);
                                 return 0;
}