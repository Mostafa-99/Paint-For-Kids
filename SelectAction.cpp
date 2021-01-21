#include <iostream>
#include "SelectAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"
using namespace std;

SelectAction::SelectAction(ApplicationManager *pApp):Action(pApp)
{
}
void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput(); 


	pOut->PrintMessage("Select A Figure!");
	
	//Read the point
	pIn->GetPointClicked(P.x, P.y);

}
void SelectAction::Execute()
{
	ReadActionParameters();
	CFigure*x=pManager->GetSelectedFig();
	Output* pOut = pManager->GetOutput();
	CFigure*ptr=pManager->GetFigure(P.x, P.y);
	if (ptr!=NULL)
	{
		if(ptr==x)
		{
			ptr->SetSelected(false);
			pManager->SetSelectedFig(NULL);
		}
		else
		{
			if (x==NULL)
			{
				ptr->SetSelected(true);
				pManager->SetSelectedFig(ptr);
				pOut->ClearStatusBar();
				ptr->PrintInfo(pOut);	
					
			}
			else if (x!=NULL)
			{
				x->SetSelected(false);
				ptr->SetSelected(true);
				pManager->SetSelectedFig(ptr);
				ptr->PrintInfo(pOut);	
			}
		}
	
	}
	else
	{
		if (pManager->GetSelectedFig()!=NULL)
		{
			pManager->GetSelectedFig()->SetSelected(false);
			pManager->SetSelectedFig(NULL);
			pOut->ClearStatusBar();
		}
		else
		{
			pOut->ClearStatusBar();
			pOut->PrintMessage("Please click on a figure");
		}
	}
}