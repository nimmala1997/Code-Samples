#include<iostream>

using namespace std;
void mergearr(int x[],int y[],int a[],int s,int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    while( i <= mid && j <= e ){
        if(x[i] < y[j]){
            a[k] = x[i];
            k++;
            i++;
        }
        else
         if(x[i] > y[j]){
             a[k] = y[j];
             k++;
             j++;
         }
    }
    while(j <= e){
            a[k] = y[j];
            k++;
            j++;
        }
     while (i <= mid)
     {
         a[k] = x[i];
         k++;
         i++;
     }
     
}

void sortarr(int a[],int s,int e){
    if(s>=e)
     return;
    int mid = (s+e)/2;
    int x[100],y[100];
    for(int i = 0 ; i <= mid ; i++){
         x[i] = a[i];
    }
    for(int i = mid+1 ; i <= e ; i++){
        y[i] = a[i];
    }
    sortarr(x,s,mid);
    sortarr(y,mid+1,e);
    mergearr(x,y,a,s,e);

}
int main(){
    int a[] = {1,3,4,5,2,6};
    sortarr(a,0,5);
    //cout<<"hi";
return 0;
}