#include<iostream>
using namespace std;

class Queue{
   int size;
   int index;
   int* arr;
   public:
    Queue(int i ){
      size = i;
      arr[i];
      index = 0;
    }
    void push(int a){
     if(index == size){
      cout<<"Queue is full";
      return ;
     }
       else{
         Q[index] = a;
          index++;
       }
    }
    int size(){
      return index;
    }
    void pop(){
      
      
    }
    bool isempty(){
      if(index == 0)
       return true;
       else
        return false;
    }
   int front(){
      if(isempty)
       return -1;
       else 
       return arr[0];
   }
};
int main(){
   Queue(5);
   for(int i = 0 ; i < Q.size() ; Q++ ){
      cout<<Q.front();
      Q.delete();
   }
}