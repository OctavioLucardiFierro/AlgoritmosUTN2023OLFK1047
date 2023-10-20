* lineaDeCaja.cpp
 *
 *  Created on: 06/10/2023
 *      Author: alumno
 */
#ifndef LINEADECAJAS_CPP_
#define LINEADECAJAS_CPP_
#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/MultidimColl.hpp"
#include "lineaDeCajas.hpp"

int diferenciaDeHoras(int hora1, int hora2)
{

   return 0;
}

void emitirLista(Map<int,Caja> mCaja)
{
   while(mapHasNext(mCaja))
   {
      Caja* c = mapNextValue<int,Caja>(mCaja);
      int i = mapNextKey<int,Caja>(mCaja);
      cout<<"Caja número: "<< i<<endl;
      cout<<"Tiempo promedio de espera: "<<c->cantHoras/c->cantTotal<<endl;
      cout<<"Tiempo de ocio: "<<c->horasOciosas<<endl;
      cout<<"Longitud máxima de la cola: "<<c->cantMaxima<<endl;
   }
}

int main()
{
   FILE* f = fopen("MOVIMIENTOS.DAT","r+b");

   Map<int,Caja> mCaja = map<int,Caja>();
   Mov m = read<Mov>(f);
   while(!feof(f))
   {
      Caja caja;
      caja.cantHoras = 0;
      caja.horasOciosas = 0;
      caja.id = m.caja;
      caja.cantMaxima = 0;
      Caja* c = mapDiscover<int,Caja>(mCaja,m.caja,caja);
      if(m.mov == 'E')
      {
         if(queueIsEmpty(c->cola))
        {
            caja.horasOciosas += m.hora - c->inicioDeOcio;
        }

         queueEnqueue(c->cola,m.hora);
         caja.cantTotal++;

      }
      if(m.mov == 'S')
      {
         int tiempoEntrada = queueDequeue(c->cola);
         int tiempoEnCaja = diferenciaDeHoras(m.hora, tiempoEntrada);
         c->cantHoras+= tiempoEnCaja;
         if(queueIsEmpty(c->cola))
               {
                  c->inicioDeOcio = m.hora;
               }

      }
      if (queueSize(c->cola)>c->cantMaxima)
      {
         c->cantMaxima = queueSize(c->cola);
      }
   }
   emitirLista(mCaja);
}




