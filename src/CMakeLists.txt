#file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.cc)

file(GLOB_RECURSE SOURCES *.h *.cpp)  #Todas las fuentes sin el Main


set(BINARY ${CMAKE_PROJECT_NAME})  # El nombre va a a estar en el CMake principal

# Definicion variable sources
set(SOURCES ${SOURCES})

 # STATIC libraries are archives of object files for use when linking other targets
#add_library(${CMAKE_PROJECT_NAME}_lib Calculator.h Calculator.cpp)  #construye una libraria que tiene los test que vamos a ejecutar

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_lib)


# Instrucción que define el ejecutable a partir de las fuentes definidas
add_executable(${BINARY}_exe ${SOURCES} Main.cpp Huesped.cpp Huesped.h Propietario.cpp Propietario.h Hogar.cpp Hogar.h Sistema.cpp Sistema.h Reserva.cpp Reserva.h Evaluacion.cpp Evaluacion.h)  # Las fuentes mas el archivo main
