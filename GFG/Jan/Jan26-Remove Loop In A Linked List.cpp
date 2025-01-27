void removeLoop(Node* head) {
        // code here
        unordered_map<Node*, int>mpp;
        Node *temp = head;
        while(temp){
            if(mpp.find(temp->next)!=mpp.end()){
                temp->next = NULL;
            }
            mpp[temp]++;
            temp = temp->next;
        }
    }