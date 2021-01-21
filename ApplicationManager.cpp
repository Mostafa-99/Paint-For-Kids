#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddTriAction.h"
#include "AddLineAction.h"
#include "AddRhombusAction.h"
#include "AddEllAction.h"
#include "CEllipse.h"
#include "Figures\CRectangle.h"
#include "SelectAction.h"
#include "ExitAction.h"
#include "ToPlay.h"
#include "ToDraw.h"
#include "ChangeOutline.h"
#include "Delete.h"
#include "ChangeFill.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "CopyAction.h"
#include "CTriangle.h"
#include "CRhombus.h"
#include "CLine.h"
#include "ByFigure.h"
#include "ByColor.h"
#include "Save.h"
#include "SaveByType.h"
#include "Load.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig=NULL;
	Clipboard=NULL;
	RemovedCounter=0;
	FigCount = 0;
	CutF=NULL;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
void ApplicationManager::AddRemoved()
{
	for (int i=0;i<(FigCount);i++)
	{
		if(FigList[i]->GetRemoved())
		{
			FigList[i]->SetRemoved(false);
		}
	}
}
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case EXIT:
			pAct = new ExitAction(this);
			break;

		case TO_PLAY:
			pAct = new ToPlay(this);
			break;

		case TO_DRAW:
			pAct = new ToDraw(this);
			break;

		case CHNG_DRAW_CLR:
			pAct = new ChangeOutline(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new ChangeFill(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;

		case CUT:
			pAct = new CutAction(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;
		
		case PASTE:
			pAct = new PasteAction(this);
			break;

		case ByShape:
			pAct = new ByFigure(this);
			break;

		case ByColor:
			pAct = new By_Color(this);
			break;

		case SAVE:
			pAct = new Save(this);
			break;

		case SAVE_BY_TYPE:
			pAct = new SaveByType(this);
			break;

		case LOAD:
			pAct = new Load(this);
			break;

		case STATUS://a click on the status bar ==> no action
			return;

	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
void ApplicationManager::ClearArray()
{
	for (int i=0; i< FigCount; i++)
	{
		delete FigList[i];
	}
	FigCount = 0;
	pOut->ClearDrawArea();
}
//Get number of the figures with the same color passed
int ApplicationManager::GetNumberOfColored(color P)
{
	int c=0;

	for (int i=0;i<FigCount;i++)
	{
		if (FigList[i]->Get_Graphics_Info().FillClr==P)
		{
			c++;
		}
	}
	return c;
}
//Get number of figures from the same type
int ApplicationManager::GetNumberOfFigures(CFigure*x)
{
	int c=0;
	CRectangle*Rect=dynamic_cast<CRectangle*>(x);
	CLine*Line=dynamic_cast<CLine*>(x);
	CTriangle*Tri=dynamic_cast<CTriangle*>(x);
	CEllipse*Ell=dynamic_cast<CEllipse*>(x);
	CRhombus*Rho=dynamic_cast<CRhombus*>(x);
	if (Rect!=NULL)
	{
		for (int i=0;i<(FigCount);i++)
		{
			CRectangle*Dummy=dynamic_cast<CRectangle*>(FigList[i]);
				if (Dummy!=NULL)
				{
					c++;
				}
		}
	}
	else if(Line!=NULL)
	{
		for (int i=0;i<(FigCount);i++)
		{
			CLine*Dummy=dynamic_cast<CLine*>(FigList[i]);
				if (Dummy!=NULL)
				{
					c++;
				}
		}
	}
	else if(Tri!=NULL)
	{
		for (int i=0;i<(FigCount);i++)
		{
			CTriangle*Dummy=dynamic_cast<CTriangle*>(FigList[i]);
				if (Dummy!=NULL)
				{
					c++;
				}
		}
	}
	else if(Ell!=NULL)
	{
		for (int i=0;i<(FigCount);i++)
		{
			CEllipse*Dummy=dynamic_cast<CEllipse*>(FigList[i]);
				if (Dummy!=NULL)
				{
					c++;
				}
		}
	}
	else if(Rho!=NULL)
	{
		for (int i=0;i<(FigCount);i++)
		{
			CRhombus*Dummy=dynamic_cast<CRhombus*>(FigList[i]);
				if (Dummy!=NULL)
				{
					c++;
				}
		}
	}
	return c;
}
//To get random figure from the figlist
CFigure* ApplicationManager::RandomFigure()
{

	CFigure* RandomFig = FigList[rand()%(FigCount)];
	return RandomFig;

}
//Setter for the selected fig
void ApplicationManager::SetSelectedFig(CFigure*x)
{
	SelectedFig=x;
}
//Getter for the seleceted fig
CFigure*ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}
//Setter for the clipboard
void ApplicationManager::SetClipBoard(CFigure*y)
{
	Clipboard=y;
}
//Getter for the clipboard
CFigure*ApplicationManager::GetClipboard()
{
	return Clipboard;
}
void ApplicationManager::SetCutF(CFigure*x)
{
	CutF=x;
}
CFigure*ApplicationManager::GetCutF()
{
	return CutF;

}
//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
		FigList[FigCount++] = pFig;
	}
	if(FigCount==1)
	{
		FigList[FigCount-1]->Set_ID(1);
	}
	else
	{
		FigList[FigCount-1]->Set_ID(FigList[FigCount-2]->Get_ID()+1);
	}

}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	CFigure* Ptr;
	for (int i=FigCount; i>0; i--)
	{
			if (FigList[i-1]->CheckPoint(x,y)==true)
			{
				Ptr=FigList[i-1];
				return  Ptr;
			}
		
	}
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
void ApplicationManager::Savewindow(ofstream &text)
{
	/*pOut->PrintMessage("type the file name!");
	ofstream text(pIn->GetSrting(pOut)+".txt");*/

	text << FigCount << endl;;

	for (int i = 0; i < FigCount; i++)
	{

		FigList[i]->Save(text);


	}text.close();
}
void ApplicationManager::SaveType(ofstream &text, int ClickedItem)
{
	/*pOut->PrintMessage("type the file name!");
	ofstream text(	pIn->GetSrting(pOut)+".txt");*/
	int ell = 0; int rhom = 0; int tri = 0; int line = 0; int rect = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CFigure *c;
		if (ClickedItem == 0)
		{
			c = dynamic_cast<CRectangle *>(FigList[i]);
			if (c != NULL)
			{
				rect++;
			}
		}
		else if (ClickedItem == 1)
		{
			c = dynamic_cast<CLine *>(FigList[i]);
			if (c != NULL)
			{
				line++;
			}
		}
		else if (ClickedItem == 2)
		{
			c = dynamic_cast<CTriangle *>(FigList[i]);
			if (c != NULL)
			{
				tri++;
			}
		}
		else if (ClickedItem == 3)
		{
			c = dynamic_cast<CEllipse *>(FigList[i]);
			if (c != NULL)
			{
				ell++;
			}
		}
		else if (ClickedItem == 4)
		{
			c = dynamic_cast<CRhombus *>(FigList[i]);
			if (c != NULL)
			{
				rhom++;
			}
		}

	}
	/*CFigure *c;
	text << c->GetFColorString() << " " << c->GetDColorString() << endl;*/
	if (ell != 0) { text << ell; }
	else if (line != 0) { text << line; }
	else if (tri != 0) { text << tri; }
	else if (rhom != 0) { text << rhom; }
	else if (rect != 0) { text << rect; }
	for (int i = 0; i < FigCount; i++)
	{
		CFigure *c;
		if (ClickedItem == 0)
		{
			c = dynamic_cast<CRectangle *>(FigList[i]);
			if (c != NULL)
			{
				FigList[i]->Save(text);
			}
		}
		else if (ClickedItem == 1)
		{
			c = dynamic_cast<CLine *>(FigList[i]);
			if (c != NULL)
			{
				FigList[i]->Save(text);
			}
		}
		else if (ClickedItem == 2)
		{
			c = dynamic_cast<CTriangle *>(FigList[i]);
			if (c != NULL)
			{
				FigList[i]->Save(text);
			}
		}
		else if (ClickedItem == 3)
		{
			c = dynamic_cast<CEllipse *>(FigList[i]);
			if (c != NULL)
			{
				FigList[i]->Save(text);
			}
		}
		else if (ClickedItem == 4)
		{
			c = dynamic_cast<CRhombus *>(FigList[i]);
			if (c != NULL)
			{
				FigList[i]->Save(text);
			}
		}

	}
	text.close();
}
//Delete selected figure
void ApplicationManager::DelFigure(CFigure * Pfig)
{
	
	int x=0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Pfig)
		{
			x=i;
			delete Pfig;
			for (int j = x; j < FigCount; j++)
			{
			FigList[j] = FigList[j+1];
			}
			FigCount--;
			break;
		}
	}
	pOut->ClearDrawArea();
	UpdateInterface();
}
void ApplicationManager::RemoveCutFigure()
{
	int x=0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetStatus()==2)
		{
			x=i;
			delete FigList[i];
			for (int j = x; j < FigCount; j++)
			{
			FigList[j] = FigList[j+1];
			}
			FigCount--;
			break;
		}
	}
	pOut->ClearDrawArea();
	UpdateInterface();
}
//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
	{
		if (FigList[i]->GetRemoved()!=true)
		{
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	if (Clipboard!=NULL)
		delete Clipboard;
	delete pIn;
	delete pOut;
}
