#include<iostream>
using namespace std;

class Node{
 
  public: 
    int val;
     Node* next;
     Node(int val){
     this->val = val;
     next = NULL;
    }
};

class stack{

   Node* head;
   int size;

 public:
   stack(int val){
    Node* temp = new Node(val);
    size = 1;
    temp->next = head;
    head = temp;
  }

  int noElements(){
   return size;
  }

  void push(int val){
    Node* temp = new Node(val);
    size++;
    temp->next = head;
    head = temp;
  }

  void pop(){
   if(isEmpty()){
      cout<<"Stack is empty";
      return ;
   }
   Node* temp = head;
   head = head->next;
   delete temp;
   size--;
  }

  int top(){
   if(isEmpty()){
      cout<<"Stack is empty";
      return -1;
   }
   return head->val;
  }

  bool isEmpty(){
   if(size == 0)
    return true;
    else
     return false;
  }

};

int main(){
   stack s1(0);
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