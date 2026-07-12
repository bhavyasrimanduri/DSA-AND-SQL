class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        int rank=1;
        unordered_map<int,int> ran;
        for(int x:temp){
            if(ran.find(x)==ran.end()){
                ran[x]=rank++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=ran[arr[i]];
        }
        return arr;
    }
};