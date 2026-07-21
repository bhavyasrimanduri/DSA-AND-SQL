class Solution {
public:
    int maxlen=0;
    int start=0;
    void expand(string &s,int left,int right){
        while(left>=0 && right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        int len=right-left-1;
        if(len>maxlen){
            maxlen=len;
            start=left+1;
        }
    }
    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return s.substr(start,maxlen);
    }
};