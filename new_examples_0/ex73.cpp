#include<iostream>
#include<vector>
using namespace std;

void roww(vector<vector<int> > &A,int i1,int i2,int n1,int n2){
    for(int i = 0;i < n2;i++){
      A.at(i1).at(i) = 2;
    }
}
void colum(vector<vector<int> > &A,int i1,int i2,int n1,int n2){
    for(int i = 0;i < n1;i++){
      A.at(i).at(i2) = 2;
    }
}

void solution(vector<vector<int> > &A){
int n1 = A.size();
int n2 = A[0].size();

for(int i1 = 0 ; i1 < n1 ; i1++){
    for(int i2 = 0; i2 < n2; i2++){
        if(A.at(i1).at(i2) == 0){
            roww(A,i1,i2,n1,n2);
            colum(A,i1,i2,n1,n2);
        }
    }
}
}

int main(){
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;
    vector<int> col(n2);
    vector<vector<int> > mat(n1,col);
    for(int i1 = 0 ; i1 < n1;i1++){
        for(int i2 = 0;i2 < n2;i2++){
            cin>>mat.at(i1).at(i2);
        }
    }
    solution(mat);
    for(int i1 = 0 ; i1 < n1;i1++){
        for(int i2 = 0;i2 < n2;i2++){
            if(mat.at(i1).at(i2) == 2)
              mat.at(i1).at(i2) = 0;
        }
    }
    for(int i1 = 0 ; i1 < n1;i1++){
        for(int i2 = 0;i2 < n2;i2++){
            cout<<mat.at(i1).at(i2);
        }
        cout<<endl;
    }


}