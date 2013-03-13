///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WeatherFaxUI.h"

///////////////////////////////////////////////////////////////////////////

WeatherFaxDialogBase::WeatherFaxDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8->AddGrowableCol( 0 );
	fgSizer8->AddGrowableRow( 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	sbFax = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Fax") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer7->AddGrowableCol( 0 );
	fgSizer7->AddGrowableRow( 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxArrayString m_lFaxesChoices;
	m_lFaxes = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_lFaxesChoices, 0 );
	fgSizer7->Add( m_lFaxes, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer16;
	fgSizer16 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer16->SetFlexibleDirection( wxBOTH );
	fgSizer16->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_bCapture = new wxButton( this, wxID_ANY, _("Capture"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer16->Add( m_bCapture, 0, wxALL, 5 );
	
	m_bOpen = new wxButton( this, wxID_ANY, _("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer16->Add( m_bOpen, 0, wxALL, 5 );
	
	m_bEdit = new wxButton( this, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer16->Add( m_bEdit, 0, wxALL, 5 );
	
	m_bDelete = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer16->Add( m_bDelete, 0, wxALL, 5 );
	
	
	fgSizer7->Add( fgSizer16, 1, wxEXPAND, 5 );
	
	
	sbFax->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	
	fgSizer8->Add( sbFax, 1, wxEXPAND, 0 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Transparency") ), wxVERTICAL );
	
	m_sTransparency = new wxSlider( this, wxID_ANY, 50, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer4->Add( m_sTransparency, 0, wxEXPAND, 5 );
	
	m_sWhiteTransparency = new wxSlider( this, wxID_ANY, 150, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer4->Add( m_sWhiteTransparency, 0, wxEXPAND, 5 );
	
	m_cInvert = new wxCheckBox( this, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_cInvert, 0, wxALL, 5 );
	
	
	fgSizer8->Add( sbSizer4, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer8 );
	this->Layout();
	fgSizer8->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_lFaxes->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( WeatherFaxDialogBase::OnFaxes ), NULL, this );
	m_lFaxes->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( WeatherFaxDialogBase::OnFaxesToggled ), NULL, this );
	m_bCapture->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::CaptureFaxClicked ), NULL, this );
	m_bOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::OpenFaxClicked ), NULL, this );
	m_bEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::EditFaxClicked ), NULL, this );
	m_bDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::DeleteFaxClicked ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_cInvert->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::OnInvert ), NULL, this );
}

WeatherFaxDialogBase::~WeatherFaxDialogBase()
{
	// Disconnect Events
	m_lFaxes->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( WeatherFaxDialogBase::OnFaxes ), NULL, this );
	m_lFaxes->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( WeatherFaxDialogBase::OnFaxesToggled ), NULL, this );
	m_bCapture->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::CaptureFaxClicked ), NULL, this );
	m_bOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::OpenFaxClicked ), NULL, this );
	m_bEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::EditFaxClicked ), NULL, this );
	m_bDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::DeleteFaxClicked ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( WeatherFaxDialogBase::TransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_sWhiteTransparency->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( WeatherFaxDialogBase::WhiteTransparencyChanged ), NULL, this );
	m_cInvert->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( WeatherFaxDialogBase::OnInvert ), NULL, this );
	
}

