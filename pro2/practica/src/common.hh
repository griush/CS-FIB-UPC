/** @file common.hh

    @brief Contiene algunas definiciones que son usadas por la mayoria de
   modulos.
*/

#ifndef COMMON_HH
#define COMMON_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/// @brief Muestra un mensaje de error y detiene la ejecución del programa.
/// @pre cierto
/// @post La ejecución del programa se detiene. Se ha escrito el mensaje m en la
/// salida estándar.
inline void panic(const char* const m) {
    std::cout << m << std::endl;
    exit(1);
}

#endif  // COMMON_HH
