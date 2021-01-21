#include <iostream>
#include "ToDraw.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"

using namespace std;

ToDraw::ToDraw(ApplicationManager *pApp):Action(pApp)
{
	pManager->AddRemoved();
	pManager->UpdateInterface();
}
void ToDraw::ReadActionParameters()
{

}

void ToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pManager->UpdateInterface();
}