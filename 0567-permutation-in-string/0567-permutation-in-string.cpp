class Solution {
private:
    bool checkEqual(int count1[],int count2[]){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            count1[index]++;
        }
        int i=0;
        int count2[26]={0};
        int windowSize=s1.length();
        while(i<windowSize && i<s2.length()){
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }
        if (checkEqual(count1,count2)) return true;

        while(i<s2.length()){
            int index=s2[i]-'a'; //new char
            count2[index]++;

            index=s2[i-windowSize]-'a';
            count2[index]--;

            i++;

            if(checkEqual(count1,count2)) return true;
        }
        return false;
    }
};