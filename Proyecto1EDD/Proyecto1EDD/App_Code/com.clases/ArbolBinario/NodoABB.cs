using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de NodoABB
/// </summary>
public class NodoABB
{
    public NodoABB izquierda;
    public NodoABB derecha;
    public Usuario usuario;
    public NodoABB(Usuario usuario)
    {
        this.usuario = usuario;
        this.izquierda = null;
        this.derecha = null;
    }
}