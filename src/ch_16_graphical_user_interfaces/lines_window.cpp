#include "lines_window.hpp"

#include <string> // for string
#include <sstream> // for stringstream
#include <GUI/Window.hpp> // for x_max(), redraw()
#include <GUI/GUI.hpp> // for Address, reference_to<>
#include <GUI/Graphics.hpp> // for Point

// constructor... initializes this Lines_window to a width of w and height
// of h pixels with its upper left coorner at xy, a name that corresponds
// to title, default values for each private attribute, and registers
// callback functions for each of this Lines_window's actions
Lines_window::Lines_window(Point xy, int w, int h, const std::string& title)
    : Window {xy, w, h, title}, // initialize super class
#ifndef NO_MENU
      color_menu {{x_max() - 70, 30}, 70, 20, Graphics_lib::Menu::vertical,
                   "color"},
      // private attributes
      menu_button {{x_max() - 80, 30}, 80, 20, "color menu", cb_menu},
#endif
      next_button {{x_max() - 150, 0}, 70, 20, "Next point", cb_next},
      quit_button {{x_max() - 70, 0}, 70, 20, "Quit", cb_quit},
      next_x {{x_max() - 310, 0}, 50, 20, "next x:"},
      next_y {{x_max() - 210, 0}, 50, 20, "next y:"},
      xy_out {{100, 0}, 100, 20, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
#ifndef NO_MENU
    xy_out.put("no point"); // default value in Out_box
    
    // Buttons for color Menu
    color_menu.attach(new Graphics_lib::Button {{0, 0}, 0, 0, "red", cb_red});
    color_menu.attach(new Graphics_lib::Button {{0, 0}, 0, 0, "blue",
                      cb_blue});
    color_menu.attach(new Graphics_lib::Button {{0, 0}, 0, 0, "black",
                      cb_black});

    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
#endif
    attach(lines);
}

// the "Next point" button's action... it reads a pair of coordinates,
// updates this Lines_window's lines member and position readout, and
// redraws the window
void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add({x, y});

    // update current position readout:
    std::stringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

#ifndef NO_MENU
// callback function for the "[red]" Button
void Lines_window::cb_red(Graphics_lib::Address, Graphics_lib::Address wid)
{
    // (*static_cast<Lines_window *>(wid)).red_pressed();
    // static_cast<Lines_window *>(wid)->red_pressed();
    // same as either of the above
    Graphics_lib::reference_to<Lines_window>(wid).red_pressed();
}

// callback function for the "[blue]" Button
void Lines_window::cb_blue(Graphics_lib::Address, Graphics_lib::Address wid)
{
    // (*static_cast<Lines_window *>(wid)).blue_pressed();
    // static_cast<Lines_window *>(wid)->blue_pressed();
    // same as either of the above
    Graphics_lib::reference_to<Lines_window>(wid).blue_pressed();
}

// callback function for the "[black]" Button
void Lines_window::cb_black(Graphics_lib::Address, Graphics_lib::Address wid)
{
    // (*static_cast<Lines_window *>(wid)).black_pressed();
    // static_cast<Lines_window *>(wid)->black_pressed();
    // same as either of the above
    Graphics_lib::reference_to<Lines_window>(wid).black_pressed();
}

// callback function for the "[color menu]" Button
void Lines_window::cb_menu(Graphics_lib::Address, Graphics_lib::Address wid)
{
    // (*static_cast<Lines_window *>(wid)).menu_pressed();
    // static_cast<Lines_window *>(wid)->menu_pressed();
    // same as either of the above
    Graphics_lib::reference_to<Lines_window>(wid).menu_pressed();
}
#endif

// callback function for the "[Quit]" Button
void Lines_window::cb_quit(Graphics_lib::Address, Graphics_lib::Address wid)
{
    // (*static_cast<Lines_window *>(wid)).quit();
    // static_cast<Lines_window *>(wid)->quit();
    // same as either of the above
    Graphics_lib::reference_to<Lines_window>(wid).quit();
}

// callback function for the "[Next point]" Button
void Lines_window::cb_next(Graphics_lib::Address, Graphics_lib::Address wid)
{
    // (*static_cast<Lines_window *>(wid)).next();
    // static_cast<Lines_window *>(wid)->next();
    // same as either of the above
    Graphics_lib::reference_to<Lines_window>(wid).next();
}
