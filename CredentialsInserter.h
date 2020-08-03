#pragma once
#include "Tree.h"

using namespace std;

class CredentialsInserter
        {
        private:
            Tree* _tree;
        public:
            CredentialsInserter(Tree* tree);
            void generateCredentials (string user, string pass);
            bool verifyCredentials (string user, string pass);
        };
