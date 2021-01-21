#include "CTriangle.h"
#include <iostream>
#include <fstream>
using namespace std;

CTriangle::CTriangle(Point P1, Point P2, Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

float CTriangle::Area(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return (abs((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0));
}
bool CTriangle::CheckPoint(int x, int y) const
{
	float a = Area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float a1 = Area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float a2 = Area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	float a3 = Area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (a == a1 + a2 + a3)
		return true;
	else
		return false;
}
void CTriangle::PrintInfo(Output* pOut) const
{
	string A="ID: "+to_string(ID)+" Start Point: " +to_string(Corner1.x)+","+to_string(Corner1.y)+" End Point: "+to_string(Corner3.x) +","+to_string(Corner3.y)+" Height: "+to_string(abs(Corner1.y-Corner2.y))+" Width: "+to_string(abs(Corner2.x-Corner3.x));
	pOut->PrintMessage(A);
}

GfxInfo CTriangle::Get_Graphics_Info()
{
	 return FigGfxInfo;
}
CFigure* CTriangle::NewSameShape()
{
	CFigure*n= new CTriangle(Corner1,Corner2,Corner3,FigGfxInfo);
	return n;
}
void CTriangle::Shift(int x,int y)
{
	Corner1.x=Corner1.x-x;
	Corner1.y=Corner1.y-y;
	Corner2.x=Corner2.x-x;
	Corner2.y=Corner2.y-y;
	Corner3.x=Corner3.x-x;
	Corner3.y=Corner3.y-y;
}
Point CTriangle::GetCent()const
{
	Point t;
	t.x=(Corner1.x+Corner2.x+Corner3.x)/3;
	t.y=(Corner1.y+Corner2.y+Corner3.y)/3;
	return t;
}
void CTriangle::Save(ofstream &OutFile)
{
	string A = GetFColorString(FigGfxInfo.FillClr);
	string B = GetDColorString(FigGfxInfo.DrawClr);
	OutFile << "Tri" <<" "<<ID <<" " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y <<" "<<A<<" "<<B<< endl;

}
void CTriangle::Load(ifstream &InFile,CFigure *&c)
{
	
	string A;
	string B;
	InFile >> ID;
	InFile >> Corner1.x >> Corner1.y>> Corner2.x >> Corner2.y>> Corner3.x >> Corner3.y;
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
	
	c = new CTriangle(Corner1,Corner2,Corner3, FigGfxInfo);
	
}