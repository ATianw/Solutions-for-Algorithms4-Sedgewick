#include "BST.h"

int BST::size(Node *root) {
    if (root = nullptr)     return 0;
    else                    return root->count;
}
//返回指向key结点的指针，如若没有则返回nullptr
BST::Node *BST::get(Node *pnode, Key key){
    if (pnode == nullptr) return nullptr;
    int cmp = pnode->compare_to(key); //pnode->key - key
    if (cmp > 0) return get(pnode->left,key);
    if (cmp < 0) return get(pnode->right,key);
    else return pnode;
}
//插入key，若有key则不作反应
//若无key则插入，并返回新建结点的指针
BST::Node *BST::put(Node *pnode, Key key) {
    if (pnode == nullptr)   return new Node(key,1);
    int cmp = pnode->compare_to(key); //pnode->key - key
    if (cmp > 0) return put(pnode->left, key);
    if (cmp < 0) return put(pnode->right,key);
    pnode->count = size(pnode->left) + size(pnode->right);
}

BST::Node *BST::min(Node *pnode) {
    if (pnode->left == nullptr) return pnode;
    return min(pnode->left);
}

BST::Node *BST::max(Node *pnode) {
    if (pnode->right == nullptr) return pnode;
    return min(pnode->right);
}

BST::Node *BST::select(Node *pnode, int k) {
    //如果k超出范围，返回空指针
    if (pnode == nullptr) retutn nullptr;
    int left_size = size(pnode->left);
    if(left_size > k) return select(pnode->left, k);
    if(left_size < k) return select(pnode->right, k-left_size-1)
    else              return pnode;
}

Node *rank(Node *pnode, Key key) {
    if (pnode == nullptr)   return nullptr;//树中没有key
    int cmp = pnode->compare_to(key);
    if (cmp < 0) return 1 + size(pnode->left) + 7rank(pnode->right, key);
    if (cmp > 0) return rank(pnode->left,  key);
    else         return size(pnode->left) + 1;
}