class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        string ans="";
        char ch;
        for(int i=0;i<26;i++){
            if(count[i]%2==1){
                ch=i+'a';
                count[i]--;
            }
            int cnt=count[i];
            int j=0;
            while(j!=(cnt/2)){
                ans+=(i+'a');
                count[i]--;
                j++;
            }
        }
         string temp=ans;
        reverse(temp.begin(),temp.end());
        if(s.size()%2==1)ans+=ch;
        ans+=temp;
        return ans;
    }
};