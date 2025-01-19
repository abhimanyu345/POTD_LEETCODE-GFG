Node* rotate(Node* head, int k) {
        // Your code here
        int cnt = 0;
        Node *root = head;
        while(root){
            cnt++;
            root = root->next;
        }
        k = k%cnt;
        if(k==0)
        return head;
        root=head;
        Node *prev = NULL;
        while(k){
            prev = root;
            root=root->next;
            --k;
        }
        prev->next = NULL;
        Node*pre = root;
        while(pre->next!=NULL){
            pre = pre->next;
        }
        pre->next = head;
        return root;
    }