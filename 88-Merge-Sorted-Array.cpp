class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a1 = m - 1;
        int a2 = n - 1;
        int a = m + n - 1;

        while(a1 >= 0 && a2 >= 0){
            if(nums1[a1] > nums2[a2]){
                nums1[a] = nums1[a1];
                a1--;
            } else{
                nums1[a] = nums2[a2];
                a2--;
            }
            a--;
        }

        while(a2 >= 0){
            nums1[a] = nums2[a2];
            a2--;
            a--;
        }
    }
};