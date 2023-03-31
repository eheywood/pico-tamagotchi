#include "pico_display.hpp"
#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "button.hpp"
#include "hardware/gpio.h"
#include "pico/stdlib.h"

using namespace pimoroni;

ST7789 st7789(PicoDisplay::WIDTH, PicoDisplay::HEIGHT, ROTATE_0, false, get_spi_pins(BG_SPI_FRONT));
PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

Button button_a(PicoDisplay::A);
Button button_b(PicoDisplay::B);
Button button_x(PicoDisplay::X);
Button button_y(PicoDisplay::Y);

int main() {
    int x_coord = st7789.width / 2;
    int y_coord = st7789.height / 2;

    //Core 0:
    /*Animations and tracking state changes */

    //Core 1:
    /* Polling buttons on a timer */

    graphics.rectangle(Rect(Point(0,0),Point(9,9)));

    while(true) {
        graphics.set_pen(255, 35, 40);
        graphics.clear();

        if(button_a.raw()) x_coord -= 1;
        if(button_b.raw()) x_coord += 1;

        if(button_x.raw()) y_coord -= 1;
        if(button_y.raw()) y_coord += 1;

        graphics.set_pen(0,255,50);
        graphics.circle(Point(x_coord,y_coord),10);

        // now we've done our drawing let's update the screen
        st7789.update(&graphics);
    }
}