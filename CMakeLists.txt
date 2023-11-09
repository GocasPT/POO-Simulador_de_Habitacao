cmake_minimum_required(VERSION 3.26)
project(POO-Simulador_Habitacao)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp
        Lib/curses.h
        Lib/Terminal.cpp
        Lib/Terminal.h
        Class/Simulador/Simulador.cpp
        Class/Simulador/Simulador.h
        Class/Habitacao/Habitacao.cpp
        Class/Habitacao/Habitacao.h
        Class/Habitacao/Zona/Zona.cpp
        Class/Habitacao/Zona/Zona.h
        Class/Habitacao/Zona/Componentes/Aparelho/Aparelho.cpp
        Class/Habitacao/Zona/Componentes/Aparelho/Aparelho.h
        Class/Habitacao/Zona/Componentes/Aparelho/Aquecedor/Aquecedor.cpp
        Class/Habitacao/Zona/Componentes/Aparelho/Aquecedor/Aquecedor.h
        Class/Habitacao/Zona/Componentes/Aparelho/Aspersor/Aspersor.cpp
        Class/Habitacao/Zona/Componentes/Aparelho/Aspersor/Aspersor.h
        Class/Habitacao/Zona/Componentes/Aparelho/Lampada/Lampada.cpp
        Class/Habitacao/Zona/Componentes/Aparelho/Lampada/Lampada.h
        Class/Habitacao/Zona/Componentes/Aparelho/Refrigerador/Refrigerador.cpp
        Class/Habitacao/Zona/Componentes/Aparelho/Refrigerador/Refrigerador.h
        Class/Habitacao/Zona/Propriedade/Propriedade.cpp
        Class/Habitacao/Zona/Propriedade/Propriedade.h
        Class/Habitacao/Zona/Componentes/Sensor/Sensor.cpp
        Class/Habitacao/Zona/Componentes/Sensor/Sensor.h
        Class/Habitacao/Zona/Componentes/Processador/Processador.cpp
        Class/Habitacao/Zona/Componentes/Processador/Processador.h
        Class/Habitacao/Zona/Componentes/Processador/Regra/Regra.cpp
        Class/Habitacao/Zona/Componentes/Processador/Regra/Regra.h)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} C:/PDCurses-3.9/wincon/pdcurses.a)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} -lncursesw)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(${PROJECT_NAME} -lncurses)
endif ()