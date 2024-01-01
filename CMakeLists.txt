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
        Class/Habitacao/Zona/Zona.cpp
        Class/Habitacao/Zona/Zona.h
        Class/Habitacao/Zona/Componente/Componente.cpp
        Class/Habitacao/Zona/Componente/Componente.h
        Class/Habitacao/Zona/Componente/Aparelho/Aparelho.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Aparelho.h
        Class/Habitacao/Zona/Componente/Aparelho/AparelhoFactory.cpp
        Class/Habitacao/Zona/Componente/Aparelho/AparelhoFactory.h
        Class/Habitacao/Zona/Componente/Aparelho/Aparelhos.h
        Class/Habitacao/Zona/Componente/Aparelho/Aquecedor/Aquecedor.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Aquecedor/Aquecedor.h
        Class/Habitacao/Zona/Componente/Aparelho/Aspersor/Aspersor.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Aspersor/Aspersor.h
        Class/Habitacao/Zona/Componente/Aparelho/Lampada/Lampada.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Lampada/Lampada.h
        Class/Habitacao/Zona/Componente/Aparelho/Refrigerador/Refrigerador.cpp
        Class/Habitacao/Zona/Componente/Aparelho/Refrigerador/Refrigerador.h
        Class/Habitacao/Zona/Componente/Sensor/Sensor.cpp
        Class/Habitacao/Zona/Componente/Sensor/Sensor.h
        Class/Habitacao/Zona/Componente/Sensor/SensorFactory.cpp
        Class/Habitacao/Zona/Componente/Sensor/SensorFactory.h
        Class/Habitacao/Zona/Componente/Sensor/Sensores.h
        Class/Habitacao/Zona/Componente/Sensor/SensorTemperatura/SensorTemperatura.cpp
        Class/Habitacao/Zona/Componente/Sensor/SensorTemperatura/SensorTemperatura.h
        Class/Habitacao/Zona/Componente/Sensor/SensorSom/SensorSom.cpp
        Class/Habitacao/Zona/Componente/Sensor/SensorSom/SensorSom.h
        Class/Habitacao/Zona/Componente/Sensor/SensorRadiacao/SensorRadiacao.cpp
        Class/Habitacao/Zona/Componente/Sensor/SensorRadiacao/SensorRadiacao.h
        Class/Habitacao/Zona/Componente/Sensor/SensorMovimento/SensorMovimento.cpp
        Class/Habitacao/Zona/Componente/Sensor/SensorMovimento/SensorMovimento.h
        Class/Habitacao/Zona/Componente/Sensor/SensorLuminosidade/SensorLuminosidade.cpp
        Class/Habitacao/Zona/Componente/Sensor/SensorLuminosidade/SensorLuminosidade.h
        Class/Habitacao/Zona/Componente/Sensor/SensorHumidade/SensorHumidade.cpp
        Class/Habitacao/Zona/Componente/Sensor/SensorHumidade/SensorHumidade.h
        Class/Habitacao/Zona/Componente/Sensor/SensorFumo/SensorFumo.cpp
        Class/Habitacao/Zona/Componente/Sensor/SensorFumo/SensorFumo.h
        Class/Habitacao/Zona/Componente/Processador/Processador.cpp
        Class/Habitacao/Zona/Componente/Processador/Processador.h
        Class/Habitacao/Zona/Componente/Regra/Regra.cpp
        Class/Habitacao/Zona/Componente/Regra/Regra.h
        Class/Habitacao/Zona/Propriedade/Propriedade.cpp
        Class/Habitacao/Zona/Propriedade/Propriedade.h
        Class/Habitacao/Zona/Propriedade/Propriedades.h
        Class/Habitacao/Zona/Propriedade/Temperatura/Temperatura.cpp
        Class/Habitacao/Zona/Propriedade/Temperatura/Temperatura.h
        Class/Habitacao/Zona/Propriedade/Luz/Luz.cpp
        Class/Habitacao/Zona/Propriedade/Luz/Luz.h
        Class/Habitacao/Zona/Propriedade/Radiacao/Radiacao.cpp
        Class/Habitacao/Zona/Propriedade/Radiacao/Radiacao.h
        Class/Habitacao/Zona/Propriedade/Vibracao/Vibracao.cpp
        Class/Habitacao/Zona/Propriedade/Vibracao/Vibracao.h
        Class/Habitacao/Zona/Propriedade/Humidade/Humidade.cpp
        Class/Habitacao/Zona/Propriedade/Humidade/Humidade.h
        Class/Habitacao/Zona/Propriedade/Fumo/Fumo.cpp
        Class/Habitacao/Zona/Propriedade/Fumo/Fumo.h
        Class/Habitacao/Zona/Propriedade/Som/Som.cpp
        Class/Habitacao/Zona/Propriedade/Som/Som.h)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} C:/PDCurses-3.9/wincon/pdcurses.a)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} -lncursesw)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(${PROJECT_NAME} -lncurses)
endif ()
