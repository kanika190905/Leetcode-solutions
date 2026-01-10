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
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=findNse(arr);
        vector<int> psee=findPsee(arr);
        int n=arr.size();
        int mod=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            long long freq=left*right*1LL;
            int val=(freq*arr[i]*1LL)%mod;
            sum=(sum+val)%mod;
        }
        return sum;
    }
};