using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de NodoLateral
/// </summary>
public class NodoLateral
{
    public NodoLateral arriba;
    public NodoLateral abajo;
    public int dato;
    public NodoLateral(int dato)
    {
        this.dato = dato;
        this.arriba = null;
        this.abajo = null;
    }
}