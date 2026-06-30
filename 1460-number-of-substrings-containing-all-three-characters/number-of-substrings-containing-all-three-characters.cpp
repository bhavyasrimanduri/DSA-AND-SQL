class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> freq(3,0);
        int i=0;
        int ans=0;
        for(int j=0;j<n;j++){
            freq[s[j]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                ans += (n-j);
                freq[s[i]-'a']--;
                i++;
            }
        }
        return ans;
    }
};