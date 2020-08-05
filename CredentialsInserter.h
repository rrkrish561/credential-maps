#pragma once
#include "Tree.h"
#include "hashlibpp.h"

using namespace std;

class CredentialsInserter
        {
        private:
            Tree* _tree;
            hashwrapper *passWrapper;
        public:
            CredentialsInserter() {
                passWrapper = new md5wrapper();
            }
            ~CredentialsInserter() {
                delete passWrapper;
            }
            CredentialsInserter(Tree* tree);
            void insertCreds (string user, string pass);
            bool verifyCreds (string user, string pass);
        };
