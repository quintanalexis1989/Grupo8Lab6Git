#include "DataAsignatura.h"

DataAsignatura::DataAsignatura()
{
    this->codigo = -1;
    this->nombre = '\0';
    this->creditos = 0;
}

DataAsignatura::DataAsignatura(int codigo, string nombre, int creditos)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->creditos = creditos;

}

DataAsignatura::DataAsignatura(const DataAsignatura &da)
{
    this->codigo = da.codigo;
    this->nombre = da.nombre;
    this->creditos = da.creditos;

}

int DataAsignatura::getCodigo()
{
	return this->codigo;
}

string DataAsignatura::getNombre()
{
	return this->nombre;
}

int DataAsignatura::getCreditos()
{
	return this->creditos;
}

DataAsignatura::~DataAsignatura()
{
    //dtor
    //vacio
}
