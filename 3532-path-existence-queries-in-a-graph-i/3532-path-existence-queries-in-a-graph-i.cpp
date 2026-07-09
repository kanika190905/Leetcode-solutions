class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        for(auto it:queries){
             int u=it[0];
             int v=it[1];
            if(u==v){
                ans.push_back(1);
                continue;
            }
            else if(u>v){
                int a=u;
                u=v;
                v=a;
            }
            if(abs(nums[u]-nums[v])<=maxDiff){
               ans.push_back(1); 
            }
            else{
                if(abs(v-u)>1){
                    bool found=0;
                    for(int i=u;i<v;i++){
                        if(abs(nums[i]-nums[i+1])>maxDiff){
                           ans.push_back(0);
                           found=1;  
                           break;
                        }
                    }
                    if(found==0)
                     ans.push_back(1);
                    }
                    
                
                else
                ans.push_back(0);
        }
            }
        
        return ans;
    }
};