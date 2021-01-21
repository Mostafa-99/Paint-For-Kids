#ifndef BYFIGURE_H
#define BYFIGURE_H
#include "Actions\Action.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"

class ByFigure: public Action
{
private: 
	int CorrectCount;
	int WrongCount;
	int x;
public:
	
	ByFigure(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute() ;
	
};





#endif
