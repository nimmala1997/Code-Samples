#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> dup ;
        vector<int> dup1 = {-1};
        for(int x = 0 ; x < n ; x++){
            for(int y = x+1; y < n; y++){
                if(arr[x] == arr[y])
                 dup.push_back(arr[x]);
                 
            }
        }
        if(dup.size()>0)
         return dup;
        else
         return dup1;
    }
};


// { Driver Code Starts.
int main() {
    //int t;
    //cin >> t;
    //while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    return 0;
}
  // } Driver Code Ends