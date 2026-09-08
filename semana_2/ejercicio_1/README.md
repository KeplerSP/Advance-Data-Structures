#  Tabla hash con encadenamiento y redimensionamiento dinámico

Este proyecto implementa una **lista enlazada simple** en C++ usando `structs` con constructores `{}`.

## 📂 Estructura
- `apps/app_main.cpp` → programa principal
- `include/lista_enlazada.h` → definición de structs y métodos
- `src/lista_enlazada.cpp` → implementación de métodos
- `bin/app_lista` → ejecutable
- `obj/` → archivos objeto
- `Makefile` → reglas de compilación

## 🚀 Compilar y ejecutar
```bash
make
./bin/app_lista
```

Implemente desde cero una tabla hash genérica utilizando direccionamiento cerrado. Cada posición de la tabla contendrá una lista enlazada creada por el estudiante.
Estructura de los registros
Estudiante:
    codigo: cadena
    nombres: cadena
    promedio: real
Requisitos
No utilizar map, dict, unordered_map, HashMap ni estructuras equivalentes.
Diseñar una función hash para claves de tipo cadena.
Implementar insertar(clave, valor), buscar(clave), eliminar(clave), actualizar(clave, valor) y contiene(clave).
Evitar claves duplicadas.
Mantener el factor de carga α = n/m.
Cuando α > 0.75, crear una tabla cuyo tamaño sea el siguiente número primo mayor que 2m.
Realizar el rehashing de todos los registros y contabilizar las colisiones producidas.
Ejemplo de operaciones
INSERTAR 20260001 Ana 16.5
INSERTAR 20260002 Luis 14.0
BUSCAR 20260001
ELIMINAR 20260002
ESTADISTICAS
La opción ESTADISTICAS mostrará:
Tamaño de la tabla y número de elementos.
Factor de carga.
Número total de colisiones.
Longitud máxima y promedio de las cadenas.
Análisis solicitado
Complejidad promedio y peor caso de cada operación.
Costo del redimensionamiento.
Complejidad amortizada de la inserción.
