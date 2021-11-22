int const EncA = 5;
int const EncB = 3;

byte valEnc;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(EncA,INPUT);
  pinMode(EncB,INPUT);  
  pinMode(12,OUTPUT);
}

void loop() {
  valEnc =valEnc + (digitalRead(EncA) << 1) + digitalRead(EncB);

  switch(valEnc){
    case B00000001:
    case B00000111:
    case B00001110:
    case B00001000:
    ++val;
    Serial.println(val);
    break;
    
    case B00000010:
    case B00001011:
    case B00001101:
    case B00000100:
      if(val>0){
        --val;
      }
    Serial.println(val);
    break;
    
    default:
    break;
  }
  valEnc = (valEnc<<2) & B00001100;
  tone(12,val);
}
