class Solution {
public:
    const int MOD=1e9+7;
    string decrementString(string s) {
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] > '0') {
            s[i]--;     
            break;      
        } else {
            s[i] = '9';  
        }
    }
    return s;
    }
    string convertToBaseB(string s, int b) {

        if (b == 10) return s;

    if (s == "0") return "0";

   

    string baseB_rep = "";

   

    // Continue until the quotient becomes empty/zero

    while (s != "0" && s != "") {

        string next_quotient = "";

        int rem = 0;

       

        // 1. Perform long division by 'b'

        for (char c : s) {

            int current_val = rem * 10 + (c - '0');

            next_quotient += to_string(current_val / b);

            rem = current_val % b;

        }

       

        // 2. The remainder of this division is our next base-B digit

        baseB_rep += to_string(rem);

       

        // 3. Remove leading zeros from the new quotient for the next iteration

        int i = 0;

        while (i < next_quotient.length() && next_quotient[i] == '0') {

            i++;

        }

       

        if (i == next_quotient.length()) {

            s = "0"; // The quotient was all zeros

        } else {

            s = next_quotient.substr(i);

        }

    }

   

    // We extracted the least significant digits first, so reverse the result!

    reverse(baseB_rep.begin(), baseB_rep.end());

    return baseB_rep;

}
    int solve(int idx,bool tight,string &s,int prev,bool leadZero,vector<vector<vector<vector<int>>>> &dp,int b){
        if(idx==s.size()){
            return 1;
        }
        if(dp[idx][tight][prev][leadZero]!=-1) return dp[idx][tight][prev][leadZero];
        int limit=tight?s[idx]-'0':b-1;
        int ans=0;
        for(int d=0;d<=limit;d++){
            int newTight=tight&&(d==limit);
            int newZero=leadZero&&(d==0);
            if(!newZero && prev<=d){
                ans=(ans+solve(idx+1,newTight,s,d,newZero,dp,b))%MOD;
            }
            else if(newZero){
                ans=(ans+solve(idx+1,newTight,s,prev,newZero,dp,b))%MOD;
            }
        }
        return dp[idx][tight][prev][leadZero]=ans;
    }
    int countNumbers(string l, string r, int b) {
        string s1=decrementString(l);
        string in1=convertToBaseB(s1,b);
        string in2=convertToBaseB(r,b);
        vector<vector<vector<vector<int>>>> dp(in2.size()+2 , vector<vector<vector<int>>>(2 , vector<vector<int>>(11 , vector<int>(2,-1 ))));
        vector<vector<vector<vector<int>>>> dp2(in1.size()+2, vector<vector<vector<int>>>(2 , vector<vector<int>>(11 , vector<int>(2,-1 ))));
        return (solve(0,true,in2,0,true,dp,b)-solve(0,true,in1,0,true,dp2,b)+MOD)%MOD;
    }
};