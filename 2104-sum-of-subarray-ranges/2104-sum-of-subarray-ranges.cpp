class Solution {
private:
    vector<int> findNse(vector<int> &arr){
        stack<int> s;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findPsee(vector<int> &arr){
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(i);
        }
        return ans;
    }
    long long  sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=findNse(arr);
        vector<int> psee=findPsee(arr);
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            long long left=i-psee[i];
            long long right=nse[i]-i;
            long long freq=left*right;
            long long val=(freq*arr[i]);
            sum=(sum+val);
        }
        return sum;
    }
    vector<int> findNle(vector<int> &arr){
        stack<int> s;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findPlee(vector<int> &arr){
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && arr[s.top()]<arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(i);
        }
        return ans;
    }
    long long  sumSubarrayMax(vector<int>& arr) {
        vector<int> nle=findNle(arr);
        vector<int> plee=findPlee(arr);
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            long long left=i-plee[i];
            long long right=nle[i]-i;
            long long freq=left*right;
            long long val=(freq*arr[i]);
            sum=(sum+val);
        }
        return sum;
    }
    public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)-sumSubarrayMins(nums);
    }
};
