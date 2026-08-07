class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int max_len = 0;
        int left = 0;
        
        vector<int> last_seen(256, -1);
        
        for (int right = 0; right < n; right++) {
            char current_char = s[right];
            
            if (last_seen[current_char] >= left) {
                left = last_seen[current_char] + 1;
            }
            
            last_seen[current_char] = right;
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};