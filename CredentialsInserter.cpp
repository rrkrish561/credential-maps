#include "CredentialsInserter.h"

// Setter
CredentialsInserter::CredentialsInserter(Tree* tree)
{
    _tree = tree;
}

// Creates the MD5 hashed password from "pass" and inserts it into the tree
void CredentialsInserter::insertCreds (string user, string pass)
{
    string hashedPass = passWrapper->getHashFromString(pass);
    _tree->Insert(user, hashedPass);
}

// Creates the hashed password to search for and compares it to the hashed password of the username specified
bool CredentialsInserter::verifyCreds (string user, string pass)
{
    string tempHashedPass = passWrapper->getHashFromString(pass);
    string hashedPass = _tree->Search(user);
    return hashedPass == tempHashedPass;
}