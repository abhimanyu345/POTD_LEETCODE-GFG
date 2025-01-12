class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
    

    if (n % 2 != 0) return false;
    
    int openCount = 0, closeCount = 0;

    for (int i = 0; i < n; ++i) {
        if (locked[i] == '1') {
            openCount += (s[i] == '(') ? 1 : -1;
        } else {
            openCount++;  
        }
        
        if (openCount < 0) return false;  // Too many ')'
    }
    
    
    openCount = closeCount = 0;

    
    for (int i = n - 1; i >= 0; --i) {
        if (locked[i] == '1') {
            closeCount += (s[i] == ')') ? 1 : -1;
        } else {
            closeCount++;  
        }
        
        if (closeCount < 0) return false;  // Too many '('
    }

    return true;
    }
};