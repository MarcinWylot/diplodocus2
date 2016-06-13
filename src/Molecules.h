/*
 * Molecules.h
 *
 *  Created on: 02-11-2012
 *      Author: marcin
 */

#ifndef MOLECULES_H_
#define MOLECULES_H_

#include	"diplodocus.h"
#include	"KeyManager.h"
//#include	"TemplateManager.h"
#include	"TypesManager.h"

#include <unordered_set>
#include <unordered_map>



class Molecules {


    //TODO mayby better to have pointers in in the S+ place ??? to think about
    
public:
OM_l inv_molecules; // object -> molecules (OS+ index)
    S_l molecules; // <subjects, <predicates, <objects> > > //temporatly public
//	void CreateMolecule(KEY_ID s);

    void AddTriple(KEY_ID s, KEY_ID p, KEY_ID o);
		void AddTriple2(KEY_ID s, KEY_ID p, KEY_ID o);
    S_l::iterator Get(KEY_ID s);
    bool CheckEndGet(S_l::iterator m);
    unordered_set<KEY_ID>* GetMoleculesFromInvertedIdx(KEY_ID o);
    bool IsItMyObject(KEY_ID s);

    void Display();
    void Display(KEY_ID molecule);
    Molecules();
    ~Molecules();
};

namespace diplo {
extern class Molecules M;
}


//class Molecule {
//	//friend class Molecules;
//	//KEY_ID templat;
////	multimap<KEY_ID,Entity> next; //triple template and multiple objects
//	unordered_map< KEY_ID,unordered_set<KEY_ID> > entities;
//
////public:
//	void AddTriple(KEY_ID p, KEY_ID o);
//
////	void FindEntityAndAddNext(KEY_ID tripleTmpl, KEY_ID o, KEY_ID s, unsigned short int scope);
////
////	bool CheckIfEntityExists(unordered_set<KEY_ID> *tripleTemplates, KEY_ID o, unsigned short int scope);
////	void GetEntity(unordered_set<KEY_ID> *tripleTemplates, KEY_ID s, unsigned short int scope, unordered_set<KEY_ID> *result);
////	void GetAllEntities(unsigned short int scope, unordered_multimap<KEY_ID, KEY_ID> *result, KEY_ID s);
////	void GetObjects(KEY_ID tripleTmpl, set<KEY_ID>* result);
//
//	void Display();
//	Molecule(KEY_ID templat);
//	~Molecule();
//};


#endif /* MOLECULES_H_ */
