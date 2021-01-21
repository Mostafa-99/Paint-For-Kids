#ifndef LOADACTION_H
#define LOADACTION_H
#include "Actions\Action.h"
class Load:public Action
{
public:
	Load(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
};

#endif