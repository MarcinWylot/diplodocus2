/*
 * TypesHierarchy.h
 *
 *  Created on: 07-08-2012
 *      Author: marcin
 */

#ifndef TYPESHIERARCHY_H_
#define TYPESHIERARCHY_H_

#include	"diplodocus.h"
#include	"KeyManager.h"
#include	"TypesManager.h"

class TypesHierarchy {
    unordered_map<KEY_ID,unordered_set<KEY_ID> > types;
public:
    TypesHierarchy();
    void Add(KEY_ID type);
    void AddRelation(KEY_ID type, KEY_ID parent);

    KEY_ID GiveSubClass(KEY_ID oldone, KEY_ID newone);
    set<KEY_ID> GetHierarchyForType(KEY_ID type);

    void Store();
    void Restore();

    void Display();
    virtual ~TypesHierarchy();
};

namespace diplo {
extern class TypesHierarchy TH;
}
#endif /* TYPESHIERARCHY_H_ */
