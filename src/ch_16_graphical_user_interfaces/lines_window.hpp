#ifndef LINES_WINDOW_HPP
#define LINES_WINDOW_HPP

#include <string> // for string
#include <GUI/Window.hpp> // for Window
#include <GUI/Graphics.hpp> // for Point, Open_polyline, Color
#include <GUI/GUI.hpp> // for Menu, Button, In_box, Out_box, Address

// class that represents a Window in which the user can draw lines that connect
// Points as specified by the user
struct Lines_window : Graphics_lib::Window {

    // constructor... initializes this Lines_window to a width of w and height
    // of h pixels with its upper left coorner at xy, a name that corresponds
    // to title, default values for each private attribute, and registers
    // callback functions for each of this Lines_window's actions
    Lines_window(Point xy, int w, int h, const std::string& title);

private:
    Graphics_lib::Open_polyline lines;
#ifndef NO_MENU
    Graphics_lib::Menu color_menu; // Menu container
    Graphics_lib::Button menu_button; // "[color menu]"
#endif
    Graphics_lib::Button next_button; // "[Next point]"
    Graphics_lib::Button quit_button; // "[Quit]"
    Graphics_lib::In_box next_x; // "next x:[___]"
    Graphics_lib::In_box next_y; // "next y:[___]"
    Graphics_lib::Out_box xy_out; // "current (x,y):[___]"

#ifndef NO_MENU
    // sets the Color of this Lines_windows lines to c
    void change(Graphics_lib::Color c)
    {
        lines.set_color(c);
    }

    // makes the color Menu invisible and the "[color menu]" Button visible
    void hide_menu()
    {
        color_menu.hide(); // make color menu (options) invisible
        menu_button.show(); // make "[color menu]" button visible
    }

    // performs the action of the "[red]" Button...
    // sets the color of this Lines_window's lines to red, makes the color
    // Menu invisible, and the "[color menu]" Button visible
    void red_pressed()
    {
        change(Graphics_lib::Color::red);
        hide_menu();
    }

    // performs the action of the "[blue]" Button...
    // sets the color of this Lines_window's lines to blue, makes the color
    // Menu invisible, and the "[color menu]" Button visible
    void blue_pressed()
    {
        change(Graphics_lib::Color::blue);
        hide_menu();
    }

    // performs the action of the "[black]" Button...
    // sets the color of this Lines_window's lines to black, makes the color
    // Menu invisible, and the "[color menu]" Button visible
    void black_pressed()
    {
        change(Graphics_lib::Color::black);
        hide_menu();
    }

    // performs the action of the "[color menu]" Button...
    // makes the "[color menu]" Button invisible and the color Menu visible
    void menu_pressed()
    {
        menu_button.hide(); // make "[color menu]" button invisible
        color_menu.show(); // make color menu (options) visible
    }
#endif

    // the "Next point" button's action... it reads a pair of coordinates,
    // updates this Lines_window's lines member and position readout, and
    // redraws the window
    void next();

    // the "Quit" button's action... clicking it, deletes this Lines_window
    void quit()
    {
        hide();
    }

#ifndef NO_MENU
    // callback functions... callable through the class
    // NOTE: Address is a synonym for void *
    // callback function for the "[red]" Button
    static void cb_red(Graphics_lib::Address, Graphics_lib::Address);

    // callback function for the "[blue]" Button
    static void cb_blue(Graphics_lib::Address, Graphics_lib::Address);

    // callback function for the "[black]" Button
    static void cb_black(Graphics_lib::Address, Graphics_lib::Address);

    // callback function for the "[color menu]" Button
    static void cb_menu(Graphics_lib::Address, Graphics_lib::Address);
#endif
    // callback for next_button
    static void cb_next(Graphics_lib::Address, Graphics_lib::Address);
 
    // callback for quit_button
    static void cb_quit(Graphics_lib::Address, Graphics_lib::Address);
};

#endif
