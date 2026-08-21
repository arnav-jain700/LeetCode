class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int uniqueNumber = 0;
        
        for (int num : nums) {
            uniqueNumber ^= num;
        }
        
        return uniqueNumber;
    }
};