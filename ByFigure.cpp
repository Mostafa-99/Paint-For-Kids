#include <iostream>
#include "ByFigure.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"
#include "CEllipse.h"
#include "CRhombus.h"
#include "CTriangle.h"
#include "Figures\CRectangle.h"
#include "CLine.h"

using namespace std;

ByFigure::ByFigure(ApplicationManager *pApp):Action(pApp)
{
	CorrectCount=0;
	WrongCount=0;
	pManager->AddRemoved();
	pManager->UpdateInterface();
}
void ByFigure::ReadActionParameters()
{
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput(); 
	pOut->PrintMessage("Change the fill color, Please select a color");
	
	

}
void ByFigure::Execute()
{
	int FiguresSelected=0;
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput(); 

	pOut->ClearStatusBar();
	CFigure*RandomFig=pManager->RandomFigure();			//Getting a random figure from the figlist

	//Checking the type of the figure
	CRectangle*Rect=dynamic_cast<CRectangle*>(RandomFig);
	CLine*Line=dynamic_cast<CLine*>(RandomFig);
	CTriangle*Tri=dynamic_cast<CTriangle*>(RandomFig);
	CEllipse*Ell=dynamic_cast<CEllipse*>(RandomFig);
	CRhombus*Rho=dynamic_cast<CRhombus*>(RandomFig);


	if (Rect!=NULL)
	{
		pOut->PrintMessage("Please select all rectangles");
	}
	else if(Line!=NULL)
	{
		pOut->PrintMessage("Please select all lines");
	}
	else if(Tri!=NULL)
	{
		pOut->PrintMessage("Please select all triangles");
	}
	else if(Ell!=NULL)
	{
		pOut->PrintMessage("Please select all ellipses");
	}
	else if(Rho!=NULL)
	{
		pOut->PrintMessage("Please select all rhombuses");
	}
	int count=pManager->GetNumberOfFigures(RandomFig);
	



	int x;
	int y;
	while(count>0)
	{
		pIn->GetPointClicked(x,y);
		if ( y >= 0 && y < UI.ToolBarHeight)      //Checking if the user is clicking on an item from the bar
		{	
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			if (ClickedItemOrder==0)
			{
				pManager->ExecuteAction(ByShape);
				break;
			}
			if (ClickedItemOrder==1)
			{
				pManager->ExecuteAction(ByColor);
				break;
			}
			if (ClickedItemOrder==2)
			{
				pManager->ExecuteAction(TO_DRAW);
				break;
			}
			if (ClickedItemOrder==3)
			{
				pManager->ExecuteAction(EXIT);
				break;
			}
		}



		CFigure*Clicked=pManager->GetFigure(x,y);
		if (Clicked!=NULL)
		{
			if (Rect!=NULL)
			{
				CRectangle*Dummy=dynamic_cast<CRectangle*>(Clicked);
				if(Dummy!=NULL)
				{
					CorrectCount++;
					count--;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a correct figure(Rectangle), Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
					Clicked->SetRemoved(true);
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
				}
				else
				{
					WrongCount++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a wrong figure, Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
				}
			}
			else if(Line!=NULL)
			{
				CLine*Dummy=dynamic_cast<CLine*>(Clicked);
				if(Dummy!=NULL)
				{
					CorrectCount++;
					count--;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a correct figure(Line), Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
					Clicked->SetRemoved(true);
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
				}
				else
				{
					WrongCount++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a wrong figure, Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
					
				}
			}
			else if(Tri!=NULL)
			{
				CTriangle*Dummy=dynamic_cast<CTriangle*>(Clicked);
				if(Dummy!=NULL)
				{
					CorrectCount++;
					count--;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a correct figure(Triangle), Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
					Clicked->SetRemoved(true);
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
				}
				else
				{
					WrongCount++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a wrong figure, Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;

			
				}
			}
			else if(Ell!=NULL)
			{
				CEllipse*Dummy=dynamic_cast<CEllipse*>(Clicked);
				if(Dummy!=NULL)
				{
					
					CorrectCount++;
					count--;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a correct figure(Ellipse), Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
					Clicked->SetRemoved(true);
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
				}
				else
				{
					WrongCount++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a wrong figure, Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
			
				}
			}
			else if(Rho!=NULL)
			{
				CRhombus*Dummy=dynamic_cast<CRhombus*>(Clicked);
				if(Dummy!=NULL)
				{
					CorrectCount++;
					count--;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a correct figure(Rhombus), Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
					Clicked->SetRemoved(true);
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
				}
				else
				{
					WrongCount++;
					pOut->ClearStatusBar();
					pOut->PrintMessage("You selected a wrong figure, Correct Figure Counter: "+to_string(CorrectCount)+" Wrong Figure Counter: "+to_string(WrongCount));
					FiguresSelected++;
					
				}
			}	
		}
		else 
		{
			pOut->ClearStatusBar();
			pOut->PrintMessage("Please Select A Figure!");
		}

	}
	float per=(((float)CorrectCount/FiguresSelected)*100);
	
	pOut->ClearStatusBar();
	pOut->PrintMessage("Congratulaions!! You Selected All Required Figures, Your Percetnage: "+to_string((int)per)+"%");
}
