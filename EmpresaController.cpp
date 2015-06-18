#include "EmpresaController.h"

// constructor
EmpresaController::EmpresaController()
{

}

EmpresaController *EmpresaController::getInstance()
{
	if (this->instance == NULL) {
		this->instance = new EmpresaController();
	}
	return this->instance;
}

void EmpresaController::AltaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales,
        	Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios,
        	DataAsignatura *asignaturas)
{

}

ICollection* EmpresaController::ListarEmpresas()
{
	return NULL;
}

ICollection *EmpresaController::ListarSucursales()
{
	return this->empresa->getDataSucursales();
}

ICollection* EmpresaController::ListarSecciones()
{
	return NULL;
}

Empresa* EmpresaController::getEmpresa()
{
    return this->empresa;
}

Sucursal* EmpresaController::getSucursal()
{
    return this->sucursal;
}

Seccion* EmpresaController::getSeccion()
{
    return this->seccion;
}

void EmpresaController::SeleccionarEmpresa(string rut)
{
	ManejadorEmpresa *me = ManejadorEmpresa::getInstance();
	this->empresa = me->getEmpresa(rut);
	// para borrar la memoria, tenemos que llamar al constru x copia
//	delete me;
}

void EmpresaController::SeleccionarSucursal(string nombre)
{
	this->sucursal = this->empresa->getSucursal(nombre);
}

void EmpresaController::SeleccionarSeccion(string nombre)
{

}

void EmpresaController::destroyEmpresaController()
{
     if (instance != NULL)
     {
        delete EmpresaController;
     }
}

EmpresaController::~EmpresaController()
{
    //dtor
    delete instance;
    instance = NULL;
}
