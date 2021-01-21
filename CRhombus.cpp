#include "CRhombus.h"
#include <iostream>
#include <fstream>
using namespace std;

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRhombus(Corner1, FigGfxInfo, Selected);
}

float CRhombus::Area(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return (abs((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0));
}

bool CRhombus::CheckPoint(int x, int y) const
{
	float a1 = Area(x, y, Corner1.x, (Corner1.y)+100, (Corner1.x)+50, Corner1.y);
	float a2 = Area(x, y, (Corner1.x)+50, Corner1.y, Corner1.x, (Corner1.y)-100);
	float a3 = Area(x, y, (Corner1.x)-50, Corner1.y, Corner1.x, (Corner1.y)-100);
	float a4 = Area(x, y, (Corner1.x)-50, Corner1.y, Corner1.x, (Corner1.y)+100);
	if (a1+a2+a3+a4==10000)
		return true;
	else
		return false;
}
void CRhombus::PrintInfo(Output* pOut) const
{
	string A="ID: "+to_string(ID)+" ,Height: "+to_string(100)+" ,Width: "+to_string(50);
	pOut->ClearStatusBar();
	pOut->PrintMessage(A);
}

GfxInfo CRhombus::Get_Graphics_Info()
{
	 return FigGfxInfo;
}
CFigure* CRhombus::NewSameShape()
{
	CFigure*n= new CRhombus(Corner1,FigGfxInfo);
	return n;
}
void CRhombus::Shift(int x,int y)
{
	Corner1.x=Corner1.x-x;
	Corner1.y=Corner1.y-y;
}
Point CRhombus::GetCent()const
{
	return Corner1;
}
void CRhombus::Save(ofstream &OutFile)
{
	string A = GetFColorString(FigGfxInfo.FillClr);
	string B = GetDColorString(FigGfxInfo.DrawClr);
	OutFile << "Rhom" <<" "<<ID<<" "<< Corner1.x << " " << Corner1.y <<" "<<A <<" "<<B <<endl;
	 
}
void CRhombus::Load(ifstream &InFile,CFigure *&c)
{
	string A;
	string B;
	InFile >> ID;
	InFile >> Corner1.x >> Corner1.y ;
	InFile >> A >> B;

	if (A == "NO_FILL")
	{
		FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		SetFColorFromString(A);
	}
	SetDColorFromString(B);
	c = new CRhombus(Corner1, FigGfxInfo);
}