#include<iostream>
using namespace std;

class PriorityQueue{
    
         vector<int> pq;

         public:
         PriorityQueue() { }

         bool isEmpty() {
            return pq.size() == 0;
         }

         void insert(int element) {
            pq.push_back(element);
            
            int childIndex = pq.size() -1;
            while(childIndex > 0){
               int parentIndex = (childIndex-1)/2 ;
               if(pq.at(parentIndex) > pq.at(childIndex)){
                  swap(pq.at(parentIndex), pq.at(childIndex));
                  childIndex = parentIndex;
               } 
               else break;
            }
         }

         void removeMin() {
               if(pq.size() == 0) return ;
               swap(pq.at(0), pq.at(getSize()-1));
               pq.pop_back();
               int size = getSize();
               int parentIndex = 0;
               while(true){
                  int child1 = 2*parentIndex + 1;
                  int child2 = 2*parentIndex + 2;
                  int minIndex = parentIndex;
                  if(child1 < size && pq.at(child1) < pq.at(minIndex))
                     minIndex = child1;
                  if(child2 < size && pq.at(child2) < pq.at(minIndex))
                     minIndex = child2;
                  if(minIndex != parentIndex){
                     swap(pq.at(minIndex) , pq.at(parentIndex));
                     parentIndex = minIndex;
                  }
                  else break;
               }
         }

         int getMin() {
            if(isEmpty()) return 0;
            return pq.at(0);
         }

         int getSize() {
            return pq.size();
         }

};

int main()  {

   PriorityQueue pq1;
   pq1.insert(12);
   pq1.insert(10);
   pq1.insert(22);
   pq1.insert(34);
   pq1.insert(4);
   pq1.insert(9);
   
   while(!pq1.isEmpty()){
      cout<<pq1.getMin()<<" ";
      pq1.removeMin();
   }
   return 0;

}