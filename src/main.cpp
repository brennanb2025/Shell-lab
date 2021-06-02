#include<iostream>
#include <unistd.h>
#include <cstdlib>
#include <signal.h>
#include "parser.h"
#include "process.h"
using namespace std;

void signal_callback_handler(int signum) { //handling ctrl+c
   cout <<  "Shell  Exiting..." << endl;
   // Terminate program
   exit(signum);
}

// C++ Program begins execution here
int main( int argc, char* argv[] ){
    signal(SIGINT, signal_callback_handler);
    string line;
    vector<Process*> procVec;
    cout << '>';
    while(getline(cin, line)) { //go until ctrl+d
        try {
            procVec = convert_processes(line);
            for(int j = 0; j < procVec.size(); j++) {
                cout << "Process " << j << "\n" << *procVec[j] << endl;
            }
        } catch(const char* msg) {
            cerr << msg << endl;
        }
        procVec.clear();
        cout << '>';
    }
    return 0;
}
