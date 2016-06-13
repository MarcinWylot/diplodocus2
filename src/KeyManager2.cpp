/*
 * KeyManager2.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: marcin
 */

#include "KeyManager2.h"


KeyManager2::KeyManager2() {
    // TODO Auto-generated constructor stub

}

KEY_ID KeyManager2::Add(const char* _uri, KEY_ID oid) {
    static KEY_ID autoinct_id = 1; //OID starts from 1
    oid = oid ? oid : autoinct_id;
    pair<Tdic::iterator,bool> it = dictionary.insert( TdicEl(_uri, oid));
    if (it.second) {
        invdictionary.insert( TinvdicEl(oid, it.first->first.c_str() ));
        autoinct_id++;
    }
    return it.first->second;
}

void KeyManager2::Display() {
    for (Tdic::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
        cout << it->second << ": " << it->first << endl;
    }
}

void KeyManager2::DisplayInv() {
    for (Tinvdic::iterator it = invdictionary.begin(); it != invdictionary.end(); it++) {
        string s((char*)it->second);
        cout << s << ": " << it->first << endl;
    }
}

string KeyManager2::Get(KEY_ID id) {
    Tinvdic::iterator it = invdictionary.find(id);
    if (it != invdictionary.end() )
        return (char*)it->second;
    else
        return "NO VALUE: ERROR";
}

KEY_ID KeyManager2::Get(const char* _uri) {
    Tdic::iterator it = dictionary.find(_uri);
    if (it != dictionary.end())
        return it->second;
    else
        return 0;
}

void KeyManager2::Store() {
    fstream file;
    try {
        file.open(diplo::dbDir+"dictionary", ios::out);
        for (Tdic::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
            file << it->second << " " << it->first << endl;
        }
        file.close();
    } catch (fstream::failure &e) {
        cerr << "Exception writing file";
    }
}

void KeyManager2::Restore() {
    fstream file;
    string line;
    KEY_ID oid;
    char * next;
    try {
        file.open(diplo::dbDir + "dictionary", ios::in);
        while (getline(file, line)) {
            oid = strtoul (line.c_str(), &next, 0);
            Add(++next, oid);
        }
        file.close();
    } catch (fstream::failure &e) {
        cerr << "Exception reading file";
    }
}

KeyManager2::~KeyManager2() {
    // TODO Auto-generated destructor stub
}



//to be removed

void KeyManager2::MakeInverseIndexTypes() {
//to be removed
}

void KeyManager2::MakeInverseIndex(multimap<KEY_ID, TYPE_ID>* data) {
    //to be removed
}
TYPE_ID KeyManager2::GetType(KEY_ID id) {
    return id >> (BASE-MASK);
}

TYPE_ID KeyManager2::GetType(const char* _uri) {
    return GetType( Get(_uri) );
}

size_t KeyManager2::GetNbOfTypes() {
    //to be removed
    return 0;
}

KEY_ID KeyManager2::GetSeq(KEY_ID id) {
    id <<= MASK;
    return id >> MASK;
}

KEY_ID KeyManager2::GetId(KEY_ID seq, TYPE_ID tid) {
    KEY_ID tmp;
    tmp = (KEY_ID) tid << (BASE - MASK);
    return seq | tmp;
}

KEY_ID KeyManager2::GetSeq(const char* _uri) {
    return GetSeq( Get(_uri) );
}

map<KEY_ID, KEY_ID>* KeyManager2::GetElementsOfType(TYPE_ID _type) {
    //to be removed
    return NULL;
}

std::ostream& operator<<(std::ostream& os, const TripleIDs& obj) {
    os << diplo::KM.Get(obj.subject) << " " << diplo::KM.Get(obj.predicate) << " " << diplo::KM.Get(obj.object) << " ." << endl;
    return os;
}
