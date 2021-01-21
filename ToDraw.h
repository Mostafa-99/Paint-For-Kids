#ifndef TODRAW_H
#define TODRAW_H
#include "Actions\Action.h"

class ToDraw: public Action
{
private: 
	Point P;
public:
	ToDraw(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;
	
};





#endif