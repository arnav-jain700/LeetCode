class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruit_counts;
        int left = 0;
        int max_picked = 0;
        
        for (int right = 0; right < fruits.size(); ++right) {
            fruit_counts[fruits[right]]++;
            
            while (fruit_counts.size() > 2) {
                fruit_counts[fruits[left]]--;
                
                if (fruit_counts[fruits[left]] == 0) {
                    fruit_counts.erase(fruits[left]);
                }
                
                left++;
            }

            max_picked = max(max_picked, right - left + 1);
        }
        
        return max_picked;
    }
};