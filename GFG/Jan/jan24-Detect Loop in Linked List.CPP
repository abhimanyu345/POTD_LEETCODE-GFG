bool detectLoop(Node* head) {
        // your code here
        unordered_map<Node*, int>mpp;
        Node *temp = head;
        while(temp){
            if(mpp.find(temp->next)!=mpp.end())
            return true;
            mpp[temp]++;
            temp =temp->next;
        }
        return false;
    }