/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> ans;
        if (root == nullptr) return ans;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            ans.push_back(curr->data);
            q.pop();
            if (curr->right){
                q.push(curr->right);
            }
            if (curr->left){
                q.push(curr->left);
            }
        }
        
        for (int i=0; i<ans.size()/2; i++){
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
};