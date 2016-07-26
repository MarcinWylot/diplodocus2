#include "Molecules.h"

Molecules::Molecules() {
}
Molecules::~Molecules() {
}


void Molecules::AddTriple(KEY_ID s, KEY_ID p, KEY_ID o) {
 
  auto mi = molecules.insert({s,Molecule(s)});
  Molecule *m =  &(mi.first->second);
  m->AddEntity(p, o);
  
   //do inverted index
   auto idx = inv_molecules.find(o);
   if (idx == inv_molecules.end() ) {
      inv_molecules.insert( {o, { m }} );
   } else {
      idx->second.insert(m);
   }
   
   //do predicate index
   auto idxp = predicate_idx.find(p);
   if (idxp == predicate_idx.end() ) {
      predicate_idx.insert( {p, { m }} );
   } else {
      idxp->second.insert(m);
   }
   
/*   
   if (p == diplo::type ) {
      auto idx = type_idx.find(o);
      if (idx == type_idx.end() ) {
	type_idx.insert( {o, { s }} );
      } else {
	idx->second.insert(s);
      }
   }*/
}


void Molecules::Display() {
  for(auto m : molecules) {
    m.second.Display();
  }
}


Molecule* Molecules::Get ( KEY_ID s ) {
  auto m = molecules.find( s );
  
  if (m == molecules.end()) return NULL;
  else return &(m->second);
}

unordered_set<Molecule*>* Molecules::GetMoleculesO ( KEY_ID o ) {
  auto ms = inv_molecules.find(o);
  if (ms != inv_molecules.end()) return &(ms->second);
  return NULL;
}

unordered_set<Molecule*>* Molecules::GetMoleculesP ( KEY_ID p ) {
  auto ms = predicate_idx.find(p);
  if (ms != predicate_idx.end()) return &(ms->second);
  return NULL;
}

void Molecules::GetMoleculesPO ( vector<QueryBGP> &bgp, unordered_map<KEY_ID, unordered_set<Molecule*> > &results ) {
  vector< decltype( inv_molecules.begin()->second ) > ms;

  decltype( type_idx.begin() ) thisType;
  
  
  size_t selective_n = 0;
  decltype( inv_molecules.begin()->second ) selective;

  for (auto pattern : bgp) {
//     cout << "Xp: " << pattern.predicate.second << endl;
//     cout << "Xo: " << pattern.object.second << endl;
    
    if (pattern.object.second != 0) {
      auto m_o = inv_molecules.find(pattern.object.second) ;
//        cout << "o: " << diplo::KM.Get(pattern.object.second) ;
      if ( m_o != inv_molecules.end() ) {
	ms.push_back(m_o->second);
	
// 	cout << "\t OK: " << m_o->second.size();
	
	if (selective_n == 0 or selective_n > m_o->second.size() ) { //this is more selective
	  selective = m_o->second;
	  selective_n = m_o->second.size();
	}
      } else continue;
//         cout << endl;
    }
    
     if (pattern.predicate.second != 0) { 
      auto m_p = predicate_idx.find(pattern.predicate.second) ;
//        cout << "p: " <<  diplo::KM.Get(pattern.predicate.second);
      if ( m_p != predicate_idx.end() ) {
	ms.push_back(m_p->second);
	
// 	cout << "\t OK: " << m_p->second.size();
	
	if (selective_n == 0 or selective_n > m_p->second.size() ) { //this is more selective
	  selective = m_p->second;
	  selective_n = m_p->second.size();
	}
      } else continue;
//        cout << endl;
    }
    
    
    
  }

//   for (auto x : ms ) {
//      cout << x.size() << endl;
//   }
  cout << "selective: " << selective.size() << endl;

   for(auto m : selective) {
     bool add = false;
     
  
     for (auto ms_x : ms ) {
      if ( ms_x.find(m) == ms_x.end()) {
	add = false;
	break;
      } else add = true;
    }
    if (add) { // here inspect the molecule
      add = false;
      for (auto pattern : bgp) {
	if ( m->CheckIfEntityExists(pattern.predicate.second, pattern.object.second) ) { 
	  add = true;
	} else {add = false;break;}
      }
      
      
      unordered_set<KEY_ID> idx; 

      if ( add ) {
	for (auto pattern : bgp) {
	  if (pattern.subject.first == QF_INDEX) { //index on subject
	    idx.insert(m->s);
	    
	    
	  } 
	  if (pattern.predicate.first == QF_INDEX) { // index on predicate
	    
	    for( auto pred : *( m->GetPredicates() ) ) {
	      if (pattern.object.second == 0 or (pred.second.find(pattern.object.second) != pred.second.end()) ) {
		idx.insert(pred.first);
	      }
	    }
	    
	    
	  } 
	  if (pattern.object.first == QF_INDEX) { // index on onject
	    //cout << "obj " << endl;
 	    if (pattern.predicate.second != 0 ) { // get object only for correct predicates
	      auto local_pred = m->GetPredicates()->find(pattern.predicate.second);
	      if (local_pred != m->GetPredicates()->end() ) {
		for (auto local_obj : local_pred->second) {
		  idx.insert(local_obj);
		}
	      }
	    } else { // no predicate in the parrern, ger all objects
	      for (auto local_pred : *(m->GetPredicates())) {
		for (auto local_obj : local_pred.second) {
		  idx.insert(local_obj);
		}
	      }
	    }
	   
	  } 
	}
	
	//PERF_PROF
	
	//put this molecle to the results, with a good index
	        if ( idx.empty() ) idx.insert ( 0 );
                for ( auto i : idx ) {
                    auto e = results.find ( i );
                    if ( e == results.end() ) {
                        results.insert ( {i, { m }} );
                    } else {
                        e->second.insert ( m );
                    }
                }

	
      } //if ( add )
	
    
    }
    
    
  }
  
   PERF_PROF
//   for (auto r : results ) {
//     cout << diplo::KM.Get(r.first) << "\t" << r.second.size() <<endl;
//    
//   }
  
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//single Molecule
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Molecule::Molecule(KEY_ID _s) {
  s = _s;
}

Molecule::~Molecule() {}


void Molecule::AddEntity(KEY_ID p, KEY_ID o) {
    auto e = entities.find ( p );
    if ( e == entities.end() ) {
        entities.insert ( {p, { o }} );
    } else {
        e->second.insert ( o );
    }
}

bool Molecule::CheckIfEntityExists ( KEY_ID p, KEY_ID o) {
     
    if ( p != 0 ) {
      
        auto e = entities.find ( p );
        if ( e != entities.end() ) {
            if ( o == 0  or e->second.find ( o ) != e->second.end() ) {
                return true;
            }
        }

    } else { // no predicate in the parrern, check all objects
        for ( auto e : entities ) {
            if ( o == 0  or e.second.find ( o ) != e.second.end() ) {
                return true;
            }
        }
    }
       
       
       
   return false;
}

const void Molecule::Display() {
  cout << diplo::KM.Get(s) << endl;
  for ( auto p : entities ) {
    cout << "\t" << diplo::KM.Get(p.first) << endl;
    for ( auto o : p.second ) {
      cout << "\t\t" << diplo::KM.Get(o) << endl;
    }
  }
}
