#include "CutAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
CutAction::CutAction(ApplicationManager *pApp) :Action(pApp)
{
}
void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Cut the selected figure");
 }
void CutAction::Execute()
{
	Output * pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure *ptr;
	ptr= pManager->GetSelectedFig();
	CFigure*PC=pManager->GetCutF();
	if (ptr != NULL)
	{			
		if( PC!=NULL)
		{
			
			PC->ChngDrawClr(BLUE);
			PC->SetStatus(0);
		}
		ptr->SetStatus(2);
		CFigure*ne=ptr->NewSameShape();
		pManager->SetClipBoard(ne);
		ne->SetStatus(2);
		ptr->ChngDrawClr(GREY);
		pManager->SetCutF(ptr);
	}
	else
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("No selected figure");
	}
	
	
}
