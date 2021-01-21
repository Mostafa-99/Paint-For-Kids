#ifndef SAVEACTION_H
#define SAVEACTION_H
#include "Actions\Action.h"
#include <fstream>
class Save :public Action
{
protected:
	ofstream text;
	string text1;
public:
	Save(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

};

#endif