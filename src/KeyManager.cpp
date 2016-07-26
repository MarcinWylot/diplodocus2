/*
 * KeyManager2.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: marcin
 */

#include "KeyManager.h"





KeyManager::KeyManager() {
    // TODO Auto-generated constructor stub

}

KEY_ID KeyManager::Add(const char* _uri, KEY_ID oid) {
     static KEY_ID autoinct_id = 1; //OID starts from 1
     oid = oid ? oid : autoinct_id; 
     auto e = dictionary.insert( {_uri, oid});
     if (e.second) {
         inv_dictionary.insert( {oid, &(e.first->first)} );
         autoinct_id++;
     }
     return e.first->second;

  return 1;
}

void KeyManager::Display() {
  for (auto s : dictionary) {
    cout << s.first << "\t[ " << s.second << " ]" << endl;
  }
}

void KeyManager::DisplayInv() {
  for (auto s : inv_dictionary) {
    cout << "[ " << s.first << " ] ---> "<< *(s.second) << endl;
  }
}

const char * KeyManager::Get(KEY_ID id) {
    auto v = inv_dictionary.find(id);
    if (v != inv_dictionary.end() )
        return v->second->c_str();
    else
        return "NO VALUE: ERROR";
}

KEY_ID KeyManager::Get(const char* _uri) {
    auto v = dictionary.find(_uri);
    if (v != dictionary.end() ) {
        return v->second;
    } else
         return 0;
}

// void KeyManager2::Store() {
//     fstream file;
//     try {
//         file.open(diplo::dbDir+"dictionary", ios::out);
//         for (Tdic::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
//             file << it->second << " " << it->first << endl;
//         }
//         file.close();
//     } catch (fstream::failure &e) {
//         cerr << "Exception writing file";
//     }
// }
// 
// void KeyManager2::Restore() {
//     fstream file;
//     string line;
//     KEY_ID oid;
//     char * next;
//     try {
//         file.open(diplo::dbDir + "dictionary", ios::in);
//         while (getline(file, line)) {
//             oid = strtoul (line.c_str(), &next, 0);
//             Add(++next, oid);
//         }
//         file.close();
//     } catch (fstream::failure &e) {
//         cerr << "Exception reading file";
//     }
// }

KeyManager::~KeyManager() {
    // TODO Auto-generated destructor stub
}
