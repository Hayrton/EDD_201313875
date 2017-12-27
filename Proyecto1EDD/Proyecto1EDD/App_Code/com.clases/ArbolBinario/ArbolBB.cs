using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de ArbolBB
/// </summary>
public class ArbolBB
{
    NodoABB raiz;

    public ArbolBB()
    {
        this.raiz = null;
    }

    public void addUser(Usuario user)
    {
        if (raiz != null)
            addUser(user, raiz);
        else
            raiz = new NodoABB(user);
    }

    public void addUser(Usuario user, NodoABB temp)
    {
        if(string.Compare(user.nickname, temp.usuario.nickname)<0)
        {
            if (temp.izquierda != null)
                addUser(user, temp.izquierda);
            else
                temp.izquierda = new NodoABB(user);
        }else if (string.Compare(user.nickname, temp.usuario.nickname) > 0)
        {
            if (temp.derecha != null)
                addUser(user, temp.derecha);
            else
                temp.derecha = new NodoABB(user);
        }
    }

    public NodoABB Buscar(Usuario user)
    {
        if (raiz == null)
            return null;
        else
            return localizar(user, raiz);
    }

    public NodoABB localizar(Usuario user, NodoABB temp)
    {
        if (temp == null)
            return null;
        else if (string.Compare(user.nickname, temp.usuario.nickname) == 0)
            return raiz;
        else if (string.Compare(user.nickname, temp.usuario.nickname) < 0)
            return localizar(user, temp.izquierda);
        else 
            return localizar(user, temp.derecha);

    }

    public Boolean EliminarNodo(NodoABB temp)
    {
        bool conDerecha = temp.derecha != null ? true : false;
        bool conIzquierda = temp.izquierda != null ? true : false;

        if (!conDerecha && !conIzquierda)
            return removerNodoSinHijos(temp);
        if (conDerecha && !conIzquierda)
            return removerNodoConUnHijo(temp);
        if (!conDerecha && conIzquierda)
            return removerNodoConUnHijo(temp);
        if (conDerecha && conIzquierda)
            return removerNodoConHijos(temp);
        return false;
    }

    private Boolean removerNodoSinHijos(NodoABB temp) // eliminacion de nodo con ningun hijo
    {
        NodoABB HIzquierdo = temp.izquierda;
        NodoABB HDerecho = temp.derecha;

        if(HIzquierdo == temp)
        {
            temp.izquierda = null;
            return true;
        }
        if(HDerecho == temp)
        {
            temp.derecha = null;
            return true;
        }
        return false;
    }

    private Boolean removerNodoConUnHijo(NodoABB temp) // eliminacion de un nodo con un hijo
    {
        NodoABB HIzquierdo = temp.izquierda;
        NodoABB HDerecho = temp.derecha;

        NodoABB HActual = temp.izquierda != null ? temp.izquierda : temp.derecha;

        if(HIzquierdo == temp)
        {
            temp.izquierda = HActual;
            HActual = temp;
            temp.derecha = null;
            temp.izquierda = null;
            return true;
        }
        if(HDerecho == temp)
        {
            HActual = temp;
            temp.derecha = null;
            temp.izquierda = null;
            return true;
        }
        return false;
    }

    private Boolean removerNodoConHijos(NodoABB temp) // eliminacion de nodos con dos hijos
    {
        NodoABB MasIzq = recorrerIzq(temp.derecha);
        if(MasIzq == null)
        {
            temp.usuario = MasIzq.usuario;
            EliminarNodo(MasIzq);
            return true;
        }
        return false;
    }

    private NodoABB recorrerIzq(NodoABB temp)
    {
        if(temp.izquierda == null)
        {
            return recorrerIzq(temp.izquierda);
        }
        return temp;
    }

    public String PreOrdnen(NodoABB temp)
    {
        string dato = "";
        if(temp != null){
            dato = temp.usuario.nickname;
            PreOrdnen(temp.izquierda);
            PreOrdnen(temp.derecha);
        }
        return dato;
    }

    public String EnOrden(NodoABB temp)
    {
        string dato = "";
        if(temp != null)
        {
            EnOrden(temp.izquierda);
            dato = temp.usuario.nickname;
            EnOrden(temp.derecha);
        }
        return dato;
    }

    public String PostOrden(NodoABB temp)
    {
        string dato = "";
        if(temp != null)
        {
            PostOrden(temp.izquierda);
            PostOrden(temp.derecha);
            dato = temp.usuario.nickname;
        }
        return dato;
    }
}