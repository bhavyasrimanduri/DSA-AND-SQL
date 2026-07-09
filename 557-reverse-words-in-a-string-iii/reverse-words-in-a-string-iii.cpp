class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        for(int j=0;j<=s.size();j++){
            if(j==s.size()||s[j]==' '){
                int left=i;
                int right=j-1;
                while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
                i=j+1;
            }
        }
        return s;
    }
};