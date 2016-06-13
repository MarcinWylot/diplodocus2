/*
 * TypesHierarchy.cpp
 *
 *  Created on: 07-08-2012
 *      Author: marcin
 */

#include "TypesHierarchy.h"

TypesHierarchy::TypesHierarchy() {
}

void TypesHierarchy::Add(KEY_ID type) {
    types.insert(pair< KEY_ID,unordered_set<KEY_ID> > (type, unordered_set<KEY_ID>() ) );
}

void TypesHierarchy::AddRelation(KEY_ID type, KEY_ID parent) {
    unordered_map<KEY_ID,unordered_set<KEY_ID> >::iterator it = types.find(parent);
    if (it != types.end() ) {
        it->second.insert(type);
    } else {
        types.insert(pair< KEY_ID,unordered_set<KEY_ID> > (parent, unordered_set<KEY_ID>( {type}) ) );
    }
}

void TypesHierarchy::Display() {
    int i = 0;
    for (unordered_map<KEY_ID,unordered_set<KEY_ID> >::iterator it = types.begin(); it != types.end(); it++) {
        cout << "[ "<< i++ << " ] ";

        cout << diplo::KM.Get( it->first ) << "( "<< it->first << " )" << " =========> " ;
        for (unordered_set<KEY_ID>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << diplo::KM.Get( *it2 )  << "( "<< *it2 << " )" << "\t" ; //types[i][j] << ", " ;
        }
        cout << endl;
    }

}

/*
 * returns more specific class,
 * in case they are not related returns the OLD one
 */
KEY_ID TypesHierarchy::GiveSubClass(KEY_ID oldone, KEY_ID newone) {
    unordered_map<KEY_ID,unordered_set<KEY_ID> >::iterator it = types.find(oldone);
    if (it != types.end() ) {
        if (it->second.find(newone) != it->second.end() ) {
            return newone;
        }
    }
    return oldone;

}

set<KEY_ID> TypesHierarchy::GetHierarchyForType(KEY_ID _type) {
    set<KEY_ID> tmp;
    set<KEY_ID> vect;
    unordered_map<KEY_ID,unordered_set<KEY_ID> >::iterator it = types.find(_type);
    if (it != types.end()) {
        for (unordered_set<KEY_ID>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            vect.insert(*it2);
            tmp = GetHierarchyForType(*it2);
            vect.insert(tmp.begin(), tmp.end());
        }
    }
    vect.insert(_type);
    return vect;
}

void TypesHierarchy::Store() {
    fstream file;
    try {
        file.open(diplo::dbDir + "types", ios::binary | ios::out);
        size_t s = types.size();
        file.write((char*) &s, sizeof(s));
        for (unordered_map<KEY_ID, unordered_set<KEY_ID> >::iterator it = types.begin(); it != types.end(); it++) {

            KEY_ID type = it->first;
            file.write((char*) &type, sizeof(type));

            s = it->second.size();
            file.write((char*) &s, sizeof(s));
            for (unordered_set<KEY_ID>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
                file.write((char*) &(*it2), sizeof(KEY_ID));
            }
        }
        file.close();
    } catch (fstream::failure &e) {
        cerr << "Exception writing file";
    }
}

void TypesHierarchy::Restore() {
    fstream file;
    try {
        file.open(diplo::dbDir+"types", ios::binary | ios::in);
        size_t s1;
        file.read((char*) &s1, sizeof(s1));
        for (size_t i = 0; i < s1; i++) {
            KEY_ID parent;
            file.read((char*) &parent, sizeof(parent));
            Add(parent);

            size_t s2;
            file.read((char*) &s2, sizeof(s2));
            for (size_t j = 0; j < s2; j++) {
                KEY_ID type;
                file.read((char*) &type, sizeof(type));
                AddRelation(type,parent);
            }
        }

    } catch (fstream::failure &e) {
        cerr << "Exception writing file";
    }
}

TypesHierarchy::~TypesHierarchy() {
    // TODO Auto-generated destructor stub
}
