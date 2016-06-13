/*
 * BTCprov.cpp
 *
 *  Created on: Jul 18, 2013
 *      Author: marcin
 */

#include "BTCprov.h"

namespace queries {

BTCprov::BTCprov() {
    // TODO Auto-generated constructor stub

}

BTCprov::~BTCprov() {
    // TODO Auto-generated destructor stub
}

void BTCprov::q01() {
    /*
     * select ?lat ?long
    where {
    ?a [] "Eiffel Tower".
    ?a <http://www.geonames.org/ontology#inCountry> <http://www.geonames.org/countries/#FR>.
    ?a <http://www.w3.org/2003/01/geo/wgs84_pos#lat> ?lat.
    ?a <http://www.w3.org/2003/01/geo/wgs84_pos#long> ?long. }
     */

    KEY_ID EiffelTower = diplo::KM.Get("\"Eiffel Tower\"");

    KEY_ID inCountry = diplo::KM.Get("<http://www.geonames.org/ontology#inCountry>");
    KEY_ID fr = diplo::KM.Get("<http://www.geonames.org/countries/#FR>");

    KEY_ID lat = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#lat>");
    KEY_ID llong = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#long>");

    KEY_ID name2 = diplo::KM.Get("<http://www.geonames.org/ontology#name>");

    vector<QueryGraph> graph;
    {
        QueryGraph patern;
        patern.predicate.second = name2;
//         patern.object.second = EiffelTower;
        graph.push_back(patern);
    }
    {
        QueryGraph patern;
        patern.predicate.second = inCountry;
//         patern.object.second = fr;
        graph.push_back(patern);
    }
    {
        QueryGraph patern;
        patern.subject.first = QF_PROJECTION;
        patern.predicate.second = lat;
        patern.object.first = QF_PROJECTION;
        graph.push_back(patern);
    }
    {
        QueryGraph patern;
        patern.predicate.second = llong;
        patern.object.first = QF_PROJECTION;
        graph.push_back(patern);
    }

    unordered_multimap<KEY_ID, vector<KEY_ID> > results;
// 	API::TriplePatern(graph, results, '0');
// 	API::DisplayResults(results,3);

// 	cerr << "API::TriplePatern(graph, results, 's');" << endl;
// 	API::TriplePatern(graph, results, 's');
// 
//     cerr << "API::TriplePatern_FromTemplates(graph, results, 'n');" << endl;
//     API::TriplePatern_FromTemplates(graph, results, 's', 'n');

	cerr << "API::TriplePatern_FromTemplates(graph, results, 'P');" << endl;
    API::TriplePatern_FromTemplates(graph, results, 's', 'P');
	
	cerr << "API::TriplePatern_FromTemplates(graph, results, 'T');" << endl;
    API::TriplePatern_FromTemplates(graph, results, 's', 'T');
}
//
//void BTCprov::q02() {
//	/*
//select ?b ?p ?bn
//where {
//?a [] "Tim Berners-Lee".
//?a <http://dbpedia.org/property/dateOfBirth> ?b.
//?a <http://dbpedia.org/property/placeOfBirth> ?p.
//?a <http://dbpedia.org/property/name> ?bn. }
//	 */
//
//	KEY_ID tbl = diplo::KM.Get("\"Tim Berners-Lee\"");
//
//	KEY_ID dateOfBirth = diplo::KM.Get("<http://dbpedia.org/property/dateOfBirth>");
//	KEY_ID placeOfBirth = diplo::KM.Get("<http://dbpedia.org/property/placeOfBirth>");
//	KEY_ID name = diplo::KM.Get("<http://dbpedia.org/property/name>");
//
//
//	vector<TripleIDs> constrains;
//	constrains.push_back(TripleIDs(0,-1,tbl,0));
//
//	vector<TripleIDs> projections;
//	projections.push_back(TripleIDs(0,dateOfBirth,0,0));
//	projections.push_back(TripleIDs(0,placeOfBirth,0,0));
//	projections.push_back(TripleIDs(0,name,0,0));
//
//
//	vector<vector<unordered_set<KEY_ID>>> results;
////	vector<vector<unordered_set<KEY_ID>>> prov;
//
//	API::TriplePatern(constrains, projections, results);
//
//	API::DrisplayResults(results);
//
////	API::DrisplayProvenance(prov);
//
//}
////
//void BTCprov::q03() {
//	/*
//	select ?t ?lat ?long
//	where {
//	?a <http://dbpedia.org/property/wikilink> <http://dbpedia.org/resource/List_of_World_Heritage_Sites_in_Europe>.
//	?a <http://dbpedia.org/property/wikilink> <http://dbpedia.org/resource/Middle_Ages> .
//	?a <http://dbpedia.org/property/title> ?t.
//	?a <http://www.w3.org/2003/01/geo/wgs84_pos#lat> ?lat.
//	?a <http://www.w3.org/2003/01/geo/wgs84_pos#long> ?long.
//	 }
//	 */
//
//	KEY_ID List = diplo::KM.Get("<http://dbpedia.org/resource/List_of_World_Heritage_Sites_in_Europe>");
//	KEY_ID Middle_Ages = diplo::KM.Get("<http://dbpedia.org/resource/Middle_Ages>");
//
//	KEY_ID wikilink = diplo::KM.Get("<http://dbpedia.org/property/wikilink>");
//
//	KEY_ID title = diplo::KM.Get("<http://dbpedia.org/property/title>");
//	KEY_ID lat = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#lat>");
//	KEY_ID llong = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#long>");
//
//	vector<TripleIDs> constrains;
//	constrains.push_back(TripleIDs(0, wikilink, List, 0));
//	constrains.push_back(TripleIDs(0, wikilink, Middle_Ages, 0));
//
//	vector<TripleIDs> projections;
//	projections.push_back(TripleIDs(0, title, 0, 0));
//	projections.push_back(TripleIDs(0, lat, 0, 0));
//	projections.push_back(TripleIDs(0, llong, 0, 0));
//
//	vector<vector<unordered_set<KEY_ID>>> results;
////	vector<vector<unordered_set<KEY_ID>>> prov;
//
//	API::TriplePatern(constrains, projections, results);
//
//	API::DrisplayResults(results);
//
////	API::DrisplayProvenance(prov);
//
//}

void BTCprov::q04() {
    /*
    select *
    where {
    ?p <http://dbpedia.org/property/name> "Krebs, Emil".
    ?p <http://dbpedia.org/property/deathPlace> ?l.

    ?c [] ?l.
    ?c <http://www.geonames.org/ontology#featureClass> <http://www.geonames.org/ontology#P>.
    ?c <http://www.geonames.org/ontology#inCountry> <http://www.geonames.org/countries/#DE>.
    ?c <http://www.w3.org/2003/01/geo/wgs84_pos#lat> ?lat.
    ?c <http://www.w3.org/2003/01/geo/wgs84_pos#long> ?long.
    }
     */


    KEY_ID Krebs = diplo::KM.Get("\"Krebs, Emil\"");
    KEY_ID name = diplo::KM.Get("<http://dbpedia.org/property/name>");

    KEY_ID deathPlace = diplo::KM.Get("<http://dbpedia.org/property/deathPlace>");

    KEY_ID featureClass = diplo::KM.Get("<http://www.geonames.org/ontology#featureClass>");
    KEY_ID P = diplo::KM.Get("<http://www.geonames.org/ontology#P>");
    KEY_ID inCountry = diplo::KM.Get("<http://www.geonames.org/ontology#inCountry>");
    KEY_ID DE = diplo::KM.Get("<http://www.geonames.org/countries/#DE>");

    KEY_ID lat = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#lat>");
    KEY_ID llong = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#long>");


    KEY_ID name2 = diplo::KM.Get("<http://www.geonames.org/ontology#name>");


    unordered_multimap<KEY_ID, vector<KEY_ID> > results1;
    unordered_multimap<KEY_ID, vector<KEY_ID> > results2;

    {
        vector<QueryGraph> graph;
        {
            QueryGraph patern;
            patern.subject.first = QF_PROJECTION;
            patern.predicate.second = name;
            patern.object.second = Krebs;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.predicate.second = deathPlace;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }



        cerr << "API::TriplePatern_FromTemplates(graph, results1, 'T');" << endl;
        API::TriplePatern_FromTemplates(graph, results1, 's', 'T');

        cerr << "API::TriplePatern_FromTemplates(graph, results1, '');" << endl;
        API::TriplePatern_FromTemplates(graph, results1, 's', 'n');
        //		API::TriplePatern_FromTemplates(graph, results1, 'o');
//				API::DisplayResults(results1, 2);
        //		unordered_set<unordered_set<KEY_ID>*> result_molecules;
        //		diplo::TM.GetMoleculesForPredicates(graph,result_molecules);
        //		cerr << "API::TriplePatern(graph, results1, 's');" << endl;
        //		API::TriplePatern(graph, results1, 's');
    }

    {
        vector<QueryGraph> graph;
        {
            QueryGraph patern;
            patern.predicate.second = featureClass;
            patern.object.second = P;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.predicate.second = inCountry;
            patern.object.second = DE;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.subject.first = QF_PROJECTION;
            patern.predicate.second = lat;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.predicate.second = llong;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.predicate.second = name2;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }


//		API::TriplePatern(graph, results2, 'o');
//		API::DisplayResults(results2, 4);
//
//		cerr << "API::TriplePatern(graph, results2, 's');" << endl;
//		API::TriplePatern(graph, results2, 's');

        cerr << "API::TriplePatern_FromTemplates(graph, results2, 'T');" << endl;
        API::TriplePatern_FromTemplates(graph, results2, 'o', 'T');

        cerr << "API::TriplePatern_FromTemplates(graph, results2, 'n');" << endl;
        API::TriplePatern_FromTemplates(graph, results2, 'M', 'n');
    }

//	unordered_multimap<KEY_ID, vector<KEY_ID> > results;
//	API::Join(&results1, &results2, &results);
//
//	cout << endl << endl;
//	API::DisplayResults(results, 6);
//	cout << endl << endl;

}

/*
 * I've removed those lines form data source,
 * something what is supposed to be molecule is as a type and this cause an issue
 * <http://dbpedia.org/resource/Barack_Obama> <http://www.w3.org/2000/01/rdf-schema#subClassOf> <http://dbpedia.org/resource/American_politicians> <http://dbpedia.org/resource/American_politicians> .
 * <http://dbpedia.org/resource/Barack_Obama_background_whisper_campaign_and_media_controversy> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://dbpedia.org/resource/Barack_Obama> <http://dbpedia.org/resource/Barack_Obama_background_whisper_campaign_and_media_controversy> .
 *
 */
void BTCprov::q05() {
    /*
     select distinct ?l ?long ?lat
     where {
     ?a [] "Barack Obama".
     ?a <http://dbpedia.org/property/placeOfBirth> ?l.
     ?l <http://www.w3.org/2003/01/geo/wgs84 pos#lat> ?lat.
     ?l <http://www.w3.org/2003/01/geo/wgs84 pos#long> ?long. }
     */

    KEY_ID Obama = diplo::KM.Get("\"Barack Obama\"");

    KEY_ID placeOfBirth = diplo::KM.Get("<http://dbpedia.org/property/placeOfBirth>");

    KEY_ID lat = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#lat>");
    KEY_ID llong = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#long>");

    KEY_ID name2 = diplo::KM.Get("<http://xmlns.com/foaf/0.1/name>");

    unordered_multimap<KEY_ID, vector<KEY_ID> > results1;
    unordered_multimap<KEY_ID, vector<KEY_ID> > results2;

    {
        vector<QueryGraph> graph;
        {
            QueryGraph patern;
//			patern.subject.first = QF_PROJECTION;
            patern.predicate.second = name2;
            patern.object.second = Obama;
            graph.push_back(patern);
        }
        {
            QueryGraph patern;
            patern.predicate.second = placeOfBirth;
            patern.object.first = QF_PROJECTION;
            graph.push_back(patern);
        }

        API::TriplePatern(graph, results2, 's');

//		API::TriplePatern(graph, results1, 'o');
//		API::DisplayResults(results1, 1);
    }

//	for (unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator it = results1.begin(); it != results1.end(); it++) {
//		cout << endl << endl;
//		{
//			vector<QueryGraph> graph;
//			{
//				QueryGraph patern;
//				patern.subject.second = it->first;
//				patern.subject.first = QF_PROJECTION;
//				patern.predicate.second = lat;
//				patern.object.first = QF_PROJECTION;
//				graph.push_back(patern);
//			}
//			{
//				QueryGraph patern;
//				patern.predicate.second = llong;
//				patern.object.first = QF_PROJECTION;
//				graph.push_back(patern);
//			}
//			API::TriplePatern(graph, results2, '0');
//			API::DisplayResults(results2, 3);
//		}
//	}
}


//
void BTCprov::q06() {
    /*
     select distinct ?d
     where {
     ?c <http://dbpedia.org/property/profession> <http://dbpedia.org/resource/Veterinarian> .
     ?b <http://www.geonames.org/ontology#inCountry> <http://www.geonames.org/countries/#US>.

     ?a <http://dbpedia.org/property/senators> ?c.
     ?a <http://www.w3.org/2002/07/owl#sameAs> ?b.

     ?a <http://dbpedia.org/property/name> ?d.


     }
     */

    KEY_ID profession = diplo::KM.Get("<http://dbpedia.org/property/profession>");
    KEY_ID Veterinarian = diplo::KM.Get("<http://dbpedia.org/resource/Veterinarian>");

    KEY_ID inCountry = diplo::KM.Get("<http://www.geonames.org/ontology#inCountry>");
    KEY_ID US = diplo::KM.Get("<http://www.geonames.org/countries/#US>");

    KEY_ID senators = diplo::KM.Get("<http://dbpedia.org/property/senators>");
    KEY_ID sameAs = diplo::KM.Get("<http://www.w3.org/2002/07/owl#sameAs>");
    KEY_ID name = diplo::KM.Get("<http://dbpedia.org/property/name>");

    unordered_multimap<KEY_ID, vector<KEY_ID> > results1;
    unordered_multimap<KEY_ID, vector<KEY_ID> > results2;
    unordered_multimap<KEY_ID, vector<KEY_ID> > results3;

    {
        vector<QueryGraph> graph;
        {
            QueryGraph patern;
            patern.subject.first = QF_PROJECTION;
            patern.predicate.second = profession;
            patern.object.second = Veterinarian;
            graph.push_back(patern);
        }
        API::TriplePatern(graph, results1, 's');
        API::DisplayResults(results1, 1);
    }


    cerr << endl << endl;
    {
        vector<QueryGraph> graph;
        {
            QueryGraph patern;
            patern.subject.first = QF_PROJECTION;
            patern.predicate.second = inCountry;
            patern.object.second = US;
            graph.push_back(patern);
        }
        API::TriplePatern(graph, results2, 's');
        API::DisplayResults(results2, 1);
    }

    cerr << endl << endl;
    for (unordered_multimap<KEY_ID, vector<KEY_ID> >::iterator it = results2.begin(); it != results2.end(); it++) {
        {
            vector<QueryGraph> graph;
            {
                QueryGraph patern;
                patern.predicate.second = sameAs;
                patern.object.second = it->first;
                graph.push_back(patern);
            }
            {
                QueryGraph patern;
                patern.predicate.second = name;
                patern.object.first = QF_PROJECTION;
                graph.push_back(patern);
            }
            {
                QueryGraph patern;
                patern.predicate.second = senators;
                patern.object.first = QF_PROJECTION;
                graph.push_back(patern);
            }

            API::TriplePatern(graph, results3, 'o');
        }
    }

    API::DisplayResults(results3, 2);

    cout << endl << endl;
    unordered_multimap<KEY_ID, vector<KEY_ID> > results;
    API::Join(&results1, &results3, &results);

    cout << endl << endl;
    API::DisplayResults(results, 2);
    cout << endl << endl;
}
//
///*
// * added
// <http://dbpedia.org/resource/Diane_Cilento> <http://dbpedia.org/property/placeOfBirth> <http://dbpedia.org/resource/Scotland> <http://mwylot.net> .
// <http://dbpedia.org/resource/Hilton_McRae> <http://dbpedia.org/property/placeOfBirth> <http://dbpedia.org/resource/Scotland> <http://mwylot.net> .
// *
// */
//void BTCprov::q07() {
//	/*
//	 Q7:
//	 select distinct ?a ?b ?lat ?long
//	 where {
//
//	 ?a <http://dbpedia.org/property/wikilink> <http://dbpedia.org/resource/actor>.
//	 ?a <http://dbpedia.org/property/spouse> ?b.
//	 ?a <http://dbpedia.org/property/placeOfBirth> ?c.
//	 ?b <http://dbpedia.org/property/placeOfBirth> ?c.
//	 ?b <http://dbpedia.org/property/wikilink> dbpediares:actor.
//
//	 ?c <http://www.w3.org/2002/07/owl#sameAs> ?c2.
//
//	 ?c2 <http://www.w3.org/2003/01/geo/wgs84 pos#lat> ?lat.
//	 ?c2 <http://www.w3.org/2003/01/geo/wgs84 pos#long> ?long. }
//	 */
//
//	KEY_ID actor = diplo::KM.Get("<http://dbpedia.org/resource/actor>");
//	KEY_ID spouse = diplo::KM.Get("<http://dbpedia.org/property/spouse>");
//	KEY_ID placeOfBirth = diplo::KM.Get("<http://dbpedia.org/property/placeOfBirth>");
//	KEY_ID wikilink = diplo::KM.Get("<http://dbpedia.org/property/wikilink>");
//	KEY_ID sameAs = diplo::KM.Get("<http://www.w3.org/2002/07/owl#sameAs>");
//	KEY_ID lat = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#lat>");
//	KEY_ID llong = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#long>");
//
//	unordered_multimap<KEY_ID, pair<KEY_ID,KEY_ID> > place_spouses;
//
////	vector<vector<vector<unordered_set<KEY_ID> > > > prov_all;
//
//	{
////		vector<vector<unordered_set<KEY_ID> > > prov;
//		set<pair<const KEY_ID, Molecule>*>* Molecules_with_O = diplo::M.GetMoleculesFromInvertedIdx(actor);
//
//		for (set<pair<const KEY_ID, Molecule>*>::iterator it = Molecules_with_O->begin(); it != Molecules_with_O->end(); it++) {
//			unordered_set<size_t> tripleTemplates;
//			unordered_set<KEY_ID> results_spouse;
//			unordered_set<KEY_ID> results_placeOfBirth;
////			unordered_set<KEY_ID> prov_A1;
//
//			tripleTemplates.clear();
//			diplo::TM.GetTemplates(diplo::KM.GetType((*it)->first), wikilink, diplo::KM.GetType(actor), 0, &tripleTemplates);
//
//			if ((*it)->second.CheckIfEntityExists(&tripleTemplates, actor, 0)) { // FIXME get prov
//
////				unordered_set<KEY_ID> prov_spouse;
//				tripleTemplates.clear();
//				diplo::TM.GetTemplates(diplo::KM.GetType((*it)->first), spouse, -1, 0, &tripleTemplates);
//				(*it)->second.GetEntity(&tripleTemplates, 0, 0, &results_spouse);  // FIXME get prov
//
//				for (unordered_set<KEY_ID>::iterator it_spouse = results_spouse.begin(); it_spouse != results_spouse.end(); it_spouse++) {
//					Molecule *m = diplo::M.Get(*it_spouse);
//					if (m) {
//
////						unordered_set<KEY_ID> prov_A2;
//						tripleTemplates.clear();
//						diplo::TM.GetTemplates(diplo::KM.GetType(*it_spouse), wikilink, diplo::KM.GetType(actor), 0, &tripleTemplates);
//						if (m->CheckIfEntityExists(&tripleTemplates, actor, 0)) {
//
////							unordered_set<KEY_ID> prov_placeOfBirth;
//							tripleTemplates.clear();
//							diplo::TM.GetTemplates(diplo::KM.GetType((*it)->first), placeOfBirth, -1, 0, &tripleTemplates);
//							(*it)->second.GetEntity(&tripleTemplates, 0, 0, &results_placeOfBirth);  // FIXME get prov
//
//							for (unordered_set<KEY_ID>::iterator it_results_placeOfBirth = results_placeOfBirth.begin(); it_results_placeOfBirth != results_placeOfBirth.end();
//									it_results_placeOfBirth++) {
//
////								unordered_set<KEY_ID> prov_placeOfBirth2;
//								tripleTemplates.clear();
//								diplo::TM.GetTemplates(diplo::KM.GetType(*it_spouse), placeOfBirth, diplo::KM.GetType(*it_results_placeOfBirth), 0, &tripleTemplates);
//								if (m->CheckIfEntityExists(&tripleTemplates, *it_results_placeOfBirth, 0)) {
////									vector<unordered_set<KEY_ID> > provl;
//									pair<KEY_ID, KEY_ID> spouses((*it)->first, *it_spouse);
//									place_spouses.insert(pair<KEY_ID, pair<KEY_ID, KEY_ID> >(*it_results_placeOfBirth, spouses));
////									provl.push_back(prov_A1);
////									provl.push_back(prov_spouse);
////									provl.push_back(prov_A2);
////									provl.push_back(prov_placeOfBirth);
////									provl.push_back(prov_placeOfBirth2);
////									prov.push_back(provl);
//
////							cout << "\t" << diplo::KM.Get((*it)->first) <<  "\t" << diplo::KM.Get(*it_spouse) <<  "\t" << diplo::KM.Get(*it_results_placeOfBirth) << endl;
//								}
//							}
//						}
//					}
//				}
//			}
//		}
////		prov_all.push_back(prov);
//	}
//
//
//
//	{
//		vector<vector<unordered_set<KEY_ID> > > prov;
//		for (unordered_multimap<KEY_ID, pair<KEY_ID, KEY_ID> >::iterator it = place_spouses.begin(); it != place_spouses.end(); it++) {
////			cerr << "\t" << diplo::KM.Get( it->first ) << endl;
////
//			unordered_set<KEY_ID> results_sameAs;
////			unordered_set<KEY_ID> prov_sameAs;
//			API::GetObjects(it->first, sameAs, results_sameAs);
//
//			for (unordered_set<KEY_ID>::iterator it2 = results_sameAs.begin(); it2 != results_sameAs.end(); it2++) {
////			cerr << "\t" << diplo::KM.Get( *it2 ) << endl;
////		}
//				vector<vector<unordered_set<KEY_ID>>> results_geo;
////				vector<vector<unordered_set<KEY_ID>>> provmaster_geo;
//				vector<TripleIDs> constrains;
//				vector<TripleIDs> projections;
//				projections.push_back(TripleIDs(*it2, lat, 0, 0));
//				projections.push_back(TripleIDs(*it2, llong, 0, 0));
//				API::TriplePatern(constrains, projections, results_geo);
//
//				if ( !results_geo.empty() ) {
//					vector<unordered_set<KEY_ID> > provl;
////					provmaster_geo[0].push_back(prov_sameAs);
////					prov.push_back(provmaster_geo[0]);
//
//					cout << diplo::KM.Get( it->first ) << "\t" << diplo::KM.Get(it->second.first) << "\t" << diplo::KM.Get(it->second.first) << endl;
//					API::DrisplayResults(results_geo);
//				}
//			}
//		}
////		prov_all.push_back(prov);
//	}
//
//////	API::DrisplayProvenance(prov);
////	for (vector<vector<vector<unordered_set<KEY_ID>>> >::iterator it_p1 = prov_all.begin(); it_p1 != prov_all.end(); it_p1++) {
////		cout << "{";
////		API::DrisplayProvenance(*it_p1);
////		cout << "} X ";
////	}
////	cout << endl;
//
//}
//
//void BTCprov::q08() {
//	/*
//	 select ?a ?y
//	 where {
//
// 	 ?b <http://purl.org/dc/elements/1.1/subject> "Blackwater".
//	 ?b [] ?n.
//
//	 ?a a <http://dbpedia.org/class/yago/Politician110451263>.
//
//	 ?a <http://xmlns.com/foaf/0.1/name> ?n.
//	 ?a <http://dbpedia.org/property/years> ?y.
//
//
//	  }
//	 */
//
//	vector<vector<unordered_set<KEY_ID>>> resultsBlackwater;
////	vector<vector<unordered_set<KEY_ID>>> provBlackwater;
//
//	vector<vector<vector<unordered_set<KEY_ID>>>> results;
////	vector<vector<vector<unordered_set<KEY_ID>>>> prov;
//
//	KEY_ID subject = diplo::KM.Get("<http://purl.org/dc/elements/1.1/subject>");
//	KEY_ID Blackwater = diplo::KM.Get("\"Blackwater\"");
//
//	{
//		vector<TripleIDs> constrains;
//		constrains.push_back(TripleIDs(0, subject, Blackwater, 0));
//
//		vector<TripleIDs> projections;
//		projections.push_back(TripleIDs(0, -1, 0, 0));
//
//		API::TriplePatern(constrains, projections, resultsBlackwater);
//	}
////	API::DrisplayResults(resultsBlackwater);
////	API::DrisplayProvenance(provBlackwater);
//
//
//	TYPE_ID Politician110451263_type_sq = diplo::KM.GetSeq(diplo::KM.Get("<http://dbpedia.org/class/yago/Politician110451263>"));
//	Politician110451263_type_sq = diplo::KM.GetType(diplo::KM.Get("<http://dbpedia.org/resource/Paul_Boateng>")); //very nasty hack!!
//
//	map<KEY_ID, class Node *> * molecules = diplo::KM.GetElementsOfType(Politician110451263_type_sq);
//
//	KEY_ID years = diplo::KM.Get("<http://dbpedia.org/property/years>");
//	KEY_ID name = diplo::KM.Get("<http://xmlns.com/foaf/0.1/name>");
//
////	cerr << "years " << years << "\t" <<  "name " << name << "\t" << xx << endl;
//
//	for (map<KEY_ID, class Node *>::iterator it = molecules->begin(); it != molecules->end(); it++) {
//		for (size_t it_p = 0; it_p < resultsBlackwater.size(); it_p++) {
//			for (size_t it1 = 0; it1 < resultsBlackwater[it_p].size(); it1++) {
//				for (unordered_set<KEY_ID>::iterator it2 = resultsBlackwater[it_p][it1].begin(); it2 != resultsBlackwater[it_p][it1].end(); it2++) {
//
//					vector<vector<unordered_set<KEY_ID>>> results_local;
////					vector<vector<unordered_set<KEY_ID>>> prov_local;
//
//
//
//					vector<TripleIDs> constrains;
//					constrains.push_back(TripleIDs(it->first, name, *it2, 0));
//
//					vector<TripleIDs> projections;
//					projections.push_back(TripleIDs(0, years, 0, 0));
//
//					API::TriplePatern(constrains, projections, results_local);
//
//					if (!results_local.empty()) {
//	//					cerr << endl << endl << diplo::KM.Get(it->first) << endl;
////						prov.push_back(provBlackwater);
////						prov.push_back(prov_local);
//						API::DrisplayResults(results_local);
//					}
//				}
//			}
//		}
//	}
//
////	for (vector<vector<vector<unordered_set<KEY_ID>>> > ::iterator it_p1 = prov.begin(); it_p1 != prov.end(); it_p1++) {
////		cout << "{";
////		API::DrisplayProvenance(*it_p1);
////		cout << "} X ";
////	}
////	cout << endl;
//
//}
//
//void BTCprov::q09() {
//	/*
//	 * SELECT DISTINCT ?s WHERE {
//	 * { ?s <http://xmlns.com/foaf/0.1/name> "Samuel" . } UNION
//	 * { ?s <http://xmlns.com/foaf/0.1/name> "Elisabeth" . }}
//	 */
//
//	KEY_ID Samuel = diplo::KM.Get("\"Samuel\"");
//	KEY_ID Elisabeth = diplo::KM.Get("\"Elisabeth\"");
//
//	KEY_ID name = diplo::KM.Get("<http://xmlns.com/foaf/0.1/name>");
////
////	unordered_multimap<KEY_ID, diplo::TripleIDs> results_S;
////	unordered_multimap<KEY_ID, diplo::TripleIDs> results_E;
//
//	vector<vector<unordered_set<KEY_ID>>> results;
////	vector<vector<unordered_set<KEY_ID>>> prov;
//
//	results.resize(2);
//	results[0].resize(1);
//	results[1].resize(1);
//
////	prov.resize(2);
//
//	API::GetSubjects(Samuel, name, results[0][0]);
//	API::GetSubjects(Elisabeth, name, results[1][0]);
//
//	API::DrisplayResults(results);
//
////	API::DrisplayProvenance(prov);
//
//}
//
//void BTCprov::q10() {
//	/*
//	 select ?t ?lat ?long
//	 where {
//	 ?a <http://dbpedia.org/property/wikilink> <http://dbpedia.org/resource/List_of_World_Heritage_Sites_in_Europe>.
//	 OPTTIONAL { ?a <http://dbpedia.org/property/wikilink> <http://dbpedia.org/resource/Middle_Ages> } .
//	 ?a <http://dbpedia.org/property/title> ?t.
//	 ?a <http://www.w3.org/2003/01/geo/wgs84_pos#lat> ?lat.
//	 ?a <http://www.w3.org/2003/01/geo/wgs84_pos#long> ?long.
//	 }
//	 */
//
//	KEY_ID List = diplo::KM.Get("<http://dbpedia.org/resource/List_of_World_Heritage_Sites_in_Europe>");
//	KEY_ID Middle_Ages = diplo::KM.Get("<http://dbpedia.org/resource/Middle_Ages>");
//
//	KEY_ID wikilink = diplo::KM.Get("<http://dbpedia.org/property/wikilink>");
//
//	KEY_ID title = diplo::KM.Get("<http://dbpedia.org/property/title>");
//	KEY_ID lat = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#lat>");
//	KEY_ID llong = diplo::KM.Get("<http://www.w3.org/2003/01/geo/wgs84_pos#long>");
//
//	vector<TripleIDs> constrains;
//	constrains.push_back(TripleIDs(0, wikilink, List, 0));
//	constrains.push_back(TripleIDs(0, wikilink, Middle_Ages, 1));
//
//	vector<TripleIDs> projections;
//	projections.push_back(TripleIDs(0, title, 0, 0));
//	projections.push_back(TripleIDs(0, lat, 0, 0));
//	projections.push_back(TripleIDs(0, llong, 0, 0));
//
//	vector<vector<unordered_set<KEY_ID>>> results;
//	vector<vector<unordered_set<KEY_ID>>> prov;
//
//	API::TriplePatern(constrains, projections, results);
//
//	API::DrisplayResults(results);
//
////	API::DrisplayProvenance(prov);
//}

void BTCprov::runthemall() {
//	cout << "---------------------q01---------------------" << endl;
//	q01();
//	cout << "---------------------q02---------------------" << endl;
//	q02();
//	cout << "---------------------q03---------------------" << endl;
//	q03();
//	cout << "---------------------q04---------------------" << endl;
//	q04();
//	cout << "---------------------q05---------------------" << endl;
//	q05();
//	cout << "---------------------q06---------------------" << endl;
//	q06();
//	cout << "---------------------q07---------------------" << endl;
//	q07();
//	cout << "---------------------q08---------------------" << endl;
//	q08();
//	cout << "---------------------q09---------------------" << endl;
//	q09();
//	cout << "---------------------q10---------------------" << endl;
//	q10();
}

void BTCprov::benchmark() {
//	vector<vector<double> > times4exel;
//	times4exel.resize(10);
//	double time;
//	for (int i = 0; i < 6; i++) {
//		cout << "--------------------- ROUND: " << i << "---------------------" << endl;
//		diplo::stopwatch_start();
//		q01();
//		time = diplo::stopwatch_get();
//		times4exel[0].push_back(time);
//		cout << "q01: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q02();
//		time = diplo::stopwatch_get();
//		times4exel[1].push_back(time);
//		cout << "q02: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q03();
//		time = diplo::stopwatch_get();
//		times4exel[2].push_back(time);
//		cout << "q03: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q04();
//		time = diplo::stopwatch_get();
//		times4exel[3].push_back(time);
//		cout << "q04: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q05();
//		time = diplo::stopwatch_get();
//		times4exel[4].push_back(time);
//		cout << "q05: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q06();
//		time = diplo::stopwatch_get();
//		times4exel[5].push_back(time);
//		cout << "q06: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q07();
//		time = diplo::stopwatch_get();
//		times4exel[6].push_back(time);
//		cout << "q07: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q08();
//		time = diplo::stopwatch_get();
//		times4exel[7].push_back(time);
//		cout << "q08: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q09();
//		time = diplo::stopwatch_get();
//		times4exel[8].push_back(time);
//		cout << "q09: " << time << endl;
//		sleep(diplo::pause_int);
//
//		diplo::stopwatch_start();
//		q10();
//		time = diplo::stopwatch_get();
//		times4exel[9].push_back(time);
//		cout << "q10: " << time << endl;
//		sleep(diplo::pause_int);
//	}
//
//
//	/////printing for exel
//	{
//		cout << endl << endl;
//		for (vector<vector<double> >::iterator q = times4exel.begin();
//				q != times4exel.end(); q++) {
//			for (size_t r = 0; r < q->size(); r++) {
//				string n = to_string((*q)[r]);
//	//			std::replace(n.begin(), n.end(), '.', ',');
//				cout << n << "\t";
//			}
//			cout << endl;
//		}
//	}
}

} /* namespace queries */
