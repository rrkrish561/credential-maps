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
    // Variable declarations
    typedef high_resolution_clock Clock;
    int menuSelect = 0;
    int treeSpecifier;
    // Wrapper to create md5 hashes
    hashwrapper *passWrapper = new md5wrapper();
    string hashedPass;
    // Creation of BST/Splay Trees
    BST * bstPointer = new BST();
    SplayTree * splayPointer = new SplayTree();
    CredentialsInserter bstInserter = CredentialsInserter(bstPointer);
    CredentialsInserter splayInserter = CredentialsInserter(splayPointer);

    // Files to read data from
    string insertCredTextFile = "credentials_data.zip";
    string loginSimulatorFile = "variedlogins_input_1to3.7z";

    while(menuSelect!=4)
    {
        // Menu initialization
        string userName;
        string passWord;
        cout << "-----Main Menu-----\n 1. Login\n 2. Register\n 3. Test Logins" << endl;
        cin >> menuSelect;
        switch(menuSelect)
        {
            case 1:
            {
                // Reads in user input for username/password
                cout << "Please enter your username: ";
                cin >> userName;
                cout << "\n";
                cout << "Please enter your password: ";
                cin >> passWord;
                // Creates the hashed password
                hashedPass = passWrapper->getHashFromString(passWord);
                cout << "Please specify which tree to search in:\n 1. BST\n 2. Splay Tree" << endl;
                cin >> treeSpecifier;
                // Checks specified tree for the user/pass specified
                if(treeSpecifier==1)
                {
                    auto t1 = Clock::now();
                    if (bstInserter.verifyCreds(userName, passWord))
                    {
                        auto t2 = Clock::now();
                        // Returns the time in nanoseconds if the acount is found
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
                // Second case just takes a user/pass input and inserts into both the BST/Splay trees
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
                cout << "Time to generate BST: " << time << " nanoseconds" << endl;

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
                cout << "Time to generate Splay Tree: " << time << " nanoseconds" << endl;

                // Reads a file of varied logins with different frequencies and puts them into a vector

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

                // Goes through that vector to search through both trees and grabs the average search time in both

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
// Deletion of dynamically stored variables in memory
    delete bstPointer;
    delete splayPointer;
    delete passWrapper;

    return 0;
}