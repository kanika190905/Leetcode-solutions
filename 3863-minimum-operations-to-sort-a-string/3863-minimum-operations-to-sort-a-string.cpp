class Solution {
public:
    int minOperations(string s) {
       char mini=s[0],maxi=s[0];
       if(s.size()==2 && s[0]>s[1]) return -1;
       for(char c:s){
        mini=min(mini,c);
        maxi=max(maxi,c);
       } 
       bool flag=false;
       for(int i=0;i<s.size()-1;i++){
        if(s[i]>s[i+1]){
            flag=true;
            break;
        }

       }
       if(!flag) return 0;
       bool fmax=false,fmini=false;
       int cnt1=0,cnt2=0;
       for(char c:s){
        if(c==mini){
            cnt1++;
        }
        else if(c==maxi){
            cnt2++;
        }
       } 
       if(cnt1>1){
        fmini=true;
       }
       if(cnt2>1){
        fmax=true;
       }
       if(mini==s[0] || maxi==s[s.size()-1]) return 1;
        if(!fmini && !fmax && mini==s[s.size()-1] && maxi==s[0]) return 3;
        return 2;

    }
};