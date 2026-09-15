class Solution {
public:
    bool palindrome(string &s,int start, int end){
        int i=start;
        int j=end;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        int start=0;
        int count =0;
        for(int end=k-1;end < n;end++){
            bool found = false;
            for(int j=start;j<=end-k+1;j++){
                if(palindrome(s,j,end)){
                    count++;
                    start=end+1;
                    found= true;
                    break;
                }
            }
        }
        return count;
    }
};