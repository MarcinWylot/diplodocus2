/*
 * WDCqueries.cpp
 *
 *  Created on: Sep 26, 2013
 *      Author: marcin
 */

#include "WDCqueries.h"

namespace queries {

WDCqueries::WDCqueries() {
    // TODO Auto-generated constructor stub

}

WDCqueries::~WDCqueries() {
    // TODO Auto-generated destructor stub
}

void WDCqueries::q01() {
    /*
     }
     select ?a ?title ?desc
    where {
    ?a ?j "http://www.fortis-angelo-srl.com".
    ?a <http://opengraphprotocol.org/schema/site_name> "PagineBianche" .
    ?a <http://opengraphprotocol.org/schema/title> ?title.
    ?a <http://opengraphprotocol.org/schema/description> ?desc. }

     */
    KEY_ID fortis_angelo = diplo::KM.Get("\"http://www.fortis-angelo-srl.com\"");

    KEY_ID site_name = diplo::KM.Get(
                           "<http://opengraphprotocol.org/schema/site_name>");
    KEY_ID PagineBianche = diplo::KM.Get("\"PagineBianche\"");

    KEY_ID title = diplo::KM.Get("<http://opengraphprotocol.org/schema/title>");
    KEY_ID description = diplo::KM.Get(
                             "<http://opengraphprotocol.org/schema/description>");

    vector < TripleIDs > constrains;
    constrains.push_back(TripleIDs(0, -1, fortis_angelo, 0));
    constrains.push_back(TripleIDs(0, site_name, PagineBianche, 0));

    vector < TripleIDs > projections;
    projections.push_back(TripleIDs(0, title, 0, 0));
    projections.push_back(TripleIDs(0, description, 0, 0));

    vector < vector < unordered_set<KEY_ID> >> results;
//	vector < vector < unordered_set<KEY_ID> >> prov;

    API::TriplePatern(constrains, projections, results);

    API::DrisplayResults (results);

//	API::DrisplayProvenance (prov);

}

void WDCqueries::q02() {
    /*
    select ?b ?p ?bn
    where {
    ?a ?j "http://fortyagency.com/35-under-35" .
    ?a <http://ogp.me/ns#image> ?b .
    ?a <http://ogp.me/ns#description> ?p .
    ?a <http://ogp.me/ns#title> ?bn.

    	 */

    KEY_ID fortyagency = diplo::KM.Get("\"http://fortyagency.com/35-under-35\"");

    KEY_ID image = diplo::KM.Get(
                       "<http://ogp.me/ns#image>");
    KEY_ID description = diplo::KM.Get(
                             "<http://ogp.me/ns#description>");
    KEY_ID title = diplo::KM.Get("<http://ogp.me/ns#title>");

    vector<TripleIDs> constrains;
    constrains.push_back(TripleIDs(0, -1, fortyagency, 0));

    vector<TripleIDs> projections;
    projections.push_back(TripleIDs(0, image, 0, 0));
    projections.push_back(TripleIDs(0, description, 0, 0));
    projections.push_back(TripleIDs(0, title, 0, 0));

    vector<vector<unordered_set<KEY_ID>>> results;
//	vector<vector<unordered_set<KEY_ID>>> prov;

    API::TriplePatern(constrains, projections, results);

    API::DrisplayResults(results);

//	API::DrisplayProvenance(prov);
}

void WDCqueries::q03() {
    /*
     * select ?t ?lat ?long
    where  {
    ?a <http://opengraphprotocol.org/schema/country-name> "United States" .
    ?a <http://opengraphprotocol.org/schema/region> "Maine" .
    ?a <http://opengraphprotocol.org/schema/title> ?t .
    ?a <http://opengraphprotocol.org/schema/latitude> ?lat.
    ?a <http://opengraphprotocol.org/schema/longitude> ?long.
    }
     *
     */

    KEY_ID country_name = diplo::KM.Get("<http://opengraphprotocol.org/schema/country-name>");
    KEY_ID UnitedStates = diplo::KM.Get("\"United States\"");

    KEY_ID region = diplo::KM.Get("<http://opengraphprotocol.org/schema/region>");
    KEY_ID Maine = diplo::KM.Get("\"Maine\"");


    KEY_ID title = diplo::KM.Get("<http://opengraphprotocol.org/schema/title>");
    KEY_ID lat = diplo::KM.Get("<http://opengraphprotocol.org/schema/latitude>");
    KEY_ID llong = diplo::KM.Get("<http://opengraphprotocol.org/schema/longitude>");

    vector<TripleIDs> constrains;
    constrains.push_back(TripleIDs(0, region, Maine, 0));
    constrains.push_back(TripleIDs(0, country_name, UnitedStates, 0));

    vector<TripleIDs> projections;
    projections.push_back(TripleIDs(0, title, 0, 0));
    projections.push_back(TripleIDs(0, lat, 0, 0));
    projections.push_back(TripleIDs(0, llong, 0, 0));

    vector<vector<unordered_set<KEY_ID>>> results;
//	vector<vector<unordered_set<KEY_ID>>> prov;

    API::TriplePatern(constrains, projections, results);

    API::DrisplayResults(results);

//	API::DrisplayProvenance(prov);

}

void WDCqueries::q04() {
    /*
    select ?c ?l ?page ?desc
    where {
    ?p <http://xmlns.com/foaf/0.1/page> <http://www.france-artifices.com/lot-de-12-lampions-tricolores-16-cm,fr,4,L12LT16.cfm> .
    ?p <http://purl.org/goodrelations/v1#hasBusinessFunction> ?l  .
    ?c ?j ?l.
    ?c <http://purl.org/goodrelations/v1#hasStockKeepingUnit>       "DUB073"^^<http://www.w3.org/2001/XMLSchema#string> .
    ?c <http://purl.org/goodrelations/v1#description> ?desc .
    ?c <http://xmlns.com/foaf/0.1/page> ?page
    }
    */

    vector<vector<vector<unordered_set<KEY_ID>>>> results;
    vector<vector<vector<unordered_set<KEY_ID>>>> prov;

    KEY_ID france_artifices = diplo::KM.Get("<http://www.france-artifices.com/lot-de-12-lampions-tricolores-16-cm,fr,4,L12LT16.cfm>");
    KEY_ID page = diplo::KM.Get("<http://xmlns.com/foaf/0.1/page>");

    KEY_ID hasBusinessFunction = diplo::KM.Get("<http://purl.org/goodrelations/v1#hasBusinessFunction>");

    KEY_ID hasStockKeepingUnit = diplo::KM.Get("<http://purl.org/goodrelations/v1#hasStockKeepingUnit>");
    KEY_ID Unit = diplo::KM.Get("\"DUB073\"^^<http://www.w3.org/2001/XMLSchema#string>");

    KEY_ID description = diplo::KM.Get("<http://purl.org/goodrelations/v1#description>");

    {
        vector<TripleIDs> constrains;
        constrains.push_back(TripleIDs(0, page, france_artifices, 0));

        vector<TripleIDs> projections;
        projections.push_back(TripleIDs(0, hasBusinessFunction, 0, 0));

        vector<vector<unordered_set<KEY_ID>>> results_local;
//		vector<vector<unordered_set<KEY_ID>>> prov_local;

        API::TriplePatern(constrains, projections, results_local);
        results.push_back(results_local);
//		prov.push_back(prov_local);
    }

    {
        vector<TripleIDs> constrains;
        for (vector<vector<vector<unordered_set<KEY_ID>>>> ::iterator it_p1 = results.begin(); it_p1 != results.end(); it_p1++) {
            for (vector<vector<unordered_set<KEY_ID>>> ::iterator it_p = it_p1->begin(); it_p != it_p1->end(); it_p++) {
                for (vector<unordered_set<KEY_ID>>::iterator it1 = it_p->begin(); it1 != it_p->end(); it1++) {
                    for (unordered_set<KEY_ID>::iterator it2 = it1->begin(); it2 != it1->end(); it2++) {
                        constrains.push_back(TripleIDs(0, -1, *it2, 0));
                    }
                }
            }
        }

        constrains.push_back(TripleIDs(0, hasStockKeepingUnit, Unit, 0));

        vector<TripleIDs> projections;
        projections.push_back(TripleIDs(0, description, 0, 0));
        projections.push_back(TripleIDs(0, page, 0, 0));

        vector<vector<unordered_set<KEY_ID>>> results_local;
//		vector<vector<unordered_set<KEY_ID>>> prov_local;

        API::TriplePatern(constrains, projections, results_local);
        results.push_back(results_local);
//		prov.push_back(prov_local);

    }

    for (vector<vector<vector<unordered_set<KEY_ID>>>> ::iterator it_p1 = results.begin(); it_p1 != results.end(); it_p1++) {
        API::DrisplayResults(*it_p1);
    }

//	for (vector<vector<vector<unordered_set<KEY_ID>>>> ::iterator it_p1 = prov.begin(); it_p1 != prov.end(); it_p1++) {
//		cout << "{";
//		API::DrisplayProvenance(*it_p1);
//		cout << "} X ";
//	}
//	cout << endl;


}

void WDCqueries::q05() {
    /*
     * select distinct ?d
    where {
    ?c <http://rdfs.org/sioc/ns#has_container>      <http://www.foundationdrupal7.com/forums/announcements> .
    ?b <http://xmlns.com/foaf/0.1/name> "Anonymous"@EN

    ?a <http://rdfs.org/sioc/ns#reply_of>  ?c .
    ?a <http://rdfs.org/sioc/ns#has_creator> ?b .

    ?a <http://purl.org/dc/terms/date> ?d .


    }
     *
     */

    KEY_ID has_container = diplo::KM.Get("<http://rdfs.org/sioc/ns#has_container>");
    KEY_ID announcements = diplo::KM.Get("<http://www.foundationdrupal7.com/forums/announcements>");

    KEY_ID name = diplo::KM.Get("<http://xmlns.com/foaf/0.1/name>");
    KEY_ID Anonymous = diplo::KM.Get("\"Anonymous\"@en");

    KEY_ID reply_of = diplo::KM.Get("<http://rdfs.org/sioc/ns#reply_of>");
    KEY_ID has_creator = diplo::KM.Get("<http://rdfs.org/sioc/ns#has_creator>");
    KEY_ID date = diplo::KM.Get("<http://purl.org/dc/terms/date>");

    unordered_set<KEY_ID> results_ANN;
    unordered_set<KEY_ID> results_ANO;

    API::GetSubjects(announcements, has_container, results_ANN);
    API::GetSubjects(Anonymous, name, results_ANO);


    vector<vector<vector<unordered_set<KEY_ID>>> > results;
//	vector<vector<vector<unordered_set<KEY_ID>>> > prov;

    vector<diplo::TripleIDs> projections;
    projections.push_back(TripleIDs(0, date, 0, 0));

    unordered_set<KEY_ID> pr;


    for (unordered_set<KEY_ID>::iterator it = results_ANO.begin();
            it != results_ANO.end(); it++) {
        pr.clear();
//		cerr << "1" << endl;
        KEY_ID varANO = *it;
//		do {
//			pr.insert(it->second);
//			it++;
//		} while (it != results_ANO.end() and varANO == it->first);
//		vector<vector<unordered_set<KEY_ID>>> prov_localANO( {vector<unordered_set<KEY_ID>>( {pr})});
//		cerr << "2" << endl;
        for (unordered_set<KEY_ID>::iterator it2 = results_ANN.begin(); it2 != results_ANN.end(); it2++) {
            pr.clear();
//			cerr << "3" << endl;
            KEY_ID varANN = *it2;
//			do {
//				pr.insert(it2->second);
//				it2++;
//			} while (it2 != results_ANN.end() and varANN == it2->first);
//			cerr << "4" << endl;
//			vector<vector<unordered_set<KEY_ID>>> prov_localANN( {vector<unordered_set<KEY_ID>>( {pr})});

            vector<TripleIDs> constrains;
            constrains.push_back(TripleIDs(0, reply_of, varANN, 0));
            constrains.push_back(TripleIDs(0, has_creator, varANO, 0));
            vector<vector<unordered_set<KEY_ID>>> results_local;
//			vector<vector<unordered_set<KEY_ID>>> prov_local;

            API::TriplePatern(constrains, projections, results_local);

//			cerr << "varANN: " << diplo::KM.Get(varANN) << "\tvarANO: " << diplo::KM.Get(varANO) << "\tprov_local.size(): " << prov_local.size()
//					<<  "\tresults_local.size(): " <<results_local.size() << endl;

            if (results_local.size() > 0) {
//				prov.push_back(prov_localANO);
//				prov.push_back(prov_localANN);
//				prov.push_back(prov_local);
                results.push_back(results_local);
            }

        }
    }

    for (vector<vector<vector<unordered_set<KEY_ID>>> > ::iterator it_p1 = results.begin(); it_p1 != results.end(); it_p1++) {
        API::DrisplayResults(*it_p1);
    }

//	for (vector<vector<vector<unordered_set<KEY_ID>>> > ::iterator it_p1 = prov.begin(); it_p1 != prov.end(); it_p1++) {
//		cout << "{";
//		API::DrisplayProvenance(*it_p1);
//		cout << "} X ";
//	}
//	cout << endl;
}

void WDCqueries::q06() {
    /*
    	 * SELECT DISTINCT ?s WHERE {
    { ?s  <http://ogp.me/ns#site_name> "fosiki" . } UNION
    { ?s <http://ogp.me/ns#site_name> "Fotogard" . }}

    	 */
    KEY_ID Fotolog = diplo::KM.Get("\"fosiki\"");
    KEY_ID Fotogard = diplo::KM.Get("\"Fotogard\"");

    KEY_ID name = diplo::KM.Get("<http://ogp.me/ns#site_name>");


    vector<vector<unordered_set<KEY_ID>>> results;
//	vector<vector<unordered_set<KEY_ID>>> prov;

    results.resize(2);
    results[0].resize(1);
    results[1].resize(1);

//	prov.resize(2);
    API::GetSubjects(Fotolog, name, results[0][0]);
    API::GetSubjects(Fotogard, name, results[1][0]);

    API::DrisplayResults(results);

//	API::DrisplayProvenance(prov);
}

void WDCqueries::q07() {
    /*
     * select ?t ?lat ?long
     where  {
     ?a <http://opengraphprotocol.org/schema/region> "Maine"  .
     OPTTIONAL { ?a <http://opengraphprotocol.org/schema/country-name> "United States" } .
     ?a <http://opengraphprotocol.org/schema/title> ?t .
     ?a <http://opengraphprotocol.org/schema/latitude> ?lat.
     ?a <http://opengraphprotocol.org/schema/longitude> ?long.
     }
     *
     */

    KEY_ID country_name = diplo::KM.Get(
                              "<http://opengraphprotocol.org/schema/country-name>");
    KEY_ID UnitedStates = diplo::KM.Get("\"United States\"");

    KEY_ID region = diplo::KM.Get(
                        "<http://opengraphprotocol.org/schema/region>");
    KEY_ID Maine = diplo::KM.Get("\"Maine\"");

    KEY_ID title = diplo::KM.Get("<http://opengraphprotocol.org/schema/title>");
    KEY_ID lat = diplo::KM.Get(
                     "<http://opengraphprotocol.org/schema/latitude>");
    KEY_ID llong = diplo::KM.Get(
                       "<http://opengraphprotocol.org/schema/longitude>");

    vector<TripleIDs> constrains;
    constrains.push_back(TripleIDs(0, region, Maine, 0));
    constrains.push_back(TripleIDs(0, country_name, UnitedStates, 1));

    vector<TripleIDs> projections;
    projections.push_back(TripleIDs(0, title, 0, 0));
    projections.push_back(TripleIDs(0, lat, 0, 0));
    projections.push_back(TripleIDs(0, llong, 0, 0));

    vector<vector<unordered_set<KEY_ID>>> results;
//	vector<vector<unordered_set<KEY_ID>>> prov;

    API::TriplePatern(constrains, projections, results);

    API::DrisplayResults(results);

//	API::DrisplayProvenance(prov);
}

void WDCqueries::runthemall() {
    cout << "---------------------q01---------------------" << endl;
    q01();
    cout << "---------------------q02---------------------" << endl;
    q02();
    cout << "---------------------q03---------------------" << endl;
    q03();
    cout << "---------------------q04---------------------" << endl;
    q04();
    cout << "---------------------q05---------------------" << endl;
    q05();
    cout << "---------------------q06---------------------" << endl;
    q06();
    cout << "---------------------q07---------------------" << endl;
    q07();
}

void WDCqueries::benchmark() {
    vector<vector<double> > times4exel;
    times4exel.resize(7);
    double time;
    for (int i = 0; i < 6; i++) {
        cout << "--------------------- ROUND: " << i << "---------------------"
             << endl;
        diplo::stopwatch_start();
        q01();
        time = diplo::stopwatch_get();
        times4exel[0].push_back(time);
        cout << "q01: " << time << endl;
        sleep(diplo::pause_int);

        diplo::stopwatch_start();
        q02();
        time = diplo::stopwatch_get();
        times4exel[1].push_back(time);
        cout << "q02: " << time << endl;
        sleep(diplo::pause_int);

        diplo::stopwatch_start();
        q03();
        time = diplo::stopwatch_get();
        times4exel[2].push_back(time);
        cout << "q03: " << time << endl;
        sleep(diplo::pause_int);

        diplo::stopwatch_start();
        q04();
        time = diplo::stopwatch_get();
        times4exel[3].push_back(time);
        cout << "q04: " << time << endl;
        sleep(diplo::pause_int);

        diplo::stopwatch_start();
        q05();
        time = diplo::stopwatch_get();
        times4exel[4].push_back(time);
        cout << "q05: " << time << endl;
        sleep(diplo::pause_int);

        diplo::stopwatch_start();
        q06();
        time = diplo::stopwatch_get();
        times4exel[5].push_back(time);
        cout << "q06: " << time << endl;
        sleep(diplo::pause_int);

        diplo::stopwatch_start();
        q07();
        time = diplo::stopwatch_get();
        times4exel[6].push_back(time);
        cout << "q07: " << time << endl;
        sleep(diplo::pause_int);
    }

    /////printing for exel
    {
        cout << endl << endl;
        for (vector<vector<double> >::iterator q = times4exel.begin();
                q != times4exel.end(); q++) {
            for (size_t r = 0; r < q->size(); r++) {
                string n = to_string((*q)[r]);
                //			std::replace(n.begin(), n.end(), '.', ',');
                cout << n << "\t";
            }
            cout << endl;
        }
    }
}

} /* namespace queries */
