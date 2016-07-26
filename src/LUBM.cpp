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
	
	
	//for (auto y : *gradstud->GetObjects(memberOf) )  {
	//for (auto y : make_iterator_pair (*gradstud->GetObjects(memberOf), *gradstud_mod->GetObjects(memberOf)) )  {

	auto it = gradstud->GetObjects(memberOf);
	auto it_mod = gradstud_mod != NULL ? gradstud_mod->GetObjects(memberOf) : NULL;
	//it_mod == NULL;
	if (it == NULL) continue;
	for (unordered_set<KEY_ID>::const_iterator h = it->begin(); ; h++ ) {
	  
	   
	  if (h == it->end()) {
	    if (it_mod == NULL) break;
	      h = it_mod->begin();
	      it_mod = NULL;
	  }
	  
	 auto y = *h;
	 
	  //H
	  if ( gradstud_neg != NULL and gradstud_neg -> CheckIfEntityExists(memberOf, y) == true) continue;
	  
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
  
  //add some hypotheses on rdf:type ub:Student (owl#GraduateStudent, owl#ResearchAssistant, owl#UndergraduateStudent)
  //maybe some hypotheses on ONTOLOGY!!!!!!!! COOL

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


void LUBM::q09() {
//    Besides the aforementioned features of class Student and the wide hierarchy of
// # class Faculty, like Query 2, this query is characterized by the most classes and
// # properties in the query set and there is a triangular pattern of relationships.
// SELECT ?X, ?Y, ?Z
// WHERE
// { ?Y rdf:type ub:Faculty .
//  ?X rdf:type ub:Student .
//   ?Z rdf:type ub:Course .
//   ?X ub:advisor ?Y .
//   ?Y ub:teacherOf ?Z .
//   ?X ub:takesCourse ?Z}
  
    KEY_ID Student = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Student>" );
    KEY_ID Faculty = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Faculty>" );
    KEY_ID Course = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Course>" );
    KEY_ID type = diplo::KM.Get ( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
    KEY_ID advisor = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#advisor>" );
    KEY_ID teacherOf = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#teacherOf>" );
    KEY_ID takesCourse = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );


    //Faculty subClasses
    vector< KEY_ID > FacultySubClasses;
    FacultySubClasses.push_back( Faculty );
    FacultySubClasses.push_back( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Lecturer>" ) ); 
    FacultySubClasses.push_back( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#PostDoc>" ) ); 
    FacultySubClasses.push_back( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Professor>" ) );
    FacultySubClasses.push_back ( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#AssistantProfessor>" ) );
    FacultySubClasses.push_back ( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#AssociateProfessor>" ) );
    FacultySubClasses.push_back ( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Chair>" ) );
    FacultySubClasses.push_back ( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Dean>" ) );
    FacultySubClasses.push_back ( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#FullProfessor>" ) );
    FacultySubClasses.push_back ( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#VisitingProfessor>" ) );
    

    //Student subClasses
    vector< KEY_ID > StudentSubClasses;
    StudentSubClasses.push_back( Student );
    StudentSubClasses.push_back( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent>" ) ); 
    StudentSubClasses.push_back( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#ResearchAssistant>" ) );
    StudentSubClasses.push_back( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#UndergraduateStudent>" ) ); 


    //Course subClasses
    vector< KEY_ID > CourseSubClasses;
    CourseSubClasses.push_back( Course );
    CourseSubClasses.push_back( diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateCourse>" ) ); 


    for (auto t : FacultySubClasses) {
      auto faculties  = diplo::M.GetMoleculesO( t );
      if ( faculties == NULL ) continue;
      for (auto faculty : *faculties ) {
	
	if ( faculty -> CheckIfEntityExists(type, t) == false) continue;
	auto y = faculty->s;
	
	auto courses = faculty->GetObjects ( teacherOf );
	auto students = diplo::M.GetMoleculesO ( faculty->s );
	if (students == NULL or  courses == NULL) continue;
	
	for (auto studentM : *students) {
	 if ( studentM-> CheckIfEntityExists(advisor, faculty->s) == false) continue;
	  
	  bool student_type = false;
	  for (auto tl : StudentSubClasses)
	    if ( studentM -> CheckIfEntityExists(type, tl) == true) {student_type = true;break;}
	    
	  if (student_type == false) continue;
	  
	  auto x = studentM ->s;
	  
	  for (auto course : *courses) { 
	    
	    auto courseM = diplo::M.Get ( course ) ;
	    bool course_type = false;
	    for (auto tl : CourseSubClasses)
	      if ( courseM -> CheckIfEntityExists(type, tl) == true) {course_type = true;break;}
	    if (course_type == false) continue;
	    
	    if ( faculty-> CheckIfEntityExists(teacherOf, course) == false) continue;
	    if ( studentM-> CheckIfEntityExists(takesCourse, course) == false) continue;
	    auto z = course;
	    
	    cout << diplo::KM.Get(x) << "\t" << diplo::KM.Get(y) << "\t" << diplo::KM.Get(z) << endl;
	  }
	      
	}

      }
    }
    
   
      
}


void LUBM::q12() {
//   # The benchmark data do not produce any instances of class Chair. Instead, each
// # Department individual is linked to the chair professor of that department by 
// # property headOf. Hence this query requires realization, i.e., inference that
// # that professor is an instance of class Chair because he or she is the head of a
// # department. Input of this query is small as well.
  
  
  ///we do hypotheses on headOf, before reasoning, cool!!
  
// SELECT ?X, ?Y
// WHERE
// {
//   ?Y ub:subOrganizationOf <http://www.University0.edu> .
//   ?Y rdf:type ub:Department .
//	?X rdf:type ub:Chair . ---- headOf
//	?X ub:worksFor ?Y .

   // KEY_ID Chair = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Chair>" );
    KEY_ID Department = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Department>" );
    KEY_ID type = diplo::KM.Get ( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
    KEY_ID worksFor = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#worksFor>" );
    KEY_ID headOf = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#headOf>" );
    KEY_ID subOrganizationOf = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
    KEY_ID University0 = diplo::KM.Get ( "<http://www.University0.edu>" );
  
    
    
    for ( auto _y : *diplo::M.GetMoleculesO ( University0 ) ) {
        if ( _y -> CheckIfEntityExists ( subOrganizationOf, University0 ) == false ) continue;
        if ( _y -> CheckIfEntityExists ( type, Department ) == false ) continue;
        KEY_ID y = _y->s;
	
	for (auto _x : *diplo::M.GetMoleculesO( y )  ) {
	  if ( _x -> CheckIfEntityExists(worksFor, y) == false) continue;
	  if ( _x -> CheckIfEntityExists(headOf, y) == false ) continue; 
	  KEY_ID x = _x->s;
	  cout << diplo::KM.Get(x) << "\t" << diplo::KM.Get(y) << endl;
	}
	
    }
    
}

void LUBM::q13() {

// # Property hasAlumnus is defined in the benchmark ontology as the inverse of
// # property degreeFrom, which has three subproperties: undergraduateDegreeFrom, 
// # mastersDegreeFrom, and doctoralDegreeFrom. The benchmark data state a person as
// # an alumnus of a university using one of these three subproperties instead of
// # hasAlumnus. Therefore, this query assumes subPropertyOf relationships between 
// # degreeFrom and its subproperties, and also requires inference about inverseOf.

// do hypoteses on ONTOLOGY  
// CHANGE SOMEHINGH HERE: "degreeFrom, which has three subproperties: undergraduateDegreeFrom, 
// # mastersDegreeFrom, and doctoralDegreeFrom. "
// or remove 
// Property hasAlumnus is defined in the benchmark ontology as the inverse of
// # property degreeFrom, 
// and change the name of degreeFrom 

// PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
// PREFIX ub: <http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#>
// SELECT ?X
// WHERE
// {?X rdf:type ub:Person .
//   <http://www.University0.edu> ub:hasAlumnus ?X}

    //KEY_ID Person = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Person>" ); //<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent> 
    KEY_ID hasAlumnus = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#hasAlumnus>" );
    KEY_ID University0 = diplo::KM.Get ( "<http://www.University0.edu>" );
    
    KEY_ID inverseOf = diplo::KM.Get ( "<http://www.w3.org/2002/07/owl#inverseOf>" );
    KEY_ID subPropertyOf = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#subPropertyOf>" ); 
    
    //Course subClasses
    vector< KEY_ID > props;
       
    for ( auto hasAlumnusM : *diplo::M.GetMoleculesO ( hasAlumnus ) ) {
      if ( hasAlumnusM -> CheckIfEntityExists ( inverseOf, hasAlumnus ) == false ) continue;
      
      for ( auto degreeFromM : *diplo::M.GetMoleculesO ( hasAlumnusM->s ) ) {
	if ( degreeFromM -> CheckIfEntityExists ( subPropertyOf, hasAlumnusM->s ) == false ) continue;
	
	props.push_back( degreeFromM->s ) ;
      }

    }
    
    
    
    for ( auto _x : *diplo::M.GetMoleculesO ( University0 ) ) {
      
      bool pr = false;
      for ( auto p : props ) {
	if ( _x  -> CheckIfEntityExists ( p, University0 ) == false ) continue;
	else {pr = true; break;}
      }
      if ( pr == false ) continue;
      
       cout << diplo::KM.Get(_x->s) <<  endl;
    }
       
  
}

}
