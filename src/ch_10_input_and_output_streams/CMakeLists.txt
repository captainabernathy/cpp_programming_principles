add_library(ch_10_utils OBJECT "ch_10_utils.cpp")
target_compile_definitions(ch_10_utils PRIVATE -DERR_OUT)

add_executable(ch_10_04_input ch_10_04_input.cpp)
target_compile_definitions(ch_10_04_input
                           PRIVATE
                           -DPOINT_IO
                           -DERR_OUT)

add_executable(ch_10_04_output ch_10_04_output.cpp)
target_compile_definitions(ch_10_04_output
                           PRIVATE
                           -DPOINT_IO
                           -DERR_OUT)

add_executable(ch_10_05_temperatures_01 ch_10_05_temperatures_01.cpp)
target_compile_definitions(ch_10_05_temperatures_01 PRIVATE -DERR_OUT)

add_executable(ch_10_06_read_int_01 ch_10_06_read_int_01.cpp)

add_executable(ch_10_07_00_read_int_02 ch_10_07_00_read_int_02.cpp)

add_executable(ch_10_07_01_read_int_03 ch_10_07_01_read_int_03.cpp)
target_compile_definitions(ch_10_07_01_read_int_03 PRIVATE -DERR_OUT)
target_link_libraries(ch_10_07_01_read_int_03 PRIVATE ch_10_utils)

add_executable(ch_10_07_01_read_int_04 ch_10_07_01_read_int_04.cpp)
target_compile_definitions(ch_10_07_01_read_int_04 PRIVATE -DERR_OUT)
target_link_libraries(ch_10_07_01_read_int_04 PRIVATE ch_10_utils)

add_executable(ch_10_07_02_read_int_05 ch_10_07_02_read_int_05.cpp)
target_compile_definitions(ch_10_07_02_read_int_05 PRIVATE -DERR_OUT)
target_link_libraries(ch_10_07_02_read_int_05 PRIVATE ch_10_utils)

add_executable(ch_10_08_Date_01 ch_10_08_Date_01.cpp)
target_compile_definitions(ch_10_08_Date_01
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)
target_link_libraries(ch_10_08_Date_01 PRIVATE date_output_only)

add_executable(ch_10_09_Date_02 ch_10_09_Date_02.cpp)
target_compile_definitions(ch_10_09_Date_02
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)
target_link_libraries(ch_10_09_Date_02 PRIVATE date_input_and_output)

add_custom_command(
    TARGET ch_10_04_input POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/points_infile.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/points_infile.txt
)

add_custom_command(
    TARGET ch_10_05_temperatures_01 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/temps_infile.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/temps_infile.txt
)
