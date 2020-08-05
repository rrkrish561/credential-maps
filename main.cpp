#include "BST.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "CredentialsInserter.h"
#include <chrono>
#include "Tree.h"
#include "SplayTree.h"
#include "hashlibpp.h"

using namespace std::chrono;

int main()
{
    typedef high_resolution_clock Clock;
    int menuSelect = 0;
    int treeSpecifier;
    hashwrapper *passWrapper = new md5wrapper();
    string hashedPass;
    BST * bstPointer = new BST();
    SplayTree * splayPointer = new SplayTree();
    CredentialsInserter bstInserter = CredentialsInserter(bstPointer);
    CredentialsInserter splayInserter = CredentialsInserter(splayPointer);

    string insertCredTextFile = "credentials_data.zip";
    string loginSimulatorFile = "variedlogins_input_1to3.7z";

    while(menuSelect!=4)
    {
        string userName;
        string passWord;
        cout << "-----Main Menu-----\n 1. Login\n 2. Register\n 3. Test Logins" << endl;
        cin >> menuSelect;
        switch(menuSelect)
        {
            case 1:
            {
                cout << "Please enter your username: ";
                cin >> userName;
                cout << "\n";
                cout << "Please enter your password: ";
                cin >> passWord;
                hashedPass = passWrapper->getHashFromString(passWord);
                cout << "Please specify which tree to search in:\n 1. BST\n 2. Splay Tree" << endl;
                cin >> treeSpecifier;
                if(treeSpecifier==1)
                {
                    auto t1 = Clock::now();
                    if (bstInserter.verifyCreds(userName, passWord))
                    {
                        auto t2 = Clock::now();
                        cout << "Account found in BST in " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds." << endl;
                    }
                    else
                    {
                        cout << "Account not found!" << endl;
                    }
                }
                else
                {
                    if(treeSpecifier==2)
                    {
                        auto t1 = Clock::now();
                        if (splayInserter.verifyCreds(userName, passWord))
                        {
                            auto t2 = Clock::now();
                            cout << "Account found in Splay Tree in " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds." << endl;
                        }
                        else
                        {
                            cout << "Invalid credentials!" << endl;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                cout << "Please enter a username: ";
                cin >> userName;
                cout << "\n";
                cout << "Please enter a password: ";
                cin >> passWord;

                cout << "Inserting account into BST and Splay Tree..." << endl;

                bstInserter.insertCreds(userName, passWord);
                splayInserter.insertCreds(userName, passWord);
                break;
            }
            case 3:
            {
                // Insert and time credentials into both trees

                ifstream fileReader;
                string userN;
                string passW;
                string dataHolder;
                fileReader.open(insertCredTextFile, ios::binary);
                auto t1 = Clock::now();
                while(getline(fileReader, dataHolder))
                {
                    stringstream ss(dataHolder);
                    ss >> userN >> passW;
                    bstInserter.insertCreds(userN, passW);
                }
                auto t2 = Clock::now();
                fileReader.close();
                int time = duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
                cout << "Time to generate BST: " << time << endl;

                fileReader.open(insertCredTextFile, ios::binary);
                t1 = Clock::now();
                while(getline(fileReader, dataHolder))
                {
                    stringstream ss(dataHolder);
                    ss >> userN >> passW;
                    splayInserter.insertCreds(userN, passW);
                }
                t2 = Clock::now();
                fileReader.close();
                time = duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
                cout << "Time to generate Splay Tree: " << time << endl;

                fileReader.open(loginSimulatorFile, ios::binary);
                vector<pair<string,string>> accounts;
                while(getline(fileReader, dataHolder))
                {
                    stringstream ss(dataHolder);
                    ss >> userN >> passW;
                    pair<string, string> account = make_pair(userN, passW);
                    accounts.push_back(account);

                }
                fileReader.close();

                t1 = Clock::now();
                for(unsigned int i = 0; i < accounts.size(); i++)
                {
                    bstInserter.verifyCreds(accounts[i].first, accounts[i].second);
                }
                t2 = Clock::now();
                time = duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
                double averageTime = time / (double) accounts.size();
                cout << "Average login time in BST is " << averageTime << " nanoseconds." << endl;

                t1 = Clock::now();
                for(unsigned int i = 0; i < accounts.size(); i++)
                {
                    splayInserter.verifyCreds(accounts[i].first, accounts[i].second);
                }
                t2 = Clock::now();
                time = duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
                averageTime = time / (double) accounts.size();
                cout << "Average login time in Splay Tree is " << averageTime << " nanoseconds." << endl;
                break;
            }
        }
    }

    delete bstPointer;
    delete splayPointer;
    delete passWrapper;

    return 0;
}