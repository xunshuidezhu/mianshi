#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct Node {
    char data;
    Node *right, *left;
} Treenode;

Treenode* create(string& s, int& pos)
{
    pos++;
    Node* node;
    if (pos > s.size()) {
        return nullptr;
    } else if (s[pos] == '#') {
        return nullptr;
    } else {
        node = new Node;
        node->data = s[pos];
        node->left = create(s, pos);
        node->right = create(s, pos);
    }
    return node;
}

class Bitree {
public:
        
    Bitree()
    {
        root = new Node();
        root->left = nullptr;
        root->right = nullptr;
    }
    void CreateBitree(string& s)
    {
        int pos = -1;
        root = Create(s, pos);
    }
    Node* Create(string& s, int& pos)
    { // 注意这里的pos一定要写成引用，否则不能保证pos的累加
        pos++;
        Node* node;
        if (pos > s.size())
            return nullptr;
        else if (s[pos] == '#')
            node = nullptr;
        else {
            node = new Node();
            node->data = s[pos];
            node->left = Create(s, pos);
            node->right = Create(s, pos);
        }
        return node;
    }

    void preorder(Node* p)
    {
        if (!p)
            return;
        cout << p->data << endl;
        preorder(p->left);
        preorder(p->right);
    }
    Node* root;
};

Treenode* createTree(string& s, int& pos)
{
    pos++;
    Treenode* root;
    if (pos > s.length()) {
        return nullptr;
    } else if (s[pos] == '#') {
        return nullptr;
    } else {
        root = new Treenode;
        root->data = s[pos];
        root->left = createTree(s, pos);
        root->right = createTree(s, pos);
    }
    return root;
}

void preOrder(Treenode* root)
{
    if (root == nullptr) {  
        return;
    }
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    string s = "ABD##E#F##C##";
    int pos = -1;
    Treenode* root = createTree(s, pos);
    preOrder(root);
    return 0;
}
