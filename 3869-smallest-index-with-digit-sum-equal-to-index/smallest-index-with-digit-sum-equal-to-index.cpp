class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int lastdigit=0;
            int sum=0;
            int num=nums[i];
            while(num>0){
                lastdigit=num%10;
                num/=10;
                sum+=lastdigit;
            }
            if(sum==i){
                mini=min(mini,i);
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};