#include "CopyAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "CEllipse.h"
#include "CLine.h"
#include "CRhombus.h"
#include "CTriangle.h"
#include "Figures\CRectangle.h"
CopyAction::CopyAction(ApplicationManager *pApp) :Action(pApp)
{
}
void CopyAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Copy the selected figure");
 }
void CopyAction::Execute()
{
	Output * pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure *ptr;
	ptr= pManager->GetSelectedFig();
	if (ptr != NULL)
	{
		CFigure*ne=ptr->NewSameShape();
		pManager->SetClipBoard(ne);
		ne->SetStatus(1);
	}
	else
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("No selected figure");
	}
	
	
}
