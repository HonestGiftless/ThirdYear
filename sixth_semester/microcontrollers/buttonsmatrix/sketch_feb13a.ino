int inputs[] = {3,4};
int outputs[] = {5,6};
int btnStates[4];

void setup(){
  Serial.begin(9600);
  for(int i=0; i<2; i++){
  	pinMode(outputs[i], OUTPUT);
    digitalWrite(outputs[i], LOW);
  }
  for( int i=0; i<2; i++){
  	pinMode( inputs[i], INPUT );
  }
  for( int i=0; i<4; i++){
  	btnStates[i]=0;
  }
}

void loop(){
  for( int y=0; y<2; y++){
    digitalWrite(outputs[y], HIGH);
    for(int x=0; x<2; x++){
      btnStates[x+y*2]=digitalRead(inputs[x]);
    }
    digitalWrite(outputs[y], LOW);
  }
  
  for( int i=0; i<4; i++){
  	Serial.print(String(i)+": "+String(btnStates[i])+", ");
  }               
  Serial.println(" ");
  delay( 100 );
}
