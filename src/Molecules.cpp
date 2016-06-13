/*
 * Molecules.cpp
 *
 *  Created on: 02-11-2012
 *      Author: marcin
 */

#include "Molecules.h"

Molecules::Molecules() {
}

void Molecules::AddTriple(KEY_ID s, KEY_ID p, KEY_ID o) {
    S_l::iterator molecule = molecules.find(s);
    if (molecule != molecules.end() ) {
        P_l::iterator predicate =  molecule->second.find(p);
        if (predicate != molecule->second.end() ) {
            predicate->second.insert(o);
        } else {
            molecule->second.insert( {p, O_l{o} });
        }
    } else {
        molecules.insert( {{ s, P_l{{p, O_l{o}}} }} );
    }

    OM_l::iterator molecs = inv_molecules.find(o);
    if (molecs == inv_molecules.end() ) {
        inv_molecules.insert( {o, {s}} );
    } else {
        molecs->second.insert(s);
    }
}

void Molecules::AddTriple2(KEY_ID s, KEY_ID p, KEY_ID o) {
	S_l::iterator molecule = molecules.find(s);
	if (molecule != molecules.end() ) {
		P_l::iterator predicate =  molecule->second.find(p);
		if (predicate != molecule->second.end() ) {
			predicate->second.insert(o);
		} else {
			molecule->second.insert( {p, O_l{o} });
		}
	} else {
		molecules.insert( {{ s, P_l{{p, O_l{o}}} }} );
	}
	
}

void Molecules::Display() {
    for (S_l::iterator it = molecules.begin(); it != molecules.end(); it++) {
        cout << diplo::KM.Get(it->first) << " [" << it->first << "]" <<  "\t #P: " << it->second.size() << endl;
        for (P_l::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << "--" << diplo::KM.Get(it2->first) << "[" << it2->first << "]" <<  "\t #O: " << it2->second.size() << endl;
            for (O_l::iterator it3 = it2->second.begin(); it3 != it2->second.end(); it3++) {
                cout << "----" << diplo::KM.Get(*it3) << "[" << *it3 << "]" << endl;
            }
        }
    }
    cout << endl << "#molecule:" << molecules.size() << endl;
}
void Molecules::Display(KEY_ID molecule) {
    S_l::iterator it = molecules.find(molecule);
    cout << diplo::KM.Get(it->first) << " [" << it->first << "]" << "\t #P: " << it->second.size() << endl;
    for (P_l::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
        cout << "--" << diplo::KM.Get(it2->first) << "[" << it2->first << "]" << "\t #O: " << it2->second.size() << endl;
        for (O_l::iterator it3 = it2->second.begin(); it3 != it2->second.end(); it3++) {
            cout << "----" << diplo::KM.Get(*it3) << "[" << *it3 << "]" << endl;
        }
    }
}

S_l::iterator Molecules::Get(KEY_ID s) {
    S_l::iterator molecule = molecules.find(s);
    if (molecule != molecules.end())
        return molecule;

//	ERROR_OUT
    return molecule;
}
bool Molecules::CheckEndGet(S_l::iterator m) {
    if (m != molecules.end()) return false;
    else return true;
}

unordered_set<KEY_ID>* Molecules::GetMoleculesFromInvertedIdx(KEY_ID o) {
    OM_l::iterator molecs = inv_molecules.find(o);
    if (molecs != inv_molecules.end())
        return &(molecs->second);

//	ERROR_OUT
    return NULL;
}

//pair<const KEY_ID, Molecule>* Molecules::GetPair(KEY_ID s) {
//	unordered_map<KEY_ID, Molecule>::iterator i;
////	cerr << "molecules.size(): "<< molecules.size() << endl;
//	i = molecules.find(s);
//	if (i != molecules.end())
//		return &(*i);
//	return NULL;
//}
//

//
//bool Molecules::IsItMyObject(KEY_ID s) {
//	if ( molecules.find(s) != molecules.end() ) return true;
//	return false;
//}

Molecules::~Molecules() {
    // TODO Auto-generated destructor stub
}