WeatherFaxWizardBase::WeatherFaxWizardBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxBitmap& bitmap, const wxPoint& pos, long style ) 
{
	this->Create( parent, id, title, bitmap, pos, style );
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxWizardPageSimple* m_wizPage1 = new wxWizardPageSimple( this );
	m_pages.Add( m_wizPage1 );
	
	m_wizPage1->SetMinSize( wxSize( 300,-1 ) );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer11->AddGrowableCol( 0 );
	fgSizer11->AddGrowableRow( 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_swFaxArea1 = new wxScrolledWindow( m_wizPage1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxHSCROLL|wxVSCROLL );
	m_swFaxArea1->SetScrollRate( 5, 5 );
	fgSizer11->Add( m_swFaxArea1, 1, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer172;
	fgSizer172 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer172->AddGrowableCol( 1 );
	fgSizer172->AddGrowableRow( 0 );
	fgSizer172->SetFlexibleDirection( wxBOTH );
	fgSizer172->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_wizPage1, wxID_ANY, _("Decoder") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer19->AddGrowableCol( 1 );
	fgSizer19->AddGrowableRow( 0 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer18->AddGrowableCol( 0 );
	fgSizer18->AddGrowableRow( 0 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_bStopDecoding = new wxButton( m_wizPage1, wxID_ANY, _("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer18->Add( m_bStopDecoding, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer20;
	fgSizer20 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer20->SetFlexibleDirection( wxBOTH );
	fgSizer20->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText212 = new wxStaticText( m_wizPage1, wxID_ANY, _("Sat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText212->Wrap( -1 );
	fgSizer20->Add( m_staticText212, 0, wxALL, 5 );
	
	m_sMinusSaturationThreshold = new wxSpinCtrl( m_wizPage1, wxID_ANY, wxT("3"), wxDefaultPosition, wxSize( 40,-1 ), wxSP_ARROW_KEYS, 0, 30, 0 );
	fgSizer20->Add( m_sMinusSaturationThreshold, 0, wxALL, 5 );
	
	
	fgSizer18->Add( fgSizer20, 1, wxEXPAND, 5 );
	
	
	fgSizer19->Add( fgSizer18, 1, wxEXPAND, 5 );
	
	m_bPhasingArea = new wxScrolledWindow( m_wizPage1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_bPhasingArea->SetScrollRate( 5, 5 );
	m_bPhasingArea->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer19->Add( m_bPhasingArea, 1, wxEXPAND | wxALL, 5 );
	
	
	sbSizer7->Add( fgSizer19, 1, wxEXPAND, 5 );
	
	
	fgSizer172->Add( sbSizer7, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_wizPage1, wxID_ANY, _("Image Correction") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer10->AddGrowableCol( 3 );
	fgSizer10->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText16 = new wxStaticText( m_wizPage1, wxID_ANY, _("Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer10->Add( m_staticText16, 0, wxALL, 5 );
	
	wxString m_cFilterChoices[] = { _("No Filter"), _("Removal 1"), _("Removal 2"), _("removal 3"), _("Value 1"), _("Value 2"), _("Value 3") };
	int m_cFilterNChoices = sizeof( m_cFilterChoices ) / sizeof( wxString );
	m_cFilter = new wxChoice( m_wizPage1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cFilterNChoices, m_cFilterChoices, 0 );
	m_cFilter->SetSelection( 0 );
	fgSizer10->Add( m_cFilter, 0, wxALL, 2 );
	
	m_staticText9 = new wxStaticText( m_wizPage1, wxID_ANY, _("Phasing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer10->Add( m_staticText9, 0, wxALL, 5 );
	
	m_sPhasing = new wxSlider( m_wizPage1, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_INVERSE );
	fgSizer10->Add( m_sPhasing, 0, wxALL|wxEXPAND, 2 );
	
	m_staticText17 = new wxStaticText( m_wizPage1, wxID_ANY, _("Rotation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	fgSizer10->Add( m_staticText17, 0, wxALL, 5 );
	
	wxString m_cRotationChoices[] = { _("None"), _("CCW"), _("CW"), _("180") };
	int m_cRotationNChoices = sizeof( m_cRotationChoices ) / sizeof( wxString );
	m_cRotation = new wxChoice( m_wizPage1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cRotationNChoices, m_cRotationChoices, 0 );
	m_cRotation->SetSelection( 0 );
	fgSizer10->Add( m_cRotation, 0, wxALL, 2 );
	
	m_staticText101 = new wxStaticText( m_wizPage1, wxID_ANY, _("Skew"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	fgSizer10->Add( m_staticText101, 0, wxALL, 2 );
	
	m_sSkew = new wxSlider( m_wizPage1, wxID_ANY, 0, -1000, 1000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	fgSizer10->Add( m_sSkew, 0, wxALL|wxEXPAND, 2 );
	
	
	sbSizer5->Add( fgSizer10, 1, wxEXPAND, 5 );
	
	
	fgSizer172->Add( sbSizer5, 1, wxEXPAND, 5 );
	
	
	fgSizer11->Add( fgSizer172, 1, wxEXPAND, 5 );
	
	
	m_wizPage1->SetSizer( fgSizer11 );
	m_wizPage1->Layout();
	fgSizer11->Fit( m_wizPage1 );
	wxWizardPageSimple* m_wizPage2 = new wxWizardPageSimple( this );
	m_pages.Add( m_wizPage2 );
	
	wxFlexGridSizer* fgSizer111;
	fgSizer111 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer111->AddGrowableCol( 0 );
	fgSizer111->AddGrowableRow( 0 );
	fgSizer111->SetFlexibleDirection( wxBOTH );
	fgSizer111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer171;
	fgSizer171 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer171->AddGrowableCol( 1 );
	fgSizer171->AddGrowableRow( 0 );
	fgSizer171->SetFlexibleDirection( wxBOTH );
	fgSizer171->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_wizPage2, wxID_ANY, _("Image Coordinates") ), wxVERTICAL );
	
	m_fgSizer434 = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgSizer434->AddGrowableRow( 1 );
	m_fgSizer434->SetFlexibleDirection( wxBOTH );
	m_fgSizer434->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_fgSizerUnMappedCoords = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgSizerUnMappedCoords->AddGrowableCol( 0 );
	m_fgSizerUnMappedCoords->SetFlexibleDirection( wxBOTH );
	m_fgSizerUnMappedCoords->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_cbCoordSet = new wxComboBox( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0, NULL, 0 ); 
	m_fgSizerUnMappedCoords->Add( m_cbCoordSet, 0, wxALL|wxEXPAND, 5 );
	
	m_bRemoveCoordSet = new wxButton( m_wizPage2, wxID_ANY, _("Remove"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_fgSizerUnMappedCoords->Add( m_bRemoveCoordSet, 0, wxTOP, 5 );
	
	
	m_fgSizer434->Add( m_fgSizerUnMappedCoords, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_rbCoord1UnMapped = new wxRadioButton( m_wizPage2, wxID_ANY, _("Coord 1"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_rbCoord1UnMapped->SetForegroundColour( wxColour( 255, 0, 0 ) );
	
	fgSizer7->Add( m_rbCoord1UnMapped, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( m_wizPage2, wxID_ANY, _("Lon/Lat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer7->Add( m_staticText6, 0, wxALL, 5 );
	
	m_sCoord1XUnMapped = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer7->Add( m_sCoord1XUnMapped, 0, wxALL, 5 );
	
	m_sCoord1LonUnMapped = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, -180, 180, 0 );
	fgSizer7->Add( m_sCoord1LonUnMapped, 0, wxALL, 5 );
	
	m_sCoord1YUnMapped = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer7->Add( m_sCoord1YUnMapped, 0, wxALL, 5 );
	
	m_sCoord1LatUnMapped = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, -90, 90, 0 );
	fgSizer7->Add( m_sCoord1LatUnMapped, 0, wxALL, 5 );
	
	m_rbCoord2UnMapped = new wxRadioButton( m_wizPage2, wxID_ANY, _("Coord 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rbCoord2UnMapped->SetForegroundColour( wxColour( 0, 255, 0 ) );
	
	fgSizer7->Add( m_rbCoord2UnMapped, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( m_wizPage2, wxID_ANY, _("Lon/Lat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer7->Add( m_staticText8, 0, wxALL, 5 );
	
	m_sCoord2XUnMapped = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer7->Add( m_sCoord2XUnMapped, 0, wxALL, 5 );
	
	m_sCoord2LonUnMapped = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, -180, 180, 0 );
	fgSizer7->Add( m_sCoord2LonUnMapped, 0, wxALL, 5 );
	
	m_sCoord2YUnMapped = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer7->Add( m_sCoord2YUnMapped, 0, wxALL, 5 );
	
	m_sCoord2LatUnMapped = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, -90, 90, 0 );
	fgSizer7->Add( m_sCoord2LatUnMapped, 0, wxALL, 5 );
	
	
	m_fgSizer434->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	
	sbSizer4->Add( m_fgSizer434, 1, 0, 5 );
	
	
	fgSizer171->Add( sbSizer4, 1, wxEXPAND, 5 );
	
	m_swFaxArea2 = new wxScrolledWindow( m_wizPage2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_swFaxArea2->SetScrollRate( 5, 5 );
	fgSizer171->Add( m_swFaxArea2, 1, wxEXPAND | wxALL, 5 );
	
	
	fgSizer111->Add( fgSizer171, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer51;
	sbSizer51 = new wxStaticBoxSizer( new wxStaticBox( m_wizPage2, wxID_ANY, _("Coordinates Mapping Correction") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer101;
	fgSizer101 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer101->AddGrowableCol( 3 );
	fgSizer101->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer101->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer17;
	fgSizer17 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer17->SetFlexibleDirection( wxBOTH );
	fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText15 = new wxStaticText( m_wizPage2, wxID_ANY, _("Input Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer17->Add( m_staticText15, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxString m_cMappingChoices[] = { _("mercator"), _("polar"), _("conic"), _("fixed-flat") };
	int m_cMappingNChoices = sizeof( m_cMappingChoices ) / sizeof( wxString );
	m_cMapping = new wxChoice( m_wizPage2, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cMappingNChoices, m_cMappingChoices, 0 );
	m_cMapping->SetSelection( 0 );
	fgSizer17->Add( m_cMapping, 0, wxALL, 5 );
	
	m_staticText21 = new wxStaticText( m_wizPage2, wxID_ANY, _("Output Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer17->Add( m_staticText21, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText22 = new wxStaticText( m_wizPage2, wxID_ANY, _("Mercator"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer17->Add( m_staticText22, 0, wxALL, 5 );
	
	m_staticText24 = new wxStaticText( m_wizPage2, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer17->Add( m_staticText24, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_tMappingMultiplier = new wxTextCtrl( m_wizPage2, wxID_ANY, _("1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer17->Add( m_tMappingMultiplier, 0, wxALL, 5 );
	
	m_staticText20 = new wxStaticText( m_wizPage2, wxID_ANY, _("W/H"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	fgSizer17->Add( m_staticText20, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_tMappingRatio = new wxTextCtrl( m_wizPage2, wxID_ANY, _("1"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer17->Add( m_tMappingRatio, 0, wxALL, 5 );
	
	m_staticText211 = new wxStaticText( m_wizPage2, wxID_ANY, _("True Width Ratio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText211->Wrap( -1 );
	fgSizer17->Add( m_staticText211, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_tTrueRatio = new wxTextCtrl( m_wizPage2, wxID_ANY, _("1"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	fgSizer17->Add( m_tTrueRatio, 0, wxALL, 5 );
	
	
	fgSizer101->Add( fgSizer17, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgChangingLabelSizer;
	fgChangingLabelSizer = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgChangingLabelSizer->SetFlexibleDirection( wxBOTH );
	fgChangingLabelSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_stMappingLabel1 = new wxStaticText( m_wizPage2, wxID_ANY, _("Pole X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stMappingLabel1->Wrap( -1 );
	fgChangingLabelSizer->Add( m_stMappingLabel1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_sMappingPoleX = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, -100000, 100000, 369 );
	fgChangingLabelSizer->Add( m_sMappingPoleX, 0, wxALL, 5 );
	
	m_stMappingLabel2 = new wxStaticText( m_wizPage2, wxID_ANY, _("Pole Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stMappingLabel2->Wrap( -1 );
	fgChangingLabelSizer->Add( m_stMappingLabel2, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_sMappingPoleY = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, -100000, 100000, -74 );
	fgChangingLabelSizer->Add( m_sMappingPoleY, 0, wxALL, 5 );
	
	m_stMapping = new wxStaticText( m_wizPage2, wxID_ANY, _("Equator Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stMapping->Wrap( -1 );
	fgChangingLabelSizer->Add( m_stMapping, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_sMappingEquatorY = new wxSpinCtrl( m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, -100000, 100000, 560 );
	fgChangingLabelSizer->Add( m_sMappingEquatorY, 0, wxALL, 5 );
	
	m_bGetMapping = new wxButton( m_wizPage2, wxID_ANY, _("Get Mapping "), wxDefaultPosition, wxDefaultSize, 0 );
	fgChangingLabelSizer->Add( m_bGetMapping, 0, wxALL, 5 );
	
	m_bGetEquator = new wxButton( m_wizPage2, wxID_ANY, _("Get Equator"), wxDefaultPosition, wxDefaultSize, 0 );
	fgChangingLabelSizer->Add( m_bGetEquator, 0, wxALL, 5 );
	
	m_bInformation = new wxButton( m_wizPage2, wxID_ANY, _("Information"), wxDefaultPosition, wxDefaultSize, 0 );
	fgChangingLabelSizer->Add( m_bInformation, 0, wxALL, 5 );
	
	
	fgSizer101->Add( fgChangingLabelSizer, 1, wxEXPAND, 5 );
	
	
	sbSizer51->Add( fgSizer101, 1, wxEXPAND, 5 );
	
	
	fgSizer111->Add( sbSizer51, 1, wxEXPAND, 5 );
	
	
	m_wizPage2->SetSizer( fgSizer111 );
	m_wizPage2->Layout();
	fgSizer111->Fit( m_wizPage2 );
	wxWizardPageSimple* m_wizPage3 = new wxWizardPageSimple( this );
	m_pages.Add( m_wizPage3 );
	
	wxFlexGridSizer* fgSizer1111;
	fgSizer1111 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer1111->AddGrowableCol( 0 );
	fgSizer1111->AddGrowableRow( 0 );
	fgSizer1111->SetFlexibleDirection( wxBOTH );
	fgSizer1111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer1711;
	fgSizer1711 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer1711->AddGrowableCol( 1 );
	fgSizer1711->AddGrowableRow( 0 );
	fgSizer1711->SetFlexibleDirection( wxBOTH );
	fgSizer1711->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( m_wizPage3, wxID_ANY, _("Image Coordinates") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer91;
	fgSizer91 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer91->AddGrowableRow( 1 );
	fgSizer91->SetFlexibleDirection( wxBOTH );
	fgSizer91->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer71;
	fgSizer71 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer71->SetFlexibleDirection( wxBOTH );
	fgSizer71->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_rbCoord1 = new wxRadioButton( m_wizPage3, wxID_ANY, _("Coord 1"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_rbCoord1->SetForegroundColour( wxColour( 255, 0, 0 ) );
	
	fgSizer71->Add( m_rbCoord1, 0, wxALL, 5 );
	
	m_staticText61 = new wxStaticText( m_wizPage3, wxID_ANY, _("Lon/Lat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer71->Add( m_staticText61, 0, wxALL, 5 );
	
	m_sCoord1X = new wxSpinCtrl( m_wizPage3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer71->Add( m_sCoord1X, 0, wxALL, 5 );
	
	m_sCoord1Lon = new wxSpinCtrl( m_wizPage3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, -180, 180, 0 );
	fgSizer71->Add( m_sCoord1Lon, 0, wxALL, 5 );
	
	m_sCoord1Y = new wxSpinCtrl( m_wizPage3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer71->Add( m_sCoord1Y, 0, wxALL, 5 );
	
	m_sCoord1Lat = new wxSpinCtrl( m_wizPage3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, -90, 90, 0 );
	fgSizer71->Add( m_sCoord1Lat, 0, wxALL, 5 );
	
	m_rbCoord2 = new wxRadioButton( m_wizPage3, wxID_ANY, _("Coord 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rbCoord2->SetForegroundColour( wxColour( 0, 255, 0 ) );
	
	fgSizer71->Add( m_rbCoord2, 0, wxALL, 5 );
	
	m_staticText81 = new wxStaticText( m_wizPage3, wxID_ANY, _("Lon/Lat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	fgSizer71->Add( m_staticText81, 0, wxALL, 5 );
	
	m_sCoord2X = new wxSpinCtrl( m_wizPage3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer71->Add( m_sCoord2X, 0, wxALL, 5 );
	
	m_sCoord2Lon = new wxSpinCtrl( m_wizPage3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, -180, 180, 0 );
	fgSizer71->Add( m_sCoord2Lon, 0, wxALL, 5 );
	
	m_sCoord2Y = new wxSpinCtrl( m_wizPage3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer71->Add( m_sCoord2Y, 0, wxALL, 5 );
	
	m_sCoord2Lat = new wxSpinCtrl( m_wizPage3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, -90, 90, 0 );
	fgSizer71->Add( m_sCoord2Lat, 0, wxALL, 5 );
	
	
	fgSizer91->Add( fgSizer71, 1, wxEXPAND, 5 );
	
	
	sbSizer41->Add( fgSizer91, 1, 0, 5 );
	
	
	fgSizer1711->Add( sbSizer41, 1, wxEXPAND, 5 );
	
	m_swFaxArea3 = new wxScrolledWindow( m_wizPage3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_swFaxArea3->SetScrollRate( 5, 5 );
	fgSizer1711->Add( m_swFaxArea3, 1, wxEXPAND | wxALL, 5 );
	
	
	fgSizer1111->Add( fgSizer1711, 1, wxEXPAND, 5 );
	
	
	m_wizPage3->SetSizer( fgSizer1111 );
	m_wizPage3->Layout();
	fgSizer1111->Fit( m_wizPage3 );
	
	this->Centre( wxBOTH );
	
	for ( unsigned int i = 1; i < m_pages.GetCount(); i++ )
	{
		m_pages.Item( i )->SetPrev( m_pages.Item( i - 1 ) );
		m_pages.Item( i - 1 )->SetNext( m_pages.Item( i ) );
	}
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( WeatherFaxWizardBase::OnSetSizes ) );
	this->Connect( wxID_ANY, wxEVT_WIZARD_PAGE_CHANGED, wxWizardEventHandler( WeatherFaxWizardBase::OnWizardPageChanged ) );
	m_swFaxArea1->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WeatherFaxWizardBase::OnBitmapClickPage1 ), NULL, this );
	m_swFaxArea1->Connect( wxEVT_PAINT, wxPaintEventHandler( WeatherFaxWizardBase::OnPaintImage ), NULL, this );
	m_bStopDecoding->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnStopDecoding ), NULL, this );
	m_bPhasingArea->Connect( wxEVT_PAINT, wxPaintEventHandler( WeatherFaxWizardBase::OnPaintPhasing ), NULL, this );
	m_cFilter->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_cRotation->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_cbCoordSet->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( WeatherFaxWizardBase::OnCoordSet ), NULL, this );
	m_cbCoordSet->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( WeatherFaxWizardBase::OnCoordText ), NULL, this );
	m_bRemoveCoordSet->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnRemoveCoords ), NULL, this );
	m_sCoord1XUnMapped->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord1YUnMapped->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord2XUnMapped->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord2YUnMapped->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_swFaxArea2->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WeatherFaxWizardBase::OnBitmapClickPage2 ), NULL, this );
	m_swFaxArea2->Connect( wxEVT_PAINT, wxPaintEventHandler( WeatherFaxWizardBase::OnPaintImage ), NULL, this );
	m_cMapping->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( WeatherFaxWizardBase::OnMappingChoice ), NULL, this );
	m_tTrueRatio->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( WeatherFaxWizardBase::OnUpdateMapping ), NULL, this );
	m_sMappingPoleX->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnUpdateMapping ), NULL, this );
	m_sMappingPoleY->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnUpdateMapping ), NULL, this );
	m_bGetMapping->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnGetMapping ), NULL, this );
	m_bGetEquator->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnGetEquator ), NULL, this );
	m_bInformation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnInformation ), NULL, this );
	m_sCoord1X->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord1Y->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord2X->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord2Y->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_swFaxArea3->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WeatherFaxWizardBase::OnBitmapClickPage3 ), NULL, this );
	m_swFaxArea3->Connect( wxEVT_PAINT, wxPaintEventHandler( WeatherFaxWizardBase::OnPaintImage ), NULL, this );
}

WeatherFaxWizardBase::~WeatherFaxWizardBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( WeatherFaxWizardBase::OnSetSizes ) );
	this->Disconnect( wxID_ANY, wxEVT_WIZARD_PAGE_CHANGED, wxWizardEventHandler( WeatherFaxWizardBase::OnWizardPageChanged ) );
	m_swFaxArea1->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WeatherFaxWizardBase::OnBitmapClickPage1 ), NULL, this );
	m_swFaxArea1->Disconnect( wxEVT_PAINT, wxPaintEventHandler( WeatherFaxWizardBase::OnPaintImage ), NULL, this );
	m_bStopDecoding->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnStopDecoding ), NULL, this );
	m_bPhasingArea->Disconnect( wxEVT_PAINT, wxPaintEventHandler( WeatherFaxWizardBase::OnPaintPhasing ), NULL, this );
	m_cFilter->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sPhasing->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_cRotation->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_sSkew->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( WeatherFaxWizardBase::UpdatePage1 ), NULL, this );
	m_cbCoordSet->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( WeatherFaxWizardBase::OnCoordSet ), NULL, this );
	m_cbCoordSet->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( WeatherFaxWizardBase::OnCoordText ), NULL, this );
	m_bRemoveCoordSet->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnRemoveCoords ), NULL, this );
	m_sCoord1XUnMapped->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord1YUnMapped->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord2XUnMapped->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord2YUnMapped->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_swFaxArea2->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WeatherFaxWizardBase::OnBitmapClickPage2 ), NULL, this );
	m_swFaxArea2->Disconnect( wxEVT_PAINT, wxPaintEventHandler( WeatherFaxWizardBase::OnPaintImage ), NULL, this );
	m_cMapping->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( WeatherFaxWizardBase::OnMappingChoice ), NULL, this );
	m_tTrueRatio->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( WeatherFaxWizardBase::OnUpdateMapping ), NULL, this );
	m_sMappingPoleX->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnUpdateMapping ), NULL, this );
	m_sMappingPoleY->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnUpdateMapping ), NULL, this );
	m_bGetMapping->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnGetMapping ), NULL, this );
	m_bGetEquator->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnGetEquator ), NULL, this );
	m_bInformation->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherFaxWizardBase::OnInformation ), NULL, this );
	m_sCoord1X->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord1Y->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord2X->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_sCoord2Y->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( WeatherFaxWizardBase::OnSpin ), NULL, this );
	m_swFaxArea3->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WeatherFaxWizardBase::OnBitmapClickPage3 ), NULL, this );
	m_swFaxArea3->Disconnect( wxEVT_PAINT, wxPaintEventHandler( WeatherFaxWizardBase::OnPaintImage ), NULL, this );
	
	m_pages.Clear();
}

WeatherFaxPrefsDialog::WeatherFaxPrefsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Audio Decoding Options") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, _("Image Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer10->Add( m_staticText29, 0, wxALL, 5 );
	
	m_sImageWidth = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 16384, 576 );
	fgSizer10->Add( m_sImageWidth, 0, wxALL, 5 );
	
	m_staticText30 = new wxStaticText( this, wxID_ANY, _("Bits per Pixel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	fgSizer10->Add( m_staticText30, 0, wxALL, 5 );
	
	m_sBitsPerPixel = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 8, 8 );
	fgSizer10->Add( m_sBitsPerPixel, 0, wxALL, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Carrier"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer10->Add( m_staticText31, 0, wxALL, 5 );
	
	m_sCarrier = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 10000, 1900 );
	fgSizer10->Add( m_sCarrier, 0, wxALL, 5 );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, _("Deviation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	fgSizer10->Add( m_staticText32, 0, wxALL, 5 );
	
	m_sDeviation = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 10000, 400 );
	fgSizer10->Add( m_sDeviation, 0, wxALL, 5 );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, _("Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	fgSizer10->Add( m_staticText33, 0, wxALL, 5 );
	
	wxString m_cFilterChoices[] = { _("narrow"), _("middle"), _("wide") };
	int m_cFilterNChoices = sizeof( m_cFilterChoices ) / sizeof( wxString );
	m_cFilter = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cFilterNChoices, m_cFilterChoices, 0 );
	m_cFilter->SetSelection( 1 );
	fgSizer10->Add( m_cFilter, 0, wxALL, 5 );
	
	
	fgSizer12->Add( fgSizer10, 1, wxEXPAND, 5 );
	
	m_cbSkip = new wxCheckBox( this, wxID_ANY, _("Skip start, stop and \nphasing detection"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( m_cbSkip, 0, wxALL, 5 );
	
	m_cbInclude = new wxCheckBox( this, wxID_ANY, _("Include header data in image"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( m_cbInclude, 0, wxALL, 5 );
	
	
	sbSizer6->Add( fgSizer12, 1, wxEXPAND, 5 );
	
	
	bSizer2->Add( sbSizer6, 1, wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bSizer2->Add( m_sdbSizer1, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );
	
	this->Centre( wxBOTH );
}

WeatherFaxPrefsDialog::~WeatherFaxPrefsDialog()
{
}
