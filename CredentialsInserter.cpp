#include "CredentialsInserter.h"

CredentialsInserter::CredentialsInserter(Tree* tree)
{
    _tree = tree;
}

void CredentialsInserter::insertCreds (string user, string pass)
{
    string hashedPass = passWrapper->getHashFromString(pass);
    _tree->Insert(user, hashedPass);
}

bool CredentialsInserter::verifyCreds (string user, string pass)
{

    string tempHashedPass = passWrapper->getHashFromString(pass);

    string hashedPass = _tree->Search(user);

    return hashedPass == tempHashedPass;

}