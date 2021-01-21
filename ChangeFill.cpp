#include <iostream>
#include "ChangeFill.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"
#include "CLine.h"

using namespace std;

ChangeFill::ChangeFill(ApplicationManager *pApp):Action(pApp)
{
}
void ChangeFill::ReadActionParameters()
{
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput(); 
	pOut->PrintMessage("Change the fill color, Please select a color");
	
	//Read the point
	int x,y;
	pIn->GetPointClicked(x,y);	//Get the coordinates of the user click
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==


			int ClickedItemOrder = (x / UI.MenuItemWidth);


			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			//Color Cases:
			case ITM_BLUE:
				PF = BLUE;
				pOut->ClearStatusBar();
				pOut->PrintMessage("Blue Color is selected");
				break;
			case ITM_RED:
				PF = RED;
				pOut->ClearStatusBar();
				pOut->PrintMessage("Red Color is selected");
				break;
			case ITM_WHITE: 
				PF = WHITE;
				pOut->ClearStatusBar();
				pOut->PrintMessage("White Color is selected");
				break;
			case ITM_GREEN:
				PF = GREEN;
				pOut->ClearStatusBar();
				pOut->PrintMessage("Green Color is selected");
				break;
			case ITM_BLACK:
				PF = BLACK;
				pOut->ClearStatusBar();
				pOut->PrintMessage("Black Color is selected");
				break;
			}
		}

}
void ChangeFill::Execute()
{
	Output * pOut = NULL;
	ReadActionParameters();
	CFigure*t=pManager->GetSelectedFig();
	if ( t!=NULL)
	{
		CLine*LC=dynamic_cast<CLine*>(t);
		if (LC==NULL)
		{
			t->ChngFillClr(PF);
		}
	}
 	pOut->ChangeFillCol(PF);
	UI.FillColor=PF;
	UI.FilledOrNot=true;
}