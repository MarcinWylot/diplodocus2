/*
 * API.cpp
 *
 *  Created on: Jul 28, 2013
 *      Author: marcin
 */

#include "API.h"

namespace queries {

API::API() {
    // TODO Auto-generated constructor stub

}

API::~API() {
    // TODO Auto-generated destructor stub
}

void API::TriplePatern(vector<QueryGraph> &graph, unordered_multimap<KEY_ID, vector<KEY_ID> > &results, char index) {
    diplo::stopwatch_start();
    unordered_set<KEY_ID>* molecules=NULL;
    unordered_set<KEY_ID> moleculestmp;
    vector<KEY_ID> resultstmp;

    if (graph[0].subject.second != 0) {
        S_l::iterator m = diplo::M.Get(graph[0].subject.second);
        if (!diplo::M.CheckEndGet(m)) {
            moleculestmp.insert(m->first);
            molecules = &moleculestmp;
        }
    } else if (graph[0].object.second != 0) {
        molecules = diplo::M.GetMoleculesFromInvertedIdx(graph[0].object.second);
    }

    if (molecules== NULL or molecules->empty()) return; // no molecules to investigate

    for (unordered_set<KEY_ID>::iterator it = molecules->begin(); it != molecules->end(); it++) {
        S_l::iterator s = diplo::M.Get(*it);
        //FIXME (if s,p,o == 0 WILDCARD)

        for (size_t i = 0; i < graph.size(); i++) {

            if (graph[i].operation == QO_NOP)
                continue;

            if (graph[i].subject.second != s->first and graph[i].subject.second != 0) {
                goto nextMolecule;
            }

            P_l::iterator p = s->second.find(graph[i].predicate.second);
            if (p == s->second.end() and graph[i].predicate.second != 0) {
                goto nextMolecule;
            }

            O_l::iterator o = p->second.find(graph[i].object.second);
            if (o == p->second.end() and graph[i].object.second != 0) {
                goto nextMolecule;
            }
        }


        //get this molecule
        for (size_t i = 0; i < graph.size(); i++) {
            if (graph[i].subject.first == QF_PROJECTION) {
                if (graph[i].predicate.first == QF_PROJECTION ) {
                    for (P_l::iterator pit = s->second.begin(); pit != s->second.end(); pit++) {
                        if (graph[i].object.first == QF_PROJECTION) {
                            for (O_l::iterator oit = pit->second.begin(); oit != pit->second.end(); oit++) {
                                resultstmp.push_back(s->first);
                                resultstmp.push_back(pit->first);
                                resultstmp.push_back(*oit);
                                if (index == 'o' and i == graph.size()-1) {
                                    results.insert( { *oit, resultstmp });
                                    resultstmp.clear();
                                }
                            }
                        } else {
                            resultstmp.push_back(s->first);
                            resultstmp.push_back(pit->first);
                        }
                        if (index == 'p' and i == graph.size()-1) {
                            results.insert( { pit->first, resultstmp });
                            resultstmp.clear();
                        }
                    }
                } else {
                    if (graph[i].object.first == QF_PROJECTION) {
                        P_l::iterator pit = s->second.find(graph[i].predicate.second); //FIXME for wildcards
                        for (O_l::iterator oit = pit->second.begin(); oit != pit->second.end(); oit++) {
                            resultstmp.push_back(s->first);
                            resultstmp.push_back(*oit);
                            if (index == 'o' and i == graph.size()-1) {
                                results.insert( { *oit, resultstmp });
                                resultstmp.clear();
                            }
                        }
                    } else {
                        resultstmp.push_back(s->first);
                    }
                }
            } else {
                if (graph[i].predicate.first == QF_PROJECTION) {
                    for (P_l::iterator pit = s->second.begin(); pit != s->second.end(); pit++) {
                        if (graph[i].object.first == QF_PROJECTION) {
                            for (O_l::iterator oit = pit->second.begin(); oit != pit->second.end(); oit++) {
                                resultstmp.push_back(pit->first);
                                resultstmp.push_back(*oit);
                                if (index == 'o' and i == graph.size()-1) {
                                    results.insert( { *oit, resultstmp });
                                    resultstmp.clear();
                                }
                            }
                        } else {
                            resultstmp.push_back(pit->first);
                        }
                        if (index == 'p' and i == graph.size()-1) {
                            results.insert( { pit->first, resultstmp });
                            resultstmp.clear();
                        }
                    }
                } else if (graph[i].object.first == QF_PROJECTION) {
                    P_l::iterator pit = s->second.find(graph[i].predicate.second); //FIXME for wildcards
                    for (O_l::iterator oit = pit->second.begin(); oit != pit->second.end(); oit++) {
                        resultstmp.push_back(*oit);
                        if (index == 'o' and i == graph.size()-1) {
                            results.insert( { *oit, resultstmp });
                            resultstmp.clear();
                        }
                    }
                }
            }


        }
        if (index == 's') {
            results.insert( { s->first, resultstmp });
            resultstmp.clear();
        }
nextMolecule:
        ;
    }
    if (index == '0' and !resultstmp.empty() ) {
        results.insert( { 0, resultstmp });
    }

    cerr << "diplo::stopwatch_get(): " << diplo::stopwatch_get() << endl;
    cerr << "results.size(): " << results.size() << endl << endl;
}

void API::TriplePatern_FromTemplates(vector<QueryGraph> &graph, unordered_multimap<KEY_ID, vector<KEY_ID> > &results, char index, char switcher) {
    results.clear();

    diplo::stopwatch_start();
    unordered_set<KEY_ID> mols;

//	unordered_set<unordered_set<KEY_ID>*> result_moleculesOR;
    unordered_set<unordered_set<KEY_ID>*> result_molecules;

    if (switcher == 'P') {
        diplo::TM.GetMoleculesForPredicates(graph, result_molecules);
    }
    
    if (switcher == 'T') {
        diplo::TM.GetMoleculesForPredicatesFromTemplates(graph, result_molecules);
    }


    cerr << "1diplo::stopwatch_get(): " << diplo::stopwatch_get() << endl;
    for (auto & t : graph) {
        if (t.object.second != 0) {
            unordered_set < KEY_ID > *molecules = diplo::M.GetMoleculesFromInvertedIdx(graph[0].object.second);
            result_molecules.insert(molecules);
        }
    }

    cerr << "2diplo::stopwatch_get(): " << diplo::stopwatch_get() << endl;
    unordered_set<KEY_ID>* smallest_molecules_set = NULL;
    size_t smallest_molecules_set_size = 999999999999999999;
    cerr << "result_molecules.size() before: " << result_molecules.size() << endl;


    for (unordered_set<unordered_set<KEY_ID>*>::iterator it = result_molecules.begin(); it != result_molecules.end(); it++) {
//		cerr << *it << " : " << (*it)->size() << endl;
        if ((*it)->size() < smallest_molecules_set_size) {
            smallest_molecules_set_size = (*it)->size();
            smallest_molecules_set = *it;
//			cerr << smallest_molecules_set << "\t" << *it << endl;
        }
    }

    cerr << "3diplo::stopwatch_get(): " << diplo::stopwatch_get() << endl;

    result_molecules.erase(smallest_molecules_set);
    cerr << "smallest_molecules_set->size(): " << smallest_molecules_set->size() << endl;
    cerr << "result_molecules.size() loop: " << result_molecules.size() << endl;
    for (unordered_set<KEY_ID>::iterator it = smallest_molecules_set->begin(); it != smallest_molecules_set->end(); it++) {
        KEY_ID molecule = *it;
        for (unordered_set<unordered_set<KEY_ID>*>::iterator it2 = result_molecules.begin(); it2 != result_molecules.end(); it2++) {
            if ((*it2)->find(*it) == (*it2)->end()) {
                molecule = 0;
                break;
            }
        }
        if (!molecule) continue;

        S_l::iterator s = diplo::M.Get(molecule);
        //FIXME (if s,p,o == 0 WILDCARD)

        for (size_t i = 0; i < graph.size(); i++) {

            if (graph[i].subject.second != s->first and graph[i].subject.second != 0) {
                molecule = 0;
                break;
            }

            P_l::iterator p = s->second.find(graph[i].predicate.second);
            if (p == s->second.end() and graph[i].predicate.second != 0) {
                molecule = 0;
                break;
            }

            O_l::iterator o = p->second.find(graph[i].object.second);
            if (o == p->second.end() and graph[i].object.second != 0) {
                molecule = 0;
                break;
            }
        }

        if (!molecule) continue;

        //if (index == 's') {
        results.insert( { s->first, { } });
        //}


    }


    cerr << "4diplo::stopwatch_get(): " << diplo::stopwatch_get() << endl;
    cerr << "results.size(): " << results.size() << endl;

    for (unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator it_p = results.begin(); it_p != results.end(); it_p++) {
        cerr << diplo::KM.Get(it_p->first) << "[" << it_p->first <<"]" << endl;
    }
    cerr << endl;
//	cerr << "molecules.size(): " << molecules.size() << endl;
//	for (unordered_set<KEY_ID>::iterator it = molecules.begin(); it != molecules.end(); it++) {
//		cerr << diplo::KM.Get(*it) << "[" << *it <<"]" << endl;
//	}

}

void API::DisplayResults(unordered_multimap<KEY_ID, vector<KEY_ID> > &results, short int nb) {
    short int _nb;
    for (unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator it_p = results.begin(); it_p != results.end(); it_p++) {
        _nb = nb;
        for (vector<KEY_ID>::iterator it1 = it_p->second.begin(); it1 != it_p->second.end(); it1++) {
            cout << diplo::KM.Get(*it1) << "[" << *it1 <<"]";
            if (_nb > 1 or nb == 0 ) {
                cout << "\t";
                _nb=_nb-1;
            }
            else {
                cout << endl;
                _nb = nb;
            }
        }
//		cout << endl;
    }
}

//void API::GetSubjects(KEY_ID o, KEY_ID p, unordered_multimap<KEY_ID>& results) {
//	unordered_set<KEY_ID> prov;
//	unordered_set<size_t> tripleTemplates;
//	set<pair<const KEY_ID, Molecule>*>* Molecules_with_O = diplo::M.GetMoleculesFromInvertedIdx(o);
//	if (Molecules_with_O) { // do we have any of this
//		for (set<pair<const KEY_ID, Molecule>*>::iterator it = Molecules_with_O->begin(); it != Molecules_with_O->end(); it++) {
//			tripleTemplates.clear();
//			prov.clear();
//			diplo::TM.GetTemplates(diplo::KM.GetType((*it)->first), p, diplo::KM.GetType(o), 0, &tripleTemplates);
//			if ( (*it)->second.CheckIfEntityExists(&tripleTemplates, o, 0, &prov) ) {  // FIXME get prov
////				if ( prov.size() != 1 ) cerr << "ups " << prov.size() << endl;
//				for (unordered_set<KEY_ID>::iterator it_p = prov.begin(); it_p != prov.end(); it_p++) {
//					results.insert(pair<KEY_ID,KEY_ID>( (*it)->first, *prov.begin() ));
//				}
////				return;
//			}
//		}
//	}
//
//}

void API::GetSubjects(KEY_ID o, KEY_ID p, unordered_set<KEY_ID> &results) {
////	unordered_set<KEY_ID> prov_local;
//	unordered_set<size_t> tripleTemplates;
//	set<pair<const KEY_ID, Molecule>*>* Molecules_with_O = diplo::M.GetMoleculesFromInvertedIdx(o);
//	if (Molecules_with_O) { // do we have any of this
//		for (set<pair<const KEY_ID, Molecule>*>::iterator it = Molecules_with_O->begin(); it != Molecules_with_O->end(); it++) {
//			tripleTemplates.clear();
////			prov.clear();
//			diplo::TM.GetTemplates(diplo::KM.GetType((*it)->first), p, diplo::KM.GetType(o), 0, &tripleTemplates);
//			if ( (*it)->second.CheckIfEntityExists(&tripleTemplates, o, 0) ) {  // FIXME get prov
//
//				results.insert((*it)->first);
////				prov.push_back(prov_local);
////				if ( prov.size() != 1 ) cerr << "ups " << prov.size() << endl;
////				for (unordered_set<diplo::TripleIDs>::iterator it_p = prov.begin(); it_p != prov.end(); it_p++) {
////					results.insert(pair<KEY_ID,diplo::TripleIDs>( (*it)->first, *it_p));
////				}
////				return;
//			}
//		}
//	}

}

void API::GetObjects(KEY_ID s, KEY_ID p, unordered_set<KEY_ID> &results) {
//	Molecule *m = diplo::M.Get(s);
//	unordered_set<size_t> tripleTemplates;
//	if (m) {
//		diplo::TM.GetTemplates(diplo::KM.GetType(s), p, -1, 0, &tripleTemplates);
////		unordered_set<KEY_ID> result4Geo;
////		unordered_set<diplo::TripleIDs> prov;
//		m->GetEntity(&tripleTemplates,s,0,&results);
////		results.insert(unordered_multimap<KEY_ID, diplo::TripleIDs>());
////		cout << "city:\t" << diplo::KM.Get(s) << "\t" << diplo::KM.GetType(s);
////		cerr << "\tOK\t" << results.size() << endl;
////		for (unordered_set<KEY_ID>::iterator it = results.begin(); it != results.end(); it++) {
////			cout << "\t\t---> " << diplo::KM.Get(*it) << endl;
////		}
//	}
}

//void API::DrisplayProvenance(vector<vector<unordered_set<KEY_ID> > >& prov) {
//	cout << endl;
//	for (vector<vector<unordered_set<KEY_ID>>> ::iterator it_p = prov.begin(); it_p != prov.end(); it_p++) {
//		cout << "[ ";
//		for (vector<unordered_set<KEY_ID>>::iterator it = it_p->begin(); it != it_p->end(); it++) {
//			cout << "( ";
//			for (unordered_set<KEY_ID>::iterator it2 = it->begin(); it2 != it->end(); it2++)
//			cout << diplo::KM.Get(*it2) << " + ";
////			cout << *it2 << "+";
//			cout << " ) x ";
//		}
//		cout << " ] + " << endl;
//	}
//	cout << endl;
//}

void API::Join(unordered_multimap<KEY_ID, vector<KEY_ID> > *results1, unordered_multimap<KEY_ID, vector<KEY_ID> > *results2, unordered_multimap<KEY_ID, vector<KEY_ID> > *results) {
    unordered_multimap<KEY_ID, vector<KEY_ID> > *r1;
    unordered_multimap<KEY_ID, vector<KEY_ID> > *r2;


    if (results1->size() <= results2->size()) {
        r1 = results1;
        r2 = results2;
    } else {
        r1 = results2;
        r2 = results1;
    }

    for (unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator it = r1->begin(); it != r1->end(); it++) {
        pair< unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator, unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator > f = r2->equal_range(it->first);
        if (f.first == r2->end() ) {
            //remove it
//			r1->erase(it); //?? not sure if it works
        } else {

            for (unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator it2 = f.first; it2 != f.second; it2++) {
                vector<KEY_ID> tmp;
                tmp.reserve(it->second.size() + it2->second.size());
                tmp.insert(tmp.end(), it->second.begin(), it->second.end());
                tmp.insert(tmp.end(), it2->second.begin(), it2->second.end());
                results->insert(make_pair(it->first,tmp));
            }
        }
    }

}

} /* namespace queries */
