#include "SaveByType.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"
#include"CEllipse.h"
#include "CTriangle.h"
#include "Figures/CRectangle.h"
#include "CRhombus.h"
#include "CLine.h"

SaveByType::SaveByType(ApplicationManager *pApp) :Action(pApp)
{

}
void SaveByType::ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	pOut->PrintMessage("type the file name!");
	text1 = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Choose the Type!");

	ActionType x = pManager->GetUserAction();
	switch (x)
	{
	case DRAW_RECT: {ClickedItem = 0; } break;
	case DRAW_LINE: {ClickedItem = 1; } break;
	case DRAW_TRI: {ClickedItem = 2; } break;
	case DRAW_ELLIPSE: {ClickedItem = 3; }break;
	case DRAW_RHOMBUS: {ClickedItem = 4; } break;
	}

}


void SaveByType::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	text.open(text1 + ".txt");
	Point a; a.x = 500; a.y = 500;
	GfxInfo FigureGfxInfo;
	CFigure *c = new CEllipse(a, FigureGfxInfo);
	text << c->GetFColorString(UI.FillColor) << " " << c->GetDColorString(UI.DrawColor) << endl;

	pManager->SaveType(text, ClickedItem);

	pOut->PrintMessage("SavedByType!");
}