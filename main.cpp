#include "BST.h"

int main(){
    BST a;
    a.Insert("b", "first");
    a.Insert("a", "second");
    a.Insert("c", "third");

    std::cout<< a.Search("a") << std::endl;
    std::cout<< a.Search("b") << std::endl;
    std::cout<< a.Search("c") << std::endl;
    return 0;
}