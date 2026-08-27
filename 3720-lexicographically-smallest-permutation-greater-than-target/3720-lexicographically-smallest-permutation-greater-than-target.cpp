class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> mp(26,0);

        string temp=s;
        sort(temp.rbegin(),temp.rend());

        if(s.size()==target.size() && temp<=target)
            return "";

        for(char c:s){
            mp[c-'a']++;
        }

        string ans="";

        for(int i=0;i<target.size();i++){
            char c=target[i];

            if(mp[c-'a']){
                ans+=c;
                mp[c-'a']--;
            }
            else{
                for(int j=c-'a'+1;j<26;j++){
                    if(mp[j]){
                        ans+=char(j+'a');
                        mp[j]--;

                        for(int x=0;x<26;x++){
                            while(mp[x]){
                                ans+=char(x+'a');
                                mp[x]--;
                            }
                        }

                        return ans;
                    }
                }

                
                for(int k=i-1;k>=0;k--){

                    mp[target[k]-'a']++;

                    for(int j=target[k]-'a'+1;j<26;j++){
                        if(mp[j]){
                            string p=target.substr(0,k);
                            p+=char(j+'a');
                            mp[j]--;

                            for(int x=0;x<26;x++){
                                while(mp[x]){
                                    p+=char(x+'a');
                                    mp[x]--;
                                }
                            }

                            return p;
                        }
                    }
                }

                return "";
            }
        }

       
        for(int k=target.size()-1;k>=0;k--){

            mp[target[k]-'a']++;

            for(int j=target[k]-'a'+1;j<26;j++){
                if(mp[j]){
                    string p=target.substr(0,k);
                    p+=char(j+'a');
                    mp[j]--;

                    for(int x=0;x<26;x++){
                        while(mp[x]){
                            p+=char(x+'a');
                            mp[x]--;
                        }
                    }

                    return p;
                }
            }
        }

        return "";
    }
};