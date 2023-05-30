#include<iostream>
#include<algorithm>
using namespace std;

void mergearr(int x[],int y[],int s,int mid,int e){
    if(s == e||s > e)
     return;
    int z = mid+1;
    int a;
    while(s == e||s > e){
      if(x[s]>y[z]){

       a = x[s];
       x[s] = y[z];
       y[z] = a;

       s++;
      }
      else
       z++;
    }
    
    
    
}

void mergeso(int arr[],int s,int e){
    if(s==e||s>e)
      return;
    int m = (s+e)/2;
    mergeso(arr,s,m);
    mergeso((arr+m+1),(m+1),e);
    mergearr(arr,(arr+m+1),s,m,e);

}

int main(){
    int arr[] = {5,3,1,4,2,6};
    //int size = 6;
    mergeso(arr,0,5);
    for (int i = 0; i < 6; i++)
    {
      cout<<arr[i];
    }
    

return 0;
}
