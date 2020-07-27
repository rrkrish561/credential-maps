#include "bst.h"

void BST::insertNode(string key, string value){
    TreeNode* newnode = new TreeNode(key,value);
    if(_size == 0){
        _root = newnode;
    }else{
        //TODO: determine where the node should be placed in the tree
    }
}

BST::TreeNode* BST::getNode(string key){
    if(_size == 0){
        return nullptr; //error: cannot search empty tree
    }else{
        BST::TreeNode* currnode = _root;
        while(currnode != nullptr){
            if(currnode->isMatchingKey(key)){
                return currnode;
            }else{
                string currnode_key = currnode->getKey();
                if(isLowerKeyValue(key, currnode_key))
                    currnode = currnode->getLeft();
                else
                    currnode = currnode->getRight();
            }
        }
        return nullptr; //error: unsuccessful search
    }
}

bool BST::isCorrectCredentials(string key, string value){
    BST::TreeNode* currnode = getNode(key);
    if(currnode == nullptr){
        return false;
    }else{
        if(currnode->isMatchingValue(value))
            return true;
        else
            return false;
    }
}