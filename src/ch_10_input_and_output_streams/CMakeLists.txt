add_executable(ch_10_04_input ch_10_04_input.cpp)
add_executable(ch_10_04_output ch_10_04_output.cpp)
add_executable(ch_10_05_temperatures_01 ch_10_05_temperatures_01.cpp)
add_executable(ch_10_06_read_int_01 ch_10_06_read_int_01.cpp)
add_executable(ch_10_07_00_read_int_02 ch_10_07_00_read_int_02.cpp)
add_executable(ch_10_07_01_read_int_03 ch_10_07_01_read_int_03.cpp)
add_executable(ch_10_07_01_read_int_04 ch_10_07_01_read_int_04.cpp)
add_executable(ch_10_07_02_read_int_05 ch_10_07_02_read_int_05.cpp)
add_executable(ch_10_08_Date_01 ch_10_08_Date_01.cpp)
add_executable(ch_10_09_Date_02 ch_10_09_Date_02.cpp)

add_custom_command(
    TARGET ch_10_04_input POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/infile.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/infile.txt
)

add_custom_command(
    TARGET ch_10_05_temperatures_01 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/temps_infile.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/temps_infile.txt
)

