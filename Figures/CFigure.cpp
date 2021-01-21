#include "CFigure.h"
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Status=0;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::SetStatus(int x)
{
	Status=x;
}
int CFigure::GetStatus()const
{
	return Status;
}
void CFigure::Set_ID(int d)
{
	ID=d;
}
int CFigure::Get_ID()const
{
	return ID;
}
string CFigure::GetFColorString(color a)
{
	string B;
	if (a==RED)
	{
		B="RED";
	}
	else if(a==BLUE)
	{
		B="BLUE";
	}
	else if(a==WHITE)
	{
		B="WHITE";
	}
	else if(a==GREEN)
	{
		B="GREEN";
	}
	else if(a==BLACK)
	{
		B="BLACK";
	}
	else 
	{
		B="NO_FILL";
	}
	return B;
}
string CFigure::GetDColorString(color a)
{
	string A;
	if (a==RED)
	{
		A="RED";
	}
	else if(a==BLUE)
	{
		A="BLUE";
	}
	else if(a==WHITE)
	{
		A="WHITE";
	}
	else if(a==GREEN)
	{
		A="GREEN";
	}
	else if(a==BLACK)
	{
		A="BLACK";
	}
	return A;

}
color CFigure::SetFColorFromString(string B)
{
	color A;
	if (B=="RED")
	{
		A=RED;
	}
	else if(B=="BLUE")
	{
		A=BLUE;
	}
	else if(B=="WHITE")
	{
		A=WHITE;
	}
	else if(B=="GREEN")
	{
		A=GREEN;
	}
	else if(B=="BLACK")
	{
		A=BLACK;
	}
	FigGfxInfo.FillClr=A;
	return A;
}
color CFigure::SetDColorFromString(string B)
{
	color A;
	if (B=="RED")
	{
		A=RED;
	}
	else if(B=="BLUE")
	{
		A=BLUE;
	}
	else if(B=="WHITE")
	{
		A=WHITE;
	}
	else if(B=="GREEN")
	{
		A=GREEN;
	}
	else if(B=="BLACK")
	{
		A=BLACK;
	}
	FigGfxInfo.DrawClr=A;
	return A;
}
void CFigure::SetRemoved(bool x)
{
	Removed=x;
}
bool CFigure::GetRemoved()
{
	return Removed;
}
