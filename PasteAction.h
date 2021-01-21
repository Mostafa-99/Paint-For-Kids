#ifndef PASTEACTION_H
#define PASTEACTION_H
#include "Actions\Action.h"
class PasteAction: public Action
{
private: 
	GfxInfo CopyFigureGfxInfo;
	Point P;
public:
	PasteAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;

	
};

#endif