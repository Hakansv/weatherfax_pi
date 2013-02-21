/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  weather fax Plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Sean D'Epagnier                                 *
 *   sean at depagnier dot com                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */

#include <list>

#include "FaxDecoder.h"
#include "WeatherFaxDialog.h"

#include <wx/listimpl.cpp>
WX_DEFINE_LIST(WeatherFaxImageCoordinateList);

/* replace characters a in input with b */
wxString ReplaceChar(wxString input, wxChar a, wxChar b)
{
    wxString output;
    for(unsigned int i=0; i<input.length(); i++)
        if(input[i] == a)
            output += b;
        else
            output += input[i];
    return output;
}

WeatherFaxDialog::WeatherFaxDialog( weatherfax_pi &_weatherfax_pi, wxWindow* parent)
    : WeatherFaxDialogBase( parent ), m_weatherfax_pi(_weatherfax_pi)
{
    wxFileConfig *pConf = m_weatherfax_pi.m_pconfig;
    pConf->SetPath ( _T ( "/Settings/WeatherFax/CoordinateSets" ) );

    wxString names;
    pConf->Read ( _T ( "Names" ), &names, _T(""));

    /* split at each ; to get all the names in a list */
    std::list<wxString> namelist;
    while(names.size()) {
        namelist.push_back(names.BeforeFirst(';'));
        names = names.AfterFirst(';');
    }

    for(std::list<wxString>::iterator it = namelist.begin();
        it != namelist.end(); it++) {
        /* replace any _ back with spaces */
        pConf->SetPath ( _T ( "/Settings/WeatherFax/CoordinateSets/" ) + *it );
        WeatherFaxImageCoordinates *newcoord
            = new WeatherFaxImageCoordinates(ReplaceChar(*it, '_', ' '));

        pConf->Read ( _T ( "Point1X" ), &newcoord->p1.x, 0);
        pConf->Read ( _T ( "Point1Y" ), &newcoord->p1.y, 0);
        pConf->Read ( _T ( "Point1Lat" ), &newcoord->lat1, 0);
        pConf->Read ( _T ( "Point1Lon" ), &newcoord->lon1, 0);
        pConf->Read ( _T ( "Point2X" ), &newcoord->p2.x, 0);
        pConf->Read ( _T ( "Point2Y" ), &newcoord->p2.y, 0);
        pConf->Read ( _T ( "Point2Lat" ), &newcoord->lat2, 0);
        pConf->Read ( _T ( "Point2Lon" ), &newcoord->lon2, 0);

        m_Coords.Append(newcoord);
    }
}

WeatherFaxDialog::~WeatherFaxDialog()
{
    wxFileConfig *pConf = m_weatherfax_pi.m_pconfig;
    pConf->SetPath ( _T ( "/Settings/WeatherFax/CoordinateSets" ) );
    wxString names;
    for(unsigned int i=0; i<m_Coords.GetCount(); i++) {
        /* names are not allowed semicolon because we need it */
        m_Coords[i]->name = ReplaceChar(m_Coords[i]->name, ';', ',');
        /* spaces not allowed either unforunately */
        m_Coords[i]->name = ReplaceChar(m_Coords[i]->name, ' ', '_');

        names += m_Coords[i]->name + _(";");
    }
    
    pConf->Write ( _T ( "Names" ), names);

    for(unsigned int i=0; i<m_Coords.GetCount(); i++) {
        pConf->SetPath ( _T ( "/Settings/WeatherFax/CoordinateSets/" ) + m_Coords[i]->name );
        pConf->Write ( _T ( "Point1X" ), m_Coords[i]->p1.x);
        pConf->Write ( _T ( "Point1Y" ), m_Coords[i]->p1.y);
        pConf->Write ( _T ( "Point1Lat" ), m_Coords[i]->lat1);
        pConf->Write ( _T ( "Point1Lon" ), m_Coords[i]->lon1);
        pConf->Write ( _T ( "Point2X" ), m_Coords[i]->p2.x);
        pConf->Write ( _T ( "Point2Y" ), m_Coords[i]->p2.y);
        pConf->Write ( _T ( "Point2Lat" ), m_Coords[i]->lat2);
        pConf->Write ( _T ( "Point2Lon" ), m_Coords[i]->lon2);
        delete m_Coords[i];
    }

    for(unsigned int i=0; i<m_lFaxes->GetCount(); i++)
        delete (WeatherFaxImage*)m_lFaxes->GetClientData(i);
}

