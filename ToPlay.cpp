#include <iostream>
#include "ToPlay.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"

using namespace std;

ToPlay::ToPlay(ApplicationManager *pApp):Action(pApp)
{
}
void ToPlay::ReadActionParameters()
{

}


void ToPlay::Execute()
{
	CFigure*Dummy=pManager->GetSelectedFig();
	if (Dummy!=NULL)
	{
		Dummy->SetSelected(false);
		pManager->SetSelectedFig(NULL);
	}
		Output* pOut = pManager->GetOutput();

	pOut->CreatePlayToolBar();
}