#include<iostream>

using namespace std;

/*int partition(int a[],int s,int e){
    int x[100];
    int k = a[e];
    int i = s;
    int y = s;
    while(i <= e && y <= e){
        if(a[y] <= k){
         k[i] = a[y];
         i++;
        }
        y++;
    }
    int ans = i;
    while(i <= e && s <= e){
        if(a[y] > k){
         k[i] = a[s];
         i++;
        }
        s++;
    }
    
   

}*/
int partition(int a[],int s,int e){
    int i = 0;
    int k = s;
    while(k <= e){
        if(a[k] < a[e])
          i++;
        k++;
    }
    int p = s+i;
    int x = a[p];
    a[p] = a[e];
    a[e] = x;
    // x is temp var;
    x = s;
    int y = e;
    int temp;
    while(x <= p && y > p){
        if(a[x] < a[p] )
         x++;
        if(a[y] > a[p] )
         y--;
        //swapping
        if(a[x] > a[p] && a[y] < a[p]){
        temp = a[x];
        a[x]  = a[y];
        a[y] = temp;
        x++;
        y--;
        }
    }
    return p;

}

void quicksort(int a[],int s,int e){
    if(s >= e)
     return;
    int p = partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}
int main(){
    int a[] = {8,5,2,1,7,3,4};
    quicksort(a,0,6);
     for(int i = 0; i < 7;i++){
        cout<<a[i];
    }

}