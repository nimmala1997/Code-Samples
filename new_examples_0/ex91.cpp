#include<iostream>
using namespace std;

template<typename T>
class stack{

 T *arr;
 int nextIndex;
 int size;

 public:
  stack(){
    arr = new T[4];
    nextIndex = 0;
    size = 4;
  }

  int noElements(){
   return nextIndex;
  }

  void push(T a){
   if(nextIndex == size){
      T* newarr = new T[2*size];
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

  T top(){
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
   stack<int> s1;
   s1.push(1);
   s1.push(2);
   s1.push(3);
   s1.push(4);
   s1.push(5);
   
  stack<char> s2;
   s2.push('a');
   s2.push('b');
   s2.push('c');
   s2.push('d');
   s2.push('e');

   while(!s1.isEmpty()){
    cout<<s1.top();
    s1.pop();
   }

    cout<<endl;

   while(!s2.isEmpty()){
    cout<<s2.top();
    s2.pop();
   }

 return 0;
}