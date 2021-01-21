#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1350;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = LIGHTGOLDENRODYELLOW;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	UI.FilledOrNot=false;


	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);


	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ChangeDrawCol(color P)
{
	UI.DrawColor=P;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Output::ChangeFillCol(color PF)
{
	UI.FillColor=PF;
}
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	//Clear Tool bar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, -UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem

	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Square.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Line.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Circle.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Rhombus.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Bluefinal.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Redfinal.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\Whitefinal.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Greenfinal.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Blackfinal.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\DrawColor.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\FillColor.jpg";
	MenuItemImages[ITM_TOPLAY] = "images\\MenuItems\\ToPlay.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_SAVE2] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";



	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	//Clearing the DrawToolBar
	ClearToolBar();


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_BYSHAPE] = "images\\MenuItems\\Byshape.jpg";
	MenuItemImages[ITM_BYCOLOR] = "images\\MenuItems\\bycolor.jpg";
	MenuItemImages[ITM_TODRAW] = "images\\MenuItems\\Todraw.jpg";
	MenuItemImages[ITM_EXIT1] = "images\\MenuItems\\Exit.jpg";
	///TODO: write code to create Play mode menu
		
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//
void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (UI.FilledOrNot)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
///////////////////////////////////////////////////////////////////////////////////////
void Output::DrawTri(Point P1, Point P2,Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (UI.FilledOrNot)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x ,P3.y, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawEll(Point P1,GfxInfo ELLIPSEGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ELLIPSEGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (UI.FilledOrNot)
	{
		style = FILLED;
		pWind->SetBrush(ELLIPSEGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point P2;
	Point P3;
	P2.x = P1.x - 100;
	P2.y = P1.y + 50;
	P3.x = P1.x + 100;
	P3.y = P1.y - 50;
	pWind->DrawEllipse(P2.x, P2.y,P3.x,P3.y, style);

}
Output::~Output()
{
	delete pWind;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawLine(Point P1, Point P2, GfxInfo LiGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LiGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (LiGfxInfo.isFilled==true)
	{
		style = FILLED;
		pWind->SetBrush(LiGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawRhombus(Point P1,GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (UI.FilledOrNot)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	//Creating four points from one point:
	int arrx[4];
	int arry[4];


	arrx[0] = P1.x+50;
	arrx[1] = P1.x;
	arrx[2] = P1.x-50;
	arrx[3] = P1.x;

	arry[0] = P1.y;
	arry[1] = P1.y + 100;
	arry[2] = P1.y;
	arry[3] = P1.y - 100;
	pWind->DrawPolygon(arrx, arry, 4, style);

}