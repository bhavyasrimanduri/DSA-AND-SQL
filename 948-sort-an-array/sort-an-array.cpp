class Solution {
public:
    void merge(vector<int> &nums,int l,int m,int r){
        int i,j,k;
        int n1=m-l+1;
        int n2=r-m;
        vector<int> L(n1);
        vector<int> R(n2);
        for(int i=0;i<n1;i++){
            L[i]=nums[l+i];
        }
        for(int j=0;j<n2;j++){
            R[j]=nums[m+1+j];
        }
        i=0;j=0;k=l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                nums[k++]=L[i++];
            }
            else{
                nums[k++]=R[j++];
            }
        }
        while(i<n1){
            nums[k++]=L[i++];
        }
        while(j<n2){
            nums[k++]=R[j++];
        }
    }
    void mergesort(vector<int> &nums,int l,int r){
        if(l<r){
            int m = l+(r-l)/2;
            mergesort(nums,l,m);
            mergesort(nums,m+1,r);
            merge(nums,l,m,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        mergesort(nums,l,r);
        return nums;
    }
};