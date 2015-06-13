#ifndef IOFERTALABORALCONTROLLER_H
#define IOFERTALABORALCONTROLLER_H

#include <string>
#include "Date.h"
#include "DataOfertaLaboral.h"
#include "ICollection.h"

using namespace std;

//Interfaz
class IOfertaLaboralController {
    public:
        virtual ICollection* ListarOfertas() = 0;
        virtual DataOfertaLaboral SeleccionarOferta(string numExpediente) = 0;
        virtual void Inscribir(Date* fechaInscripcion) = 0;
        virtual void Entrevistar(Date* fechaEntrevista) = 0;
        virtual ICollection* MostrarOfertasActivas() = 0;
        virtual void AltaAsignacionDelCargo()=0;
        virtual void DarBajaLlamado() = 0;
        virtual ~IOfertaLaboralController(){}; //virtual y vacio
};

#endif // IOFERTALABORALCONTROLLER_H
