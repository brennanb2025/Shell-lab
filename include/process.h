#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <vector>
#include <string>

using namespace std;

class Process{
public:
    Process(string cmd, vector<string> args);
    ~Process();
    Process(const Process &copyMe);
    operator std::string() const;
    bool compare(const Process &other);
    friend std::ostream& operator<<(std::ostream&, const Process&);
private:
    string command;
    vector<string> arguments;
};

#endif
