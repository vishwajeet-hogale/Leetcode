#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// int getMaxDepth(TreeNode *root){
//     if(root == NULL){
//         return 0;
//     }
//     if(root->left == NULL && root->right == NULL){
//         return 1;
//     }
//     return max(getMaxDepth(root->left),getMaxDepth(root->right)) + 1 ;

// }
int getMaxDepth(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int l = 1+getMaxDepth(root->left);
    int r = 1+getMaxDepth(root->right);
    return max(l,r) ;
    
}