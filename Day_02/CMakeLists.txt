cmake_minimum_required(VERSION 3.30)
project(Day_02)

set(CMAKE_CXX_STANDARD 20)

add_executable(Day_02 main.cpp)

# Setze den Pfad zur Quelldatei und das Zielverzeichnis
set(INPUT_FILE "${CMAKE_SOURCE_DIR}/Input_Day02.txt")
set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}") # z.B. das Verzeichnis mit den erstellten Binärdateien

# Füge den Befehl hinzu, um die Datei beim Kompilieren zu kopieren
add_custom_command(
        TARGET Day_02 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${INPUT_FILE}" "${OUTPUT_DIRECTORY}"
)
