class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        string left="";
        char mid=0;
        for(auto &it:mp){
            left.append(it.second/2,it.first);
            if(it.second%2!=0){
               mid=it.first;
            }
        }
        string right=left;
        reverse(right.begin(),right.end());
        if(mid!=0){
            return left+mid+right;
        }
        return left+right;
    }
};