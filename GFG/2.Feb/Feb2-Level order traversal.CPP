vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>arr;
            for(int i=0; i<n; i++){
                Node *head = q.front();
                arr.push_back(head->data);
                q.pop();
                if(head->left)
                {
                    q.push(head->left);
                }
                if(head->right){
                    q.push(head->right);
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }