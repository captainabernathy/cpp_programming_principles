#include <GUI/GUI.hpp>
#include <cstdlib> // for strtol()
#include <cerrno> // for errno
#include <climits> // for LONG_MIN, LONG_MAX, INT_MIN, INT_MAX
#include <FL/Fl_Input.H> // for Fl_Input
#include <GUI/Point.hpp> // for Point

namespace Graphics_lib {

// returns the integer typed into this In_box... or -999999 if this In_box
// does not contain an integer
// NOTE: this function does not parse an integer expression... it only attempts
// to parse (and return) a single integer from the text entered into this
// In_box
int In_box::get_int()
{
    Fl_Input& pi = reference_to<Fl_Input>(widptr);
    const char *p = pi.value();
    char *end;
    errno = 0;
    long l = strtol(p, &end, 10);
    if (((l == LONG_MIN || l == LONG_MAX) && errno)
        || (l < INT_MIN || l > INT_MAX)
        || (p == end) || *end)
        return -999999;
    
    return int(l);
}

// attaches b to this Menu and returns b's position in this Menu's Vector_ref
// of Buttons
int Menu::attach(Button& b)
{
    // initialize b's width and height to this Menu's width and height
    b.width = width;
    b.height = height;

    // NOTE: k is this Menu's Kind (horizontal or vertical)
    switch (k)
    {
        case horizontal:
            // adjust b's location horizontally and update this menu's offset
            b.loc = {loc.x + offset, loc.y};
            offset += b.width;
            break;
        case vertical:
            // adjust b's location vertically and update this menu's offset
            b.loc = {loc.x, loc.y + offset};
            offset += b.height;
            break;
    }

    // add b to this Menu's Vector_ref of Buttons
    selection.push_back(b); // b is NOT OWNED... pass by reference
    return int(selection.size() - 1); // index of b in this Menu's Vector_ref
}

// attaches a new Botton (p) to this Menu and returns p's position in this
// Menu's Vector_ref of Buttons
int Menu::attach(Button *p)
{
    // initialize a reference to a Button with *p
    Button &b = *p;

    // initialize b's width and height to this Menu's width and height
    b.width = width;
    b.height = height;

    // NOTE: k is this Menu's Kind (horizontal or vertical)
    switch (k)
    {
        case horizontal:
            // adjust b's location horizontally and update this menu's offset
            b.loc = {loc.x + offset, loc.y};
            offset += b.width;
            break;
        case vertical:
            // adjust b's location vertically and update this menu's offset
            b.loc = {loc.x, loc.y + offset};
            offset += b.height;
            break;
    }

    // add b to this Menu's Vector_ref of Buttons
    selection.push_back(&b); // b is owned... pass by pointer
    return int(selection.size() - 1); // index of b in this Menu's Vector_ref
}

}
