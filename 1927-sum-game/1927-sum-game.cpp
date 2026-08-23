class Solution {
public:
    bool sumGame(string num) {
        int ques1=0,ques2=0,sum1=0,sum2=0;
        for(int i=0;i<num.size();i++){
            if(num[i]=='?' && i<num.size()/2){
                ques1++;
            }
            else if(num[i]=='?'){
                ques2++;
            }
            else if(i<num.size()/2){
                sum1+=(num[i]-'0');
            }
            else{
                sum2+=(num[i]-'0');
            }
        }
       
        if ((ques1 + ques2) % 2 == 1)
            return true;
        if (ques1 == ques2)
            return sum1 != sum2;

        return 2 * (sum1 - sum2) != 9 * (ques2 - ques1);
    }
};