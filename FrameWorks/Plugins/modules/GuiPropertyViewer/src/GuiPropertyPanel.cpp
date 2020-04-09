/////////////////////////////////////////////////////////////////////////////
// Name:        GuiPropertyPanel.cpp
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     18/09/2013 22:40:39
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#ifdef WX_PRECOMP
#include "wx/wxprec.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "Plugins/GuiPropertyPanel.h"
#include "PluginItf/wxGuiPluginBase.h"

////@begin XPM images
////@end XPM images


/*
 * GuiPropertyPanel type definition
 */

IMPLEMENT_DYNAMIC_CLASS( GuiPropertyPanel, wxGuiPluginWindowBase )
/*
 * GuiPropertyPanel event table definition
 */

BEGIN_EVENT_TABLE( GuiPropertyPanel, wxGuiPluginWindowBase )

////@begin GuiPropertyPanel event table entries
    EVT_WINDOW_DESTROY( GuiPropertyPanel::OnDestroy )
////@end GuiPropertyPanel event table entries

END_EVENT_TABLE()


/*
 * GuiPropertyPanel constructors
 */

GuiPropertyPanel::GuiPropertyPanel()
{
    Init();
}

GuiPropertyPanel::GuiPropertyPanel( wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
   Init();
   Create(plugin, parent, id, pos, size, style);
}


/*
 * GuiPropertyPanel creator
 */

bool GuiPropertyPanel::Create( wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    wxGuiPluginWindowBase::Create(plugin, parent, id, pos, size, style );

    CreateControls(parent);
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
    return true;
}


/*
 * GuiPropertyPanel destructor
 */

GuiPropertyPanel::~GuiPropertyPanel()
{
////@begin GuiPropertyPanel destruction
////@end GuiPropertyPanel destruction
}


/*
 * Member initialisation
 */

void GuiPropertyPanel::Init()
{
////@begin GuiPropertyPanel member initialisation
    m_treeCtrl1 = NULL;
    m_propertyGrid1 = NULL; 
	m_propertyGridItem1 = NULL;
	m_propertyGridItem2 = NULL;
	m_propertyGridItem3 = NULL;
	m_propertyGridItem4 = NULL;
	m_propertyGridItem5 = NULL;
	m_propertyGridItem6 = NULL;
////@end GuiPropertyPanel member initialisation
}


/*
 * Control creation for GuiPropertyPanel
 */

void GuiPropertyPanel::CreateControls(wxWindow* parent)
{    
////@begin GuiPropertyPanel content construction
    GuiPropertyPanel* itemGuiPluginWindowBase1 = this;

	wxBoxSizer* m_Sizer1;
	m_Sizer1 = new wxBoxSizer( wxVERTICAL );
    
	m_treeListCtrl1 = new wxTreeListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTL_DEFAULT_STYLE );
	m_treeListCtrl1->AppendColumn( wxT("Database"), wxCOL_WIDTH_DEFAULT, wxALIGN_LEFT, wxCOL_RESIZABLE );
	m_Sizer1->Add( m_treeListCtrl1, 1, wxEXPAND | wxALL, 5 );
	
    /*
    m_propertyGrid1 = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	m_propertyGridItem1 = m_propertyGrid1->Append( new wxPropertyCategory( wxT("C++"), wxT("C++") ) ); 
	m_propertyGridItem2 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) ); 
	m_propertyGridItem3 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) ); 
	m_propertyGridItem4 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) ); 
	m_propertyGridItem5 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) ); 
	m_propertyGridItem6 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) ); 
	*/
	this->SetSizer( m_Sizer1 );
	this->Layout();
}


/*
 * Should we show tooltips?
 */

bool GuiPropertyPanel::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap GuiPropertyPanel::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin GuiPropertyPanel bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end GuiPropertyPanel bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon GuiPropertyPanel::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin GuiPropertyPanel icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end GuiPropertyPanel icon retrieval
}

/*
 * wxEVT_DESTROY event handler for ID_GuiPropertyPanel
 */

void GuiPropertyPanel::OnDestroy( wxWindowDestroyEvent& event )
{
//	GetPlugin()->GetEventHandler()->Unbind(wxEVT_GUI_PLUGIN_INTEROP,
//		wxCommandEventHandler(GuiPropertyPanel::OnInteropMessageReceived), this);
////@begin wxEVT_DESTROY event handler for ID_GuiPropertyPanel in GuiPropertyPanel.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_DESTROY event handler for ID_GuiPropertyPanel in GuiPropertyPanel. 
}

