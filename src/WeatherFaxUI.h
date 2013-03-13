///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WEATHERFAXUI_H__
#define __WEATHERFAXUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/checklst.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/scrolwin.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/choice.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/combobox.h>
#include <wx/radiobut.h>
#include <wx/textctrl.h>
#include <wx/wizard.h>
#include <wx/dynarray.h>
WX_DEFINE_ARRAY_PTR( wxWizardPageSimple*, WizardPages );

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WeatherFaxDialogBase
///////////////////////////////////////////////////////////////////////////////
class WeatherFaxDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxButton* m_bCapture;
		wxButton* m_bOpen;
		wxButton* m_bEdit;
		wxButton* m_bDelete;
		wxCheckBox* m_cInvert;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFaxes( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFaxesToggled( wxCommandEvent& event ) { event.Skip(); }
		virtual void CaptureFaxClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenFaxClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void EditFaxClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void DeleteFaxClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void TransparencyChanged( wxScrollEvent& event ) { event.Skip(); }
		virtual void WhiteTransparencyChanged( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnInvert( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxStaticBoxSizer* sbFax;
		wxCheckListBox* m_lFaxes;
		wxSlider* m_sTransparency;
		wxSlider* m_sWhiteTransparency;
		
		WeatherFaxDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Weather Fax"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL ); 
		~WeatherFaxDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class WeatherFaxWizardBase
///////////////////////////////////////////////////////////////////////////////
class WeatherFaxWizardBase : public wxWizard 
{
	private:
	
	protected:
		wxScrolledWindow* m_swFaxArea1;
		wxButton* m_bStopDecoding;
		wxStaticText* m_staticText212;
		wxSpinCtrl* m_sMinusSaturationThreshold;
		wxScrolledWindow* m_bPhasingArea;
		wxStaticText* m_staticText16;
		wxChoice* m_cFilter;
		wxStaticText* m_staticText9;
		wxSlider* m_sPhasing;
		wxStaticText* m_staticText17;
		wxChoice* m_cRotation;
		wxStaticText* m_staticText101;
		wxSlider* m_sSkew;
		wxFlexGridSizer* m_fgSizerUnMappedCoords;
		wxComboBox* m_cbCoordSet;
		wxButton* m_bRemoveCoordSet;
		wxRadioButton* m_rbCoord1UnMapped;
		wxStaticText* m_staticText6;
		wxSpinCtrl* m_sCoord1XUnMapped;
		wxSpinCtrl* m_sCoord1LonUnMapped;
		wxSpinCtrl* m_sCoord1YUnMapped;
		wxSpinCtrl* m_sCoord1LatUnMapped;
		wxRadioButton* m_rbCoord2UnMapped;
		wxStaticText* m_staticText8;
		wxSpinCtrl* m_sCoord2XUnMapped;
		wxSpinCtrl* m_sCoord2LonUnMapped;
		wxSpinCtrl* m_sCoord2YUnMapped;
		wxSpinCtrl* m_sCoord2LatUnMapped;
		wxScrolledWindow* m_swFaxArea2;
		wxStaticText* m_staticText15;
		wxChoice* m_cMapping;
		wxStaticText* m_staticText21;
		wxStaticText* m_staticText22;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_tMappingMultiplier;
		wxStaticText* m_staticText20;
		wxTextCtrl* m_tMappingRatio;
		wxStaticText* m_staticText211;
		wxTextCtrl* m_tTrueRatio;
		wxStaticText* m_stMappingLabel1;
		wxSpinCtrl* m_sMappingPoleX;
		wxStaticText* m_stMappingLabel2;
		wxSpinCtrl* m_sMappingPoleY;
		wxStaticText* m_stMapping;
		wxSpinCtrl* m_sMappingEquatorY;
		wxButton* m_bGetMapping;
		wxButton* m_bGetEquator;
		wxButton* m_bInformation;
		wxRadioButton* m_rbCoord1;
		wxStaticText* m_staticText61;
		wxSpinCtrl* m_sCoord1X;
		wxSpinCtrl* m_sCoord1Lon;
		wxSpinCtrl* m_sCoord1Y;
		wxSpinCtrl* m_sCoord1Lat;
		wxRadioButton* m_rbCoord2;
		wxStaticText* m_staticText81;
		wxSpinCtrl* m_sCoord2X;
		wxSpinCtrl* m_sCoord2Lon;
		wxSpinCtrl* m_sCoord2Y;
		wxSpinCtrl* m_sCoord2Lat;
		wxScrolledWindow* m_swFaxArea3;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSetSizes( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnWizardPageChanged( wxWizardEvent& event ) { event.Skip(); }
		virtual void OnBitmapClickPage1( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnPaintImage( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnStopDecoding( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPaintPhasing( wxPaintEvent& event ) { event.Skip(); }
		virtual void UpdatePage1( wxCommandEvent& event ) { event.Skip(); }
		virtual void UpdatePage1( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnCoordSet( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCoordText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveCoords( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSpin( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnBitmapClickPage2( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnMappingChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateMapping( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateMapping( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnGetMapping( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGetEquator( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInformation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBitmapClickPage3( wxMouseEvent& event ) { event.Skip(); }
		
	
	public:
		wxFlexGridSizer* m_fgSizer434;
		
		WeatherFaxWizardBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Weather Fax Image"), const wxBitmap& bitmap = wxNullBitmap, const wxPoint& pos = wxDefaultPosition, long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER );
		WizardPages m_pages;
		~WeatherFaxWizardBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class WeatherFaxPrefsDialog
///////////////////////////////////////////////////////////////////////////////
class WeatherFaxPrefsDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText29;
		wxStaticText* m_staticText30;
		wxStaticText* m_staticText31;
		wxStaticText* m_staticText32;
		wxStaticText* m_staticText33;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
	
	public:
		wxSpinCtrl* m_sImageWidth;
		wxSpinCtrl* m_sBitsPerPixel;
		wxSpinCtrl* m_sCarrier;
		wxSpinCtrl* m_sDeviation;
		wxChoice* m_cFilter;
		wxCheckBox* m_cbSkip;
		wxCheckBox* m_cbInclude;
		
		WeatherFaxPrefsDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Weather Fax Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE ); 
		~WeatherFaxPrefsDialog();
	
};

#endif //__WEATHERFAXUI_H__
