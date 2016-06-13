/*
 * ConductorNode.cpp
 *
 *  Created on: 22-03-2013
 *      Author: marcin
 */

#include "ConductorNode.h"

using namespace diplo;

ConductorNode::ConductorNode() {
}

void ConductorNode::LoadData() {
    unordered_set<KEY_ID> myMolecules;
    vector<TripleIDs> tripleIDs;
    KEY_ID predicateType = 0;
    fstream file;
    size_t s;
    try {
        file.open(diplo::dbDir+"triples", ios::binary | ios::in);
        file.read((char*) &predicateType, sizeof(predicateType));
        file.read( (char*)  &s, sizeof(s));
        tripleIDs.resize(s);

        file.read((char*) tripleIDs.data(), s * sizeof(TripleIDs));
        file.close();

    } catch (fstream::failure &e) {
        cerr << "Exception reading file";
    }
    readMyMolecules(&myMolecules);
    TH.Restore();
//	TM.Restore();


    cout << "M.CreateMolecule" << endl;
    for (vector<TripleIDs>::iterator it_tripleIDs = tripleIDs.begin(); it_tripleIDs != tripleIDs.end(); it_tripleIDs++) {
        if (myMolecules.find(it_tripleIDs->subject) != myMolecules.end() ) {
            if (it_tripleIDs->predicate == predicateType )
                TypesM.AddElement(it_tripleIDs->object, it_tripleIDs->subject);

            //FIXME!! assign template!!!!
//			M.CreateMolecule(it_tripleIDs->subject, 00000);
            M.AddTriple(it_tripleIDs->subject, it_tripleIDs->predicate, it_tripleIDs->object);
            
            M.AddTriple2(it_tripleIDs->object, ( it_tripleIDs->predicate | PredMask), it_tripleIDs->subject);
        }
    }

    cout << "TM.CreateTemplates" << endl;
    cout << "Memory TM.CreateTemplates before:  " << diplo::memory_usage() << endl;
    unordered_map<KEY_ID, unordered_map<KEY_ID, unordered_set<KEY_ID> > > predicate_counter;


//	M.Display();exit(1);

	  
    static KEY_ID autoinct_id = 1; //TemplateID starts from 1
    auto it_predicates  = TM.templates2.find(0);;
    for (auto& molecule : M.molecules ) {
	
 	 TM.MineTemplateFromMolecule(molecule); //this makes only predicate index
		

		
//////this discovers template from types
  	O_l *sbj_types;
 	auto it_type = molecule.second.find(predicateType);
	
 	if ( it_type != molecule.second.end()) sbj_types = &(it_type->second);
 	else sbj_types = new O_l(0);
	
	for (auto type : *sbj_types) {
	  auto it_tmpl = TM.RootTemplateIdx.find(type) ;
	  KEY_ID tmpl = 0 ;
	  if ( it_tmpl == TM.RootTemplateIdx.end() ) { //there is no template for this type, create it
	    tmpl = autoinct_id;
	    autoinct_id++;
	    
	    
	    TM.RootTemplateIdx.insert({type,tmpl});
	    TM.TemplateMolecules.insert({tmpl,{molecule.first}});
	    TM.templates2.insert({tmpl,unordered_set<KEY_ID>()});
	    
	    it_tmpl = TM.RootTemplateIdx.find(type) ;
	    
// 	    cout << "NEW--type: " << type << "\ttemplate: " << tmpl << endl; 
	    
	  } else {
	    tmpl = it_tmpl->second;
// 	    cout << "OLD--type: " << type << "\ttemplate: " << tmpl << endl; 
	    
	    TM.TemplateMolecules.find(tmpl)->second.insert(molecule.first);
	  
	    
	  }
	  


	  it_predicates= TM.templates2.find(tmpl);
	  for (auto &pred : molecule.second ) {
     if  ( (pred.first & PredMask)  == PredMask ) continue;
	    it_predicates->second.insert(pred.first);
	    
	    auto itpred = TM.PredicateTemplates.find(pred.first);
	    if (itpred == TM.PredicateTemplates.end() ) {
	      TM.PredicateTemplates.insert({pred.first,{tmpl}});
	    } else {
	      itpred->second.insert(tmpl);
	    }
	    
	    
	  }
	   
	 // cout << tmpl << endl; 
	}
	
	
	
    }

//   TM.DisplayTemplates();
   
   
//    for ( auto t : TM.PredicateTemplates ) {
//      cout << t.first << endl;
//       for ( auto p : t.second ) {
// 	cout << "\t" << KM.Get(p) << endl;
//       }
//    }
//    
//    return;

   cout << "templates2merge" << endl;
   unordered_multimap<KEY_ID, KEY_ID> templates2merge;
   
   auto tmpl2 = TM.templates2.begin();
   float r = 0;
   for (auto tmpl1 = TM.templates2.begin() ; tmpl1 != TM.templates2.end(); tmpl1++) {
      tmpl2 = tmpl1;
      tmpl2++;
      tmpl2 =  TM.templates2.begin() ;
      for ( ;tmpl2 != TM.templates2.end(); tmpl2++) {
	r = TemplateManager::CompateTemplates( tmpl1->first, tmpl2->first );
	
	if (r == 1 and tmpl1->first != tmpl2->first) {
	  templates2merge.insert({tmpl1->first, tmpl2->first}); 
	}
      }   
   }
   
   
   cout << "TemplateManager::MergeTemplates" << endl;
   for (auto t : templates2merge) {
    // cout << "merge : " << t.first << " + " << t.second << endl;
     TemplateManager::MergeTemplates( t.first, t.second );
   }
   
   
  // TM.DisplayTemplates();
   cout << "TM.MoleculeTemplate" << endl;
   for (auto& tmpl : TM.TemplateMolecules ) {
     for (auto& m : tmpl.second ) {
       TM.MoleculeTemplate.insert( {m, tmpl.first } );
     }
   }
   
   
   
    cout << "TM.TemplatesGraph" << endl;
   for (auto& m1 : M.molecules ) {
     unordered_set<KEY_ID> t2s;
     for (auto& p : m1.second ) {
       for (auto& m2 : p.second ) {
	 auto range = TM.MoleculeTemplate.equal_range(m2);
	 for (auto it = range.first; it != range.second; ++it) {
	   t2s.insert(it->second);
	 }
       }
     }
     
     auto range = TM.MoleculeTemplate.equal_range(m1.first);
     for (auto t1 = range.first; t1 != range.second; ++t1) {
       
      bool ins = false;
      auto it1 = TM.TemplatesGraph.find(t1->first);
      if ( it1 ==  TM.TemplatesGraph.end() ) ins = true;
      
      for (auto& t2 : t2s ) {
	if (ins) { 
	  it1 =  TM.TemplatesGraph.insert(it1, {t1->second, {t2}});
	  ins = false;
	}
	else it1->second.insert(t2);
      }
     }
   }

   
   
   
//    for (auto t1 : TM.TemplatesGraph ) {
//      cout << t1.first << endl; 
//      for (auto t2 : t1.second ) {
//       cout << "\t" << t2 << endl; 
//      }
//      cout << endl;
//    }
	
}

