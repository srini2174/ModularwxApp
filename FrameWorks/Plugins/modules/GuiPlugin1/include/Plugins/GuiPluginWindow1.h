/////////////////////////////////////////////////////////////////////////////
// Name:        GuiPluginWindow1.h
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     10/09/2013 00:01:49
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _GuiPluginWindow1_H_
#define _GuiPluginWindow1_H_


/*!
 * Includes
 */

////@begin includes
#include "windowBaseImpl/wxGuiPluginWindowBase.h"
#include "windowBaseImpl/GuiCustomEvent.h"
#include "./GuiPlugin1dllExp.h"
////@end includes


/*!
 * Forward declarations
 */

////@begin forward declarations
class wxGuiPluginBase;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_GuiPluginWindow1 10000
#define ID_SAMPLE_TEXTCTRL 10001
#define ID_SEND_EVENT_BUTTON 10002
#define SYMBOL_GuiPluginWindow1_STYLE wxTAB_TRAVERSAL
#define SYMBOL_GuiPluginWindow1_TITLE _("GuiPluginWindow1")
#define SYMBOL_GuiPluginWindow1_IDNAME ID_GuiPluginWindow1
#define SYMBOL_GuiPluginWindow1_SIZE wxSize(400, 300)
#define SYMBOL_GuiPluginWindow1_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * GuiPluginWindow1 class declaration
 */

class WXDLLIMPEXP_GUI1 GuiPluginWindow1: public wxGuiPluginWindowBase
{    
    DECLARE_DYNAMIC_CLASS( GuiPluginWindow1 )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    GuiPluginWindow1();
    GuiPluginWindow1(wxGuiPluginBase * plugin, wxWindow* parent, 
                        wxWindowID id = SYMBOL_GuiPluginWindow1_IDNAME, 
                        const wxPoint& pos = SYMBOL_GuiPluginWindow1_POSITION, 
                        const wxSize& size = SYMBOL_GuiPluginWindow1_SIZE, 
                        long style = SYMBOL_GuiPluginWindow1_STYLE );

    /// Creation
    bool Create(wxGuiPluginBase * plugin, wxWindow* parent, 
                wxWindowID id = SYMBOL_GuiPluginWindow1_IDNAME, 
                const wxPoint& pos = SYMBOL_GuiPluginWindow1_POSITION, 
                const wxSize& size = SYMBOL_GuiPluginWindow1_SIZE, 
                long style = SYMBOL_GuiPluginWindow1_STYLE );

    /// Destructor
    ~GuiPluginWindow1();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    virtual void CreateControls();

////@begin GuiPluginWindow1 event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SEND_EVENT_BUTTON
    void OnSENDEVENTBUTTONClick( wxCommandEvent& event );

////@end GuiPluginWindow1 event handler declarations

////@begin GuiPluginWindow1 member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end GuiPluginWindow1 member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin GuiPluginWindow1 member variables
    wxTextCtrl* m_SamppleTextCtrl;
////@end GuiPluginWindow1 member variables
};

#endif
    // _GuiPluginWindow1_H_
