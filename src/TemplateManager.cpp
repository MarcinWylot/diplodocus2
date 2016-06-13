/*
 * TemplateManager.cpp
 *
 *  Created on: 08-10-2012
 *      Author: marcin
 */

#include "TemplateManager.h"

TemplateManager::TemplateManager() {
}

//void TemplateManager::AddTemplate(TripleTemplate triple) {
//	static KEY_ID autoinct_id = 1; //Template ID starts from 1
//
//	//check if there is already template for this root
//	pair<unordered_multimap< KEY_ID, KEY_ID>::iterator, unordered_multimap< KEY_ID, KEY_ID>::iterator> templat = RootTemplateIdx.equal_range(triple.subjectType);
//
//	if (templat.first != RootTemplateIdx.end()) {
//		for (unordered_multimap<KEY_ID, KEY_ID>::iterator it = templat.first; it != templat.second; it++) {
//			unordered_map<KEY_ID, set<TripleTemplate> >::iterator it_templates = templates.find(it->second);
//			triple.ID = it_templates->second.size() + 1;
//			it_templates->second.insert(triple);
//		}
//	} else {
//		set<TripleTemplate> tmp;
//		triple.ID = 1;
//		tmp.insert(triple);
//		templates.insert(pair<KEY_ID, set<TripleTemplate> >(autoinct_id, tmp));
//
//		RootTemplateIdx.insert(pair<KEY_ID,KEY_ID>(triple.subjectType, autoinct_id) );
//		TemplateRootIdx.insert(pair<KEY_ID,KEY_ID>(autoinct_id, triple.subjectType) );
//		autoinct_id++;
//	}
//}
//
//
void TemplateManager::AddTriple(KEY_ID subjectType, KEY_ID predicate, KEY_ID objectType, KEY_ID moleculeID) {
//     static KEY_ID autoinct_id = 1; //TemplateID starts from 1
//     KEY_ID templateID = 0; //need this for predicate index
//     unordered_map< KEY_ID, KEY_ID>::iterator it_templates;
// 
//     it_templates = RootTemplateIdx.find(subjectType);
//     if (it_templates != RootTemplateIdx.end() ) {
//         templateID = it_templates->second;
//         //add triple to existing template
//         unordered_map<KEY_ID, S_l>::iterator itT = templates.find(it_templates->second);
//         if (itT != templates.end() ) {
//             S_l::iterator itS = itT->second.find(subjectType);
//             if (itS != itT->second.end() ) {
//                 P_l::iterator itP = itS->second.find(predicate);
//                 if (itP != itS->second.end() ) {
//                     O_l::iterator itO = itP->second.find(predicate);
//                     if (itO != itP->second.end() ) {
//                         // NOTHING, it is already there,
//                         TemplateMolecules.find(it_templates->second)->second.insert(moleculeID);
//                         //MAYBE add only molecyle????
//                     } else {
//                         //add object
//                         itP->second.insert(objectType);
//                         TemplateMolecules.find(it_templates->second)->second.insert(moleculeID);
//                     }
//                 } else {
//                     //add predicate and object
//                     itS->second.insert( {{predicate,{objectType}}});
//                     TemplateMolecules.find(it_templates->second)->second.insert(moleculeID);
//                 }
//             } else {
//                 //well, probably never happen
//                 ERROR_OUT
//             }
//         } else {
//             //well, probably never happen
//             ERROR_OUT
//         }
//     } else {
//         //create a new template
//         templates.insert( {{autoinct_id, { {subjectType,{{predicate,{objectType}}} } } }});
//         RootTemplateIdx.insert( {{subjectType,{autoinct_id}}});
//         TemplateMolecules.insert( {{autoinct_id,{{moleculeID}}}});
//         NaturaltemplateMaxID = autoinct_id;
//         templateID = autoinct_id;
//         autoinct_id++;
//     }
// 
// 
// 
//     //predicate index
//     unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it_PredicateIndex = PredicateTemplates.find(predicate);
//     if (it_PredicateIndex == PredicateTemplates.end()) {
//         PredicateTemplates.insert( {predicate,{templateID}});
//     } else {
//         it_PredicateIndex->second.insert(templateID);
//     }


}
//
//void TemplateManager::AddTripleInScope(TripleTemplate triple, KEY_ID root, unsigned short int scope) {
//
//	pair<unordered_multimap< KEY_ID, KEY_ID>::iterator, unordered_multimap< KEY_ID, KEY_ID>::iterator> templat = RootTemplateIdx.equal_range(root);
//
//	for (unordered_multimap<KEY_ID, KEY_ID>::iterator it = templat.first; it != templat.second; it++) {
//
//		unordered_map<KEY_ID, set<TripleTemplate> >::iterator it_templates = templates.find(it->second);
//		set<TripleTemplate>::iterator it_triples;
//
//		if (it_templates != templates.end()) {
//			for (it_triples = it_templates->second.begin(); it_triples != it_templates->second.end(); it_triples++) {
//				if (it_triples->scope == scope - 1 and it_triples->objectType == triple.subjectType) {
//					triple.scope = scope;
//					triple.ID = it_templates->second.size() + 1;
//					it_templates->second.insert(triple);
//				}
//			}
//		}
//	}
//}
//
//void TemplateManager::GetTemplates(KEY_ID s, KEY_ID p, KEY_ID o, unsigned short int scope, unordered_multimap<KEY_ID, KEY_ID>* result_templates) {
////FIXME, maybe create an index which opjectTypes and predicated are where and then do the search, should be cheap for memory
//	unordered_map< KEY_ID, set<TripleTemplate> >::iterator it_templates;
//	set<TripleTemplate>::iterator it_triple;
//
//	TripleTemplate tmp;
//	tmp.subjectType = s;
//	tmp.predicateID = p;
//	tmp.objectType = o;
//	tmp.scope = scope;
//
//	if (s != 0 and o != 0 and p!= 0) { //FIXME, this is kinda hack, should find better way for wildcards
//		if (scope == 0 and s != 0) {
//			pair<unordered_multimap< KEY_ID, KEY_ID>::iterator, unordered_multimap< KEY_ID, KEY_ID>::iterator> templat = RootTemplateIdx.equal_range(s);
//			for (unordered_multimap<KEY_ID, KEY_ID>::iterator it = templat.first; it != templat.second; it++) {
//				unordered_map<KEY_ID, set<TripleTemplate> >::iterator it_templates = templates.find(it->second);
//				if (it_templates != templates.end()) {
//					it_triple = it_templates->second.find(tmp);
//					if (it_triple != it_templates->second.end()) {
//						result_templates->insert(pair<KEY_ID, KEY_ID>(it_templates->first, it_triple->ID));
//					}
//				}
//			}
//		} else {
//			for (it_templates = templates.begin(); it_templates != templates.end(); it_templates++) {
//				it_triple = it_templates->second.find(tmp);
//				if (it_triple != it_templates->second.end()) {
//					result_templates->insert(pair<KEY_ID, KEY_ID>(it_templates->first, it_triple->ID));
//				}
//			}
//		}
//	} else {
//		//FIXME this is a "slow" hack, find a "normal" solution to work with wildcards
//		for (it_templates = templates.begin(); it_templates != templates.end(); it_templates++) {
//			for (it_triple = it_templates->second.begin(); it_triple != it_templates->second.end(); it_triple++) {
//				if ((it_triple->subjectType == s or s == 0) and (it_triple->objectType == o or o == 0) and (it_triple->predicateID == p or p == 0)
//						and it_triple->scope == scope) {
//					result_templates->insert(pair<KEY_ID, KEY_ID>(it_templates->first, it_triple->ID));
//				}
//			}
//		}
//
//	}
//
//}
//
//void TemplateManager::Store() {
//	unordered_map< KEY_ID, set<TripleTemplate> >::iterator it_templates;
//	set<TripleTemplate>::iterator it_triples;
//	vector<TripleTemplate> triples_tmp;
//	size_t s;
//	fstream file;
//	try {
//		file.open(diplo::dbDir+"templates", ios::binary | ios::out);
//		s = templates.size();
//		file.write( (char*)  &s, sizeof(s)); //number of elements in templates
//
//		for (it_templates = templates.begin(); it_templates != templates.end(); it_templates++) {
//			file.write( (char*)  &(it_templates->first), sizeof(it_templates->first));
//
//			s = it_templates->second.size();
//			file.write( (char*)  &s, sizeof(s)); //number of elements in <set> for each template
//
//			for (it_triples = it_templates->second.begin(); it_triples != it_templates->second.end(); it_triples++) {
//				file.write( (char*)  &(*it_triples), sizeof(*it_triples));
//			}
//		}
//		file.close();
//
//	} catch (fstream::failure &e) {
//		cerr << "Exception writing file";
//	}
//
//}
//
//void TemplateManager::Restore() {
//	unordered_map< KEY_ID, set<TripleTemplate> >::iterator it_templates;
//	set<TripleTemplate>::iterator it_triples;
//	size_t s1,s2;
//	KEY_ID type;
//	TripleTemplate tripleTemplate;
//	set<TripleTemplate> triples_tmp;
//	fstream file;
//	try {
//		file.open(diplo::dbDir+"templates", ios::binary | ios::in);
//		file.read( (char*)  &s1, sizeof(s1)); //number of elements in templates
//		for (size_t i = 0 ; i < s1; i++) {
//			set<TripleTemplate> triples_tmp;
//			file.read( (char*)  &type, sizeof(type));
//			file.read( (char*)  &s2, sizeof(s2)); //number of elements in <set> for each template
//			for (size_t j = 0 ; j < s2; j++) {
//				file.read( (char*)  &tripleTemplate, sizeof(tripleTemplate));
//				triples_tmp.insert(tripleTemplate);
//			}
//			templates.insert ( pair< KEY_ID, set<TripleTemplate> > (type, triples_tmp) );
//		}
//		file.close();
//
//	} catch (fstream::failure &e) {
//		cerr << "Exception writing file";
//	}
//
//
//}
//
void TemplateManager::DisplayTemplates(KEY_ID tmp) {
  for(auto tmpl : templates2) { 
    cout << endl << "Temple ID: " << tmpl.first << "\t#preds:" << tmpl.second.size() << "\t#molecules:" << TemplateMolecules.find(tmpl.first)->second.size() << endl;
    for(auto pred : tmpl.second) {
      cout << "--" << diplo::KM.Get(pred) << " [" << pred << "]" << endl;
    }
  }
  
}

