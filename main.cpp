#include "pico_display.hpp"
#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "button.hpp"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/timer.h"
#include "hardware/irq.h"

#define ALARM_NUM 0
#define ALARM_IRQ TIMER_IRQ_0

static volatile bool alarm_fired;

using namespace pimoroni;

ST7789 st7789(PicoDisplay::WIDTH, PicoDisplay::HEIGHT, ROTATE_0, false, get_spi_pins(BG_SPI_FRONT));
PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

Button button_a(PicoDisplay::A);
Button button_b(PicoDisplay::B);
Button button_x(PicoDisplay::X);
Button button_y(PicoDisplay::Y);

volatile int x_coord = st7789.width / 2;
volatile int y_coord = st7789.height / 2;

void core1_entry();
static void alarm(uint32_t delay);
void poll_buttons_irq();

int main() {

    graphics.rectangle(Rect(Point(0,0),Point(9,9)));
    

    //Core 0:
    /*Animations and tracking state changes */

    //Core 1:
    /* Polling buttons on an internal timer */
    multicore_launch_core1(core1_entry);

    while(true) {
        graphics.set_pen(255, 35, 40);
        graphics.clear();

        graphics.set_pen(0,255,50);
        graphics.circle(Point(x_coord,y_coord),10);

        // now we've done our drawing let's update the screen
        st7789.update(&graphics);
    }
}

/* Entry for second core to poll buttons */
void core1_entry(){
    while(true){
        alarm_fired = false;

        alarm(10000); 

        while(!alarm_fired);
    }
}

static void alarm(uint32_t delay){
    // Enable the interrupt for our alarm (the timer outputs 4 alarm irqs)
    hw_set_bits(&timer_hw->inte, 1u << ALARM_NUM);
    // Set irq handler for alarm irq
    irq_set_exclusive_handler(ALARM_IRQ, poll_buttons_irq);
    // Enable the alarm irq
    irq_set_enabled(ALARM_IRQ, true);
    // Enable interrupt in block and at processor

    uint64_t target = timer_hw->timerawl + delay;
    
    timer_hw->alarm[ALARM_NUM] = (uint32_t) target;
}

/*Polls the values from the buttons*/
void poll_buttons_irq(){
    hw_clear_bits(&timer_hw->intr, 1u << ALARM_NUM);

    if(button_a.raw()) x_coord -= 1;
    if(button_b.raw()) x_coord += 1;

    if(button_x.raw()) y_coord -= 1;
    if(button_y.raw()) y_coord += 1;

    alarm_fired = true;
}


