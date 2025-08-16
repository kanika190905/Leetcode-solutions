class Solution {
    int getpivot(vector<int>& arr){
    int s=0,e=arr.size()-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=arr[0])
            s=mid+1;
        else
            e=mid;
    }
    return s;
}
int binsearch(vector<int>& arr,int initial,int final,int key){
	
	
	while(initial<=final){
		
		int mid=initial+(final-initial)/2;
		if(arr[mid]==key){
			return mid;
			
		}
		else if(arr[mid]<key){
			initial=mid+1;
			
		}
		else{
	         final=mid-1;
		}
	
	}
	return -1;
}
public:
    int search(vector<int>& nums, int target) {
        int pivot = getpivot(nums);
        int n = nums.size();
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binsearch(nums, pivot, n - 1, target);
        }
        return binsearch(nums, 0, pivot - 1, target);
    }
};