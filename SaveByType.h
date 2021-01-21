#pragma once
#include "Actions\Action.h"
#include <fstream>
class SaveByType :public Action
{
protected:

	int ClickedItem;
	ofstream text;
	string text1;
public:

	SaveByType(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};