#include<iostream>
using namespace std;

class ListNode{
   public:
    int val;
    ListNode* next;
    ListNode();
    ListNode(int val){
      this->val = val;
    }
};
ListNode* input(){
   int val;
   cin>>val;
   ListNode * temp;
   ListNode* prev = NULL;
   ListNode* head;
   while(val != -1){
      temp = new ListNode(val);
       if(prev == NULL){
         head = temp;
         prev = temp;
       }
       else{
         prev->next = temp;
         prev = temp;
      
       }
       cin>>val;
   }
   return head;
}
void print(ListNode* n1){
   ListNode* temp  = n1;
   while(temp != NULL){
   cout<<temp->val<<"->";
   temp = temp->next;
   }
   cout<<"NULL";
}
bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL)
         return false;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == NULL)
             break;
        }
        ListNode* temp = slow;
        ListNode* prev = NULL;
        while(temp != NULL){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            if(temp != NULL)
             slow = temp;
        }
        //return slow;
       while(slow != NULL && head != NULL){
            if(slow->val != head->val){
             return false;
            }
            slow = slow->next;
            head = head->next;
        } 
        return true ;
}

int main(){
   ListNode* head = input();
   bool ans = isPalindrome(head);
   cout<<ans;

return 0;

}