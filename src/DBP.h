#ifndef DBP_H_
#define DBP_H_

#include	"diplodocus.h"
#include	"KeyManager.h"
#include 	"TypesHierarchy.h"
#include	"TemplateManager.h"
#include	"Molecules.h"
#include	"API.h"
#include	"Conductor.h"
#include	"ConductorNode.h"



namespace queries {
	
	class DBP {
	public:

		
		void predQuery();
		void pathQueryPredicates();
		void pathQueryTemplates();
		void pathQueryTemplates2(); //birirectional molecules
		void pathQueryTemplatesGraph();
		void pathQueryTemplatesGraph2();  //birirectional molecules		
		
		void pathQuery2Predicates();
		void pathQuery2Templates();
		void pathQuery2TemplatesGraph();
		
		void trianglePredicates();
		void triangleTemplates();
		void triangleTemplatesGraph();
		
		void triangle2Predicates();
		void triangle2Templates();
		void triangle2TemplatesGraph();
		
		void triangle3Templates();
		void triangle3TemplatesGraph();

		DBP();
		~DBP();
		void run(string);
	};
	
}

#endif /* DBP_H_ */