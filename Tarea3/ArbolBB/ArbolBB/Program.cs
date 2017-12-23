using System;

namespace ArbolBB
{
    class Program
    {
    	
        static void Main(string[] args)
        {
            Arbol arbol = new Arbol();
            int opcion = 0;
            int dato;
            do
            {
                //Console.Clear();
                Console.WriteLine("  Menu de Arbol Binario de Busqueda");
                Console.WriteLine("   1.- Ingresar Dato");
                Console.WriteLine("   2.- Recorrido en Pre-Orden");
                Console.WriteLine("   3.- Recorrido en In-Orden");
                Console.WriteLine("   4.- Recorrido en Post-Orden");
                Console.WriteLine("   5.- Salir");
                Console.WriteLine("");
                Console.Write("  Seleccione Opcion: ");
                opcion = int.Parse(Console.ReadLine());
                switch (opcion)
                {
                    case 1:
                        Console.Write("Ingrese un Dato: ");
                        dato = int.Parse(Console.ReadLine());
                        arbol.Insertar(dato);
                        Console.WriteLine("");
                        break;
                    case 2:
                        Console.WriteLine("----------------------------------");
                        Console.WriteLine("Recorrido en PreOrden");
                        arbol.PreOrden(arbol.getRaiz());
                        Console.WriteLine("");
                        Console.WriteLine("----------------------------------");
                        break;
                    case 3:
                        Console.WriteLine("---------------------------------");
                        Console.WriteLine("Recorrido en InOrden");
                        arbol.EnOrden(arbol.getRaiz());
                        Console.WriteLine("");
                        Console.WriteLine("---------------------------------");
                        break;
                    case 4:
                        Console.WriteLine("---------------------------------");
                        Console.WriteLine("Recorrido en PostOrden");
                        arbol.PostOrden(arbol.getRaiz());
                        Console.WriteLine("");
                        Console.WriteLine("--------------------------------");
                        break;
                }
                Console.WriteLine("");
                Console.WriteLine("");
            } while (opcion != 5);
        }
    }
}
