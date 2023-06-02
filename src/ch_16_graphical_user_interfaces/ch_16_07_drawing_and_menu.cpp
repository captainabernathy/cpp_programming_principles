// program allows a user to display a sequence of lines as specified by a
// sequence of coordinate pairs and also allows the user to change the color
// of the line
//
// program demonstrates how to use the graphics library to create a Window
// specific to program features

#include <iostream> // for cerr
#include <string> // for string
#include <sstream> // for stringstream
#include <exception> // for exception
#include <GUI/Window.hpp> // for Window, gui_main(), redraw(), x_max(), y_max()
#include <GUI/GUI.hpp> // for Menu, Button, In_box, Out_box, Address,
                       // reference_to<>()
#include <GUI/Graphics.hpp> // for Point, Open_polyline, Color

struct Lines_window : Graphics_lib::Window {

    // constructor... initializes this Lines_window to a width of w and height
    // of h pixels with its upper left coorner at xy, a name that corresponds
    // to title, default values for each private attribute, and registers
    // callback functions for each of this Lines_window's actions
    Lines_window(Point xy, int w, int h, std::string const& title);

private:
    Graphics_lib::Open_polyline lines;

    Graphics_lib::Menu color_menu; // Menu container
    Graphics_lib::Button menu_button; // "[color menu]"
    Graphics_lib::Button next_button; // "[Next point]"
    Graphics_lib::Button quit_button; // "[Quit]"
    Graphics_lib::In_box next_x; // "next x:[__]"
    Graphics_lib::In_box next_y; // "next y:[__]"
    Graphics_lib::Out_box xy_out; // "current (x,y):[__]"

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

    // performs the action of the "[Next point]" Button...
    // reads a pair of coordinates, updates this Lines_window's lines member
    // and position readout, and redraws the window
    void next();

    // performs the action of the "[Quit]" Button... deletes this Lines_window
    // on call
    void quit()
    {
        hide();
    }

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

    // callback function for the "[Next point]" Button
    static void cb_next(Graphics_lib::Address, Graphics_lib::Address);

    // callback function for the "[Quit]" Button
    static void cb_quit(Graphics_lib::Address, Graphics_lib::Address);
};

// constructor... initializes this Lines_window to a width of w and height
// of h pixels with its upper left coorner at xy, a name that corresponds
// to title, default values for each private attribute, and registers
// callback functions for each of this Lines_window's actions
Lines_window::Lines_window(Point xy, int w, int h, std::string const& title)
    : Window {xy, w, h, title}, // initialize super class
      color_menu {{x_max() - 70, 30}, 70, 20, Graphics_lib::Menu::vertical,
                   "color"},
      // private attributes
      menu_button {{x_max() - 80, 30}, 80, 20, "color menu", cb_menu},
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
    attach(lines);
}

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

// performs the action of the "[Next point]" Button...
// reads a pair of coordinates, updates this Lines_window's lines member
// and position readout, and redraws the window
void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add({x, y});

    // update current position readout
    std::stringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    redraw();
}

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

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        // initialize a Lines_window
        Lines_window win {{100, 100}, 600, 400, "lines"};
        return Graphics_lib::gui_main(); // run the program
    }
    catch (exception& ex)
    {
        cerr << "exception" << ex.what() << '\n';
        return 1;
    }
    catch ( ... )
    {
        cerr << "unknown exception\n";
        return 2;
    }
}
