class Solution {
public:
    bool cansplit(vector<int>& nums,long long mid,int k){
        int subarray=1;
        int curntsum=0;
        for(int i=0;i<nums.size();i++){
            if(curntsum+nums[i]>mid){
                subarray++;
                curntsum=nums[i];
            }
            else{
                curntsum += nums[i];
            }
        }
        return subarray<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low= *max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0ll);
        while(low<high){
            long long mid=low+(high-low)/2;
            if(cansplit(nums,mid,k)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};