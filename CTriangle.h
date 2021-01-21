#pragma once
#include"Figures/CFigure.h"
class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CheckPoint(int x, int y) const;			//Check if the point is inside the figure
	virtual void PrintInfo(Output* pOut) const;				//Print the info of the figure
	float Area(int x1, int y1, int x2, int y2, int x3, int y3) const;
	virtual GfxInfo Get_Graphics_Info();			//Getter for the gfx info
	virtual CFigure*NewSameShape();					//Creates a typical object from the calling object
	virtual void Shift(int x, int y);				//Shifts the centre of the calling object 
	virtual Point GetCent()const;					//Get the centre of the calling object
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infil,CFigure*&);
};

