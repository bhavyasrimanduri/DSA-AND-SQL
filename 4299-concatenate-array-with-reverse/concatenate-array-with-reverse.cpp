class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        nums.resize(2*n);
        for(int i=0;i<n;i++){
            nums[i]=nums[i];
            nums[n+i]=nums[n-1-i];
        }
        return nums;
    }
};