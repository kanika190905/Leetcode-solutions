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
        if (s == "0" || s.empty()) return "0";
        
        // OPTIMIZATION: Use vector of ints instead of strings for the math
        vector<int> num;
        for (char c : s) num.push_back(c - '0');
        
        string baseB_rep = "";
        
        while (!num.empty()) {
            int rem = 0;
            vector<int> next_num;
            
            for (int digit : num) {
                int current_val = rem * 10 + digit;
                int q = current_val / b;
                rem = current_val % b;
                
                // Add to next quotient only if it's not a leading zero
                if (!next_num.empty() || q > 0) {
                    next_num.push_back(q);
                }
            }
            
            baseB_rep += (char)(rem + '0'); // Fast char append instead of to_string
            num = std::move(next_num);      // Efficiently swap to the new quotient
        }
        
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