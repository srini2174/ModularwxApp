/////////////////////////////////////////////////////////////////////////////
// Name:        GuiPluginWindow1.cpp
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     10/09/2013 00:01:49
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
//#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "Plugins/GuiPluginWindow1.h"
#include "PluginItf/wxGuiPluginBase.h"

////@begin XPM images
////@end XPM images


/*
 * GuiPluginWindow1 type definition
 */

IMPLEMENT_DYNAMIC_CLASS( GuiPluginWindow1, wxGuiPluginWindowBase )
/*
 * GuiPluginWindow1 event table definition
 */

BEGIN_EVENT_TABLE( GuiPluginWindow1, wxGuiPluginWindowBase )

////@begin GuiPluginWindow1 event table entries
    EVT_BUTTON( ID_SEND_EVENT_BUTTON, GuiPluginWindow1::OnSENDEVENTBUTTONClick )
////@end GuiPluginWindow1 event table entries

END_EVENT_TABLE()


/*
 * GuiPluginWindow1 constructors
 */

GuiPluginWindow1::GuiPluginWindow1()
{
    Init();
}

GuiPluginWindow1::GuiPluginWindow1( wxGuiPluginBase * plugin, 
											   wxWindow* parent, wxWindowID id, 
											   const wxPoint& pos, const wxSize& size, 
											   long style )
{
    Init();
    Create(plugin, parent, id, pos, size, style);
}


/*
 * GuiPluginWindow1 creator
 */

bool GuiPluginWindow1::Create(wxGuiPluginBase * plugin, 
									wxWindow* parent, wxWindowID id, 
									const wxPoint& pos, const wxSize& size, 
									long style )
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
 * GuiPluginWindow1 destructor
 */

GuiPluginWindow1::~GuiPluginWindow1()
{
////@begin GuiPluginWindow1 destruction
////@end GuiPluginWindow1 destruction
}


/*
 * Member initialisation
 */

void GuiPluginWindow1::Init()
{
////@begin GuiPluginWindow1 member initialisation
    m_SamppleTextCtrl = NULL;
////@end GuiPluginWindow1 member initialisation
}


/*
 * Control creation for GuiPluginWindow1
 */

void GuiPluginWindow1::CreateControls()
{    
////@begin GuiPluginWindow1 content construction
    GuiPluginWindow1* itemGuiPluginWindowBase1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemGuiPluginWindowBase1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemGuiPluginWindowBase1, wxID_STATIC, _("Enter some text here:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SamppleTextCtrl = new wxTextCtrl( itemGuiPluginWindowBase1, ID_SAMPLE_TEXTCTRL, _("Hello, GUI Plugin 2!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(m_SamppleTextCtrl, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    wxButton* itemButton5 = new wxButton( itemGuiPluginWindowBase1, ID_SEND_EVENT_BUTTON, _("Send event"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemButton5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end GuiPluginWindow1 content construction
}


/*
 * Should we show tooltips?
 */

bool GuiPluginWindow1::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap GuiPluginWindow1::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin GuiPluginWindow1 bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end GuiPluginWindow1 bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon GuiPluginWindow1::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin GuiPluginWindow1 icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end GuiPluginWindow1 icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SEND_EVENT_BUTTON
 */

void GuiPluginWindow1::OnSENDEVENTBUTTONClick( wxCommandEvent& event )
{
	wxCommandEvent e(wxEVT_GUI_PLUGIN_INTEROP);
	e.SetString(m_SamppleTextCtrl->GetValue());
	GetPlugin()->GetEventHandler()->AddPendingEvent(e);

////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SEND_EVENT_BUTTON in GuiPluginWindow1.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SEND_EVENT_BUTTON in GuiPluginWindow1. 
}

