/***************************************************************
 * Name:      ExpandedCalculatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    CoopProjects
 * Created:   2018-12-09
 * Copyright: CoopProjects
 * License:
 **************************************************************/

#include "ExpandedCalculatorApp.h"

//(*AppHeaders
#include "ExpandedCalculatorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ExpandedCalculatorApp);

bool ExpandedCalculatorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ExpandedCalculatorFrame* Frame = new ExpandedCalculatorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
