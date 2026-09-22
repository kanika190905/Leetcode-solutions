class Solution {
public:
    int reverseDegree(string s) {
        int ans=0,count=0;
        for(char c:s){
            int a=c-'a';
            
                a=26-a;
           
            
            count++;
            ans+=(a*count);
        }
        return ans;
    }
};