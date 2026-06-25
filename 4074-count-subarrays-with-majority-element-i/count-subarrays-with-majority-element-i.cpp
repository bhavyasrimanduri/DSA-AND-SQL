class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
       int n=nums.size();
       vector<int> prefix(n+1,0);
       for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+(nums[i]==target?1:-1);
       }
       long long ans=0;
       for(int r=1;r<=n;r++){
        for(int l=0;l<r;l++){
            if(prefix[r]>prefix[l]){
                ans++;
            }
        }
       }
       return ans;
    }
};