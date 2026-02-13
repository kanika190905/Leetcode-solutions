class Solution {
public:
    int addDigits(int num) {
        // Continue the process until num becomes a single digit
        while (num >= 10) {
            int sum = 0;
            
            // Inner loop to sum all digits of the current 'num'
            while (num > 0) {
                sum += num % 10; // Get the last digit
                num /= 10;      // Remove the last digit
            }
            
            // Update num with the sum of its digits for the next iteration
            num = sum;
        }
        
        return num;
    }
};