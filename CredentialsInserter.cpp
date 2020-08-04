#include "CredentialsInserter.h"

CredentialsInserter::CredentialsInserter(Tree* tree)
{
    _tree = tree;
}

void CredentialsInserter::generateCredentials (string user, string pass)
{
    _tree.Insert(user, pass);
}

bool CredentialsInserter::verifyCredentials (string user, string pass)
{
    ifstream fileReader;
    string userN;
    string passW;
    vector<pair<string,string>> accounts;
    fileReader.open("FILE NAME HERE", ios::binary);
    pair<string,string> userPass;
    while(getline(fileReader, userPass)
    {
        stringstream ss(userPass);
        ss >> userN >> passW;
        pair<string, string> account = make_pair(userN, passW);
        accounts[i] = userPass.
    }

}