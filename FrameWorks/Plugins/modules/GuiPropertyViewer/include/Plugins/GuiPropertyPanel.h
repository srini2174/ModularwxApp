/////////////////////////////////////////////////////////////////////////////
// Name:        GuiPropertyPanel.h
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     18/09/2013 22:40:39
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _GuiPropertyPanel_H_
#define _GuiPropertyPanel_H_


/*!
 * Includes
 */

////@begin includes
#include "./GuiPVPlugindllExp.h"
#include "windowBaseImpl/wxGuiPluginWindowBase.h"
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/advprops.h>
#include <wx/treelist.h>
#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
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
#define ID_GuiPropertyPanel 15000
#define ID_GUI_PLUGIN2_MESSAGE_TEXTCTRL 15001
#define SYMBOL_GuiPropertyPanel_STYLE wxTAB_TRAVERSAL
#define SYMBOL_GuiPropertyPanel_TITLE _("GuiPropertyPanel")
#define SYMBOL_GuiPropertyPanel_IDNAME ID_GuiPropertyPanel
#define SYMBOL_GuiPropertyPanel_SIZE wxSize(400, 300)
#define SYMBOL_GuiPropertyPanel_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * GuiPropertyPanel class declaration
 */

class WXDLLIMPEXP_GUIPV GuiPropertyPanel: public wxGuiPluginWindowBase
{    
    DECLARE_DYNAMIC_CLASS( GuiPropertyPanel )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    GuiPropertyPanel();
    GuiPropertyPanel( wxGuiPluginBase * plugin, wxWindow* parent, 
							wxWindowID id = SYMBOL_GuiPropertyPanel_IDNAME, 
							const wxPoint& pos = SYMBOL_GuiPropertyPanel_POSITION, 
							const wxSize& size = SYMBOL_GuiPropertyPanel_SIZE, 
							long style = SYMBOL_GuiPropertyPanel_STYLE );

    /// Creation
    bool Create( wxGuiPluginBase * plugin, wxWindow* parent, 
				wxWindowID id = SYMBOL_GuiPropertyPanel_IDNAME, 
				const wxPoint& pos = SYMBOL_GuiPropertyPanel_POSITION, 
				const wxSize& size = SYMBOL_GuiPropertyPanel_SIZE, 
				long style = SYMBOL_GuiPropertyPanel_STYLE );

    /// Destructor
    ~GuiPropertyPanel();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls(wxWindow* parent=NULL);

////@begin GuiPropertyPanel event handler declarations

    /// wxEVT_DESTROY event handler for ID_GuiPropertyPanel
    void OnDestroy( wxWindowDestroyEvent& event );

////@end GuiPropertyPanel event handler declarations
	void OnInteropMessageReceived(wxCommandEvent & event);

////@begin GuiPropertyPanel member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end GuiPropertyPanel member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin GuiPropertyPanel member variables
	protected:
		wxTreeCtrl* m_treeCtrl1;
        wxTreeListCtrl* m_treeListCtrl1;
        wxPropertyGrid* m_propertyGrid1;
		wxPGProperty* m_propertyGridItem1;
		wxPGProperty* m_propertyGridItem2;
		wxPGProperty* m_propertyGridItem3;
		wxPGProperty* m_propertyGridItem4;
		wxPGProperty* m_propertyGridItem5;
		wxPGProperty* m_propertyGridItem6;
////@end GuiPropertyPanel member variables
};

#endif
    // _GuiPropertyPanel_H_
