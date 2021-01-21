#ifndef CRHOMBUS_H
#define CRHOMBUS_H

#include "Figures/CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Corner1;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CheckPoint(int x, int y) const;		//Check if the point is in the shape
	virtual void PrintInfo(Output* pOut) const;			//Print the info of the shape
	float Area(int x1, int y1, int x2, int y2, int x3, int y3) const;
	virtual GfxInfo Get_Graphics_Info();				//Get the gfx info of the shape
	virtual CFigure*NewSameShape();						//Creates a typical shape from the calling object
	virtual void Shift(int x, int y);					//Shifts the centre of the calling object
	virtual Point GetCent()const;						//Get the centre of the calling object
	virtual void Save(ofstream &OutFile);		
	virtual void Load(ifstream &Infil,CFigure*&);
};

#endif