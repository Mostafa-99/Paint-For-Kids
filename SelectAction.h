#ifndef SELECTACTION_H
#define SELECTACTION_H
#include "Actions\Action.h"

class SelectAction: public Action
{
private: 
	Point P;
public:
	SelectAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;
	
};





#endif
