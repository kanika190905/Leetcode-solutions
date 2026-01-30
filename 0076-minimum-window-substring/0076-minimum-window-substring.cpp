class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> f(256,0);
        string ans="";
        for(int i=0;i<t.size();i++){
            f[t[i]]++;
        }
        int n=t.size();
        int l=0,r=0,cnt=0,mini=INT_MAX,bestL=0;
        while(r<s.size()){
            if(f[s[r]]>0){
                cnt++;
            }
            f[s[r]]--;
            while(cnt==n){
                if(mini>(r-l+1)){
                    mini=(r-l+1);
                    bestL=l;
                }
                f[s[l]]++;
                if(f[s[l]]>0){
                    cnt--;
                }
                l++;    
            }
            r++;
        }
        
        return mini==INT_MAX?"":s.substr(bestL,mini);

    }
};