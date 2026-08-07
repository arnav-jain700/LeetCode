class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writeIndex = 0;
        for(int readIndex = 0; readIndex < nums.size(); readIndex++){
            if(nums[readIndex] != 0){
                swap(nums[writeIndex], nums[readIndex]);
                writeIndex++;
            }
        }
    }
};