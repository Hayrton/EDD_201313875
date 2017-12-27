using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de NodoCabecera
/// </summary>
public class NodoCabecera
{
    public NodoCabecera siguiente;
    public NodoCabecera anterior;
    public NodoCabecera acceso;
    public int dato;

    public NodoCabecera(int dato)
    {
        this.dato = dato;
        this.siguiente = null;
        this.anterior = null;
    }
}