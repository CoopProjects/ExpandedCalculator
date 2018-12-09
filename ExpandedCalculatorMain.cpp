/***************************************************************
 * Name:      ExpandedCalculatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    CoopProjects
 * Created:   2018-12-09
 * Copyright: CoopProjects
 * License:
 **************************************************************/

#include "ExpandedCalculatorMain.h"
#include <wx/msgdlg.h>
#include "tinyexpr.h"

//(*InternalHeaders(ExpandedCalculatorFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ExpandedCalculatorFrame)
const long ExpandedCalculatorFrame::ID_TEXTCTRL1 = wxNewId();
const long ExpandedCalculatorFrame::ID_TEXTCTRL2 = wxNewId();
const long ExpandedCalculatorFrame::ID_BUTTON2 = wxNewId();
const long ExpandedCalculatorFrame::idMenuQuit = wxNewId();
const long ExpandedCalculatorFrame::idMenuAbout = wxNewId();
const long ExpandedCalculatorFrame::ID_STATUSBAR1 = wxNewId();
const long ExpandedCalculatorFrame::ID_PROGRESSDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ExpandedCalculatorFrame,wxFrame)
    //(*EventTable(ExpandedCalculatorFrame)
    //*)
END_EVENT_TABLE()

ExpandedCalculatorFrame::ExpandedCalculatorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ExpandedCalculatorFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Equation"), wxPoint(32,48), wxSize(224,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Output"), wxPoint(80,96), wxSize(176,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->SetForegroundColour(wxColour(0,0,0));
    TextCtrl2->SetBackgroundColour(wxColour(255,146,37));
    Button2 = new wxButton(this, ID_BUTTON2, _("Calculate"), wxPoint(280,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    	printDialogData_1 = new wxPrintDialogData;
    PrintDialog1 = new wxPrintDialog(this, printDialogData_1);

    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ExpandedCalculatorFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ExpandedCalculatorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ExpandedCalculatorFrame::OnAbout);
    //*)
}

ExpandedCalculatorFrame::~ExpandedCalculatorFrame()
{
    //(*Destroy(ExpandedCalculatorFrame)
    //*)
}

void ExpandedCalculatorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ExpandedCalculatorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ExpandedCalculatorFrame::OnButton2Click(wxCommandEvent& event)
{
    wxString Input = TextCtrl1->GetValue();

    const char* eqInput = Input.mb_str();

    double result = te_interp(eqInput,0);


    wxString output = wxString::Format(wxT("%f"),result);

    TextCtrl2->SetValue(output);
    //wxMessageBox(output);

}
