#include<iostream>

using namespace std;
class Node{
public:
int data;
Node * next;

Node(int data){
    this->data = data;
    next = NULL;
}
};

Node* takeinput(){
int data;
cin>>data;
Node *Head = NULL;
Node *Tail = NULL;
while(data != -1){
    Node *n = new Node(data);
    if(Head == NULL){
        Head = n;
        Tail = n;
    }
    else{
        Tail->next = n;
        Tail = n;
    }
    cin>>data;
    
}
return Head;
}

Node* mergell(Node* ll1,Node* ll2){
if(ll1 == NULL)
return ll2;
if(ll2 == NULL)
return ll1;
Node* Head;
Node* temp;
if(ll1->data <= ll2->data){
Head = ll1;
temp = Head;
ll1 = ll1->next;
}
if(ll2->data<ll1->data){
    Head = ll2;
    temp = Head;
    ll2 = ll2->next;
}
while(ll1 != NULL && ll2 != NULL){
if(ll1->data <= ll2->data){
    temp->next = ll1;
    ll1 = ll1->next;
}
else
if(ll2->data < ll1->data){
    temp->next = ll2;
    ll2 = ll2->next;
}
temp = temp->next;
}
if(ll1 == NULL){
    temp->next = ll2;
}
if(ll2 == NULL){
    temp->next = ll1;
}
return Head;
}

Node* mergell2(Node* ll1,Node* ll2){
if(ll1 == NULL)
return ll2;
if(ll2 == NULL)
return ll1;

while(ll1 != NULL && ll2 != NULL){
if(ll1->data <= ll2->data){
    ll1->next = mergell2(ll1->next,ll2);
    return ll1;
}
else
if(ll2->data < ll1->data){
    ll2->next = mergell2(ll1,ll2->next);
    return ll2;
}

}

}

void print(Node *Head){
    Node *temp = Head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
Node* ll = takeinput();
Node* ll1 = takeinput();
Node* merge = mergell2(ll,ll1);
print(merge);

return 0;
}
