using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de NodoColumna
/// </summary>
public class NodoColumna
{
    public NodoColumna arriba;
    public NodoColumna abajo;
    public int dato;
    public NodoColumna(int dato)
    {
        this.dato = dato;
        this.abajo = null;
        this.arriba = null;
    }
}