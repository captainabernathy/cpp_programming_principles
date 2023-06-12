add_library(vector_dbl.reserve OBJECT "vector_dbl_reserve.cpp")
target_compile_definitions(vector_dbl.reserve
                           PRIVATE
                           -DNO_RESIZE
                           -DNO_PUSH_BACK)

add_library(vector_dbl.resize
            OBJECT
            "vector_dbl_reserve.cpp"
            "vector_dbl_resize.cpp")
target_compile_definitions(vector_dbl.resize PRIVATE -DNO_PUSH_BACK)

add_library(vector_dbl
            OBJECT
            "vector_dbl_reserve.cpp"
            "vector_dbl_resize.cpp"
            "vector_dbl_copy_assign.cpp"
            "vector_dbl_move_assign.cpp"
            "vector_dbl_push_back.cpp")

add_library(vector_dbl_utils OBJECT "vector_dbl_utils.cpp")

add_executable(ch_19_01_the_problems ch_19_01_the_problems.cpp)
add_executable(ch_19_02_00_changing_size ch_19_02_00_changing_size.cpp)

add_executable(ch_19_02_01_representation ch_19_02_01_representation.cpp)
target_compile_definitions(ch_19_02_01_representation
                           PRIVATE
                           -DNO_RESERVE
                           -DNO_RESIZE
                           -DNO_PUSH_BACK)

add_executable(ch_19_02_02_reserve_and_capacity
               ch_19_02_02_reserve_and_capacity.cpp)
target_compile_definitions(ch_19_02_02_reserve_and_capacity
                           PRIVATE
                           -DNO_RESIZE
                           -DNO_PUSH_BACK)
target_link_libraries(ch_19_02_02_reserve_and_capacity vector_dbl.reserve)

add_executable(ch_19_02_03_resize ch_19_02_03_resize.cpp)
target_compile_definitions(ch_19_02_03_resize PRIVATE -DNO_PUSH_BACK)
target_link_libraries(ch_19_02_03_resize vector_dbl.resize)

add_executable(ch_19_02_04_push_back ch_19_02_04_push_back.cpp)
target_link_libraries(ch_19_02_04_push_back vector_dbl)

add_executable(ch_19_02_05_assignment ch_19_02_05_assignment.cpp)
target_link_libraries(ch_19_02_05_assignment
                      vector_dbl
                      vector_dbl_utils)

add_executable(ch_19_02_06_vector_so_far ch_19_02_06_vector_so_far.cpp)
target_link_libraries(ch_19_02_06_vector_so_far
                      vector_dbl
                      vector_dbl_utils)

add_executable(ch_19_03_01_types_as_template_parameters
               ch_19_03_01_types_as_template_parameters.cpp)
target_compile_definitions(ch_19_03_01_types_as_template_parameters
                           PRIVATE
                           -DVECTOR_T)

add_executable(ch_19_03_05_template_parameters
               ch_19_03_05_template_parameters.cpp)

add_executable(ch_19_03_06_template_argument_deduction
               ch_19_03_06_template_argument_deduction.cpp)

add_executable(ch_19_03_07_generalizing_vector
               ch_19_03_07_generalizing_vector.cpp)

add_executable(ch_19_04_02_range_checking_and_exceptions
               ch_19_04_02_range_checking_and_exceptions.cpp)
