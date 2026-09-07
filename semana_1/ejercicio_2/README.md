# ejercicio_2

Plantilla de proyecto en C++ replicada desde `ejercicio_1`, adaptada a esta subcarpeta (`ejercicio_2`).

## Estructura
- `apps/app_main.cpp`      -> programa principal (punto de entrada `main`)
- `include/ejercicio_2.h`  -> definición de structs y declaración de métodos
- `src/ejercicio_2.cpp`    -> implementación de los métodos
- `Makefile`              -> reglas de compilación
- `bin/ejercicio_2`       -> ejecutable generado
- `obj/`                  -> archivos objeto intermedios

## Qué cambia respecto a `ejercicio_1`
Lo único que varía entre subcarpetas es el nombre de los archivos y las
referencias internas, todas alineadas al nombre de la carpeta (`ejercicio_2`):

| Elemento                    | Valor en esta subcarpeta        |
|-----------------------------|---------------------------------|
| Header                      | `include/ejercicio_2.h`     |
| Guarda de inclusión         | `EJERCICIO_2_H`      |
| Implementación              | `src/ejercicio_2.cpp`       |
| `#include` en `.cpp` y app   | `#include "ejercicio_2.h"`  |
| `TARGET` del Makefile        | `bin/ejercicio_2`           |
| `.o` del Makefile            | `obj/ejercicio_2.o`         |

## Compilar y ejecutar
```bash
make
./bin/ejercicio_2
# o directamente:
make run
```

## Limpiar
```bash
make clean
```
