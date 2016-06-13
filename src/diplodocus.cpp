//============================================================================
// Name        : diplodocus.cpp
// Author      : marcin
// Version     : 2.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include	"diplodocus.h"
#include	"Conductor.h"
#include	"ConductorNode.h"

#include	"LUBM.h"
#include	"DBP.h"
//#include	"LUBMnetwork.h"
//#include	"DBPnetwork.h"
//#include	"PageManager.h"

//#include	"BTCprov.h"
//#include	"WDCqueries.h"





using namespace diplo;
namespace diplo {
string server_adr;
string server_port;
unsigned myID;
unsigned nbOfClients;
bool onlyPartition;
int maxScope;
int minScope;
string moleculeconffile;
string dbDir;
string srcDir;
int pause_int;
size_t network_buf_size;
int PartitionerRange;
}

void ch(const int& a) {
cout << a << endl;
}

int main(int argc, char *argv[]) {

// dictionary testing
//diplo::dictionatyTest("/home/marcin/URIs_datasets/DS1_LUBM800");return 0;

  
    char hostname[128];
    bzero(hostname,128);
    gethostname(hostname, 128);

    string fn = argv[0];
    diplo::server_port = "9999";
    diplo::onlyPartition = false;
    diplo::nbOfClients = 1;
    diplo::moleculeconffile = "/home/marcin/workspace/diplodocus2/src/MoleculeTemplates.conf";
    diplo::dbDir = "/home/marcin/tmp/dbDiplo/";
    diplo::pause_int = 0;
    diplo::maxScope = 4;
    diplo::minScope = 1;
    diplo::network_buf_size = 56;
    diplo::PartitionerRange = 1;
    diplo::server_adr = "localhost";

    
		
		//queries::LUBM q;
		//q.run("/home/marcin/Dropbox/projects.kdv4/datasets/lubm1/");
		//     diplo::srcDir = "/home/marcin/100nt2/";
		
		
		queries::DBP q;
//		q.run("/home/marcin/Dropbox/projects.kdv4/datasets/dbpedia_Preds/");
 		q.run("/home/marcin/dbpedia/subset2/");
 
    return 0;
}


void diplo::stopwatch_start() {
    gettimeofday(&diplo::stopwatch,0);
}
double diplo::stopwatch_get() {
    timeval tmp;
    gettimeofday(&tmp,0);
    return (tmp.tv_sec - diplo::stopwatch.tv_sec) + (tmp.tv_usec - diplo::stopwatch.tv_usec)/1000000.0;
}

string diplo::memory_usage() {
    string l;
    ifstream my("/proc/self/status");
    if (my.is_open()) {
        while (getline(my, l)) {
            if (l.find("VmSize:") != string::npos) {
                return l;
            }
        }
        my.close();
    }
    return "no data";
}

void diplo::dictionatyTest(const char * file) {//dictionary testing
    ifstream f(file);
    string line;
    diplo::stopwatch_start();
    while (getline(f, line)) {
        diplo::KM.Add(line.c_str());
    }
    cout << "Loading Time: " << diplo::stopwatch_get() << endl;
    cout << "Memory: " << diplo::memory_usage() << endl;
}

