/*
 * Conductor.cpp
 *
 *  Created on: 19-11-2012
 *      Author: marcin
 */

#include "Conductor.h"

namespace diplo {
KeyManager2 KM;
class TypesHierarchy TH;
class TemplateManager TM;
class Molecules M;
class Partitioner P;
TypesManager TypesM;
//Server SRV;
Client CLI;
timeval stopwatch;
}

using namespace diplo;

Conductor::Conductor() {
    // TODO Auto-generated constructor stub

}

void Conductor::LoadData() {
    DIR* dir = opendir(srcDir.c_str());
    vector<string> files;
    KEY_ID predicateType = 0;
    KEY_ID predicatesubClassOf = 0;

    struct dirent* pos = 0;
    while ((pos = readdir(dir))) {
        string file = pos->d_name;
        if (file != "." and file != ".." and file.size() >= 1 and file[0] != '.'
                and (0
                     or file.compare(file.size() - 3, 3, ".nt") == 0 or file.compare(file.size() - 3, 3, ".nq") == 0
                     or file.compare(file.size() - 8, 8, "-urified") == 0 or file.compare(file.size() - 8, 8, ".nq.sort") == 0
//						or file.compare(file.size() - 4, 4, "6.nt") == 0
                    ))
            files.push_back(srcDir + "/" + file);
    }

    cout << "first pass" << endl;

//	unordered_multimap<KEY_ID, KEY_ID> oid_type;
    vector<string> triple;
    vector<TripleIDs> tripleIDs;
    unordered_set<KEY_ID> types;
    unordered_multimap<KEY_ID, KEY_ID> subclesses;

    cout << "KM.Add" << endl;
    for (vector<string>::iterator it = files.begin(); it != files.end(); it++) {
        string line;
        ifstream f(it->c_str());

        while (getline(f, line)) {
            TripleIDs tripleIDsTmp;
            triple.clear();
            tokenize(line, " ", triple);

            tripleIDsTmp.subject = KM.Add(triple[0].c_str());
            tripleIDsTmp.predicate = KM.Add(triple[1].c_str());
            tripleIDsTmp.object = KM.Add(triple[2].c_str());

            tripleIDs.push_back(tripleIDsTmp);

            if (predicateType == 0 or predicatesubClassOf == 0) {
                if (triple[1] == "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>")
                    predicateType = tripleIDsTmp.predicate;
                else if (triple[1] == "<http://www.w3.org/2000/01/rdf-schema#subClassOf>")
                    predicatesubClassOf = tripleIDsTmp.predicate;
            }


            if (tripleIDsTmp.predicate == predicateType) {
//				oid_type.insert(pair<KEY_ID, KEY_ID>(tripleIDsTmp.subject, tripleIDsTmp.object));
                types.insert(tripleIDsTmp.object);
            } else if (tripleIDsTmp.predicate ==predicatesubClassOf) {
                subclesses.insert(pair<KEY_ID, KEY_ID>(tripleIDsTmp.subject, tripleIDsTmp.object));
            }

        }

        f.close();
    }

    cout << "TH.Add" << endl;
    for (unordered_set<KEY_ID>::iterator it = types.begin(); it != types.end(); it++) {
        TH.Add(*it);
    }
    cout << "TH.AddRelation" << endl;
    for (unordered_multimap<KEY_ID, KEY_ID>::iterator it = subclesses.begin(); it != subclesses.end(); it++) {
        TH.AddRelation(it->first, it->second);
    }


    cout << "storing all triples" << endl;
    fstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    size_t s = tripleIDs.size();
    try {
        file.open(diplo::dbDir + "triples", ios::binary | ios::out);
        file.write((char*) &predicateType, sizeof(predicateType));
        file.write((char*) &s, sizeof(s));
        file.write((char*) tripleIDs.data(), s * sizeof(TripleIDs));
        file.close();

    } catch (fstream::failure &e) {
        cerr << "Exception writing file";
    }

    unordered_set<KEY_ID> molecules_tmp;
    cout << "P.PartitionMolecules" << endl;
    for (vector<TripleIDs>::iterator it_tripleIDs = tripleIDs.begin(); it_tripleIDs != tripleIDs.end(); it_tripleIDs++) {
        molecules_tmp.insert(it_tripleIDs->subject);
    }
    cout << "all molecules on master: " << molecules_tmp.size() << endl;
    P.PartitionMolecules(&molecules_tmp);

    P.SendMolecules();
//	TM.Store();
    TH.Store();
    KM.Store();

}

