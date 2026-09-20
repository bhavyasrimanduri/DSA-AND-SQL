class Solution {
public:
    int reverseDegree(string s) {
        int product=0;
        for(int j=0;j<s.size();j++){
            char ch = s[j];
            int value='z'-ch+1;
            product += value*(j+1);
        }
        return product;
    }
};