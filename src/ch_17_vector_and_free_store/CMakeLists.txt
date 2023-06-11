add_library(link_str_utils OBJECT "link_str_utils.cpp")
target_compile_definitions(link_str_utils PRIVATE -DLINK_STR)

add_library(link_str
            OBJECT
            "link_str_insert.cpp"
            "link_str_add.cpp"
            "link_str_erase.cpp"
            "link_str_find.cpp"
            "link_str_advance.cpp")
target_compile_definitions(link_str PRIVATE -DLINK_STR)

add_library(link_str_class
            OBJECT
            "link_str_insert.cpp"
            "link_str_erase.cpp"
            "link_str_find.cpp")
target_compile_definitions(link_str_class
                           PRIVATE
                           -DLINK_STR
                           -DLINK_STR_CLASS)

add_executable(ch_17_03_00_memory_addresses_pointers
               ch_17_03_00_memory_addresses_pointers.cpp)

add_executable(ch_17_03_01_sizeof_operator ch_17_03_01_sizeof_operator.cpp)

add_executable(ch_17_04_01_free_store_allocation
               ch_17_04_01_free_store_allocation.cpp)

add_executable(ch_17_04_02_access_through_pointers
               ch_17_04_02_access_through_pointers.cpp)

add_executable(ch_17_04_04_initialization ch_17_04_04_initialization.cpp)

add_executable(ch_17_04_06_free_store_deallocation
               ch_17_04_06_free_store_deallocation.cpp)

add_executable(ch_17_06_access_to_elements ch_17_06_access_to_elements.cpp)

add_executable(ch_17_09_00_pointers_and_references
               ch_17_09_00_pointers_and_references.cpp)

add_executable(ch_17_09_01_pointer_and_reference_parameters
               ch_17_09_01_pointer_and_reference_parameters.cpp)

add_executable(ch_17_09_05_list_use ch_17_09_05_list_use.cpp)
target_compile_definitions(link_str PRIVATE -DLINK_STR)
target_link_libraries(ch_17_09_05_list_use link_str link_str_utils)

add_executable(ch_17_10_01_the_this_pointer ch_17_10_01_the_this_pointer.cpp)
target_compile_definitions(link_str_class
                           PRIVATE
                           -DLINK_STR
                           -DLINK_STR_CLASS)
target_link_libraries(ch_17_10_01_the_this_pointer
                      link_str_class
                      link_str_utils)
