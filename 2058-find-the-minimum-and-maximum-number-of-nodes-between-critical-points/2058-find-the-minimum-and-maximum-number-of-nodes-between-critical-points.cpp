/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        
        if(head==NULL) return {-1,-1};
        int cnt=1;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* next=temp->next;
            if(prev && next){
                if((temp->val>prev->val && temp->val>next->val)||(temp->val<prev->val && temp->val<next->val)){
                    
                    ans.push_back(cnt);
                   
                    }
                }
            
            cnt++;
            prev=temp;
            temp=temp->next;
        }
        if(ans.size()<2) return {-1,-1};
        int maxi=INT_MIN,mini=INT_MAX,smax=INT_MIN;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(ans[i]>maxi){
                smax=maxi;
                maxi=ans[i];
            }
            else if(ans[i]>smax){
                smax=ans[i];
            }
            if(i!=0)
            mini=min(mini,ans[i]-ans[i-1]);
        }
        int m1,m2;
        m2=maxi-ans[0];
        m1=mini;
        return {m1,m2};
    }
};