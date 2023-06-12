add_library(lines_window.no_menu OBJECT "lines_window.cpp")
target_compile_definitions(lines_window.no_menu PRIVATE -DNO_MENU)

add_library(lines_window OBJECT "lines_window.cpp")

add_executable(ch_16_05_drawing_example ch_16_05_drawing_example.cpp)
target_compile_definitions(ch_16_05_drawing_example PRIVATE -DNO_MENU)
target_link_libraries(ch_16_05_drawing_example
                      lines_window.no_menu
                      bookgui
                      fltk
                      fltk_images
                      X11)

add_executable(ch_16_07_drawing_and_menu ch_16_07_drawing_and_menu.cpp)
target_link_libraries(ch_16_07_drawing_and_menu
                      lines_window
                      bookgui
                      fltk
                      fltk_images
                      X11)
