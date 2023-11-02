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
        Class/Habitacao/Zona/Aparelho/Aparelho.cpp
        Class/Habitacao/Zona/Aparelho/Aparelho.h
        Class/Habitacao/Zona/Aparelho/Aquecedor/Aquecedor.cpp
        Class/Habitacao/Zona/Aparelho/Aquecedor/Aquecedor.h
        Class/Habitacao/Zona/Aparelho/Aspersor/Aspersor.cpp
        Class/Habitacao/Zona/Aparelho/Aspersor/Aspersor.h
        Class/Habitacao/Zona/Aparelho/Lampada/Lampada.cpp
        Class/Habitacao/Zona/Aparelho/Lampada/Lampada.h
        Class/Habitacao/Zona/Aparelho/Refrigerador/Refrigerador.cpp
        Class/Habitacao/Zona/Aparelho/Refrigerador/Refrigerador.h
        Class/Habitacao/Zona/Ambiente/Ambiente.cpp
        Class/Habitacao/Zona/Ambiente/Ambiente.h
        Class/Habitacao/Zona/Sensor/Sensor.cpp
        Class/Habitacao/Zona/Sensor/Sensor.h
        Class/Habitacao/Zona/Processador/Processador.cpp
        Class/Habitacao/Zona/Processador/Processador.h)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} C:/PDCurses-3.9/wincon/pdcurses.a)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} -lncursesw)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(${PROJECT_NAME} -lncurses)
endif ()