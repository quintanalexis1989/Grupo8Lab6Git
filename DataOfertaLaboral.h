#ifndef DATAOFERTALABORAL_H
#define DATAOFERTALABORAL_H

#include "Date.h"
#include "Rango.h"
#include <string>
#include "interfaces/ICollectible.h"

using namespace std;

class DataOfertaLaboral: public ICollectible
{
    public:
		DataOfertaLaboral();
        DataOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales,
                        Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios,
                        IDictionary *asignaturas, Seccion* seccion, ICollection *inscripciones, ICollection *entrevistas);
        DataOfertaLaboral(const DataOfertaLaboral &dol);
        ~DataOfertaLaboral();
        string getNumExpediente();
        string getTitulo();
        string getDescripcion();
        int getCantidadHorasSemanales();
        Rango *getRangoSalarial();
        Date *getFechaComienzo();
        Date *getFechaFin();
        int getCantidadPuestosNecesarios();
        Seccion* getSeccion();
        ICollection *getInscripciones();
        ICollection *getEntrevistas();
        IDictionary *getAsignaturas();
    private:
        string numExpediente;
        string titulo;
        string descripcion;
        int cantidadHorasSemanales;
        Rango *rangoSalarial;
        Date *fechaComienzo;
        Date *fechaFin;
        int cantidadPuestosNecesarios;
        Seccion* seccion;
        ICollection *inscripciones;
        ICollection *entrevistas;
        IDictionary *asignaturas;
};

#endif // DATAOFERTALABORAL_H
