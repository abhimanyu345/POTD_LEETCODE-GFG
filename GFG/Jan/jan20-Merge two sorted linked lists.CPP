Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node *root1 = head1;
        Node *root2 = head2;
        vector<int>arr;
        while(root1){
            arr.push_back(root1->data);
            root1=root1->next;
        }
        while(root2->next){
            arr.push_back(root2->data);
            root2=root2->next;
        }
        arr.push_back(root2->data);
        root2->next = head1;
        sort(arr.begin(), arr.end());
        root2 = head2;
        for(int i=0; i<arr.size(); i++){
            root2->data = arr[i];
            root2 = root2->next;
        }
        return head2;
    }