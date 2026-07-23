class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
      vector<pair<int,int>> temp;
      for(int i=0;i<arr.size();i++){
        int cnt=0;
        int x=arr[i];
        while(arr[i]){
            cnt+=arr[i]&1;
            arr[i]>>=1;
        }
        temp.push_back({cnt,x});
      } 
      sort(temp.begin(),temp.end());
      vector<int> ans;
      for(auto it:temp){
        ans.push_back(it.second);
      } 
      return ans;
    }
};