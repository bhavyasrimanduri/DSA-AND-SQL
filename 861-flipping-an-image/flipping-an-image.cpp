class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &i:image){
            reverse(i.begin(),i.end());
            for(int &x:i){
                x=1-x;
            }
        }
        return image;
    }
};