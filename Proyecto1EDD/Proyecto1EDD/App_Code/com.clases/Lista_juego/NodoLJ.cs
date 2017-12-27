using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de NodoLJ
/// </summary>
public class NodoLJ
{
    public NodoLJ siguiente;
    public NodoLJ anterior;
    public int dato;
    public ListaDJuego DATOLISTA;

    public NodoLJ(ListaDJuego DATO)
    {
        this.DATOLISTA = DATO;
        this.siguiente = null;
        this.anterior = null;
    }
}