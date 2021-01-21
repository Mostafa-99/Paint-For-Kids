#ifndef BYCOLOR_H
#define BYCOLOR_H
#include "Actions\Action.h"
#include "ApplicationManager.h"

class By_Color: public Action
{
private: 
	int Correct_Count;
	int Wrong_Count;
public:
	By_Color(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;
	
};





#endif
