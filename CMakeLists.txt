cmake_minimum_required(VERSION 3.26)
project(POO-Simulador_Habitacao)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp
        Lib/Terminal/curses.h
        Lib/Terminal/Terminal.cpp
        Lib/Terminal/Terminal.h
        Lib/utils/utils.h
        Lib/utils/utils.cpp
        Class/Simulador/Simulador.cpp
        Class/Simulador/Simulador.h
        Class/Habitacao/Habitacao.cpp
        Class/Habitacao/Habitacao.h
        Class/Zona/Zona.cpp
        Class/Zona/Zona.h
        Class/Componente/Componente.cpp
        Class/Componente/Componente.h
        Class/Componente/Aparelho/Aparelho.cpp
        Class/Componente/Aparelho/Aparelho.h
        Class/Componente/Aparelho/AparelhoFactory.cpp
        Class/Componente/Aparelho/AparelhoFactory.h
        Class/Componente/Aparelho/Aparelhos.h
        Class/Componente/Aparelho/Aquecedor/Aquecedor.cpp
        Class/Componente/Aparelho/Aquecedor/Aquecedor.h
        Class/Componente/Aparelho/Aspersor/Aspersor.cpp
        Class/Componente/Aparelho/Aspersor/Aspersor.h
        Class/Componente/Aparelho/Lampada/Lampada.cpp
        Class/Componente/Aparelho/Lampada/Lampada.h
        Class/Componente/Aparelho/Refrigerador/Refrigerador.cpp
        Class/Componente/Aparelho/Refrigerador/Refrigerador.h
        Class/Componente/Sensor/Sensor.cpp
        Class/Componente/Sensor/Sensor.h
        Class/Componente/Sensor/SensorFactory.cpp
        Class/Componente/Sensor/SensorFactory.h
        Class/Componente/Sensor/Sensores.h
        Class/Componente/Sensor/SensorTemperatura/SensorTemperatura.cpp
        Class/Componente/Sensor/SensorTemperatura/SensorTemperatura.h
        Class/Componente/Sensor/SensorSom/SensorSom.cpp
        Class/Componente/Sensor/SensorSom/SensorSom.h
        Class/Componente/Sensor/SensorRadiacao/SensorRadiacao.cpp
        Class/Componente/Sensor/SensorRadiacao/SensorRadiacao.h
        Class/Componente/Sensor/SensorMovimento/SensorMovimento.cpp
        Class/Componente/Sensor/SensorMovimento/SensorMovimento.h
        Class/Componente/Sensor/SensorLuminosidade/SensorLuminosidade.cpp
        Class/Componente/Sensor/SensorLuminosidade/SensorLuminosidade.h
        Class/Componente/Sensor/SensorHumidade/SensorHumidade.cpp
        Class/Componente/Sensor/SensorHumidade/SensorHumidade.h
        Class/Componente/Sensor/SensorFumo/SensorFumo.cpp
        Class/Componente/Sensor/SensorFumo/SensorFumo.h
        Class/Componente/Processador/Processador.cpp
        Class/Componente/Processador/Processador.h
        Class/Componente/Regra/Regra.cpp
        Class/Componente/Regra/Regra.h
        Class/Propriedade/Propriedade.cpp
        Class/Propriedade/Propriedade.h
        Class/Propriedade/Propriedades.h
        Class/Propriedade/Temperatura/Temperatura.cpp
        Class/Propriedade/Temperatura/Temperatura.h
        Class/Propriedade/Luz/Luz.cpp
        Class/Propriedade/Luz/Luz.h
        Class/Propriedade/Radiacao/Radiacao.cpp
        Class/Propriedade/Radiacao/Radiacao.h
        Class/Propriedade/Vibracao/Vibracao.cpp
        Class/Propriedade/Vibracao/Vibracao.h
        Class/Propriedade/Humidade/Humidade.cpp
        Class/Propriedade/Humidade/Humidade.h
        Class/Propriedade/Fumo/Fumo.cpp
        Class/Propriedade/Fumo/Fumo.h
        Class/Propriedade/Som/Som.cpp
        Class/Propriedade/Som/Som.h)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} C:/PDCurses-3.9/wincon/pdcurses.a)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} -lncursesw)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(${PROJECT_NAME} -lncurses)
endif ()