void WeatherFaxDialog::OnListBox( wxCommandEvent& event )
{
    int selection = m_lFaxes->GetSelection();
    if(selection >= 0) {
        WeatherFaxImage *image = (WeatherFaxImage*)m_lFaxes->GetClientData(selection);
        m_weatherfax_pi.SetImageToRender(image);
    } else
        m_weatherfax_pi.SetImageToRender(NULL);
}

void WeatherFaxDialog::NewFaxClicked( wxCommandEvent& event )
{
    wxFileDialog openDialog
        ( this, _( "Open Weather Fax Input File" ),
          m_weatherfax_pi.m_path, wxT ( "" ),
          _ ( "\
WAV files (*.wav)|*.WAV;*.wav|\
Supported Image Files|*.BMP;*.bmp;*.XBM;*.xbm;*.XPM;*.xpm;\
*.TIF;*.tif;*.TIFF;*.tiff;*.GIF;*.gif;*.JPEG;*.jpeg;*.JPG;*.jpg;*.PNM;*.pnm;*.PNG;*.png;\
*.PCX;*.pcx;*.PICT;*.pict;*.TGA;*.tga|\
All files (*.*)|*.*" ), wxFD_OPEN);

#if 0
    if( openDialog.ShowModal() == wxID_OK ) {
        wxString filename = openDialog.GetPath();
#else
    if(1) {
        wxString filename = _("/home/sean/fax2.png");
#endif
        wxFileName filenamec(filename);
        m_weatherfax_pi.m_path = openDialog.GetDirectory();        
        if(filenamec.GetExt() == _("wav") || filenamec.GetExt() == _("WAV")) {
            FaxDecoder decoder(*this,
                               m_weatherfax_pi.m_ImageWidth,
                               m_weatherfax_pi.m_BitsPerPixel,
                               m_weatherfax_pi.m_Carrier,
                               m_weatherfax_pi.m_Deviation,
                               (enum Bandwidth)m_weatherfax_pi.m_Filter,
                               m_weatherfax_pi.m_bSkipHeaderDetection,
                               m_weatherfax_pi.m_bIncludeHeadersInImage);
            decoder.DecodeFaxFromAudio(filename);
            FaxImageList images = decoder.images;
            int i=0, n = -1;
            for(FaxImageList::iterator it = images.begin(); it !=  images.end(); it++) {
                WeatherFaxImage *img = new WeatherFaxImage(**it);
                n = m_lFaxes->Append(filenamec.GetFullName()+_("-")
                                     +wxString::Format(_T("%d"), ++i), img);
            }
            if(n == -1) {
                wxMessageDialog w( this, _("Failed to decode input file: ") + filename, _("Failed"),
                                   wxOK | wxICON_ERROR );
                w.ShowModal();
            } else {
                m_lFaxes->SetSelection(n);
                EditFaxClicked(event);
            }
        } else {
            wxImage wimg;
            if(wimg.LoadFile(filename)) {
                WeatherFaxImage *img = new WeatherFaxImage(wimg);
                int n = m_lFaxes->Append(filenamec.GetFullName(), img);
                m_lFaxes->SetSelection(n);
                EditFaxClicked(event);
            } else {
                wxMessageDialog w( this, _("Failed to load input file: ") + filename, _("Failed"),
                                   wxOK | wxICON_ERROR );
                w.ShowModal();
            }
        }
    }
}

void WeatherFaxDialog::EditFaxClicked( wxCommandEvent& event )
{
    int selection = m_lFaxes->GetSelection();
    if(selection < 0)
        return;

    WeatherFaxImage &image = *(WeatherFaxImage*)m_lFaxes->GetClientData(selection);
    EditFaxDialog dialog(image, m_lFaxes->GetString(selection), *this, m_Coords);
    dialog.ShowModal();

    dialog.StoreCoords();

    if(image.m_Coords->p1.x < image.m_Coords->p2.x &&
       image.m_Coords->p1.y < image.m_Coords->p2.y &&
       image.m_Coords->lat1 > image.m_Coords->lat2) {
        m_weatherfax_pi.SetImageToRender(&image);
    } else {
        wxMessageDialog w( this, _("Image edit resulted in zero size (did you forget to set the coordinates?)"),
                           _("Failed"), wxOK | wxICON_ERROR );
        w.ShowModal();
        m_weatherfax_pi.SetImageToRender(NULL);
    }
}

void WeatherFaxDialog::DeleteFaxClicked( wxCommandEvent& event )
{
    int selection = m_lFaxes->GetSelection();
    if(selection < 0)
        return;
    delete (WeatherFaxImage*)m_lFaxes->GetClientData();
    m_lFaxes->Delete(selection);
    RequestRefresh( m_parent );
}

void WeatherFaxDialog::TransparencyChanged( wxScrollEvent& event )
{
    m_weatherfax_pi.SetTransparency(event.GetPosition());
    RequestRefresh( m_parent );
}

void WeatherFaxDialog::WhiteTransparencyChanged( wxScrollEvent& event )
{
    m_weatherfax_pi.UpdateImage();
    m_weatherfax_pi.SetWhiteTransparency(event.GetPosition());
    RequestRefresh( m_parent );
}

void WeatherFaxDialog::OnInvert( wxCommandEvent& event )
{
    m_weatherfax_pi.UpdateImage();
    m_weatherfax_pi.SetInvert(event.IsChecked());
    RequestRefresh( m_parent );
}

EditFaxDialog::EditFaxDialog( WeatherFaxImage &img, wxString name,
                              WeatherFaxDialog &parent,
                              WeatherFaxImageCoordinateList &coords)
    : EditFaxDialogBase( &parent ), m_parent(parent),
      m_wfimg(img), m_curCoords(img.m_Coords),
      m_name(name), m_splits(0),
      m_EditState(COORDINATES), m_Coords(coords)
{
    m_swFaxArea->SetScrollbars(1, 1, m_wfimg.m_img.GetWidth(), m_wfimg.m_img.GetHeight()-1);

    m_sPhasing->SetRange(0, m_wfimg.m_img.GetWidth()-1);
    m_sPhasing->SetValue(m_wfimg.phasing);

    m_rbCoord1->SetValue(true);
    m_rbCoord2->SetValue(false);

    m_sCoord1X->SetRange(0, 0);
    m_sCoord2X->SetRange(m_wfimg.m_img.GetWidth(), m_wfimg.m_img.GetWidth());
    m_sCoord1Y->SetRange(0, 0);
    m_sCoord2Y->SetRange(m_wfimg.m_img.GetHeight()-1, m_wfimg.m_img.GetHeight()-1);

    UpdateCoords();

    /* make a new coord, yet making sure it has a unique name */
    wxString newcoordname;
    int cc = m_Coords.GetCount();
    for(int n=0, i=-1; i != cc; n++) {
        if(n)
            newcoordname = wxString::Format(_("New Coord %d"), n);
        else
            newcoordname = _("New Coord");
        if(!cc)
            break;
        for(i=0; i<cc; i++)
            if(m_Coords[i]->name == newcoordname)
                break;
    }

    m_cbCoordSet->Append(newcoordname);
    int sel = 0;
    for(int i=0; i<cc; i++) {
        if(m_curCoords == m_Coords[i])
            sel = i+1;
        m_cbCoordSet->Append(m_Coords[i]->name);
    }

    m_cbCoordSet->SetSelection(sel);
    m_newCoords = new WeatherFaxImageCoordinates(newcoordname);
    m_newCoords->lat1 = m_newCoords->lat2 = m_newCoords->lon1 = m_newCoords->lon2 = 0;



    SetCoords();
}

EditFaxDialog::~EditFaxDialog()
{
    /* add coordinates to set if it is the new one, but make
       sure it has a unique name */
    int sel = m_cbCoordSet->GetSelection();
    if(sel == -1)
        sel = m_SelectedIndex;

    if(sel == 0 &&
       (m_newCoords->lat1 || m_newCoords->lat2 ||
        m_newCoords->lon1 || m_newCoords->lon2)) {
        int cc = m_Coords.GetCount();
        wxString newname = m_newCoords->name, newnumberedname;
        for(int n=0, i=-1; i != cc; n++) {
            newnumberedname = newname;
            if(n)
                newnumberedname += wxString::Format(_(" %d"), n);

            if(!cc)
                break;
            for(i=0; i<cc; i++)
                if(m_Coords[i]->name == newnumberedname)
                    break;
        }
        m_newCoords->name = newnumberedname;
        m_Coords.Append(m_newCoords);
    } else
        delete m_newCoords;
}

void EditFaxDialog::OnBitmapClick( wxMouseEvent& event )
{
    switch(m_EditState) {
    case COORDINATES:
    {
        wxPoint p = m_swFaxArea->CalcUnscrolledPosition(event.GetPosition());
        
        if(m_rbCoord1->GetValue()) {
            m_sCoord1X->SetRange(p.x, p.x);
            m_sCoord1Y->SetRange(p.y, p.y);
            m_rbCoord1->SetValue(false);
            m_rbCoord2->SetValue(true);
        } else if(m_rbCoord2->GetValue()) {
            m_sCoord2X->SetRange(p.x, p.x);
            m_sCoord2Y->SetRange(p.y, p.y);
            m_rbCoord2->SetValue(false);
            m_rbCoord1->SetValue(true);
        }
        
        /* automatically make sure coord2 is greater than coord1,
           but if all zero (initial) leave it alone */
        
        int x1, x2, y1, y2;
        x1 = m_sCoord1X->GetValue();
        x2 = m_sCoord2X->GetValue();
        y1 = m_sCoord1Y->GetValue();
        y2 = m_sCoord2Y->GetValue();
        
        if( x1 > x2 ) {
            if(x2)
                m_sCoord1X->SetRange(x2, x2);
            m_sCoord2X->SetRange(x1, x1);
        }
        
        if( y1 > y2 ) {
            if(y2)
                m_sCoord1Y->SetRange(y2, y2);
            m_sCoord2Y->SetRange(y1, y1);
        }
        
        UpdateCoords();
    } break;
    case SPLITIMAGE:
    {
        wxPoint split = m_swFaxArea->CalcUnscrolledPosition(event.GetPosition());
        wxRect r1(0, split.y, m_wfimg.m_img.GetWidth(), m_wfimg.m_img.GetHeight()-split.y-1);
        wxImage img2 = m_wfimg.m_img.GetSubImage(r1);
        m_parent.m_lFaxes->Append(m_name + _("-")
                                  + wxString::Format(_T("%d"), m_splits++),
                                  new WeatherFaxImage(img2));
        
        wxRect r2(0, 0, m_wfimg.m_img.GetWidth(), split.y);
        m_wfimg.m_img = m_wfimg.m_img.GetSubImage(r2);
        Refresh();
        m_EditState = COORDINATES;
    } break;
    case POLAR:
    {
        polarpole.x = event.GetPosition().x;
        polarpole.y = -event.GetPosition().y;

        MakeMercatorFromPolar();
        UpdateCoords();

        m_EditState = COORDINATES;
    } break;

    }
}

void EditFaxDialog::OnCoordSet( wxCommandEvent& event )
{
    StoreCoords();
    SetCoords();
}

void EditFaxDialog::OnCoordText( wxCommandEvent& event )
{
    int index = m_cbCoordSet->GetSelection();
    if(index == -1)
        index = m_SelectedIndex;
    m_cbCoordSet->SetString(index, m_cbCoordSet->GetValue());

    if(index == 0)
        m_newCoords->name = m_cbCoordSet->GetValue();
    else
        m_Coords[index-1]->name = m_cbCoordSet->GetValue();
}

void EditFaxDialog::OnRemoveCoords( wxCommandEvent& event )
{
    int selection = m_cbCoordSet->GetSelection();
    if(selection == 0) /* don't delete first item, button should be disabled anyway */
        return;

    m_cbCoordSet->Delete(selection);
    m_Coords.DeleteNode(m_Coords.Item(selection-1));
    m_cbCoordSet->SetSelection(selection-1);

    SetCoords();
}

void EditFaxDialog::OnSplitImage( wxCommandEvent& event )
{
    wxMessageDialog w( this, _("Click the image to split image vertically.\n"),
                       _("Split Image"), wxOK | wxCANCEL );
    if(w.ShowModal() == wxID_OK)
        m_EditState = SPLITIMAGE;
    else
        m_EditState = COORDINATES;
}

void EditFaxDialog::OnPolarToMercator( wxCommandEvent& event )
{
#if 0
    wxMessageDialog w( this, _("Click lowest latitude on vertical meridian"),
                       _("Polar correction"), wxOK );
    w.ShowModal();
    m_wfimg.Reset();

    m_EditState = POLAR;
#else
    polarpole.x = 297;
    polarpole.y = -76;
    m_wfimg.Reset();

    MakeMercatorFromPolar();
    UpdateCoords();
#endif
    Refresh();
}

void EditFaxDialog::OnPhasing( wxScrollEvent& event )
{
    m_wfimg.phasing = event.GetPosition();
    Refresh();
}

void EditFaxDialog::StoreCoords()
{
    m_curCoords->p1.x = m_sCoord1X->GetValue();
    m_curCoords->p1.y = m_sCoord1Y->GetValue();
    m_curCoords->lat1 = m_sCoord1Lat->GetValue();
    m_curCoords->lon1 = m_sCoord1Lon->GetValue();
    m_curCoords->p2.x = m_sCoord2X->GetValue();
    m_curCoords->p2.y = m_sCoord2Y->GetValue();
    m_curCoords->lat2 = m_sCoord2Lat->GetValue();
    m_curCoords->lon2 = m_sCoord2Lon->GetValue();
}

void EditFaxDialog::SetCoords()
{
    int index = m_cbCoordSet->GetSelection();
    if(index == -1 ) /* should never occur, but prevent crash */
        return;

    if(index == 0) {
        m_curCoords = m_newCoords;
        m_bRemoveCoordSet->Disable();
    } else {
        m_curCoords = m_Coords[index-1];
        m_bRemoveCoordSet->Enable();
    }
    m_SelectedIndex = index;

    int w = m_wfimg.m_img.GetWidth(), h = m_wfimg.m_img.GetHeight()-1;
    m_sCoord1X->SetRange(0, w);
    m_sCoord2X->SetRange(0, w);
    m_sCoord1Y->SetRange(0, h);
    m_sCoord2Y->SetRange(0, h);

    m_sCoord1X->SetValue(m_curCoords->p1.x);
    m_sCoord1Y->SetValue(m_curCoords->p1.y);
    m_sCoord1Lat->SetValue(m_curCoords->lat1);
    m_sCoord1Lon->SetValue(m_curCoords->lon1);

    m_sCoord2X->SetValue(m_curCoords->p2.x);
    m_sCoord2Y->SetValue(m_curCoords->p2.y);
    m_sCoord2Lat->SetValue(m_curCoords->lat2);
    m_sCoord2Lon->SetValue(m_curCoords->lon2);

    UpdateCoords();
}

void EditFaxDialog::OnSpin( wxSpinEvent& event)
{
    UpdateCoords();
}

void EditFaxDialog::UpdateCoords()
{
    m_sCoord1X->SetRange(0, m_sCoord2X->GetValue());
    m_sCoord1Y->SetRange(0, m_sCoord2Y->GetValue());
    m_sCoord2X->SetRange(m_sCoord1X->GetValue(), m_wfimg.m_img.GetWidth());
    m_sCoord2Y->SetRange(m_sCoord1Y->GetValue(), m_wfimg.m_img.GetHeight()-1);
    Refresh();
}

void EditFaxDialog::OnPaintImage( wxPaintEvent& event)
{
    wxPaintDC dc( m_swFaxArea );
    wxBitmap bmp(m_wfimg.PhasedImage());

    int x, y;
    m_swFaxArea->GetViewStart(&x, &y);

    int w, h;
    m_swFaxArea->GetSize(&w, &h);

    if( bmp.IsOk() ) {

        wxMemoryDC mdc(bmp);
        dc.Blit( 0, 0, w, h, &mdc, x, y);
        mdc.SelectObject( wxNullBitmap );
    }

    int x1 = m_sCoord1X->GetValue(), y1 = m_sCoord1Y->GetValue();
    int x2 = m_sCoord2X->GetValue(), y2 = m_sCoord2Y->GetValue();
    
    dc.SetPen(wxPen( *wxRED, 3 ));
    dc.SetBrush(wxBrush(*wxBLACK));

    dc.DrawLine(x1-x, 0, x1-x, h);
    dc.DrawLine(x2-x, 0, x2-x, h);
    dc.DrawLine(0, y1-y, w, y1-y);
    dc.DrawLine(0, y2-y, w, y2-y);
}

inline unsigned char ImageValueMono(unsigned char *data, int w, int x, int y)
{
    return data[3*(y*w + x) + 0];
}

void ImageValue(unsigned char *data, int w, int x, int y, unsigned char c[3])
{
    for(int i = 0; i<3; i++)
        c[i] = data[3*(y*w + x) + i];
}

inline unsigned char InterpColorMono(unsigned char c0, unsigned char c1, double d)
{
    return (1-d)*c0 + d*c1;
}

void InterpColor(unsigned char c0[3], unsigned char c1[3], double d, unsigned char c[3])
{
    for(int i=0; i<3; i++)
        c[i] = (1-d)*c0[i] + d*c1[i];
}

void ImageInterpolatedValueMono(unsigned char *data, int w, double x, double y, unsigned char c[3])
{
    int x0 = floor(x), x1 = ceil(x), y0 = floor(y), y1 = ceil(y);
    unsigned char nc[4], xc[2];
    nc[0] = ImageValueMono(data, w, x0, y0);
    nc[1] = ImageValueMono(data, w, x1, y0);
    nc[2] = ImageValueMono(data, w, x0, y1);
    nc[3] = ImageValueMono(data, w, x1, y1);

    double d0 = x - x0, d1 = y - y0;
    xc[0] = InterpColorMono(nc[0], nc[1], d0);
    xc[1] = InterpColorMono(nc[2], nc[3], d0);
    c[0] = c[1] = c[2] = InterpColorMono(xc[0], xc[1], d1);
}

void ImageInterpolatedValue(unsigned char *data, int w, double x, double y, unsigned char c[3])
{
    int x0 = floor(x), x1 = ceil(x), y0 = floor(y), y1 = ceil(y);
    unsigned char nc[4][3], xc[2][3];
    ImageValue(data, w, x0, y0, nc[0]);
    ImageValue(data, w, x1, y0, nc[1]);
    ImageValue(data, w, x0, y1, nc[2]);
    ImageValue(data, w, x1, y1, nc[3]);

    double d0 = x - x0, d1 = y - y0;
    InterpColor(nc[0], nc[1], d0, xc[0]);
    InterpColor(nc[2], nc[3], d0, xc[1]);
    InterpColor(xc[0], xc[1], d1, c);
}

const double alpha = .38;

void EditFaxDialog::PolarToMercator(double px, double py, double &mx, double &my)
{
    double dx = px - polarpole.x, dy = py - polarpole.y;

    double theta = atan2(dx, dy);
    mx = mercatoroffset.x + theta*mercatorwidth;

    double d = hypot(dx, dy);

    d = polarheight - d;
    double pu = d/polarheight;

// begin quadratic fit
    double pp = alpha*pu*pu + (1-alpha)*pu;
// end

#if 1
    double t = pp * (M_PI/2);
    double s = sin(t);
    double y = .5 * log((1 + s) / (1 - s));
#else
    void toSM(double lat, double lon, double lat0, double lon0, double *x, double *y);
    double x, y;
    double lat = pp*90;
    double z = 6375585.74;
    toSM(lat, 0, 0, 0, &x, &y);
    y /= z;
#endif

    y*=mercatorheight;

    y = mercatoroffset.y - y;

    my = y;
}

void EditFaxDialog::MercatorToPolar(double mx, double my, double &px, double &py)
{
    double theta = (mx - mercatoroffset.x)/mercatorwidth;
    double y = my;

    y = mercatoroffset.y - y;

    y /= mercatorheight;

#if 1
    double lat = 2.0 * atan(exp(y)) - M_PI/2.;
    double pp = lat/(M_PI/2);
#else
    void fromSM(double x, double y, double lat0, double lon0, double *lat, double *lon);
    double lat, lon;
    double z = 6375585.74;
    fromSM(0, y*z, 0, 0, &lat, &lon);
    double pp = lat/90;
#endif

// begin quadratic fit
    double b = 1-alpha;
    double pu = (alpha == 0) ? pp: (-b + sqrt( b*b + 4*alpha*pp ) ) / (2 * alpha);
// end

    double d = pu*polarheight;

    d = polarheight - d;

    double dx = d*sin(theta), dy = d*cos(theta);

    px = dx + polarpole.x;
    py = dy + polarpole.y;
}

void EditFaxDialog::MakeMercatorFromPolar()
{
    int w = m_wfimg.m_img.GetWidth(), h = m_wfimg.m_img.GetHeight();

    polarequator = 560;
    polarheight = polarequator - polarpole.y;

    mercatorwidth = w;
    mercatorheight = h;

/* determine location of mercator pole and image boundaries */
    mercatoroffset.x = 0;
    mercatoroffset.y = 0;

    double p1x, p2x, p3x, p4x, p5x, p6x;
    double p1y, p2y, p3y, p4y, p5y, p6y;
    PolarToMercator(0, 0, p1x, p1y);
    PolarToMercator(w, 0, p2x, p2y);
    PolarToMercator(w, h, p3x, p3y);
    PolarToMercator(0, h, p4x, p4y);

    int minp = wxMin(p1x, p4x);
    int maxp = wxMax(p2x, p3x);

    mercatoroffset.x = -minp;

    int mw = maxp - minp;

    PolarToMercator(polarpole.x, 0, p5x, p5y);
    PolarToMercator(polarpole.x, h, p6x, p6y);

    minp = wxMin(p1y, p2y);
    minp = wxMin(minp, p5y);

    mercatoroffset.y = -minp;

    maxp = wxMax(p3y, p4y);
    maxp = wxMax(maxp, p6y);

    int mh = maxp - minp;

/* now generate mercator image from polar image */
    m_wfimg.m_img.Create(mw, mh);
    unsigned char *d = m_wfimg.m_origimg.GetData(), *md = m_wfimg.m_img.GetData();
    for(int x=0; x<mw; x++)
        for(int y=0; y<mh; y++) {
            double px, py;
            unsigned char *cd = md + 3*(y*mw + x);

            MercatorToPolar(x, y, px, py);

            if(px >= 0 && py >= 0 && px < w-1 && py < h-1)
#if 1
                ImageInterpolatedValueMono
#elif 1                
                ImageInterpolatedValue
#else
                ImageValue
#endif
                    (d, w, px, py, cd);
            else
                cd[0] = cd[1] = cd[2] = 255;
        }

    m_swFaxArea->SetScrollbars(1, 1, m_wfimg.m_img.GetWidth(), m_wfimg.m_img.GetHeight()-1);
}
