#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include <string>
#include <vector>

using namespace std;

void parse(){
    fstream indata;
    fstream outdata;
    string s_line;
    vector<pair<string,string>> creds;
    //vector<pair<string,string>> varied_creds;

    int num_parsed_lines = 0;

    indata.open("usernameData.txt", ios::in);
    outdata.open("variedlogins.txt", ios::out);

    //while(num_parsed_lines < 100 && getline(indata, s_line)){
    while(getline(indata, s_line)){
        stringstream ss_line(s_line);
        string username;
        string password;

        getline(ss_line, username, '\t');
        getline(ss_line, password);

        creds.push_back(make_pair(username, password));
        num_parsed_lines++;
    }

    unsigned int vsize = creds.size();
    unsigned int numtests = vsize; //this can change to some scalar multiple of vsize if desired

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 random_gen(seed);
    std::normal_distribution<double> normdist(vsize/2, vsize/5); //mean needs to be vsize/2. stdev can change if needed

    for(unsigned int i = 0; i < numtests; i++){
        double unref_index = normdist(random_gen);
        unsigned int ref_index;
        while(unref_index < 0 || unref_index > vsize){ //while value is not in proper range
            unref_index = normdist(random_gen); //generate new values
        }
        ref_index = (unsigned int)unref_index; //truncate the decimals

        //cout<<ref_index<<", ";
        //varied_creds.push_back(creds[ref_index]);
        outdata << creds[ref_index].first << '\t' << creds[ref_index].second << endl;
    }

    indata.close();
    outdata.close();
}


// int main(){
//     parse();
//     return 0;
// }