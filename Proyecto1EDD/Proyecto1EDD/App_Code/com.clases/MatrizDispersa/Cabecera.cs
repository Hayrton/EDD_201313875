using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de Cabecera
/// </summary>
public class Cabecera
{
    NodoCabecera primero;
    NodoCabecera ultimo;

    public Cabecera()
    {
        this.primero = null;
        this.ultimo = null;
    }

    public void agregarCabecera(NodoCabecera nuevo)
    {
        if(primero == null)
        {
            primero = nuevo;
            ultimo = primero;
        }
        else
        {
            ultimo.siguiente = nuevo;
            nuevo.anterior = ultimo;
            ultimo = nuevo;
        }
    }

    public void eliminarCabecera(int dato)
    {
        if (primero == null)
        {
            Console.WriteLine("cabecera inexistente");
        }
        else
        {
            NodoCabecera temp = primero;
            NodoCabecera aux = null;
            while (temp != null)
            {
                if (temp.dato == dato)
                {
                    if (aux == null)
                    {
                        primero = primero.siguiente;
                        temp.siguiente = null;
                        temp = primero;
                    }
                    else
                    {
                        aux.siguiente = temp.siguiente;
                        temp.siguiente = null;
                        temp = aux.siguiente;
                    }
                }
                else
                {
                    aux = temp;
                    temp = temp.siguiente;
                }
            }
        }
    }

    public void mostrar()
    {
        if (primero == null)
        {
            Console.WriteLine("cabecera inexistente");
        }
        else
        {
            NodoCabecera tmp = primero;
            while (tmp != null)
            {
                Console.WriteLine("dato: " + tmp.dato);
                tmp = tmp.siguiente;
            }
        }
    }

    public NodoCabecera getNodoC(int dato)
    {
        NodoCabecera actual = primero;
        while(actual != null)
        {
            if (actual.dato == dato)
                return actual;
            actual = actual.siguiente;
        }
        return null;
    }
}