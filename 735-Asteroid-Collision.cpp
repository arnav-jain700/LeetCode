class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; 
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            while (!st.empty() && ast < 0 && st.back() > 0) {
                if (st.back() < -ast) {
                    st.pop_back();
                    continue;
                } else if (st.back() == -ast) {
                    st.pop_back();
                }
                destroyed = true;
                break;
            }
            
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};