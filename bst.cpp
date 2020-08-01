#include "bst.h"

BST::~BST(){
    if(_root != nullptr)
        deleteNodes(_root);
}

BST::BST(){
    _size = 0;
    _root = nullptr;
}

void BST::deleteNodes(TreeNode* currnode){
    deleteNodes(currnode->getLeft());
    deleteNodes(currnode->getRight());
    delete currnode;
}

void BST::insertNode(string key, string value){
    TreeNode* newnode = new TreeNode(key,value);
    if(_size == 0){
        _root = newnode;
        _size++;
    }else{
        TreeNode* currnode = _root;
        TreeNode* prevnode;
        bool lower = false;

        while(currnode != nullptr){
            string currnode_key = currnode->getKey();
            if(key.compare(currnode->getKey()) == 0){ //if the keys are equal
                prevnode = nullptr;//duplicate found, do not insert anything
                currnode = nullptr;
                delete newnode;
            }else{
                //lower = isLowerKeyValue(key, currnode_key);
                lower = key < currnode_key;
                if(lower){
                    prevnode = currnode;
                    currnode = currnode->getLeft();
                }else{
                    prevnode = currnode;
                    currnode = currnode->getRight();
                }
            }
        }

        if(prevnode != nullptr){
            if(lower)
                prevnode->setLeft(newnode);
            else
                prevnode->setRight(newnode);
            //newnode->setParent(prevnode);
            _size++;
        }


    }
}

BST::TreeNode* BST::getNode(string key){
    if(_size == 0){
        return nullptr; //error: cannot search empty tree
    }else{
        BST::TreeNode* currnode = _root;
        while(currnode != nullptr){
            string currnode_key = currnode->getKey();

            if(key == currnode_key){
                return currnode;
            }else{
                //bool lower = isLowerKeyValue(key, currnode_key);
                bool lower = key < currnode_key;
                if(lower)
                    currnode = currnode->getLeft();
                else
                    currnode = currnode->getRight();
            }
        }
        return nullptr; //error: unsuccessful search
    }
}

bool BST::isLowerKeyValue(string k1, string k2){
    unsigned int num_iters;
    bool isLowerChar = false;
    
    //number of comparisons depends on length of shorter string
    if(k1.length() > k2.length())
        num_iters = k2.length();
    else
        num_iters = k1.length();

    for(unsigned int i = 0 ; i < num_iters; i++){
        isLowerChar = k1[i] < k2[i]; 
        if(isLowerChar) //if there is one instance where this is true, k1 has a lower overall value.
            break;
    }
    return isLowerChar;
}

BST::TreeNode::TreeNode(string key, string value){
    _key = key;
    _value = value;
    //_parent = nullptr;
    _left = nullptr;
    _right = nullptr;
    _isLeaf = true;
}
// void BST::TreeNode::setParent(TreeNode* parent){
//     _parent = parent;
// }
void BST::TreeNode::setLeft(TreeNode* left){
    _left = left;
}
void BST::TreeNode::setRight(TreeNode* right){
    _right = right;
}
void BST::TreeNode::setIsLeaf(bool isLeaf){
    _isLeaf = isLeaf;
}

string BST::TreeNode::getKey(){
    return _key;
}
string BST::TreeNode::getValue(){
    return _value;
}
bool BST::TreeNode::getIsLeaf(){
    return _isLeaf;
}
// BST::TreeNode* BST::TreeNode::getParent(){
//     return _parent;
// }
BST::TreeNode* BST::TreeNode::getLeft(){
    return _left;
}
BST::TreeNode* BST::TreeNode::getRight(){
    return _right;
}