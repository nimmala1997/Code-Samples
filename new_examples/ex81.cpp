#include<iostream>
using namespace std;

int final = 11; 
int guess(int pick);
int guessNumber(int n) {
        int s = 0;
        int e = n;
        while(s <= e){
            int mid = s + (e - s)/2;
            int ans = guess(mid);
            if(ans == 0)
                 return mid;
            else
                if(ans == -1)
                     e = mid;
                else
                     s = mid;
        }
         return -1;
    }
int guess(int pick){
if(pick == final)
 return 0;
 else 
  if(pick > final)
   return -1;
   else
    return 1;
}

int main(){
   //int n;
   //cin>>n;
   //cin>>final;
   int ans = guessNumber(25);
   cout<<ans;
   
return ans;

}
   