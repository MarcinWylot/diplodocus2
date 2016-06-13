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



using namespace std;

//functions
void *DiploMalloc(size_t size);
void ExtractTripleFromLine(const string& str, vector<string>& tokens);
void tokenize(const string& str,const string& delimiters, vector<string>& tokens);
void tokenize2(const string& str,const string& delimiters, vector<string>& tokens);

long double getDuble(const string& str);




/// proper types definitions
typedef unsigned long int TYPE_ID;
typedef	unsigned long int KEY_ID;
#define MASK 16
#define BASE 64

//typedef	unsigned int KEY_ID;
//#define MASK 8
//#define BASE 32

#define PredMask 0x8000000000000000 //for inferted graphs we set MSB to 1


//#define IFEXITERROR                                                     if(Constante::ExitIfError){exit(0);};
//#define PRINT_ERROR                                                     false
#define ERROR_OUT {cerr << endl << "ERROR in " << __FILE__ << " at line " << __LINE__ << endl;}

//#define PRINT_NO_RESULTS {cout << endl << "results.size(): " << results.size() << endl;}
#define PRINT_NO_RESULTS {}

//#define PRINT_CLIENT_TIME {data[3] = '\0'; cout << data << "\t" << diplo::stopwatch_get() << endl;}
#define PRINT_CLIENT_TIME {}


typedef unordered_set<KEY_ID> O_l; // list of objects
typedef unordered_map< KEY_ID, O_l > P_l; //list of predicates and co-located objects
typedef unordered_map<KEY_ID, P_l > S_l; //list of subjects and co-located p_l
typedef unordered_map< KEY_ID, unordered_set<KEY_ID> > OM_l; //list of objects and their molecules

namespace queries {

class val4 {
public:
    KEY_ID v1;
    KEY_ID v2;
    KEY_ID v3;
    KEY_ID v4;
};

class val5 {
public:
    KEY_ID v1;
    KEY_ID v2;
    KEY_ID v3;
    KEY_ID v4;
    KEY_ID v5;
};

}

class QueryGraph {
public:
    short int operation;
    pair <short int, KEY_ID> subject;
    pair <short int, KEY_ID> predicate;
    pair <short int, KEY_ID> object;
    vector<QueryGraph> next;
    QueryGraph() {
        subject.first = 0;
        predicate.first=0;
        object.first=0;
        subject.second = 0;
        predicate.second=0;
        object.second=0;
        operation=0;
    }
//	TripleIDs(KEY_ID s,KEY_ID p,KEY_ID o,KEY_ID pr) {subject = s;predicate=p; object=o;}
};


namespace diplo {
extern string server_adr;
extern string server_port;
extern unsigned myID;
extern unsigned nbOfClients;
extern void usage(const char * msg);
extern bool onlyPartition;
extern int maxScope;
extern int minScope;
extern void stopwatch_start();
extern double stopwatch_get();
extern string memory_usage();
extern void dictionatyTest(const char * file);
extern timeval stopwatch;
extern string moleculeconffile;
extern string dbDir;
extern string srcDir;
extern int pause_int;
extern size_t network_buf_size;
extern int PartitionerRange;

}
#endif /* DIPLODOCUS_H_ */
