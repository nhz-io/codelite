#ifndef WXCRAFTER_H
#define WXCRAFTER_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/splitter.h>
#include <wx/panel.h>
#include <wx/checklst.h>
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/button.h>

class SvnCommitDialogBaseClass : public wxDialog
{
protected:
    wxStaticText* m_staticText32;
    wxTextCtrl* m_textCtrlFrID;
    wxStaticText* m_staticTextBugID;
    wxTextCtrl* m_textCtrlBugID;
    wxSplitterWindow* m_splitter1;
    wxPanel* m_panel1;
    wxStaticText* m_staticText17;
    wxCheckListBox* m_checkListFiles;
    wxPanel* m_splitterPage14;
    wxStaticText* m_staticText19;
    wxTextCtrl* m_textCtrlMessage;
    wxChoice* m_choiceMessages;
    wxButton* m_button3;
    wxButton* m_button4;

protected:

public:
    SvnCommitDialogBaseClass(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Svn Commit"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~SvnCommitDialogBaseClass();
};

#endif
