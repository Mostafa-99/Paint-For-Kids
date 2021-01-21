#ifndef CHANGEFILL_H
#define CHANGEFILL_H
#include "Actions\Action.h"

class ChangeFill: public Action
{
private: 
	color PF;
public:
	ChangeFill(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;

	
};





#endif