/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //using catlan number we are calclulating the number of binary trees are possible 
 //the formula of catlan number is {(2n)C(n)/n+1}
 /*
    --steps
    1.) decide the root node
    2.) Call the function again to make all possible trees for left and right subtree.
    3.) Use all combinations of it to make trees and return it 
 */
class Solution {
public:
  
   vector<TreeNode*> help(int l , int r){
       //base condition
       if(l > r || l < 1) {
            vector<TreeNode*> v;
            v.push_back(NULL);
            return v;
        }
        if(l==r) {
            
            vector<TreeNode*> v;
            TreeNode* temp = new TreeNode;
            temp->val = l;
            temp->left = NULL;
            temp->right = NULL;
            v.push_back(temp);
            return v;
        }
        vector<TreeNode*>ans;
        for(int i = l; i <= r; i++) {
            
            vector<TreeNode*> lt = help(l,i-1);
            vector<TreeNode*> rt = help(i+1,r);
            for(int k = 0; k < lt.size(); k++) {
                for(int j = 0; j < rt.size(); j++) {
                    TreeNode* temp = new TreeNode;
                    temp->val = i;
                    temp->left = lt[k];
                    temp->right = rt[j];
                    ans.push_back(temp);
                }
            }
            
        }
        return ans;
   }

    vector<TreeNode*> generateTrees(int n) {
        return help(1 ,n) ;
    }
};