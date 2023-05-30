#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BTNode{
         public:
               T data;
               BTNode<T> * left;
               BTNode<T> * right;
         
               BTNode(T data){
                  this->data = data;
                  left = NULL;
                  right = NULL;
               }
         
               ~BTNode(){
                  delete left;
                  delete right;
               }

};

class BST{
               BTNode<int>* root;

               void printTree(BTNode<int>* root){
                  if(root == NULL)
                     return;
                  
                  cout<<root->data<<":";
                  if(root->left != NULL) cout<<"L"<<root->left->data<<",";
                  if(root->right != NULL) cout<<"R"<<root->right->data;
                  cout<<endl;

                  printTree(root->left);
                  printTree(root->right);
               }

               bool hasData(BTNode<int>* root, int data){
                  if(root == NULL)
                     return false;

                  if(root->data == data)
                     return true;
                  
                  if(data < root->data)
                     return hasData(root->left,data);
                      else 
                        return hasData(root->right,data);
               }

               BTNode<int>* insert(BTNode<int>* root,int data){
                  if(root == NULL){
                     root = new BTNode<int> (data);
                     return root;
                  }

                  if(data > root->data){
                        root->right = insert(root->right,data);
                        return root;
                  }
                  else{ 
                        root->left = insert(root->left,data);
                        return root;
                  }
               }

               BTNode<int>* deleteData(BTNode<int>* root, int data){
                  if(root == NULL)
                     return NULL;

                  if(data > root->data)
                     root->right = deleteData(root->right,data);
                  else
                    if(data < root->data) 
                     root->left = deleteData(root->left,data);

                  else 
                    if(root->left == NULL && root->right == NULL){
                     delete root;
                     return NULL;
                    }
                  else 
                    if(root->left == NULL){
                     BTNode<int>* temp = root->right;
                     root->right = NULL;
                     delete root;
                     return temp;
                    }
                  else
                    if(root->right == NULL){
                     BTNode<int>* temp = root->left;
                     root->left = NULL;
                     delete root;
                     return temp;
                    }
                  else{
                     BTNode<int>* minRoot = root->right;
                     while(minRoot->left != NULL)
                        minRoot = minRoot->left;
                     root->data = minRoot->data;
                     root->right = deleteData(root->right,root->data);
                  }

                  return root;
               }
                
               pair<BTNode<int>*,BTNode<int>*> convertToLinkedList(BTNode<int>* root){
                  if(root == NULL){
                     pair<BTNode<int>*,BTNode<int>*> p;
                     p.first = NULL;
                     p.second = NULL;
                     return p;
                  }
                  if(root->left == NULL && root->right == NULL){
                     pair<BTNode<int>*, BTNode<int>*> p;
                     p.first = root;
                     p.second = root;
                     return p;
                  }
                  
                  if(root->right == NULL && root->left != NULL){
                     pair<BTNode<int>*,BTNode<int>*> p = convertToLinkedList(root->left);
                     pair<BTNode<int>*,BTNode<int>*> ans;
                     ans.first = p.first;
                     p.second->right = root;
                     ans.second = root;
                     return ans;
                   }
                   
                  if(root->left == NULL && root->right != NULL){
                     pair<BTNode<int>*,BTNode<int>*> p = convertToLinkedList(root->right);
                     pair<BTNode<int>*,BTNode<int>*> ans;
                     root->right = p.first;
                     ans.first = root;
                     ans.second = p.second;
                     return ans;
                  }
                  pair<BTNode<int>*, BTNode<int>* > p1,p2;
                  p1 = convertToLinkedList(root->left);
                  p2 = convertToLinkedList(root->right);
                  p1.second->right = root;
                  root->right = p2.first;
                  pair<BTNode<int>*, BTNode<int>*> answer;
                  answer.first = p1.first;
                  answer.second = p2.second;
                  return answer;
               }

         public:
                  BST(){
                     root = NULL;
                  }

                  void deleteData(int data){
                     root = deleteData(root,data);
                  }
               
                  void insert(int data){
                     root = insert(root,data);
                  }

                  bool hasData(int data){
                     return hasData(root,data);
                  }

                  void print(){
                     printTree(this->root);
                  }

                  BTNode<int>* convertToLinkedList(){
                     pair<BTNode<int>*,BTNode<int>* > p =  convertToLinkedList(root);
                     BTNode<int>* temp = p.first;
                     while(temp != NULL){
                        temp->left = NULL;
                        temp = temp->right;
                     }
                     return p.first;
                  }
                  
                  ~BST(){
                     delete root;
                  }
};

int main(){
                 BST b;
                 b.insert(4);
                 b.insert(2);
                 b.insert(1);
                 b.insert(3);
                 b.insert(6);
                 b.insert(5);
                 b.insert(7);
                 b.print();
                 //b.deleteData(11);
                 //b.print();
                 BTNode<int>* head = b.convertToLinkedList();
                 cout<<endl;
                 while(head != NULL){
                  cout<<head->data<<"->";
                  head = head->right;
                 }

                 



         return 0;
}