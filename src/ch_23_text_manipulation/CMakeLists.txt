add_library(mail_file OBJECT "mail_file.cpp")
add_library(message_utils OBJECT "message_utils.cpp")

add_executable(ch_23_02_strings ch_23_02_strings.cpp)

add_executable(ch_23_04_01_maps_and_messages ch_23_04_01_maps_and_messages.cpp)
target_link_libraries(ch_23_04_01_maps_and_messages
                      PRIVATE
                      string_utils
                      mail_file
                      message_utils)

add_executable(ch_23_05_a_problem ch_23_05_a_problem.cpp)

add_executable(ch_23_07_searching_with_regular_expressions
               ch_23_07_searching_with_regular_expressions.cpp)

add_executable(ch_23_09_matching_with_regular_expressions
               ch_23_09_matching_with_regular_expressions.cpp)
target_compile_definitions(ch_23_09_matching_with_regular_expressions
                           PRIVATE -DERR_OUT)

add_custom_command(
    TARGET ch_23_04_01_maps_and_messages POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/example-mail-file.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/example-mail-file.txt
)

add_custom_command(
    TARGET ch_23_05_a_problem POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/chapter_23_05_infile.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/chapter_23_05_infile.txt
)

add_custom_command(
    TARGET ch_23_07_searching_with_regular_expressions POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/file.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/file.txt
)

add_custom_command(
    TARGET ch_23_09_matching_with_regular_expressions POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/table.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/table.txt
)
