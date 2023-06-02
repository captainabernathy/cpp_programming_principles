add_executable(ch_09_02_classes_and_members ch_09_02_classes_and_members.cpp)
add_executable(ch_09_03_interface_and_implementation
               ch_09_03_interface_and_implementation.cpp)
add_executable(ch_09_04_03_keep_details_private
               ch_09_04_03_keep_details_private.cpp)
add_executable(ch_09_04_06_reporting_errors ch_09_04_06_reporting_errors.cpp)
add_executable(ch_09_05_enumerations ch_09_05_enumerations.cpp)
add_executable(ch_09_06_operator_overloading ch_09_06_operator_overloading.cpp)
add_executable(ch_09_07_01_argument_types ch_09_07_01_argument_types.cpp)
add_executable(ch_09_07_02_copying ch_09_07_02_copying.cpp)
add_executable(ch_09_07_03_default_constructors
               ch_09_07_03_default_constructors.cpp)
add_executable(ch_09_07_04_const_member_functions
               ch_09_07_04_const_member_functions.cpp)
add_executable(ch_09_07_05_members_and_helper_functions
               ch_09_07_05_members_and_helper_functions.cpp)
add_executable(ch_09_08_date_class ch_09_08_date_class.cpp)

target_compile_definitions(ch_09_05_enumerations PRIVATE -DERR_OUT)

