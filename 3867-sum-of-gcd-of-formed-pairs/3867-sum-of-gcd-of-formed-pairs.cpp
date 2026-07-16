class Solution {
public:
    int gcd(int a,int b){
       if(a==0) return b;
       else
            return gcd(b%a,a);

       
    }
    long long gcdSum(vector<int>& nums) {
      vector<int> prefixGcd(nums.size());
      int maxi=nums[0];
      for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);
        prefixGcd[i]=gcd(nums[i],maxi);
      }  
      sort(prefixGcd.begin(),prefixGcd.end());
      int l=0,r=nums.size()-1;
      long long sum=0;
      while(l<r){
        sum+=gcd(prefixGcd[l],prefixGcd[r]);
        l++;
        r--;
      }
      return sum;
    }
};