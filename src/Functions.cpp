/*
 * Functions.cpp
 *
 *  Created on: 23-07-2012
 *      Author: marcin
 */

#include	"diplodocus.h"
void tokenize(const string& str,const string& delimiters, vector<string>& tokens)
{
    //SUBJECT
    // skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);
    string s = str.substr(lastPos, pos - lastPos);
    tokens.push_back(s);


    //PREDICATE
    // skip delimiters.  Note the "not_of"
    lastPos = str.find_first_not_of(delimiters, pos);
    // find next "non-delimiter"
    pos = str.find_first_of(delimiters, lastPos);
    s = str.substr(lastPos, pos - lastPos);
    tokens.push_back(s);


    //PREDICATE
    // skip delimiters.  Note the "not_of"
    lastPos = str.find_first_not_of(delimiters, pos);


    pos = str.find_last_of(delimiters);
//	cerr << str.size() << "\t" << pos << "\t" << lastPos << endl;
    s = str.substr(lastPos, pos - lastPos);

    pos = s.find(" <", 1);
    string r = s.substr(0, pos);

    tokens.push_back(r);

    r = s.substr(pos+1, s.size());
    tokens.push_back(r);




    return;
}
void tokenize2(const string& str, const string& delimiters, vector<string>& tokens) {
    // skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        // found a token, add it to the vector.
        string s = str.substr(lastPos, pos - lastPos);
        tokens.push_back(s);

        // skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);

        // find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

