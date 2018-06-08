#include "EvtMyDialogAide.h"

EvtMyDialogAide::EvtMyDialogAide(wxWindow* parent) : MyDialogAide(parent)
{
}

void EvtMyDialogAide::OnDialogClose(wxCloseEvent& event)
{
    // TODO: Implement OnDialogClose
    Destroy();
}

void EvtMyDialogAide::OnOKButtonClick(wxCommandEvent& event)
{
    // TODO: Implement OnOKButtonClick
    Destroy();
}
