#include	"diplodocus.h"




using namespace diplo;
namespace diplo {
KEY_ID type;
string dbDir;
string srcDir;
Molecules H_neg; 
Molecules H_mod; 
}


int main ( int argc, char *argv[] ) {

  
    diplo::srcDir = "/home/martin/Dropbox/projects.kdv4/datasets/lubm1/";
    diplo::srcDir = "/home/martin/Dropbox/projects.kdv4/datasets/dbpediaHypotheses/";
    diplo::stopwatch_start();

    
    Conductor dipl;
    dipl.LoadData();
    cout << "Loading Time: " << diplo::stopwatch_get() << endl;
    cout << "Memory: " << diplo::memory_usage() << endl;
    
    ////hypothesis
    
  //  <http://www.Department11.University3.edu/GraduateStudent86>	<http://www.Department11.University3.edu>	<http://www.University3.edu>
//<http://www.Department19.University3.edu/GraduateStudent29>	<http://www.Department19.University3.edu>	<http://www.University3.edu>
    
    
//  NOT <http://www.Department11.University3.edu> <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf> <http://www.University3.edu>
//	and 
// MOD <http://www.Department11.University3.edu/GraduateStudent86> <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf> <http://www.Department11.University3.edu>
    
//     {
//       KEY_ID subject = KM.Get("<http://www.Department11.University3.edu>");
//       KEY_ID predicate = KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>");
//       KEY_ID object = KM.Get("<http://www.University3.edu>");
// 
//        H_neg.AddTriple(subject, predicate, object);
//     }
// //     
//     {
//       KEY_ID subject = KM.Get("<http://www.Department11.University3.edu/GraduateStudent86>");
//       KEY_ID predicate = KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>");
//       KEY_ID object = KM.Get("<http://www.Department11.University3.edu>");
// 
//       cout << subject << "\t" << predicate << "\t" <<  object << "\t" << endl;
//       H_neg.AddTriple(subject, predicate, object);
//       object = KM.Get("<http://www.Department19.University3.edu>");
//       
//       cout << subject << "\t" << predicate << "\t" <<  object << "\t" << endl;
//       H_mod.AddTriple(subject, predicate, object);
//     }
//     
    
    ////
    
    
  queries::DBP q;
   diplo::stopwatch_start();
   q.q03();
   //q.q13();
    
//     /////////////////////////////////////////////////////////////////////
//     
//     
//     KEY_ID p1 = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>");
//    KEY_ID o1 = diplo::KM.Get("<http://www.Department0.University0.edu/GraduateCourse0>");
// 
//     KEY_ID p2 = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");
//     KEY_ID o2 = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent>");
//     
//     vector<QueryBGP> graph;
//    
//     {
//         QueryBGP patern;
//         patern.predicate.second = p1;
//         patern.object.second = o1;
// 	patern.subject.first = QF_INDEX;
//         graph.push_back(patern);
//     }
//      {
//         QueryBGP patern;
//         patern.subject.first = QF_PROJECTION;
//         patern.predicate.second = p2;
//         patern.object.second = o2;
//         graph.push_back(patern);
//     }
// 
//     unordered_map<KEY_ID, unordered_set<Molecule*> > results;
//     M.GetMoleculesPO(graph,results);
// 
//     
//     
//     
//     for ( auto r : results ) {
//         KEY_ID p3 = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#publicationAuthor>" );
//         KEY_ID o3 = r.first;
// 
//         //KEY_ID p4 = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");
// cout << "######\t" << r.first << "\t" <<  diplo::KM.Get(r.first) << endl;
//         vector<QueryBGP> graph2;
//         {
//             QueryBGP patern;
// 	   
//             patern.subject.first = QF_PROJECTION;
// 	     patern.subject.first = QF_INDEX;
//             patern.predicate.second = p3;
//             patern.object.second = o3;
//             graph2.push_back ( patern );
//         }
// 
// 
//         unordered_map<KEY_ID, unordered_set<Molecule*> > results2;
//         M.GetMoleculesPO ( graph2,results2 );
//     }
//     /////////////////////////////////////////////////////////////////////
//     
//     
//     
//     
    
    
    
    return 0;
}


void diplo::stopwatch_start() {
    gettimeofday ( &diplo::stopwatch,0 );
}
double diplo::stopwatch_get() {
    timeval tmp;
    gettimeofday ( &tmp,0 );
    return ( tmp.tv_sec - diplo::stopwatch.tv_sec ) + ( tmp.tv_usec - diplo::stopwatch.tv_usec ) /1000000.0;
}

string diplo::memory_usage() {
    string l;
    ifstream my ( "/proc/self/status" );
    if ( my.is_open() ) {
        while ( getline ( my, l ) ) {
            if ( l.find ( "VmSize:" ) != string::npos ) {
                return l;
            }
        }
        my.close();
    }
    return "no data";
}

void diplo::dictionatyTest ( const char * file ) { //dictionary testing
    ifstream f ( file );
    string line;
    diplo::stopwatch_start();
    while ( getline ( f, line ) ) {
        diplo::KM.Add ( line.c_str() );
    }
    cout << "Loading Time: " << diplo::stopwatch_get() << endl;
    cout << "Memory: " << diplo::memory_usage() << endl;
}

