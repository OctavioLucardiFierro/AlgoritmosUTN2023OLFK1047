* lineaDeCajas.hpp
 *
 *  Created on: 06/10/2023
 *      Author: alumno
 */

#ifndef LINEADECAJAS_HPP_
#define LINEADECAJAS_HPP_
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

struct Mov
{
   int caja;
   char mov; // 'E' => Entra, 'S' => Sale
   int hora; // hhmm
};
struct Caja
{
   int id;
   int cantHoras;
   int inicioDeOcio;
   int cantTotal;
   int horasOciosas;
   int cantMaxima;
   Queue<int> cola = queue<int>();
};
#endif /* LINEADECAJAS_HPP_ */
