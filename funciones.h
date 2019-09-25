#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///--------------------------------------FUNCIONES GENERALES-------------------------------------------


/*int contarRegistros(char archivo[20], estructura)
{
    FILE *p;
    int cantbyte;
    p=fopen(archivo,"rb");
    if(p==NULL)
    {
        cout<<"Error de archivo";
        return-1;
    }
    fseek(p,0,2);
    cantbyte=ftell(p);
    fclose(p);
    cantbyte=cantbyte/sizeof (struct estructura);
    return cantbyte;
}*/

///---------------------------------------------ALTA MATERIA--------------------------------------------

bool grabarMateria(struct Materia reg)
{
    FILE *p;
    p=fopen("materia.dat", "ab");
    if(p==NULL)
        return false;
    bool guardo=fwrite(&reg, sizeof (Materia), 1, p);
    fclose(p);
    return guardo;
}

void cargarMateria(struct Materia *preg)
{
    system("cls");
    cout<<"idmateria: "<<endl;
    cout<<"-> ";
    getline(preg->idmateria,20);
    cout<<"ingrese el nombre de la materia: "<<endl;
    cout<<"-> ";
    getline(preg->materia,50);
    cout<<"ingrese el nombre del profesor"<<endl;
    cout<<"-> ";
    getline(preg->profesor,50);

    preg->estado=true;
}

