add_library(jack_and_jill OBJECT jack_and_jill.cpp)

add_executable(ch_20_01_01_working_with_data ch_20_01_01_working_with_data.cpp)
target_link_libraries(ch_20_01_01_working_with_data PRIVATE jack_and_jill)

add_executable(ch_20_01_02_generalizing_code_01
               ch_20_01_02_generalizing_code_01.cpp)
target_link_libraries(ch_20_01_02_generalizing_code_01 PRIVATE jack_and_jill)

add_executable(ch_20_01_02_generalizing_code_02
               ch_20_01_02_generalizing_code_02.cpp)
target_link_libraries(ch_20_01_02_generalizing_code_02 PRIVATE jack_and_jill)

add_executable(ch_20_03_01_back_to_the_example
               ch_20_03_01_back_to_the_example.cpp)
target_link_libraries(ch_20_03_01_back_to_the_example PRIVATE jack_and_jill)

add_executable(ch_20_04_02_list_iteration ch_20_04_02_list_iteration.cpp)

add_executable(ch_20_06_01_lines ch_20_06_01_lines.cpp)
target_link_libraries(ch_20_06_01_lines PRIVATE document_utils)

add_executable(ch_20_06_02_text_iteration ch_20_06_02_text_iteration.cpp)
target_link_libraries(ch_20_06_02_text_iteration
                      PRIVATE
                      document_utils
                      text_utils)

add_executable(ch_20_07_01_insert_and_erase ch_20_07_01_insert_and_erase.cpp)

add_executable(ch_20_08_adapting_vector_to_stl
               ch_20_08_adapting_vector_to_stl.cpp)

add_executable(ch_20_09_adapting_arrays_to_stl
               ch_20_09_adapting_arrays_to_stl.cpp)
