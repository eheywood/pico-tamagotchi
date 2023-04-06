#include "main.h"

using namespace pimoroni;

ST7789 st7789(PicoDisplay::WIDTH, PicoDisplay::HEIGHT, ROTATE_0, false, get_spi_pins(BG_SPI_FRONT));
PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

//Button definitions
Button button_a(PicoDisplay::A);
Button button_b(PicoDisplay::B);
Button button_x(PicoDisplay::X);
Button button_y(PicoDisplay::Y);

volatile int x_coord = st7789.width / 2;
volatile int y_coord = st7789.height / 2;

int main() {

    graphics.rectangle(Rect(Point(0,0),Point(9,9)));
    
    //Core 0:
    /*Animations and tracking state changes */

    //Core 1:
    /* Polling buttons on an internal timer */
    multicore_launch_core1(core1_entry);

    while(true) {
        graphics.set_pen(0, 0, 0);
        graphics.clear();

        draw_states_bars();

        // now we've done our drawing let's update the screen
        st7789.update(&graphics);
    }
}

void draw_states_bars(){
    graphics.set_pen(255,255,255);
    graphics.thick_line(Point(170,10),Point(230,10),3);
    graphics.thick_line(Point(170,20),Point(230,20),3);
    graphics.thick_line(Point(170,30),Point(230,30),3);

    //happiness
    int hap_length = 50*(happiness/100);
    graphics.set_pen(255, 51, 153);
    graphics.thick_line(Point(170,10),Point(170+hap_length,10),3);

    //hunger
    int hung_length = 50*(hunger/100);
    graphics.set_pen(255, 128, 0);
    graphics.thick_line(Point(170,20),Point(170+hung_length,20),3);

    //cleanliness
    int clean_length = 50*(cleanliness/100);
    graphics.set_pen(102, 255, 255);
    graphics.thick_line(Point(170,30),Point(170+clean_length,30),3);

}

/* Entry for second core to poll buttons */
void core1_entry(){
    state_decline_counter = 0;
    while(true){
        button_alarm_fired = false;
        button_a_prev = false;
        button_b_prev = false;
        button_x_prev = false;

        button_poll_alarm(100000); 

        while(!button_alarm_fired);
    }
}

static void button_poll_alarm(uint32_t delay){
    // Enable the interrupt for our alarm (the timer outputs 4 alarm irqs)
    hw_set_bits(&timer_hw->inte, 1u << BUTTON_ALARM);
    // Set irq handler for alarm irq
    irq_set_exclusive_handler(BUTTON_IRQ, poll_buttons_irq);
    // Enable the alarm irq
    irq_set_enabled(BUTTON_IRQ, true);
    // Enable interrupt in block and at processor

    uint64_t target = timer_hw->timerawl + delay;
    
    timer_hw->alarm[BUTTON_ALARM] = (uint32_t) target;
}


/*Polls the values from the buttons*/
void poll_buttons_irq(){
    hw_clear_bits(&timer_hw->intr, 1u << BUTTON_ALARM);

    if(button_a.raw() && !button_a_prev){
        happiness += 30;
        button_a_prev = true;    
    } 
    if(button_b.raw() && !button_b_prev){
        cleanliness += 30;
        button_b_prev = true;    
    } 

    if(button_x.raw() && !button_x_prev){
        hunger += 30;
        button_x_prev = true;    
    } 

    //if(button_y.raw()) y_coord += 1;

    if(state_decline_counter == (10*10)){
        state_decline();
        state_decline_counter = 0;
    }else{
        state_decline_counter += 1;
    }

    button_alarm_fired = true;
}

void state_decline(){
    if(!(happiness <= 0)){
        happiness = happiness - 10;
    }

    if(!(cleanliness <= 0)){
        cleanliness = cleanliness - 10;
    }
    if(!(hunger <= 0)){
        hunger = hunger - 10;
    }
}


