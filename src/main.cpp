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
Pen PEN_GREY = graphics.create_pen(192,192,192);
Pen PEN_L_BLUE = graphics.create_pen(153,255,255);
Pen PEN_M_BLUE = graphics.create_pen(102,178,255);
Pen PEN_D_BLUE = graphics.create_pen(0,128,255);


int main() {
    
    happiness = 100;
    cleanliness = 100;
    hunger = 100;

    cat_state = NORMAL;
    
    //Core 1:
    /* Polling buttons on an internal timer */
    multicore_launch_core1(core1_entry);

    //Core 0:
    /*Animations and tracking state changes */
    while(true) {
        graphics.set_pen(0,0,0);
        graphics.clear();

        if(cat_state == NORMAL){
            animation_stand();
        }else if(cat_state == FEEDING){
            animation_feed();
            cat_state = NORMAL;
        }else if(cat_state == PLAYING){
            animation_play();
            cat_state = NORMAL;
        }else if(cat_state == CLEANING){
            animation_bath();
            cat_state = NORMAL;
        }
    
    }
}

void draw_states_bars(){
    // Draw the levels of happiness, hunger and cleanliness to the pico-display:

}

void animation_play(){
    draw_from_arr(stand_cat_1,8,0,0);
    draw_from_arr(yarn_1,3,19,24);
    clear_animation();

    draw_from_arr(cat_arm,8,0,0);
    draw_from_arr(yarn_2,3,19,24);
    clear_animation();

    draw_from_arr(stand_cat_3,8,0,0);
    draw_from_arr(yarn_3,3,19,24);
    clear_animation();

    draw_from_arr(cat_arm,8,0,0);
    draw_from_arr(yarn_4,3,19,24);
    clear_animation();
}

void animation_feed(){
    draw_from_arr(sat_cat_1,8,0,0);
    draw_from_arr(cat_food_1,4,15,16);
    clear_animation();

    draw_from_arr(sat_cat_2,8,0,0);
    draw_from_arr(cat_food_2,4,15,16);
    clear_animation();

    draw_from_arr(sat_cat_1,8,0,0);
    draw_from_arr(cat_food_3,4,15,16);
    clear_animation();
}

void animation_stand(){
    draw_from_arr(stand_cat_1,8,0,0);
    clear_animation();

    draw_from_arr(stand_cat_2,8,0,0);
    clear_animation();


    draw_from_arr(stand_cat_3,8,0,0);
    clear_animation();


    draw_from_arr(stand_cat_2,8,0,0);
    clear_animation();
}

void animation_sat(){
    
    draw_from_arr(sat_cat_1,8,0,0);
    clear_animation();

    draw_from_arr(sat_cat_2,8,0,0);
    clear_animation();


    draw_from_arr(sat_cat_3,8,0,0);
    clear_animation();


    draw_from_arr(sat_cat_2,8,0,0);
    clear_animation();
}

void animation_bath(){
    draw_from_arr(bath_cat_1,8,0,0);
    clear_animation();

    draw_from_arr(bath_cat_2,8,0,0);
    clear_animation();

    draw_from_arr(bath_cat_3,8,0,0);
    clear_animation();

    draw_from_arr(bath_cat_2,8,0,0);
    clear_animation();
}

/**
 * Implements a time delay between frames and updates the display
*/
void clear_animation(){
    draw_states_bars();
    st7789.update(&graphics);
    sleep_ms(500);
    graphics.set_pen(0,0,0);
    graphics.clear();
}

/**
 * Draws an 8x8 sprite to the left 150x135 pixels 
*/
void draw_from_arr(unsigned int* arr,int size, int xoffset,int yoffset){

    int x = round(150 / 2.0f) - (size*4) + (xoffset * size);
    int y = round(135 / 2.0f) - (size*4) + (yoffset);

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
                case L_BLUE:
                    graphics.set_pen(PEN_L_BLUE);
                    break;
                case M_BLUE:
                    graphics.set_pen(PEN_M_BLUE);
                    break;
                case D_BLUE:
                    graphics.set_pen(PEN_D_BLUE);
                    break;    
                case GREY:
                    graphics.set_pen(PEN_GREY);
                    break;
                case TRANSP:
                    continue;
            }
            graphics.rectangle(Rect(x+(i*size),y+(j*size),size,size));

        }
    }
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
        cat_state = PLAYING;
        button_a_prev = true;    
    } 
    if(button_b.raw() && !button_b_prev){
        if((cleanliness + 30) > 100){
            cleanliness = 100;
        }else{
            cleanliness += 30;
        }
        cat_state = CLEANING;
        button_b_prev = true;    
    } 

    if(button_x.raw() && !button_x_prev){
        if((hunger + 30) > 100){
            hunger = 100;
        }else{
            hunger += 30;
        }
        cat_state = FEEDING;
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

    
    //Decreases the cleanliness, happiness and hunger of the pet every 5 seconds
    if(state_decline_counter == (100 * 5)){
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


