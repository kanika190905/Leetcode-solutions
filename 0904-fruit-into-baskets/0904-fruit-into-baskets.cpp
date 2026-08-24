class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set<int> st;
        int left=0;
        int ans=0;
        int maxi=0;
        vector<int> freq(100000,0);
          left=0;
          int last1=0;
          int last2=0;
          bool flag=true;
        for(int i=0;i<fruits.size();i++){
         
            st.insert(fruits[i]);
             if(fruits[i]==fruits[last1] && last1>last2){
                flag=false;
            }
            while(st.size()>2){
                freq[fruits[left]]--;
                ans--;

                if(freq[fruits[left]]==0){
                    st.erase(fruits[left]);
                }

                left++;
            }
           
            
               if(fruits[last1]!=fruits[i] && last1==last2 && fruits[i]!=fruits[last2]){
                last2=i;
            }
            freq[fruits[i]]++;
            ans++;
            maxi=max(maxi,ans);
        }
        return maxi;
        
    }
};