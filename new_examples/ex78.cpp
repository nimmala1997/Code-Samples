 #include<iostream>
 #include<vector>
 using namespace std;


int binarySearch(vector<int> arr, int s,int e){
        int mid ;
        while(s <= e){ 
         cout<<"while";
            mid = s + (e-s)/2;
            cout<<mid;
           if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
               return mid;
               cout<<mid;
            if(arr[mid]>arr[mid+1])
               e = mid;
            if(arr[mid]<arr[mid+1])
               s = mid;
        }
        return -1;
    }

 int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size(); 
        int ans = binarySearch(arr,0,n-1);
        return ans;
    }
int main(){
      int n, a ;
      //cin>>n;
      vector<int> vect;
      vect.push_back(0);
      vect.push_back(1);
      vect.push_back(0);
      
      int ans = peakIndexInMountainArray(vect);
      cout<<ans;

   return 0;
}