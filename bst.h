#include <string>
using namespace std;

struct BST{
    private:
        struct TreeNode{
            private:
                TreeNode* _left;
                TreeNode* _right;
                string _key;
                string _value;
                bool isLeaf;
            public:
                TreeNode(string key, string value);
                string getKey();
                //void setKey(string key);
                //void setValue(string value);
                TreeNode* getLeft();
                TreeNode* getRight();
                bool isMatchingKey(string key);
                bool isMatchingValue(string value);
        };
        TreeNode* _root;
        unsigned int _size;
        bool isLowerKeyValue(string k1, string k2); //returns true if k1 has a lower value than k2, based on char values
    public:
        TreeNode* getNode(string key);
        void insertNode(string key, string value);
        bool isCorrectCredentials(string key, string value);
};