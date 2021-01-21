#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	int Status; //If 1 means copied, If 2 means cut.
	bool Removed;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool CheckPoint(int x, int y) const  = 0 ;   //CheckPoint in or out
	virtual GfxInfo Get_Graphics_Info()=0;				//A getter for the GfXinfo
	virtual int Get_ID()const;							//Getter For ID
	void SetStatus(int);								//Setter for the status
	int GetStatus()const;								//Getter for the status
	void Set_ID(int d);									//Setter for the ID
	virtual CFigure*NewSameShape()=0;					//Creates a typical copy from the calling figure without drawing it		
	virtual void Shift(int x, int y)=0;					//Shift the centre of the calling figure
	virtual Point GetCent()const=0;						//Get the centre of the calling figure
	void SetRemoved(bool);								//Settter for the removed
	bool GetRemoved();									//Getter for the removed
	
	string GetFColorString(color);							
	string GetDColorString(color);
	color SetFColorFromString(string);
	color SetDColorFromString(string);

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color




	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile,CFigure*&) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut)const = 0;	//print all figure info on the status bar
};

#endif