 Node* last_node(Node *root){
        while(root->next){
            root = root->next;
        }
        return root;
    }
    void reverse(Node *root, vector<Node *>&arr){
        Node *prev = NULL;
        Node *temp = root;
        while(temp){
            Node *res = temp->next;
            temp->next = prev;
            prev = temp;
            temp = res;
        }
        arr.push_back(prev);
    }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        vector<Node*>arr;
        int cnt = 0;
        Node *temp = head;
        Node *start = head;
        while(temp){
            cnt++;
            if(cnt%k==0){
                Node *temp2 = temp->next;
                temp->next = NULL;
                reverse(start, arr);
                start = temp2;
                temp = start;
            }
            else
            temp = temp->next;
        }
        if(start)
        reverse(start, arr);
        for(int i=0; i<arr.size()-1; i++){
            Node *last = last_node(arr[i]);
            last->next = arr[i+1];
        }
        return arr[0];
    }