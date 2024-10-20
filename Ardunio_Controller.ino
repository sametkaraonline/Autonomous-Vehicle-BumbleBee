
// HIGH 5V, LOW 0V demek.

//Left

const int EnableL = 5;
const int HighL = 6;
const int LowL = 7;

//Right

const int EnableR = 10;
const int HighR = 8;
const int LowR = 9;

char gelenVeri;

void setup() {
  // put your setup code here, to run once:

  pinMode(EnableL, OUTPUT);
  pinMode(HighL, OUTPUT);
  pinMode(LowL, OUTPUT);
  pinMode(EnableR, OUTPUT);
  pinMode(HighR, OUTPUT);
  pinMode(LowR, OUTPUT);
  Serial.begin(9600);


}

void Forward(){


  digitalWrite(HighL, LOW );
  digitalWrite(LowL, HIGH);

  analogWrite(EnableL, 255);

  digitalWrite(HighR, HIGH );
  digitalWrite(LowR, LOW);

  analogWrite(EnableR, 255);

}

void Left1(){


  digitalWrite(HighL,LOW);
  digitalWrite(LowL,HIGH );

  analogWrite(EnableL, 255);

  digitalWrite(HighR, HIGH );
  digitalWrite(LowR, LOW);

  analogWrite(EnableR, 120);

}

void Rigth1(){


  digitalWrite(HighL, LOW );
  digitalWrite(LowL, HIGH);

  analogWrite(EnableL, 75);

  digitalWrite(HighR, HIGH );
  digitalWrite(LowR, LOW);

  analogWrite(EnableR, 255);

}

void Backward(){


  digitalWrite(HighL, HIGH );
  digitalWrite(LowL, LOW);

  analogWrite(EnableL, 255);

  digitalWrite(HighR, LOW );
  digitalWrite(LowR, HIGH);

  analogWrite(EnableR, 255);

}

void Stop(){


  digitalWrite(HighL, HIGH );
  digitalWrite(LowL, LOW);

  analogWrite(EnableL, 0);

  digitalWrite(HighR, LOW );
  digitalWrite(LowR, HIGH);

  analogWrite(EnableR, 0);

}
void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0){
    gelenVeri = Serial.read();


    if (gelenVeri=='f'){
      Forward();
    }
    else if(gelenVeri == 'b'){
      Backward();
    }
    else if(gelenVeri == 'l'){
      Left1();
    }
    else if(gelenVeri == 'r'){
      Rigth1();
    }
     else if(gelenVeri == 's'){
      Stop();
    }
  }

}
