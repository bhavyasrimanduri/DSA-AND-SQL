class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int i=0;
        int j=0;
        int length=0;
        int maxfreq=0;
        while(i<s.size()){
            freq[s[i]-'A']++;
            maxfreq=max(maxfreq,freq[s[i]-'A']);
            i++;
            while((i-j)-maxfreq>k){
                freq[s[j]-'A']--;
                j++;
            }
            length=max(length,i-j);
        }
        return length;
    }
};