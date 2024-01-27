 #include<iostream>
 #include<string>
 using namespace std;
 
 bool check(string s){
        int n = s.size();
        int mid = (n-1)/2;
        for(int i = 0 ; i <= mid ; i++){
            if(s[i] != s[n-1-i])
             return false;
        }
        return true;
    }

 bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        if(n == 1)
         return true;
        int i = 0, j = n-1;
        while(i <= j){
            if(a[i] != b[j]){
                if(check(a.substr(0,i)+b.substr(i)))
                 return true;
                 if(check(a.substr(0,j+1)+b.substr(j+1)))
                  return true;
            }
            i++;
            j--;
        }
         if(i >= j)
         return true;
        i = 0, j = n-1;
        while(i <= j){
            if(b[i] != a[j]){
                if(check(b.substr(0,i)+a.substr(i)))
                 return true;
                 if(check(b.substr(0,j+1)+a.substr(j+1)))
                  return true;
            }
            i++;
            j--;
        }
         if(i >= j)
         return true;
        return false;
}

int main(){
   string s1 = "xbdef";
   string s2 = "xecab";
   bool ans = checkPalindromeFormation(s1,s2);

 return 0;
}