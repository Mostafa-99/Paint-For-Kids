#include "Delete.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"


Delete::Delete(ApplicationManager *pApp) :Action(pApp)
{
}

void Delete::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Deleted the selected figure");
 }

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure *ptr;
	ptr= pManager->GetSelectedFig();
	if (ptr !=NULL)
	{
		pManager->DelFigure(ptr);
	}
	else 
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("No selected figure");
	}
	
	
}


