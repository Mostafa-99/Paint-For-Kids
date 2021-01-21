#include <iostream>
#include "ChangeOutline.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"

using namespace std;

ChangeOutline::ChangeOutline(ApplicationManager *pApp):Action(pApp)
{
}
void ChangeOutline::ReadActionParameters()
{
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput(); 
	pOut->PrintMessage("Change the outline color, Please select a color");
	
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
				P = BLUE;
				pOut->ClearStatusBar();
				pOut->PrintMessage("Blue Color is selected");
				break;
			case ITM_RED:
				P = RED;
				pOut->ClearStatusBar();
				pOut->PrintMessage("Red Color is selected");
				break;
			case ITM_WHITE: 
				P = WHITE;
				pOut->ClearStatusBar();
				pOut->PrintMessage("White Color is selected");
				break;
			case ITM_GREEN:
				P = GREEN;
				pOut->ClearStatusBar();
				pOut->PrintMessage("Green Color is selected");
				break;
			case ITM_BLACK:
				P = BLACK;
				pOut->ClearStatusBar();
				pOut->PrintMessage("Black Color is selected");
				break;
			}
		}

}
void ChangeOutline::Execute()
{
	Output * pOut = NULL;
	ReadActionParameters();
	CFigure*t=pManager->GetSelectedFig();
	if ( t!=NULL)
	{
		t->ChngDrawClr(P);
	}
	pOut->ChangeDrawCol(P);

}