//void TemplateManager::AddPredicates(KEY_ID predicateType) {
//void TemplateManager::AddPredicates(unordered_map<KEY_ID, unordered_map<KEY_ID, unordered_set<KEY_ID>> > *predicates) {
// void TemplateManager::AddPredicates(KEY_ID predicate1, KEY_ID predicate2, unordered_set<KEY_ID> *moleculesID) {
// //	if (predicate1 == predicate2) return;
// //	for (unordered_map<KEY_ID, unordered_map<KEY_ID, unordered_set<KEY_ID>> >::iterator predicate1 = predicates->begin(); predicate1 != predicates->end(); predicate1++) {
// ////		unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it_PredicateIndex1 = PredicateIndex.find(predicate1->first);
// ////		if (it_PredicateIndex1 == PredicateIndex.end()) {
// //			KEY_ID autoinct_id = templates.size() + 1;
// //			templates.insert( { { autoinct_id, { { 0, { { predicate1->first, { 0 } } } } } } });
// //			PredicateIndex.insert( { predicate1->first, { autoinct_id } });
// //			for (unordered_map<KEY_ID, unordered_set<KEY_ID>>::iterator predicate2 = predicate1->second.begin(); predicate2 != predicate1->second.end(); predicate2++) {
// //				templates.insert( { { autoinct_id, { { 0, { { predicate2->first, { 0 } } } } } } });
// //				PredicateIndex.insert( { predicate2->first, { autoinct_id } });
// //				TemplateMolecules.insert( { { autoinct_id, { predicate2->second.begin(), predicate2->second.end() } } }); //check it it works!!!
// //			}
// ////		}
// ////		else {
// ////			for (unordered_map<KEY_ID, unordered_set<KEY_ID>>::iterator predicate2 = predicate1->second.begin(); predicate2 != predicate1->second.end(); predicate2++) {
// ////				unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it_PredicateIndex2 = PredicateIndex.find(predicate2->first);
// ////				if (it_PredicateIndex2 == PredicateIndex.end()) {
// ////					for (unordered_set<KEY_ID>::iterator itT = it_PredicateIndex2->second.begin(); itT != it_PredicateIndex2->second.end(); itT++) {
// ////						KEY_ID autoinct_id = *itT;
// ////					}
// ////				}
// ////			}
// ////		}
// //	}
// 
// //	KEY_ID moleculeID = 0;
//     unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it_PredicateIndex1 = PredicateIndex.find(predicate1);
//     unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it_PredicateIndex2 = PredicateIndex.find(predicate2);
//     if (it_PredicateIndex1 == PredicateIndex.end() and it_PredicateIndex2 == PredicateIndex.end()) { //none of them is there, simple!!
//         //create new template and add those predicates
//         //create a new template
//         KEY_ID autoinct_id = templates.size() +1;
//         templates.insert( { { autoinct_id, { { 0, { { predicate1, { 0 } } } } } } });
//         templates.insert( { { autoinct_id, { { 0, { { predicate2, { 0 } } } } } } });
// 
//         TemplateMolecules.insert( {{ autoinct_id, {moleculesID->begin(), moleculesID->end() } } }); //check it it works!!!
// 
//         PredicateIndex.insert( {predicate1,{autoinct_id}});
//         PredicateIndex.insert( {predicate2,{autoinct_id}});
//     } else { //only one exists
// //		cout << "- " << diplo::KM.Get(predicate1) << "\t" << diplo::KM.Get(predicate2) << "\t[ " << predicate1 << " ] -- [" << predicate2 << " ]" <<endl;
// //		//get the templates and insert p2 there
//         if (
//             (it_PredicateIndex1 == PredicateIndex.end() and it_PredicateIndex2 != PredicateIndex.end()) or
//             (it_PredicateIndex1 != PredicateIndex.end() and it_PredicateIndex2 == PredicateIndex.end())
//         ) {
// //			cout << "- 1" << endl;
//             unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it_PredicateIndex;
//             KEY_ID predicate;
//             if (it_PredicateIndex2 != PredicateIndex.end() ) {
// //				cout << "- 1a" << endl;
//                 it_PredicateIndex = it_PredicateIndex2;
//                 predicate = predicate1;
//             } else if (it_PredicateIndex1 != PredicateIndex.end() ) {
// //				cout << "- 1b" << endl;
//                 it_PredicateIndex = it_PredicateIndex1;
//                 predicate = predicate2;
//             }
// 
//             for (unordered_set<KEY_ID>::iterator itT = it_PredicateIndex->second.begin(); itT != it_PredicateIndex->second.end(); itT++) {
//                 KEY_ID autoinct_id = *itT;
//                 if(autoinct_id <= NaturaltemplateMaxID) continue; //do not mess with natural templates
// 
//                 templates.find(autoinct_id)->second.begin()->second.insert( { { predicate, { 0 } } } );
// //				templates.find(autoinct_id)->second.insert({ { 0, { { predicate, { 0 } } } } });
//                 PredicateIndex.insert( {predicate,{autoinct_id}});
// 
//                 TemplateMolecules.find(autoinct_id)->second.insert( moleculesID->begin(), moleculesID->end() );
//             }
//         } else {
// //			cout << "- 2" << endl;
//             if (it_PredicateIndex1 != PredicateIndex.end() and it_PredicateIndex2 != PredicateIndex.end()) {
//                 //both predicates are already in the system, add to their templated the other predicate
// 
//                 for (unordered_set<KEY_ID>::iterator itT = it_PredicateIndex1->second.begin(); itT != it_PredicateIndex1->second.end(); itT++) {
//                     KEY_ID autoinct_id = *itT;
//                     if (autoinct_id <= NaturaltemplateMaxID)
//                         continue; //do not mess with natural templates
// 
//                     templates.find(autoinct_id)->second.begin()->second.insert( { { predicate2, { 0 } } } );
// //					templates.find(autoinct_id)->second.insert( { { 0, { { predicate2, { 0 } } } } });
// 
// //					unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it_PredicateIndex = PredicateIndex.find(predicate2);
// //					if (it_PredicateIndex == PredicateIndex.end())
// //						PredicateIndex.insert( { predicate2, { autoinct_id } });
// //					else
//                     it_PredicateIndex2->second.insert(autoinct_id);
// 
//                     TemplateMolecules.find(autoinct_id)->second.insert(moleculesID->begin(), moleculesID->end());
//                 }
// //				for (unordered_set<KEY_ID>::iterator itT = it_PredicateIndex2->second.begin(); itT != it_PredicateIndex2->second.end(); itT++) {
// //					KEY_ID autoinct_id = *itT;
// //					if (autoinct_id <= NaturaltemplateMaxID)
// //						continue; //do not mess with natural templates
// //
// //					templates.find(autoinct_id)->second.begin()->second.insert({ { predicate1, { 0 } } } );
// ////					templates.find(autoinct_id)->second.insert( { { 0, { { predicate1, { 0 } } } } });
// ////					unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it_PredicateIndex = PredicateIndex.find(predicate1);
// ////					if (it_PredicateIndex == PredicateIndex.end())
// ////						PredicateIndex.insert( { predicate1, { autoinct_id } });
// ////					else
// //					it_PredicateIndex1->second.insert(autoinct_id);
// //
// //
// //					TemplateMolecules.find(autoinct_id)->second.insert(moleculesID->begin(), moleculesID->end());
// //				}
// 
//             } else {
//                 //well, probably never happen
//                 ERROR_OUT
//             }
//         }
//     }
// //
// 
// //		if (it_PredicateIndex->second.find(predicate2) !=  it_PredicateIndex->second.end() ) return ;
// //		for (unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it = it_PredicateIndex->second.begin(); it != it_PredicateIndex->second.end(); it++) {
// //			for (unordered_set<KEY_ID>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
// //				KEY_ID autoinct_id = *it2;
// //				if(autoinct_id <= NaturaltemplateMaxID) continue; //do not mess with natural templates
// //
// //				templates.find(autoinct_id)->second.insert({ { 0, { { predicate1, { 0 } } } } });
// //				templates.find(autoinct_id)->second.insert({ { 0, { { predicate2, { 0 } } } } });
// //
// //				TemplateMolecules.find(autoinct_id)->second.insert( moleculeID );
// //
// //				it_PredicateIndex->second.insert( { { predicate2, { autoinct_id } } } );
// //				unordered_map<KEY_ID, unordered_map<KEY_ID, unordered_set<KEY_ID> > >::iterator it_PredicateIndex2 = PredicateIndex.find(predicate2);
// //				if (it_PredicateIndex2 != PredicateIndex.end() ) it_PredicateIndex2->second.insert( { { predicate1, { autoinct_id } } } );
// //				else PredicateIndex.insert( { { predicate2, { { predicate1,{autoinct_id}}}}});
// //
// ////				templates.insert( { { autoinct_id, { { 0, { { predicate1, { 0 } } } } } } });
// ////				templates.insert( { { autoinct_id, { { 0, { { predicate2, { 0 } } } } } } });
// ////				RootTemplateIdx.insert( { subjectType, { autoinct_id } });
// ////				TemplateMolecules.insert( { { autoinct_id, { moleculeID } } });
// ////				PredicateIndex.insert( { { predicate1, { { predicate2, { autoinct_id } } } } });
// ////				PredicateIndex.insert( { { predicate2, { { predicate1,{autoinct_id}}}}});
// //
// //
// //			}
// //		}
// //	}
// }

