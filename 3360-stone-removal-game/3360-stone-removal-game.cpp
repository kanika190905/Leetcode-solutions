class Solution {
public:
    bool canAliceWin(int n) {
      int x=1;
      int y=10;
      while(n>0){
        if(n>=y){
            n-=y;
            x++;
            y--;
        }
        else{
            if(x%2==1){
                return false;
            }
            else{
                return true;
            }
        }
       

      }
      
      if(x%2==1)
      return false;
      return 1; 
    }
};