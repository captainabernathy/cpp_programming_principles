add_executable(ch_09_02_classes_and_members ch_09_02_classes_and_members.cpp)

add_executable(ch_09_03_interface_and_implementation
               ch_09_03_interface_and_implementation.cpp)

add_executable(ch_09_04_03_keep_details_private
               ch_09_04_03_keep_details_private.cpp)
target_compile_definitions(ch_09_04_03_keep_details_private
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_DEFAULT_CONS
                           -DNO_MONTH
                           -DNO_INVALID
                           -DNO_MONTH_CONS
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)
target_link_libraries(ch_09_04_03_keep_details_private date_constructor_only)

add_executable(ch_09_04_06_reporting_errors ch_09_04_06_reporting_errors.cpp)
target_compile_definitions(ch_09_04_06_reporting_errors
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_DEFAULT_CONS
                           -DNO_MONTH
                           -DNO_MONTH_CONS
                           -DHAS_CHECK_METH
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS
                           -DERR_OUT)
target_link_libraries(ch_09_04_06_reporting_errors date_has_check)

add_executable(ch_09_05_enumerations ch_09_05_enumerations.cpp)
target_compile_definitions(ch_09_05_enumerations PRIVATE -DERR_OUT)
target_link_libraries(ch_09_05_enumerations month_utils)

add_executable(ch_09_06_operator_overloading ch_09_06_operator_overloading.cpp)
target_compile_definitions(ch_09_06_operator_overloading PRIVATE -DERR_OUT)
target_link_libraries(ch_09_06_operator_overloading month_utils)

add_executable(ch_09_07_01_argument_types ch_09_07_01_argument_types.cpp)
target_compile_definitions(ch_09_07_01_argument_types
                           PRIVATE
                           -DHAS_YEAR
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_DEFAULT_CONS
                           -DHAS_YEAR_CONS
                           -DNO_DAY_METH
                           -DNO_MONTH_METH
                           -DNO_YEAR_METH
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)
target_link_libraries(ch_09_07_01_argument_types date_has_year)

add_executable(ch_09_07_02_copying ch_09_07_02_copying.cpp)
target_compile_definitions(ch_09_07_02_copying
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_DEFAULT_CONS
                           -DNO_DAY_METH
                           -DNO_MONTH_METH
                           -DNO_YEAR_METH
                           -DNO_ADD_YEAR_METH
                           -DHAS_FRIEND_DATE_OUTPUT_OP
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)
target_link_libraries(ch_09_07_02_copying date_has_friend)

add_executable(ch_09_07_03_default_constructors
               ch_09_07_03_default_constructors.cpp)
target_compile_definitions(ch_09_07_03_default_constructors
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_ADD_YEAR_METH
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)
target_link_libraries(ch_09_07_03_default_constructors date_has_default)

add_executable(ch_09_07_04_const_member_functions
               ch_09_07_04_const_member_functions.cpp)
target_compile_definitions(ch_09_07_04_const_member_functions
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_DEFAULT_CONS
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)
target_link_libraries(ch_09_07_04_const_member_functions date_has_accessors)

add_executable(ch_09_07_05_members_and_helper_functions
               ch_09_07_05_members_and_helper_functions.cpp)
target_compile_definitions(ch_09_07_05_members_and_helper_functions
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_DEFAULT_CONS
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_OF_WEEK_FN)
target_link_libraries(ch_09_07_05_members_and_helper_functions
                      date_has_helpers)

add_executable(ch_09_08_date_class ch_09_08_date_class.cpp)
target_link_libraries(ch_09_08_date_class date_chrono)
