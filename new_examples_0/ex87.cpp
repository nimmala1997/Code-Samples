#include<iostream>

using namespace std;

class stack{

 int *arr;
 int nextIndex;
 int size;

 public:
  stack(){
    arr = new int[4];
    nextIndex = 0;
    size = 4;
  }

  int noElements(){
   return nextIndex;
  }

  void push(int a){
   if(nextIndex == size){
      int* newarr = new int[2*size];
      for(int i = 0; i < size ;i ++){
         newarr[i] = arr[i];
      }
      size = 2*size;
      delete[] arr;
      arr = newarr;
   }
    arr[nextIndex] = a;
    nextIndex++;
  }

  void pop(){
   if(isEmpty()){
      cout<<"Stack is empty";
      return ;
   }
   nextIndex--;
  }

  int top(){
   if(isEmpty()){
      cout<<"Stack is empty";
      return -1;
   }
   return arr[nextIndex-1];
  }

  bool isEmpty(){
   if(nextIndex == 0)
    return true;
    else
     return false;
  }

};

int main(){
   stack s1;
   s1.push(1);
   s1.push(2);
   s1.push(3);
   s1.push(4);
   s1.push(5);
   
  
   while(!s1.isEmpty()){
    cout<<s1.top();
    s1.pop();
   }

 return 0;
}