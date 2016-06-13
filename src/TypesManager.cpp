/*
 * TypesManager.cpp
 *
 *  Created on: 30-03-2013
 *      Author: marcin
 */

#include "TypesManager.h"

TypesManager::TypesManager() {
}

void TypesManager::AddElement(TYPE_ID type, KEY_ID e) {
//	unordered_map<KEY_ID, unordered_set< KEY_ID >>::iterator it = types.find(type);
//	if( it != types.end() )
//		it->second.insert(e);
//	else
//		types.insert(pair<KEY_ID, unordered_set<KEY_ID> >(type,{e}));
}

unordered_set<KEY_ID>* TypesManager::GetElementsOfType(TYPE_ID type) {
//	unordered_map<KEY_ID, unordered_set<KEY_ID>>::iterator it = types.find(type);
//	if (it != types.end())
//		return &(it->second);
//	else
    return NULL;
}

TypesManager::~TypesManager() {
    // TODO Auto-generated destructor stub
}

