#ifndef UTILERIAS_H_INCLUDED
#define UTILERIAS_H_INCLUDED


//************************************************************************************************************************************************************
enum TIPOTABLAHASH{
    CAD_ENT=1,
    ENT_ENT,
    CAD_CAD,
    ENT_CAD,
    SALIRTIPO
    };
//************************************************************************************************************************************************************
enum OPERACIONES{
    AGREGAR = 1,
    ELIMINAR,
    BUSCAR,
    BUSCAR_VALOR,
    COLISIONES,
    NUMELEMENTOS,
    VACIAR,
    SEL_TABLA,
    SALIR
    };

//************************************************************************************************************************************************************
template<typename C, typename V>
class TablaHash;

template <typename C, typename V>
void OperacionesTablaHash(TablaHash<C, V>& T);

void GestionarTabla();

int TipoTabla();
//************************************************************************************************************************************************************

#endif // UTILERIAS_H_INCLUDED
