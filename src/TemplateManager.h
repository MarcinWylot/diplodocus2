/*
 * TemplateManager.h
 *
 *  Created on: 08-10-2012
 *      Author: marcin
 */

#ifndef TEMPLATEMANAGER_H_
#define TEMPLATEMANAGER_H_

#include	"diplodocus.h"
#include	"KeyManager.h"
#include	"Molecules.h"
#include 	"API.h"
#include <unordered_set>

//class TripleTemplate {
//public:
////	KEY_ID ID;
//	KEY_ID subjectType; // 0 - undefined
//	KEY_ID	predicateID; // must be defined
//	KEY_ID objectType; // 0 - undefined
////	unsigned short int scope;
////	friend int operator<(const TripleTemplate& left, const TripleTemplate& right);
//	friend int operator==(const TripleTemplate& left, const TripleTemplate& right);
//	void Display() const;
//	TripleTemplate();
//
//};

class TemplateManager {
    KEY_ID NaturaltemplateMaxID;

    bool CheckIfRoot(KEY_ID t);
public:
  
  //this I use for templates with TYPEs
  	//unordered_map<KEY_ID, S_l> templates; // <TemplateID, <subjectsType, <predicates, <objectsType> > > >
	unordered_map< KEY_ID, KEY_ID> RootTemplateIdx; //TYPE -> Template
	unordered_map< KEY_ID, unordered_set<KEY_ID>> TemplateMolecules; //Template -> molecules

  	 unordered_map<KEY_ID, unordered_set<KEY_ID>> templates2; // <TemplateID, predicates>

	//unordered_map< KEY_ID, KEY_ID> TmergedWith; //OldTemplate -> NewTemplate templates after merginig
	
	
	unordered_multimap< KEY_ID, KEY_ID> MoleculeTemplate; //root Molecule -> Template
	unordered_map< KEY_ID, unordered_set<KEY_ID> > TemplatesGraph; //root Template -> Template
	
//simple predicate index
	unordered_map<KEY_ID, unordered_set<KEY_ID> > PredicateMolecules; //Predicate -> molecules
//Templates indexed by Predicates
	unordered_map<KEY_ID, unordered_set<KEY_ID> > PredicateTemplates; //Predicate -> templates
  
    int n=0,o=0;
    TemplateManager();
//	void AddTemplate(TripleTemplate triple);
    void AddTriple(KEY_ID subjectType, KEY_ID predicate, KEY_ID objectType, KEY_ID moleculeID);
    void AddPredicates(KEY_ID predicate1, KEY_ID predicate2, unordered_set<KEY_ID> *moleculesID);
    void MineTemplateFromMolecule(const pair<KEY_ID, P_l>& molecule);
    
    static float CompateTemplates(KEY_ID t1, KEY_ID t2);
    static void MergeTemplates(KEY_ID t1, KEY_ID t2);
    
    
    
//	void AddPredicates(unordered_map<KEY_ID, unordered_map<KEY_ID, unordered_set<KEY_ID>> > *predicates);
//	void AddPredicates(KEY_ID predicateType);

//	void AddTripleInScope(TripleTemplate triple, KEY_ID root, unsigned short int scope);

//	void GetTemplates(KEY_ID s, KEY_ID p, KEY_ID o, unsigned short int scope, unordered_multimap<KEY_ID, KEY_ID> *result_templates); //FIXME change to unordered_multimap

    void GetMoleculesForPredicates(vector<QueryGraph> &graph, unordered_set<unordered_set<KEY_ID>*> &result_molecules);
     void GetMoleculesForPredicatesFromTemplates(vector<QueryGraph> &graph, unordered_set<unordered_set<KEY_ID>*> &result_molecules);

    void DisplayTemplates(KEY_ID tmp = 0);
    void DisplayMoleculesStats();
    void DisplayNoTemplates();
//	void Display(size_t tmpl);
//	void Store();
//	void Restore();
    virtual ~TemplateManager();

    //remove
//	size_t GetTemplate(KEY_ID root, KEY_ID s, KEY_ID p, KEY_ID o);
};

namespace diplo {
extern class TemplateManager TM;
}

#endif /* TEMPLATEMANAGER_H_ */
