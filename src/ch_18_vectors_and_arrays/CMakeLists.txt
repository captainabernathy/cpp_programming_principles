add_library(vector_dbl.copy_assign OBJECT "vector_dbl_copy_assign.cpp")
target_compile_definitions(vector_dbl.copy_assign
                           PRIVATE
                           -DPRINT_DEBUG
                           -DGET_AND_SET
                           -DNO_MOVE
                           -DNO_ACCESS
                           -DNO_CONST)

add_library(vector_dbl.access_read_only OBJECT "vector_dbl_copy_assign.cpp")
target_compile_definitions(vector_dbl.access_read_only
                           PRIVATE
                           -DNO_MOVE
                           -DREAD_ONLY
                           -DNO_CONST)

add_library(vector_dbl.access_read_write_ptr
            OBJECT
            "vector_dbl_copy_assign.cpp")
target_compile_definitions(vector_dbl.access_read_write_ptr
                           PRIVATE
                           -DNO_MOVE
                           -DREAD_WRITE_PTR
                           -DNO_CONST)

add_library(vector_dbl.access_no_const OBJECT "vector_dbl_copy_assign.cpp")
target_compile_definitions(vector_dbl.access_no_const
                           PRIVATE
                           -DNO_MOVE
                           -DNO_CONST)

add_library(vector_dbl.access_read_write OBJECT "vector_dbl_copy_assign.cpp")
target_compile_definitions(vector_dbl.access_read_write
                           PRIVATE
                           -DNO_MOVE)

add_library(vector_dbl.copy_move
            OBJECT
            "vector_dbl_copy_assign.cpp"
            "vector_dbl_move_assign.cpp")
target_compile_definitions(vector_dbl.copy_move PRIVATE -DPRINT_DEBUG)


add_executable(ch_18_02_00_initialization ch_18_02_00_initialization.cpp)
target_compile_definitions(ch_18_02_00_initialization
                           PRIVATE
                           -DPRINT_DEBUG
                           -DGET_AND_SET
                           -DNO_INIT
                           -DNO_COPY
                           -DNO_MOVE
                           -DNO_ASSIGN
                           -DNO_ACCESS
                           -DNO_CONST)

add_executable(ch_18_02_01_initializer_list
               vector_dbl_utils.cpp
               ch_18_02_01_initializer_list.cpp)
target_compile_definitions(ch_18_02_01_initializer_list
                           PRIVATE
                           -DPRINT_DEBUG
                           -DGET_AND_SET
                           -DNO_COPY
                           -DNO_MOVE
                           -DNO_ASSIGN
                           -DNO_ACCESS
                           -DNO_CONST)

add_executable(ch_18_03_01_copy_constructors
               vector_dbl_utils.cpp
               ch_18_03_01_copy_constructors.cpp)
target_compile_definitions(ch_18_03_01_copy_constructors
                           PRIVATE
                           -DPRINT_DEBUG
                           -DGET_AND_SET
                           -DNO_MOVE
                           -DNO_ASSIGN
                           -DNO_ACCESS
                           -DNO_CONST)

add_executable(ch_18_03_02_copy_assignments
               vector_dbl_utils.cpp
               ch_18_03_02_copy_assignments.cpp)
target_compile_definitions(ch_18_03_02_copy_assignments
                           PRIVATE
                           -DPRINT_DEBUG
                           -DGET_AND_SET
                           -DNO_MOVE
                           -DNO_ACCESS
                           -DNO_CONST)
target_link_libraries(ch_18_03_02_copy_assignments vector_dbl.copy_assign)

add_executable(ch_18_03_03_copy_terminology ch_18_03_03_copy_terminology.cpp)

add_executable(ch_18_04_00_essential_operations
               ch_18_04_00_essential_operations.cpp)

add_executable(ch_18_04_02_debugging_constructors_and_destructors
               ch_18_04_02_debugging_constructors_and_destructors.cpp)

add_executable(ch_18_05_00_access_to_vector_elements_v1
               ch_18_05_00_access_to_vector_elements_v1.cpp)
target_compile_definitions(ch_18_05_00_access_to_vector_elements_v1
                           PRIVATE
                           -DNO_MOVE
                           -DREAD_ONLY
                           -DNO_CONST)
target_link_libraries(ch_18_05_00_access_to_vector_elements_v1
                      vector_dbl.access_read_only)

add_executable(ch_18_05_00_access_to_vector_elements_v2
               ch_18_05_00_access_to_vector_elements_v2.cpp)
target_compile_definitions(ch_18_05_00_access_to_vector_elements_v2
                           PRIVATE
                           -DNO_MOVE
                           -DREAD_WRITE_PTR
                           -DNO_CONST)
target_link_libraries(ch_18_05_00_access_to_vector_elements_v2
                      vector_dbl.access_read_write_ptr)

add_executable(ch_18_05_00_access_to_vector_elements_v3
               ch_18_05_00_access_to_vector_elements_v3.cpp)
target_compile_definitions(ch_18_05_00_access_to_vector_elements_v3
                           PRIVATE
                           -DNO_MOVE
                           -DNO_CONST)
target_link_libraries(ch_18_05_00_access_to_vector_elements_v3
                      vector_dbl.access_no_const)

add_executable(ch_18_05_01_overloading_on_const
               vector_dbl_utils.cpp
               ch_18_05_01_overloading_on_const.cpp)
target_compile_definitions(ch_18_05_01_overloading_on_const PRIVATE -DNO_MOVE)
target_link_libraries(ch_18_05_01_overloading_on_const
                      vector_dbl.access_read_write)

add_executable(ch_18_05_02_move_semantics ch_18_05_02_move_semantics.cpp)
target_compile_definitions(ch_18_05_02_move_semantics PRIVATE -DPRINT_DEBUG)
target_link_libraries(ch_18_05_02_move_semantics vector_dbl.copy_move)

add_executable(ch_18_06_03_array_initialization
               ch_18_06_03_array_initialization.cpp)

add_executable(ch_18_07_01_palindromes_using_string
               ch_18_07_01_palindromes_using_string.cpp)
target_link_libraries(ch_18_07_01_palindromes_using_string
                      string_utils)

add_executable(ch_18_07_02_palindromes_using_arrays
               ch_18_07_02_palindromes_using_arrays.cpp)
target_link_libraries(ch_18_07_02_palindromes_using_arrays
                      string_utils
                      io_utils)

add_executable(ch_18_07_03_palindromes_using_pointers
               ch_18_07_03_palindromes_using_pointers.cpp)
target_link_libraries(ch_18_07_03_palindromes_using_pointers
                      string_utils.no_recursion
                      io_utils)

add_executable(ch_18_07_04_palindromes_using_pointers_recursive
               ch_18_07_04_palindromes_using_pointers_recursive.cpp)
target_link_libraries(ch_18_07_04_palindromes_using_pointers_recursive
                      string_utils
                      io_utils)
