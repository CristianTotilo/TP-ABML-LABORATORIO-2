#ifndef ESTRUC_H_INCLUDED
#define ESTRUC_H_INCLUDED

struct Alumno
{
    char legajo[20];
    char alumno[50];
    char dia[3];
    char mes[3];
    char anio[5];
    bool estado=false;
};

struct Materia
{
    char idmateria[20];
    char materia[50];
    char profesor[50];
    bool estado=false;
};

struct materiaxalumno
{
    char idmateria[20];
    char legajo[20];
    bool estado=false;
};

#endif // ESTRUC_H_INCLUDED
