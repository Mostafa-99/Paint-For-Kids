#include "CEllipse.h"
#include <iostream>
#include <math.h> 
#include <fstream>
using namespace std;

CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}


void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a Ellipse on the screen	
	pOut->DrawEll(Corner1, FigGfxInfo, Selected);
}

bool CEllipse::CheckPoint(int x, int y)const
{
	if ((((double)(pow((x-Corner1.x),2))/pow(100,2))+((double)(pow((y-Corner1.y),2))/pow(50,2)))<=1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CEllipse::PrintInfo(Output* pOut) const
{
	string A="ID: "+to_string(ID)+" Start Point: " +to_string(Corner1.x-50)+","+to_string(Corner1.y)+" End Point: "+to_string(Corner1.x+50) +","+to_string(Corner1.y)+" Height: "+to_string(100)+" Width: "+to_string(200);
	pOut->PrintMessage(A);
}

GfxInfo CEllipse::Get_Graphics_Info()
{
	 return FigGfxInfo;
}
CFigure* CEllipse::NewSameShape()
{
	CFigure*n= new CEllipse(Corner1,FigGfxInfo);
	return n;
}
void CEllipse::Shift(int x,int y)
{
	Corner1.x=Corner1.x-x;
	Corner1.y=Corner1.y-y;
}
Point CEllipse::GetCent()const
{
	return Corner1;
}
void CEllipse::Save(ofstream &OutFile)
{
	string A=GetFColorString(FigGfxInfo.FillClr);
	string B=GetDColorString(FigGfxInfo.DrawClr);

	OutFile << "Ell" <<" "<<ID<<" "<< Corner1.x << " "<< Corner1.y << " " << A << " " << B << endl; 
}

void CEllipse::Load(ifstream &InFile,CFigure*&c)
{
	string A;
	string B;	
	Point a;
	InFile >> ID;
	InFile >> a.x >> a.y;
	InFile >> A >> B;
	if(A=="NO_FILL")
	{
		//FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		color s=SetFColorFromString(A);
	}
	color s=SetDColorFromString(B);
	c = new CEllipse(a, FigGfxInfo);
}