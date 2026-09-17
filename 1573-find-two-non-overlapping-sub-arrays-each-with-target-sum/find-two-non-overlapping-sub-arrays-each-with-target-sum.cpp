class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int INF=1e9;
        vector<int> best(n+1,INF);
        int ans=INF;
        int j=0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            while(sum > target){
                sum -= arr[j];
                j++;
            }
            best[i+1]=best[i];
            if(sum==target){
                int len=i-j+1;
                if(best[j]!=INF){
                    ans=min(ans,len+best[j]);
                }
                best[i+1]=min(best[i+1],len);
            }
        }
        return ans==INF ? -1:ans; 
    }
};