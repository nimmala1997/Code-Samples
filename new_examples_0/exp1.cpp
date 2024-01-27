#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x,e,f,z;
    for( x = 0 ; x < n ; x++)
    {
        cin>>e>>f;
        int arr[e] ;
        for(int y=0;y < e;y++)
        {
              cin>>arr[y];
        }
    
    
        for( z = f ; z != f - 1 ; z++)
        {
         if(z == e )
         {
             z = 0;
         }
         cout<<arr[z];
        
        }
        cout<< arr[z]<<endl;
    }

return 0;
    
}