void Conductor::HandleQueriesLUBMnetwork() {
//	diplo::SRV.Start();
//	queries::LUBM_network lubm;

//	diplo::TM.Display();
//	diplo::TH.Display();

//	diplo::stopwatch_start();
//	lubm.q02s1_m();
//	cout << "q02s1_m: " << diplo::stopwatch_get() << endl;
//	diplo::stopwatch_start();
//	lubm.q02s2_m();
//	cout << "q02s2_m: " << diplo::stopwatch_get() << endl;
//	return;

//	vector< vector<double> > times4exel;
//	times4exel.resize(17);
//	double time;
//
//	for (int i = 0; i < 11; i++) {
//		cout << "--------------------- ROUND: " << i << "---------------------" << endl;
//		diplo::stopwatch_start();
//		lubm.q01_m();
//		time = diplo::stopwatch_get();
//		times4exel[0].push_back(time);
//		cout << "q01: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q02s1_m();
//		time = diplo::stopwatch_get();
//		times4exel[1].push_back(time);
//		cout << "q02s1: " << time << endl;
//		sleep(diplo::pause_int);
//
//		if (diplo::maxScope == 1) {
//			diplo::stopwatch_start();
//			lubm.q02s2_m();
//			time = diplo::stopwatch_get();
////				times4exel[0].push_back(time);
//			cout << "q02s2: " << time << endl;
//			sleep(diplo::pause_int);
//		}
//
//		diplo::stopwatch_start();
//		lubm.q03_m();
//		time = diplo::stopwatch_get();
//		times4exel[2].push_back(time);
//		cout << "q03: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q04_m();
//		time = diplo::stopwatch_get();
//		times4exel[3].push_back(time);
//		cout << "q04: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q05_m();
//		time = diplo::stopwatch_get();
//		times4exel[4].push_back(time);
//		cout << "q05: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q06_m();
//		time = diplo::stopwatch_get();
//		times4exel[5].push_back(time);
//		cout << "q06: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q07_m();
//		time = diplo::stopwatch_get();
//		times4exel[6].push_back(time);
//		cout << "q07: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q08s1_m();
//		time = diplo::stopwatch_get();
//		times4exel[7].push_back(time);
//		cout << "q08s1: " << time << endl;
//		sleep(diplo::pause_int);
//
//		if (diplo::maxScope == 1) {
//			diplo::stopwatch_start();
//			lubm.q08s2_m();
//			time = diplo::stopwatch_get();
////				times4exel[0].push_back(time);
//			cout << "q08s2: " << time << endl;
//			sleep(diplo::pause_int);
//		}
//
//		diplo::stopwatch_start();
//		lubm.q09s1_m();
//		time = diplo::stopwatch_get();
//		times4exel[8].push_back(time);
//		cout << "q09s1: " << time << endl;
//		sleep(diplo::pause_int);
//
//		if (diplo::maxScope == 1) {
//			diplo::stopwatch_start();
//			lubm.q09s2_m();
//			time = diplo::stopwatch_get();
////				times4exel[0].push_back(time);
//			cout << "q09s2: " << time << endl;
//			sleep(diplo::pause_int);
//		}
//		diplo::stopwatch_start();
//		lubm.q10_m();
//		time = diplo::stopwatch_get();
//		times4exel[9].push_back(time);
//		cout << "q10: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q11s1_m();
//		time = diplo::stopwatch_get();
//		times4exel[10].push_back(time);
//		cout << "q11s1: " << time << endl;
//		sleep(diplo::pause_int);
//
//		if (diplo::maxScope == 1) {
//			diplo::stopwatch_start();
//			lubm.q11s2_m();
//			time = diplo::stopwatch_get();
////				times4exel[0].push_back(time);
//			cout << "q11s2: " << time << endl;
//			sleep(diplo::pause_int);
//		}
//
//		diplo::stopwatch_start();
//		lubm.q12_m();
//		time = diplo::stopwatch_get();
//		times4exel[11].push_back(time);
//		cout << "q12: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q13_m();
//		time = diplo::stopwatch_get();
//		times4exel[12].push_back(time);
//		cout << "q13: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q14_m();
//		time = diplo::stopwatch_get();
//		times4exel[13].push_back(time);
//		cout << "q14: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q15_m();
//		time = diplo::stopwatch_get();
//		times4exel[14].push_back(time);
//		cout << "q15: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		lubm.q16s1_m();
//		time = diplo::stopwatch_get();
//		times4exel[15].push_back(time);
//		cout << "q16s1: " << time << endl;
//		sleep(diplo::pause_int);
//
//		if (diplo::maxScope == 1) {
//			diplo::stopwatch_start();
//			lubm.q16s2_m();
//			time = diplo::stopwatch_get();
////				times4exel[0].push_back(time);
//			cout << "q16s2: " << time << endl;
//			sleep(diplo::pause_int);
//		}
//
//		diplo::stopwatch_start();
//		lubm.q17_m();
//		time = diplo::stopwatch_get();
//		times4exel[16].push_back(time);
//		cout << "q17: " << time << endl;
//		sleep(diplo::pause_int);
//	}
//
//
//	/////printing for exel
//	{
//		cout << endl << endl;
//		for (vector<vector<double> >::iterator q = times4exel.begin(); q != times4exel.end(); q++) {
//			for (size_t r = 0; r < q->size(); r++) {
//				string n = to_string( (*q)[r] );
//				replace(n.begin(), n.end(),'.',',');
//				cout << n << "\t";
//			}
//			cout << endl;
//		}
//	}

}

