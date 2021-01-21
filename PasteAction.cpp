#include "PasteAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "CEllipse.h"
#include "CLine.h"
#include "CTriangle.h"
#include "CRhombus.h"
#include "Figures\CRectangle.h"
PasteAction::PasteAction(ApplicationManager *pApp) :Action(pApp)
{
}
void PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input*pIn=pManager->GetInput();
	pOut->PrintMessage("Paste the cut/copied figure, Click Point");
	//Read the point
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
 }
void PasteAction::Execute()
{
	Output * pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure *ptr;
	ptr= pManager->GetClipboard();
	
	if (ptr != NULL)
	{
		if(ptr->GetStatus()==1)
		{
			Point u=ptr->GetCent();
			int x=u.x-P.x;
			int y=u.y-P.y;
			ptr->Shift(x,y);
			pManager->AddFigure(ptr);
			ptr->SetStatus(0);
			CFigure*Z=ptr->NewSameShape();
			pManager->SetClipBoard(Z);
			Z->SetStatus(1);
		}
		else if(ptr->GetStatus()==2)
		{
			Point u=ptr->GetCent();
			int x=u.x-P.x;
			int y=u.y-P.y;
			ptr->Shift(x,y);
			pManager->RemoveCutFigure();
			pManager->AddFigure(ptr);
			ptr->SetStatus(2);
			CFigure*Z=ptr->NewSameShape();
			pManager->SetClipBoard(Z);
			Z->SetStatus(2);
			
		}
	}
	else
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("No copied/cut figure");
	}
	
	
}
