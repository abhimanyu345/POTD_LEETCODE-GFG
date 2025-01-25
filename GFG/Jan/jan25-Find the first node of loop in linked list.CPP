Node* findFirstNode(Node* head) {
        // your code here
        unordered_map<Node*, int>mpp;
        Node *root = head;
        while(root){
            if(mpp.find(root->next)!=mpp.end()){
                return root->next;
            }
            mpp[root]++;
            root = root->next;
        }
        return NULL;
    }