void TemplateManager::DisplayMoleculesStats() {
    for (unordered_map<KEY_ID, unordered_set<KEY_ID>>::iterator it = TemplateMolecules.begin(); it != TemplateMolecules.end(); it++)
        cout << "TID: " << it->first << " -- #molecules: " << it->second.size() << endl;

    cout << "NaturaltemplateMaxID: " << NaturaltemplateMaxID << endl;
}

void TemplateManager::DisplayNoTemplates() {
  //  cout << "#templates: " << templates.size() << endl;
}

void TemplateManager::GetMoleculesForPredicates(vector<QueryGraph> &graph, unordered_set<unordered_set<KEY_ID>*> &result_molecules) {
//     size_t smallest_templatesSet_size = 0;
// 
//     for (auto t : graph) {
//         auto it_PredicateIndex = PredicateMolecules.find(t.predicate.second);
// 
//         result_molecules.insert(&(it_PredicateIndex->second));
//     }
// 
// 
// 
//     cerr << "--GetMoleculesForPredicates - 1diplo::stopwatch_get(): " << diplo::stopwatch_get() << endl;
//     cerr << "--GetMoleculesForPredicates - result_molecules.size(): " << result_molecules.size() << endl;


}


void TemplateManager::GetMoleculesForPredicatesFromTemplates ( vector<QueryGraph> &graph, unordered_set<unordered_set<KEY_ID>*> &result_molecules )
{
//     vector<unordered_set<KEY_ID>*> templatesSet;
//     unordered_set<KEY_ID>* smallest_templatesSet;
//     size_t smallest_templatesSet_size = 0;
// 
//     for ( auto t : graph ) {
//         auto it = PredicateTemplates.find ( t.predicate.second );
// 
//         templatesSet.push_back ( & ( it->second ) );
// 		
//     }
// 
// 
// 
//     unordered_set<KEY_ID>* smallest_molecules_set = NULL;
//     size_t smallest_molecules_set_size = 999999999999999999;
// 
//     for ( auto && it : templatesSet ) {
//         if ( it->size() < smallest_molecules_set_size ) {
//             smallest_molecules_set_size = it->size();
//             smallest_molecules_set = it;
//         }
//     }
// 
//     for ( auto & it : *smallest_molecules_set ) {
// 	  bool found = true;
//       for ( auto & it2 : templatesSet ) {
// 		if ( it2->find ( it ) == it2->end() ) {
// 		  found == false;
// 		  break;
//         }
//       }
//       if (found) {//we want this template
// 		result_molecules.insert( &(TemplateMolecules.find(it)->second) );
// 		
// 		
// // 		for (auto& ttemplate : it->second) {
// 		  auto preds = templates2.find(it);
// 		  for (auto predicate : preds->second) {
// 			cout << predicate << "\t" << KM.Get(predicate) << endl;
// 		  }
// 		  cout << endl;
// // 		}
// 	  }
// 	  
//     }
//     
//     cerr << "--GetMoleculesForPredicatesFromTemplates - 1diplo::stopwatch_get(): " << diplo::stopwatch_get() << endl;
//     cerr << "--GetMoleculesForPredicatesFromTemplates - result_molecules.size(): " << result_molecules.size() << endl;
}

