#include "Save.h"
#include "ApplicationManager.h"
#include "CEllipse.h"
#include <fstream>
#include "GUI\Output.h"


Save::Save(ApplicationManager *pApp) :Action(pApp)
{

}
void Save::ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	pOut->PrintMessage("type the file name!");
	text1 = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void Save::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	//Input *pIn = pManager->GetInput();
	text.open(text1 + ".txt");
	Point a; a.x = 500; a.y = 500;
	GfxInfo FigureGfxInfo;
	CFigure *c = new CEllipse(a, FigureGfxInfo);
	text << c->GetFColorString(UI.FillColor) << " " << c->GetDColorString(UI.DrawColor) << endl;

	pManager->Savewindow(text);
	text.close();
	pOut->PrintMessage("Saved!");


}