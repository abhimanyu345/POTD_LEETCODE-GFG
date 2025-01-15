class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsInNum2 = __builtin_popcount(num2);

    // Step 2: Start constructing x with the minimum XOR result
    int x = 0;

    // Step 3: Set bits from left to right in num1 to minimize XOR
    for (int i = 31; i >= 0 && setBitsInNum2 > 0; --i) {
        if (num1 & (1 << i)) {
            x |= (1 << i);  // Set the bit in x
            --setBitsInNum2;
        }
    }

    // Step 4: If more bits need to be set, set them from the right
    for (int i = 0; i < 32 && setBitsInNum2 > 0; ++i) {
        if ((x & (1 << i)) == 0) {
            x |= (1 << i);  // Set the bit in x
            --setBitsInNum2;
        }
    }

    return x;
    }
};