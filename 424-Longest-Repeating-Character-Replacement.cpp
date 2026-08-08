class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxCount = 0;
        int maxLength = 0;
        vector<int> counts(26, 0);

        for (int right = 0; right < s.length(); right++) {
            counts[s[right] - 'A']++;
            
            maxCount = max(maxCount, counts[s[right] - 'A']);

            if (right - left + 1 - maxCount > k) {
                counts[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};