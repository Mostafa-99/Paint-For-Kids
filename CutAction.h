#ifndef CUTACTION_H
#define CUTACTION_H
#include "Actions\Action.h"
#include "Figures\CFigure.h"
class CutAction:public Action
{
public:
	CutAction(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters();


};
#endif