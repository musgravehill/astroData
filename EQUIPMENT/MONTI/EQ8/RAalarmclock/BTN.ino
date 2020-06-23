

void BUTTON_BOX_check() {
  uint8_t state;

  //pult_speed_inc 5 //PD5
  state = bitRead(PIND, 5);
  if (state == 0) { //btn pressed
    PULT_SPEED_inc();
  }

  //pult_speed_dec PD4
  state = bitRead(PIND, 4);
  if (state == 0) { //btn pressed
    PULT_SPEED_dec();
  }

}

void BUTTON_PULT_check() {
  uint8_t state;
  uint8_t SYS_STATE_TMP = SYS_STATE_STAR_TRACKING;

  //BUTTON_RA_FORWARD 7 //PD7
  state = bitRead(PIND, 7);
  if (state == 0) {
    SYS_STATE_TMP = SYS_STATE_PULT_RA_FORWARD;
  }

  //BUTTON_RA_BACKWARD 6 //PD6
  state = bitRead(PIND, 6);
  if (state == 0) {
    SYS_STATE_TMP = SYS_STATE_PULT_RA_BACKWARD;
  }

  //BUTTON_DEC_FORWARD 9 //PB1
  state = bitRead(PINB, 1);
  if (state == 0) {
    SYS_STATE_TMP = SYS_STATE_PULT_DEC_FORWARD;
  }

  //BUTTON_DEC_BACKWARD 8 //PB0
  state = bitRead(PINB, 0);
  if (state == 0) {
    SYS_STATE_TMP = SYS_STATE_PULT_DEC_BACKWARD;
  }

  SYS_STATE = SYS_STATE_TMP;

  if (SYS_STATE_PREV != SYS_STATE) {
    switch (SYS_STATE) {
      case SYS_STATE_PULT_RA_FORWARD:
        TIMER_config(PULT_SPEED_COEFF, true, true);
        break;
      case SYS_STATE_PULT_RA_BACKWARD:
        TIMER_config(PULT_SPEED_COEFF, false, true);
        break;
      case SYS_STATE_PULT_DEC_FORWARD:
        TIMER_config(PULT_SPEED_COEFF, true, true);
        break;
      case SYS_STATE_PULT_DEC_BACKWARD:
        TIMER_config(PULT_SPEED_COEFF, true, false);
        break;
      case SYS_STATE_STAR_TRACKING:
        TIMER_config(1, true, true);
        break;
    }
  }
  SYS_STATE_PREV = SYS_STATE;
}

void BUTTON_init() {
  pinMode(RA_speed_inc,  INPUT_PULLUP);
  pinMode(RA_speed_dec,  INPUT_PULLUP);

  pinMode(BUTTON_RA_FORWARD,  INPUT_PULLUP);
  pinMode(BUTTON_RA_BACKWARD,  INPUT_PULLUP);
  pinMode(BUTTON_DEC_FORWARD,  INPUT_PULLUP);
  pinMode(BUTTON_DEC_BACKWARD,  INPUT_PULLUP);
}

void PULT_SPEED_inc() {
  if (PULT_SPEED_COEFF < PULT_SPEED_COEFF_MAX && PULT_SPEED_COEFF < 50) {
    PULT_SPEED_COEFF++;
  }
  if (PULT_SPEED_COEFF < PULT_SPEED_COEFF_MAX && PULT_SPEED_COEFF >= 50) {
    PULT_SPEED_COEFF += 100;
  }
  PULT_SPEED_COEFF = constrain(PULT_SPEED_COEFF, PULT_SPEED_COEFF_MIN, PULT_SPEED_COEFF_MAX);
}
void PULT_SPEED_dec() {
  if (PULT_SPEED_COEFF > PULT_SPEED_COEFF_MIN && PULT_SPEED_COEFF < 50) {
    PULT_SPEED_COEFF--;
  }
  if (PULT_SPEED_COEFF > PULT_SPEED_COEFF_MIN && PULT_SPEED_COEFF >= 50) {
    PULT_SPEED_COEFF -= 100;
  }
  PULT_SPEED_COEFF = constrain(PULT_SPEED_COEFF, PULT_SPEED_COEFF_MIN, PULT_SPEED_COEFF_MAX);
}


