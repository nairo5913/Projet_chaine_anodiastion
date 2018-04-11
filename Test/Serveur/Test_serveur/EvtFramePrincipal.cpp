#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal( wxWindow* parent )
:
FramePrincipal( parent )
{
    //Initialisation de la communication avec le convertisseur
   	I2C = new AccesI2C();
}
