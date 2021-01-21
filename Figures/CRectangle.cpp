#include "CRectangle.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::CheckPoint(int x, int y)const
{
	if ((x<=Corner1.x && x>=Corner2.x) || (x<=Corner2.x && x>=Corner1.x) )
	{
		if((y<=Corner1.y && y>=Corner2.y) || (y<=Corner2.y && y>=Corner1.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
	return false;
	}
}

 void CRectangle::PrintInfo(Output* pOut) const
{
	
	string A="ID: "+to_string(ID)+" Start Point: " +to_string(Corner1.x)+","+to_string(Corner1.y)+" End Point: "+to_string(Corner2.x) +","+to_string(Corner2.y)+" Height: "+to_string(abs(Corner1.y-Corner2.y))+" Width: "+to_string(abs(Corner1.x-Corner2.x));
	pOut->PrintMessage(A);
}

 GfxInfo CRectangle::Get_Graphics_Info()
 {
	 return FigGfxInfo;
 }

 CFigure* CRectangle::NewSameShape()
{
	CFigure*n= new CRectangle(Corner1,Corner2,FigGfxInfo);
	return n;
}
 void CRectangle::Shift(int x,int y)
{
	Corner1.x=Corner1.x-x;
	Corner1.y=Corner1.y-y;
	Corner2.x=Corner2.x-x;
	Corner2.y=Corner2.y-y;
}
 Point CRectangle::GetCent()const
{
	Point r;
	r.x=(Corner1.x+Corner2.x)/2;
	r.y=(Corner1.y+Corner2.y)/2;
	return r;
}
void CRectangle::Save(ofstream &OutFile)
 {
	string A = GetFColorString(FigGfxInfo.FillClr);
	string B = GetDColorString(FigGfxInfo.DrawClr);
	 OutFile << "Rect"<<" "<<ID<<" "<< Corner1.x << " " << Corner1.y<<" "<< Corner2.x << " " << Corner2.y <<" "<<A<<" "<<B<<endl;
	

 }
 void CRectangle::Load(ifstream &InFile,CFigure *&c)
 {
	 string A;
	 string B;
	 InFile >> ID;
	 InFile >> Corner1.x >> Corner1.y>>Corner2.x>>Corner2.y;
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
	c = new CRectangle(Corner1, Corner2, FigGfxInfo);
 }