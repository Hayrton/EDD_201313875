using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de NodoFila
/// </summary>
public class NodoFila
{
    public NodoFila siguiente;
    public NodoFila anterior;
    public int dato;
    public NodoFila(int dato)
    {
        this.dato = dato;
        this.siguiente = null;
        this.anterior = null;
    }
}