#include <string>
#include <iostream>
using namespace std;

struct BST{
    private:
        struct TreeNode{
            private:
                //TreeNode* _parent;
                TreeNode* _left; //init nullptr
                TreeNode* _right;
                string _key;
                string _value;
                bool _isLeaf;
            public:
                TreeNode(string key, string value);
                string getKey();
                string getValue();
                bool getIsLeaf();
                void setIsLeaf(bool isLeaf);
                //TreeNode* getParent();
                TreeNode* getLeft();
                TreeNode* getRight();
                //void setParent(TreeNode* parent);
                void setLeft(TreeNode* left);
                void setRight(TreeNode* right);
        };
        TreeNode* _root;
        unsigned int _size;
        bool isLowerKeyValue(string k1, string k2); //returns true if k1 has a lower value than k2, based on char values
        void deleteNodes(TreeNode* currnode);
    public:
        ~BST();
        BST();
        TreeNode* getNode(string key);
        void insertNode(string key, string value);
};