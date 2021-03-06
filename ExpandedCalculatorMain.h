/***************************************************************
 * Name:      ExpandedCalculatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    CoopProjects
 * Created:   2018-12-09
 * Copyright: CoopProjects
 * License:
 **************************************************************/

#ifndef EXPANDEDCALCULATORMAIN_H
#define EXPANDEDCALCULATORMAIN_H

//(*Headers(ExpandedCalculatorFrame)
#include <wx/progdlg.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/printdlg.h>
//*)

class ExpandedCalculatorFrame: public wxFrame
{
    public:

        ExpandedCalculatorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ExpandedCalculatorFrame();

    private:

        //(*Handlers(ExpandedCalculatorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(ExpandedCalculatorFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_PROGRESSDIALOG1;
        //*)

        //(*Declarations(ExpandedCalculatorFrame)
        wxStatusBar* StatusBar1;
        wxProgressDialog* ProgressDialog1;
        wxButton* Button2;
        wxPrintDialogData  *printDialogData_1;
        wxTextCtrl* TextCtrl1;
        wxPrintDialog* PrintDialog1;
        wxTextCtrl* TextCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // EXPANDEDCALCULATORMAIN_H
