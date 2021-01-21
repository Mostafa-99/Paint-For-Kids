#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "Figures/CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CheckPoint(int x, int y) const;			//Check if the point is inside the figure
	virtual void PrintInfo(Output* pOut) const;				//Print the info of the shape
	virtual GfxInfo Get_Graphics_Info();					//Get gfx info
	virtual CFigure*NewSameShape();							//Create a typical shape from the calling object
	virtual void Shift(int x,int y);						//Shift the centre of the shape
	virtual Point GetCent()const;							//Get the centre of the shape
	virtual void Save(ofstream &OutFile);				
	virtual void Load(ifstream &Infil,CFigure*&);
};

#endif