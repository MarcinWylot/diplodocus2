#include "DBP.h"

namespace queries {
	
DBP::DBP() {
		// TODO Auto-generated constructor stub
}
	
DBP::~DBP() {
		// TODO Auto-generated destructor stub
}

void DBP::run(string dir) {
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
	
		// 		pathQueryPredicates();
// 		cout << "====== pathQueryTemplates ======" << endl;
//  				pathQueryTemplates();
// 				pathQueryTemplatesGraph();
//  		pathQuery2Predicates();
// 				cout << "====== pathQuery2Templates ======" << endl;
//  		pathQuery2Templates();
// 		pathQuery2TemplatesGraph();
// 		trianglePredicates();
// 		triangleTemplates();
// 		triangleTemplatesGraph();
// 		triangle2Predicates();
// 		cout << "====== triangle2Templates ======" << endl;
//  		triangle2Templates();
// 		triangle2TemplatesGraph();
// 		return;
		
//  		diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
//  		diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
//  		diplo::stopwatch_start();pathQueryPredicates();  cerr << endl << "pathQueryPredicates: " << diplo::stopwatch_get() << endl;
//  		
//  		diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
//  		diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
//  		diplo::stopwatch_start();pathQueryTemplates();  cerr << endl << "pathQueryTemplates: " << diplo::stopwatch_get() << endl;
//  
//  		diplo::stopwatch_start();pathQueryTemplatesGraph();  cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;
//  		diplo::stopwatch_start();pathQueryTemplatesGraph();  cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();pathQueryTemplatesGraph();  cerr << endl << "pathQueryTemplatesGraph: " << diplo::stopwatch_get() << endl;
 		
 		diplo::stopwatch_start();pathQuery2Predicates();  cerr << endl << "pathQuery2Predicates: " << diplo::stopwatch_get() << endl;
 		diplo::stopwatch_start();pathQuery2Predicates();  cerr << endl << "pathQuery2Predicates: " << diplo::stopwatch_get() << endl;
 		diplo::stopwatch_start();pathQuery2Predicates();  cerr << endl << "pathQuery2Predicates: " << diplo::stopwatch_get() << endl;
 		
 		diplo::stopwatch_start();pathQuery2Templates();  cerr << endl << "pathQuery2Templates: " << diplo::stopwatch_get() << endl;
 		diplo::stopwatch_start();pathQuery2Templates();  cerr << endl << "pathQuery2Templates: " << diplo::stopwatch_get() << endl;
 		diplo::stopwatch_start();pathQuery2Templates();  cerr << endl << "pathQuery2Templates: " << diplo::stopwatch_get() << endl;
 		
//  		diplo::stopwatch_start();pathQuery2TemplatesGraph();  cerr << endl << "pathQuery2TemplatesGraph: " << diplo::stopwatch_get() << endl;
//  		diplo::stopwatch_start();pathQuery2TemplatesGraph();  cerr << endl << "pathQuery2TemplatesGraph: " << diplo::stopwatch_get() << endl;
//  		diplo::stopwatch_start();pathQuery2TemplatesGraph();  cerr << endl << "pathQuery2TemplatesGraph: " << diplo::stopwatch_get() << endl;
		
// 		diplo::stopwatch_start();trianglePredicates();  cerr << endl << "trianglePredicates: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();trianglePredicates();  cerr << endl << "trianglePredicates: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();trianglePredicates();  cerr << endl << "trianglePredicates: " << diplo::stopwatch_get() << endl;
// 		
// 		diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();triangleTemplates();  cerr << endl << "triangleTemplates: " << diplo::stopwatch_get() << endl;
// 		
// 		diplo::stopwatch_start();triangleTemplatesGraph();  cerr << endl << "triangleTemplatesGraph: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();triangleTemplatesGraph();  cerr << endl << "triangleTemplatesGraph: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();triangleTemplatesGraph();  cerr << endl << "triangleTemplatesGraph: " << diplo::stopwatch_get() << endl;
		
		diplo::stopwatch_start();triangle2Predicates();  cerr << endl << "triangle2Predicates: " << diplo::stopwatch_get() << endl;
		diplo::stopwatch_start();triangle2Predicates();  cerr << endl << "triangle2Predicates: " << diplo::stopwatch_get() << endl;
		diplo::stopwatch_start();triangle2Predicates();  cerr << endl << "triangle2Predicates: " << diplo::stopwatch_get() << endl;
		
		diplo::stopwatch_start();triangle2Templates();  cerr << endl << "triangle2Templates: " << diplo::stopwatch_get() << endl;
		diplo::stopwatch_start();triangle2Templates();  cerr << endl << "triangle2Templates: " << diplo::stopwatch_get() << endl;
		diplo::stopwatch_start();triangle2Templates();  cerr << endl << "triangle2Templates: " << diplo::stopwatch_get() << endl;
		
// 		diplo::stopwatch_start();triangle2TemplatesGraph();  cerr << endl << "triangle2TemplatesGraph: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();triangle2TemplatesGraph();  cerr << endl << "triangle2TemplatesGraph: " << diplo::stopwatch_get() << endl;
// 		diplo::stopwatch_start();triangle2TemplatesGraph();  cerr << endl << "triangle2TemplatesGraph: " << diplo::stopwatch_get() << endl;

}
	
	
	
void DBP::pathQueryPredicates() {
	/*
	select distinct * where {
		
		?X <http://www.w3.org/2000/01/rdf-schema#comment> ?Z1.
		?X <http://dbpedia.org/ontology/birthYear> ?Z2.
		?X <http://dbpedia.org/ontology/deathDate> ?Z3.
		?X <http://dbpedia.org/ontology/wikiPageRevisionID> ?Z4.
		?X <http://dbpedia.org/ontology/wikiPageExternalLink> ?Z5.
		?X <http://xmlns.com/foaf/0.1/isPrimaryTopicOf> ?Z6.
		?X <http://dbpedia.org/property/placeofdeath> ?Z7 .
		?X <http://dbpedia.org/property/placeOfBirth> ?Z.
		
		?Z <http://xmlns.com/foaf/0.1/name> ?Y1.
		?Z <http://www.w3.org/2002/07/owl#sameAs> ?Y2.
		?Z <http://www.w3.org/ns/prov#wasDerivedFrom> ?Y3 .
		?Z <http://dbpedia.org/ontology/isPartOf> ?Y4 .
		?Z <http://dbpedia.org/ontology/province> ?Y5
		?Z <http://dbpedia.org/ontology/country> ?Y.
		
	}
	*/
	
	
	
	KEY_ID comment              = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID birthYear           = diplo::KM.Get ( "<http://dbpedia.org/ontology/birthYear>" );
	KEY_ID deathDate    = diplo::KM.Get ( "<http://dbpedia.org/ontology/deathDate>" );
	KEY_ID wikiPageRevisionID            = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageRevisionID>" );
	KEY_ID wikiPageExternalLink           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageExternalLink>" );
	KEY_ID isPrimaryTopicOf          = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/isPrimaryTopicOf>" );
	KEY_ID placeofdeath      = diplo::KM.Get ( "<http://dbpedia.org/property/placeofdeath>" );
	KEY_ID placeOfBirth           = diplo::KM.Get ( "<http://dbpedia.org/property/placeOfBirth>" );
	
	KEY_ID name           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/name>" );
	KEY_ID sameAs           = diplo::KM.Get ( "<http://www.w3.org/2002/07/owl#sameAs>" );
	KEY_ID wasDerivedFrom           = diplo::KM.Get ( "<http://www.w3.org/ns/prov#wasDerivedFrom>" );
	KEY_ID isPartOf           = diplo::KM.Get ( "<http://dbpedia.org/ontology/isPartOf>" );
	KEY_ID province           = diplo::KM.Get ( "<http://dbpedia.org/ontology/province>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	
	
	
	auto &Mcomment              = TM.PredicateMolecules.find( comment )->second; //7
	auto &MbirthYear           = TM.PredicateMolecules.find( birthYear )->second; //2
	auto &MdeathDate    = TM.PredicateMolecules.find( deathDate )->second; //2
	auto &MwikiPageRevisionID            = TM.PredicateMolecules.find( wikiPageRevisionID )->second; //8
	auto &MwikiPageExternalLink           = TM.PredicateMolecules.find( wikiPageExternalLink )->second; //7
	auto &MisPrimaryTopicOf          = TM.PredicateMolecules.find( isPrimaryTopicOf )->second; //8
	auto &Mplaceofdeath      = TM.PredicateMolecules.find( placeofdeath )->second; //2
	auto &MplaceOfBirth           = TM.PredicateMolecules.find( placeOfBirth )->second; //2
	
	auto &Mname           = TM.PredicateMolecules.find( name )->second; //8
	auto &MsameAs           = TM.PredicateMolecules.find( sameAs )->second; //8
	auto &MwasDerivedFrom           = TM.PredicateMolecules.find( wasDerivedFrom )->second; //8
	auto &MisPartOf           = TM.PredicateMolecules.find( isPartOf )->second; //2
	auto &Mprovince           = TM.PredicateMolecules.find( province )->second; //2
	auto &Mcountry           = TM.PredicateMolecules.find( country )->second; //4
	
	
// 	cout << Mcomment.size() << endl; 
// 	cout << MbirthYear.size() << endl; 
// 	cout << MdeathDate.size() << endl; 
// 	cout << MwikiPageRevisionID.size() << endl; 
// 	cout << MwikiPageExternalLink.size() << endl; 
// 	cout << MisPrimaryTopicOf.size() << endl; 
// 	cout << Mplaceofdeath.size() << endl; 
// 	cout << MplaceOfBirth.size() << endl; 
// 	
// 	cout << Mname.size() << endl; 
// 	cout << MsameAs.size() << endl; 
// 	cout << MwasDerivedFrom.size() << endl; 
// 	cout << MisPartOf.size() << endl; 
// 	cout << Mprovince.size() << endl; 
// 	cout << Mcountry.size() << endl; 
	

	
	unordered_set<KEY_ID> moleculesZ;
	for ( auto m : MisPartOf) {
		if ( Mname.find(m) == Mname.end() ) continue;
		if ( MsameAs.find(m) == MsameAs.end() ) continue;
		if ( MwasDerivedFrom.find(m) == MwasDerivedFrom.end() ) continue;
		if ( Mprovince.find(m) == Mprovince.end() ) continue;
		if ( Mcountry.find(m) == Mcountry.end() ) continue;
		
		moleculesZ.insert(m);
	}
	
	cout << "moleculesZ.size(): " << moleculesZ.size() << endl;
	
	int i = 0;
	
	for ( auto m : MbirthYear) {
		if ( Mcomment.find(m) == Mcomment.end() ) continue;
		if ( MdeathDate.find(m) == MdeathDate.end() ) continue;
		if ( MwikiPageRevisionID.find(m) == MwikiPageRevisionID.end() ) continue;
		if ( MwikiPageExternalLink.find(m) == MwikiPageExternalLink.end() ) continue;
		if ( MisPrimaryTopicOf.find(m) == MisPrimaryTopicOf.end() ) continue;
		if ( Mplaceofdeath.find(m) == Mplaceofdeath.end() ) continue;
		if ( MplaceOfBirth.find(m) == MplaceOfBirth.end() ) continue;
	
		
		

		
		auto &preds = M.molecules.find ( m )->second;
		for ( auto OplaceOfBirth : preds.find ( placeOfBirth )->second ) {
			if ( moleculesZ.find ( OplaceOfBirth ) == moleculesZ.end() ) continue;
			
			auto preds_placeOfBirth = M.molecules.find ( OplaceOfBirth )->second;
 

 for ( auto Ocomment : preds.find ( comment )->second ) {
	 for ( auto ObirthYear : preds.find ( birthYear )->second ) {
		 for ( auto OdeathDate : preds.find ( deathDate )->second ) {
			 for ( auto OwikiPageRevisionID : preds.find ( wikiPageRevisionID )->second ) {
				 for ( auto OwikiPageExternalLink : preds.find ( wikiPageExternalLink )->second ) {
					 for ( auto OisPrimaryTopicOf : preds.find ( isPrimaryTopicOf )->second ) {
						 for ( auto Oplaceofdeath : preds.find ( placeofdeath )->second ) {
								
								//second
							 for ( auto Oname : preds_placeOfBirth.find ( name )->second ) {
								 for ( auto OsameAs : preds_placeOfBirth.find ( sameAs )->second ) {
									 for ( auto OwasDerivedFrom : preds_placeOfBirth.find ( wasDerivedFrom )->second ) {
										 for ( auto OisPartOf : preds_placeOfBirth.find ( isPartOf )->second ) {
											 for ( auto Oprovince : preds_placeOfBirth.find ( province )->second ) {
												 for ( auto Ocountry : preds_placeOfBirth.find ( country )->second ) {
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
	
	cout << "# " << i << endl;
	
	
	
	
}




void DBP::pathQueryTemplates() {
	/*
	 select distinct * where {                                                    *
	 
	 ?X <http://www.w3.org/2000/01/rdf-schema#comment> ?Z1.
	 ?X <http://dbpedia.org/ontology/birthYear> ?Z2.
	 ?X <http://dbpedia.org/ontology/deathDate> ?Z3.
	 ?X <http://dbpedia.org/ontology/wikiPageRevisionID> ?Z4.
	 ?X <http://dbpedia.org/ontology/wikiPageExternalLink> ?Z5.
	 ?X <http://xmlns.com/foaf/0.1/isPrimaryTopicOf> ?Z6.
	 ?X <http://dbpedia.org/property/placeofdeath> ?Z7 .
	 ?X <http://dbpedia.org/property/placeOfBirth> ?Z.
	 
	 ?Z <http://xmlns.com/foaf/0.1/name> ?Y1.
	 ?Z <http://www.w3.org/2002/07/owl#sameAs> ?Y2.
	 ?Z <http://www.w3.org/ns/prov#wasDerivedFrom> ?Y3 .
	 ?Z <http://dbpedia.org/ontology/isPartOf> ?Y4 .
	 ?Z <http://dbpedia.org/ontology/province> ?Y5
	 ?Z <http://dbpedia.org/ontology/country> ?Y.
	 
}
*/
	
	
	
	KEY_ID comment              = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID birthYear           = diplo::KM.Get ( "<http://dbpedia.org/ontology/birthYear>" );
	KEY_ID deathDate    = diplo::KM.Get ( "<http://dbpedia.org/ontology/deathDate>" );
	KEY_ID wikiPageRevisionID            = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageRevisionID>" );
	KEY_ID wikiPageExternalLink           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageExternalLink>" );
	KEY_ID isPrimaryTopicOf          = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/isPrimaryTopicOf>" );
	KEY_ID placeofdeath      = diplo::KM.Get ( "<http://dbpedia.org/property/placeofdeath>" );
	KEY_ID placeOfBirth           = diplo::KM.Get ( "<http://dbpedia.org/property/placeOfBirth>" );
	
	KEY_ID name           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/name>" );
	KEY_ID sameAs           = diplo::KM.Get ( "<http://www.w3.org/2002/07/owl#sameAs>" );
	KEY_ID wasDerivedFrom           = diplo::KM.Get ( "<http://www.w3.org/ns/prov#wasDerivedFrom>" );
	KEY_ID isPartOf           = diplo::KM.Get ( "<http://dbpedia.org/ontology/isPartOf>" );
	KEY_ID province           = diplo::KM.Get ( "<http://dbpedia.org/ontology/province>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	
	
// 	cout << "======" <<endl;
	unordered_set<KEY_ID> moleculesZ;
	{ //second template
		
		auto &Tname           = TM.PredicateTemplates.find( name )->second; //21
		auto &TsameAs           = TM.PredicateTemplates.find( sameAs )->second; //21
		auto &TwasDerivedFrom           = TM.PredicateTemplates.find( wasDerivedFrom )->second; //21
		auto &TisPartOf           = TM.PredicateTemplates.find( isPartOf )->second; //12
		auto &Tprovince           = TM.PredicateTemplates.find( province )->second; //13
		auto &Tcountry           = TM.PredicateTemplates.find( country )->second; //15
		
		cout << "Tname: " <<  Tname.size() << endl; 
		cout << "TsameAs: " << TsameAs.size() << endl; 
		cout << "TwasDerivedFrom: " << TwasDerivedFrom.size() << endl; 
		cout << "TisPartOf: " << TisPartOf.size() << endl; 
		cout << "Tprovince: " << Tprovince.size() << endl; 
		cout << "Tcountry: " << Tcountry.size() << endl; 

		
		
		for ( auto tmpl : TisPartOf ) {
			if ( 
				Tname.find ( tmpl ) == Tname.end() or
				TsameAs.find ( tmpl ) == TsameAs.end() or
				TwasDerivedFrom.find ( tmpl ) == TwasDerivedFrom.end() or
				Tprovince.find ( tmpl ) == Tprovince.end() or
				Tcountry.find ( tmpl ) == Tcountry.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesZ.insert ( m );
			}
		}
		
	} //second template
 	cout << "moleculesZ.size(): "<< moleculesZ.size() <<endl;
	{ //firts template
		
		auto &Tcomment              = TM.PredicateTemplates.find( comment )->second; //20
		auto &TbirthYear           = TM.PredicateTemplates.find( birthYear )->second;  //7 
		auto &TdeathDate    = TM.PredicateTemplates.find( deathDate )->second; //7
		auto &TwikiPageRevisionID            = TM.PredicateTemplates.find( wikiPageRevisionID )->second; //21
		auto &TwikiPageExternalLink           = TM.PredicateTemplates.find( wikiPageExternalLink )->second; //20
		auto &TisPrimaryTopicOf          = TM.PredicateTemplates.find( isPrimaryTopicOf )->second; //21
		auto &Tplaceofdeath      = TM.PredicateTemplates.find( placeofdeath )->second;  //7
		auto &TplaceOfBirth           = TM.PredicateTemplates.find( placeOfBirth )->second; //7
		
		
		cout << "Tcomment: " << Tcomment.size() << endl; 
		cout << "TbirthYear: " << TbirthYear.size() << endl; 
		cout << "TdeathDate: " << TdeathDate.size() << endl; 
		cout << "TwikiPageRevisionID: " << TwikiPageRevisionID.size() << endl; 
		cout << "TwikiPageExternalLink: " << TwikiPageExternalLink.size() << endl; 
		cout << "TisPrimaryTopicOf: " << TisPrimaryTopicOf.size() << endl; 
		cout << "Tplaceofdeath: " << Tplaceofdeath.size() << endl; 
		cout << "TplaceOfBirth: " << TplaceOfBirth.size() << endl; 



// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : TbirthYear ) {
				if (    
					Tcomment.find ( tmpl ) == Tcomment.end() or
					TdeathDate.find ( tmpl ) == TdeathDate.end() or
					TwikiPageRevisionID.find ( tmpl ) == TwikiPageRevisionID.end() or
					TwikiPageExternalLink.find ( tmpl ) == TwikiPageExternalLink.end() or
					TisPrimaryTopicOf.find ( tmpl ) == TisPrimaryTopicOf.end() or
					Tplaceofdeath.find ( tmpl ) == Tplaceofdeath.end() or
					TplaceOfBirth.find ( tmpl ) == TplaceOfBirth.end()
				) 
					continue;
					
					
					auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
					for ( auto m : ms ) {
						
						pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
						if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
						

						
						auto &preds = M.molecules.find ( m )->second;
						
						if (preds.find ( deathDate ) == preds.end() or
							preds.find ( comment ) == preds.end()
						) continue;
						
						
						for ( auto OplaceOfBirth : preds.find ( placeOfBirth )->second ) {
							if ( moleculesZ.find ( OplaceOfBirth ) == moleculesZ.end() ) continue;
							auto preds_placeOfBirth = M.molecules.find ( OplaceOfBirth )->second;
						
						for ( auto Ocomment : preds.find ( comment )->second ) {
							for ( auto ObirthYear : preds.find ( birthYear )->second ) {
								for ( auto OdeathDate : preds.find ( deathDate )->second ) {
									for ( auto OwikiPageRevisionID : preds.find ( wikiPageRevisionID )->second ) {
										for ( auto OwikiPageExternalLink : preds.find ( wikiPageExternalLink )->second ) {
											for ( auto OisPrimaryTopicOf : preds.find ( isPrimaryTopicOf )->second ) {
												for ( auto Oplaceofdeath : preds.find ( placeofdeath )->second ) {
													
													//second
													for ( auto Oname : preds_placeOfBirth.find ( name )->second ) {
														for ( auto OsameAs : preds_placeOfBirth.find ( sameAs )->second ) {
															for ( auto OwasDerivedFrom : preds_placeOfBirth.find ( wasDerivedFrom )->second ) {
																for ( auto OisPartOf : preds_placeOfBirth.find ( isPartOf )->second ) {
																	for ( auto Oprovince : preds_placeOfBirth.find ( province )->second ) {
																		for ( auto Ocountry : preds_placeOfBirth.find ( country )->second ) {
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

	
	
}




void DBP::pathQueryTemplatesGraph() {
	/*
	 * select distinct * where {                                                    *
	 * 
	 * ?X <http://www.w3.org/2000/01/rdf-schema#comment> ?Z1.
	 * ?X <http://dbpedia.org/ontology/birthYear> ?Z2.
	 * ?X <http://dbpedia.org/ontology/deathDate> ?Z3.
	 * ?X <http://dbpedia.org/ontology/wikiPageRevisionID> ?Z4.
	 * ?X <http://dbpedia.org/ontology/wikiPageExternalLink> ?Z5.
	 * ?X <http://xmlns.com/foaf/0.1/isPrimaryTopicOf> ?Z6.
	 * ?X <http://dbpedia.org/property/placeofdeath> ?Z7 .
	 * ?X <http://dbpedia.org/property/placeOfBirth> ?Z.
	 * 
	 * ?Z <http://xmlns.com/foaf/0.1/name> ?Y1.
	 * ?Z <http://www.w3.org/2002/07/owl#sameAs> ?Y2.
	 * ?Z <http://www.w3.org/ns/prov#wasDerivedFrom> ?Y3 .
	 * ?Z <http://dbpedia.org/ontology/isPartOf> ?Y4 .
	 * ?Z <http://dbpedia.org/ontology/province> ?Y5
	 * ?Z <http://dbpedia.org/ontology/country> ?Y.
	 * 
}
*/
	
	
	
	KEY_ID comment              = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID birthYear           = diplo::KM.Get ( "<http://dbpedia.org/ontology/birthYear>" );
	KEY_ID deathDate    = diplo::KM.Get ( "<http://dbpedia.org/ontology/deathDate>" );
	KEY_ID wikiPageRevisionID            = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageRevisionID>" );
	KEY_ID wikiPageExternalLink           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageExternalLink>" );
	KEY_ID isPrimaryTopicOf          = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/isPrimaryTopicOf>" );
	KEY_ID placeofdeath      = diplo::KM.Get ( "<http://dbpedia.org/property/placeofdeath>" );
	KEY_ID placeOfBirth           = diplo::KM.Get ( "<http://dbpedia.org/property/placeOfBirth>" );
	
	KEY_ID name           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/name>" );
	KEY_ID sameAs           = diplo::KM.Get ( "<http://www.w3.org/2002/07/owl#sameAs>" );
	KEY_ID wasDerivedFrom           = diplo::KM.Get ( "<http://www.w3.org/ns/prov#wasDerivedFrom>" );
	KEY_ID isPartOf           = diplo::KM.Get ( "<http://dbpedia.org/ontology/isPartOf>" );
	KEY_ID province           = diplo::KM.Get ( "<http://dbpedia.org/ontology/province>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	
	
// 	cout << "======" <<endl;
// 	unordered_set<KEY_ID> moleculesZ;
// 	{ //second template
		
	
		
		// 		cout << Tname.size() << endl; 
		// 		cout << TsameAs.size() << endl; 
		// 		cout << TwasDerivedFrom.size() << endl; 
		// 		cout << TisPartOf.size() << endl; 
		// 		cout << Tprovince.size() << endl; 
		// 		cout << Tcountry.size() << endl; 
		
		
		/*
		for ( auto tmpl : TisPartOf ) {
			if ( 
				Tname.find ( tmpl ) == Tname.end() or
				TsameAs.find ( tmpl ) == TsameAs.end() or
				TwasDerivedFrom.find ( tmpl ) == TwasDerivedFrom.end() or
				Tprovince.find ( tmpl ) == Tprovince.end() or
				Tcountry.find ( tmpl ) == Tcountry.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesZ.insert ( m );
			}
		}
		
	} //second template
	cout << "moleculesZ.size(): "<< moleculesZ.size() <<endl;*/
	{ //firts template
		
		auto &Tcomment              = TM.PredicateTemplates.find( comment )->second; //20
		auto &TbirthYear           = TM.PredicateTemplates.find( birthYear )->second;  //7 
		auto &TdeathDate    = TM.PredicateTemplates.find( deathDate )->second; //7
		auto &TwikiPageRevisionID            = TM.PredicateTemplates.find( wikiPageRevisionID )->second; //21
		auto &TwikiPageExternalLink           = TM.PredicateTemplates.find( wikiPageExternalLink )->second; //20
		auto &TisPrimaryTopicOf          = TM.PredicateTemplates.find( isPrimaryTopicOf )->second; //21
		auto &Tplaceofdeath      = TM.PredicateTemplates.find( placeofdeath )->second;  //7
		auto &TplaceOfBirth           = TM.PredicateTemplates.find( placeOfBirth )->second; //7
		
		auto &Tname           = TM.PredicateTemplates.find( name )->second; //21
		auto &TsameAs           = TM.PredicateTemplates.find( sameAs )->second; //21
		auto &TwasDerivedFrom           = TM.PredicateTemplates.find( wasDerivedFrom )->second; //21
		auto &TisPartOf           = TM.PredicateTemplates.find( isPartOf )->second; //12
		auto &Tprovince           = TM.PredicateTemplates.find( province )->second; //13
		auto &Tcountry           = TM.PredicateTemplates.find( country )->second; //15
		// 		cout << Tcomment.size() << endl; 
		// 		cout << TbirthYear.size() << endl; 
		// 		cout << TdeathDate.size() << endl; 
		// 		cout << TwikiPageRevisionID.size() << endl; 
		// 		cout << TwikiPageExternalLink.size() << endl; 
		// 		cout << TisPrimaryTopicOf.size() << endl; 
		// 		cout << Tplaceofdeath.size() << endl; 
		// 		cout << TplaceOfBirth.size() << endl; 
		
		
		
		// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : TbirthYear ) {
			if (    
				Tcomment.find ( tmpl ) == Tcomment.end() or
				TdeathDate.find ( tmpl ) == TdeathDate.end() or
				TwikiPageRevisionID.find ( tmpl ) == TwikiPageRevisionID.end() or
				TwikiPageExternalLink.find ( tmpl ) == TwikiPageExternalLink.end() or
				TisPrimaryTopicOf.find ( tmpl ) == TisPrimaryTopicOf.end() or
				Tplaceofdeath.find ( tmpl ) == Tplaceofdeath.end() or
				TplaceOfBirth.find ( tmpl ) == TplaceOfBirth.end()
			) 
				continue;
				
				
				
				
				auto &tmplZ = TM.TemplatesGraph.find ( tmpl )->second;
				
				unordered_set<unordered_set<KEY_ID>*> templates1;
				for (auto tmpl2 : tmplZ ) {
					if ( 
						Tname.find ( tmpl2 ) != Tname.end() and
						TsameAs.find ( tmpl2 ) != TsameAs.end() and
						TwasDerivedFrom.find ( tmpl2 ) != TwasDerivedFrom.end() and
						Tprovince.find ( tmpl2 ) != Tprovince.end() and
						Tcountry.find ( tmpl2 ) != Tcountry.end()
					) {
						auto &y = TM.TemplateMolecules.find(tmpl2)->second;
						templates1.insert(&y);
					}
				}
				
				
				auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
				for ( auto m : ms ) {
					
					pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
					if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
					
					
					
					auto &preds = M.molecules.find ( m )->second;
					
					if (preds.find ( deathDate ) == preds.end() or
						preds.find ( comment ) == preds.end()
					) continue;
					
					
					for ( auto OplaceOfBirth : preds.find ( placeOfBirth )->second ) {
						
						bool takeit = false;
						for (auto t : templates1) { 
							if ( t->find( OplaceOfBirth ) != t->end() ) {
								takeit = true;
								break;
							}
						}  
						if (!takeit) continue;
						
						auto preds_placeOfBirth = M.molecules.find ( OplaceOfBirth )->second;
						
						for ( auto Ocomment : preds.find ( comment )->second ) {
							for ( auto ObirthYear : preds.find ( birthYear )->second ) {
								for ( auto OdeathDate : preds.find ( deathDate )->second ) {
									for ( auto OwikiPageRevisionID : preds.find ( wikiPageRevisionID )->second ) {
										for ( auto OwikiPageExternalLink : preds.find ( wikiPageExternalLink )->second ) {
											for ( auto OisPrimaryTopicOf : preds.find ( isPrimaryTopicOf )->second ) {
												for ( auto Oplaceofdeath : preds.find ( placeofdeath )->second ) {
													
													//second
													for ( auto Oname : preds_placeOfBirth.find ( name )->second ) {
														for ( auto OsameAs : preds_placeOfBirth.find ( sameAs )->second ) {
															for ( auto OwasDerivedFrom : preds_placeOfBirth.find ( wasDerivedFrom )->second ) {
																for ( auto OisPartOf : preds_placeOfBirth.find ( isPartOf )->second ) {
																	for ( auto Oprovince : preds_placeOfBirth.find ( province )->second ) {
																		for ( auto Ocountry : preds_placeOfBirth.find ( country )->second ) {
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
	
	
	
}




void DBP::pathQuery2Predicates() {
	/*
	 * select distinct * where {                                                    *
	 * 
	 * ?X <http://www.w3.org/2000/01/rdf-schema#comment> ?Z1.
	 * ?X <http://dbpedia.org/ontology/birthYear> ?Z2.
	 * ?X <http://dbpedia.org/ontology/deathDate> ?Z3.
	 * ?X <http://dbpedia.org/ontology/wikiPageRevisionID> ?Z4.
	 * ?X <http://dbpedia.org/ontology/wikiPageExternalLink> ?Z5.
	 * ?X <http://xmlns.com/foaf/0.1/isPrimaryTopicOf> ?Z6.
	 * ?X <http://dbpedia.org/property/placeofdeath> ?Z7 .
	 * ?X <http://dbpedia.org/property/placeOfBirth> ?Z.
	 * 
	 * ?Z <http://xmlns.com/foaf/0.1/name> ?Y1.
	 * ?Z <http://www.w3.org/2002/07/owl#sameAs> ?Y2.
	 * ?Z <http://www.w3.org/ns/prov#wasDerivedFrom> ?Y3 .
	 * ?Z <http://dbpedia.org/ontology/isPartOf> ?Y4 .
	 * ?Z <http://dbpedia.org/ontology/province> ?Y5
	 * ?Z <http://dbpedia.org/ontology/country> ?Y.
	 * 
	 * ?Y <http://xmlns.com/foaf/0.1/homepage> ?W1 . 
	 * ?Y <http://dbpedia.org/ontology/PopulatedPlace/populationDensity> ?W2 . 
	 * ?Y <http://dbpedia.org/ontology/percentageOfAreaWater> ?W3 . 
	 * ?Y <http://dbpedia.org/ontology/wikiPageOutDegree> ?W4 . 
	 * ?Y <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?W5 . 
	 * 
}
*/
	
	
	
	KEY_ID comment              = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID birthYear           = diplo::KM.Get ( "<http://dbpedia.org/ontology/birthYear>" );
	KEY_ID deathDate    = diplo::KM.Get ( "<http://dbpedia.org/ontology/deathDate>" );
	KEY_ID wikiPageRevisionID            = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageRevisionID>" );
	KEY_ID wikiPageExternalLink           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageExternalLink>" );
	KEY_ID isPrimaryTopicOf          = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/isPrimaryTopicOf>" );
	KEY_ID placeofdeath      = diplo::KM.Get ( "<http://dbpedia.org/property/placeofdeath>" );
	KEY_ID placeOfBirth           = diplo::KM.Get ( "<http://dbpedia.org/property/placeOfBirth>" );
	
	KEY_ID name           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/name>" );
	KEY_ID sameAs           = diplo::KM.Get ( "<http://www.w3.org/2002/07/owl#sameAs>" );
	KEY_ID wasDerivedFrom           = diplo::KM.Get ( "<http://www.w3.org/ns/prov#wasDerivedFrom>" );
	KEY_ID isPartOf           = diplo::KM.Get ( "<http://dbpedia.org/ontology/isPartOf>" );
	KEY_ID province           = diplo::KM.Get ( "<http://dbpedia.org/ontology/province>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	
	KEY_ID homepage           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/homepage>" );
	KEY_ID populationDensity           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/populationDensity>" );
	KEY_ID percentageOfAreaWater           = diplo::KM.Get ( "<http://dbpedia.org/ontology/percentageOfAreaWater>" );
	KEY_ID wikiPageOutDegree           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageOutDegree>" );
	KEY_ID seeAlso           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
	
	
	
		auto &Mcomment              = TM.PredicateMolecules.find( comment )->second; //7
		auto &MbirthYear           = TM.PredicateMolecules.find( birthYear )->second;  //2 
		auto &MdeathDate    = TM.PredicateMolecules.find( deathDate )->second; //2
		auto &MwikiPageRevisionID            = TM.PredicateMolecules.find( wikiPageRevisionID )->second; //8
		auto &MwikiPageExternalLink           = TM.PredicateMolecules.find( wikiPageExternalLink )->second; //7
		auto &MisPrimaryTopicOf          = TM.PredicateMolecules.find( isPrimaryTopicOf )->second; //8
		auto &Mplaceofdeath      = TM.PredicateMolecules.find( placeofdeath )->second;  //2
		auto &MplaceOfBirth           = TM.PredicateMolecules.find( placeOfBirth )->second; //2
		
		auto &Mname           = TM.PredicateMolecules.find( name )->second; //8
		auto &MsameAs           = TM.PredicateMolecules.find( sameAs )->second; //8
		auto &MwasDerivedFrom           = TM.PredicateMolecules.find( wasDerivedFrom )->second; //8
		auto &MisPartOf           = TM.PredicateMolecules.find( isPartOf )->second; //2
		auto &Mprovince           = TM.PredicateMolecules.find( province )->second; //2
		auto &Mcountry           = TM.PredicateMolecules.find( country )->second; //4
		
		auto &Mhomepage           = TM.PredicateMolecules.find( homepage )->second; //6
		auto &MpopulationDensity           = TM.PredicateMolecules.find( populationDensity )->second; //3
		auto &MpercentageOfAreaWater           = TM.PredicateMolecules.find( percentageOfAreaWater )->second; //2
		auto &MwikiPageOutDegree           = TM.PredicateMolecules.find( wikiPageOutDegree )->second; //8
		auto &MseeAlso           = TM.PredicateMolecules.find( seeAlso )->second; //3
		
				
// 				cout << Mcomment.size() << endl; 
// 				cout << MbirthYear.size() << endl; 
// 				cout << MdeathDate.size() << endl; 
// 				cout << MwikiPageRevisionID.size() << endl; 
// 				cout << MwikiPageExternalLink.size() << endl; 
// 				cout << MisPrimaryTopicOf.size() << endl; 
// 				cout << Mplaceofdeath.size() << endl; 
// 				cout << MplaceOfBirth.size() << endl << endl;
// 				
// 				cout << Mname.size() << endl; 
// 				cout << MsameAs.size() << endl; 
// 				cout << MwasDerivedFrom.size() << endl; 
// 				cout << MisPartOf.size() << endl; 
// 				cout << Mprovince.size() << endl; 
// 				cout << Mcountry.size() << endl << endl;
// 				
// 				cout << Mhomepage.size() << endl; 
// 				cout << MpopulationDensity.size() << endl; 
// 				cout << MpercentageOfAreaWater.size() << endl; 
// 				cout << MwikiPageOutDegree.size() << endl; 
// 				cout << MseeAlso.size() << endl << endl;
// 				
		
		
		unordered_set<KEY_ID> moleculesZ;
		for ( auto m : MisPartOf) {
			if ( Mcomment.find(m) == Mcomment.end() ) continue;
			if ( MsameAs.find(m) == MsameAs.end() ) continue;
			if ( MwasDerivedFrom.find(m) == MwasDerivedFrom.end() ) continue;
			if ( Mprovince.find(m) == Mprovince.end() ) continue;
			if ( Mcountry.find(m) == Mcountry.end() ) continue;
			
			moleculesZ.insert(m);
		}
// 		cout << "moleculesZ.size(): " << moleculesZ.size() << endl;
		
		
		unordered_set<KEY_ID> moleculesY;
		for ( auto m : MpercentageOfAreaWater) {
			if ( Mhomepage.find(m) == Mhomepage.end() ) continue;
			if ( MpopulationDensity.find(m) == MpopulationDensity.end() ) continue;
			if ( MwikiPageOutDegree.find(m) == MwikiPageOutDegree.end() ) continue;
			if ( MseeAlso.find(m) == MseeAlso.end() ) continue;
			
			moleculesY.insert(m);
		}
// 		cout << "moleculesY.size(): " << moleculesY.size() << endl;
		

		{
			int i = 0;
		for ( auto m : MbirthYear) {
			if ( Mcomment.find(m) == Mcomment.end() ) continue;
			if ( MdeathDate.find(m) == MdeathDate.end() ) continue;
			if ( MwikiPageRevisionID.find(m) == MwikiPageRevisionID.end() ) continue;
			if ( MwikiPageExternalLink.find(m) == MwikiPageExternalLink.end() ) continue;
			if ( MisPrimaryTopicOf.find(m) == MisPrimaryTopicOf.end() ) continue;
			if ( Mplaceofdeath.find(m) == Mplaceofdeath.end() ) continue;
			if ( MplaceOfBirth.find(m) == MplaceOfBirth.end() ) continue;

					
					auto &preds = M.molecules.find ( m )->second;

			
			if (    
				preds.find ( comment ) == preds.end() or
				preds.find ( birthYear ) == preds.end() or
				preds.find ( deathDate ) == preds.end() or
				preds.find ( wikiPageRevisionID ) == preds.end() or
				preds.find ( wikiPageExternalLink ) == preds.end() or
				preds.find ( isPrimaryTopicOf ) == preds.end() or
				preds.find ( placeofdeath ) == preds.end()
			) 
				continue;
				
				for ( auto OplaceOfBirth : preds.find ( placeOfBirth )->second ) {
					if ( moleculesZ.find ( OplaceOfBirth ) == moleculesZ.end() ) continue;
					auto preds_placeOfBirth = M.molecules.find ( OplaceOfBirth )->second;
					
					if (    
						preds_placeOfBirth.find ( name ) == preds_placeOfBirth.end() or
						preds_placeOfBirth.find ( sameAs ) == preds_placeOfBirth.end() or
						preds_placeOfBirth.find ( wasDerivedFrom ) == preds_placeOfBirth.end() or
						preds_placeOfBirth.find ( isPartOf ) == preds_placeOfBirth.end() or
						preds_placeOfBirth.find ( province ) == preds_placeOfBirth.end()
					) 
						continue;

						for ( auto Ocountry : preds_placeOfBirth.find ( country )->second ) {
							if ( moleculesY.find ( Ocountry ) == moleculesY.end() ) continue;
							auto preds_country = M.molecules.find ( Ocountry )->second;
							
							if (    
								preds_country.find ( homepage ) == preds_country.end() or
								preds_country.find ( populationDensity ) == preds_country.end() or
								preds_country.find ( percentageOfAreaWater ) == preds_country.end() or
								preds_country.find ( wikiPageOutDegree ) == preds_country.end() or
								preds_country.find ( seeAlso ) == preds_country.end()
							) 
								continue;
								i++;
						}
				}
		
			
			
			
			
			
			
			
					
// 					for ( auto OplaceOfBirth : preds.find ( placeOfBirth )->second ) {
// 						if ( moleculesZ.find ( OplaceOfBirth ) == moleculesZ.end() ) continue;
// 						auto preds_placeOfBirth = M.molecules.find ( OplaceOfBirth )->second;
// 						
// 
// 						for ( auto Ocomment : preds.find ( comment )->second ) {
// 							for ( auto ObirthYear : preds.find ( birthYear )->second ) {
// 								for ( auto OdeathDate : preds.find ( deathDate )->second ) {
// 									for ( auto OwikiPageRevisionID : preds.find ( wikiPageRevisionID )->second ) {
// 										for ( auto OwikiPageExternalLink : preds.find ( wikiPageExternalLink )->second ) {
// 											for ( auto OisPrimaryTopicOf : preds.find ( isPrimaryTopicOf )->second ) {
// 												for ( auto Oplaceofdeath : preds.find ( placeofdeath )->second ) {
// 													
// 													//second
// 													for ( auto Ocountry : preds_placeOfBirth.find ( country )->second ) {
// 														if ( moleculesY.find ( Ocountry ) == moleculesY.end() ) continue;
// 														auto preds_country = M.molecules.find ( Ocountry )->second;
// 														
// 														for ( auto Oname : preds_placeOfBirth.find ( name )->second ) {
// 															for ( auto OsameAs : preds_placeOfBirth.find ( sameAs )->second ) {
// 																for ( auto OwasDerivedFrom : preds_placeOfBirth.find ( wasDerivedFrom )->second ) {
// 																	for ( auto OisPartOf : preds_placeOfBirth.find ( isPartOf )->second ) {
// 																		for ( auto Oprovince : preds_placeOfBirth.find ( province )->second ) {
// 																			
// 																			//3rd
// 																			for ( auto Ohomepage : preds_country.find ( homepage )->second ) {
// 																				for ( auto OpercentageOfAreaWater : preds_country.find ( populationDensity )->second ) {
// 																					for ( auto OpercentageOfAreaWater : preds_country.find ( percentageOfAreaWater )->second ) {
// 																						for ( auto OwikiPageOutDegree : preds_country.find ( wikiPageOutDegree )->second ) {
// 																							for ( auto OseeAlso : preds_country.find ( seeAlso )->second ) {
// 																								i++;
// 																							}
// 																						}
// 																					}
// 																				}
// 																			}
// 																			
// 																			
// 																			
// 																			
// 																		}
// 																	}
// 																}
// 															}
// 														}
// 													}
// 													
// 												}
// 											}
// 										}
// 									}
// 								}
// 							}
// 						}
// 					}
					

				
		}
		cout << "# " << i << endl;
		}

	

	
	
	
}


void DBP::pathQuery2Templates() {
	/*
	 * select distinct ?X ?Z ?Y where {                                                    *
	 * 
	 * ?X <http://www.w3.org/2000/01/rdf-schema#comment> ?Z1.
	 * ?X <http://dbpedia.org/ontology/birthYear> ?Z2.
	 * ?X <http://dbpedia.org/ontology/deathDate> ?Z3.
	 * ?X <http://dbpedia.org/ontology/wikiPageRevisionID> ?Z4.
	 * ?X <http://dbpedia.org/ontology/wikiPageExternalLink> ?Z5.
	 * ?X <http://xmlns.com/foaf/0.1/isPrimaryTopicOf> ?Z6.
	 * ?X <http://dbpedia.org/property/placeofdeath> ?Z7 .
	 * ?X <http://dbpedia.org/property/placeOfBirth> ?Z.
	 * 
	 * ?Z <http://xmlns.com/foaf/0.1/name> ?Y1.
	 * ?Z <http://www.w3.org/2002/07/owl#sameAs> ?Y2.
	 * ?Z <http://www.w3.org/ns/prov#wasDerivedFrom> ?Y3 .
	 * ?Z <http://dbpedia.org/ontology/isPartOf> ?Y4 .
	 * ?Z <http://dbpedia.org/ontology/province> ?Y5
	 * ?Z <http://dbpedia.org/ontology/country> ?Y.
	 * 
	 * ?Y <http://xmlns.com/foaf/0.1/homepage> ?W1 . 
	 * ?Y <http://dbpedia.org/ontology/PopulatedPlace/populationDensity> ?W2 . 
	 * ?Y <http://dbpedia.org/ontology/percentageOfAreaWater> ?W3 . 
	 * ?Y <http://dbpedia.org/ontology/wikiPageOutDegree> ?W4 . 
	 * ?Y <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?W5 . 
	 * 
}
*/
	
	
	
	KEY_ID comment              = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID birthYear           = diplo::KM.Get ( "<http://dbpedia.org/ontology/birthYear>" );
	KEY_ID deathDate    = diplo::KM.Get ( "<http://dbpedia.org/ontology/deathDate>" );
	KEY_ID wikiPageRevisionID            = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageRevisionID>" );
	KEY_ID wikiPageExternalLink           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageExternalLink>" );
	KEY_ID isPrimaryTopicOf          = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/isPrimaryTopicOf>" );
	KEY_ID placeofdeath      = diplo::KM.Get ( "<http://dbpedia.org/property/placeofdeath>" );
	KEY_ID placeOfBirth           = diplo::KM.Get ( "<http://dbpedia.org/property/placeOfBirth>" );
	
	KEY_ID name           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/name>" );
	KEY_ID sameAs           = diplo::KM.Get ( "<http://www.w3.org/2002/07/owl#sameAs>" );
	KEY_ID wasDerivedFrom           = diplo::KM.Get ( "<http://www.w3.org/ns/prov#wasDerivedFrom>" );
	KEY_ID isPartOf           = diplo::KM.Get ( "<http://dbpedia.org/ontology/isPartOf>" );
	KEY_ID province           = diplo::KM.Get ( "<http://dbpedia.org/ontology/province>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	
	KEY_ID homepage           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/homepage>" );
	KEY_ID populationDensity           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/populationDensity>" );
	KEY_ID percentageOfAreaWater           = diplo::KM.Get ( "<http://dbpedia.org/ontology/percentageOfAreaWater>" );
	KEY_ID wikiPageOutDegree           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageOutDegree>" );
	KEY_ID seeAlso           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );

	
// 	cout << "======" <<endl;
	unordered_set<KEY_ID> moleculesZ;
	{ //second template
		
		auto &Tname           = TM.PredicateTemplates.find( name )->second; //21
		auto &TsameAs           = TM.PredicateTemplates.find( sameAs )->second; //21
		auto &TwasDerivedFrom           = TM.PredicateTemplates.find( wasDerivedFrom )->second; //21
		auto &TisPartOf           = TM.PredicateTemplates.find( isPartOf )->second; //12
		auto &Tprovince           = TM.PredicateTemplates.find( province )->second; //13
		auto &Tcountry           = TM.PredicateTemplates.find( country )->second; //15
		
		// 		cout << Tname.size() << endl; 
		// 		cout << TsameAs.size() << endl; 
		// 		cout << TwasDerivedFrom.size() << endl; 
		// 		cout << TisPartOf.size() << endl; 
		// 		cout << Tprovince.size() << endl; 
		// 		cout << Tcountry.size() << endl; 
		
		
		
		for ( auto tmpl : TisPartOf ) {
			if ( 
				Tname.find ( tmpl ) == Tname.end() or
				TsameAs.find ( tmpl ) == TsameAs.end() or
				TwasDerivedFrom.find ( tmpl ) == TwasDerivedFrom.end() or
				Tprovince.find ( tmpl ) == Tprovince.end() or
				Tcountry.find ( tmpl ) == Tcountry.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesZ.insert ( m );
			}
		}
		
	} //second template
 	cout << "moleculesZ.size(): "<< moleculesZ.size() <<endl;
	
// 	cout << "======" <<endl;
	unordered_set<KEY_ID> moleculesY;
	{ //3rd template
		
		KEY_ID homepage           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/homepage>" );
		KEY_ID populationDensity           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/populationDensity>" );
		KEY_ID percentageOfAreaWater           = diplo::KM.Get ( "<http://dbpedia.org/ontology/percentageOfAreaWater>" );
		KEY_ID wikiPageOutDegree           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageOutDegree>" );
		KEY_ID seeAlso           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
		
		
		auto &Thomepage           = TM.PredicateTemplates.find( homepage )->second; //19
		auto &TpopulationDensity           = TM.PredicateTemplates.find( populationDensity )->second; //12
		auto &TpercentageOfAreaWater           = TM.PredicateTemplates.find( percentageOfAreaWater )->second; //10
		auto &TwikiPageOutDegree           = TM.PredicateTemplates.find( wikiPageOutDegree )->second; //21
		auto &TseeAlso           = TM.PredicateTemplates.find( seeAlso )->second; //12
		
// 		cout << "Thomepage: " << Thomepage.size() << endl; 
// 		cout << "TpopulationDensity: " << TpopulationDensity.size() << endl; 
// 		cout << "TpercentageOfAreaWater: " << TpercentageOfAreaWater.size() << endl; 
// 		cout << "TwikiPageOutDegree: " << TwikiPageOutDegree.size() << endl; 
// 		cout << "TseeAlso: " << TseeAlso.size() << endl; 
		
		
		
		for ( auto tmpl : TpercentageOfAreaWater ) {
			if ( 
				Thomepage.find ( tmpl ) == Thomepage.end() or
				TpopulationDensity.find ( tmpl ) == TpopulationDensity.end() or
				TwikiPageOutDegree.find ( tmpl ) == TwikiPageOutDegree.end() or
				TseeAlso.find ( tmpl ) == TseeAlso.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesY.insert ( m );
			}
		}
		
	} //3rd template
//  	cout << "moleculesY.size(): "<< moleculesY.size() <<endl;
	
	
	{ //firts template
		
		auto &Tcomment              = TM.PredicateTemplates.find( comment )->second; //20
		auto &TbirthYear           = TM.PredicateTemplates.find( birthYear )->second;  //7 
		auto &TdeathDate    = TM.PredicateTemplates.find( deathDate )->second; //7
		auto &TwikiPageRevisionID            = TM.PredicateTemplates.find( wikiPageRevisionID )->second; //21
		auto &TwikiPageExternalLink           = TM.PredicateTemplates.find( wikiPageExternalLink )->second; //20
		auto &TisPrimaryTopicOf          = TM.PredicateTemplates.find( isPrimaryTopicOf )->second; //21
		auto &Tplaceofdeath      = TM.PredicateTemplates.find( placeofdeath )->second;  //7
		auto &TplaceOfBirth           = TM.PredicateTemplates.find( placeOfBirth )->second; //7
		
		
		// 		cout << Tcomment.size() << endl; 
		// 		cout << TbirthYear.size() << endl; 
		// 		cout << TdeathDate.size() << endl; 
		// 		cout << TwikiPageRevisionID.size() << endl; 
		// 		cout << TwikiPageExternalLink.size() << endl; 
		// 		cout << TisPrimaryTopicOf.size() << endl; 
		// 		cout << Tplaceofdeath.size() << endl; 
		// 		cout << TplaceOfBirth.size() << endl; 
		
		
		
		// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : TbirthYear ) {
			if (    
				Tcomment.find ( tmpl ) == Tcomment.end() or
				TdeathDate.find ( tmpl ) == TdeathDate.end() or
				TwikiPageRevisionID.find ( tmpl ) == TwikiPageRevisionID.end() or
				TwikiPageExternalLink.find ( tmpl ) == TwikiPageExternalLink.end() or
				TisPrimaryTopicOf.find ( tmpl ) == TisPrimaryTopicOf.end() or
				Tplaceofdeath.find ( tmpl ) == Tplaceofdeath.end() or
				TplaceOfBirth.find ( tmpl ) == TplaceOfBirth.end()
			) 
				continue;

				
				auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
				for ( auto m : ms ) {
					
					pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
					if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
					
					
					
					auto &preds = M.molecules.find ( m )->second;
					
// 					if (preds.find ( deathDate ) == preds.end() or
// 						preds.find ( comment ) == preds.end()
// 					) continue;
// 					
					
					if (    
						preds.find ( comment ) == preds.end() or
						preds.find ( birthYear ) == preds.end() or
						preds.find ( deathDate ) == preds.end() or
						preds.find ( wikiPageRevisionID ) == preds.end() or
						preds.find ( wikiPageExternalLink ) == preds.end() or
						preds.find ( isPrimaryTopicOf ) == preds.end() or
						preds.find ( placeofdeath ) == preds.end()
					) 
						continue;
						
					for ( auto OplaceOfBirth : preds.find ( placeOfBirth )->second ) {
						if ( moleculesZ.find ( OplaceOfBirth ) == moleculesZ.end() ) continue;
						auto preds_placeOfBirth = M.molecules.find ( OplaceOfBirth )->second;
						
						if (    
							preds_placeOfBirth.find ( name ) == preds_placeOfBirth.end() or
							preds_placeOfBirth.find ( sameAs ) == preds_placeOfBirth.end() or
							preds_placeOfBirth.find ( wasDerivedFrom ) == preds_placeOfBirth.end() or
							preds_placeOfBirth.find ( isPartOf ) == preds_placeOfBirth.end() or
							preds_placeOfBirth.find ( province ) == preds_placeOfBirth.end()
						) 
							continue;
						
						
// 						for ( auto Ocomment : preds.find ( comment )->second ) {
// 							for ( auto ObirthYear : preds.find ( birthYear )->second ) {
// 								for ( auto OdeathDate : preds.find ( deathDate )->second ) {
// 									for ( auto OwikiPageRevisionID : preds.find ( wikiPageRevisionID )->second ) {
// 										for ( auto OwikiPageExternalLink : preds.find ( wikiPageExternalLink )->second ) {
// 											for ( auto OisPrimaryTopicOf : preds.find ( isPrimaryTopicOf )->second ) {
// 												for ( auto Oplaceofdeath : preds.find ( placeofdeath )->second ) {
													
													//second
													for ( auto Ocountry : preds_placeOfBirth.find ( country )->second ) {
														if ( moleculesY.find ( Ocountry ) == moleculesY.end() ) continue;
														auto preds_country = M.molecules.find ( Ocountry )->second;
														
														if (    
															preds_country.find ( homepage ) == preds_country.end() or
															preds_country.find ( populationDensity ) == preds_country.end() or
															preds_country.find ( percentageOfAreaWater ) == preds_country.end() or
															preds_country.find ( wikiPageOutDegree ) == preds_country.end() or
															preds_country.find ( seeAlso ) == preds_country.end()
														) 
															continue;
														
														
// 														for ( auto Oname : preds_placeOfBirth.find ( name )->second ) {
// 															for ( auto OsameAs : preds_placeOfBirth.find ( sameAs )->second ) {
// 																for ( auto OwasDerivedFrom : preds_placeOfBirth.find ( wasDerivedFrom )->second ) {
// 																	for ( auto OisPartOf : preds_placeOfBirth.find ( isPartOf )->second ) {
// 																		for ( auto Oprovince : preds_placeOfBirth.find ( province )->second ) {
																		
																			//3rd
// 																			for ( auto Ohomepage : preds_country.find ( homepage )->second ) {
// 																				for ( auto OpercentageOfAreaWater : preds_country.find ( populationDensity )->second ) {
// 																					for ( auto OpercentageOfAreaWater : preds_country.find ( percentageOfAreaWater )->second ) {
// 																						for ( auto OwikiPageOutDegree : preds_country.find ( wikiPageOutDegree )->second ) {
// 																							for ( auto OseeAlso : preds_country.find ( seeAlso )->second ) {
																								i++;
// 																							}
// 																						}
// 																					}
// 																				}
// 																			}
																			
																			
																			
																			
// 																		}
// 																	}
// 																}
// 															}
// 														}
													}
													
// 												}
// 											}
// 										}
// 									}
// 								}
// 							}
// 						}
					}
					
					
					
					
					
				}
		}
		cout << "# " << i << endl;
	}
	
	
	
}
	
	
	
	
	
	
void DBP::pathQuery2TemplatesGraph() {
	/*
	 * select distinct * where {                                                    *
	 * 
	 * ?X <http://www.w3.org/2000/01/rdf-schema#comment> ?Z1.
	 * ?X <http://dbpedia.org/ontology/birthYear> ?Z2.
	 * ?X <http://dbpedia.org/ontology/deathDate> ?Z3.
	 * ?X <http://dbpedia.org/ontology/wikiPageRevisionID> ?Z4.
	 * ?X <http://dbpedia.org/ontology/wikiPageExternalLink> ?Z5.
	 * ?X <http://xmlns.com/foaf/0.1/isPrimaryTopicOf> ?Z6.
	 * ?X <http://dbpedia.org/property/placeofdeath> ?Z7 .
	 * ?X <http://dbpedia.org/property/placeOfBirth> ?Z.
	 * 
	 * ?Z <http://xmlns.com/foaf/0.1/name> ?Y1.
	 * ?Z <http://www.w3.org/2002/07/owl#sameAs> ?Y2.
	 * ?Z <http://www.w3.org/ns/prov#wasDerivedFrom> ?Y3 .
	 * ?Z <http://dbpedia.org/ontology/isPartOf> ?Y4 .
	 * ?Z <http://dbpedia.org/ontology/province> ?Y5
	 * ?Z <http://dbpedia.org/ontology/country> ?Y.
	 * 
	 * ?Y <http://xmlns.com/foaf/0.1/homepage> ?W1 . 
	 * ?Y <http://dbpedia.org/ontology/PopulatedPlace/populationDensity> ?W2 . 
	 * ?Y <http://dbpedia.org/ontology/percentageOfAreaWater> ?W3 . 
	 * ?Y <http://dbpedia.org/ontology/wikiPageOutDegree> ?W4 . 
	 * ?Y <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?W5 . 
	 * 
}
*/
	
	
	
	KEY_ID comment              = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID birthYear           = diplo::KM.Get ( "<http://dbpedia.org/ontology/birthYear>" );
	KEY_ID deathDate    = diplo::KM.Get ( "<http://dbpedia.org/ontology/deathDate>" );
	KEY_ID wikiPageRevisionID            = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageRevisionID>" );
	KEY_ID wikiPageExternalLink           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageExternalLink>" );
	KEY_ID isPrimaryTopicOf          = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/isPrimaryTopicOf>" );
	KEY_ID placeofdeath      = diplo::KM.Get ( "<http://dbpedia.org/property/placeofdeath>" );
	KEY_ID placeOfBirth           = diplo::KM.Get ( "<http://dbpedia.org/property/placeOfBirth>" );
	
	KEY_ID name           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/name>" );
	KEY_ID sameAs           = diplo::KM.Get ( "<http://www.w3.org/2002/07/owl#sameAs>" );
	KEY_ID wasDerivedFrom           = diplo::KM.Get ( "<http://www.w3.org/ns/prov#wasDerivedFrom>" );
	KEY_ID isPartOf           = diplo::KM.Get ( "<http://dbpedia.org/ontology/isPartOf>" );
	KEY_ID province           = diplo::KM.Get ( "<http://dbpedia.org/ontology/province>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	
	KEY_ID homepage           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/homepage>" );
	KEY_ID populationDensity           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/populationDensity>" );
	KEY_ID percentageOfAreaWater           = diplo::KM.Get ( "<http://dbpedia.org/ontology/percentageOfAreaWater>" );
	KEY_ID wikiPageOutDegree           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageOutDegree>" );
	KEY_ID seeAlso           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );

	
	/*
// 	cout << "======" <<endl;
	unordered_set<KEY_ID> moleculesZ;
	{ //second template
		
		auto &Tname           = TM.PredicateTemplates.find( name )->second; //21
		auto &TsameAs           = TM.PredicateTemplates.find( sameAs )->second; //21
		auto &TwasDerivedFrom           = TM.PredicateTemplates.find( wasDerivedFrom )->second; //21
		auto &TisPartOf           = TM.PredicateTemplates.find( isPartOf )->second; //12
		auto &Tprovince           = TM.PredicateTemplates.find( province )->second; //13
		auto &Tcountry           = TM.PredicateTemplates.find( country )->second; //15
		
		// 		cout << Tname.size() << endl; 
		// 		cout << TsameAs.size() << endl; 
		// 		cout << TwasDerivedFrom.size() << endl; 
		// 		cout << TisPartOf.size() << endl; 
		// 		cout << Tprovince.size() << endl; 
		// 		cout << Tcountry.size() << endl; 
		
		
		
		for ( auto tmpl : TisPartOf ) {
			if ( 
				Tname.find ( tmpl ) == Tname.end() or
				TsameAs.find ( tmpl ) == TsameAs.end() or
				TwasDerivedFrom.find ( tmpl ) == TwasDerivedFrom.end() or
				Tprovince.find ( tmpl ) == Tprovince.end() or
				Tcountry.find ( tmpl ) == Tcountry.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesZ.insert ( m );
			}
		}
		
	} //second template
// 	cout << "moleculesZ.size(): "<< moleculesZ.size() <<endl;
	
// 	cout << "======" <<endl;
	unordered_set<KEY_ID> moleculesY;
	{ //3rd template
		
		KEY_ID homepage           = diplo::KM.Get ( "<http://xmlns.com/foaf/0.1/homepage>" );
		KEY_ID populationDensity           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/populationDensity>" );
		KEY_ID percentageOfAreaWater           = diplo::KM.Get ( "<http://dbpedia.org/ontology/percentageOfAreaWater>" );
		KEY_ID wikiPageOutDegree           = diplo::KM.Get ( "<http://dbpedia.org/ontology/wikiPageOutDegree>" );
		KEY_ID seeAlso           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
		
		
		auto &Thomepage           = TM.PredicateTemplates.find( homepage )->second; //19
		auto &TpopulationDensity           = TM.PredicateTemplates.find( populationDensity )->second; //12
		auto &TpercentageOfAreaWater           = TM.PredicateTemplates.find( percentageOfAreaWater )->second; //10
		auto &TwikiPageOutDegree           = TM.PredicateTemplates.find( wikiPageOutDegree )->second; //21
		auto &TseeAlso           = TM.PredicateTemplates.find( seeAlso )->second; //12
		
// 		cout << Thomepage.size() << endl; 
// 		cout << TpopulationDensity.size() << endl; 
// 		cout << TpercentageOfAreaWater.size() << endl; 
// 		cout << TwikiPageOutDegree.size() << endl; 
// 		cout << TseeAlso.size() << endl; 
		
		
		
		for ( auto tmpl : TpercentageOfAreaWater ) {
			if ( 
				Thomepage.find ( tmpl ) == Thomepage.end() or
				TpopulationDensity.find ( tmpl ) == TpopulationDensity.end() or
				TwikiPageOutDegree.find ( tmpl ) == TwikiPageOutDegree.end() or
				TseeAlso.find ( tmpl ) == TseeAlso.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesY.insert ( m );
			}
		}
		
	} //3rd template
// 	cout << "moleculesY.size(): "<< moleculesY.size() <<endl;
	*/
	
	{ //firts template
		
		auto &Tcomment              = TM.PredicateTemplates.find( comment )->second; //20
		auto &TbirthYear           = TM.PredicateTemplates.find( birthYear )->second;  //7 
		auto &TdeathDate    = TM.PredicateTemplates.find( deathDate )->second; //7
		auto &TwikiPageRevisionID            = TM.PredicateTemplates.find( wikiPageRevisionID )->second; //21
		auto &TwikiPageExternalLink           = TM.PredicateTemplates.find( wikiPageExternalLink )->second; //20
		auto &TisPrimaryTopicOf          = TM.PredicateTemplates.find( isPrimaryTopicOf )->second; //21
		auto &Tplaceofdeath      = TM.PredicateTemplates.find( placeofdeath )->second;  //7
		auto &TplaceOfBirth           = TM.PredicateTemplates.find( placeOfBirth )->second; //7
		
		auto &Tname           = TM.PredicateTemplates.find( name )->second; //21
		auto &TsameAs           = TM.PredicateTemplates.find( sameAs )->second; //21
		auto &TwasDerivedFrom           = TM.PredicateTemplates.find( wasDerivedFrom )->second; //21
		auto &TisPartOf           = TM.PredicateTemplates.find( isPartOf )->second; //12
		auto &Tprovince           = TM.PredicateTemplates.find( province )->second; //13
		auto &Tcountry           = TM.PredicateTemplates.find( country )->second; //15
		
		auto &Thomepage           = TM.PredicateTemplates.find( homepage )->second; //19
		auto &TpopulationDensity           = TM.PredicateTemplates.find( populationDensity )->second; //12
		auto &TpercentageOfAreaWater           = TM.PredicateTemplates.find( percentageOfAreaWater )->second; //10
		auto &TwikiPageOutDegree           = TM.PredicateTemplates.find( wikiPageOutDegree )->second; //21
		auto &TseeAlso           = TM.PredicateTemplates.find( seeAlso )->second; //12
		
		// 		cout << Tcomment.size() << endl; 
		// 		cout << TbirthYear.size() << endl; 
		// 		cout << TdeathDate.size() << endl; 
		// 		cout << TwikiPageRevisionID.size() << endl; 
		// 		cout << TwikiPageExternalLink.size() << endl; 
		// 		cout << TisPrimaryTopicOf.size() << endl; 
		// 		cout << Tplaceofdeath.size() << endl; 
		// 		cout << TplaceOfBirth.size() << endl; 
		
		
		
		// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : TbirthYear ) {
			if (    
				Tcomment.find ( tmpl ) == Tcomment.end() or
				TdeathDate.find ( tmpl ) == TdeathDate.end() or
				TwikiPageRevisionID.find ( tmpl ) == TwikiPageRevisionID.end() or
				TwikiPageExternalLink.find ( tmpl ) == TwikiPageExternalLink.end() or
				TisPrimaryTopicOf.find ( tmpl ) == TisPrimaryTopicOf.end() or
				Tplaceofdeath.find ( tmpl ) == Tplaceofdeath.end() or
				TplaceOfBirth.find ( tmpl ) == TplaceOfBirth.end()
			) 
				continue;
				
				
				
				auto &tmplZ = TM.TemplatesGraph.find ( tmpl )->second;
				
				unordered_set<unordered_set<KEY_ID>*> templatesZ;
				unordered_set<unordered_set<KEY_ID>*> templatesY;
				for (auto tmpl2 : tmplZ ) {
					if ( 
						Tname.find ( tmpl2 ) != Tname.end() and
						TsameAs.find ( tmpl2 ) != TsameAs.end() and
						TwasDerivedFrom.find ( tmpl2 ) != TwasDerivedFrom.end() and
						Tprovince.find ( tmpl2 ) != Tprovince.end() and
						Tcountry.find ( tmpl2 ) != Tcountry.end()
					) {
						auto &z = TM.TemplateMolecules.find(tmpl2)->second;
						
						
						auto &tmplY = TM.TemplatesGraph.find ( tmpl )->second;
						
						
						for (auto tmpl3 : tmplY ) {
							if ( 
								Thomepage.find ( tmpl3 ) != Thomepage.end() and
								TpopulationDensity.find ( tmpl3 ) != TpopulationDensity.end() and
								TwikiPageOutDegree.find ( tmpl3 ) != TwikiPageOutDegree.end() and
								TseeAlso.find ( tmpl3 ) != TseeAlso.end()
							) {
								auto &y = TM.TemplateMolecules.find(tmpl3)->second;
								templatesZ.insert(&z);
								templatesY.insert(&y);
							}
						}
							
						
					}
				}
				
				
				auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
				for ( auto m : ms ) {
					
					pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
					if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
					
					
					
					auto &preds = M.molecules.find ( m )->second;
					
					if (preds.find ( deathDate ) == preds.end() or
						preds.find ( comment ) == preds.end()
					) continue;
					
					
					for ( auto OplaceOfBirth : preds.find ( placeOfBirth )->second ) {
						

						bool takeit = false;
						for (auto t : templatesZ) { 
							if ( t->find( OplaceOfBirth ) != t->end() ) {
								takeit = true;
								break;
							}
						}  
						if (!takeit) continue;
						
						
						
						
						auto preds_placeOfBirth = M.molecules.find ( OplaceOfBirth )->second;
						
						for ( auto Ocomment : preds.find ( comment )->second ) {
							for ( auto ObirthYear : preds.find ( birthYear )->second ) {
								for ( auto OdeathDate : preds.find ( deathDate )->second ) {
									for ( auto OwikiPageRevisionID : preds.find ( wikiPageRevisionID )->second ) {
										for ( auto OwikiPageExternalLink : preds.find ( wikiPageExternalLink )->second ) {
											for ( auto OisPrimaryTopicOf : preds.find ( isPrimaryTopicOf )->second ) {
												for ( auto Oplaceofdeath : preds.find ( placeofdeath )->second ) {
													
													//second
													for ( auto Ocountry : preds_placeOfBirth.find ( country )->second ) {
														
														
														bool takeit = false;
														for (auto t : templatesY) { 
															if ( t->find( Ocountry ) != t->end() ) {
																takeit = true;
																break;
															}
														}  
														if (!takeit) continue;
														
														
														
														auto preds_country = M.molecules.find ( Ocountry )->second;
														
														for ( auto Oname : preds_placeOfBirth.find ( name )->second ) {
															for ( auto OsameAs : preds_placeOfBirth.find ( sameAs )->second ) {
																for ( auto OwasDerivedFrom : preds_placeOfBirth.find ( wasDerivedFrom )->second ) {
																	for ( auto OisPartOf : preds_placeOfBirth.find ( isPartOf )->second ) {
																		for ( auto Oprovince : preds_placeOfBirth.find ( province )->second ) {
																		
																			//3rd
																			for ( auto Ohomepage : preds_country.find ( homepage )->second ) {
																				for ( auto OpercentageOfAreaWater : preds_country.find ( populationDensity )->second ) {
																					for ( auto OpercentageOfAreaWater : preds_country.find ( percentageOfAreaWater )->second ) {
																						for ( auto OwikiPageOutDegree : preds_country.find ( wikiPageOutDegree )->second ) {
																							for ( auto OseeAlso : preds_country.find ( seeAlso )->second ) {
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
							}
						}
					}
					
					
					
					
					
				}
		}
		cout << "# " << i << endl;
	}
}
	
void DBP::trianglePredicates() {
	/*
	 * select distinct * where {
	 * 
	 * ?X <http://dbpedia.org/ontology/location> ?Z1 .
	 * ?X <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?X <http://dbpedia.org/ontology/abbreviation> ?Z3 .
	 * ?X <http://dbpedia.org/property/homepage> ?Z4 .
	 * ?X <http://dbpedia.org/property/state> ?Z5 .
	 *    
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?Z2 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#comment> ?W1 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#label> ?W2 .
	 * ?Z1 <http://dbpedia.org/ontology/PopulatedPlace/areaTotal> ?W3 .
	 * ?Z1 <http://dbpedia.org/ontology/areaCode> ?W4 .
	 * ?Z1 <http://dbpedia.org/ontology/areaTotal> ?W5 .
	 * ?Z1 <http://dbpedia.org/ontology/leaderName> ?W6 .
	 * 
	 */
	
	
	
	KEY_ID location              = diplo::KM.Get ( "<http://dbpedia.org/ontology/location>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID abbreviation    = diplo::KM.Get ( "<http://dbpedia.org/ontology/abbreviation>" );
	KEY_ID homepage            = diplo::KM.Get ( "<http://dbpedia.org/property/homepage>" );
	KEY_ID state           = diplo::KM.Get ( "<http://dbpedia.org/property/state>" );
	
	KEY_ID seeAlso          = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
	KEY_ID comment      = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID label           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#label>" );
	KEY_ID areaTotal1           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/areaTotal>" );
	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID areaTotal2           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaTotal>" );
	KEY_ID leaderName           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderName>" );

	
	auto &Tlocation              = TM.PredicateMolecules.find( location )->second; //1
	auto &Tcountry           = TM.PredicateMolecules.find( country )->second;  //2 
	auto &Tabbreviation    = TM.PredicateMolecules.find( abbreviation )->second; //1
	auto &Thomepage            = TM.PredicateMolecules.find( homepage )->second; //1
	auto &Tstate           = TM.PredicateMolecules.find( state )->second; //4
	
	auto &TseeAlso           = TM.PredicateMolecules.find( seeAlso )->second; //3
	auto &Tcomment           = TM.PredicateMolecules.find( comment )->second; //7
	auto &Tlabel           = TM.PredicateMolecules.find( label )->second; //8
	auto &TareaTotal1           = TM.PredicateMolecules.find( areaTotal1 )->second; //4
	auto &TareaCode           = TM.PredicateMolecules.find( areaCode )->second; //4
	auto &TareaTotal2           = TM.PredicateMolecules.find( areaTotal2 )->second; //4
	auto &TleaderName           = TM.PredicateMolecules.find( leaderName )->second; //3
	
	
// 					cout << Tlocation.size() << endl; 
// 					cout << Tcountry.size() << endl; 
// 					cout << Tabbreviation.size() << endl; 
// 					cout << Thomepage.size() << endl; 
// 					cout << Tstate.size() << endl; 
// 	
// 					cout << TseeAlso.size() << endl; 
// 					cout << Tcomment.size() << endl; 
// 					cout << Tlabel.size() << endl; 
// 					cout << TareaTotal1.size() << endl; 
// 					cout << TareaCode.size() << endl; 
// 					cout << TareaTotal2.size() << endl; 
// 					cout << TleaderName.size() << endl; 
	
	unordered_set<KEY_ID> moleculesZ1;
// 	unordered_set<KEY_ID> moleculesZ2;
	
		

		
		
		
		for ( auto m : TleaderName ) {
			if ( 
				TareaTotal2.find ( m ) == TareaTotal2.end() or
				TareaCode.find ( m ) == TareaCode.end() or
				TareaTotal1.find ( m ) == TareaTotal1.end() or
				Tlabel.find ( m ) == Tlabel.end() or
				TseeAlso.find ( m ) == TseeAlso.end()
			) continue;

				moleculesZ1.insert ( m );
		}


		
		int i = 0;
		
		for ( auto m : Tlocation ) {
			if (    
				Tcountry.find ( m ) == Tcountry.end() or
				Tabbreviation.find ( m ) == Tabbreviation.end() or
				Thomepage.find ( m ) == Thomepage.end() or
				Thomepage.find ( m ) == Thomepage.end() or
				Tstate.find ( m ) == Tstate.end() 
			) 
				continue;
				
					auto &preds = M.molecules.find ( m )->second;
	

					for ( auto Olocation : preds.find ( location )->second ) {
						if ( moleculesZ1.find ( Olocation ) == moleculesZ1.end() ) continue;
						auto preds_location = M.molecules.find ( Olocation )->second;
						
						for ( auto Ocountry : preds.find ( country )->second ) {
							for ( auto Oabbreviation : preds.find ( abbreviation )->second ) {
								for ( auto Ohomepage : preds.find ( homepage )->second ) {
									for ( auto Ostate : preds.find ( state )->second ) {
										
										//second
										for ( auto OseeAlso : preds_location.find ( seeAlso )->second ) {
											if ( Ocountry != OseeAlso ) continue; //Z2 
											
											for ( auto Ocomment : preds_location.find ( comment )->second ) {
												for ( auto Olabel : preds_location.find ( label )->second ) {
													for ( auto OareaTotal1 : preds_location.find ( areaTotal1 )->second ) {
														for ( auto OareaCode : preds_location.find ( areaCode )->second ) {
															for ( auto OareaTotal2 : preds_location.find ( areaTotal2 )->second ) {
																for ( auto OleaderName : preds_location.find ( leaderName )->second ) {
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
// 		}
		cout << "# " << i << endl; 

		
		
		
		
		
		
		
		
		
		
		
		
	
}		
	
	
void DBP::triangleTemplates() {
	/*
	 * select distinct * where {
	 * 
	 * ?X <http://dbpedia.org/ontology/location> ?Z1 .
	 * ?X <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?X <http://dbpedia.org/ontology/abbreviation> ?Z3 .
	 * ?X <http://dbpedia.org/property/homepage> ?Z4 .
	 * ?X <http://dbpedia.org/property/state> ?Z5 .
	 *    
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?Z2 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#comment> ?W1 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#label> ?W2 .
	 * ?Z1 <http://dbpedia.org/ontology/PopulatedPlace/areaTotal> ?W3 .
	 * ?Z1 <http://dbpedia.org/ontology/areaCode> ?W4 .
	 * ?Z1 <http://dbpedia.org/ontology/areaTotal> ?W5 .
	 * ?Z1 <http://dbpedia.org/ontology/leaderName> ?W6 .
	 * 
	 */
	
	
	
	KEY_ID location              = diplo::KM.Get ( "<http://dbpedia.org/ontology/location>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID abbreviation    = diplo::KM.Get ( "<http://dbpedia.org/ontology/abbreviation>" );
	KEY_ID homepage            = diplo::KM.Get ( "<http://dbpedia.org/property/homepage>" );
	KEY_ID state           = diplo::KM.Get ( "<http://dbpedia.org/property/state>" );
	
	KEY_ID seeAlso          = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
	KEY_ID comment      = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID label           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#label>" );
	KEY_ID areaTotal1           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/areaTotal>" );
	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID areaTotal2           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaTotal>" );
	KEY_ID leaderName           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderName>" );

	
	
	// 	cout << "======" <<endl;
	unordered_set<KEY_ID> moleculesZ1;
	unordered_set<KEY_ID> moleculesZ2;
	{ //second template
		
		auto &TseeAlso           = TM.PredicateTemplates.find( seeAlso )->second; //12
		auto &Tcomment           = TM.PredicateTemplates.find( comment )->second; //20
		auto &Tlabel           = TM.PredicateTemplates.find( label )->second; //21
		auto &TareaTotal1           = TM.PredicateTemplates.find( areaTotal1 )->second; //16
		auto &TareaCode           = TM.PredicateTemplates.find( areaCode )->second; //16
		auto &TareaTotal2           = TM.PredicateTemplates.find( areaTotal2 )->second; //16
		auto &TleaderName           = TM.PredicateTemplates.find( leaderName )->second; //12
		
// 				cout << TseeAlso.size() << endl; 
// 				cout << Tcomment.size() << endl; 
// 				cout << Tlabel.size() << endl; 
// 				cout << TareaTotal1.size() << endl; 
// 				cout << TareaCode.size() << endl; 
// 				cout << TareaTotal2.size() << endl; 
// 				cout << TleaderName.size() << endl; 
		

		
		for ( auto tmpl : TleaderName ) {
			if ( 
				TareaTotal2.find ( tmpl ) == TareaTotal2.end() or
				TareaCode.find ( tmpl ) == TareaCode.end() or
				TareaTotal1.find ( tmpl ) == TareaTotal1.end() or
				Tlabel.find ( tmpl ) == Tlabel.end() or
				TseeAlso.find ( tmpl ) == TseeAlso.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesZ1.insert ( m );
			}
		}
		
	} //second template
// 	cout << "moleculesZ1.size(): "<< moleculesZ1.size() <<endl;
	
	
	{ //firts template
	 auto &Tlocation              = TM.PredicateTemplates.find( location )->second; //6
	 auto &Tcountry           = TM.PredicateTemplates.find( country )->second;  //15 
	 auto &Tabbreviation    = TM.PredicateTemplates.find( abbreviation )->second; //6
	 auto &Thomepage            = TM.PredicateTemplates.find( homepage )->second; //6
	 auto &Tstate           = TM.PredicateTemplates.find( state )->second; //15
	
// 				cout << Tlocation.size() << endl; 
// 				cout << Tcountry.size() << endl; 
// 				cout << Tabbreviation.size() << endl; 
// 				cout << Thomepage.size() << endl; 
// 				cout << Tstate.size() << endl; 
	
		// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : Tlocation ) {
			if (    
				Tcountry.find ( tmpl ) == Tcountry.end() or
				Tabbreviation.find ( tmpl ) == Tabbreviation.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Tstate.find ( tmpl ) == Tstate.end() 
			) 
				continue;
				
				
				auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
				for ( auto m : ms ) {
					
					pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
					if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
					
					
					
					auto &preds = M.molecules.find ( m )->second;
					
					if (preds.find ( location ) == preds.end() 
// 	 					or preds.find ( comment ) == preds.end()
					) continue;

					
					
					for ( auto Olocation : preds.find ( location )->second ) {
						if ( moleculesZ1.find ( Olocation ) == moleculesZ1.end() ) continue;
						auto preds_location = M.molecules.find ( Olocation )->second;
						
						for ( auto Ocountry : preds.find ( country )->second ) {
							for ( auto Oabbreviation : preds.find ( abbreviation )->second ) {
								for ( auto Ohomepage : preds.find ( homepage )->second ) {
									for ( auto Ostate : preds.find ( state )->second ) {
									
										//second
										for ( auto OseeAlso : preds_location.find ( seeAlso )->second ) {
											if ( Ocountry != OseeAlso ) continue; //Z2 
											
											for ( auto Ocomment : preds_location.find ( comment )->second ) {
												for ( auto Olabel : preds_location.find ( label )->second ) {
													for ( auto OareaTotal1 : preds_location.find ( areaTotal1 )->second ) {
														for ( auto OareaCode : preds_location.find ( areaCode )->second ) {
															for ( auto OareaTotal2 : preds_location.find ( areaTotal2 )->second ) {
																for ( auto OleaderName : preds_location.find ( leaderName )->second ) {
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
	}

	
	
	
	
}
	

	
	
	
	void DBP::triangleTemplatesGraph() {
	/*
	 * select distinct * where {
	 * 
	 * ?X <http://dbpedia.org/ontology/location> ?Z1 .
	 * ?X <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?X <http://dbpedia.org/ontology/abbreviation> ?Z3 .
	 * ?X <http://dbpedia.org/property/homepage> ?Z4 .
	 * ?X <http://dbpedia.org/property/state> ?Z5 .
	 *    
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?Z2 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#comment> ?W1 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#label> ?W2 .
	 * ?Z1 <http://dbpedia.org/ontology/PopulatedPlace/areaTotal> ?W3 .
	 * ?Z1 <http://dbpedia.org/ontology/areaCode> ?W4 .
	 * ?Z1 <http://dbpedia.org/ontology/areaTotal> ?W5 .
	 * ?Z1 <http://dbpedia.org/ontology/leaderName> ?W6 .
	 * 
	 */
	
	
	
	KEY_ID location              = diplo::KM.Get ( "<http://dbpedia.org/ontology/location>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID abbreviation    = diplo::KM.Get ( "<http://dbpedia.org/ontology/abbreviation>" );
	KEY_ID homepage            = diplo::KM.Get ( "<http://dbpedia.org/property/homepage>" );
	KEY_ID state           = diplo::KM.Get ( "<http://dbpedia.org/property/state>" );
	
	KEY_ID seeAlso          = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
	KEY_ID comment      = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID label           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#label>" );
	KEY_ID areaTotal1           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/areaTotal>" );
	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID areaTotal2           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaTotal>" );
	KEY_ID leaderName           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderName>" );

	

	
	{ //firts template
	 auto &Tlocation              = TM.PredicateTemplates.find( location )->second; //6
	 auto &Tcountry           = TM.PredicateTemplates.find( country )->second;  //15 
	 auto &Tabbreviation    = TM.PredicateTemplates.find( abbreviation )->second; //6
	 auto &Thomepage            = TM.PredicateTemplates.find( homepage )->second; //6
	 auto &Tstate           = TM.PredicateTemplates.find( state )->second; //15
	
// 				cout << Tlocation.size() << endl; 
// 				cout << Tcountry.size() << endl; 
// 				cout << Tabbreviation.size() << endl; 
// 				cout << Thomepage.size() << endl; 
// 				cout << Tstate.size() << endl; 

		auto &TseeAlso           = TM.PredicateTemplates.find( seeAlso )->second; //12
		auto &Tcomment           = TM.PredicateTemplates.find( comment )->second; //20
		auto &Tlabel           = TM.PredicateTemplates.find( label )->second; //21
		auto &TareaTotal1           = TM.PredicateTemplates.find( areaTotal1 )->second; //16
		auto &TareaCode           = TM.PredicateTemplates.find( areaCode )->second; //16
		auto &TareaTotal2           = TM.PredicateTemplates.find( areaTotal2 )->second; //16
		auto &TleaderName           = TM.PredicateTemplates.find( leaderName )->second; //12
	
		// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : Tlocation ) {
			if (    
				Tcountry.find ( tmpl ) == Tcountry.end() or
				Tabbreviation.find ( tmpl ) == Tabbreviation.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Tstate.find ( tmpl ) == Tstate.end() 
			) 
				continue;
				
				auto &tmplZ = TM.TemplatesGraph.find ( tmpl )->second;
				
				unordered_set<unordered_set<KEY_ID>*> templates1;
				for (auto tmpl2 : tmplZ ) {
					if ( 
						TseeAlso.find ( tmpl2 ) != TseeAlso.end() and
						Tcomment.find ( tmpl2 ) != Tcomment.end() and
						Tlabel.find ( tmpl2 ) != Tlabel.end() and
						TareaTotal1.find ( tmpl2 ) != TareaTotal1.end() and
						TareaCode.find ( tmpl2 ) != TareaCode.end() and
						TareaTotal2.find ( tmpl2 ) != TareaTotal2.end()and
						TleaderName.find ( tmpl2 ) != TleaderName.end()
					) {
						
// 						cout << "tmpl2: " << tmpl2 << endl;
						auto tmplZ2 = TM.TemplatesGraph.find ( tmpl2 );
						bool takeit = false;
// 						cout << "tmplZ2: " << &tmplZ2 << endl;
						if (tmplZ2 != TM.TemplatesGraph.end())
						for (auto Z2 : tmplZ2->second )
							if ( tmplZ.find(Z2) != tmplZ.end() ) 
								takeit = true;

						
						if (takeit) {
							auto &y = TM.TemplateMolecules.find(tmpl2)->second;
							templates1.insert(&y);
						}
					}
				}
				if ( templates1.empty() ) continue;
				
				
				auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
				for ( auto m : ms ) {
					
					pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
					if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
					
					
					
					auto &preds = M.molecules.find ( m )->second;
					
					if (preds.find ( location ) == preds.end() 
// 	 					or preds.find ( comment ) == preds.end()
					) continue;

					
					
					for ( auto Olocation : preds.find ( location )->second ) {
						
						bool takeit = false;
						for (auto t : templates1) { 
							if ( t->find( Olocation ) != t->end() ) {
								takeit = true;
								break;
							}
						}  
						if (!takeit) continue;
						
						
						auto preds_location = M.molecules.find ( Olocation )->second;
						
						for ( auto Ocountry : preds.find ( country )->second ) {
							for ( auto Oabbreviation : preds.find ( abbreviation )->second ) {
								for ( auto Ohomepage : preds.find ( homepage )->second ) {
									for ( auto Ostate : preds.find ( state )->second ) {
									
										//second
										for ( auto OseeAlso : preds_location.find ( seeAlso )->second ) {
											if ( Ocountry != OseeAlso ) continue; //Z2 
											
											for ( auto Ocomment : preds_location.find ( comment )->second ) {
												for ( auto Olabel : preds_location.find ( label )->second ) {
													for ( auto OareaTotal1 : preds_location.find ( areaTotal1 )->second ) {
														for ( auto OareaCode : preds_location.find ( areaCode )->second ) {
															for ( auto OareaTotal2 : preds_location.find ( areaTotal2 )->second ) {
																for ( auto OleaderName : preds_location.find ( leaderName )->second ) {
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
	}

	
	
	
	
}
	
	
	
void DBP::triangle2Predicates() {
	/*
	 * select distinct * where {
	 * 
	 * ?X <http://dbpedia.org/ontology/location> ?Z1 .
	 * ?X <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?X <http://dbpedia.org/ontology/abbreviation> ?Z3 .
	 * ?X <http://dbpedia.org/property/homepage> ?Z4 .
	 * ?X <http://dbpedia.org/property/state> ?Z5 .
	 *    
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?Z2 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#comment> ?W1 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#label> ?W2 .
	 * ?Z1 <http://dbpedia.org/ontology/PopulatedPlace/areaTotal> ?W3 .
	 * ?Z1 <http://dbpedia.org/ontology/areaCode> ?W4 .
	 * ?Z1 <http://dbpedia.org/ontology/areaTotal> ?W5 .
	 * ?Z1 <http://dbpedia.org/ontology/leaderName> ?W6 .
	 * 
	 * ?Z5 <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?Z5 <http://dbpedia.org/ontology/leaderTitle> ?V1 .
	 * ?Z5 <http://dbpedia.org/ontology/areaCode> ?V2 .
	 * ?Z5 <http://dbpedia.org/ontology/elevation> ?V3 .
	 * ?Z5 <http://dbpedia.org/ontology/postalCode> ?V4 .
	 * 
	 */
	
	
	
	KEY_ID location              = diplo::KM.Get ( "<http://dbpedia.org/ontology/location>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID abbreviation    = diplo::KM.Get ( "<http://dbpedia.org/ontology/abbreviation>" );
	KEY_ID homepage            = diplo::KM.Get ( "<http://dbpedia.org/property/homepage>" );
	KEY_ID state           = diplo::KM.Get ( "<http://dbpedia.org/property/state>" );
	
	KEY_ID seeAlso          = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
	KEY_ID comment      = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID label           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#label>" );
	KEY_ID areaTotal1           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/areaTotal>" );
	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID areaTotal2           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaTotal>" );
	KEY_ID leaderName           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderName>" );

// 	KEY_ID country           = ddiplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID leaderTitle           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderTitle>" );
// 	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID elevation           = diplo::KM.Get ( "<http://dbpedia.org/ontology/elevation>" );
	KEY_ID postalCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/postalCode>" );
	
	
	unordered_set<KEY_ID> moleculesZ1;
	{ //second template
		
		auto &TseeAlso           = TM.PredicateMolecules.find( seeAlso )->second; //3
		auto &Tcomment           = TM.PredicateMolecules.find( comment )->second; //7
		auto &Tlabel           = TM.PredicateMolecules.find( label )->second; //8
		auto &TareaTotal1           = TM.PredicateMolecules.find( areaTotal1 )->second; //4
		auto &TareaCode           = TM.PredicateMolecules.find( areaCode )->second; //4
		auto &TareaTotal2           = TM.PredicateMolecules.find( areaTotal2 )->second; //4
		auto &TleaderName           = TM.PredicateMolecules.find( leaderName )->second; //3
		
// 						cout << TseeAlso.size() << endl; 
// 						cout << Tcomment.size() << endl; 
// 						cout << Tlabel.size() << endl; 
// 						cout << TareaTotal1.size() << endl; 
// 						cout << TareaCode.size() << endl; 
// 						cout << TareaTotal2.size() << endl; 
// 						cout << TleaderName.size() << endl; 
// 						cout << "==============" << endl;
						
		for ( auto m : TleaderName ) {
			if ( 
				TareaTotal2.find ( m ) == TareaTotal2.end() or
				TareaCode.find ( m ) == TareaCode.end() or
				TareaTotal1.find ( m ) == TareaTotal1.end() or
				Tlabel.find ( m ) == Tlabel.end() or
				TseeAlso.find ( m ) == TseeAlso.end()
			) continue;
			

				moleculesZ1.insert ( m );

		}
		
	} //second template
	// 	cout << "moleculesZ1.size(): "<< moleculesZ1.size() <<endl;
	
	
	unordered_set<KEY_ID> moleculesZ5;
	{ //3rd template
		auto &Tcountry           = TM.PredicateMolecules.find( country )->second; //4
		auto &TleaderTitle           = TM.PredicateMolecules.find( leaderTitle )->second; //4
		auto &TareaCode           = TM.PredicateMolecules.find( areaCode )->second; //4
		auto &Televation           = TM.PredicateMolecules.find( elevation )->second; //2
		auto &TpostalCode           = TM.PredicateMolecules.find( postalCode )->second; //3
		
// 							cout << Tcountry.size() << endl; 
// 							cout << TleaderTitle.size() << endl; 
// 							cout << TareaCode.size() << endl; 
// 							cout << Televation.size() << endl; 
// 							cout << TpostalCode.size() << endl; 
// 							cout << "==============" << endl;
		
		for ( auto m : Televation ) {
			if ( 
				Tcountry.find ( m ) == Tcountry.end() or
				TleaderTitle.find ( m ) == TleaderTitle.end() or
				TareaCode.find ( m ) == TareaCode.end() or
				TpostalCode.find ( m ) == TpostalCode.end() 
			) continue;

				moleculesZ5.insert ( m );
		}
		
	} //3rd template
	
	
	
	
	
	
	{ //firts template
		auto &Tlocation              = TM.PredicateMolecules.find( location )->second; //1
		auto &Tcountry           = TM.PredicateMolecules.find( country )->second;  //4 
		auto &Tabbreviation    = TM.PredicateMolecules.find( abbreviation )->second; //1
		auto &Thomepage            = TM.PredicateMolecules.find( homepage )->second; //1
		auto &Tstate           = TM.PredicateMolecules.find( state )->second; //4
		
// 						cout << Tlocation.size() << endl; 
// 						cout << Tcountry.size() << endl; 
// 						cout << Tabbreviation.size() << endl; 
// 						cout << Thomepage.size() << endl; 
// 						cout << Tstate.size() << endl; 
// 		cout << "==============" << endl;
		
		// 		unordered_set<KEY_ID> templates;
// 		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto m : Tlocation ) {
			if (    
				Tcountry.find ( m ) == Tcountry.end() or
				Tabbreviation.find ( m ) == Tabbreviation.end() or
				Thomepage.find ( m ) == Thomepage.end() or
				Thomepage.find ( m ) == Thomepage.end() or
				Tstate.find ( m ) == Tstate.end() 
			) 
				continue;
				

					
					auto &preds = M.molecules.find ( m )->second;
					
					
					
					if (    
						preds.find ( location ) == preds.end() or
						preds.find ( state ) == preds.end() or
						preds.find ( country ) == preds.end() or
						preds.find ( abbreviation ) == preds.end() or
						preds.find ( homepage ) == preds.end()
					) 
						continue;
						
						
						for ( auto Olocation : preds.find ( location )->second ) {
							if ( moleculesZ1.find ( Olocation ) == moleculesZ1.end() ) continue;
							auto preds_location = M.molecules.find ( Olocation )->second;
							
							if (    
								preds_location.find ( seeAlso ) == preds_location.end() or
								preds_location.find ( comment ) == preds_location.end() or
								preds_location.find ( label ) == preds_location.end() or
								preds_location.find ( areaTotal1 ) == preds_location.end() or
								preds_location.find ( areaCode ) == preds_location.end() or
								preds_location.find ( areaTotal2 ) == preds_location.end() or
								preds_location.find ( leaderName ) == preds_location.end() 
							) 
								continue;
								
								for ( auto Ostate : preds.find ( state )->second ) {
									if ( moleculesZ5.find ( Ostate ) == moleculesZ5.end() ) continue;
									auto preds_state = M.molecules.find ( Ostate )->second;
									
									if (    
										preds_state.find ( country ) == preds_state.end() or
										preds_state.find ( leaderTitle ) == preds_state.end() or
										preds_state.find ( areaCode ) == preds_state.end() or
										preds_state.find ( elevation ) == preds_state.end() or
										preds_state.find ( postalCode ) == preds_state.end()
									) 
										continue;
										
										for ( auto Ocountry : preds.find ( country )->second ) {
											// 								for ( auto Oabbreviation : preds.find ( abbreviation )->second ) {
											// 									for ( auto Ohomepage : preds.find ( homepage )->second ) {
											
											//second
											for ( auto OseeAlso : preds_location.find ( seeAlso )->second ) {
												if ( Ocountry != OseeAlso ) continue; //Z1->Z2 
												
												// 											for ( auto Ocomment : preds_location.find ( comment )->second ) {
												// 												for ( auto Olabel : preds_location.find ( label )->second ) {
												// 													for ( auto OareaTotal1 : preds_location.find ( areaTotal1 )->second ) {
												// 														for ( auto OareaCode : preds_location.find ( areaCode )->second ) {
												// 															for ( auto OareaTotal2 : preds_location.find ( areaTotal2 )->second ) {
												// 																for ( auto OleaderName : preds_location.find ( leaderName )->second ) {
												
												//3rd
												for ( auto Ocountry1 : preds_state.find ( country )->second ) {
													if ( Ocountry != Ocountry1 ) continue; //Z5->Z2 
													i++;
												}
											}
										}
								}
						}
		}
					
					

					
					
					/*
					for ( auto Olocation : preds.find ( location )->second ) {
						if ( moleculesZ1.find ( Olocation ) == moleculesZ1.end() ) continue;
						auto preds_location = M.molecules.find ( Olocation )->second;
						
						for ( auto Ostate : preds.find ( state )->second ) {
							if ( moleculesZ5.find ( Ostate ) == moleculesZ5.end() ) continue;
							auto preds_state = M.molecules.find ( Ostate )->second;
							
							for ( auto Ocountry : preds.find ( country )->second ) {
								for ( auto Oabbreviation : preds.find ( abbreviation )->second ) {
									for ( auto Ohomepage : preds.find ( homepage )->second ) {
										
										//second
										for ( auto OseeAlso : preds_location.find ( seeAlso )->second ) {
											if ( Ocountry != OseeAlso ) continue; //Z1->Z2 
											
											for ( auto Ocomment : preds_location.find ( comment )->second ) {
												for ( auto Olabel : preds_location.find ( label )->second ) {
													for ( auto OareaTotal1 : preds_location.find ( areaTotal1 )->second ) {
														for ( auto OareaCode : preds_location.find ( areaCode )->second ) {
															for ( auto OareaTotal2 : preds_location.find ( areaTotal2 )->second ) {
																for ( auto OleaderName : preds_location.find ( leaderName )->second ) {
																	
																	//3rd
																	for ( auto Ocountry1 : preds_state.find ( country )->second ) {
																		if ( Ocountry != Ocountry1 ) continue; //Z5->Z2 
																		
																		for ( auto OleaderTitle : preds_state.find ( leaderTitle )->second ) {
																			for ( auto OareaCode1 : preds_state.find ( areaCode )->second ) {
																				for ( auto Oelevation : preds_state.find ( elevation )->second ) {
																					for ( auto OpostalCode : preds_state.find ( postalCode )->second ) {
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
					}	
				}
// 		}*/
		cout << "# " << i << endl; 
	}
	
	
	
	
	
	
	
	
	
	
	
}
	
	
	
void DBP::triangle2Templates() {
	/*
	 * select distinct ?X ?Z1 ?Z2 ?Z5 where {
	 * 
	 * ?X <http://dbpedia.org/ontology/location> ?Z1 .
	 * ?X <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?X <http://dbpedia.org/ontology/abbreviation> ?Z3 .
	 * ?X <http://dbpedia.org/property/homepage> ?Z4 .
	 * ?X <http://dbpedia.org/property/state> ?Z5 .
	 *    
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?Z2 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#comment> ?W1 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#label> ?W2 .
	 * ?Z1 <http://dbpedia.org/ontology/PopulatedPlace/areaTotal> ?W3 .
	 * ?Z1 <http://dbpedia.org/ontology/areaCode> ?W4 .
	 * ?Z1 <http://dbpedia.org/ontology/areaTotal> ?W5 .
	 * ?Z1 <http://dbpedia.org/ontology/leaderName> ?W6 .
	 * 
	 * ?Z5 <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?Z5 <http://dbpedia.org/ontology/leaderTitle> ?V1 .
	 * ?Z5 <http://dbpedia.org/ontology/areaCode> ?V2 .
	 * ?Z5 <http://dbpedia.org/ontology/elevation> ?V3 .
	 * ?Z5 <http://dbpedia.org/ontology/postalCode> ?V4 .
	 * 
	 */
	
	
	
	KEY_ID location              = diplo::KM.Get ( "<http://dbpedia.org/ontology/location>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID abbreviation    = diplo::KM.Get ( "<http://dbpedia.org/ontology/abbreviation>" );
	KEY_ID homepage            = diplo::KM.Get ( "<http://dbpedia.org/property/homepage>" );
	KEY_ID state           = diplo::KM.Get ( "<http://dbpedia.org/property/state>" );
	
	KEY_ID seeAlso          = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
	KEY_ID comment      = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID label           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#label>" );
	KEY_ID areaTotal1           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/areaTotal>" );
	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID areaTotal2           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaTotal>" );
	KEY_ID leaderName           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderName>" );

// 	KEY_ID country           = ddiplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID leaderTitle           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderTitle>" );
// 	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID elevation           = diplo::KM.Get ( "<http://dbpedia.org/ontology/elevation>" );
	KEY_ID postalCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/postalCode>" );
	
	
	unordered_set<KEY_ID> moleculesZ1;
	{ //second template
		
		auto &TseeAlso           = TM.PredicateTemplates.find( seeAlso )->second; //12
		auto &Tcomment           = TM.PredicateTemplates.find( comment )->second; //20
		auto &Tlabel           = TM.PredicateTemplates.find( label )->second; //21
		auto &TareaTotal1           = TM.PredicateTemplates.find( areaTotal1 )->second; //16
		auto &TareaCode           = TM.PredicateTemplates.find( areaCode )->second; //16
		auto &TareaTotal2           = TM.PredicateTemplates.find( areaTotal2 )->second; //16
		auto &TleaderName           = TM.PredicateTemplates.find( leaderName )->second; //12
		
// 		cout << "TseeAlso: " << TseeAlso.size() << endl; 
// 		cout << "Tcomment: " << Tcomment.size() << endl; 
// 		cout << "Tlabel: " << Tlabel.size() << endl; 
// 		cout << "TareaTotal1: " << TareaTotal1.size() << endl; 
// 		cout << "TareaCode: " << TareaCode.size() << endl; 
// 		cout << "TareaTotal2: " << TareaTotal2.size() << endl; 
// 		cout << "TleaderName: " << TleaderName.size() << endl; 
		

		
		for ( auto tmpl : TleaderName ) {
			if ( 
				TareaTotal2.find ( tmpl ) == TareaTotal2.end() or
				TareaCode.find ( tmpl ) == TareaCode.end() or
				TareaTotal1.find ( tmpl ) == TareaTotal1.end() or
				Tlabel.find ( tmpl ) == Tlabel.end() or
				TseeAlso.find ( tmpl ) == TseeAlso.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesZ1.insert ( m );
			}
		}
		
	} //second template
//   	cout << "moleculesZ1.size(): "<< moleculesZ1.size() <<endl;


unordered_set<KEY_ID> moleculesZ5;
{ //3rd template
	auto &Tcountry           = TM.PredicateTemplates.find( country )->second; //15
	auto &TleaderTitle           = TM.PredicateTemplates.find( leaderTitle )->second; //16
	auto &TareaCode           = TM.PredicateTemplates.find( areaCode )->second; //16
	auto &Televation           = TM.PredicateTemplates.find( elevation )->second; //13
	auto &TpostalCode           = TM.PredicateTemplates.find( postalCode )->second; //14

// 	cout << "Tcountry: " << Tcountry.size() << endl; 
// 	cout << "TleaderTitle: " << TleaderTitle.size() << endl; 
// 	cout << "TareaCode: " << TareaCode.size() << endl; 
// 	cout << "Televation: " << Televation.size() << endl; 
// 	cout << "TpostalCode: " << TpostalCode.size() << endl; 
	
	for ( auto tmpl : Televation ) {
		if ( 
			Tcountry.find ( tmpl ) == Tcountry.end() or
			TleaderTitle.find ( tmpl ) == TleaderTitle.end() or
			TareaCode.find ( tmpl ) == TareaCode.end() or
			TpostalCode.find ( tmpl ) == TpostalCode.end() 
		) continue;
		
		
		auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
		for ( auto m : ms ) {
			moleculesZ5.insert ( m );
		}
	}
	
} //3rd template

//   	cout << "moleculesZ5.size(): "<< moleculesZ5.size() <<endl;
// 	return;
	
	{ //firts template
	 auto &Tlocation              = TM.PredicateTemplates.find( location )->second; //6
	 auto &Tcountry           = TM.PredicateTemplates.find( country )->second;  //15 
	 auto &Tabbreviation    = TM.PredicateTemplates.find( abbreviation )->second; //6
	 auto &Thomepage            = TM.PredicateTemplates.find( homepage )->second; //6
	 auto &Tstate           = TM.PredicateTemplates.find( state )->second; //15
	
// 	cout << "Tlocation: " << Tlocation.size() << endl; 
// 	cout << "Tcountry: " << Tcountry.size() << endl; 
// 	cout << "Tabbreviation: " << Tabbreviation.size() << endl; 
// 	cout << "Thomepage: " << Thomepage.size() << endl; 
// 	cout << "Tstate: " << Tstate.size() << endl; 
	
		// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : Tlocation ) {
			if (    
				Tcountry.find ( tmpl ) == Tcountry.end() or
				Tabbreviation.find ( tmpl ) == Tabbreviation.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Tstate.find ( tmpl ) == Tstate.end() 
			) 
				continue;
				
				
				auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
				for ( auto m : ms ) {
					
					pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
					if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
					
					
					
					auto &preds = M.molecules.find ( m )->second;
					
// 					if (preds.find ( location ) == preds.end() 
// // 	 					or preds.find ( comment ) == preds.end()
// 					) continue;

					if (    
						preds.find ( location ) == preds.end() or
						preds.find ( state ) == preds.end() or
						preds.find ( country ) == preds.end() or
						preds.find ( abbreviation ) == preds.end() or
						preds.find ( homepage ) == preds.end()
					) 
						continue;
						
					
					for ( auto Olocation : preds.find ( location )->second ) {
						if ( moleculesZ1.find ( Olocation ) == moleculesZ1.end() ) continue;
						auto preds_location = M.molecules.find ( Olocation )->second;
						
						if (    
							preds_location.find ( seeAlso ) == preds_location.end() or
							preds_location.find ( comment ) == preds_location.end() or
							preds_location.find ( label ) == preds_location.end() or
							preds_location.find ( areaTotal1 ) == preds_location.end() or
							preds_location.find ( areaCode ) == preds_location.end() or
							preds_location.find ( areaTotal2 ) == preds_location.end() or
							preds_location.find ( leaderName ) == preds_location.end() 
						) 
							continue;
						
						for ( auto Ostate : preds.find ( state )->second ) {
							if ( moleculesZ5.find ( Ostate ) == moleculesZ5.end() ) continue;
							auto preds_state = M.molecules.find ( Ostate )->second;
							
							if (    
								preds_state.find ( country ) == preds_state.end() or
								preds_state.find ( leaderTitle ) == preds_state.end() or
								preds_state.find ( areaCode ) == preds_state.end() or
								preds_state.find ( elevation ) == preds_state.end() or
								preds_state.find ( postalCode ) == preds_state.end()
							) 
								continue;
						
 							for ( auto Ocountry : preds.find ( country )->second ) {
// 								for ( auto Oabbreviation : preds.find ( abbreviation )->second ) {
// 									for ( auto Ohomepage : preds.find ( homepage )->second ) {
										
										//second
										for ( auto OseeAlso : preds_location.find ( seeAlso )->second ) {
											if ( Ocountry != OseeAlso ) continue; //Z1->Z2 
											
// 											for ( auto Ocomment : preds_location.find ( comment )->second ) {
// 												for ( auto Olabel : preds_location.find ( label )->second ) {
// 													for ( auto OareaTotal1 : preds_location.find ( areaTotal1 )->second ) {
// 														for ( auto OareaCode : preds_location.find ( areaCode )->second ) {
// 															for ( auto OareaTotal2 : preds_location.find ( areaTotal2 )->second ) {
// 																for ( auto OleaderName : preds_location.find ( leaderName )->second ) {
																	
																	//3rd
																	for ( auto Ocountry1 : preds_state.find ( country )->second ) {
																		if ( Ocountry != Ocountry1 ) continue; //Z5->Z2 

// 																		for ( auto OleaderTitle : preds_state.find ( leaderTitle )->second ) {
// 																			for ( auto OareaCode1 : preds_state.find ( areaCode )->second ) {
// 																				for ( auto Oelevation : preds_state.find ( elevation )->second ) {
// 																					for ( auto OpostalCode : preds_state.find ( postalCode )->second ) {
																							i++;
// 																					}
// 																				}
// 																			}
// 																		}
																	}
// 																}
// 															}
// 														}
// 													}
// 												}
// 											}
										}
									}
// 								}
// 							}
 						}
					}	
				}
		}
		cout << "# " << i << endl; 
	}

	
}
	
	
	
void DBP::triangle2TemplatesGraph() {
	/*
	 * select distinct * where {
	 * 
	 * ?X <http://dbpedia.org/ontology/location> ?Z1 .
	 * ?X <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?X <http://dbpedia.org/ontology/abbreviation> ?Z3 .
	 * ?X <http://dbpedia.org/property/homepage> ?Z4 .
	 * ?X <http://dbpedia.org/property/state> ?Z5 .
	 *    
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?Z2 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#comment> ?W1 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#label> ?W2 .
	 * ?Z1 <http://dbpedia.org/ontology/PopulatedPlace/areaTotal> ?W3 .
	 * ?Z1 <http://dbpedia.org/ontology/areaCode> ?W4 .
	 * ?Z1 <http://dbpedia.org/ontology/areaTotal> ?W5 .
	 * ?Z1 <http://dbpedia.org/ontology/leaderName> ?W6 .
	 * 
	 * ?Z5 <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?Z5 <http://dbpedia.org/ontology/leaderTitle> ?V1 .
	 * ?Z5 <http://dbpedia.org/ontology/areaCode> ?V2 .
	 * ?Z5 <http://dbpedia.org/ontology/elevation> ?V3 .
	 * ?Z5 <http://dbpedia.org/ontology/postalCode> ?V4 .
	 * 
	 */
	
	
	
	KEY_ID location              = diplo::KM.Get ( "<http://dbpedia.org/ontology/location>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID abbreviation    = diplo::KM.Get ( "<http://dbpedia.org/ontology/abbreviation>" );
	KEY_ID homepage            = diplo::KM.Get ( "<http://dbpedia.org/property/homepage>" );
	KEY_ID state           = diplo::KM.Get ( "<http://dbpedia.org/property/state>" );
	
	KEY_ID seeAlso          = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
	KEY_ID comment      = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID label           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#label>" );
	KEY_ID areaTotal1           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/areaTotal>" );
	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID areaTotal2           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaTotal>" );
	KEY_ID leaderName           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderName>" );
	
	// 	KEY_ID country           = ddiplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID leaderTitle           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderTitle>" );
	// 	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID elevation           = diplo::KM.Get ( "<http://dbpedia.org/ontology/elevation>" );
	KEY_ID postalCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/postalCode>" );

	

	
	{ //firts template
	 auto &Tlocation              = TM.PredicateTemplates.find( location )->second; //6
	 auto &Tcountry           = TM.PredicateTemplates.find( country )->second;  //15 
	 auto &Tabbreviation    = TM.PredicateTemplates.find( abbreviation )->second; //6
	 auto &Thomepage            = TM.PredicateTemplates.find( homepage )->second; //6
	 auto &Tstate           = TM.PredicateTemplates.find( state )->second; //15
	
// 				cout << Tlocation.size() << endl; 
// 				cout << Tcountry.size() << endl; 
// 				cout << Tabbreviation.size() << endl; 
// 				cout << Thomepage.size() << endl; 
// 				cout << Tstate.size() << endl; 

		auto &TseeAlso           = TM.PredicateTemplates.find( seeAlso )->second; //12
		auto &Tcomment           = TM.PredicateTemplates.find( comment )->second; //20
		auto &Tlabel           = TM.PredicateTemplates.find( label )->second; //21
		auto &TareaTotal1           = TM.PredicateTemplates.find( areaTotal1 )->second; //16
		auto &TareaCode           = TM.PredicateTemplates.find( areaCode )->second; //16
		auto &TareaTotal2           = TM.PredicateTemplates.find( areaTotal2 )->second; //16
		auto &TleaderName           = TM.PredicateTemplates.find( leaderName )->second; //12
	
// 		auto &Tcountry           = TM.PredicateTemplates.find( country )->second; //15
		auto &TleaderTitle           = TM.PredicateTemplates.find( leaderTitle )->second; //16
// 		auto &TareaCode           = TM.PredicateTemplates.find( areaCode )->second; //16
		auto &Televation           = TM.PredicateTemplates.find( elevation )->second; //13
		auto &TpostalCode           = TM.PredicateTemplates.find( postalCode )->second; //14
	
	
		// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : Tlocation ) {
			if (    
				Tcountry.find ( tmpl ) == Tcountry.end() or
				Tabbreviation.find ( tmpl ) == Tabbreviation.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Tstate.find ( tmpl ) == Tstate.end() 
			) 
				continue;
				
				auto &tmplZ = TM.TemplatesGraph.find ( tmpl )->second;
				
				unordered_set<unordered_set<KEY_ID>*> templatesZ1;
				unordered_set<unordered_set<KEY_ID>*> templatesZ5;
				for (auto tmpl2 : tmplZ ) {
					if ( 
						TseeAlso.find ( tmpl2 ) != TseeAlso.end() and
						Tcomment.find ( tmpl2 ) != Tcomment.end() and
						Tlabel.find ( tmpl2 ) != Tlabel.end() and
						TareaTotal1.find ( tmpl2 ) != TareaTotal1.end() and
						TareaCode.find ( tmpl2 ) != TareaCode.end() and
						TareaTotal2.find ( tmpl2 ) != TareaTotal2.end()and
						TleaderName.find ( tmpl2 ) != TleaderName.end() 
					) {
						
// 						cout << "tmpl2: " << tmpl2 << endl;
						auto tmplZ2 = TM.TemplatesGraph.find ( tmpl2 );
						bool takeit = false;
// 						cout << "tmplZ2: " << &tmplZ2 << endl;
						if (tmplZ2 != TM.TemplatesGraph.end())
						for (auto Z2 : tmplZ2->second )
							if ( tmplZ.find(Z2) != tmplZ.end() ) 
								takeit = true;

						
						if (takeit) {
							auto &y = TM.TemplateMolecules.find(tmpl2)->second;
							templatesZ1.insert(&y);
						}
					} 
					
					
					if (
						Tcountry.find ( tmpl2 ) != Tcountry.end() and
						TleaderTitle.find ( tmpl2 ) != TleaderTitle.end() and
						TareaCode.find ( tmpl2 ) != TareaCode.end() and
						Televation.find ( tmpl2 ) != Televation.end() and
						TpostalCode.find ( tmpl2 ) != TpostalCode.end() 
					) {
						
						// 						cout << "tmpl2: " << tmpl2 << endl;
						auto tmplZ5 = TM.TemplatesGraph.find ( tmpl2 );
						bool takeit = false;
						// 						cout << "tmplZ2: " << &tmplZ2 << endl;
						if (tmplZ5 != TM.TemplatesGraph.end())
							for (auto Z5 : tmplZ5->second )
								if ( tmplZ.find(Z5) != tmplZ.end() ) 
									takeit = true;
								
								if (takeit) {
									auto &y = TM.TemplateMolecules.find(tmpl2)->second;
									templatesZ5.insert(&y);
								}
				}
			}
				if ( templatesZ1.empty() or templatesZ5.empty() ) continue;
				
				
				auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
				for ( auto m : ms ) {
					
					pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
					if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
					
					
					
					auto &preds = M.molecules.find ( m )->second;
					
					if (preds.find ( location ) == preds.end() 
// 	 					or preds.find ( comment ) == preds.end()
					) continue;

					
					
					for ( auto Olocation : preds.find ( location )->second ) { //Z1
						
						bool takeit = false;
						for (auto t : templatesZ1) { 
							if ( t->find( Olocation ) != t->end() ) {
								takeit = true;
								break;
							}
						}  
						if (!takeit) continue;
						
						
						auto preds_location = M.molecules.find ( Olocation )->second;
						
						for ( auto Ostate : preds.find ( state )->second ) { //Z5
							
							
							bool takeit = false;
							for (auto t : templatesZ5) { 
								if ( t->find( Ostate ) != t->end() ) {
									takeit = true;
									break;
								}
							}  
							if (!takeit) continue;
							auto preds_state = M.molecules.find ( Ostate )->second;
							
						
							for ( auto Ocountry : preds.find ( country )->second ) {
								for ( auto Oabbreviation : preds.find ( abbreviation )->second ) {
									for ( auto Ohomepage : preds.find ( homepage )->second ) {
									
										//second
										for ( auto OseeAlso : preds_location.find ( seeAlso )->second ) {
											if ( Ocountry != OseeAlso ) continue; //Z2 
											
											for ( auto Ocomment : preds_location.find ( comment )->second ) {
												for ( auto Olabel : preds_location.find ( label )->second ) {
													for ( auto OareaTotal1 : preds_location.find ( areaTotal1 )->second ) {
														for ( auto OareaCode : preds_location.find ( areaCode )->second ) {
															for ( auto OareaTotal2 : preds_location.find ( areaTotal2 )->second ) {
																for ( auto OleaderName : preds_location.find ( leaderName )->second ) {
																	
																	//3rd
																	for ( auto Ocountry1 : preds_state.find ( country )->second ) {
																		if ( Ocountry != Ocountry1 ) continue; //Z5->Z2 
																		
																		for ( auto OleaderTitle : preds_state.find ( leaderTitle )->second ) {
																			for ( auto OareaCode1 : preds_state.find ( areaCode )->second ) {
																				for ( auto Oelevation : preds_state.find ( elevation )->second ) {
																					for ( auto OpostalCode : preds_state.find ( postalCode )->second ) {
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
					}	
				}
		}
		cout << "# " << i << endl; 
	}

	
}
	
	
	
	
	void DBP::triangle3Templates() {
	/*
	 * select distinct * where {
	 * 
	 * ?X <http://dbpedia.org/ontology/location> ?Z1 .
	 * ?X <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?X <http://dbpedia.org/ontology/abbreviation> ?Z3 .
	 * ?X <http://dbpedia.org/property/homepage> ?Z4 .
	 * ?X <http://dbpedia.org/property/state> ?Z5 .
	 *    
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#seeAlso> ?Z2 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#comment> ?W1 .
	 * ?Z1 <http://www.w3.org/2000/01/rdf-schema#label> ?W2 .
	 * ?Z1 <http://dbpedia.org/ontology/PopulatedPlace/areaTotal> ?W3 .
	 * ?Z1 <http://dbpedia.org/ontology/areaCode> ?W4 .
	 * ?Z1 <http://dbpedia.org/ontology/areaTotal> ?W5 .
	 * ?Z1 <http://dbpedia.org/ontology/leaderName> ?W6 .
	 * 
	 * ?Z5 <http://dbpedia.org/ontology/country> ?Z2 .
	 * ?Z5 <http://dbpedia.org/ontology/leaderTitle> ?V1 .
	 * ?Z5 <http://dbpedia.org/ontology/areaCode> ?V2 .
	 * ?Z5 <http://dbpedia.org/ontology/elevation> ?V3 .
	 * ?Z5 <http://dbpedia.org/ontology/postalCode> ?V4 .
	 * 
	 */
	
	
	
	KEY_ID location              = diplo::KM.Get ( "<http://dbpedia.org/ontology/location>" );
	KEY_ID country           = diplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID abbreviation    = diplo::KM.Get ( "<http://dbpedia.org/ontology/abbreviation>" );
	KEY_ID homepage            = diplo::KM.Get ( "<http://dbpedia.org/property/homepage>" );
	KEY_ID state           = diplo::KM.Get ( "<http://dbpedia.org/property/state>" );
	
	KEY_ID seeAlso          = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#seeAlso>" );
	KEY_ID comment      = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#comment>" );
	KEY_ID label           = diplo::KM.Get ( "<http://www.w3.org/2000/01/rdf-schema#label>" );
	KEY_ID areaTotal1           = diplo::KM.Get ( "<http://dbpedia.org/ontology/PopulatedPlace/areaTotal>" );
	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID areaTotal2           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaTotal>" );
	KEY_ID leaderName           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderName>" );

// 	KEY_ID country           = ddiplo::KM.Get ( "<http://dbpedia.org/ontology/country>" );
	KEY_ID leaderTitle           = diplo::KM.Get ( "<http://dbpedia.org/ontology/leaderTitle>" );
// 	KEY_ID areaCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/areaCode>" );
	KEY_ID elevation           = diplo::KM.Get ( "<http://dbpedia.org/ontology/elevation>" );
	KEY_ID postalCode           = diplo::KM.Get ( "<http://dbpedia.org/ontology/postalCode>" );
	
	
	unordered_set<KEY_ID> moleculesZ1;
	{ //second template
		
		auto &TseeAlso           = TM.PredicateTemplates.find( seeAlso )->second; //12
		auto &Tcomment           = TM.PredicateTemplates.find( comment )->second; //20
		auto &Tlabel           = TM.PredicateTemplates.find( label )->second; //21
		auto &TareaTotal1           = TM.PredicateTemplates.find( areaTotal1 )->second; //16
		auto &TareaCode           = TM.PredicateTemplates.find( areaCode )->second; //16
		auto &TareaTotal2           = TM.PredicateTemplates.find( areaTotal2 )->second; //16
		auto &TleaderName           = TM.PredicateTemplates.find( leaderName )->second; //12
		
// 				cout << TseeAlso.size() << endl; 
// 				cout << Tcomment.size() << endl; 
// 				cout << Tlabel.size() << endl; 
// 				cout << TareaTotal1.size() << endl; 
// 				cout << TareaCode.size() << endl; 
// 				cout << TareaTotal2.size() << endl; 
// 				cout << TleaderName.size() << endl; 
		

		
		for ( auto tmpl : TleaderName ) {
			if ( 
				TareaTotal2.find ( tmpl ) == TareaTotal2.end() or
				TareaCode.find ( tmpl ) == TareaCode.end() or
				TareaTotal1.find ( tmpl ) == TareaTotal1.end() or
				Tlabel.find ( tmpl ) == Tlabel.end() or
				TseeAlso.find ( tmpl ) == TseeAlso.end()
			) continue;
			
			
			auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
			for ( auto m : ms ) {
				moleculesZ1.insert ( m );
			}
		}
		
	} //second template
// 	cout << "moleculesZ1.size(): "<< moleculesZ1.size() <<endl;


unordered_set<KEY_ID> moleculesZ5;
{ //3rd template
	auto &Tcountry           = TM.PredicateTemplates.find( country )->second; //15
	auto &TleaderTitle           = TM.PredicateTemplates.find( leaderTitle )->second; //16
	auto &TareaCode           = TM.PredicateTemplates.find( areaCode )->second; //16
	auto &Televation           = TM.PredicateTemplates.find( elevation )->second; //13
	auto &TpostalCode           = TM.PredicateTemplates.find( postalCode )->second; //14

// 					cout << Tcountry.size() << endl; 
// 					cout << TleaderTitle.size() << endl; 
// 					cout << TareaCode.size() << endl; 
// 					cout << Televation.size() << endl; 
// 					cout << TpostalCode.size() << endl; 
	
	for ( auto tmpl : Televation ) {
		if ( 
			Tcountry.find ( tmpl ) == Tcountry.end() or
			TleaderTitle.find ( tmpl ) == TleaderTitle.end() or
			TareaCode.find ( tmpl ) == TareaCode.end() or
			TpostalCode.find ( tmpl ) == TpostalCode.end() 
		) continue;
		
		
		auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
		for ( auto m : ms ) {
			moleculesZ5.insert ( m );
		}
	}
	
} //3rd template

// 	cout << "moleculesZ5.size(): "<< moleculesZ5.size() <<endl;
// 	return;
	
	{ //firts template
	 auto &Tlocation              = TM.PredicateTemplates.find( location )->second; //6
	 auto &Tcountry           = TM.PredicateTemplates.find( country )->second;  //15 
	 auto &Tabbreviation    = TM.PredicateTemplates.find( abbreviation )->second; //6
	 auto &Thomepage            = TM.PredicateTemplates.find( homepage )->second; //6
	 auto &Tstate           = TM.PredicateTemplates.find( state )->second; //15
	
// 				cout << Tlocation.size() << endl; 
// 				cout << Tcountry.size() << endl; 
// 				cout << Tabbreviation.size() << endl; 
// 				cout << Thomepage.size() << endl; 
// 				cout << Tstate.size() << endl; 
	
		// 		unordered_set<KEY_ID> templates;
		unordered_set<KEY_ID> moleculesDone;
		int i=0;
		for ( auto tmpl : Tlocation ) {
			if (    
				Tcountry.find ( tmpl ) == Tcountry.end() or
				Tabbreviation.find ( tmpl ) == Tabbreviation.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Thomepage.find ( tmpl ) == Thomepage.end() or
				Tstate.find ( tmpl ) == Tstate.end() 
			) 
				continue;
				
				
				auto &ms = TM.TemplateMolecules.find ( tmpl )->second;
				for ( auto m : ms ) {
					
					pair<unordered_set<KEY_ID>::iterator,bool> INSmoleculesDone = moleculesDone.insert ( m ) ;
					if ( INSmoleculesDone.second == false ) continue;    // this molecule was already done
					
					
					
					auto &preds = M.molecules.find ( m )->second;
					
					if (preds.find ( location ) == preds.end() 
// 	 					or preds.find ( comment ) == preds.end()
					) continue;

					
					
					for ( auto Olocation : preds.find ( location )->second ) {
						if ( moleculesZ1.find ( Olocation ) == moleculesZ1.end() ) continue;
						auto preds_location = M.molecules.find ( Olocation )->second;
						
						for ( auto Ostate : preds.find ( state )->second ) {
							if ( moleculesZ5.find ( Ostate ) == moleculesZ5.end() ) continue;
							auto preds_state = M.molecules.find ( Ostate )->second;
						
							for ( auto Ocountry : preds.find ( country )->second ) {
								for ( auto Oabbreviation : preds.find ( abbreviation )->second ) {
									for ( auto Ohomepage : preds.find ( homepage )->second ) {
										
										//second
										for ( auto OseeAlso : preds_location.find ( seeAlso )->second ) {
											if ( Ocountry != OseeAlso ) continue; //Z1->Z2 
											
											for ( auto Ocomment : preds_location.find ( comment )->second ) {
												for ( auto Olabel : preds_location.find ( label )->second ) {
													for ( auto OareaTotal1 : preds_location.find ( areaTotal1 )->second ) {
														for ( auto OareaCode : preds_location.find ( areaCode )->second ) {
															for ( auto OareaTotal2 : preds_location.find ( areaTotal2 )->second ) {
																for ( auto OleaderName : preds_location.find ( leaderName )->second ) {
																	
																	//3rd
																	for ( auto Ocountry1 : preds_state.find ( country )->second ) {
																		if ( Ocountry != Ocountry1 ) continue; //Z5->Z2 

																		for ( auto OleaderTitle : preds_state.find ( leaderTitle )->second ) {
																			for ( auto OareaCode1 : preds_state.find ( areaCode )->second ) {
																				for ( auto Oelevation : preds_state.find ( elevation )->second ) {
																					for ( auto OpostalCode : preds_state.find ( postalCode )->second ) {
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
					}	
				}
		}
		cout << "# " << i << endl; 
	}

	
}
	
	
	
}
	
	
	
