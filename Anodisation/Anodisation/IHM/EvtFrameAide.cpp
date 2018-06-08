#include "EvtFrameAide.h"

EvtFrameAide::EvtFrameAide( wxWindow* parent )
:
FrameAide( parent )
{
    // 
}

void EvtFrameAide::OnCloseFrame( wxCloseEvent& event )
{
// TODO: Implement OnCloseFrame
Destroy();
}

void EvtFrameAide::OnOkButtonClick( wxCommandEvent& event )
{
// TODO: Implement OnOkButtonClick
Destroy();
}
