#include <string>
using namespace std;

struct BST{
    private:
        struct TreeNode{
            private:
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
                TreeNode* getLeft();
                TreeNode* getRight();
                void setLeft(TreeNode* left);
                void setRight(TreeNode* right);
        };
        TreeNode* _root;
        unsigned int _size;
        bool isLowerKeyValue(string k1, string k2); //returns true if k1 has a lower value than k2, based on char values
    public:
        ~BST();
        TreeNode* getNode(string key);
        void insertNode(string key, string value);
};