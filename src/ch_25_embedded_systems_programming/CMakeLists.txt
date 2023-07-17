add_executable(ch_25_04_02_a_problem_dysfunctional_interfaces
               ch_25_04_02_a_problem_dysfunctional_interfaces.cpp)

add_executable(ch_25_04_03_a_solution_an_interface_class
               ch_25_04_03_a_solution_an_interface_class.cpp)
target_compile_definitions(ch_25_04_03_a_solution_an_interface_class
                           PRIVATE
                           -DNO_ARRAY_REF_CALL_OPERATOR)
                       
add_executable(ch_25_04_04_inheritance_and_containers
               ch_25_04_04_inheritance_and_containers.cpp)

add_executable(ch_25_05_02_bitset ch_25_05_02_bitset.cpp)

add_executable(ch_25_05_03_signed_and_unsigned
               ch_25_05_03_signed_and_unsigned.cpp)

add_executable(ch_25_05_06_01_encrypt_text ch_25_05_06_01_encrypt_text.cpp)
target_compile_definitions(ch_25_05_06_01_encrypt_text PRIVATE -DERR_OUT)
target_link_libraries(ch_25_05_06_01_encrypt_text PRIVATE encryption_utils)

add_executable(ch_25_05_06_02_decrypt_text ch_25_05_06_02_decrypt_text.cpp)
target_compile_definitions(ch_25_05_06_02_decrypt_text PRIVATE -DERR_OUT)
target_link_libraries(ch_25_05_06_02_decrypt_text PRIVATE encryption_utils)

add_custom_command(
    TARGET ch_25_05_06_01_encrypt_text POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/message.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/message.txt
)
