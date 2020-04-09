/////////////////////////////////////////////////////////////////////////////
// Name:        MainFrame.cpp
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     02/08/2013 21:20:05
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "Common/stdwx.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/imaglist.h"
////@end includes

#include "PrivateHeaders/MainFrame.h"
#include "PrivateHeaders/wxModularHostApp.h"
#include "PrivateHeaders/ReferencePluginManager.h"

////@begin XPM images
////@end XPM images


/*
 * MainFrame type definition
 */

IMPLEMENT_CLASS( MainFrame, wxFrame )


/*
 * MainFrame event table definition
 */

BEGIN_EVENT_TABLE( MainFrame, wxFrame )

////@begin MainFrame event table entries
////@end MainFrame event table entries

END_EVENT_TABLE()


/*
 * MainFrame constructors
 */

MainFrame::MainFrame()
{
    Init();
}

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, 
                    const wxString& caption, const wxPoint& pos, 
                    const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*
 * MainFrame creator
 */

bool MainFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin MainFrame creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();
////@end MainFrame creation
    return true;
}


/*
 * MainFrame destructor
 */

MainFrame::~MainFrame()
{
////@begin MainFrame destruction
    GetAuiManager().UnInit();
////@end MainFrame destruction
}


/*
 * Member initialisation
 */

void MainFrame::Init()
{
////@begin MainFrame member initialisation
    m_CentrePane = NULL;
////@end MainFrame member initialisation
}


/*
 * Control creation for MainFrame
 */

void MainFrame::CreateControls()
{    
////@begin MainFrame content construction
    MainFrame* itemFrame1 = this;
    GetAuiManager().SetManagedWindow(this);
    GetAuiManager().SetFlags(wxAUI_MGR_DEFAULT);

    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* itemMenu4 = new wxMenu;
    itemMenu4->Append(wxID_EXIT, _("Exit\tAlt+F4"), wxEmptyString, wxITEM_NORMAL);
    menuBar->Append(itemMenu4, _("File"));
    itemFrame1->SetMenuBar(menuBar);

    wxStatusBar* itemStatusBar2 = new wxStatusBar( itemFrame1, ID_STATUSBAR, wxST_SIZEGRIP|wxNO_BORDER );
    itemStatusBar2->SetFieldsCount(2);
    itemFrame1->SetStatusBar(itemStatusBar2);

	m_CentrePane = new GuiCentralPanel( this, ID_AUINOTEBOOK, wxDefaultPosition, wxDefaultSize, 0 );

    itemFrame1->GetAuiManager().AddPane(m_CentrePane, wxAuiPaneInfo()
        .Name(_T("Pane1")).Centre().CaptionVisible(true).CloseButton(false).DestroyOnClose(true).Resizable(true).Floatable(true));

	AddPagesFromGuiPlugins();

    GetAuiManager().Update();

////@end MainFrame content construction
}


/*
 * Should we show tooltips?
 */

bool MainFrame::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap MainFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin MainFrame bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end MainFrame bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon MainFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin MainFrame icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end MainFrame icon retrieval
}

void MainFrame::AddPagesFromGuiPlugins()
{
	ReferencePluginManager * pluginManager = wxGetApp().GetPluginManager();
    for(wxGuiPluginBaseList::Node * node = pluginManager->GetGuiPlugins().GetFirst();
        node; node = node->GetNext())
    {
        wxGuiPluginBase * plugin = node->GetData();
        if(plugin)
        {
           wxWindow * page = NULL;
           page = plugin->CreatePanel(this);
           if(NULL != page)
           {
	            this->GetAuiManager().AddPane( page, wxAuiPaneInfo() .Left() .PinButton( true ).Dock().Resizable().FloatingSize( wxDefaultSize ) );
           }
        }
    }
}
