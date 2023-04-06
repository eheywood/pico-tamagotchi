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

//PENS for drawing the cat
Pen PEN_ORANGE = graphics.create_pen(255,153,51);
Pen PEN_BROWN = graphics.create_pen(101,57,13);
Pen PEN_CREAM = graphics.create_pen(252,235,203);
Pen PEN_GREEN = graphics.create_pen(178,255,102);

int main() {
    
    happiness = 100;
    cleanliness = 100;
    hunger = 100;
    
    //Core 1:
    /* Polling buttons on an internal timer */
    multicore_launch_core1(core1_entry);

    //Core 0:
    /*Animations and tracking state changes */
    while(true) {
        graphics.set_pen(0,0,0);
        graphics.clear();

        
        animation_normal();
    
    }
}

void animation_normal(){
    draw_from_arr(cat_1);
    draw_states_bars();
    st7789.update(&graphics);
    sleep_ms(500);
    graphics.set_pen(0,0,0);
    graphics.clear();

    draw_from_arr(cat_2);
    draw_states_bars();
    st7789.update(&graphics);
    sleep_ms(500);
    graphics.set_pen(0,0,0);
    graphics.clear();

    draw_from_arr(cat_3);
    draw_states_bars();
    st7789.update(&graphics);
    sleep_ms(500);
    graphics.set_pen(0,0,0);
    graphics.clear();

    draw_from_arr(cat_2);
    draw_states_bars();
    st7789.update(&graphics);
    sleep_ms(500);
    graphics.set_pen(0,0,0);
    graphics.clear();

}

void draw_from_arr(unsigned int* arr){
    int size = 8;

    int x = round(150 / 2.0f) - (size*4);
    int y = round(135 / 2.0f) - (size*4);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            switch(*(arr + i + (j*8))) {
                case ORANGE:
                    graphics.set_pen(PEN_ORANGE);
                    break;
                case BROWN:
                    graphics.set_pen(PEN_BROWN);
                    break;
                case CREAM:
                    graphics.set_pen(PEN_CREAM);
                    break;
                case GREEN:
                    graphics.set_pen(PEN_GREEN);
                    break;
                case TRANSP:
                    continue;
            }
            graphics.rectangle(Rect(x+(i*size),y+(j*size),size,size));

        }
    }
}


void draw_states_bars(){
    float lineLength = 70.0f;
    graphics.set_pen(255,255,255);
    graphics.thick_line(Point(160,10),Point(160+lineLength,10),3);
    graphics.thick_line(Point(160,25),Point(160+lineLength,25),3);
    graphics.thick_line(Point(160,40),Point(160+lineLength,40),3);

    //happiness
    int hap_length = round(lineLength * (happiness/100.0f));
    graphics.set_pen(255, 51, 153);
    graphics.text("happiness",Point(160,0),10,1.25F,0.0F,1);
    graphics.thick_line(Point(160,10),Point(160+hap_length,10),3);

    //hunger
    int hung_length = round(lineLength * (hunger/100.0f));
    graphics.set_pen(255, 128, 0);
    graphics.text("hunger",Point(160,15),10,1.25F,0.0F,1);
    graphics.thick_line(Point(160,25),Point(160+hung_length,25),3);

    //cleanliness
    int clean_length = round(lineLength * (cleanliness/100.0f));
    graphics.set_pen(51, 153, 255);
    graphics.text("cleanliness",Point(160,30),10,1.25F,0.0F,1);
    graphics.thick_line(Point(160,40),Point(160+clean_length,40),3);

}


/* Entry for second core to poll buttons */
void core1_entry(){
    state_decline_counter = 0;
    button_a_prev = false;
    button_b_prev = false;
    button_x_prev = false;
    while(true){
        button_alarm_fired = false;
        
        button_poll_alarm(10000); 

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
        if((happiness + 30) > 100){
            happiness = 100;
        }else{
            happiness += 30;
        }
        button_a_prev = true;    
    } 
    if(button_b.raw() && !button_b_prev){
        if((cleanliness + 30) > 100){
            cleanliness = 100;
        }else{
            cleanliness += 30;
        }
        button_b_prev = true;    
    } 

    if(button_x.raw() && !button_x_prev){
        hunger += 30;
        button_x_prev = true;    
    } 

    if(button_a_prev && !button_a.raw()){
        button_a_prev = false;
    }
    if(button_b_prev && !button_b.raw()){
        button_b_prev = false;
    }
    if(button_x_prev && !button_x.raw()){
        button_x_prev = false;
    }

    //if(button_y.raw()) y_coord += 1;

    if(state_decline_counter == (100)){
        state_decline();
        state_decline_counter = 0;
    }else{
        state_decline_counter += 1;
    }

    button_alarm_fired = true;
}

void state_decline(){
    if(!(happiness <= 0)){
        happiness += -1;
    }
    if(!(cleanliness <= 0)){
        cleanliness += -1;
    }
    if(!(hunger <= 0)){
        hunger += -1;
    }
}


