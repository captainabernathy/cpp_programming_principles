add_executable(ch_11_02_01_integer_output ch_11_02_01_integer_output.cpp)
add_executable(ch_11_02_02_integer_input ch_11_02_02_integer_input.cpp)
add_executable(ch_11_02_03_floating_point_output
               ch_11_02_03_floating_point_output.cpp)
add_executable(ch_11_02_04_floating_point_precision
               ch_11_02_04_floating_point_precision.cpp)
add_executable(ch_11_02_05_output_field_width
               ch_11_02_05_output_field_width.cpp)
add_executable(ch_11_03_01_file_open_modes ch_11_03_01_file_open_modes.cpp)
add_executable(ch_11_03_02_binary_files ch_11_03_02_binary_files.cpp)
add_executable(ch_11_03_03_stream_positioning
               ch_11_03_03_stream_positioning.cpp)
add_executable(ch_11_04_string_streams ch_11_04_string_streams.cpp)
add_executable(ch_11_05_line_oriented_input ch_11_05_line_oriented_input.cpp)
add_executable(ch_11_07_using_nonstandard_separators
               ch_11_07_using_nonstandard_separators.cpp)

target_compile_definitions(ch_11_03_02_binary_files PRIVATE -DERR_OUT)
target_compile_definitions(ch_11_03_03_stream_positioning PRIVATE -DERR_OUT)
target_compile_definitions(ch_11_04_string_streams PRIVATE -DERR_OUT)

add_custom_command(
    TARGET ch_11_03_02_binary_files POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/mybin
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mybin
)

add_custom_command(
    TARGET ch_11_03_03_stream_positioning POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/positioning.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/positioning.txt
)

