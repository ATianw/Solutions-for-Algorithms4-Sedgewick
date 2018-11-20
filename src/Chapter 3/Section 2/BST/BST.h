#ifndef _BST_H_
#define _BST_H_
#include <iostream>

typedef int Key;
class BST{
        struct Node {
                Key key;
                Node *left;
                Node *right;
                int count; 
            public:
                Node(Key in_key, int N) : key(in_key), left(nullptr), right(nullptr), count(N) {}
                ~Node() = default;
                int compare_to(Key in_key) {return key - in_key;}
        };
        Node *root;
        public: 
            int size() {return size(root);}
            //返回指向key结点的指针，如若没有则返回nullptr
            Node *get(Key key) {return get(root,key);}
            //插入key，若有key则不作反应
            //若无key则插入，并返回新建结点的指针
            void put(Key key) {root = put(root,key);}
            //返回树中最小值
            Key min() {return min(root)->key;}
            Key max() {return max(root)->key;}
            //返回排名为k的结点
            Key select(int k) {return select(root,k)->key;}
            //返回key的排名
            Key rank(Key key) {return rank(root, key);}
        private: 
            int size(Node *pnode);
            Node *get(Node *pnode, Key key);
            Node *put(Node *pnode, Key key);
            Node *min(Node *pnode);
            Node *max(Node *pnode);
            Node *select(Node *pnode, int k);
            Node *rank(Node *pnode, Key key);
};

#endif //_BST_H_