/*
 * Molecules.h
 *
 *  Created on: 02-11-2012
 *      Author: marcin
 */

#ifndef MOLECULES_H_
#define MOLECULES_H_

#include	"diplodocus.h"

#include <unordered_set>
#include <unordered_map>


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//single Molecule
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Molecule
{
    unordered_map< KEY_ID, unordered_set<KEY_ID> > entities;
public:
KEY_ID s;
    void AddEntity ( KEY_ID p, KEY_ID o );

    bool CheckIfEntityExists ( KEY_ID p = 0, KEY_ID o = 0 );

    const void Display();

    const unordered_set<KEY_ID>* GetObjects ( KEY_ID p ) {
        auto e = entities.find ( p );
        if ( e !=  entities.end() ) {
            return &e->second;
        }
        return NULL;
    } ;
    const unordered_map< KEY_ID, unordered_set<KEY_ID> >* GetPredicates() {
        return &entities;
    } ;

    Molecule ( KEY_ID _s );
    ~Molecule();
};






/////////////////////////////////////////
//collection of molecules, database
//////////////////////////////////////////

class Molecules
{

    unordered_map<KEY_ID, Molecule> molecules;
    unordered_map<KEY_ID, unordered_set<Molecule*> > inv_molecules; // object -> molecules (OS+ index)
    unordered_map<KEY_ID, unordered_set<Molecule*> > predicate_idx; // predicate -> molecules (PS+ index)
    unordered_map<KEY_ID, unordered_set<KEY_ID> > type_idx; // type -> molecules
public:
    void AddTriple ( KEY_ID s, KEY_ID p, KEY_ID o );

    Molecule * Get ( KEY_ID s );
    void GetMoleculesPO ( vector<QueryBGP> &bgp, unordered_map<KEY_ID, unordered_set<Molecule*> > &results );
    unordered_set<Molecule*>* GetMoleculesO ( KEY_ID o );
    unordered_set<Molecule*>* GetMoleculesP ( KEY_ID p );
    
    unordered_set<KEY_ID>* GetMoleculesType ( KEY_ID _type ){
        auto e = type_idx.find ( _type );
        if ( e !=  type_idx.end() ) {
            return &e->second;
        }
        return NULL;
    } ;
   
    void Display();
    Molecules();
    ~Molecules();
};

namespace diplo
{
extern class Molecules M;

extern Molecules H_neg; 
extern Molecules H_mod; 
}






#endif /* MOLECULES_H_ */
