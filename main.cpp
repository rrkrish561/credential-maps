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
    BST * bstPointer = new BST();
    SplayTree * splayPointer = new SplayTree();
    CredentialsInserter bstInserter = CredentialsInserter(bstPointer);
    CredentialsInserter splayInserter = CredentialsInserter(splayPointer);

    string insertCredTextFile = "usernameData_100k.txt";
    string loginSimulatorFile = "variedlogins_100k_1to3.txt";

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
                ifstream fileReader;
                string dataHolder;
                vector<pair<string,string>> accounts, logins;
                auto t1 = Clock::now();
                auto t2 = Clock::now();
                
                //read account data from file and put it into a vector
                fileReader.open(insertCredTextFile, ios::binary);
                while(getline(fileReader, dataHolder)) 
                {
                    stringstream ss(dataHolder);
                    string userN, passW;
                    ss >> userN >> passW;
                    accounts.push_back(make_pair(userN,passW));
                }
                fileReader.close();

                //insert account data into BST and check time
                t1 = Clock::now();
                for(unsigned int i = 0; i < accounts.size(); i++)
                {
                    bstInserter.insertCreds(accounts[i].first, accounts[i].second);
                }
                t2 = Clock::now();
                int time = duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
                cout << "Time to generate BST: " << time << " nanoseconds." <<endl;

                //insert account data into SplayTree and check time
                t1 = Clock::now();
                for(unsigned int i = 0; i < accounts.size(); i++)
                {
                    splayInserter.insertCreds(accounts[i].first, accounts[i].second);
                }
                t2 = Clock::now();
                time = duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
                cout << "Time to generate Splay Tree: " << time << " nanoseconds." << endl;

                
                //read simulated logins from file and put it into a vector
                fileReader.open(loginSimulatorFile, ios::binary);
                while(getline(fileReader, dataHolder))
                {
                    stringstream ss(dataHolder);
                    string userN, passW;
                    ss >> userN >> passW;
                    logins.push_back(make_pair(userN, passW));

                }
                fileReader.close();

                //search for simulated logins in BST and check average time for one user to log in
                t1 = Clock::now();
                for(unsigned int i = 0; i < logins.size(); i++)
                {
                    bstInserter.verifyCreds(logins[i].first, logins[i].second);
                }
                t2 = Clock::now();
                time = duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
                double averageTime = time / (double) logins.size();
                cout << "Average login time in BST is " << averageTime << " nanoseconds." << endl;

                //search for simulated logins in SplayTree and check average time for one user to log in
                t1 = Clock::now();
                for(unsigned int i = 0; i < logins.size(); i++)
                {
                    splayInserter.verifyCreds(logins[i].first, logins[i].second);
                }
                t2 = Clock::now();
                time = duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
                averageTime = time / (double) logins.size();
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