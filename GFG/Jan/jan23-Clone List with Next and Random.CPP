Node *find(int y, Node *node){
        Node *temp=node;
        while(temp){
            if(temp->data==y)
            return temp;
            temp=temp->next;
        }
    }
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        int x = head->data;
        Node* node = new Node(x);
        Node *temp = node;
        Node *root = head->next;
        while(root){
            int a = root->data;
            Node* res = new Node(a);
            temp->next = res;
            temp = temp->next;
            root = root->next;
        }
        root = head;
        temp = node;
        while(root){
            if(root->random){
            int y = (root->random)->data;
            temp->random = find(y, node);
            }
            temp = temp->next;
            root = root->next;
        }
        temp = node;
        while(temp){
            cout<<temp->data<<" "<<temp->random->data;
            temp = temp->next;
        }
        return node;
    }