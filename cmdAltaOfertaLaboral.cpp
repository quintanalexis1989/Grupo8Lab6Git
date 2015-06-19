#include <iostream>
#include <string>
#include "cmdAltaOfertaLaboral.h"
#include "ManejadorEmpresa.h"
#include "EmpresaController.h"
#include "interfaces/ICollection.h"
#include "DataEmpresa.h"
#include "DataSucursal.h"
#include "DataSeccion.h"
#include "Fabrica.h"
#include "IEmpresaController.h"
#include "Integer.h"
#include "ManejadorEstudiante.h"

using namespace std;

cmdAltaOfertaLaboral::cmdAltaOfertaLaboral()
{
    //ctor
}

void cmdAltaOfertaLaboral::ejecutarComando()
{
    string rutEmpresa, nomSucursal, nomSeccion, descripcion, numExpe, titulo;
    int cantHorasSema, cantPuestos, salMinimo, salMaximo, ddCom, ddFin, mmCom, mmFin, aaaaCom, aaaaFin, codAsig;
    string respuesta;
    Fabrica* fab = Fabrica::getInstance();
    IEmpresaController* cEmpresa = fab->getIEmpresaController();
//    IEstudianteController* cEstudiante = fab->getIEstudianteController();

    try
    {
        ICollection* dataEmpresas = cEmpresa->ListarEmpresas();

        cout << "Lista de Empresas:\n";
        IIterator * it = dataEmpresas->getIterator();
        while(it->hasCurrent())
        {
            DataEmpresa *dEmpresa;
            if( (dEmpresa = dynamic_cast<DataEmpresa*> (it->getCurrent())) != NULL )
            {
                cout << "Nombre: " + dEmpresa->getNombre() + ", RUT:" + dEmpresa->getRut() + "\n";
            }
            else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataEmpresa.";
            }
            it->next();
        }
        delete it;
        cout<< "Seleccione una Empresa indicando el RUT\n";
        cin >> rutEmpresa;
        cEmpresa->SeleccionarEmpresa(rutEmpresa);


        ICollection* dataSucursales = cEmpresa->ListarSucursales();
        cout << "Lista de Sucursales:\n";

        IIterator * it2 = dataSucursales->getIterator();
        while(it2->hasCurrent())
        {
            DataSucursal *dSucursal;
            if( (dSucursal = dynamic_cast<DataSucursal*> (it2->getCurrent())) != NULL )
            {
                cout << "Nombre: " + dSucursal->getNombre() + "\n";
            } else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataSucursal.";
            }
            it2->next();
        }
        delete it2;

        cout<< "Seleccione una Sucursal indicando el nombre\n";
        cin >> nomSucursal;
        cEmpresa->SeleccionarSucursal(nomSucursal);

        ICollection* dataSecciones = cEmpresa->ListarSecciones();
        cout<< "Lista de Secciones:\n";
        IIterator * it3 = dataSecciones->getIterator();
        while(it3->hasCurrent())
        {
            DataSeccion *dSeccion;
            if( (dSeccion = dynamic_cast<DataSeccion*> (it3->getCurrent())) != NULL )
            {
                cout << "Nombre: " + dSeccion->getNombre() + "\n";
            } else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataSeccion.";
            }
            it3->next();
        }
        delete it3;

        cout<< "Seleccione una Secci�n indicando su nombre\n";
        cin >> nomSeccion;
        cEmpresa->SeleccionarSeccion(nomSeccion);

        cout<< "Ingrese los datos correspondientes a la nueva Oferta Laboral\n";
        cout<< "\n";
        cout<< "Numero de expediente: ";
        cin >> numExpe;
        cout<< "\nTitulo: ";
        cin >> titulo;
        cout<< "\nDescripcion: ";
        cin >> descripcion;
        cout<< "\nCantidad de horas semanales: ";
        cin >> cantHorasSema;
        cout<< "\nSalario minimo: ";
        cin >> salMinimo;
        cout<< "\nSalario maximo: ";
        cin >> salMaximo;
        Rango* rangoSalarial = new Rango(salMinimo, salMaximo);
        cout<< "\nFecha de comienzo(dd mm aaaa): ";
        cin >> ddCom >> mmCom >> aaaaCom;
        cout<< "\nFecha de fin(dd mm aaaa): ";
        cin >> ddFin >> mmFin >> aaaaFin;
        Date* fechaComienzo = new Date(ddCom, mmCom, aaaaCom);
        Date* fechaFin = new Date(ddFin, mmFin, aaaaFin);
        cout<< "\nCantidad de puestos necesarios: ";
        cin >> cantPuestos;

        // doy de alta la oferta
        cEmpresa->altaOfertaLaboral(numExpe, titulo, descripcion, cantHorasSema, rangoSalarial, fechaComienzo, fechaFin, cantPuestos, NULL);

        // obtengo la lista de ofertas de la empresa/seccion
        IDictionary *ofertasDadasDeAlta = cEmpresa->getSeccion()->getOfertasLaborales();

        // busco la oferta en el dictionary
        OfertaLaboral *ol = ofertasDadasDeAlta->find(numExpe);

        // obtengo el dictionary de asignaturas de esa oferta
        IDictionary *asignaturasEnOferta = ol->getAsignaturas();

        //Solicitar Asignaturas
        cout<< "\nAsignaturas:";
        bool desea = true;
        bool strategyOK = false;

        ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
        IDictionary *asignaturasIngresadas = me->getAsignaturas();

        while (!strategyOK)
        {
            while (desea)
            {
                // muestro asignaturas
                cout << "Lista de Asignaturas:\n";
                IIterator * it = asignaturasIngresadas->getIterator();
                while(it->hasCurrent())
                {
                    DataAsignatura *dAsignatura;
                    if( (dAsignatura = dynamic_cast<DataAsignatura*> (it->getCurrent())) != NULL )
                    {
                        cout << "CODIGO: " + std::to_string(dAsignatura->getCodigo()) + ", NOMBRE:" + dAsignatura->getNombre() + "\n";
                    }
                    else
                    {
                        throw "AltaOfertaLaboral -> El objeto no es de la clase DataAsignatura.";
                    }
                    it->next();
                }
                delete it;

                // pido asignatura
                cout<< "\n  Ingrese el codigo: ";
                cin >> codAsig;
                Integer* codigo = new Integer(codAsig);

                // busco la asignatura
                if (asignaturasIngresadas->member(codigo))
                {
                    // la agrego
                    asignaturasEnOferta->add(codigo, asignaturasEnOferta);
                } else {
                    throw "Codigo de Asignatura incorrecto.";
                }

                // seguir ingresando
                cout<< "\n  Desea ingresar otra asignatura?(s/n): ";
                cin >> respuesta;
                if(respuesta == "n")
                {
                    desea = false;
                }
            }

            // strategy

            // aca hay que verificar los criterios del strategy y pedir que strategy usar


        }

    }
    catch (const char* e)
    {
    	throw;
    }


}

cmdAltaOfertaLaboral::~cmdAltaOfertaLaboral()
{
    //dtor
}
