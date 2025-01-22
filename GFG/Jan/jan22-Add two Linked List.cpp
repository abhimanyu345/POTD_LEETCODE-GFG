Node* reverseList(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    // Function to add two numbers represented by linked lists
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;

        while (num1 || num2 || carry) {
            int sum = carry;
            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }

            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }

        // Reverse the sum list
        Node* result = reverseList(dummy->next);

        // Remove leading zeros (except if the result is exactly "0")
        while (result && result->data == 0 && result->next) {
            result = result->next;
        }

        return result;
    }