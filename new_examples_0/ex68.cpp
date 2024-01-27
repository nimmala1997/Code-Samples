 #include<iostream>
 using namespace std;

 int rotsearch(int arr[],int n,int x){
    int s = 0,e = n-1;
    int mid;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid] == x)
         return mid;
        else
         if(arr[mid]< x){
            if(arr[e]< x)
             e = mid-1;
            else
             s = mid+1;
         }
         else
          if(arr[mid] > x){
            if(arr[s] > x)
             s = mid+1;
            else
             e = mid-1;
         }
         

    }
 }

 int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
       cin>>a[i];
    }
    int x1;
    cin>>x1;    
    int ans = rotsearch(a,n,x1);  
    cout<<ans;

return 0;                                                           
 }