#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int size;
	for(int x = 0 ;x < n;x++){
	    cin>>size;
	    int arr[size];
	    for(int y = 0;y<size;y++){
	        cin>>arr[y];
	    }
	   for(int y = (size-1) ;y >= 0; y--){
           cout<<arr[y]<<" ";
       }
       cout<<endl;
	}
	return 0;
}