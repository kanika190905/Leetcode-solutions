class Solution {
public:
    bool isTrue(int n){
        bool changed=false;
        while(n){
            int x=n%10;
            if(x==2 || x==5 || x==9 ||x==6) 
            changed = true;;
            if(x==3 || x==4 || x==7) return false;
            n/=10;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int cnt=0;
      for(int i=1;i<=n;i++){
        if(isTrue(i)){
            cnt++;
        }
      }  
      return cnt;
    }
};