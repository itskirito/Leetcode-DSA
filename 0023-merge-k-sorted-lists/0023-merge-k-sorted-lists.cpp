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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for(ListNode* list:lists)
        {
            if(list != nullptr)
            {
                minHeap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while(!minHeap.empty())
        {
            ListNode* node = minHeap.top();
            minHeap.pop();

            current->next = node;
            current = current->next;

            if(node->next != nullptr)
            {
                minHeap.push(node->next);
            }
        }
        
        return dummy->next;
    }
};