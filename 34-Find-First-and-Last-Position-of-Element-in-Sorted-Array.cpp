class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurrence = findBound(nums, target, true);
        
        if (firstOccurrence == -1) {
            return {-1, -1};
        }
        
        int lastOccurrence = findBound(nums, target, false);
        
        return {firstOccurrence, lastOccurrence};
    }

private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        
        return bound;
    }
};