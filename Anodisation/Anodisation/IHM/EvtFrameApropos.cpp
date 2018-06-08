#include "EvtFrameApropos.h"

EvtFrameApropos::EvtFrameApropos( wxWindow* parent )
:
FrameApropos( parent )
{
    //
}

void EvtFrameApropos::OnCloseFrame( wxCloseEvent& event )
{
// TODO: Implement OnCloseFrame
Destroy();
}

void EvtFrameApropos::OnOkButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnOkButtonClick
Destroy();
}
