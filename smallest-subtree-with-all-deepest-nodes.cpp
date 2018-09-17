
#include <iostream>
#include <cstdlib>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root);
    bool traverseAndFind(TreeNode* root, int depth); 

private:
    int maxDepth = 0;
    TreeNode* answer;

};




TreeNode*
Solution::subtreeWithAllDeepest(TreeNode* root)
{
    traverseAndFind(root, 1);
    return this->answer;    
}


bool
Solution::traverseAndFind(TreeNode* root, int depth) 
{
    bool isThere = false;

    if (root->left)
        traverseAndFind(root->left, depth+1);
        isThere |= true;

    if (root->right) 
        traverseAndFind(root->right, depth+1);
        isThere |= true;

    if (this->maxDepth < depth && )
        this->answer = root;
}



int 
main()
{
    return 0;
}