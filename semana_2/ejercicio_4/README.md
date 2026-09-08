# ejercicio_4

Plantilla de proyecto en C++ replicada desde `ejercicio_1`, adaptada a esta subcarpeta (`ejercicio_4`).

## Estructura
- `apps/app_main.cpp`      -> programa principal (punto de entrada `main`)
- `include/ejercicio_4.h`  -> definición de structs y declaración de métodos
- `src/ejercicio_4.cpp`    -> implementación de los métodos
- `Makefile`              -> reglas de compilación
- `bin/ejercicio_4`       -> ejecutable generado
- `obj/`                  -> archivos objeto intermedios

## Qué cambia respecto a `ejercicio_1`
Lo único que varía entre subcarpetas es el nombre de los archivos y las
referencias internas, todas alineadas al nombre de la carpeta (`ejercicio_4`):

| Elemento                    | Valor en esta subcarpeta        |
|-----------------------------|---------------------------------|
| Header                      | `include/ejercicio_4.h`     |
| Guarda de inclusión         | `EJERCICIO_4_H`      |
| Implementación              | `src/ejercicio_4.cpp`       |
| `#include` en `.cpp` y app   | `#include "ejercicio_4.h"`  |
| `TARGET` del Makefile        | `bin/ejercicio_4`           |
| `.o` del Makefile            | `obj/ejercicio_4.o`         |

## Compilar y ejecutar
```bash
make
./bin/ejercicio_4
# o directamente:
make run
```

## Limpiar
```bash
make clean
```
