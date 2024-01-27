#include<iostream>
#include<string>
using namespace std;

bool halvesAreAlike(string s) {
        int mid = s.size()/2;
        int count1 = 0,count2 = 0;
        for(int i = 0 ; i < mid; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'|| s[i] == 'A'|| s[i] == 'E'|| s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U' ){
                count1++;
            }
             if(s[i+mid] == 'a' || s[mid+i] == 'e' || s[i+mid] == 'i'|| s[i+mid] == 'o'|| s[i+mid] == 'u'|| s[i+mid] == 'A'|| s[i+mid] == 'E'|| s[i+mid] == 'I'|| s[i+mid] == 'O'|| s[i+mid] == 'U' ){
                count2++;
            }
        }
        return count1==count2;
}
int main(){
   string s1 = "book";
   bool ans = halvesAreAlike(s1);

 return 0;
}