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

    TYPE_ID t = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent>");
    TYPE_ID type = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");

    vector<QueryGraph> graph;
    {
        QueryGraph patern;
        patern.predicate.second = p;
        patern.object.second = o;
        graph.push_back(patern);
    }
    {
        QueryGraph patern;
        patern.subject.first = QF_PROJECTION;
        patern.predicate.second = type;
        patern.object.second = t;
        graph.push_back(patern);
    }

    unordered_multimap<KEY_ID, vector<KEY_ID> > results;
    API::TriplePatern(graph,results, '0');
	API::DisplayResults(results,1);

}

void LUBM::q02() {
//	/*
//	 * SELECT ?X ?Y ?Z
//
//		?Z a :Department .
//		?Z :subOrganizationOf ?Y . <----- FIRST CONST
//		?Y a :University .
//
//		?X a :GraduateStudent .
//		?X :undergraduateDegreeFrom ?Y . <----- SECOND CONST
//		?X :memberOf ?Z . <----- THIRD CONST
//	 *
//	 */
//

    TYPE_ID Department = diplo::KM.GetSeq("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Department>");
    TYPE_ID University = diplo::KM.GetSeq("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#University>");

    TYPE_ID GraduateStudent = diplo::KM.GetSeq("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#GraduateStudent>"); //FIXME

    KEY_ID subOrganizationOf = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>");

    KEY_ID undergraduateDegreeFrom = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>");
    KEY_ID memberOf = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>");
    TYPE_ID type = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");

    unordered_multimap<KEY_ID, vector<KEY_ID> > results1, results2;

    {
        vector<QueryGraph> graph;
        {
            QueryGraph patern;
            patern.predicate.second = type;
            patern.object.second = Department;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.subject.first = QF_PROJECTION;
            patern.predicate.second = subOrganizationOf;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }


        API::TriplePatern(graph, results1, 's');
//		API::DisplayResults(results1, 1);
    }
    {
        vector<QueryGraph> graph;
        {
            QueryGraph patern;
            patern.subject.first = QF_PROJECTION;
            patern.predicate.second = type;
            patern.object.second = University;
            graph.push_back(patern);
        }
        API::TriplePatern(graph, results2, 's');
//		API::DisplayResults(results2, 1);
    }

    for (unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator it = results1.begin(); it != results1.end(); it++) {
        for (vector<KEY_ID>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++) {
            it1++;
            if ( results2.find(*it1) == results2.end() ) break;
            {
                vector<QueryGraph> graph;
                {
                    QueryGraph patern;
                    patern.predicate.second = memberOf;
                    patern.object.first = QF_PROJECTION;
                    patern.object.second = it->first;
                    graph.push_back(patern);
                }
                {
                    QueryGraph patern;
                    patern.subject.first = QF_PROJECTION;
                    patern.predicate.second = type;
                    patern.object.second = GraduateStudent;
                    graph.push_back(patern);
                }
                {
                    QueryGraph patern;
                    patern.predicate.second = undergraduateDegreeFrom;
                    patern.object.first = QF_PROJECTION;
                    patern.object.second = *it1;
                    graph.push_back(patern);
                }


                unordered_multimap<KEY_ID, vector<KEY_ID> > results;
                API::TriplePatern(graph, results, '0');
                //API::DisplayResults(results, 3);
            }
        }
    }

}

void LUBM::q03() {
    /*
     * SELECT ?X
     * ?X a :Publication .
     * ?X :publicationAuthor <http://www.Department0.University0.edu/AssistantProfessor0> .   <---- THE CONSTRAIN
     *
     */

    KEY_ID o = diplo::KM.Get("<http://www.Department0.University0.edu/AssistantProfessor0>");
    TYPE_ID Publication = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Publication>");
    KEY_ID p = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#publicationAuthor>");
    TYPE_ID type = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");

    vector<QueryGraph> graph;
    {
        QueryGraph patern;
        patern.predicate.second = p;
        patern.object.second = o;
        graph.push_back(patern);
    }
    {
        QueryGraph patern;
        patern.subject.first = QF_PROJECTION;
        patern.predicate.second = type;
        patern.object.second = Publication;
        graph.push_back(patern);
    }

    unordered_multimap<KEY_ID, vector<KEY_ID> > results;
    API::TriplePatern(graph,results, '0');
    API::DisplayResults(results,0);



}