void TemplateManager::MineTemplateFromMolecule(const pair<KEY_ID, P_l>& molecule) {
  
 //this builds a simple predicate index,
 //predicate -> molecules
 ///////////////////////////////////////////////////////////////////
  for (auto & it_predicates_l1 : molecule.second) {
      if  ( (it_predicates_l1.first & PredMask)  == PredMask ) continue;
        auto it_PredicateIndex = PredicateMolecules.find(it_predicates_l1.first);
        if (it_PredicateIndex == PredicateMolecules.end()) {
            PredicateMolecules.insert( { it_predicates_l1.first, { molecule.first } });
        } else {
            it_PredicateIndex->second.insert(molecule.first);
        }
  }
///////////////////////////////////////////////////////////////////


// auto predicates = molecule.second.begin();
//  for ( ; predicates != molecule.second.end(); predicates++) {
//    cout << KM.Get(predicates->first) << endl;
//  }


// KEY_ID molecule_tempalte = 0;
    
//     for (P_l::iterator it_predicates_l1 = molecule->second.begin(); it_predicates_l1 != molecule->second.end(); it_predicates_l1++) {
// 	  
// 	  
// 	  
// 	}
    //
////		if (it_predicates_l1->first == 107054) cout << KM.Get(molecule->first) << endl;
//		auto it_PredicateIndex1 = PredicateIndex.find(it_predicates_l1->first);
//		if (it_PredicateIndex1 == PredicateIndex.end() ) continue;
//		for (auto ttemplate : it_PredicateIndex1->second) {
//			templates_counter.insert(ttemplate);
//		}
//
//
////		if (it_predicates_l1->first == 107054) cout << 1 << endl;
//
//		//exclude supper common predicates!!!!!!
//		//count some agv on predicate occurence to eliminate super common predicates
////		if (it_PredicateIndex1->second.size() > 200 ) { //this looks like a frequent predicate, skip it
////			x++;
////			continue;
////			cout << KM.Get(it_predicates_l1->first) << "\tit_PredicateIndex1->second.size(): " << it_PredicateIndex1->second.size() << endl;
////
////		}
//
//
///*
//		for (P_l::iterator it_predicates_l2 = molecule->second.begin(); it_predicates_l2 != molecule->second.end(); it_predicates_l2++) {
//			if (it_predicates_l1->first == it_predicates_l2->first)
//				continue;
//			auto it_PredicateIndex2 = PredicateIndex.find(it_predicates_l2->first);
//
//			if (it_PredicateIndex2 == PredicateIndex.end())
//				continue;
//
////			if (it_predicates_l1->first == 107054) cout << 2 << endl;
//			unordered_set<KEY_ID>* tmps1,*tmps2;
//
//			if (it_PredicateIndex1->second.size() <= it_PredicateIndex2->second.size()) {
//				tmps1 = &(it_PredicateIndex1->second);
//				tmps2 = &(it_PredicateIndex2->second);
//			} else {
//				tmps2 = &(it_PredicateIndex2->second);
//				tmps1 = &(it_PredicateIndex1->second);
//			}
//
////			int templates_counter = 0;
//			for (auto ttemplate : *tmps1) {
//				if (tmps2->find(ttemplate) != tmps2->end()) {
//
//					auto it_templates_counter = templates_counter.find(ttemplate);
//					if (it_templates_counter == templates_counter.end() ) {
//						templates_counter.insert({{ttemplate,1}});
//					} else {
//						it_templates_counter->second++;
////						if (it_templates_counter->second > 100)
////						if (it_predicates_l1->first == 107054) cout << 3 << endl;
////							cout << KM.Get(it_predicates_l1->first) << "\t" << KM.Get(it_predicates_l2->first)
////									<< "\ttemplates_counter.size(): " << templates_counter.size()
////									<< endl;
//					}
//				}
//			}
//
////			if (it_predicates_l1->first == 107054) cout << 4 << endl;
//		}
//
//
//
//		for (auto e : templates_counter) {
//			if (e.second > max_predicate_counter) {
//				max_predicate_counter = e.second;
//				molecule_tempalte = e.first;
//			}
//		}
//
//		if (molecule_tempalte == 0) {
//			molecule_tempalte = *(it_PredicateIndex1->second.begin());
////			if (it_predicates_l1->first == 107054) cout << 5 << endl;
//		}
//
//
//*/
//
//
//	}
//
////////////////////////////
//	P_l *preds;
//	if (templates_counter.size() == 0) {
//		n++;
//
//		KEY_ID autoinct_id = templates.size() + 1;
//		templates.insert( { { autoinct_id, { { 0, { } } } } });
//		molecule_tempalte = autoinct_id;
//		TemplateMolecules.insert( { molecule_tempalte, { molecule->first } });
//
//		preds = &(templates.find(molecule_tempalte)->second.find(0)->second);
//
//		for (auto it_predicate : molecule->second) {
//			preds->insert( { { it_predicate.first, { } } });
//
//			auto it_PredicateIndex = PredicateIndex.find(it_predicate.first);
//			if (it_PredicateIndex == PredicateIndex.end()) {
//				PredicateIndex.insert( { it_predicate.first, { molecule_tempalte } });
//			} else {
//				it_PredicateIndex->second.insert(molecule_tempalte);
//			}
//		}
//
//	} else {
//		o++;
//
//		for (auto molecule_tempalte : templates_counter) {
//			TemplateMolecules.find(molecule_tempalte)->second.insert(molecule->first);
//
//			preds = &(templates.find(molecule_tempalte)->second.find(0)->second);
//			for (auto it_predicate : molecule->second) {
//				preds->insert( { { it_predicate.first, { } } });
//
//				auto it_PredicateIndex = PredicateIndex.find(it_predicate.first);
//				if (it_PredicateIndex == PredicateIndex.end()) {
//					PredicateIndex.insert( { it_predicate.first, { molecule_tempalte } });
//				} else {
//					it_PredicateIndex->second.insert(molecule_tempalte);
//				}
//			}
//		}
//	}
/////////////////////////
//
//

    /*
    	P_l *preds;
    	if (molecule_tempalte == 0 ) {
    		n++;

    		KEY_ID autoinct_id = templates.size() + 1;
    		templates.insert( { { autoinct_id, { { 0, {} } } } });
    		molecule_tempalte = autoinct_id;
    		TemplateMolecules.insert( { molecule_tempalte, { molecule->first } });

    	} else {
    		o++;
    		TemplateMolecules.find(molecule_tempalte)->second.insert(molecule->first);
    	}

    	preds = &(templates.find(molecule_tempalte)->second.find(0)->second);

    	for (auto it_predicate : molecule->second) {
    		preds->insert({{it_predicate.first,{}}});

    		auto it_PredicateIndex = PredicateIndex.find(it_predicate.first);
    		if (it_PredicateIndex == PredicateIndex.end()) {
    			PredicateIndex.insert( { it_predicate.first, { molecule_tempalte } });
    		} else {
    			it_PredicateIndex->second.insert(molecule_tempalte);
    		}
    	}
    */

}


