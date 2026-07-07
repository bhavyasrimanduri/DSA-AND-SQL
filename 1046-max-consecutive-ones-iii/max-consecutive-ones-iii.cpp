class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        int n=nums.size();
        int j=0;
        int zeros=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeros++;
            while(zeros>k){
                if(nums[j]==0) zeros--;
                j++;
            } 
            maxlen=max(maxlen,i-j+1);
        }
        return maxlen;
    }
};