#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



enum TIPOTABLAHASH{
    CAD_ENT=1,
    ENT_ENT,
    CAD_CAD,
    ENT_CAD,
    SALIRTIPO
    };

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


template<typename C, typename V>
class TablaHashDirA;

template <typename C, typename V>
void MenuOperaciones(TablaHashDirA<C, V>& T);

void MenuTipo();

int TipoTabla();


#endif // MENU_H_INCLUDED
