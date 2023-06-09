//File to store all the 8bit sprites used in the animations

#define TRANSP 0
#define ORANGE 1
#define BROWN 2
#define CREAM 3
#define GREEN 4
#define L_BLUE 5
#define M_BLUE 6
#define D_BLUE 7
#define GREY 8

unsigned int stand_cat_1[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    ORANGE,BROWN,TRANSP,TRANSP,BROWN,ORANGE,CREAM,CREAM,
    TRANSP,ORANGE,TRANSP,BROWN,CREAM,CREAM,ORANGE,TRANSP,
    TRANSP,BROWN,ORANGE,CREAM,CREAM,CREAM,CREAM,TRANSP,
    TRANSP,TRANSP,ORANGE,BROWN,TRANSP,CREAM,BROWN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
};

unsigned int stand_cat_2[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,ORANGE,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    TRANSP,BROWN,TRANSP,TRANSP,BROWN,ORANGE,CREAM,CREAM,
    TRANSP,ORANGE,TRANSP,BROWN,CREAM,CREAM,ORANGE,TRANSP,
    TRANSP,BROWN,ORANGE,CREAM,CREAM,CREAM,CREAM,TRANSP,
    TRANSP,TRANSP,ORANGE,BROWN,TRANSP,CREAM,BROWN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
};

unsigned int stand_cat_3[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    TRANSP,BROWN,ORANGE,TRANSP,BROWN,ORANGE,CREAM,CREAM,
    TRANSP,ORANGE,TRANSP,BROWN,CREAM,CREAM,ORANGE,TRANSP,
    TRANSP,BROWN,ORANGE,CREAM,CREAM,CREAM,CREAM,TRANSP,
    TRANSP,TRANSP,ORANGE,BROWN,TRANSP,CREAM,BROWN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
};

unsigned int cat_arm[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,ORANGE,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    TRANSP,BROWN,TRANSP,TRANSP,BROWN,ORANGE,CREAM,CREAM,
    TRANSP,ORANGE,TRANSP,BROWN,CREAM,CREAM,ORANGE,TRANSP,
    TRANSP,BROWN,ORANGE,CREAM,CREAM,CREAM,CREAM,BROWN,
    TRANSP,TRANSP,ORANGE,BROWN,TRANSP,CREAM,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
};

unsigned int sat_cat_1[8 * 8] = {
  TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    ORANGE,BROWN,TRANSP,TRANSP,BROWN,ORANGE,CREAM,CREAM,
    TRANSP,ORANGE,TRANSP,BROWN,CREAM,CREAM,ORANGE,TRANSP,
    TRANSP,BROWN,ORANGE,CREAM,CREAM,CREAM,CREAM,TRANSP,
    TRANSP,TRANSP,ORANGE,ORANGE,BROWN,CREAM,BROWN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };

  unsigned int sat_cat_2[8*8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,ORANGE,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    TRANSP,BROWN,TRANSP,TRANSP,BROWN,ORANGE,CREAM,CREAM,
    TRANSP,ORANGE,TRANSP,BROWN,CREAM,CREAM,ORANGE,TRANSP,
    TRANSP,BROWN,ORANGE,CREAM,CREAM,CREAM,CREAM,TRANSP,
    TRANSP,TRANSP,ORANGE,ORANGE,BROWN,CREAM,BROWN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };

  unsigned int sat_cat_3[8*8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    TRANSP,BROWN,ORANGE,TRANSP,BROWN,ORANGE,CREAM,CREAM,
    TRANSP,ORANGE,TRANSP,BROWN,CREAM,CREAM,ORANGE,TRANSP,
    TRANSP,BROWN,ORANGE,CREAM,CREAM,CREAM,CREAM,TRANSP,
    TRANSP,TRANSP,ORANGE,ORANGE,BROWN,CREAM,BROWN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };  

  unsigned int bath_cat_1[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    ORANGE,BROWN,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    TRANSP,BROWN,ORANGE,BROWN,M_BLUE,CREAM,ORANGE,TRANSP,
    GREY,L_BLUE,M_BLUE,D_BLUE,L_BLUE,D_BLUE,L_BLUE,GREY,
    TRANSP,M_BLUE,GREY,M_BLUE,GREY,L_BLUE,D_BLUE,TRANSP,
    TRANSP,GREY,GREY,GREY,GREY,D_BLUE,GREY,TRANSP
  };

  unsigned int bath_cat_2[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,ORANGE,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,BROWN,TRANSP,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    TRANSP,BROWN,ORANGE,BROWN,M_BLUE,CREAM,ORANGE,TRANSP,
    GREY,L_BLUE,M_BLUE,D_BLUE,L_BLUE,D_BLUE,L_BLUE,GREY,
    TRANSP,M_BLUE,GREY,M_BLUE,GREY,L_BLUE,D_BLUE,TRANSP,
    TRANSP,GREY,GREY,GREY,GREY,D_BLUE,GREY,TRANSP
  };

  unsigned int bath_cat_3[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,TRANSP,TRANSP,BROWN,
    TRANSP,TRANSP,TRANSP,TRANSP,ORANGE,ORANGE,BROWN,BROWN,
    TRANSP,BROWN,ORANGE,TRANSP,ORANGE,GREEN,BROWN,GREEN,
    TRANSP,BROWN,ORANGE,BROWN,M_BLUE,CREAM,ORANGE,TRANSP,
    GREY,L_BLUE,M_BLUE,D_BLUE,L_BLUE,D_BLUE,L_BLUE,GREY,
    TRANSP,M_BLUE,GREY,M_BLUE,GREY,L_BLUE,D_BLUE,TRANSP,
    TRANSP,GREY,GREY,GREY,GREY,D_BLUE,GREY,TRANSP
  };

  unsigned int cat_food_1[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,BROWN,TRANSP,TRANSP,BROWN,TRANSP,TRANSP,
    TRANSP,GREY,BROWN,BROWN,BROWN,GREY,TRANSP,TRANSP,
    TRANSP,TRANSP,GREY,GREY,GREY,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };

    unsigned int cat_food_2[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,GREY,BROWN,BROWN,BROWN,GREY,TRANSP,TRANSP,
    TRANSP,TRANSP,GREY,GREY,GREY,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };

    unsigned int cat_food_3[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,GREY,TRANSP,TRANSP,TRANSP,GREY,TRANSP,TRANSP,
    TRANSP,TRANSP,GREY,GREY,GREY,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };

    unsigned int yarn_1[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,GREEN,GREEN,GREEN,TRANSP,
    TRANSP,TRANSP,TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,
    TRANSP,TRANSP,TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,
    TRANSP,TRANSP,TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,
    TRANSP,TRANSP,TRANSP,TRANSP,GREEN,GREEN,GREEN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };

  unsigned int yarn_2[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,GREEN,GREEN,GREEN,TRANSP,TRANSP,
    TRANSP,TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,
    TRANSP,TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,
    TRANSP,TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,
    TRANSP,TRANSP,TRANSP,GREEN,GREEN,GREEN,GREEN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };

  unsigned int yarn_3[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,GREEN,GREEN,GREEN,TRANSP,TRANSP,TRANSP,
    TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,TRANSP,
    TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,TRANSP,
    TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,TRANSP,
    TRANSP,TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
  };

  unsigned int yarn_4[8 * 8] = {
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,
    TRANSP,GREEN,GREEN,GREEN,TRANSP,TRANSP,TRANSP,TRANSP,
    GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,TRANSP,TRANSP,
    GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,TRANSP,TRANSP,
    GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,TRANSP,TRANSP,
    TRANSP,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,TRANSP,
    TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP,TRANSP
  };