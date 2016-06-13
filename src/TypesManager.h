/*
 * TypesManager.h
 *
 *  Created on: 30-03-2013
 *      Author: marcin
 */

#ifndef TYPESMANAGER_H_
#define TYPESMANAGER_H_

#include "KeyManager.h"

class TypesManager {
    unordered_map<KEY_ID, unordered_set< KEY_ID >> types;
public:
    void AddElement(KEY_ID type, KEY_ID e);
    unordered_set< KEY_ID >* GetElementsOfType( KEY_ID type );
    TypesManager();
    virtual ~TypesManager();
};

namespace diplo {
extern class TypesManager TypesM;
}

#endif /* TYPESMANAGER_H_ */