bool altaMateria()
{
    struct Materia reg;
    cargarMateria(&reg);
    if(grabarMateria(reg))
    {
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else
    {
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
    }
}

///--------------------------------LISTAR MATERIAS-------------------------------------------------

void mostrarMateria(struct Materia reg)
{
    if(reg.estado==true)
    {
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"id de la materia ";
        cout<<reg.idmateria<<endl;
        cout<<"nombre de la materia: ";
        cout<<reg.materia<<endl;
        cout<<"nombre del profesor: ";
        cout<<reg.profesor<<endl;
    }
    else
    {
        cout<<"el registro no existe"<<endl;
    }
}
void listarMaterias()
{
    FILE *p;
    struct Materia reg;
    p=fopen("materia.dat", "rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&reg, sizeof(Materia),1, p)!=0)
    {
        mostrarMateria(reg);
        cout<<endl;
    }
    fclose(p);
}

///---------------------------------------ALTA DE ALUMNOS-------------------------------------------

bool grabarAlumno(struct Alumno reg)
{
    FILE *p;
    p=fopen("alumno.dat", "ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(&reg, sizeof(Alumno), 1, p);
    fclose(p);
    return escribio;
}

bool cargarAlumno(struct Alumno *preg)
{
    system("cls");
    cout<<"ingrese legajo: "<<endl;
    cout<<"-> ";
    getline(preg->legajo,20);
    cout<<"ingrese el nombre del alumno: "<<endl;
    cout<<"-> ";
    getline(preg->alumno,50);

    cout<<"ingrese el dia de nacimiento"<<endl;
    cout<<"-> ";
    getline(preg->dia,3);
    cout<<"ingrese el mes de nacimento"<<endl;
    cout<<"-> ";
    getline(preg->mes,3);
    cout<<"ingrese el anio de nacimiento"<<endl;
    cout<<"-> ";
    getline(preg->anio,5);

    preg->estado=true;

    return true;
}

bool altaAlumno()
{
    struct Alumno reg;
    cargarAlumno(&reg);
    if(grabarAlumno(reg))
    {
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else
    {
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
    }
}


///----------------------------------------LISTAR ALUMNOS-----------------------------------

void listarFechaNacimiento(struct Alumno reg)
{
    cout<<"Fecha de nacimiento: ";
    cout<<reg.dia<<"/";
    cout<<reg.mes<<"/";
    cout<<reg.anio<<endl;
}

void mostrarAlumno(struct Alumno reg)
{
    if(reg.estado==true)
    {
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Legajo del alumno: ";
        cout<<reg.legajo<<endl;
        cout<<"nombre del alumno: ";
        cout<<reg.alumno<<endl;
        listarFechaNacimiento(reg);

    }
    else
    {
        cout<<"El registro no existe"<<endl;
    }
}


void listarAlumnos()
{
    FILE *p;
    struct Alumno reg;
    p=fopen("alumno.dat", "rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;

    }
    while(fread(&reg, sizeof(Alumno), 1, p)==1)
    {
        mostrarAlumno(reg);
        cout<<endl;
    }
    fclose(p);
}

///--------------------------------ASIGNAR ALUMNOS A MATERIAS--------------------------------

void asignarAlumnos()
{
    struct materiaxalumno reg;
    bool valido=false;
    bool validar=false;
    bool salir=false;
    bool salir2=false;
    FILE *p;
    p=fopen("materiaxalumno.dat","ab" );
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        fclose(p);
        return;
    }
    while(!salir)
    {
        system("cls");
        cout<<"ingrese el legajo del alumno que quiere asignar: ";
        getline(reg.legajo,20);
        validar=validarAlumno(reg.legajo,&salir);
        cin.ignore();
        cout<<endl;
    }
    if(!validar)
    {
        salir2=true;
    }
    while(!salir2)
    {

        cout<<"ingrese el id de la materia a la cual queire asignar al alumno:  ";
        getline(reg.idmateria,20);
        validar=validarMateria(reg.idmateria,&salir2);
        cin.ignore();
        cout<<endl;
        if(validar)
        {
            reg.estado= true;
        }
    }
    if(reg.estado)
    {
        bool escribio=fwrite(&reg,sizeof(materiaxalumno),1,p);
        if(escribio)
        {
            cout<<"el registro fue cargado en la base de datos"<<endl;
        }
        else
        {
            cout<<"No se pudo grabar el registro"<<endl;
        }
    }

    fclose(p);
}


///--------------------------------LISTAR ALUMNOS POR MATERIAS--------------------------------

void mostrarMateriaPorAlumno(struct materiaxalumno reg)
{
    if (reg.estado==true)
    {
        cout<<"-------------------------------------------"<<endl;
        cout<<"Alumno :";
        cout<<reg.legajo<<endl;
        cout<<"Materia :";
        cout<<reg.idmateria<<endl;
    }
    else
    {
        cout<<"El registro no existe"<<endl;
    }
}

void listarMateriaPorAlumno()
{
    FILE *p;
    struct materiaxalumno reg;
    p=fopen("materiaxalumno.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&reg, sizeof reg,1,p)!=0)
    {
        mostrarMateriaPorAlumno(reg);
        cout<<endl;

    }
    fclose(p);
}

///--------------------------------MODIFICAR ALUMNO--------------------------------

void modificarAlumno()
{
    struct Alumno reg;
    char legajo[20];
    int pos;
    bool valido=false;
    FILE *p;

    cout<<"ingrese el legajo del alumno que quiere modificar: "<<endl;
    getline(legajo,20) ;
    validarAlumno(legajo,&valido);
    if(valido)
    {
        p=fopen("alumno.dat","rb+");
        if(p==NULL)
        {
            cout<<"ERROR DE ARCHIVO"<<endl;
            return;
        }
        while(fread(&reg,sizeof reg,1,p)!=0)
        {
            if(strcmp(reg.legajo,legajo)==0)
            {
                pos=ftell(p)/sizeof (Alumno);
                pos--;
                fseek(p,pos*sizeof(Alumno),SEEK_SET);
                system("PAUSE");
                subMenuModificarAlumno(&reg);
                bool guardo=fwrite(&reg,sizeof (Alumno),1,p);
                if(guardo)
                {
                    cout<<"REGISTRO AGREGADO"<<endl;
                }
                else
                {
                    cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                }
                fclose(p);
                return;
            }
        }
        fclose(p);
        return;
    }
}

///---------------------------------------DAR DE BAJA ALUMNO A UNA MATERIA--------------------------------------------

bool eliminarRegistro(char legajo[20])
{
    char op;
    struct materiaxalumno reg;
    FILE *p;
    p=fopen("materiaxalumno.dat","rb+");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        fclose(p);
        return false;
    }
    else
    {
        while(fread(&reg,sizeof(materiaxalumno),1,p))
        {
            if(strcmp(legajo,reg.legajo)==0)
            {

                cout<<"desea eleminiar el registro? S/N"<<endl;
                cin>>op;
                switch(op)
                {
                case 'N':
                case 'n':
                    fclose(p);
                    return false;
                    break;
                case 'S':
                case 's':
                    int pos;
                    reg.estado=false;
                    pos=ftell(p)/sizeof(materiaxalumno);
                    pos--;
                    fseek(p,pos*sizeof(materiaxalumno),SEEK_SET);
                    fwrite(&reg,sizeof(materiaxalumno),1,p);
                    fclose(p);
                    return true;
                    break;
                default:
                    cout<<"ingreso no valido"<<endl;
                    break;
                }
            }
        }

    }
}

bool validarAlumnoPorMateria(char legajo[20], bool *salir)
{
    struct materiaxalumno reg;
    FILE *p;
    p=fopen("materiaxalumno.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        fclose(p);
        *salir=true;
        return false;
    }
    else
    {
        while(fread(&reg,sizeof(materiaxalumno),1,p))
        {
            if(strcmp(legajo,reg.legajo)==0)
            {
                system("cls");
                cout<<"Se encontro el legajo ingresado: ";
                cout<<reg.legajo<<endl;
                cout<<"De la materia ID: ";
                cout<<reg.idmateria<<endl;
                fclose(p);
                *salir=true;
                return true;
            }
            else
            {
                system("cls");
                cout<<"No se encontro el legajo ingresado"<<endl;
                cin.ignore();
                cout<<"desea intentar nuevamente? S/N: ";
                char op;
                cin>>op;
                switch(op)
                {
                case 's':
                case 'S':
                    *salir=false;
                    break;
                case 'n':
                case 'N':
                    *salir=true;
                    break;
                default:
                    cout<<"ingreso no valido"<<endl;
                    break;
                }
            }
        }
    }
    fclose(p);
    *salir=true;
    return false;
}

void eliminarAlumnoPorMateria()
{
    bool elimino=false;
    bool validar=false;
    bool salir=false;
    char legajo[20];
    while(!salir)
    {
        cout<<"ingrese el legajo del alumno que quiere dar de baja: "<<endl;
        getline(legajo,20) ;
        validar=validarAlumnoPorMateria(legajo,&salir);
    }
    if(validar)
    {
        elimino=eliminarRegistro(legajo);
        if(elimino)
        {
            cout<<"El registro fue eliminado correctamente"<<endl;
        }
        else
        {
            cout<<"No se pudo eliminar el registro"<<endl;
        }
    }
}

#endif // FUNCIONES_H_INCLUDED
