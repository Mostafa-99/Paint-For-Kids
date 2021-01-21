#include <iostream>
#include "ByColor.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"
#include "CLine.h"

using namespace std;

By_Color::By_Color(ApplicationManager *pApp):Action(pApp)
{
	Correct_Count=0;
	Wrong_Count=0;
	pManager->AddRemoved();
	pManager->UpdateInterface();
}
void By_Color::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput(); 
	pOut->PrintMessage("Change the fill color, Please select a color");

}
void By_Color::Execute()
{
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput(); 

	CFigure*RandomFig=pManager->RandomFigure();      //Get a random figure from the figlist
	GfxInfo Dummy = RandomFig->Get_Graphics_Info();		//Get the graphics info of the random figure
	CLine*Y=dynamic_cast<CLine*>(RandomFig);		
	color RandomColor;


	if (Y!=NULL)
	{
		RandomColor=Dummy.DrawClr;				//Getting the drawing color if the figure is line
	}
	else
	{
		RandomColor=Dummy.FillClr;				//Getting the filling color 
	}


	int count=pManager->GetNumberOfColored(RandomColor);
	int x;
	int y;
	int ClickedFig=0;      //Counter for the number of chosen figures
	if (RandomColor==BLUE)
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("Pick blue figures");
	}
	else if(RandomColor==RED)
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("Pick red figures");
	}
	else if(RandomColor==WHITE)
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("Pick white figures");
	}
	else if(RandomColor==BLACK)
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("Pick black figures");
	}
	else if(RandomColor==GREEN)
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("Pick green figures");
	}
	while(count>0)
	{
		pIn->GetPointClicked(x,y);
		if ( y >= 0 && y < UI.ToolBarHeight)
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
			color W;
			CLine*LC=dynamic_cast<CLine*>(Clicked);
			if(LC!=NULL)
			{
				W=Clicked->Get_Graphics_Info().DrawClr;
			}
			else
			{
				W=Clicked->Get_Graphics_Info().FillClr;
			}
			if (W==RandomColor)
			{
				Correct_Count++;
				count--;
				ClickedFig++;
				pOut->ClearStatusBar();
				pOut->PrintMessage("You picked a correct figure, Correct Counter: "+to_string(Correct_Count)+ " Wrong Counter: "+to_string(Wrong_Count));	
				Clicked->SetRemoved(true);
				pOut->ClearDrawArea();
				pManager->UpdateInterface();
			
			}
			else 
			{
				Wrong_Count++;
				ClickedFig++;
				pOut->ClearStatusBar();
				pOut->PrintMessage("You picked a wrong figure, Correct-Counter: "+to_string(Correct_Count)+ " Wrong-Counter: "+to_string(Wrong_Count));
			}

		}
		else
		{
			pOut->ClearStatusBar();
			pOut->PrintMessage("Please Pick A Figure!!");
		
		}

	}
	float per=(((float)Correct_Count/ClickedFig)*100);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Congratulations!! You Picked All Required Figures, Percentage"+to_string((int)per)+"%");	
}