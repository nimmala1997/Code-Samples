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
Node *takeinput(){
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
int midvalue(Node *Head){
    Node *slow;
    Node *fast;
    slow = Head;
    fast = Head->next;
    int count = 0;
    while(fast != NULL){
        if(fast->next != NULL){
        slow = slow->next;
        count++;
        fast = fast->next->next;
        }
        else{
            slow = slow->next;
            count++;
            fast = fast->next;
        }

    }
    return count;
}
Node *reversell(Node *Head){
    Node *temp ;
    Node *first = Head;
    Node *second = Head->next;
    Head->next = NULL;
    while(second != NULL){
       temp = second->next;
       second->next = first;
       first = second;
       second = temp;

    }
    //Head->next = NULL;
    return first;
}
void print(Node *Head){
    Node *temp = Head;
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
int main(){
Node * newll = takeinput(); 
//cout<<midvalue(newll);
Node *newll2 = reversell(newll);
print(newll2);

return 0;
}