/////////////////////////////////////////////////////////////////////////////
// Name:        GuiPluginWindow2.cpp
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

#include "Plugins/GuiPluginWindow2.h"
#include "PluginItf/wxGuiPluginBase.h"

////@begin XPM images
////@end XPM images


/*
 * GuiPluginWindow2 type definition
 */

IMPLEMENT_DYNAMIC_CLASS( GuiPluginWindow2, wxGuiPluginWindowBase )
/*
 * GuiPluginWindow2 event table definition
 */

BEGIN_EVENT_TABLE( GuiPluginWindow2, wxGuiPluginWindowBase )

////@begin GuiPluginWindow2 event table entries
    EVT_WINDOW_DESTROY( GuiPluginWindow2::OnDestroy )
////@end GuiPluginWindow2 event table entries

END_EVENT_TABLE()


/*
 * GuiPluginWindow2 constructors
 */

GuiPluginWindow2::GuiPluginWindow2()
{
    Init();
}

GuiPluginWindow2::GuiPluginWindow2( wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(plugin, parent, id, pos, size, style);
}


/*
 * GuiPluginWindow2 creator
 */

bool GuiPluginWindow2::Create( wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    wxGuiPluginWindowBase::Create(plugin, parent, id, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
    return true;
}


/*
 * GuiPluginWindow2 destructor
 */

GuiPluginWindow2::~GuiPluginWindow2()
{
////@begin GuiPluginWindow2 destruction
////@end GuiPluginWindow2 destruction
}


/*
 * Member initialisation
 */

void GuiPluginWindow2::Init()
{
////@begin GuiPluginWindow2 member initialisation
    m_MessageTextCtrl = NULL;
////@end GuiPluginWindow2 member initialisation
}


/*
 * Control creation for GuiPluginWindow2
 */

void GuiPluginWindow2::CreateControls()
{    
////@begin GuiPluginWindow2 content construction
    GuiPluginWindow2* itemGuiPluginWindowBase1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemGuiPluginWindowBase1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemGuiPluginWindowBase1, wxID_STATIC, _("This text box receives messages from GUI Plugin 1:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_MessageTextCtrl = new wxTextCtrl( itemGuiPluginWindowBase1, ID_GUI_PLUGIN2_MESSAGE_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer2->Add(m_MessageTextCtrl, 0, wxGROW|wxALL, 5);

    // Connect events and objects
    itemGuiPluginWindowBase1->Connect(ID_GUIPLUGINWINDOW2, wxEVT_DESTROY, wxWindowDestroyEventHandler(GuiPluginWindow2::OnDestroy), NULL, this);
////@end GuiPluginWindow2 content construction
	GetPlugin()->GetEventHandler()->Bind(wxEVT_GUI_PLUGIN_INTEROP, 
		wxCommandEventHandler(GuiPluginWindow2::OnInteropMessageReceived), this);
}


/*
 * Should we show tooltips?
 */

bool GuiPluginWindow2::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap GuiPluginWindow2::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin GuiPluginWindow2 bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end GuiPluginWindow2 bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon GuiPluginWindow2::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin GuiPluginWindow2 icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end GuiPluginWindow2 icon retrieval
}

void GuiPluginWindow2::OnInteropMessageReceived(wxCommandEvent & event)
{
	m_MessageTextCtrl->SetValue(event.GetString());
}


/*
 * wxEVT_DESTROY event handler for ID_GUIPLUGINWINDOW2
 */

void GuiPluginWindow2::OnDestroy( wxWindowDestroyEvent& event )
{
	GetPlugin()->GetEventHandler()->Unbind(wxEVT_GUI_PLUGIN_INTEROP,
		wxCommandEventHandler(GuiPluginWindow2::OnInteropMessageReceived), this);
////@begin wxEVT_DESTROY event handler for ID_GUIPLUGINWINDOW2 in GuiPluginWindow2.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_DESTROY event handler for ID_GUIPLUGINWINDOW2 in GuiPluginWindow2. 
}

