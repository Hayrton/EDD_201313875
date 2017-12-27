using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de Matriz
/// </summary>
public class Matriz
{
    Cabecera cabecera;
    Lateral lateral;

    public Matriz()
    {
        this.cabecera = new Cabecera();
        this.lateral = new Lateral();
    }

    public void inserta(int x, int y, int nivel, string dato)
    {
        NodoDisperso nuevo = new NodoDisperso(x,y,nivel,dato);
        NodoCabecera cab = cabecera.getNodoC(x);
        if(cab == null)
        {
            cab = new NodoCabecera(x);
            cabecera.agregarCabecera(cab);
        }
        else
        {
            if(cab.dato < x)
            {
                cab.anterior = nuevo;
                nuevo.derecho = cab;
            }
            NodoCabecera actual = 
        }

    }
}