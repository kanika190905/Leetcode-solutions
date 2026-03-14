class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int high=arr.size()-1;
        int low=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return low;
    }
};