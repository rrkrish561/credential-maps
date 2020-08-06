#include "CredentialsHandler.h"

CredentialsHandler::CredentialsHandler(Tree *tree) {
  _tree = tree;
  passWrapper = new md5wrapper();
}

void CredentialsHandler::insertCreds(string user, string pass) {
  string hashedPass = passWrapper->getHashFromString(pass);
  _tree->Insert(user, hashedPass);
}

bool CredentialsHandler::verifyCreds(string user, string pass) {
  string tempHashedPass = passWrapper->getHashFromString(pass);

  string hashedPass = _tree->Search(user);

  return hashedPass == tempHashedPass;
}