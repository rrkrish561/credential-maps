#include "CredentialsInserter.h"

CredentialsInserter::CredentialsInserter(Tree tree)
{
    _tree = tree;
}

void CredentialsInserter::generateCredentials (string user, string pass)
{
    _tree.Insert(user, pass);
}

bool CredentialsInserter::verifyCredentials (string user, string pass)
{

}