void Conductor::HandleQueriesDBPnetwork() {
//	diplo::SRV.Start();
//	queries::LUBM_network lubm; //FIXME why without this line it breaks????????
//
//	queries::DBP_network dbp;
//
//	vector< vector<double> > times4exel;
//	times4exel.resize(5);
//	double time;
//
//	for (int i = 0; i < 11; i++) {
//		cout << "--------------------- ROUND: " << i << "---------------------" << endl;
//		diplo::stopwatch_start();
//		dbp.q01_m();
//		time = diplo::stopwatch_get();
//		times4exel[0].push_back(time);
//		cout << "q01: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		dbp.q02_m();
//		time = diplo::stopwatch_get();
//		times4exel[1].push_back(time);
//		cout << "q02: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		dbp.q03_m();
//		time = diplo::stopwatch_get();
//		times4exel[2].push_back(time);
//		cout << "q03: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		dbp.q04_m();
//		time = diplo::stopwatch_get();
//		times4exel[3].push_back(time);
//		cout << "q04: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		dbp.q05_m();
//		time = diplo::stopwatch_get();
//		times4exel[4].push_back(time);
//		cout << "q05: " << time << endl;
//		sleep(diplo::pause_int);
//	}
//
//
//	/////printing for exel
//	{
//		cout << endl << endl;
//		for (vector<vector<double> >::iterator q = times4exel.begin(); q != times4exel.end(); q++) {
//			for (size_t r = 0; r < q->size(); r++) {
//				string n = to_string((*q)[r]);
//				replace(n.begin(), n.end(), '.', ',');
//				cout << n << "\t";
//			}
//			cout << endl;
//		}
//	}

}

void Conductor::StoreDataForGraphPartitioning() {
    vector<string> files;

    {
        DIR* dir = opendir(srcDir.c_str());
        string file;
        struct dirent* pos = 0;
        while ((pos = readdir(dir))) {
            file = pos->d_name;
            if (file != "." and file != ".." and file.size() >= 1 and file[0] != '.'
                    and (file.compare(file.size() - 3, 3, ".nt") == 0 or file.compare(file.size() - 3, 3, ".nq") == 0
//							or file.compare(file.size() - 8, 8, "-urified") == 0 or file.compare(file.size() - 8, 8, ".nq.sort") == 0
                         //						or file.compare(file.size() - 4, 4, ".ntX") == 0
                        ))
                files.push_back(srcDir + "/" + file);
        }
    }

    {
        ifstream f;
        f.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        string line;
        vector<string> triple;
        TripleIDs tripleIDsTmp;
        vector<TripleIDs> tripleIDs;

        for (vector<string>::iterator it = files.begin(); it != files.end(); it++) {
            f.open(it->c_str());

            while (getline(f, line)) {
                triple.clear();
                tokenize(line, " ", triple);

                tripleIDsTmp.subject = KM.Add(triple[0].c_str());
                tripleIDsTmp.predicate = KM.Add(triple[1].c_str());
                tripleIDsTmp.object = KM.Add(triple[2].c_str());

                tripleIDs.push_back(tripleIDsTmp);
            }

            f.close();
        }

        KM.Store();

        fstream file;
        size_t s = tripleIDs.size();
        try {
            file.open(diplo::dbDir + "triples", ios::binary | ios::out);
            file.write((char*) &s, sizeof(s));
            file.write((char*) tripleIDs.data(), s * sizeof(TripleIDs));
            file.close();

        } catch (fstream::failure &e) {
            cerr << "Exception writing file";
        }
    }
}

void Conductor::RestoreDataForGraphPartitioning() {
    fstream file;
    file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    string prefix = "partitioned_graphs/10U_1everywhere_triples.";
    int nbPart = 4;
    size_t s;
    vector<TripleIDs> triples;

    diplo::KM.Restore();

    for (int i = 0; i < nbPart; i++) {
        triples.clear();
        try {
            file.open(diplo::dbDir + prefix + to_string(i), ios::binary | ios::in);
            file.read((char*) &s, sizeof(s));
            triples.resize(s);

            file.read((char*) triples.data(), s * sizeof(TripleIDs));
            file.close();


            file.open(diplo::dbDir + prefix + to_string(i) + ".nt", ios::out);
            for (vector<TripleIDs>::iterator it = triples.begin(); it != triples.end(); it++) {
                file << *it;
            }
            file.close();


        } catch (fstream::failure &e) {
            cerr << "Exception reading/writing file" << endl;
        }

    }


}

Conductor::~Conductor() {
    // TODO Auto-generated destructor stub
}
