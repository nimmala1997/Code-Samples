#include<iostream>
#include<cstdlib>

using namespace std;

class Node{
    public :
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};
Node *takeinput2(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    Node *temp;

    while(data != -1){
        Node *n = new Node(data);

        if(head == NULL){
            head = n;
            head->next = NULL;
            tail = n;
            //temp = NULL;
        }
        //temp = n;
        else{
            head = n;
            head->next = tail;
            tail = n ;
            //temp = n;
        }
         cin>>data;
    }
    return head;
}
Node *takeinput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    Node *temp;

    while(data != -1){
        Node *n = new Node(data);

        if(head == NULL){
            head = n;
            //head->next = NULL;
            tail = n;
            //temp = NULL;
        }
        //temp = n;
        else{
            //head = n;
            tail->next = n;
            tail = n ;
            //temp = n;
        }
         cin>>data;
    }
    return head;
}
int length(Node *Head){
    int count = 0;
    while(Head != NULL){
            count++;
            Head = Head->next;
    }
    return count;
}
void print(Node *Head){
    Node *temp = Head;
    while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
    
}
void printinode(Node *Head,int i){
    int count = -1;
    if(i >= 0){
    while (Head != NULL){
        count++;
        if(count == i){
            cout<<Head->data;
            return;
        }
        else
            Head = Head->next;
    }
    }
    else
     cout<<count;
    if(count <= i)
     cout<<-1;
    
}

Node* insertinode(Node *Head,int d,int i){
  int count = 0;
  //int n = length(Head);
  Node* tail = Head->next;
  if(i > 0){
      while(count < i && tail != NULL){
          if(count == i-1){
              Node *temp = tail->next;
              Node *n = new Node(d);
              tail->next = n;
              n->next = temp;
              return Head;
              }
          tail = tail->next;
          count++;
      }
      return Head;
  }
  else
  if(i == 0){
       //Node *temp = Head;
       Node *n = new Node(d);
       n->next = Head;
       Head = n;
       return Head;
  }
  else
    return Head;
}
int main(){
  Node n1(1);
  Node n2(2);
  Node n3(3);
  Node n4(4);
  Node n5(5);

  Node *HEAD;
  HEAD = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  //print(HEAD);

  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  Node *n8 = new Node(8);

  n5.next = n6;
  n6->next = n7;
  n7->next = n8;
  
  Node *newll = takeinput();
  cout<<"enter i node"<<endl;
  Node * newl = insertinode(newll,23,5);
  newll = newl;
  print(newll);
  //int ans = length(newll);
  //cout<<ans;
  //printinode(newll,-2);
  //print(HEAD);

}