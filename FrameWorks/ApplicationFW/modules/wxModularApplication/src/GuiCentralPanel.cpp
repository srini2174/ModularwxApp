///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "PrivateHeaders/GuiCentralPanel.h"

///////////////////////////////////////////////////////////////////////////

GuiCentralPanel::GuiCentralPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* m_Sizer1;
	m_Sizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_grid1 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid1->CreateGrid( 140, 140 );
	m_grid1->EnableEditing( true );
	m_grid1->EnableGridLines( true );
	m_grid1->EnableDragGridSize( false );
	m_grid1->SetMargins( 0, 0 );
	
	// Columns
	m_grid1->AutoSizeColumns();
	m_grid1->EnableDragColMove( true );
	m_grid1->EnableDragColSize( true );
	m_grid1->SetColLabelSize( 30 );
	m_grid1->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid1->AutoSizeRows();
	m_grid1->EnableDragRowSize( true );
	m_grid1->SetRowLabelSize( 80 );
	m_grid1->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid1->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_Sizer1->Add( m_grid1, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( m_Sizer1 );
	this->Layout();
}

GuiCentralPanel::~GuiCentralPanel()
{
}
