#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	int RemovedCounter;		//Counter For removed figures while in play mode
	CFigure*CutF;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure*);          //Set the selected figure
	CFigure*GetSelectedFig();				//Get the selected figure
	void SetClipBoard(CFigure*);			//Set the clipboard
	CFigure*GetClipboard();				//Get the clipboard figure			
	CFigure* RandomFigure();			//Get a random figure
	int GetNumberOfFigures(CFigure*);       //Get number of the same type of figure in the list 
	int GetNumberOfColored(color);			//Get number of the figures with the same color passed
	void ClearArray();						//Clear FigList		
	void AddRemoved();					//Toggle Removed to be drawn again
	void SetCutF(CFigure*);
	CFigure*GetCutF();


	// -- Interface Management Functions
	void DelFigure(CFigure * Pfig);      //Remove the sent figure from the list, and re-arrange it
	void Savewindow(ofstream &text);
	void SaveType(ofstream &, int);
	void RemoveCutFigure();				//
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif