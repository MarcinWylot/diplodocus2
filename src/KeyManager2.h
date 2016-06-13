/*
 * KeyManager2.h
 *
 *  Created on: Feb 13, 2014
 *      Author: marcin
 */

#ifndef KEYMANAGER2_H_
#define KEYMANAGER2_H_

#include	"diplodocus.h"

typedef pair<string, KEY_ID > TdicEl;
typedef unordered_map<string, KEY_ID > Tdic;

typedef unordered_map<KEY_ID, const void* > Tinvdic;
typedef pair< KEY_ID, const void* > TinvdicEl;

class KeyManager2 {
    Tdic dictionary;
    Tinvdic invdictionary;
public:
    KEY_ID Add(const char * _uri, KEY_ID oid = 0);
    void Display();
    void DisplayInv();
    string Get(KEY_ID id);
    KEY_ID Get(const char* _uri);
    void Store();
    void Restore();

    //to be removed
    void MakeInverseIndexTypes();
    void MakeInverseIndex(multimap<KEY_ID, TYPE_ID>* data);
    static TYPE_ID GetType(KEY_ID id);
    TYPE_ID GetType(const char* _uri);
    size_t GetNbOfTypes();
    KEY_ID GetSeq(KEY_ID id);
    static KEY_ID GetId(KEY_ID seq, TYPE_ID tid);
    KEY_ID GetSeq(const char* _uri);
    map<KEY_ID, KEY_ID> * GetElementsOfType(TYPE_ID _type);


    KeyManager2();
    virtual ~KeyManager2();
};

namespace diplo {
extern KeyManager2 KM;
}

class TripleIDs {
public:
    KEY_ID subject;
    KEY_ID predicate;
    KEY_ID object;
    TripleIDs() {
        subject = 0;
        predicate=0;
        object=0;
    }
    TripleIDs(KEY_ID s,KEY_ID p,KEY_ID o,KEY_ID pr) {
        subject = s;
        predicate=p;
        object=o;
    }
};
std::ostream& operator<<(std::ostream& os, const TripleIDs& obj);

#endif /* KEYMANAGER2_H_ */
