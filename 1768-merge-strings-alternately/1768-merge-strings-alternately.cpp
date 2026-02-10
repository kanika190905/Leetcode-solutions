class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string ans="";
       int n=(word1.size()>word2.size())?word2.size():word1.size();
       int i=0;
       for(i=0;i<n;i++){
        ans+=word1[i];
        ans+=word2[i];
       }
       while(i<word1.size()){
        ans+=word1[i];
        i++;
       }
       while(i<word2.size()){
        ans+=word2[i];
        i++;
       }
       return ans;
    }
};