float TemplateManager::CompateTemplates(KEY_ID t1, KEY_ID t2) {
  
  auto it1 = TM.templates2.find(t1);
  auto it2 = TM.templates2.find(t2);
  
  int t1_positive = 0;
  int t1_negative = 0;
  int t2_positive = 0;
  int t2_negative = 0;
  float t1_result = 0.0;
  float t2_result = 0.0;
  float result = 0.0;
  
  
  for (auto p : it1->second) {
    if ( it2->second.find(p) != it2->second.end() ) t1_positive++; 
    else t1_negative++;
  }
  
  for (auto p : it2->second) {
    if ( it1->second.find(p) != it1->second.end() ) t2_positive++; 
    else t2_negative++;
  }

  //FIXME, veryfy thhis math!!!! do some similarity metric here
  //take int account number of molecules in the template
  t1_result = t1_positive/(t1_positive+t1_negative);
  t2_result = t2_positive/(t2_positive+t2_negative);
  result = (t1_result + t2_result)/2;
  
  if ( (t1_positive+t1_negative) <  (t2_positive+t2_negative) ) { //if T2 bigger, then return negative, to be adjusted
    result = -result;
  }
  
  return result;
}

void TemplateManager::MergeTemplates(KEY_ID t1, KEY_ID t2) {
  //check if t2 still exsit!! 
  if (TM.templates2.find(t1) == TM.templates2.end() ) return;

  {
    auto it1 = TM.templates2.find(t1); // <TemplateID, predicates>
    auto it2 = TM.templates2.find(t2); // <TemplateID, predicates>
    it1->second.insert( it2->second.begin(), it2->second.end() ); // copy predicates to the first one
    
    for (auto pred : it2->second) { 
//       cout << KM.Get(pred) << endl;
      auto itpred = TM.PredicateTemplates.find(pred);
      itpred->second.insert(t1);
      itpred->second.erase(t2);
      
    }
    TM.templates2.erase(t2);
  }
  
  
  for (auto type : TM.RootTemplateIdx) //this is not efficient!!!
    if (type.second == t2) type.second = t1; // FIXME this is not correct!!!!

  {
    auto it1 = TM.TemplateMolecules.find(t1); // <TemplateID, molecules>
    auto it2 = TM.TemplateMolecules.find(t2); // <TemplateID, molecules>
    it1->second.insert( it2->second.begin(), it2->second.end() ); // copy predicates to the first one
    TM.TemplateMolecules.erase(t2);
  }

}




