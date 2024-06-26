///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class TimerFrameBase
///////////////////////////////////////////////////////////////////////////////
class TimerFrameBase : public wxFrame
{
	private:

	protected:
		wxTextCtrl* m_timerTextCtrl;
		wxButton* m_button1;
		wxButton* m_button2;

		// Virtual event handlers, override them in your derived class
		virtual void OnTimerStart( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimerStop( wxCommandEvent& event ) { event.Skip(); }


	public:

		TimerFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Timer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~TimerFrameBase();

};

