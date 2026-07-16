class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        vector<int> prefixgcd(n);
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            prefixgcd[i]=gcd(nums[i],maxi);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int i=0;
        int j=n-1;
        long long sum=0;
        while(i<j){
            sum+=gcd(prefixgcd[i],prefixgcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};