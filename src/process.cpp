#include "process.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cstddef>
#include<cstring>
using namespace std;

Process::Process(string cmd, vector<string> args){
    string command;
    vector<string> arguments;
    this->command = cmd;
    this->arguments = args;
};

Process::Process(const Process& copyMe) {
    command = copyMe.command;
    arguments = copyMe.arguments;
};

Process::~Process(){};

bool Process::compare(const Process &other) {
    bool rtn;
    if(command != other.command) {
        return false;
    }
    if(other.arguments.size() != arguments.size()) {
        return false;
    }
    for(int i = 0; i < other.arguments.size(); i++) {
        if(other.arguments[i] != arguments[i]) {
            return false;
        }
    }
    return true;
};

Process::operator std::string() const { 
    string rtn;
    rtn += "Command: " + command + "\nArguments:\n";
    for(int i = 0; i < arguments.size(); i++) {
        rtn += to_string(i);
        rtn += (": " + arguments[i] + "\n");
    }
    return rtn;
};

std::ostream& operator<<(std::ostream& os, const Process& obj)
{
   os << static_cast<string>(obj);
   return os;
}