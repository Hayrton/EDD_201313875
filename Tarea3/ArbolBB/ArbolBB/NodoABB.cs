using System;
using System.Collections.Generic;
using System.Text;

namespace ArbolBB
{
    class NodoABB
    {
        public NodoABB izq;
        public NodoABB der;
        public int dato;

        public NodoABB(int dato)
        {
            this.dato = dato;
            this.izq = null;
            this.der = null;
        }
    }
}
