class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string currentString, int openCount, int closeCount, int maxPairs) {
        if (currentString.length() == maxPairs * 2) {
            result.push_back(currentString);
            return;
        }

        if (openCount < maxPairs) {
            backtrack(result, currentString + "(", openCount + 1, closeCount, maxPairs);
        }

        if (closeCount < openCount) {
            backtrack(result, currentString + ")", openCount, closeCount + 1, maxPairs);
        }
    }
};