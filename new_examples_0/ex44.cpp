#include<iostream>

using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp;
        ListNode* Head = NULL;
        if(list1 == NULL)
            return list2;
        else
            if(list2 == NULL)
                return list1;
        if(list1->val <= list2->val){
            Head = list1;
            list1 = list1->next;
        }
        else{
            Head = list2;
            list2 = list2->next;
        }   
        temp = Head;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1 == NULL)
            temp->next = list2;
        else
            if(list2 == NULL)
            temp->next = list1;
        return Head;
    }
    /*ListNode* sortList(ListNode* head) {
         if(head==NULL || head->next==NULL) return head;
        ListNode* slow = head;;
        ListNode* fast = head->next;
        //ListNode* mid;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* n = slow->next;
        slow->next = NULL;
        //ListNode* NewHead,NewHead2,NewHead3;
        ListNode* a = sortList(head);
        ListNode* b = sortList(n);
        
        head =  mergeTwoLists(a,b);
        return head;
        //return NewHead3;    
    }*/
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        /// break list into two
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *n = slow->next;
        slow->next = NULL;
        
        ListNode* a = sortList(head);
        ListNode* b = sortList(n);
        
        head = mergeTwoLists(a,b);
        return head;
    }
    ListNode *takeinput(){
        int data;
        cin>>data;
        ListNode *Head = NULL;
        ListNode *Tail = NULL;
        while(data != -1){
            ListNode *n = new ListNode(data);
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
void print(ListNode *Head){
    ListNode *temp = Head;
    while (temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
    int main(){
        ListNode* n1 = takeinput();
        ListNode* n2 = sortList(n1);
        print(n2);

    return 0;
    }