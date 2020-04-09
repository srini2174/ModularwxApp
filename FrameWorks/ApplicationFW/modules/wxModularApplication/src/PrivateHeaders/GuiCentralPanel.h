///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUICENTRALWINDOW_H__
#define __GUICENTRALWINDOW_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GuiCentralPanel
///////////////////////////////////////////////////////////////////////////////
class GuiCentralPanel : public wxPanel 
{
	private:
	
	protected:
		wxGrid* m_grid1;
	
	public:
		
		GuiCentralPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~GuiCentralPanel();
	
};

#endif //__GUICENTRALWINDOW_H__
