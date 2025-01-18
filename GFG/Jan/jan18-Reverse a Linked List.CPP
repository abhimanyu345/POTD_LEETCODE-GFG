Node* reverseList(struct Node* head) {
        // code here
        Node *prev = NULL;
        while(head->next){
            Node *node = head->next;
            head->next = prev;
            prev= head;
            head = node;
        }
        head->next = prev;
        return head;
    }