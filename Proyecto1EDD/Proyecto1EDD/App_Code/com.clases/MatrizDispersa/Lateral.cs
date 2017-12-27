using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de Lateral
/// </summary>
public class Lateral
{
    public NodoLateral primero;
    public NodoLateral ultimo;
    public Lateral()
    {
        this.primero = null;
        this.ultimo = null;
    }

    public void agregarLateral(int dato)
    {
        NodoLateral nuevo = new NodoLateral(dato);
        if(primero == null)
        {
            primero = nuevo;
            ultimo = primero;
        }
        else
        {
            ultimo.abajo = nuevo;
            nuevo.arriba = ultimo;
            ultimo = nuevo;
        }
    }

    public void eliminarLateral(int dato)
    {
        if (primero == null)
        {
            Console.WriteLine("lateral inexistente");
        }
        else
        {
            NodoLateral temp = primero;
            NodoLateral aux = null;
            while (temp != null)
            {
                if (temp.dato == dato)
                {
                    if (aux == null)
                    {
                        primero = primero.abajo;
                        temp.abajo = null;
                        temp = primero;
                    }
                    else
                    {
                        aux.abajo = temp.abajo;
                        temp.abajo = null;
                        temp = aux.abajo;
                    }
                }
                else
                {
                    aux = temp;
                    temp = temp.abajo;
                }
            }
        }
    }

    public void mostrar()
    {
        if (primero == null)
        {
            Console.WriteLine("lateral inexistente");
        }
        else
        {
            NodoLateral tmp = primero;
            while (tmp != null)
            {
                Console.WriteLine("dato: " + tmp.dato);
                tmp = tmp.abajo;
            }
        }
    }
}