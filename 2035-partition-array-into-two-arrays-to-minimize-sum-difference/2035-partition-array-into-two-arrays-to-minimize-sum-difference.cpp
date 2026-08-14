class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        int n=nums.size()/2;
        vector<vector<int>> leftSum(n+1);
        vector<vector<int>> rightSum(n+1);
        //Left 
        for(int mask=0;mask<(1<<n);mask++){
          int sz=0;
          int tempSum=0;
          for(int i=0;i<n;i++){
            if((mask & (1<<i))!=0){
                sz++;
                tempSum+=nums[i];
            }
          } 
          leftSum[sz].push_back(tempSum); 
        }
        // RIGHT
        for(int mask=0;mask<(1<<n);mask++){
          int sz=0;
          int tempSum=0;
          for(int i=0;i<n;i++){
            if((mask & (1<<i))!=0){
                sz++;
                tempSum+=nums[i+n];
            }
          } 
          rightSum[sz].push_back(tempSum); 
        }
        // sorting the rightSum array so that binary search can be applied
        for(int i=0;i<=n;i++){
            sort(rightSum[i].begin(),rightSum[i].end());
        }
        int min_diff=2e9;
        double target=sum/2.0;
        for(int k=0;k<=n;k++){
            int right_k=n-k;

            for(int a:leftSum[k]){
                auto &right_list=rightSum[right_k];
                int b_target=target-a;
                auto it=lower_bound(right_list.begin(),right_list.end(),b_target);

                if(it!=right_list.end()){
                    int b=*it;
                    int curr_sum=a+b;
                    min_diff=min(min_diff,abs(2*curr_sum - sum));
                }
                   if(it!=right_list.begin()){
                    auto prev_it=it-1;
                    int b=*prev_it;
                    int curr_sum=a+b;
                    min_diff=min(min_diff,abs(2*curr_sum - sum));
                }
            }
        }
        return min_diff;
    }
};