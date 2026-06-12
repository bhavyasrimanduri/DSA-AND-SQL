class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0;
        int top=0;
        int n=matrix[0].size();
        int m=matrix.size();
        int bottom=m-1;
        int right=n-1;
        vector<int> ans;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
            }
            for(int i=top+1;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            for(int i=right-1;i>=left;i--){
                if(top==bottom){
                    break;
                }
                ans.push_back(matrix[bottom][i]);
            }
            for(int i=bottom-1;i>top;i--){
                if(left==right){
                    break;
                }
                ans.push_back(matrix[i][left]);
            }
            top++;
            left++;
            right--;
            bottom--;
        }
        return ans;
    }
};