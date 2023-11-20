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
        Class/Habitacao/Zona/Componente/Componente.cpp
        Class/Habitacao/Zona/Componente/Componente.h
        Class/Habitacao/Zona/Componente/Aparelho/Aparelho.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Aparelho.h
        Class/Habitacao/Zona/Componente/Aparelho/Aquecedor/Aquecedor.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Aquecedor/Aquecedor.h
        Class/Habitacao/Zona/Componente/Aparelho/Aspersor/Aspersor.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Aspersor/Aspersor.h
        Class/Habitacao/Zona/Componente/Aparelho/Lampada/Lampada.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Lampada/Lampada.h
        Class/Habitacao/Zona/Componente/Aparelho/Refrigerador/Refrigerador.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Refrigerador/Refrigerador.h
        Class/Habitacao/Zona/Propriedade/Propriedade.cpp
        Class/Habitacao/Zona/Propriedade/Propriedade.h
        Class/Habitacao/Zona/Componente/Sensor/Sensor.cpp
        Class/Habitacao/Zona/Componente/Sensor/Sensor.h
        Class/Habitacao/Zona/Componente/Processador/Processador.cpp
        Class/Habitacao/Zona/Componente/Processador/Processador.h
        Class/Habitacao/Zona/Componente/Processador/Regra/Regra.cpp
        Class/Habitacao/Zona/Componente/Processador/Regra/Regra.h)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} C:/PDCurses-3.9/wincon/pdcurses.a)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} -lncursesw)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(${PROJECT_NAME} -lncurses)
endif ()