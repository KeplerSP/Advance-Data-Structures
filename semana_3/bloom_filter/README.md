# Bloom Filter

Implementación **simple y legible** de un Bloom Filter en C++ usando un `struct`
básico y dos funciones hash sencillas. El objetivo es poder leer el código
línea por línea junto al pseudocódigo.

## Estructura
- `apps/app_main.cpp` → programa principal de ejemplo
- `include/bloom_filter.h` → definición del struct y funciones hash
- `src/bloom_filter.cpp` → implementación de `initialize`, `insert`, `lookup`
- `bin/bloom_filter` → ejecutable
- `obj/` → archivos objeto
- `Makefile` → reglas de compilación

## Compilar y ejecutar
```bash
make
./bin/bloom_filter
```
O directamente:
```bash
make run
```

Salida esperada:
```
gato -> true  (probablemente esta)
elefante -> false (seguro NO esta)
```

## Pseudocódigo base

```
procedure Initialize(m, k)
    Create bit array B of size m
    for i <- 0 to m-1
        B[i] <- 0
    Choose k independent hash functions h_1, ..., h_k
    return B

procedure Insert(item)
    for i <- 1 to k
        pos <- h_i(item) mod m
        B[pos] <- 1

procedure Lookup(item)
    for i <- 1 to k
        pos <- h_i(item) mod m
        if B[pos] = 0
            return false
    return true
```

Las `k` funciones hash se simulan con la fórmula:
```
pos = (hash1(item) + i * hash2(item)) % m
```
donde `hash1` suma los valores ASCII del string (módulo 101) y `hash2` suma los
valores ASCII ponderados por la posición (módulo 103).

## Análisis de complejidad

| Operación    | Complejidad | Motivo                                             |
|--------------|-------------|----------------------------------------------------|
| `initialize` | O(m)        | recorre el arreglo `B` poniendo cada bit en 0      |
| `insert`     | O(k)        | calcula `k` posiciones y marca `k` bits            |
| `lookup`     | O(k)        | revisa como máximo `k` bits (puede cortar antes)   |

> `hash1` y `hash2` recorren el string, así que en rigor cada operación es
> O(k · L) siendo L el largo del `item`; como L se considera pequeño y constante,
> se resume como O(k).

### Nota sobre falsos positivos
`lookup` puede devolver `true` para un elemento que nunca se insertó (falso
positivo), pero **nunca** devuelve `false` para un elemento que sí se insertó
(no hay falsos negativos).
