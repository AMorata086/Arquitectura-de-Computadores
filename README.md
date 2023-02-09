# Arquitectura-de-Computadores
Repositorio para las prácticas de Arquitectura de Computadores

## Descripción contenidos
### Laboratorios
Contiene 4 laboratorios distintos realizados a lo largo de la asignatura.
- **Laboratorio 2** - laboratorio para aprender a utilizar el nodo de cómputo *Avignon* y analizar el rendimiento y consumo de energía de programas mediante la herramienta *perf*.
- **Laboratorio 3** - laboratorio para la evaluación de la memoria caché mediante las herramientas *Valgrind* y *Callgrind*
- **Laboratorio 5** - laboratorio para observar el impacto que tienen los saltos y la predicción de saltos a nivel de instrucción y cómo mejorar el rendimiento.
- **Laboratorio 6** - laboratorio para observar y evaluar el impacto que tiene en el rendimiento los distintos mecanismos de concurrencia (*mutex*, *atómicos*, *spinlock*) y cómo implementarlos en C++.
### Prácticas
- ***Práctica 1: Programación secuencial orientada al rendimiento*** - Práctica en la que se desarrolló un programa en dos versiones distintas (AOS y SOA) que añadía 4 funcionalidades distintas sobre archivos Bitmap:
  - *histo*: Función que genera un archivo que contiene consecutivamente los histogramas de los 3 canales (R-G-B).
    > Un histograma representa la frecuencia absoluta (número de apariciones) de cada valor numérico (de 0 a 255).
  - *gauss*: Función que aplica sobre una imagen un filtro de difusión gaussiana (disminución de la nitidez de imagen y ayuda previa para la detección de bordes).
  - *copy*: Función que permite copiar un Bitmap *bit a bit*. 
  - *mono*: Función que aplica sobre una imagen una conversión a escala de grises.
- ***Práctica 2: Programación paralela con OpenMP*** - Práctica en la que se hizo uso de [OpenMP](https://www.openmp.org/) para la paralelización de las funciones implementadas en la primera práctica (partiendo de un código garantizado por los profesores).
