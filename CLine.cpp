#include "CLine.h"
#include <iostream>
using namespace std;
#include<math.h>
#include<fstream>


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CLine::CheckPoint(int x, int y)const
{
	int sline;
	int sline1;
	int sline2;
	sline = sqrt((pow((Corner1.x-Corner2.x),2))+(pow((Corner1.y-Corner2.y),2)));
	sline1 = sqrt((pow((x-Corner1.x),2))+(pow((y-Corner1.y),2)));
	sline2 = sqrt((pow((x-Corner2.x),2))+(pow((y-Corner2.y),2)));
	if(sline==(sline1+sline2))
		return true;
	return false;
}
void CLine::PrintInfo(Output* pOut) const
{
	string A="ID: "+to_string(ID)+" Start Point: " +to_string(Corner1.x)+","+to_string(Corner1.y)+" End Point: "+to_string(Corner2.x) +","+to_string(Corner2.y)+" Height: "+to_string(abs(Corner1.y-Corner2.y))+" Width: "+to_string(abs(Corner1.x-Corner2.x));
	pOut->PrintMessage(A);
}
GfxInfo CLine::Get_Graphics_Info()
 {
	 return FigGfxInfo;
 }
CFigure* CLine::NewSameShape()
{
	CFigure*n= new CLine(Corner1,Corner2,FigGfxInfo);
	return n;
}
void CLine::Shift(int x,int y)
{
	Corner1.x=Corner1.x-x;
	Corner1.y=Corner1.y-y;
	Corner2.x=Corner2.x-x;
	Corner2.y=Corner2.y-y;
}
Point CLine::GetCent()const
{
	Point l;
	l.x=(Corner1.x+Corner2.x)/2;
	l.y=(Corner1.y+Corner2.y)/2;
	return l;
}
void CLine::Save(ofstream &OutFile)
{
	string B = GetDColorString(FigGfxInfo.DrawClr);

	OutFile << "Line" << " " << ID<<" "<<Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y <<" "<<B<< endl;
}
void CLine::Load(ifstream &InFile,CFigure *&c)
{
	string A;
	Point a;
	InFile >> ID;
	InFile >> Corner1.x>> Corner1.y >> Corner2.x >> Corner2.y;
	InFile >> A ;
	SetDColorFromString(A);	
	c = new CLine(Corner1,Corner2, FigGfxInfo);
}