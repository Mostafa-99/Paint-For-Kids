#ifndef CHANGEOUTLINE_H
#define CHANGEOUTLINE_H
#include "Actions\Action.h"

class ChangeOutline: public Action
{
private: 
	color P;
public:
	ChangeOutline(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;

	
};





#endif