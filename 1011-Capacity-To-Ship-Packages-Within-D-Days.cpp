class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0;
        int totalWeight = 0;
        
        for (int w : weights) {
            maxWeight = max(maxWeight, w);
            totalWeight += w;
        }
        
        int left = maxWeight;
        int right = totalWeight;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            int daysNeeded = 1;
            int currentWeight = 0;
            
            for (int w : weights) {
                if (currentWeight + w > mid) {
                    daysNeeded++;
                    currentWeight = w;
                } else {
                    currentWeight += w;
                }
            }
            
            if (daysNeeded > days) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};