#ifndef TOPLAY_H
#define TOPLAY_H
#include "Actions\Action.h"

class ToPlay: public Action
{
private: 
	Point P;
public:
	ToPlay(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;
	
};





#endif