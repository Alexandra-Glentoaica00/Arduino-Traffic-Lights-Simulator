//-----------variables
int trafficLight_red_LED = 2;
int trafficLight_yellow_LED = 3;
int trafficLight_green_LED = 4;

int pedestrianLight_red_LED = 5;
int pedestrianLight_yellow_LED = 6;
int pedestrianLight_green_LED = 7;

int button = 8;
int button_current_state;
int button_previous_state=1;

int buzzer = 9;

int latch = 11;
int data = 12;
int clock = 13;

//delay times
int dt_red_LED = 10000; //10.000 ms <-> 10 seconds
int dt_green_LED = 7000; //7000 ms <-> 7 seconds
int dt_yellow_LED = 3000; //3000 ms <-> 3 seconds
int dt_one_second = 1000;

//-----------functions
void segment_display_countdown(byte value){
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, value);
  digitalWrite(latch, HIGH);
  delay(dt_one_second);
}

void traffic_light_on(){ 
  segment_display_countdown(0);
  digitalWrite(trafficLight_green_LED, HIGH);
  digitalWrite(trafficLight_yellow_LED, LOW);
  digitalWrite(trafficLight_red_LED, LOW);
  digitalWrite(pedestrianLight_red_LED, HIGH);
}

void traffic_light_off(){ //first function called after the button is pushed
  digitalWrite(trafficLight_green_LED, HIGH);
  delay(5000); //the green light won't turn off immediatly after the push, it will stay on for 7 more seconds
  digitalWrite(trafficLight_green_LED, LOW);
  digitalWrite(trafficLight_yellow_LED, HIGH);
  delay(dt_yellow_LED);
  digitalWrite(trafficLight_yellow_LED, LOW);
  digitalWrite(trafficLight_red_LED, HIGH);
}

void pedestrian_light_on(){
  digitalWrite(pedestrianLight_red_LED, LOW);

  digitalWrite(pedestrianLight_green_LED, HIGH);
  digitalWrite(buzzer, HIGH);
  segment_display_countdown(103);
  segment_display_countdown(127);
  segment_display_countdown(7);
  segment_display_countdown(125);
  segment_display_countdown(109);
  segment_display_countdown(102);
  segment_display_countdown(79);
  
  digitalWrite(pedestrianLight_green_LED, LOW);

  digitalWrite(pedestrianLight_yellow_LED, HIGH);
  segment_display_countdown(91);
  segment_display_countdown(6);
  segment_display_countdown(63);

  digitalWrite(pedestrianLight_yellow_LED, LOW);
  digitalWrite(buzzer, LOW);

  digitalWrite(pedestrianLight_red_LED, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  pinMode(trafficLight_red_LED, OUTPUT);
  pinMode(trafficLight_yellow_LED, OUTPUT);
  pinMode(trafficLight_green_LED, OUTPUT);

  pinMode(pedestrianLight_red_LED, OUTPUT);
  pinMode(pedestrianLight_yellow_LED, OUTPUT);
  pinMode(pedestrianLight_green_LED, OUTPUT);

  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
}

void loop() {
  traffic_light_on();

  button_current_state=digitalRead(button);
  if(button_current_state != button_previous_state){
    if(button_current_state == 0){
      Serial.println("butonul a fost apasat!");
      traffic_light_off();
      pedestrian_light_on();
    }
    button_previous_state=button_current_state;
  }

}