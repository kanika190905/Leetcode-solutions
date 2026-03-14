class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int high=arr.size()-1;
        int low=0;int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }
            else {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};