//
//void TemplateManager::Display(KEY_ID tmpl) {
//	unordered_map<KEY_ID, set<TripleTemplate> >::iterator it_templates;
//	set<TripleTemplate>::iterator it_triples;
//
//	it_templates = templates.find(tmpl);
//
//	cout << "Temple ID: " << it_templates->first << endl;
//	for (it_triples = it_templates->second.begin(); it_triples != it_templates->second.end(); it_triples++) {
//		it_triples->Display();
//	}
//	cout << endl;
//}


TemplateManager::~TemplateManager() {
    // TODO Auto-generated destructor stub
}

//int operator<(const TripleTemplate& left, const TripleTemplate& right) {
//
//	bool x = false;
//
//	if (left.subjectType < right.subjectType      )
//		x = true;
//	else if (left.subjectType == right.subjectType        ) {
//		if (left.predicateID < right.predicateID       )
//			x = true;
//		else if (left.predicateID == right.predicateID       ) {
//			if (left.objectType < right.objectType   )
//				x = true;
//			else if (left.objectType == right.objectType        ) {
//				if (left.scope < right.scope)
//					x = true;
//			}
//		}
//	}
//
//
//	return x;
//}
//
//void TripleTemplate::Display() const {
//	cout << "ID: [ " << ID << " ]\t"
//			<< diplo::KM.Get(subjectType) << " [ " << subjectType << " ] \t"
//			<< diplo::KM.Get(predicateID) << " [ " << predicateID << " ] \t"
//			<< diplo::KM.Get(objectType) << " [ " << objectType << " ] \t"  << scope << endl;
//}
//
//int operator ==(const TripleTemplate& left, const TripleTemplate& right) {
//	if (
//			( left.subjectType == right.subjectType or right.subjectType == 0 )  and
//			( left.predicateID == right.predicateID or right.predicateID == 0 )  and
//			( left.objectType == right.objectType or right.objectType == 0 )  and
//			( left.scope == right.scope or right.scope == 0 )
//		)
//		return true;
//
//	return false;
//}
//
//TripleTemplate::TripleTemplate() {
//	ID = 0;
//	subjectType = 0;
//	predicateID = 0;
//	objectType = 0;
//	scope=1;
//}





//to be removed
//size_t TemplateManager::GetTemplate(KEY_ID root, KEY_ID s, KEY_ID p, KEY_ID o) {
//	return -1;
//}

