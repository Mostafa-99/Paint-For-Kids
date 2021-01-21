#include <iostream>
#include "ExitAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"

using namespace std;

ExitAction::ExitAction(ApplicationManager *pApp):Action(pApp)
{
}
void ExitAction::ReadActionParameters()
{

}
void ExitAction::Execute()
{
	pManager->ClearArray();
	
}