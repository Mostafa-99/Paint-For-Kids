#ifndef EXITACTION_H
#define EXITACTION_H
#include "Actions\Action.h"

class ExitAction: public Action
{
private: 
	Point P;
public:
	ExitAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;
	
};





#endif