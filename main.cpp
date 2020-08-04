#include <iostream>
#include "BST.h"
#include "SplayTree.h"


using namespace std;

int main(){
    BST a;
    a.Insert("b", "first");
    a.Insert("a", "second");
    a.Insert("c", "third");

    std::cout<< a.Search("a") << std::endl;
    std::cout<< a.Search("b") << std::endl;
    std::cout<< a.Search("c") << std::endl;

    SplayTree b;

    b.Insert("user", "pass");

    cout << b.Search("user") << endl;

    return 0;
}