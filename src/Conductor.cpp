#include "Conductor.h"

namespace diplo {
KeyManager KM;
class Molecules M;

timeval stopwatch;
}

using namespace diplo;


Conductor::Conductor() {
    // TODO Auto-generated constructor stub

}

void Conductor::LoadData() {
    DIR* dir = opendir(srcDir.c_str());
    vector<string> files;

    struct dirent* pos = 0;
    while ((pos = readdir(dir))) {
        string file = pos->d_name;
        if (file != "." and file != ".." and file.size() >= 1 and file[0] != '.'
                and (0
                     or file.compare(file.size() - 3, 3, ".nt") == 0 
		    ))
            files.push_back(srcDir + "/" + file);
    }

    diplo::type = KM.Add("<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>");
    
    for (auto it : files) {
        string line;
        ifstream f(it.c_str());

        while (getline(f, line)) {
            vector<string> triple;
            tokenize(line, " \t", triple);

            KEY_ID subject = KM.Add(triple[0].c_str());
            KEY_ID predicate = KM.Add(triple[1].c_str());
            KEY_ID object = KM.Add(triple[2].c_str());

            M.AddTriple(subject, predicate, object);
        }
        f.close();
    }

}

Conductor::~Conductor() {
    // TODO Auto-generated destructor stub
}
