int jugadores=24;
int opciones=8;
int cuanto=9;
int buttonState;
int buttonPin=25;
int buttonAlc=33;
int MQ3=0;
int state=0; //1 que, 2 que hace, 3 como lo hace
int value;
void setup() {
// configurar pines 
Serial.begin(9600);
pinMode(MQ3, INPUT);
for (int i=1; i <=jugadores; i++){// LEDS DE QUIEN
  pinMode(i, OUTPUT);
}
pinMode(25,INPUT);//BOTON PRINCIPAL

for (int i=1; i<=opciones; i++){//LEDS DE QUE
  pinMode(jugadores+1+i,OUTPUT);
}
pinMode(33, INPUT); //BOTON ALCOHOTEST
for (int i=1; i<=cuanto; i++){//LEDS DE QUE
  pinMode(jugadores+1+i,OUTPUT);
}

}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState==HIGH){
    state=state+1;
    if (state==5){
      state=0;
    }
  }
  if (state==1){
    quien();
  }
  if (state==2){
    quien();
  }
  if (state==3){
    quien();
  }
  if (state==4){
    quien();
  }
}
void pararLento(int totalLeds, int ini){
  int azar=random(ini,ini+totalLeds-1);
  for (int i=ini; i<azar; i++){
    digitalWrite(i,HIGH);
    delay(70+(i-ini));
    digitalWrite(i,LOW);
  }
  digitalWrite(azar,HIGH);
} 
void quien(){
  vuelta(50, 4,jugadores,1);
  vuelta(70, 1,jugadores,1);
  pararLento(jugadores, 1);
  
}
void queHace(){
  vuelta(50, 3,opciones,jugadores+2);
  vuelta(70, 1,opciones,jugadores+2);
  pararLento(opciones, jugadores+2);
  
}
void alcoTest(){
  value = analogRead(MQ3);
  
  
}


void vuelta(int lentitud, int vueltas, int totalLeds, int ini){
  for (int j=0; j<vueltas;j++){
    for (int i=1; i<=totalLeds;i++){
      digitalWrite(i, HIGH);
      delay(lentitud);
      digitalWrite(i,LOW);
      //delay(lentitud);
    }
  }
}
