void MOTOR_RA_TICK() {
  PORTB |= _BV(PB5); //high
  delayMicroseconds(4); //DRV8825 needs 1.9 us
  PORTB &= ~_BV(PB5); //low
}

void MOTOR_DEC_TICK() {
  PORTB |= _BV(PB3); //high
  delayMicroseconds(4); //8us by OWON. DRV8825 needs 1.9 us
  PORTB &= ~_BV(PB3); //low
}

//RA true== star_speed (ПРОТИВ ЧАСОВОЙ СТРЕЛКИ); false == counter star rotation (ПО ЧАСОВОЙ СТРЕЛКЕ)
void MOTOR_set_RA_dir(bool dir_forward) {
  if (dir_forward) {
    PORTB |= _BV(PB4); //high
  } else {
    PORTB &= ~_BV(PB4); //low
  }
}
void MOTOR_set_DEC_dir(bool dir_forward) {
  if (dir_forward) {
    PORTB |= _BV(PB2); //high
  } else {
    PORTB &= ~_BV(PB2); //low
  }
}

void MOTOR_init() {
  pinMode(DRIVER_RA_STEP,  OUTPUT);
  digitalWrite(DRIVER_RA_STEP, LOW);

  pinMode(DRIVER_RA_DIR,  OUTPUT);
  digitalWrite(DRIVER_RA_DIR, LOW);

  pinMode(DRIVER_DEC_STEP,  OUTPUT);
  digitalWrite(DRIVER_DEC_STEP, LOW);

  pinMode(DRIVER_DEC_DIR,  OUTPUT);
  digitalWrite(DRIVER_DEC_DIR, LOW);

  MOTOR_set_RA_dir(true); //run star-speed  ПРОТИВ ЧАСОВОЙ СТРЕЛКИ
  TIMER_STAR_config(); //run star-speed
}

