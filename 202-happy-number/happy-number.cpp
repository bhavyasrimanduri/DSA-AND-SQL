class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && seen.find(n)==seen.end()){
            seen.insert(n);
            int num=0;
            while(n!=0){
               int last=n%10;
               num=num+last*last;
               n=n/10;
            }
            n=num;
        }
        return n==1;
    }
};