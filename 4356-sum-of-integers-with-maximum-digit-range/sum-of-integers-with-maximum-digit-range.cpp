class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> digits;
        for(int i:nums){
            int maxnum=0;
            int minnum=9;
            while(i>0){
                int last=i%10;
                maxnum=max(maxnum,last);
                minnum=min(minnum,last);
                i=i/10;
            }
            int diff=maxnum-minnum;
            digits.push_back(diff);
        }
        int maxdigi=0;
        for(int i=0;i<digits.size();i++){
            maxdigi=max(maxdigi,digits[i]);
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(digits[i]==maxdigi){
                sum += nums[i];
            }
        }
        return sum;
    }
};