class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int size=0;
        int cnt=0;
        vector<int> freq(n,0);
        int i=0;
        int j=0;
        while(i<n){
            if(freq[fruits[i]]==0){
                size++;
            }
            freq[fruits[i]]++;
            i++;
            while(size>2){
                freq[fruits[j]]--;
                if(freq[fruits[j]]==0){
                    size--;
                }
                j++;
            }
            cnt=max(cnt,i-j);
        }
        return cnt;
    }
};