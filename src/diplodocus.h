/*
 * diplodocus.h
 *
 *  Created on: 12-07-2012
 *      Author: marcin
 */

#ifndef DIPLODOCUS_H_
#define DIPLODOCUS_H_

//common includes
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include <unistd.h>

#include <sys/time.h>

#include <unordered_set>
#include <unordered_map>
#include <dirent.h>
#include <algorithm>
#include <typeinfo>


using namespace std;

//functions
void tokenize(const string& str,const string& delimiters, vector<string>& tokens);
void tokenize2(const string& str,const string& delimiters, vector<string>& tokens);


/// proper types definitions
typedef	unsigned long int KEY_ID;

//#define PRINT_ERROR                                                     false
#define ERROR_OUT {cerr << "ERROR in " << __FILE__ << " at line " << __LINE__ << endl;}
#define PERF_PROF {cerr << "TIME: " << diplo::stopwatch_get() << "--" << diplo::memory_usage() << " " << "FILE: " << __FILE__ << " LINE: " << __LINE__ << endl;}
//#define PERF_PROF {}

namespace diplo {
extern void dictionatyTest ( const char * file );
extern void stopwatch_start();
extern double stopwatch_get();
extern string memory_usage();
extern timeval stopwatch;
extern string dbDir;
extern string srcDir;

extern KEY_ID type;

}



#define QO_UNION 1
#define QO_NOP 2
#define QO_OO_Join 3

#define QF_PROJECTION 1
#define QF_INDEX 2
class QueryBGP {
public:
    //short int operation;
    pair <short int, KEY_ID> subject;
    pair <short int, KEY_ID> predicate;
    pair <short int, KEY_ID> object;
    QueryBGP() {
        subject.first = 0;
        predicate.first=0;
        object.first=0;
        subject.second = 0;
        predicate.second=0;
        object.second=0;
    }
};

template <typename Iterator>
class iterator_pair
{
public:
    iterator_pair ( Iterator first, Iterator last ) : f_ ( first ), l_ ( last ) {}
    Iterator begin () const { return f_; }
    Iterator end   () const { return l_; }

private:
    Iterator f_;
    Iterator l_;
};

template <typename Iterator>
iterator_pair<Iterator> make_iterator_pair ( Iterator f, Iterator l )
{
    return iterator_pair<Iterator> ( f, l );
}

#include "KeyManager.h"
#include	"Conductor.h"
#include	"LUBM.h"
#include	"DBP.h"

#endif /* DIPLODOCUS_H_ */
