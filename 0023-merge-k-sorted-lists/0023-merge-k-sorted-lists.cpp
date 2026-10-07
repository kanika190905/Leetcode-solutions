class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL || list2 == NULL)
            return list1 == NULL ? list2 : list1;

        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;

        while(lists.size() > 1) {
            vector<ListNode*> temp;

            for(int i = 0; i < lists.size(); i += 2) {
                if(i + 1 < lists.size())
                    temp.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                else
                    temp.push_back(lists[i]);
            }

            lists = temp;
        }

        return lists[0];
    }
};