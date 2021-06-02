#include "process.h"
#include<iostream>
#include<string>
#include<cstring>
#include<cstddef>
#include<cstring>
#include<vector>
using namespace std;

vector<Process*> convert_processes( string s ) {
    vector<Process*> v;
    string commandName;
    int i = 0;
    int prevEnd = 0;
    bool ended;
    bool found;
    while(i < s.length()) {
        while(s[i] == ' ') { //skip all the spaces in between text
            i++;
            prevEnd = i;
        }
        found = false;
        ended = false;
        //command name comes first
        for(; i < s.length(); i++) {
            if(s[i] == ' ' || s[i] == '|' || s[i] == '<' || s[i] == '>') {
                found = true;
                if(s[i] == '|' || s[i] == '<' || s[i] == '>') {
                    ended = true;
                }
                commandName = s.substr(prevEnd,(i-prevEnd));
                i++;
                prevEnd = i;
                break;
            }
        }
        if(i == s.length() && !found) { //if end of line, save cmd
            commandName = s.substr(prevEnd,s.length());
            ended = true;
        }
        while(s[i] == ' ') { //skip all the spaces in between text
            i++;
            prevEnd = i;
            if(i == s.length()) {
                ended = true;
            }
        }
        if(s[i] == '|' || s[i] == '<' || s[i] == '>') {
            ended = true;
            i++;
            prevEnd = i;
        }
        while(s[i] == ' ') { //skip all the spaces in between text
            i++;
            prevEnd = i;
            if(i == s.length()) {
                ended = true;
            }
        }

        //arguments next
        vector<string> args;
        found = false;
        bool onSingleQuote = false;
        bool onDoubleQuote = false;
        if(!ended) {
            for(; i < s.length(); i++) {
                if(s[i] == '\"') { //double quote
                    onDoubleQuote = !onDoubleQuote;
                }
                if(s[i] == '\'') {
                    onSingleQuote = !onSingleQuote;
                }
                
                if(!onDoubleQuote && !onSingleQuote && (s[i] == ' ' || s[i] == '|' || s[i] == '<' || s[i] == '>')) { //argument list ended
                    args.push_back(s.substr(prevEnd,(i-prevEnd)));
                    prevEnd = i+1;
                    if(s[i] == '|' || s[i] == '<' || s[i] == '>') {
                        i++;
                        found = true;
                        break;
                    } else {
                        while(s[i] == ' ') { //skip all the spaces in between text
                            i++;
                            prevEnd = i;
                            if(i == s.length()) {
                                found = true;
                                break;
                            }
                        }
                        if(s[i] == '|' || s[i] == '<' || s[i] == '>') {
                            i++;
                            prevEnd = i;
                            found = true;
                            break;
                        }
                        i--; //ensure don't skip character
                    }
                }
            }
            if(onDoubleQuote || onSingleQuote) { //unmatched quotes
                throw "Exception: mismatched quotes";
            }
            if(i == s.length() && !found) { //if end of line, save cmd
                args.push_back(s.substr(prevEnd,s.length()));
            }
        }
        for(int j=0; j < args.size(); j++) { //go thru and remove quotes on args
            if(args[j][0] == '\"' || args[j][0] == '\'') {
                args[j] = args[j].substr(1,args[j].length()-2);
            }
        }
        Process *p = new Process(commandName, args);
        v.push_back(p);
    }
    return v;
}