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
    // ifstream fileReader;
    // string userN;
    // string passW;
    // vector<pair<string,string>> accounts;
    // fileReader.open("FILE NAME HERE", ios::binary);
    // pair<string,string> userPass;
    // while(getline(fileReader, userPass)
    // {
    //     stringstream ss(userPass);
    //     ss >> userN >> passW;
    //     pair<string, string> account = make_pair(userN, passW);
    //     accounts[i] = userPass.
    // }

    string tempHashedPass = passWrapper->getHashFromString(pass);

    string hashedPass = _tree->Search(user);

    return hashedPass == tempHashedPass;

}