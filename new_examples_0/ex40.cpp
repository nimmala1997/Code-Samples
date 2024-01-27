#include<iostream>

using namespace std;

class Node{
    public:
    int data ;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

int length(Node *ll){
    if(ll == NULL)
     return 0;
    return 1+length(ll->next);
}
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
bool ispresent(Node *ll,int data){
    while(ll != NULL){
        if(ll->data == data)
         return true;
        else
          ll = ll->next;
    }
  return false;
}
bool findelement(Node *ll,int data){
    if(ll == NULL)
     return false;
    if(ll->data == data)
     return true;
    return findelement(ll->next,data);
}
void print(Node *Head){
    Node *temp = Head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node *newll = takeinput();
    //print(newll);
    //cout<<endl;
    //cout<<length(newll)<<endl;
    bool ans = findelement(newll,8);
    cout<<ans;
    //print(newll);
    
    delete newll;
return 0;

}