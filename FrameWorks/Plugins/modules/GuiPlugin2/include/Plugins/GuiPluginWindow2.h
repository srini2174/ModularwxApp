/////////////////////////////////////////////////////////////////////////////
// Name:        GuiPluginWindow2.h
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     18/09/2013 22:40:39
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _GUIPLUGINWINDOW2_H_
#define _GUIPLUGINWINDOW2_H_


/*!
 * Includes
 */

////@begin includes
#include "./GuiPlugin2dllExp.h"
#include "windowBaseImpl/wxGuiPluginWindowBase.h"
#include "windowBaseImpl/GuiCustomEvent.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_GUIPLUGINWINDOW2 10000
#define ID_GUI_PLUGIN2_MESSAGE_TEXTCTRL 10001
#define SYMBOL_GUIPLUGINWINDOW2_STYLE wxTAB_TRAVERSAL
#define SYMBOL_GUIPLUGINWINDOW2_TITLE _("GuiPluginWindow2")
#define SYMBOL_GUIPLUGINWINDOW2_IDNAME ID_GUIPLUGINWINDOW2
#define SYMBOL_GUIPLUGINWINDOW2_SIZE wxSize(400, 300)
#define SYMBOL_GUIPLUGINWINDOW2_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * GuiPluginWindow2 class declaration
 */

class WXDLLIMPEXP_GUI2 GuiPluginWindow2: public wxGuiPluginWindowBase
{    
    DECLARE_DYNAMIC_CLASS( GuiPluginWindow2 )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    GuiPluginWindow2();
    GuiPluginWindow2( wxGuiPluginBase * plugin, wxWindow* parent, 
							wxWindowID id = SYMBOL_GUIPLUGINWINDOW2_IDNAME, 
							const wxPoint& pos = SYMBOL_GUIPLUGINWINDOW2_POSITION, 
							const wxSize& size = SYMBOL_GUIPLUGINWINDOW2_SIZE, 
							long style = SYMBOL_GUIPLUGINWINDOW2_STYLE );

    /// Creation
    bool Create( wxGuiPluginBase * plugin, wxWindow* parent, 
				wxWindowID id = SYMBOL_GUIPLUGINWINDOW2_IDNAME, 
				const wxPoint& pos = SYMBOL_GUIPLUGINWINDOW2_POSITION, 
				const wxSize& size = SYMBOL_GUIPLUGINWINDOW2_SIZE, 
				long style = SYMBOL_GUIPLUGINWINDOW2_STYLE );

    /// Destructor
    ~GuiPluginWindow2();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin GuiPluginWindow2 event handler declarations

    /// wxEVT_DESTROY event handler for ID_GUIPLUGINWINDOW2
    void OnDestroy( wxWindowDestroyEvent& event );

////@end GuiPluginWindow2 event handler declarations
	void OnInteropMessageReceived(wxCommandEvent & event);

////@begin GuiPluginWindow2 member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end GuiPluginWindow2 member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin GuiPluginWindow2 member variables
    wxTextCtrl* m_MessageTextCtrl;
////@end GuiPluginWindow2 member variables
};

#endif
    // _GUIPLUGINWINDOW2_H_
