#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

struct node{
    int data;
    node* left;
    node *right;
};
struct node* create_node(int val){
    struct node *p = new node;
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}
struct LinkedNode{
    int data;
    LinkedNode *next;
};
struct node* insert(vector<int>& arr,struct node *root,int i,int n){
    if(i<n){
        struct node *p = create_node(arr[i]);
        root = p;
        root->left = insert(arr,root->left,2*i+1,n);
        root->right = insert(arr,root->right,2*i+2,n);

    }
    return root;
}
LinkedNode* create_lined_node(int val){
    struct LinkedNode *p = new LinkedNode;
    p->data = val;
    p->next = NULL;
    return p;
}
LinkedNode* insert_linked(LinkedNode *root,int val){
    LinkedNode *head;
    if(!root){
        head = create_lined_node(val);
    }
    else{
        LinkedNode *ptr = root;
        if(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = create_lined_node(val);

    }
    return head;
}
// void flatten(node *root,LinkedNode *root1){
//     // LinkedNode* head = root1;
//     if(root == NULL){
//         return;
//     }
//     root1 = insert_linked(root1,root->data);
//     cout<<root->data<<"->";
//     flatten(root->left,root1);
//     flatten(root->right,root1);
    
// }
int goodNodesHelper(node* root, int max_value){
    if(!root) 
        return 0;
    return goodNodesHelper(root->left, max(max_value, root->data)) + goodNodesHelper(root->right, max(max_value, root->data)) + (root->data >= max_value);
}

int goodNodes(node* root) {
        return goodNodesHelper(root, INT_MIN);   
    }
    // int goodNodes(node* root) {
    //     int count = 0;
    //     int g =INT_MIN;
    //     onemoremethod(root, g);   
    //     return count;
    // }


int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(5);
    
    
    struct node *root = insert(arr,root,0,arr.size());
    cout<<goodNodes(root)<<endl;

    return 0;
}