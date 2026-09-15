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
        for(int i=0;i<n; ){
            bool found = false;
            if(i+k<=n && palindrome(s,i,i+k-1)){
                count++;
                found=true;
                i += k;
            }
            else if(i+k+1<=n && palindrome(s,i,i+k)){
                count++;
                found=true;
                i += k+1;
            }
            if(!found){
                i++;
            }
        }
        return count;
    }
};