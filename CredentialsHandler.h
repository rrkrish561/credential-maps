#pragma once
#include "Tree.h"
#include "hashlibpp.h"

using namespace std;

class CredentialsHandler
        {
        private:
            Tree* _tree;
            hashwrapper *passWrapper;
        public:
            ~CredentialsHandler() {
                delete passWrapper;
            }
            CredentialsHandler(Tree* tree);
            void insertCreds (string user, string pass);
            bool verifyCreds (string user, string pass);
        };
