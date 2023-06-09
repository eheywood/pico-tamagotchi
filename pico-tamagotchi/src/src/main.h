#include "pico_display.hpp"
#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "button.hpp"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include <cmath>
#include "cats.h"

//Tamagotchi states
static volatile int hunger;
static volatile int happiness;
static volatile int cleanliness;

//CAT STATES
#define NORMAL 0
#define FEEDING 1
#define CLEANING 2
#define PLAYING 3

static volatile int cat_state;

//For the internal timer interrupt for the button polling
#define BUTTON_ALARM 0
#define BUTTON_IRQ TIMER_IRQ_0
static volatile bool button_alarm_fired;
volatile int state_decline_counter;

//last states of each of the buttons
bool button_a_prev;
bool button_b_prev;
bool button_x_prev;

void draw_states_bars();
void draw_from_arr(unsigned int* arr, int size,int xoffset,int yoffset);
void draw_incr_pixel(int size,int x,int y);
void animation_sat();
void animation_stand();
void animation_feed();
void animation_play();
void animation_bath();
void clear_animation();


void core1_entry();
static void button_poll_alarm(uint32_t delay);
void poll_buttons_irq();
void state_decline();