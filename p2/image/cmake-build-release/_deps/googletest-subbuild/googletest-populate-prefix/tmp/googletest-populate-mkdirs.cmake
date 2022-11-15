# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "H:/almoh/Documents/GitHub/Arquitectura-de-Computadores/p2/image/cmake-build-release/_deps/googletest-src"
  "H:/almoh/Documents/GitHub/Arquitectura-de-Computadores/p2/image/cmake-build-release/_deps/googletest-build"
  "H:/almoh/Documents/GitHub/Arquitectura-de-Computadores/p2/image/cmake-build-release/_deps/googletest-subbuild/googletest-populate-prefix"
  "H:/almoh/Documents/GitHub/Arquitectura-de-Computadores/p2/image/cmake-build-release/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "H:/almoh/Documents/GitHub/Arquitectura-de-Computadores/p2/image/cmake-build-release/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "H:/almoh/Documents/GitHub/Arquitectura-de-Computadores/p2/image/cmake-build-release/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "H:/almoh/Documents/GitHub/Arquitectura-de-Computadores/p2/image/cmake-build-release/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "H:/almoh/Documents/GitHub/Arquitectura-de-Computadores/p2/image/cmake-build-release/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
