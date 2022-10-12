#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;

    Tree(int x): val(x), left(nullptr), right(nullptr) {};

    Tree* insert(Tree* root, int data) {
        if (!root) return new Tree(data);
        if (root->val > data) {
            root->left = insert(root->left, data);
        } else root->right = insert(root->right, data);
    }

    bool search(Tree* root, int data) {
        if (!root) return false;
        if (root->val == data) return true;
        if (root->val < data) return search(root->right, data);
        else return search(root->left, data);
    }

    int minVal(Tree* root) {
        while(root->left) root = root->left;
        return root->val;
    }

    Tree* deleteNode(Tree* root, int data) {
        if (!root) return nullptr;
        if (root->val == data) {
            if (!root->right and !root->left) {
                return nullptr;
            }
            else if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else {
                int min_val = minVal(root->right);
                root->val = min_val;
                root->right = deleteNode(root->right, min_val);
                return root;
            }
        }
        if (root->val < data) root->right = deleteNode(root->right, data);
        else root->left = deleteNode(root->left, data);
        return root;
    }

    void inorder(Tree* root) {
        if (!root) return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);       
    }

    void preorder(Tree* root) {
        if (!root) return;
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);       
    }
    
    void postorder(Tree* root) {
        if (!root) return;
        postorder(root->right);       
        postorder(root->left);
        cout<<root->val<<" ";
    }


};
 

int main(){
    Tree* root = new Tree(4);
    root = root->insert(root, 5);
    root = root->insert(root, 2);
    root = root->insert(root,1);
    root = root->insert(root, 7);
    root = root->insert(root, 6);
    root = root->insert(root, 12);
    root->inorder(root);
    cout<<endl;
    root = root->deleteNode(root, 12);
    cout<<"deleting 12:"<<endl;
    root->inorder(root);
    cout<<"\ndeleting 4:"<<endl;
    root = root->deleteNode(root, 4);
    root->inorder(root);
    return 0;
}