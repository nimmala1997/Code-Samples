#include <iostream>

using namespace std;
int ans(int n,int A[], int L[],int R[]){
    for(int i = 0 ; i < n;i++){
        if (L[i] < 0)
         A[R[i]-1] = -L[i];
        else
         if(L[i] <= R[i])
          for(int x = L[i];x<=R[i];x++){
              A[x-1] = A[x-1]*(L[i]+R[i]);
          }
    }
    int s = 0;
    for(int i = 0;i<n;i++){
      s = s+A[i];
    }
    return s%(1000000000+7);

}
int main(){
    int n;
    cin>>n;
    int A[n];
    int L[n];
    int R[n];
    for(int i = 0; i < n;i++)
     cin>>A[i];
    for(int i = 0; i < n;i++)
     cin>>L[i];
    for(int i = 0; i < n;i++)
     cin>>R[i];

    int a = ans(n,A,L,R);
    cout<<a;

return 0;
}