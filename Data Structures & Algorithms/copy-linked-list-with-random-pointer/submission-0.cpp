/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp ;

        Node* dummy = new Node(0);
        Node* curr = dummy ;
        vector<Node*> random ;

        Node* temp = head ;

        while(temp != nullptr){
            Node* node = new Node(temp->val);
            mpp[temp] = node ;
            curr->next = node ;
            curr = curr->next ;
            random.push_back(temp->random) ;

            temp = temp->next ;
        }

        curr = dummy->next ;
        temp = head ;
        for(int i = 0; i< random.size(); i++){
            if(random[i] == NULL) curr->random = NULL ;
            else{
                curr->random = mpp[random[i]];
            }

            curr = curr->next ;
        }

        return dummy->next ;
    }
};
