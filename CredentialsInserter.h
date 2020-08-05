#pragma once
#include "Tree.h"
#include "hashlibpp.h"

using namespace std;

class CredentialsInserter
        {
        private:
            // Private variable initializers
            Tree* _tree;
            hashwrapper *passWrapper = new md5wrapper();
        public:
            // Destructor
            ~CredentialsInserter() {
                delete passWrapper;
            }
            // Constructor
            CredentialsInserter(Tree* tree);
            // Method declarations
            void insertCreds (string user, string pass);
            bool verifyCreds (string user, string pass);
        };
