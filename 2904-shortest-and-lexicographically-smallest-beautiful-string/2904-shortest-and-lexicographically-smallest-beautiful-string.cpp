class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int l=0,r=0,cnt=0;
        int mini=INT_MAX;
        int total=0;
        while(r<s.size() && l<=r){
            if(s[r]=='1'){
                cnt++;
                total++;
            }
            while(cnt>k){
                if(s[l]=='1'){
                    cnt--;
                }
                l++;
            }
            while(cnt==k){
                if(s[l]=='0')
                    l++;
                else break;
            }
            if( cnt==k){
                if(mini>(r-l+1) ){
                   string temp=s.substr(l,r-l+1);
                     ans=temp;
                mini=r-l+1;
                }
                else if(mini==(r-l+1)){
                string temp=s.substr(l,r-l+1);
                if(ans.size()==0 ||temp<ans){
                    ans=temp;
                mini=r-l+1;
                }
                }
            }
            r++;
        }
        if(total<k) return "";
        return ans;
    }
};