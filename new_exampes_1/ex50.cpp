#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{

   vector<int> pqueue;
   
   void updatePriority(){
      int childIndex = pqueue.size() - 1;
      int parentIndex = (childIndex - 1)/ 2;
      while(pqueue[parentIndex] > pqueue[childIndex]){
         swap(pqueue[parentIndex],pqueue[childIndex]);
         childIndex = parentIndex;
         parentIndex = (childIndex - 1)/2;
      }
   }

   void updateFromTop(){
      if(isEmpty()) return;
      int parentIndex = 0;
      int childIndex1 = 2*parentIndex + 1;
      int childValue1 = childIndex1 < pqueue.size() ? pqueue.at(childIndex1) : INT_MAX ;
      int childValue2 = childIndex1 + 1 < pqueue.size() ? pqueue.at(childIndex1 + 1) : INT_MAX ;
      while (pqueue.at(parentIndex) > childValue1 || pqueue.at(parentIndex) > childValue2)
      {
         if(childValue1 > childValue2){
            swap(pqueue.at(parentIndex), pqueue.at(childIndex1+1));
            parentIndex = childIndex1+1;
         }
         else{
            swap(pqueue.at(parentIndex), pqueue.at(childIndex1));
            parentIndex = childIndex1;
         }
         childIndex1 = 2*parentIndex + 1;
         childValue1 = childIndex1 < pqueue.size() ? pqueue.at(childIndex1) : INT_MAX ;
         childValue2 = childIndex1 + 1 < pqueue.size() ? pqueue.at(childIndex1 + 1) : INT_MAX ;
      } 
   }

   public:
   
   void insert(int value){
      pqueue.push_back(value);
      updatePriority();
   }

   void removeMin(){
      if(isEmpty()) return;
      int lastElement = pqueue.size()-1;
      swap(pqueue.at(0), pqueue.at(lastElement));
      pqueue.pop_back();
      updateFromTop();
   }
   
   void printAllValues(){
      for(int i = 0 ; i < pqueue.size() ; i++){
         cout<<pqueue.at(i)<<",";
      }
      cout<<endl;
   }

   int getMin(){
      return pqueue.empty() ? -1 : pqueue[0];
   }

   bool isEmpty(){
      return pqueue.empty();
   }

   int getSize(){
      return pqueue.size();
   }

};

int main(){
   PriorityQueue p1;
   p1.insert(5);
   p1.insert(4);
   p1.insert(3);
   p1.printAllValues();
   p1.insert(2);
   p1.printAllValues();
   p1.insert(1);
   p1.printAllValues();
   p1.removeMin();
   p1.printAllValues();
   p1.removeMin();
   p1.printAllValues();
   return 0;
}