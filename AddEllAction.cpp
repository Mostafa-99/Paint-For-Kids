#include "AddEllAction.h"
#include "CEllipse.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddEllAction::AddEllAction(ApplicationManager * pApp) :Action(pApp)
{
	 PlaySound(TEXT("EllSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void AddEllAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at ellipse center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	EllGfxInfo.isFilled =  UI.FilledOrNot; //pOut->GetFilledOrFrame();	//default is not filled

	//get drawing, filling colors and pen width from the interface
	EllGfxInfo.DrawClr = UI.DrawColor;
	EllGfxInfo.FillClr = UI.FillColor;

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a ellipse with the parameters read from the user
	CEllipse *E = new CEllipse(P1, EllGfxInfo);

	//Add the ellipse to the list of figures
	pManager->AddFigure(E);
}