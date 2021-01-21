#include "AddRhombusAction.h"
#include "CRhombus.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddRhombusAction::AddRhombusAction(ApplicationManager * pApp) :Action(pApp)
{
	 PlaySound(TEXT("RhomSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void AddRhombusAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at rhombus center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	RhombusGfxInfo.isFilled= UI.FilledOrNot;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RhombusGfxInfo.DrawClr = UI.DrawColor;
	RhombusGfxInfo.FillClr = UI.FillColor;

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombusAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CRhombus *R = new CRhombus(P1, RhombusGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(R);
}
