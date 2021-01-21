 #ifndef ADD_RHOMBUS_ACTION_H
#define ADD_RHOMBUS_ACTION_H

#include "Actions/Action.h"

//Add Rhombus Action class
class AddRhombusAction : public Action
{
private:
	Point P1; //Rhombus Center
	GfxInfo RhombusGfxInfo;
public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();

	//Add rhombus to the ApplicationManager
	virtual void Execute();

};

#endif
