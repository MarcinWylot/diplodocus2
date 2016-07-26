/*
 * KeyManager2.h
 *
 *  Created on: Feb 13, 2014
 *      Author: marcin
 */

#include	"diplodocus.h"

#ifndef KEYMANAGER_H_
#define KEYMANAGER_H_

class KeyManager {
    
   
public:
  unordered_map<string, KEY_ID> dictionary;
  unordered_map<KEY_ID, const string * > inv_dictionary;
     KEY_ID Add(const char * _uri, KEY_ID oid = 0);
     void Display();
     void DisplayInv();
     const char * Get(KEY_ID id);
     KEY_ID Get(const char* _uri);
//     void Store();
//     void Restore();

    KeyManager();
    virtual ~KeyManager();
};

namespace diplo {
extern KeyManager KM;
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

namespace diplo {
extern KeyManager KM;
}

#endif /* KEYMANAGER_H_ */