void ConductorNode::readMyMolecules(unordered_set<KEY_ID> *myMolecules) {
    vector<KEY_ID> myMolecules_tmp;
    size_t size = 0;
    fstream file;
    try {
        file.open(diplo::dbDir+"node" + to_string(diplo::myID), ios::in | ios::out | ios::app | ios::binary | ios::out);
        file.read((char*) &size, sizeof(size));
        myMolecules_tmp.resize(size);
        file.read((char*) myMolecules_tmp.data(), size*sizeof(KEY_ID));
        file.close();

    } catch (fstream::failure &e) {
        cerr << "Exception reading file";
    }

    myMolecules->reserve(myMolecules_tmp.size());
    copy(myMolecules_tmp.begin(), myMolecules_tmp.end(), inserter(*myMolecules,myMolecules->begin() ) );

    cout << "Number of molecules for this node: " << myMolecules_tmp.size() << endl;

}

void ConductorNode::HandleQueries() {
//	diplo::CLI.Start();
//	queries::LUBM_network lubm;
//	queries::DBP_network dbp;
//
//	char *data = (char *)malloc(diplo::network_buf_size);
//	while(1) {
//		bzero(data,diplo::network_buf_size);
//		diplo::CLI.Receive(data, diplo::network_buf_size);
//		diplo::stopwatch_start();
//		if (strncmp(data,"q01",3) == 0 ) {
//			lubm.q01_n(data+3);
//		} else if (strncmp(data,"q02s1",5) == 0 ) {
//			lubm.q02s1_n(data+5);
//		} else if (strncmp(data,"q02s2",5) == 0 ) {
//			lubm.q02s2_n(data+5);
//		} else if (strncmp(data,"q03",3) == 0 ) {
//				lubm.q03_n(data+3);
//		} else if (strncmp(data,"q04",3) == 0 ) {
//			lubm.q04_n(data+3);
//		} else if (strncmp(data,"q05",3) == 0 ) {
//			lubm.q05_n(data+3);
//		} else if (strncmp(data,"q06",3) == 0 ) {
//			lubm.q06_n(data+3);
//		} else if (strncmp(data,"q07",3) == 0 ) {
//			lubm.q07_n(data+3);
//		} else if (strncmp(data,"q08s1",5) == 0 ) {
//			lubm.q08s1_n(data+5);
//		} else if (strncmp(data,"q08s2",5) == 0 ) {
//			lubm.q08s2_n(data+5);
//		} else if (strncmp(data,"q09s1",5) == 0 ) {
//			lubm.q09s1_n(data+5);
//		} else if (strncmp(data,"q09s2",5) == 0 ) {
//			lubm.q09s2_n(data+5);
//		} else if (strncmp(data,"q10",3) == 0 ) {
//			lubm.q10_n(data+3);
//		} else if (strncmp(data,"q11s1",5) == 0 ) {
//			lubm.q11s1_n(data+5);
//		} else if (strncmp(data,"q11s2",5) == 0 ) {
//			lubm.q11s2_n(data+5);
//		} else if (strncmp(data,"q12",3) == 0 ) {
//			lubm.q12_n(data+3);
//		} else if (strncmp(data,"q13",3) == 0 ) {
//			lubm.q13_n(data+3);
//		} else if (strncmp(data,"q14",3) == 0 ) {
//			lubm.q14_n(data+3);
//		} else if (strncmp(data,"q15",3) == 0 ) {
//			lubm.q15_n(data+3);
//		} else if (strncmp(data,"q16s1",5) == 0 ) {
//			lubm.q16s1_n(data+5);
//		} else if (strncmp(data,"q16s2",5) == 0 ) {
//			lubm.q16s2_n(data+5);
//		} else if (strncmp(data,"q17",3) == 0 ) {
//			lubm.q17_n(data+3);
//		} else if (strncmp(data, "Dq01", 4) == 0) {
//			dbp.q01_n(data + 4);
//		} else if (strncmp(data, "Dq02", 4) == 0) {
//			dbp.q02_n(data + 4);
//		} else if (strncmp(data, "Dq03", 4) == 0) {
//			dbp.q03_n(data + 4);
//		} else if (strncmp(data, "Dq04", 4) == 0) {
//			dbp.q04_n(data + 4);
//		} else if (strncmp(data, "Dq05", 4) == 0) {
//			dbp.q05_n(data + 4);
//		}
//
//		PRINT_CLIENT_TIME
////		return;
//	}
//	free (data);

}

ConductorNode::~ConductorNode() {
}