void LUBM::q04() {
    /*
    SELECT ?X ?Y1 ?Y2 ?Y3
        ?t rdfs:subClassOf :Professor .
        ?X a ?t .
        ?X :worksFor <http://www.Department0.University0.edu> .

        ?X :name ?Y1 .
        ?X :emailAddress ?Y2 .
        ?X :telephone ?Y3 .
     */
    set<TYPE_ID> ProfessorAndSubClasses = TH.GetHierarchyForType ( diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#Professor>") );

    KEY_ID o = diplo::KM.Get("<http://www.Department0.University0.edu>");
    KEY_ID worksFor = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#worksFor>");

    KEY_ID name = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>");
    KEY_ID emailAddress = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>");
    KEY_ID telephone = diplo::KM.Get("<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>");

    TYPE_ID type = diplo::KM.Get("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");


    unordered_multimap<KEY_ID, vector<KEY_ID> > results;
    for (set<TYPE_ID>::iterator it = ProfessorAndSubClasses.begin(); it != ProfessorAndSubClasses.end(); it++) {
        vector<QueryGraph> graph;
        {
            QueryGraph patern;
            patern.predicate.second = type;
            patern.object.second = *it;
            graph.push_back(patern);
        }

        {
            QueryGraph patern;
            patern.predicate.second = worksFor;
            patern.object.second = o;
            graph.push_back(patern);
        }

        {
            QueryGraph patern;
            patern.subject.first = QF_PROJECTION;
            patern.predicate.second = name;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.predicate.second = emailAddress;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.predicate.second = telephone;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }
        API::TriplePatern(graph, results, '0');
    }
    
    API::DisplayResults(results,4);

}


void LUBM::triangleTemplates() {
    /*
     * select * where  {
     *  ?X :name ?Z1 .
     *  ?X :memberOf ?Z2 .
     *  ?X :undergraduateDegreeFrom ?Z3 .
     *  ?X :takesCourse ?Z4 .
     *  ?X :emailAddress ?Z5 .
     *  ?X :telephone ?Z6 .
     *  
     *  ?Z2 :name ?Y1
     *  ?Z2 :subOrganizationOf ?Z3
     *  ?Z2 :type ?Y3   
}
*/
    
    KEY_ID name         = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
    KEY_ID memberOf       = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
    KEY_ID undergraduateDegreeFrom  = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
    KEY_ID takesCourse      = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
    KEY_ID emailAddress       = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
    KEY_ID telephone      = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
    KEY_ID subOrganizationOf    = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
    KEY_ID type       = diplo::KM.Get( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
    
    int nom = 0 ;
    

    unordered_set<unordered_set<KEY_ID>*> templates1;
    { // first template
        auto &Tname = TM.PredicateTemplates.find(name)->second; //9
        auto &TmemberOf = TM.PredicateTemplates.find(memberOf)->second; //3
        auto &TundergraduateDegreeFrom = TM.PredicateTemplates.find(undergraduateDegreeFrom)->second; //5 
        auto &TtakesCourse = TM.PredicateTemplates.find(takesCourse)->second; //3 
        auto &TemailAddress = TM.PredicateTemplates.find(emailAddress)->second; //6 
        auto &Ttelephone = TM.PredicateTemplates.find(telephone)->second; //6
        
  
        
        
        for (auto &tmpl : TmemberOf ) {
            if ( Tname.find(tmpl) == Tname.end() ) continue;
            if ( TundergraduateDegreeFrom.find(tmpl) == TundergraduateDegreeFrom.end() ) continue;
            if ( TtakesCourse.find(tmpl) == TtakesCourse.end() ) continue;
            if ( TemailAddress.find(tmpl) == TemailAddress.end() ) continue;
            if ( Ttelephone.find(tmpl) == Ttelephone.end() ) continue;
            
            auto ms = &(TM.TemplateMolecules.find(tmpl)->second);
            templates1.insert(ms);
        }
    }
    
    int i = 0;
    { //second template
        auto &Tname = TM.PredicateTemplates.find(name)->second; //9
        auto &TsubOrganizationOf = TM.PredicateTemplates.find(subOrganizationOf)->second; //2
        auto &Ttype = TM.PredicateTemplates.find(type)->second; //15
        
        
        
        for (auto &tmpl : TsubOrganizationOf ) {
            if ( Tname.find(tmpl) == Tname.end() ) continue;
            if ( Ttype.find(tmpl) == Ttype.end() ) continue;

            auto &ms = TM.TemplateMolecules.find(tmpl)->second;

            for (auto m : ms ) {
                auto &preds = M.molecules.find(m)->second;
                 
                for ( auto SSmemberOf : preds.find ( (memberOf | PredMask) )->second ) {
                    bool takeit = false;
                    for (auto t : templates1) { 
                        if ( t->find(SSmemberOf) != t->end() ) {
                            takeit = true;
                            break;
                        }
                    }
     
                    if (!takeit) continue;
                    
                    auto &preds_SSmemberOf = M.molecules.find(SSmemberOf)->second;
                
                    
                    
                    
                    //second 
                    for ( auto OsubOrganizationOf : preds.find ( subOrganizationOf )->second ) {
                        for ( auto Oundergraduatedegreefrom : preds_SSmemberOf.find ( undergraduateDegreeFrom )->second ) {
                            if (OsubOrganizationOf != Oundergraduatedegreefrom) continue;

                        
                      for ( auto Oname2 : preds.find ( name )->second ) {
                        for ( auto Otype : preds.find ( type )->second ) {

                            
                           
                            for ( auto Omemberof : preds_SSmemberOf.find ( memberOf )->second ) {
                                for ( auto Oname : preds_SSmemberOf.find ( name )->second ) {
                                    
                                        for ( auto Otakescourse : preds_SSmemberOf.find ( takesCourse )->second ) {
                                            for ( auto Oemailaddress : preds_SSmemberOf.find ( emailAddress )->second ) {
                                                for ( auto Otelephone : preds_SSmemberOf.find ( telephone )->second ) {

i++;

                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            



                            }
                        }
                    }
                    
                    
                    
                    
                    
                    
                    
                }
                                                    
          
            }
        }
    } //second template
    
    cout << "# " << i << endl;

}

void LUBM::predQuery() {
/*
  select * where  {
    ?X :name ?Z1 .
    ?X :memberOf ?Z1 .
    ?X :undergraduateDegreeFrom ?Z2 .
    ?X :takesCourse ?Z3 .
    ?X :emailAddress ?Z4 .
    ?X :telephone ?Z5 .
  }
*/
  KEY_ID name 				= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
  KEY_ID memberOf 			= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
  KEY_ID undergraduateDegreeFrom 	= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
  KEY_ID takesCourse 			= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
  KEY_ID emailAddress 			= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
  KEY_ID telephone 			= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
 
  
  auto &Tname = TM.PredicateTemplates.find(name)->second; //9
  auto &TmemberOf = TM.PredicateTemplates.find(memberOf)->second; //3
  auto &TundergraduateDegreeFrom = TM.PredicateTemplates.find(undergraduateDegreeFrom)->second; //5 
  auto &TtakesCourse = TM.PredicateTemplates.find(takesCourse)->second; //3 
  auto &TemailAddress = TM.PredicateTemplates.find(emailAddress)->second; //6 
  auto &Ttelephone = TM.PredicateTemplates.find(telephone)->second; //6
  
  unordered_set<KEY_ID> templates;
  unordered_set<KEY_ID> moleculesDone;
  
  for (auto tmpl : TmemberOf ) {
    if ( Tname.find(tmpl) == Tname.end() ) continue;
    if ( TundergraduateDegreeFrom.find(tmpl) == TundergraduateDegreeFrom.end() ) continue;
    if ( TtakesCourse.find(tmpl) == TtakesCourse.end() ) continue;
    if ( TemailAddress.find(tmpl) == TemailAddress.end() ) continue;
    if ( Ttelephone.find(tmpl) == Ttelephone.end() ) continue;
    
    templates.insert(tmpl);
  }
  
  //cout << "# templates: " << templates.size() << endl;
   
  int i=0;
  for (auto tmpl : templates ) {
    auto &ms = TM.TemplateMolecules.find(tmpl)->second;
    for (auto m : ms ) {
      
     pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert(m) ;
     if (INSmoleculesDone.second == false ) continue; // this molecule was already done
      
      auto preds = M.molecules.find(m)->second;
      for ( auto Oname : preds.find(name)->second ) {
	for ( auto Omemberof : preds.find(memberOf)->second ) {
	  for ( auto Oundergraduatedegreefrom : preds.find(undergraduateDegreeFrom)->second ) {
	    for ( auto Otakescourse : preds.find(takesCourse)->second ) {
	      for ( auto Oemailaddress : preds.find(emailAddress)->second ) {
		for ( auto Otelephone : preds.find(telephone)->second ) {
		  cout << KM.Get( m ) << "\t"
		    << KM.Get( Oname ) << "\t" 
		    << KM.Get( Omemberof ) << "\t" 
		    << KM.Get( Oundergraduatedegreefrom ) << "\t"
		    << KM.Get( Otakescourse ) << "\t" 
		    << KM.Get( Oemailaddress ) << "\t" 
		    << KM.Get( Otelephone ) << "\t" 
		    << endl;
		    i++;
		}
	      }
	    }
	  }
	}
      }
    }   
  }
  cout << "# " << i << endl;      
}

void LUBM::pathQueryPredicates() {
/*
     * select * where  {
     *  ?X :name ?Z1 .
     *  ?X :memberOf ?Z2 .
     *  ?X :undergraduateDegreeFrom ?Z3 .
     *  ?X :takesCourse ?Z4 .
     *  ?X :emailAddress ?Z5 .
     *  ?X :telephone ?Z6 .
     *  
     *  ?Z2 :name ?Y1
     *  ?Z2 :subOrganizationOf ?Y2
     *  ?Z2 :type ?Y3   
}
*/
    KEY_ID name              = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
    KEY_ID memberOf           = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
    KEY_ID undergraduateDegreeFrom    = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
    KEY_ID takesCourse            = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
    KEY_ID emailAddress           = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
    KEY_ID telephone          = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
    KEY_ID subOrganizationOf      = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
    KEY_ID type           = diplo::KM.Get ( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );

    
    auto &Mname = TM.PredicateMolecules.find(name)->second; //76523
    auto &MmemberOf = TM.PredicateMolecules.find(memberOf)->second; //37114
    auto &MundergraduateDegreeFrom = TM.PredicateMolecules.find(undergraduateDegreeFrom)->second; //11677
    auto &MtakesCourse = TM.PredicateMolecules.find(takesCourse)->second; //37114
    auto &MemailAddress = TM.PredicateMolecules.find(emailAddress)->second; //39697
    auto &Mtelephone = TM.PredicateMolecules.find(telephone)->second; //39697

    auto &MsubOrganizationOf = TM.PredicateMolecules.find(subOrganizationOf)->second; //1131
    auto &Mtype = TM.PredicateMolecules.find(type)->second; //78655
    

    unordered_set<KEY_ID> moleculesZ2;
    for ( auto m : MsubOrganizationOf) {
        if ( Mtype.find(m) == Mtype.end() ) continue;
        if ( Mname.find(m) == Mname.end() ) continue;
        
        moleculesZ2.insert(m);
    }
  
  int i = 0;
    
    for ( auto m : MundergraduateDegreeFrom) {
        if ( Mname.find(m) == Mname.end() ) continue;
        if ( MmemberOf.find(m) == MmemberOf.end() ) continue;
        if ( MtakesCourse.find(m) == MtakesCourse.end() ) continue;
        if ( MemailAddress.find(m) == MemailAddress.end() ) continue;
        if ( Mtelephone.find(m) == Mtelephone.end() ) continue;

        auto &preds = M.molecules.find ( m )->second;
        for ( auto Omemberof : preds.find ( memberOf )->second ) {
            if ( moleculesZ2.find ( Omemberof ) == moleculesZ2.end() ) continue;

            auto preds_memberof = M.molecules.find ( Omemberof )->second;

            for ( auto Oname : preds.find ( name )->second ) {
                for ( auto Oundergraduatedegreefrom : preds.find ( undergraduateDegreeFrom )->second ) {
                    for ( auto Otakescourse : preds.find ( takesCourse )->second ) {
                        for ( auto Oemailaddress : preds.find ( emailAddress )->second ) {
                            for ( auto Otelephone : preds.find ( telephone )->second ) {

                                //second
                                for ( auto Oname2 : preds_memberof.find ( name )->second ) {
                                    for ( auto OsubOrganizationOf : preds_memberof.find ( subOrganizationOf )->second ) {
                                        for ( auto Otype : preds_memberof.find ( type )->second ) {
                                            i++;
                                        }
                                    }
                                }
                                
                            }
                        }
                    }
                }
            }
        }
        
        
    }
    
    cout << "# " << i << endl;
}

void LUBM::pathQueryTemplates() {
/*
  select * where  {
    ?X :name ?Z1 .
    ?X :memberOf ?Z2 .
    ?X :undergraduateDegreeFrom ?Z3 .
    ?X :takesCourse ?Z4 .
    ?X :emailAddress ?Z5 .
    ?X :telephone ?Z6 .
    
    ?Z2 :name ?Y1
    ?Z2 :subOrganizationOf ?Y2
    ?Z2 :type ?Y3   
  }
*/


  KEY_ID name 				= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
  KEY_ID memberOf 			= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
  KEY_ID undergraduateDegreeFrom 	= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
  KEY_ID takesCourse 			= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
  KEY_ID emailAddress 			= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
  KEY_ID telephone 			= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
  KEY_ID subOrganizationOf 		= diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
  KEY_ID type 			= diplo::KM.Get( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
 

  unordered_set<KEY_ID> moleculesZ2;
  { //second template
        auto &Tname = TM.PredicateTemplates.find ( name )->second; //9
        auto &TsubOrganizationOf = TM.PredicateTemplates.find ( subOrganizationOf )->second; //2
        auto &Ttype = TM.PredicateTemplates.find ( type )->second; //15


        for ( auto tmpl : TsubOrganizationOf ) {
            if ( 
                    Tname.find ( tmpl ) == Tname.end() or
                    Ttype.find ( tmpl ) == Ttype.end() 
            ) continue;

    
            auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
            for ( auto m : ms ) {

                moleculesZ2.insert ( m );
            }
        }
           
  } //second template

  int i=0;
  
  { // first template
        auto &Tname = TM.PredicateTemplates.find ( name )->second; //9
        auto &TmemberOf = TM.PredicateTemplates.find ( memberOf )->second; //3
        auto &TundergraduateDegreeFrom = TM.PredicateTemplates.find ( undergraduateDegreeFrom )->second; //5
        auto &TtakesCourse = TM.PredicateTemplates.find ( takesCourse )->second; //3
        auto &TemailAddress = TM.PredicateTemplates.find ( emailAddress )->second; //6
        auto &Ttelephone = TM.PredicateTemplates.find ( telephone )->second; //6

        unordered_set<KEY_ID> templates;
        unordered_set<KEY_ID> moleculesDone;

        for ( auto tmpl : TmemberOf ) {
            if (    
                    Tname.find ( tmpl ) == Tname.end() or
                    TundergraduateDegreeFrom.find ( tmpl ) == TundergraduateDegreeFrom.end()  or
                    TtakesCourse.find ( tmpl ) == TtakesCourse.end()  or
                    TemailAddress.find ( tmpl ) == TemailAddress.end() or
                    Ttelephone.find ( tmpl ) == Ttelephone.end() 
                ) 
                continue;


 
            auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
            for ( auto m : ms ) {

                pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
                if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done


                auto &preds = M.molecules.find ( m )->second;
                for ( auto Omemberof : preds.find ( memberOf )->second ) {
                    if ( moleculesZ2.find ( Omemberof ) == moleculesZ2.end() ) continue;

                    auto &preds_memberof = M.molecules.find ( Omemberof )->second;

                    for ( auto Oname : preds.find ( name )->second ) {
                        for ( auto Oundergraduatedegreefrom : preds.find ( undergraduateDegreeFrom )->second ) {
                            for ( auto Otakescourse : preds.find ( takesCourse )->second ) {
                                for ( auto Oemailaddress : preds.find ( emailAddress )->second ) {
                                    for ( auto Otelephone : preds.find ( telephone )->second ) {

                                        //second
                                        for ( auto Oname2 : preds_memberof.find ( name )->second ) {
                                            for ( auto OsubOrganizationOf : preds_memberof.find ( subOrganizationOf )->second ) {
                                                for ( auto Otype : preds_memberof.find ( type )->second ) {

// 			cout << KM.Get( m ) << "\t"
// 			  << KM.Get( Oname ) << "\t"
// 			  << KM.Get( Omemberof ) << "\t"
// 			  << KM.Get( Oundergraduatedegreefrom ) << "\t"
// 			  << KM.Get( Otakescourse ) << "\t"
// 			  << KM.Get( Oemailaddress ) << "\t"
// 			  << KM.Get( Otelephone ) << "\t"
// 			  << KM.Get( Oname2 ) << "\t"
// 			  << KM.Get( OsubOrganizationOf ) << "\t"
// 			  << KM.Get( Otype ) << "\t"
// 			  << endl;
                                                    i++;
                                                    }
                                                }
                                            }


                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

        cout << "# " << i << endl;
  } // first template 
}



void LUBM::pathQueryTemplates2() { //bidirectional molecules
    /*
     * select * where  {
     *  ?X :name ?Z1 .
     *  ?X :memberOf ?Z2 .
     *  ?X :undergraduateDegreeFrom ?Z3 .
     *  ?X :takesCourse ?Z4 .
     *  ?X :emailAddress ?Z5 .
     *  ?X :telephone ?Z6 .
     *  
     *  ?Z2 :name ?Y1
     *  ?Z2 :subOrganizationOf ?Y2
     *  ?Z2 :type ?Y3   
}
*/
    
    KEY_ID name         = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
    KEY_ID memberOf       = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
    KEY_ID undergraduateDegreeFrom  = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
    KEY_ID takesCourse      = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
    KEY_ID emailAddress       = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
    KEY_ID telephone      = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
    KEY_ID subOrganizationOf    = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
    KEY_ID type       = diplo::KM.Get( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
    
    int nom = 0 ;
    
    
    unordered_set<unordered_set<KEY_ID>*> templates1;
    { // first template
        auto &Tname = TM.PredicateTemplates.find(name)->second; //9
        auto &TmemberOf = TM.PredicateTemplates.find(memberOf)->second; //3
        auto &TundergraduateDegreeFrom = TM.PredicateTemplates.find(undergraduateDegreeFrom)->second; //5 
        auto &TtakesCourse = TM.PredicateTemplates.find(takesCourse)->second; //3 
        auto &TemailAddress = TM.PredicateTemplates.find(emailAddress)->second; //6 
        auto &Ttelephone = TM.PredicateTemplates.find(telephone)->second; //6
        
        
        
        
        for (auto &tmpl : TmemberOf ) {
            if (    
                Tname.find ( tmpl ) == Tname.end() or
                TundergraduateDegreeFrom.find ( tmpl ) == TundergraduateDegreeFrom.end()  or
                TtakesCourse.find ( tmpl ) == TtakesCourse.end()  or
                TemailAddress.find ( tmpl ) == TemailAddress.end() or
                Ttelephone.find ( tmpl ) == Ttelephone.end() 
            ) 
                continue;
            
            auto ms = &(TM.TemplateMolecules.find(tmpl)->second);
            templates1.insert(ms);
        }
    }
    
    int i = 0;
    { //second template
        auto &Tname = TM.PredicateTemplates.find(name)->second; //9
        auto &TsubOrganizationOf = TM.PredicateTemplates.find(subOrganizationOf)->second; //2
        auto &Ttype = TM.PredicateTemplates.find(type)->second; //15
        
        
        
        for (auto &tmpl : TsubOrganizationOf ) {
            if ( Tname.find(tmpl) == Tname.end() ) continue;
            if ( Ttype.find(tmpl) == Ttype.end() ) continue;
            
            auto &ms = TM.TemplateMolecules.find(tmpl)->second;
            
            for (auto m : ms ) {
                auto &preds = M.molecules.find(m)->second;
                
                for ( auto SSmemberOf : preds.find ( (memberOf | PredMask) )->second ) {
                    bool takeit = false;
                    for (auto t : templates1) { 
                        if ( t->find(SSmemberOf) != t->end() ) {
                            takeit = true;
                            break;
                        }
                    }
                    
                    if (!takeit) continue;
                    
                    auto &preds_SSmemberOf = M.molecules.find(SSmemberOf)->second;
                    

                    
                    //second 
                    for ( auto OsubOrganizationOf : preds.find ( subOrganizationOf )->second ) {
                        for ( auto Oundergraduatedegreefrom : preds_SSmemberOf.find ( undergraduateDegreeFrom )->second ) {                       
                            
                            
                            for ( auto Oname2 : preds.find ( name )->second ) {
                                for ( auto Otype : preds.find ( type )->second ) {
                                    
                                    
                                    
                                    for ( auto Omemberof : preds_SSmemberOf.find ( memberOf )->second ) {
                                        for ( auto Oname : preds_SSmemberOf.find ( name )->second ) {
                                            
                                            for ( auto Otakescourse : preds_SSmemberOf.find ( takesCourse )->second ) {
                                                for ( auto Oemailaddress : preds_SSmemberOf.find ( emailAddress )->second ) {
                                                    for ( auto Otelephone : preds_SSmemberOf.find ( telephone )->second ) {
                                                        
                                                        i++;
                                                        
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                
                                
                                
                                
                            }
                        }
                    }
                    
                    
                    
                    
                    
                    
                    
                }
                
                
            }
        }
    } //second template
    
    cout << "# " << i << endl;
    
}




void LUBM::pathQueryTemplatesGraph()
{
  /*
    select * where  {
      ?X :name ?Z1 .
      ?X :memberOf ?Z2 .
      ?X :undergraduateDegreeFrom ?Z3 .
      ?X :takesCourse ?Z4 .
      ?X :emailAddress ?Z5 .
      ?X :telephone ?Z6 .

      ?Z2 :name ?Y1
      ?Z2 :subOrganizationOf ?Y2
      ?Z2 :type ?Y3
    }
  */


  KEY_ID name 				= diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
  KEY_ID memberOf 			= diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
  KEY_ID undergraduateDegreeFrom 	= diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
  KEY_ID takesCourse 			= diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
  KEY_ID emailAddress 			= diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
  KEY_ID telephone 			= diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
  KEY_ID subOrganizationOf 		= diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
  KEY_ID type 				= diplo::KM.Get ( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
  int i=0;

  
   {
    //second template
    auto &Tname = TM.PredicateTemplates.find ( name )->second; //9
    auto &TsubOrganizationOf = TM.PredicateTemplates.find ( subOrganizationOf )->second; //2
    auto &Ttype = TM.PredicateTemplates.find ( type )->second; //15

    
    auto &TmemberOf = TM.PredicateTemplates.find ( memberOf )->second; //3
    auto &TundergraduateDegreeFrom = TM.PredicateTemplates.find ( undergraduateDegreeFrom )->second; //5
    auto &TtakesCourse = TM.PredicateTemplates.find ( takesCourse )->second; //3
    auto &TemailAddress = TM.PredicateTemplates.find ( emailAddress )->second; //6
    auto &Ttelephone = TM.PredicateTemplates.find ( telephone )->second; //6

    unordered_set<KEY_ID> templates;
    unordered_set<KEY_ID> moleculesDone;
      
      
      
      
      for ( auto tmpl : TmemberOf ) {
          if ( Tname.find(tmpl) == Tname.end() ) continue;
          if ( TundergraduateDegreeFrom.find(tmpl) == TundergraduateDegreeFrom.end() ) continue;
          if ( TtakesCourse.find(tmpl) == TtakesCourse.end() ) continue;
          if ( TemailAddress.find(tmpl) == TemailAddress.end() ) continue;
          if ( Ttelephone.find(tmpl) == Ttelephone.end() ) continue;
          
          auto &tmplZ2 = TM.TemplatesGraph.find ( tmpl )->second;

          unordered_set<unordered_set<KEY_ID>*> templates1;
          for (auto tmpl2 : tmplZ2 ) {
              if (  TsubOrganizationOf.find ( tmpl2 ) != Tname.end() and
                    Tname.find ( tmpl2 ) != Tname.end() and
                    Ttype.find ( tmpl2 ) != Ttype.end() 
                  ) {
                  auto &y = TM.TemplateMolecules.find(tmpl2)->second;
                  templates1.insert(&y);
              }
          }

          
          
          auto &ms = TM.TemplateMolecules.find(tmpl)->second;
          
          
          for (auto m : ms ) {
             
              pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert(m) ;
              if (INSmoleculesDone.second == false ) continue; // this molecule was already done
              
              auto &preds = M.molecules.find(m)->second;
              for ( auto Omemberof : preds.find(memberOf)->second ) {
                  
                  
                  bool takeit = false;
                  for (auto t : templates1) { 
                      if ( t->find(Omemberof) != t->end() ) {
                          takeit = true;
                          break;
                      }
                  }  
                  if (!takeit) continue;
                  
                  auto &preds_memberof = M.molecules.find(Omemberof)->second;
                  
                  for ( auto Oname : preds.find(name)->second ) {
                      for ( auto Oundergraduatedegreefrom : preds.find(undergraduateDegreeFrom)->second ) {
                          for ( auto Otakescourse : preds.find(takesCourse)->second ) {
                              for ( auto Oemailaddress : preds.find(emailAddress)->second ) {
                                  for ( auto Otelephone : preds.find(telephone)->second ) {
                                      
                                      //second
                                      for ( auto Oname2 : preds_memberof.find(name)->second ) {
                                          for ( auto OsubOrganizationOf : preds_memberof.find(subOrganizationOf)->second ) {
                                              for ( auto Otype : preds_memberof.find(type)->second ) {
  
                                                  i++;
                                              }
                                          }
                                      }
                                      
                                      
                                  }
                              }
                          }
                      }
                  }
              }
          }   
      
      
      
      } 
      
      
  }

  cout << "# " << i << endl;


  
}


void LUBM::pathQueryTemplatesGraph2() //bidirectional molecules
{
    /*
     *   select * where  {
     *     ?X :name ?Z1 .
     *     ?X :memberOf ?Z2 .
     *     ?X :undergraduateDegreeFrom ?Z3 .
     *     ?X :takesCourse ?Z4 .
     *     ?X :emailAddress ?Z5 .
     *     ?X :telephone ?Z6 .
     * 
     *     ?Z2 :name ?Y1
     *     ?Z2 :subOrganizationOf ?Y2
     *     ?Z2 :type ?Y3
}
*/
    
    
    KEY_ID name         = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
    KEY_ID memberOf       = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
    KEY_ID undergraduateDegreeFrom  = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
    KEY_ID takesCourse      = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
    KEY_ID emailAddress       = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
    KEY_ID telephone      = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
    KEY_ID subOrganizationOf    = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
    KEY_ID type         = diplo::KM.Get ( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
    

    unordered_set<KEY_ID> templatesX;
    {
        // first template
        auto &Tname = TM.PredicateTemplates.find ( name )->second; //9
        auto &TmemberOf = TM.PredicateTemplates.find ( memberOf )->second; //3
        auto &TundergraduateDegreeFrom = TM.PredicateTemplates.find ( undergraduateDegreeFrom )->second; //5
        auto &TtakesCourse = TM.PredicateTemplates.find ( takesCourse )->second; //3
        auto &TemailAddress = TM.PredicateTemplates.find ( emailAddress )->second; //6
        auto &Ttelephone = TM.PredicateTemplates.find ( telephone )->second; //6

        
        for ( auto tmpl : TmemberOf ) {
            if ( Tname.find(tmpl) == Tname.end() ) continue;
            if ( TundergraduateDegreeFrom.find(tmpl) == TundergraduateDegreeFrom.end() ) continue;
            if ( TtakesCourse.find(tmpl) == TtakesCourse.end() ) continue;
            if ( TemailAddress.find(tmpl) == TemailAddress.end() ) continue;
            if ( Ttelephone.find(tmpl) == Ttelephone.end() ) continue;
            
            templatesX.insert(tmpl);
        }

    } //first template
    
    
    
    int i = 0;
    { //second template
        auto &Tname = TM.PredicateTemplates.find(name)->second; //9
        auto &TsubOrganizationOf = TM.PredicateTemplates.find(subOrganizationOf)->second; //2
        auto &Ttype = TM.PredicateTemplates.find(type)->second; //15
        
        
        
        for (auto &tmpl : TsubOrganizationOf ) {
            if ( Tname.find(tmpl) == Tname.end() ) continue;
            if ( Ttype.find(tmpl) == Ttype.end() ) continue;
 
            
            bool takeit = false;
            unordered_set<unordered_set<KEY_ID>*> templates1;
            for (auto tmplX : templatesX) {
                auto &x = TM.TemplatesGraph.find(tmplX)->second;
                if (x.find(tmpl) != x.end() ) {
                    takeit = true; 
                    auto &y = TM.TemplateMolecules.find(tmplX)->second;
                    templates1.insert(&y);

                }
            }
            if (!takeit) continue;
            
            
            auto &ms = TM.TemplateMolecules.find(tmpl)->second;
            
            
            
            for (auto m : ms ) {
                auto &preds  = M.molecules.find(m)->second;
                
                for ( auto SSmemberOf : preds.find ( (memberOf | PredMask) )->second ) {
                    bool takeit = false;
                    for (auto t : templates1) { 
                        if ( t->find(SSmemberOf) != t->end() ) {
                            takeit = true;
                            break;
                        }
                    }
                    
                    if (!takeit) continue;
                   
                    auto &preds_SSmemberOf = M.molecules.find(SSmemberOf)->second;                 
                    
                    
                    //second 
                    for ( auto OsubOrganizationOf : preds.find ( subOrganizationOf )->second ) {
                        for ( auto Oundergraduatedegreefrom : preds_SSmemberOf.find ( undergraduateDegreeFrom )->second ) {                       
                            
                            
                            for ( auto Oname2 : preds.find ( name )->second ) {
                                for ( auto Otype : preds.find ( type )->second ) {
                                    
                                    
                                    
                                    for ( auto Omemberof : preds_SSmemberOf.find ( memberOf )->second ) {
                                        for ( auto Oname : preds_SSmemberOf.find ( name )->second ) {
                                            
                                            for ( auto Otakescourse : preds_SSmemberOf.find ( takesCourse )->second ) {
                                                for ( auto Oemailaddress : preds_SSmemberOf.find ( emailAddress )->second ) {
                                                    for ( auto Otelephone : preds_SSmemberOf.find ( telephone )->second ) {
                                                        
                                                        i++;
                                                        
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                
                                
                                
                                
                            }
                        }
                    }
                    
     
                    
                }
                
                
            }
        }
    } //second template
    cout << "# " << i << endl;
    
    
    
}



void LUBM::pathQuery2Predicates() {
  /*
   * select * where  {
   * ?W :type ?A
   * ?W :name ?B
   * ?W :publicationAuthor ?X 
   * 
   *  ?X :name ?Z1 .
   *  ?X :memberOf ?Z2 .
   *  ?X :undergraduateDegreeFrom ?Z3 .
   *  ?X :takesCourse ?Z4 .
   *  ?X :emailAddress ?Z5 .
   *  ?X :telephone ?Z6 .
   *  
   *  ?Z2 :name ?Y1
   *  ?Z2 :subOrganizationOf ?Y2
   *  ?Z2 :type ?Y3   
}
*/
  KEY_ID publicationAuthor           = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#publicationAuthor>" );
  KEY_ID name              = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
  KEY_ID memberOf           = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
  KEY_ID undergraduateDegreeFrom    = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
  KEY_ID takesCourse            = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
  KEY_ID emailAddress           = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
  KEY_ID telephone          = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
  KEY_ID subOrganizationOf      = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
  KEY_ID type           = diplo::KM.Get ( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
  
  auto &MpublicationAuthor = TM.PredicateMolecules.find(publicationAuthor)->second; //29004
 
  auto &Mname = TM.PredicateMolecules.find(name)->second; //76523
  auto &MmemberOf = TM.PredicateMolecules.find(memberOf)->second; //37114
  auto &MundergraduateDegreeFrom = TM.PredicateMolecules.find(undergraduateDegreeFrom)->second; //11677
  auto &MtakesCourse = TM.PredicateMolecules.find(takesCourse)->second; //37114
  auto &MemailAddress = TM.PredicateMolecules.find(emailAddress)->second; //39697
  auto &Mtelephone = TM.PredicateMolecules.find(telephone)->second; //39697
  
  auto &MsubOrganizationOf = TM.PredicateMolecules.find(subOrganizationOf)->second; //1131
  auto &Mtype = TM.PredicateMolecules.find(type)->second; //78655
  
  
  unordered_set<KEY_ID> moleculesZ2;
  for ( auto m : MsubOrganizationOf) {
    if ( Mtype.find(m) == Mtype.end() ) continue;
    if ( Mname.find(m) == Mname.end() ) continue;
    
    moleculesZ2.insert(m);
  }
  

  
  //1st
  int i = 0;

  for ( auto m1 : MpublicationAuthor) {
    if ( Mtype.find(m1) == Mtype.end() ) continue;
    if ( Mname.find(m1) == Mname.end() ) continue;
    
    auto &preds1 = M.molecules.find ( m1 )->second;
    for ( auto OpublicationAuthor: preds1.find ( publicationAuthor )->second ) {  
//2nd
    auto m = OpublicationAuthor;
      
    if ( MundergraduateDegreeFrom.find(m) == Mname.end() ) continue;
    if ( Mname.find(m) == Mname.end() ) continue;
    if ( MmemberOf.find(m) == MmemberOf.end() ) continue;
    if ( MtakesCourse.find(m) == MtakesCourse.end() ) continue;
    if ( MemailAddress.find(m) == MemailAddress.end() ) continue;
    if ( Mtelephone.find(m) == Mtelephone.end() ) continue;
    
    auto &preds = M.molecules.find ( m )->second;
    for ( auto Omemberof : preds.find ( memberOf )->second ) {
      if ( moleculesZ2.find ( Omemberof ) == moleculesZ2.end() ) continue;
      
      auto &preds_memberof = M.molecules.find ( Omemberof )->second;
      
      for ( auto Oname : preds.find ( name )->second ) {
        for ( auto Oundergraduatedegreefrom : preds.find ( undergraduateDegreeFrom )->second ) {
          for ( auto Otakescourse : preds.find ( takesCourse )->second ) {
            for ( auto Oemailaddress : preds.find ( emailAddress )->second ) {
              for ( auto Otelephone : preds.find ( telephone )->second ) {
                
                //3rd
                for ( auto Oname2 : preds_memberof.find ( name )->second ) {
                  for ( auto OsubOrganizationOf : preds_memberof.find ( subOrganizationOf )->second ) {
                    for ( auto Otype : preds_memberof.find ( type )->second ) {
                      i++;
                    }
                  }
                }
                
              }
            }
          }
        }
      }
    }
    
    }  
  }
  
  cout << "# " << i << endl;
}


void LUBM::pathQuery2Templates() {
  /*
   * select * where  {
   * ?W :type ?A
   * ?W :name ?B
   * ?W :publicationAuthor ?X 
   * 
   *  ?X :name ?Z1 .
   *  ?X :memberOf ?Z2 .
   *  ?X :undergraduateDegreeFrom ?Z3 .
   *  ?X :takesCourse ?Z4 .
   *  ?X :emailAddress ?Z5 .
   *  ?X :telephone ?Z6 .
   *  
   *  ?Z2 :name ?Y1
   *  ?Z2 :subOrganizationOf ?Y2
   *  ?Z2 :type ?Y3   
}
*/
  KEY_ID publicationAuthor           = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#publicationAuthor>" );
  
  KEY_ID name               = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
  KEY_ID memberOf           = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
  KEY_ID undergraduateDegreeFrom    = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
  KEY_ID takesCourse            = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
  KEY_ID emailAddress           = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
  KEY_ID telephone          = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
  KEY_ID subOrganizationOf      = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
  KEY_ID type           = diplo::KM.Get( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );
  
  
  unordered_set<KEY_ID> moleculesZ2;
  { //3rd template
    auto &Tname = TM.PredicateTemplates.find(name)->second; //9
    auto &TsubOrganizationOf = TM.PredicateTemplates.find(subOrganizationOf)->second; //2
    auto &Ttype = TM.PredicateTemplates.find(type)->second; //15
    
    unordered_set<KEY_ID> templates;
    
    for (auto tmpl : TsubOrganizationOf ) {
      if ( Tname.find(tmpl) == Tname.end() ) continue;
      if ( Ttype.find(tmpl) == Ttype.end() ) continue;
      templates.insert(tmpl);
    }
    
    for (auto tmpl : templates ) {
      auto &ms = TM.TemplateMolecules.find(tmpl)->second;
      for (auto m : ms ) {
        
        auto &preds = M.molecules.find(m)->second;
        if (preds.find(name)  == preds.end() ) continue;
        if (preds.find(subOrganizationOf)  == preds.end() ) continue;
        if (preds.find(type)  == preds.end() ) continue;
        
        moleculesZ2.insert(m);
      }
    }
  } //3rd template
  
  

  unordered_set<KEY_ID> moleculesX;
  { //2nd template
    auto &Tname = TM.PredicateTemplates.find(name)->second; //9
    auto &TmemberOf = TM.PredicateTemplates.find(memberOf)->second; //3
    auto &TundergraduateDegreeFrom = TM.PredicateTemplates.find(undergraduateDegreeFrom)->second; //5 
    auto &TtakesCourse = TM.PredicateTemplates.find(takesCourse)->second; //3 
    auto &TemailAddress = TM.PredicateTemplates.find(emailAddress)->second; //6 
    auto &Ttelephone = TM.PredicateTemplates.find(telephone)->second; //6
    
    unordered_set<KEY_ID> templates;
    
    for (auto tmpl : TmemberOf ) {
      if ( Tname.find(tmpl) == Tname.end() ) continue;
      if ( TundergraduateDegreeFrom.find(tmpl) == TundergraduateDegreeFrom.end() ) continue;
      if ( TtakesCourse.find(tmpl) == TtakesCourse.end() ) continue;
      if ( TemailAddress.find(tmpl) == TemailAddress.end() ) continue;
      if ( Ttelephone.find(tmpl) == Ttelephone.end() ) continue;
      
      templates.insert(tmpl);
    }
    
    for (auto tmpl : templates ) {
      auto &ms = TM.TemplateMolecules.find(tmpl)->second;
      for (auto m : ms ) {
        
        auto &preds = M.molecules.find(m)->second;
        if (preds.find(name)  == preds.end() ) continue;
        if (preds.find(memberOf)  == preds.end() ) continue;
        if (preds.find(undergraduateDegreeFrom)  == preds.end() ) continue;
        if (preds.find(takesCourse)  == preds.end() ) continue;
        if (preds.find(emailAddress)  == preds.end() ) continue;
        if (preds.find(telephone)  == preds.end() ) continue;
        
        moleculesX.insert(m);
      }
    }
  } //2nd template
  
  
  
  
  
  { // first template

    auto &Tname = TM.PredicateTemplates.find(name)->second; //9
    auto &Ttype = TM.PredicateTemplates.find(type)->second; //15
    auto &TpublicationAuthor = TM.PredicateTemplates.find(publicationAuthor)->second; //1 
    

    unordered_set<KEY_ID> templates;
    unordered_set<KEY_ID> moleculesDone;
    
    for (auto tmpl : TpublicationAuthor ) {
      if ( Tname.find(tmpl) == Tname.end() ) continue;
      if ( Ttype.find(tmpl) == Ttype.end() ) continue;
      
      templates.insert(tmpl);
    }

    
    int i=0;
    for (auto tmpl : templates ) {
      auto &ms = TM.TemplateMolecules.find(tmpl)->second;
      for (auto m : ms ) {
        
        pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert(m) ;
        if (INSmoleculesDone.second == false ) continue; // this molecule was already done
        
        auto &preds = M.molecules.find(m)->second;
        
        //1st
        for ( auto OpublicationAuthor : preds.find(publicationAuthor)->second ) {
          if ( moleculesX.find(OpublicationAuthor) == moleculesX.end() ) continue;
          auto &preds_publicationAuthor = M.molecules.find(OpublicationAuthor)->second;
 
          for ( auto Oname : preds.find(name)->second ) {
            for ( auto Otype : preds.find(type)->second ) {

              //2nd
              for ( auto Omemberof : preds_publicationAuthor.find ( memberOf )->second ) {
                if ( moleculesZ2.find(Omemberof) == moleculesZ2.end() ) continue;
                auto &preds_memberof = M.molecules.find(Omemberof)->second;
                  
                for ( auto Oname : preds_publicationAuthor.find ( name )->second ) {
                  for ( auto Oundergraduatedegreefrom : preds_publicationAuthor.find ( undergraduateDegreeFrom )->second ) {
                    for ( auto Otakescourse : preds_publicationAuthor.find ( takesCourse )->second ) {
                      for ( auto Oemailaddress : preds_publicationAuthor.find ( emailAddress )->second ) {
                        for ( auto Otelephone : preds_publicationAuthor.find ( telephone )->second ) {
                          
                          //3rd
                          for ( auto Oname2 : preds_memberof.find(name)->second ) {
                            for ( auto OsubOrganizationOf : preds_memberof.find(subOrganizationOf)->second ) {
                              for ( auto Otype : preds_memberof.find(type)->second ) {
                                i++;
                              }
                            }
                          }
                          
                        }
                      }
                    }
                  }
                }
                
              }

            }
          }
        }
      }   
    }

    cout << "# " << i << endl;
  } // first template 
}







void LUBM::pathQuery2TemplatesGraph() {
/*
 * select * where  {
 * ?W :type ?A
 * ?W :name ?B
 * ?W :publicationAuthor ?X 
 * 
 *  ?X :name ?Z1 .
 *  ?X :memberOf ?Z2 .
 *  ?X :undergraduateDegreeFrom ?Z3 .
 *  ?X :takesCourse ?Z4 .
 *  ?X :emailAddress ?Z5 .
 *  ?X :telephone ?Z6 .
 *  
 *  ?Z2 :name ?Y1
 *  ?Z2 :subOrganizationOf ?Y2
 *  ?Z2 :type ?Y3   
}
*/
KEY_ID publicationAuthor           = diplo::KM.Get ( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#publicationAuthor>" );

KEY_ID name               = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#name>" );
KEY_ID memberOf           = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#memberOf>" );
KEY_ID undergraduateDegreeFrom    = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#undergraduateDegreeFrom>" );
KEY_ID takesCourse            = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#takesCourse>" );
KEY_ID emailAddress           = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#emailAddress>" );
KEY_ID telephone          = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#telephone>" );
KEY_ID subOrganizationOf      = diplo::KM.Get( "<http://www.lehigh.edu/~zhp2/2004/0401/univ-bench.owl#subOrganizationOf>" );
KEY_ID type           = diplo::KM.Get( "<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>" );

  unordered_set<KEY_ID> templatesZ2;
  { //3rd template
    auto &Tname = TM.PredicateTemplates.find ( name )->second; //9
    auto &TsubOrganizationOf = TM.PredicateTemplates.find ( subOrganizationOf )->second; //2
    auto &Ttype = TM.PredicateTemplates.find ( type )->second; //15

    for ( auto tmpl : TsubOrganizationOf ) {
        if ( Tname.find ( tmpl ) == Tname.end() ) continue;
        if ( Ttype.find ( tmpl ) == Ttype.end() ) continue;

        templatesZ2.insert ( tmpl );
      }
  } //3rd template


  unordered_set<KEY_ID> templatesX;
  { // 2nd template
    auto &Tname = TM.PredicateTemplates.find ( name )->second; //9
    auto &TmemberOf = TM.PredicateTemplates.find ( memberOf )->second; //3
    auto &TundergraduateDegreeFrom = TM.PredicateTemplates.find ( undergraduateDegreeFrom )->second; //5
    auto &TtakesCourse = TM.PredicateTemplates.find ( takesCourse )->second; //3
    auto &TemailAddress = TM.PredicateTemplates.find ( emailAddress )->second; //6
    auto &Ttelephone = TM.PredicateTemplates.find ( telephone )->second; //6


    for ( auto tmpl : TmemberOf ) {
        if ( Tname.find ( tmpl ) == Tname.end() )continue;
        if ( TundergraduateDegreeFrom.find ( tmpl ) == TundergraduateDegreeFrom.end() ) continue;
        if ( TtakesCourse.find ( tmpl ) == TtakesCourse.end() ) continue;
        if ( TemailAddress.find ( tmpl ) == TemailAddress.end() ) continue;
        if ( Ttelephone.find ( tmpl ) == Ttelephone.end() ) continue;

        templatesX.insert ( tmpl );
    }

  } // 2nd template


  unordered_set<KEY_ID> templatesW;
  { // 1st template
    auto &Tname = TM.PredicateTemplates.find ( name )->second; //9
    auto &Ttype = TM.PredicateTemplates.find ( type )->second; //15
    auto &TpublicationAuthor = TM.PredicateTemplates.find(publicationAuthor)->second; //1 
    
    
    for ( auto tmpl : TpublicationAuthor ) {
      if ( Tname.find ( tmpl ) == Tname.end() ) continue;
      if ( Ttype.find ( tmpl ) == Ttype.end() ) continue;
      
      templatesW.insert ( tmpl );
      
    } // 1st template
  }
  
  unordered_map< unordered_set<KEY_ID>*, unordered_map< unordered_set<KEY_ID>*, unordered_set<unordered_set<KEY_ID>*> > > moleculessMap;
  
  { //molecules map
    
    for (auto tW : templatesW) {
      auto &tgW = TM.TemplatesGraph.find(tW)->second;
      auto W = &TM.TemplateMolecules.find ( tW )->second;
      
      
      
      for (auto tX : templatesX) {
        if ( tgW.find(tX) == tgW.end() ) continue;
        auto &tgX = TM.TemplatesGraph.find(tX)->second;
        auto X = &TM.TemplateMolecules.find ( tX )->second;
        
        for (auto tZ2 : templatesZ2) {
          if ( tgX.find(tZ2) == tgX.end() ) continue;
          auto Z2 = &TM.TemplateMolecules.find ( tZ2 )->second;
          
          auto it_moleculessMapW = moleculessMap.find ( W );
          if ( it_moleculessMapW ==  moleculessMap.end() ) moleculessMap.insert({ W,{{X,{Z2}}} });
          else {
            auto it_moleculessMapX = it_moleculessMapW->second.find(X);
            if ( it_moleculessMapX ==  it_moleculessMapW->second.end() ) it_moleculessMapW->second.insert({X,{Z2}});
            else it_moleculessMapX->second.insert(Z2);
          }

        }
      }
    }
    
  }
 
 unordered_map< KEY_ID, unordered_map< KEY_ID, unordered_set<KEY_ID> > > moleculesGraph;
 {
     unordered_set<KEY_ID> moleculesDone;
     int i = 0;
    for ( auto m1SET : moleculessMap ) {
        for ( auto m1 : *m1SET.first ) {
            auto INSmoleculesDone = moleculesDone.insert ( m1 ) ;
            if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
            unordered_set<KEY_ID> moleculesDone2;
            
            auto &preds = M.molecules.find ( m1 )->second;
             
             //1st
            for ( auto OpublicationAuthor : preds.find ( publicationAuthor )->second ) {
                auto INSmoleculesDone = moleculesDone2.insert ( OpublicationAuthor ) ;
                if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
                unordered_set<KEY_ID> moleculesDone3;
                 
                for ( auto m2SET : m1SET.second ) {
                    if ( m2SET.first->find(OpublicationAuthor) == m2SET.first->end() ) continue;
                    auto &preds_publicationAuthor = M.molecules.find ( OpublicationAuthor )->second;
                     
                     //2nd
                     for ( auto Omemberof : preds_publicationAuthor.find ( memberOf )->second ) {
                        auto INSmoleculesDone = moleculesDone3.insert ( Omemberof ) ;
                        if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
                         
                        for ( auto m3SET : m2SET.second ) {
                            if ( m3SET->find(Omemberof) == m3SET->end() ) continue;
                            //3rd
                            
//                             auto it_moleculessMapW = moleculesGraph.find ( m1 );
//                             if ( it_moleculessMapW ==  moleculesGraph.end() ) moleculesGraph.insert({ m1,{{OpublicationAuthor,{Omemberof}}} });
//                             else {
//                                 auto it_moleculessMapX = it_moleculessMapW->second.find(OpublicationAuthor);
//                                 if ( it_moleculessMapX ==  it_moleculessMapW->second.end() ) it_moleculessMapW->second.insert({OpublicationAuthor,{Omemberof}});
//                                 else it_moleculessMapX->second.insert(Omemberof);
//                             }
//                             /////////////////////////////////
                            auto &preds_memberof = M.molecules.find(Omemberof)->second;
                            
                            //1st                              
                                for ( auto Oname : preds.find(name)->second ) {
                                    for ( auto Otype : preds.find(type)->second ) {
                                        
                                        //2nd
                                            for ( auto Oname2 : preds_publicationAuthor.find ( name )->second ) {
                                                for ( auto Oundergraduatedegreefrom : preds_publicationAuthor.find ( undergraduateDegreeFrom )->second ) {
                                                    for ( auto Otakescourse : preds_publicationAuthor.find ( takesCourse )->second ) {
                                                        for ( auto Oemailaddress : preds_publicationAuthor.find ( emailAddress )->second ) {
                                                            for ( auto Otelephone : preds_publicationAuthor.find ( telephone )->second ) {
                                                                
                                                                //3rd
                                                                for ( auto Oname3 : preds_memberof.find(name)->second ) {
                                                                    for ( auto OsubOrganizationOf : preds_memberof.find(subOrganizationOf)->second ) {
                                                                        for ( auto Otype3 : preds_memberof.find(type)->second ) {
                                                                            i++;
                                                                        }
                                                                    }
                                                                }
                                                                
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            
                                        }
                                        
                                    }

                            
                            
                            
                            
                            
                            
                        }
                     }
                }
            }
        }
    }
    cout << "# " << i << endl;
 }
 
//  int i =0;
//  for (auto m1 : moleculesGraph) {
//      for (auto m2 : m1.second) {
//          for (auto m3 : m2.second) {
//              i++;
//          }
//      }
//  }
//  cout << "2 # " << i << endl;
 
/* this is slow
 
 {
  int i = 0;
    unordered_set<KEY_ID> moleculesDone;
    for ( auto m1SET : moleculessMap ) {
        for ( auto m1 : *m1SET.first ) {

            auto INSmoleculesDone = moleculesDone.insert ( m1 ) ;
            if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done

                auto preds = M.molecules.find ( m1 )->second;

                //1st
                unordered_set<KEY_ID> moleculesDone2;
                for ( auto OpublicationAuthor : preds.find ( publicationAuthor )->second ) {
                    
                    auto INSmoleculesDone = moleculesDone2.insert ( OpublicationAuthor ) ;
                    if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
                    
                    unordered_set<KEY_ID> moleculesDone3;
                    
                    for ( auto m2SET : m1SET.second ) {
                        if ( m2SET.first->find(OpublicationAuthor) == m2SET.first->end() ) continue;
                        auto preds_publicationAuthor = M.molecules.find ( OpublicationAuthor )->second;
                        for ( auto Oname : preds.find ( name )->second ) {
                            for ( auto Otype : preds.find ( type )->second ) {

                                //2nd
                                
                                for ( auto Omemberof : preds_publicationAuthor.find ( memberOf )->second ) {
                                    
                                  auto INSmoleculesDone = moleculesDone3.insert ( Omemberof ) ;
                                  if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
                                  
                                  for ( auto m3SET : m2SET.second ) {
                                    if ( m3SET->find(Omemberof) == m3SET->end() ) continue;
                                    auto preds_memberof = M.molecules.find(Omemberof)->second;
                                    
                                    for ( auto Oname2 : preds_publicationAuthor.find ( name )->second ) {
                                        for ( auto Oundergraduatedegreefrom : preds_publicationAuthor.find ( undergraduateDegreeFrom )->second ) {
                                            for ( auto Otakescourse : preds_publicationAuthor.find ( takesCourse )->second ) {
                                                for ( auto Oemailaddress : preds_publicationAuthor.find ( emailAddress )->second ) {
                                                    for ( auto Otelephone : preds_publicationAuthor.find ( telephone )->second ) { 
                                                        
                                                        //3rd
                                                        for ( auto Oname3 : preds_memberof.find(name)->second ) {
                                                            for ( auto OsubOrganizationOf : preds_memberof.find(subOrganizationOf)->second ) {
                                                                for ( auto Otype3 : preds_memberof.find(type)->second ) {
                                                                    i++;
                                                                    
//                                                                          cout << KM.Get( m1 ) << "\t"
//                                                                             << KM.Get( Otype ) << "\t"
//                                                                            << KM.Get( Oname ) << "\t" 
//                                                                            << KM.Get( OpublicationAuthor ) << "\t" 
//                                                                            
//                                                                            << KM.Get( Oname2 ) << "\t"
//                                                                            << KM.Get( Omemberof ) << "\t" 
//                                                                            << KM.Get( Oundergraduatedegreefrom ) << "\t"
//                                                                            << KM.Get( Otakescourse ) << "\t" 
//                                                                            << KM.Get( Oemailaddress ) << "\t" 
//                                                                            << KM.Get( Otelephone ) << "\t"
//                                                                            
//                                                                            << KM.Get( Oname3 ) << "\t"
//                                                                            << KM.Get( OsubOrganizationOf ) << "\t"
//                                                                            << KM.Get( Otype3 ) << "\t"
//                                                                            << endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    
                                }
                              }  
                            }
                        }
                    }
                }
        }
    }
    cout << "# " << i << endl;
 } */



}

void LUBM::run(string dir) {
	diplo::srcDir = dir;
	diplo::stopwatch_start();
	diplo::onlyPartition = true;
	Conductor dipl;
	dipl.LoadData();
	cout << "Loading Time: " << diplo::stopwatch_get() << endl;
	cout << "Memory: " << diplo::memory_usage() << endl;
	ConductorNode dipl2;
	dipl2.LoadData();
	cout << "Loading Time: " << diplo::stopwatch_get() << endl;
	cout << "Memory: " << diplo::memory_usage() << endl;
	
	
	
	diplo::stopwatch_start();
	//     predQuery();
	//    pathQueryTemplates();
	//    pathQuery2TemplatesGraph();
	//    triangleTemplates(); 
	//     diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
	//     diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplates2();  cerr << endl << "pathQueryTemplates2: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplatesGraph();  cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplatesGraph2();  cerr << endl << "pathQueryTemplatesGraph2: " << diplo::stopwatch_get() << endl;
	
	
	
	return;
	diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
	
	
	diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
	
	diplo::stopwatch_start();pathQueryTemplatesGraph();  cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplatesGraph();  cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;  
	diplo::stopwatch_start();pathQueryTemplatesGraph();  cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplatesGraph();  cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQueryTemplatesGraph(); cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;
	
	
	diplo::stopwatch_start();pathQuery2Predicates();  cerr << endl << "pathQuery2Predicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2Predicates();  cerr << endl << "pathQuery2Predicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2Predicates();  cerr << endl << "pathQuery2Predicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2Predicates();  cerr << endl << "pathQuery2Predicates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2Predicates();  cerr << endl << "pathQuery2Predicates: " << diplo::stopwatch_get() << endl;
	
	diplo::stopwatch_start();pathQuery2Templates();  cerr << endl << "pathQuery2Templates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2Templates();  cerr << endl << "pathQuery2Templates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2Templates();  cerr << endl << "pathQuery2Templates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2Templates();  cerr << endl << "pathQuery2Templates: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2Templates();  cerr << endl << "pathQuery2Templates: " << diplo::stopwatch_get() << endl;
	
	diplo::stopwatch_start();pathQuery2TemplatesGraph();  cerr << endl << "pathQuery2TemplatesGraph: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2TemplatesGraph();  cerr << endl << "pathQuery2TemplatesGraph: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2TemplatesGraph();  cerr << endl << "pathQuery2TemplatesGraph: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2TemplatesGraph();  cerr << endl << "pathQuery2TemplatesGraph: " << diplo::stopwatch_get() << endl;
	diplo::stopwatch_start();pathQuery2TemplatesGraph();  cerr << endl << "pathQuery2TemplatesGraph: " << diplo::stopwatch_get() << endl;
	
	
	//    diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;
	//    diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;
	//    diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;
	//    diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;
	//    diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;

	
}

}
