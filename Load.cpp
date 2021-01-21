#include "Load.h"
#include <fstream>
#include <iostream>
using namespace std;

#include "ApplicationManager.h"
#include "Figures\CFigure.h"
#include"CEllipse.h"
#include "CTriangle.h"
#include "Figures/CRectangle.h"
#include "CRhombus.h"
#include "CLine.h"
Load::Load(ApplicationManager *pApp):Action(pApp)
{
}
void Load::Execute()
{
	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Enter the name of the file!");
	Input* pIn = pManager->GetInput();
	pManager->ClearArray();
	ifstream text(pIn->GetSrting(pOut)+".txt");
	Point a; a.x = 500; a.y = 500;
	GfxInfo FigureGfxInfo;
	CFigure *c = new CEllipse(a, FigureGfxInfo);
	string x, y;
	text >> x >> y;
	UI.FillColor = c->SetFColorFromString(x);
	UI.DrawColor = c->SetDColorFromString(y);
	if (UI.FillColor != SNOW) UI.FilledOrNot = true;
	int FigCount;
	text >> FigCount;
	string z;
	for (int i = 0; i < FigCount; i++)
	{
		Point a, d, b, c;
		GfxInfo FigGfxInfo;
		a.x =500;
		a.y =500;
		d = a; b = a; c = a;
		FigGfxInfo.isFilled = false;
		
		text >> z;
		if (z == "Ell")
		{			
			CFigure*c = new CEllipse(a, FigGfxInfo);
			c->Load(text,c);
			pManager->AddFigure(c);
		}
		if (z == "Tri")
		{	
			CFigure*a  = new CTriangle(d,b,c, FigGfxInfo);
			a->Load(text,a);
			pManager->AddFigure(a);
		}
		if (z == "Rect")
		{	
			CFigure *c = new CRectangle(a,b, FigGfxInfo);
			c->Load(text,c);
			pManager->AddFigure(c);
		}if (z == "Rhom")
		{	
			CFigure *c = new CRhombus(a, FigGfxInfo);
			c->Load(text,c);
			pManager->AddFigure(c);
		}if (z == "Line")
		{	
			CFigure*c = new CLine(a,b, FigGfxInfo);
			c->Load(text,c);
			pManager->AddFigure(c);
		}

	}
	pManager->UpdateInterface();	
	text.close();
	pOut->PrintMessage("Loaded!");
	
 }
 void Load::ReadActionParameters()
 {

 }