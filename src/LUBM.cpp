/*
 * LUBM.cpp
 *
 *  Created on: 19-11-2012
 *      Author: marcin
 */

#include "LUBM.h"

namespace queries {

LUBM::LUBM() {
    // TODO Auto-generated constructor stub

}

LUBM::~LUBM() {
    // TODO Auto-generated destructor stub
}


void LUBM::q01() {
    /*  SELECT ?X
     *  ?X a :GraduateStudent .
     *	?X :takesCourse <http://www.Department0.University0.edu/GraduateCourse0> . <<<< ------- THE CONSTRAIN
     */

    KEY_ID o = diplo::KM.Get("<http://www.Department0.University0.edu/GraduateCourse0>");
    KEY_ID p = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>");

    KEY_ID t = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent>");
    KEY_ID type = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");

    vector<QueryBGP> graph;
    {
        QueryBGP patern;
        patern.predicate.second = p;
        patern.object.second = o;
        graph.push_back(patern);
    }
    {
        QueryBGP patern;
        patern.subject.first = QF_PROJECTION;
        patern.predicate.second = type;
        patern.object.second = t;
        graph.push_back(patern);
    }

  
    unordered_map<KEY_ID, unordered_set<Molecule*> > results;
    diplo::M.GetMoleculesPO(graph,results);

    for(auto m : results[0]) {
      cout << diplo::KM.Get(m->s) << endl;
    }

}

void LUBM::q02() {
//	/*
//	 * SELECT ?X ?Y ?Z
//
//		?Z a :Department .
//		?Z :subOrganizationOf ?Y . <----- FIRST CONST
//		?Y a :University .
  
//		?X a :GraduateStudent .
//		?X :undergraduateDegreeFrom ?Y . <----- SECOND CONST
//		?X :memberOf ?Z . <----- THIRD CONST
//	 *
//	 */
//
// what-if??
//  departemenr11.university3 IS NOT suborfanization of Univeristy3
//	and 
 // <http://www.Department11.University3.edu/GraduateStudent86>	is member of 	departemenr19.university3
	

    KEY_ID Department = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Department>");
    KEY_ID University = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#University>");
    KEY_ID subOrganizationOf = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>");
    KEY_ID GraduateStudent = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent>"); //FIXME
    KEY_ID undergraduateDegreeFrom = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>");
    KEY_ID memberOf = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>");
    KEY_ID type = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");

    for (auto gradstud : *diplo::M.GetMoleculesO(GraduateStudent) ) {
      if ( gradstud -> CheckIfEntityExists(type, GraduateStudent) == false) continue;
      KEY_ID x =  gradstud->s;
      for (auto z : *gradstud->GetObjects(undergraduateDegreeFrom) )  {
	if ( diplo::M.Get (z ) -> CheckIfEntityExists(type, University) == false) continue;
	for (auto y : *gradstud->GetObjects(memberOf) )  {		
	  auto dep = diplo::M.Get (y ) ;
	  if ( dep -> CheckIfEntityExists(type, Department) == false) continue;
	  if ( dep -> CheckIfEntityExists(subOrganizationOf, z) == false) continue;
	  
	  cout << diplo::KM.Get(x) << "\t" << diplo::KM.Get(y) << "\t" << diplo::KM.Get(z) << endl;
	}
      }
    }
    

PERF_PROF
}

void LUBM::q02H() {
//	/*
//	 * SELECT ?X ?Y ?Z
//
//		?Z a :Department .
//		?Z :subOrganizationOf ?Y . <----- FIRST CONST
//		?Y a :University .
  
//		?X a :GraduateStudent .
//		?X :undergraduateDegreeFrom ?Y . <----- SECOND CONST
//		?X :memberOf ?Z . <----- THIRD CONST
//	 *
//	 */
//
// what-if??
//  departemenr11.university3 IS NOT suborfanization of Univeristy3
//	and 
 // <http://www.Department11.University3.edu/GraduateStudent86>	is member of 	departemenr19.university3
	

    KEY_ID Department = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Department>");
    KEY_ID University = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#University>");
    KEY_ID subOrganizationOf = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>");
    KEY_ID GraduateStudent = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent>"); //FIXME
    KEY_ID undergraduateDegreeFrom = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>");
    KEY_ID memberOf = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>");
    KEY_ID type = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");
int i = 0 ;
    for (auto gradstud : *diplo::M.GetMoleculesO(GraduateStudent) ) {
      KEY_ID x =  gradstud->s;
      
      auto gradstud_mod = diplo::H_mod.Get(x);
      auto gradstud_neg = diplo::H_neg.Get(x);    
      
      if ( gradstud -> CheckIfEntityExists(type, GraduateStudent) == false ) continue; 
      
      for (auto z : *gradstud->GetObjects(undergraduateDegreeFrom) )  {	
	if ( diplo::M.Get (z ) -> CheckIfEntityExists(type, University) == false) continue;
	
	
	for (auto y : *gradstud->GetObjects(memberOf) )  {
	  
	  //H
	  if ( gradstud_neg != NULL and gradstud_neg -> CheckIfEntityExists(memberOf, y) == true) continue;
	  
	  auto dep = diplo::M.Get (y ) ;
	  if ( dep -> CheckIfEntityExists(type, Department) == false) continue;
	  if ( dep -> CheckIfEntityExists(subOrganizationOf, z) == false) continue;
	  
	  //H
	  auto dep_neg = diplo::H_neg.Get(y); if ( dep_neg != NULL and dep_neg -> CheckIfEntityExists(subOrganizationOf, z) == true) continue;
	  
	  cout << diplo::KM.Get(x) << "\t" << diplo::KM.Get(y) << "\t" << diplo::KM.Get(z) << endl;
	}
	
// 	//H
	if(gradstud_mod == NULL) continue; 
 	for (auto y : *gradstud_mod->GetObjects(memberOf) )  { 
	  auto dep = diplo::M.Get (y ) ;
	  if ( dep -> CheckIfEntityExists(type, Department) == false) continue;
	  if ( dep -> CheckIfEntityExists(subOrganizationOf, z) == false) continue;
	  
	  //H
	  auto dep_neg = diplo::H_neg.Get(y); if ( dep_neg != NULL and dep_neg -> CheckIfEntityExists(subOrganizationOf, z) == true) continue;
	  
	  cout << diplo::KM.Get(x) << "\t" << diplo::KM.Get(y) << "\t" << diplo::KM.Get(z) << endl;
 	}
	
      }
      
      
      
    }
     cout << i << endl;

PERF_PROF
}

void LUBM::q08() {
//	SELECT ?X, ?Y, ?Z WHERE {
//   		?Y ub:subOrganizationOf <http://www.University0.edu> .
//		?Y rdf:type ub:Department .
//   		?X ub:memberOf ?Y .
//		?X rdf:type ub:Student .   		
//   		?X ub:emailAddress ?Z}
  
// what-if? ----- Departemenr3.university0 DID NOT EXIST!!!

    KEY_ID Student = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Student>" );
    KEY_ID Department = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Department>" );
    KEY_ID type = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");
    KEY_ID memberOf = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
    KEY_ID subOrganizationOf = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
    KEY_ID University0 = diplo::KM.Get ( "<http://www.University0.edu>" );
    KEY_ID emailAddress = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
   
    
    
    //Student subClasses
    KEY_ID GraduateStudent = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent>" );
    KEY_ID ResearchAssistant = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#ResearchAssistant>" );
    KEY_ID UndergraduateStudent = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#UndergraduateStudent>" );
      
    for (auto _y : *diplo::M.GetMoleculesO(University0) ) {
	if ( _y -> CheckIfEntityExists(subOrganizationOf, University0) == false) continue;
	if ( _y -> CheckIfEntityExists(type, Department) == false) continue;
	KEY_ID y = _y->s; 
	for (auto _x : *diplo::M.GetMoleculesO( y )  ) {
	  if ( _x -> CheckIfEntityExists(memberOf, y) == false) continue;
	  if ( _x -> CheckIfEntityExists(type, Student) == false and 
	    _x -> CheckIfEntityExists(type, GraduateStudent) == false and 
	    _x -> CheckIfEntityExists(type, ResearchAssistant) == false and 
	    _x -> CheckIfEntityExists(type, UndergraduateStudent) == false  
	  ) continue;  
	  KEY_ID x = _x->s;
	  auto _z = _x -> GetObjects(emailAddress);  
	  if (_z == NULL) continue;  
	  for (auto z : *_z ) {
	     //diplo::KM.Get(x) ; diplo::KM.Get(y); diplo::KM.Get(z) ;
	    cout << diplo::KM.Get(x) << "\t" << diplo::KM.Get(y) << "\t" << diplo::KM.Get(z) << endl;
	  }
	}
    }
    PERF_PROF
}



}
