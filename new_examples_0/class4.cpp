#include<iostream>
using namespace std;

class DynamicArray{
    int *arr;
    int nextindex;
    int capacity;

public:
  DynamicArray(){
      arr = new int[5];
      nextindex = 0;
      capacity = 5;
  }
  void add(int n){
      if(nextindex == capacity){
          int *arr1 = new int[2*capacity];
          for(int x = 0; x < capacity; x++){
              arr1[x] = arr[x];
          }
          delete []arr;
          capacity = 2*capacity;
          arr = arr1;
      }
      arr[nextindex] = n;
      nextindex++;
  }
  void display(){
      for
  }
};
int main(){

 return 0;
}