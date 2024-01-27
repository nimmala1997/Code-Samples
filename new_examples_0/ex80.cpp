#include<iostream>
#include<string>

using namespace std;

string addBinary(string a, string b) {
         int n1 = a.size()-1;
         int n2 = b.size()-1;
         int c = 0;//carry
         string sum;
         int m,n,k;
         while(n1>=0 || n2 >= 0 ){
             if(a[n1] == '1') 
              m = 1;
              else
               m =  0;
             if(b[n2] == '1') 
              n = 1;
              else
               n = 0;
             k =  m+n+c;
             if(k == 3){
                 sum.push_back('1');
                 c = 1;
             }
             else
              if(k == 2){
                 sum.push_back('0');
                 c = 1;
                }
                else
                 if(k == 1){
                    sum.push_back('1');
                    c = 0;
                }
                else{
                    sum.push_back('0');
                    c = 0;
                }
                n1--;
                n2--;
         }
         while(n1>=0){
             if(a[n1] == '1') 
              m = 1;
              else
               m =  0;
                k =  m+c;
            if(k == 3){
                 sum.push_back('1');
                 c = 1;
             }
             else
              if(k == 2){
                 sum.push_back('0');
                 c = 1;
                }
                else
                 if(k == 1){
                    sum.push_back('1');
                    c = 0;
                }
                else{
                    sum.push_back('0');
                    c = 0;
                }
                n1--;
        }        
         while(n2>=0){
             if(b[n2] == '1') 
              m = 1;
              else
               m =  0;
              k =  m+c;
            if(k == 3){
                 sum.push_back('1');
                 c = 1;
             }
             else
              if(k == 2){
                 sum.push_back('0');
                 c = 1;
                }
                else
                 if(k == 1){
                    sum.push_back('1');
                    c = 0;
                }
                else{
                    sum.push_back('0');
                    c = 0;
                }
                n2--;
         }
         if(c == 1)
          sum.push_back('1');
          return sum;

    }

    int main (){
      string s1 = "111";
      string s2 = "10";
      string s3 = addBinary(s1,s2);
      cout<<s3;
    }