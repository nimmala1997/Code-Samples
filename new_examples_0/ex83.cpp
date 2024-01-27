#include<iostream>
using namespace std;
class Node{

   public:

   int value;
   Node* next;

   Node(){}

   Node(int value){
      this->value = value;
      next = NULL;
   }

};

Node* input(){
   int value;
   cin>>value;
   Node * temp;
   Node* prev = NULL;
   Node* head;
   while(value != -1){
      temp = new Node(value);
       if(prev == NULL){
         head = temp;
         prev = temp;
       }
       else{
         prev->next = temp;
         prev = temp;
      
       }
       cin>>value;
   }
   return head;
}
Node* input2(){
   int value;
   cin>>value;
   Node* Head = NULL; 
   Node* temp;
   while(value != -1){
      temp = new Node(value);
      if(Head == NULL){
         Head = temp;
      }
      else{
         temp->next = Head;
         Head = temp;
      }
      cin>>value;
   }
   return Head;

}

void print(Node* n1){
   Node* temp  = n1;
   while(temp != NULL){
   cout<<temp->value<<"->";
   temp = temp->next;
   }
   cout<<"NULL";
}
int Nodeatn(Node* head, int n){
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
      if(count == n){
       return temp->value;
      }
       else{
        temp = temp->next;
        count++;
       }
    }
    return -1;
    
}
void deletenode(Node* &head, int n){
   if(head == NULL)
    return ;
    Node* temp;
    Node* prev;
    if(n == 0){
      temp = head;
      head = head->next;
      delete temp;
      return;
    }
    int count = 1;
    temp = head;
    while(temp != NULL ){
      if(count == n){
         prev = temp->next;
         temp->next = temp->next->next;
         delete prev;
         return;
      }
      else 
       temp = temp->next;
       count++;
    }
    
}
int midLL(Node* head){
   Node* temp1 = head;
   Node* temp2 = head;

   while(temp2->next != NULL){
      if(temp2->next->next != NULL)
       temp2 = temp2->next->next;
       else 
        break;
      temp1 = temp1->next;
   }

 return temp1->value;
}
int findNfromend(Node* head, int n){
   Node* temp1 = head;
   int count = 1;
   while(count < n){
      temp1 = temp1->next;
      count++;
   }
   //cout<<temp1->value;
   while (temp1->next != NULL)
   {
      head = head->next;
      temp1 = temp1->next;
   }
 return head->value;

}
void Merge(Node* Head1, Node* Head2, Node* Head){
   Node* temp;
   Node* prev;
   while (Head1 != NULL && Head2 != NULL )
   {
      temp = new Node();
      if(Head1->value <= Head2->value){
         Head->value = Head1->value;
         Head1 = Head1->next;
      }
      else {
         Head->value = Head2->value;
         Head2 = Head2->next;
      }
      Head->next = temp;
      Head = temp;

   }
   while (Head1 != NULL)
   {
      temp = new Node();
      Head->value = Head1->value;
      Head->next = temp;
      prev = Head;
      Head = temp;
      Head1 = Head1->next;
   }
   while(Head2 != NULL){
      temp = new Node();
      Head->value = Head2->value;
      Head->next = temp;
      prev = Head;
      Head = temp;
      Head2 = Head2->next;
   }
 
   prev->next = NULL;
   
}

int main(){
   //Node n1(1);
   //Node n2(2);

   //n1.next = &n2;
   Node* head1 = input();
   Node* head2 = input();

   Node* head = new Node();
   Merge(head1,head2,head);
   print(head);
   
   //cout<<Nodeatn(head,2);
   
    //deletenode(head,0);
    //print(head);

    //cout<<midLL(head);

  
    //cout<<findNfromend(head,0);

return 0;

}