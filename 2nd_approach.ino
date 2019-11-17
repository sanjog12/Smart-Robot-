#include<SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int m1 = A3;
int m2 = A2;
int m3 = A1;
int m4 = A0;
int sl1 = 4;
int sr1 = 3;
int sb1 = 2;
int sf1 = 5;
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int randomtime[] = {100, 1000, 500, 500};
int randomtimed[] = {200, 400, 500, 700};
int rs[] = {100, 125, 150, 160};
int ns[] = {100, 125, 150}; int temp; int tempf;



void setup() {

  Serial.begin(115200);
  
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(sl1, INPUT);
  pinMode(sr1, INPUT);
  pinMode(sb1, INPUT);
  pinMode(sf1, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();

}


void loop() {
  Serial.println("Start Loop");
  face();
  Serial.println("End Loop");
}


int check() {
  
  int sf = digitalRead(sf1);
  int sb = digitalRead(sb1);
  int sl = digitalRead(sl1);
  int sr = digitalRead(sr1);
  Serial.println(sf);
                                                                                        //    sf   sb   sl   sr
  if (sf == 0 && sb == 0 && sl == 0 && sr == 0)                                         //1 = 0    0    0    0      no object
    return 1;                                                                           //2 = 1    0    0    0      object in front
                                                                                        //3 = 0    1    0    0      object at back
  else if (sf == 1 && sb == 0 && sl == 0 && sr == 0)                                    //4 = 0    0    1    0      object at left
    return 2;                                                                           //5 = 0    0    0    1      object at right
                                                                                        //6 = 1    1    0    0      object at front and back
  else if (sf == 0 && sb == 1 && sl == 0 && sr == 0)                                    //7 = 0    0    1    1      object at left and right
    return 3;                                                                           //8 = 1    1    1    1      blocked

  else if (sf == 0 && sb == 0 && sl == 1 && sr == 0)
    return 4;

  else if (sf == 0 && sb == 0 && sl == 0 && sr == 1)
    return 5;

  else if (sf == 1 && sb == 1 && sl == 0 && sr == 0)
    return 6;

  else if (sf == 0 && sb == 0 && sl == 1 && sr == 1)
    return 7;

  else if (sf == 1 && sb == 1 && sl == 1 && sr == 1)
    return 8;
}



int face() {
  Serial.println("Start face");
  int t1 = check();

  if (t1 == 1) {
    tempf=1;
    blinkeye();
    int t2 = random(1, 7);

    switch (t2) {
      case 1:
      case 3:
      case 5:{   
        movement(0, 150, 0, 150);
      }

      case 4:{
        
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(44, 12, 10, WHITE);
        display.fillCircle(44, 12, 10, WHITE);
        display.drawCircle(104, 12, 10, WHITE);
        display.fillCircle(104, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        movement(0,150,150,0);
        delay(200);
        display.clearDisplay();

        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(28, 12, 10, WHITE);
        display.fillCircle(28, 12, 10, WHITE);
        display.drawCircle(88, 12, 10, WHITE);
        display.fillCircle(88, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        movement(150,0,0,150);
        delay(200);
        display.clearDisplay();

        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(36, 12, 10, WHITE);
        display.fillCircle(36, 12, 10, WHITE);
        display.drawCircle(96, 12, 10, WHITE);
        display.fillCircle(96, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        movement(0,150,0,150);
        delay(200);
        display.clearDisplay();
        break;        
        }

       case 2:{
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(36, 12, 10, WHITE);
        display.fillCircle(36, 12, 10, WHITE);
        display.drawCircle(96, 12, 10, WHITE);
        display.fillCircle(96, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();

        temp=random(2,5);
        int i=0;
        while(i<temp){
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(44, 12, 10, WHITE);
        display.fillCircle(44, 12, 10, WHITE);
        display.drawCircle(104, 12, 10, WHITE);
        display.fillCircle(104, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();

        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(36, 4, 10, WHITE);
        display.fillCircle(36, 4, 10, WHITE);
        display.drawCircle(96, 4, 10, WHITE);
        display.fillCircle(96, 4, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();

        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(28, 12, 10, WHITE);
        display.fillCircle(28, 12, 10, WHITE);
        display.drawCircle(88, 12, 10, WHITE);
        display.fillCircle(88, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();

        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(36, 20, 10, WHITE);
        display.fillCircle(36, 20, 10, WHITE);
        display.drawCircle(96, 20, 10, WHITE);
        display.fillCircle(96, 20, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        i++;
        }
       }

       case 6:{
        temp=random(3,9);
        int i=0 ;
        int t[]={500,1000,750,1500,2000}
        while(i<temp){
          movement (0,150,0,0);
          delay(500);
          movement(0,0,0,150);
          delay(500);
        }
        movement(255,0,175,0);
        delay(t[random(0,5)]);

        temp=random(3,9); i=0;
        while(i<temp){
          movement (0,0,150,0);
          delay(500);
          movement(150,0,0,0);
          delay(500);
        }
       } 
     }
  }

  else if (t1 == 2) {
    tempf=2;
    int tarr[] = {500, 700, 900, 1000};

    movement(0, 0, 0, 0);
    display.drawCircle(36, 12, 18, WHITE);
    display.drawCircle(96, 12, 18, WHITE);
    display.drawLine(64,38,64,30,WHITE);
    display.drawLine(65,38,65,30,WHITE);
    display.drawLine(63,38,63,30,WHITE);
    display.drawLine(56, 52, 72, 52, WHITE);
    display.drawLine(52, 48, 56, 52, WHITE);
    display.drawLine(76, 48, 72, 52, WHITE);
    display.drawCircle(36, 12, 10, WHITE);
    display.fillCircle(36, 12, 10, WHITE);
    display.drawCircle(96, 12, 10, WHITE);
    display.fillCircle(96, 12, 10, WHITE);
    display.display();
    delay(tarr[random(0, 4)]);
    display.clearDisplay();

    display.drawCircle(36, 12, 18, WHITE);
    display.drawCircle(96, 12, 18, WHITE);
    display.drawLine(64,38,64,30,WHITE);
    display.drawLine(65,38,65,30,WHITE);
    display.drawLine(63,38,63,30,WHITE);    
    display.drawLine(56, 52, 72, 52, WHITE);
    display.drawLine(52, 48, 56, 52, WHITE);
    display.drawLine(76, 48, 72, 52, WHITE);
    display.drawCircle(36, 6, 10, WHITE);
    display.fillCircle(36, 6, 10, WHITE);
    display.drawCircle(96, 6, 10, WHITE);
    display.fillCircle(96, 6, 10, WHITE);
    display.display();
    delay(tarr[random(0, 4)]);
    display.clearDisplay();

    display.drawCircle(36, 12, 18, WHITE);
    display.drawCircle(96, 12, 18, WHITE);
    display.drawLine(64,38,64,30,WHITE);
    display.drawLine(65,38,65,30,WHITE);
    display.drawLine(63,38,63,30,WHITE);    
    display.drawLine(56, 52, 72, 52, WHITE);
    display.drawLine(52, 48, 56, 52, WHITE);
    display.drawLine(76, 48, 72, 52, WHITE);
    display.drawCircle(36, 18, 10, WHITE);
    display.fillCircle(36, 18, 10, WHITE);
    display.drawCircle(96, 18, 10, WHITE);
    display.fillCircle(96, 18, 10, WHITE);
    display.display();
    delay(tarr[random(0, 4)]);
    display.clearDisplay();
    
    movement(150,0,150,0);
    delay(750);
    temp=check();
    while(temp != 3){
      movement(150,0,0,150);
      temp=check();
    }
  }

  else if (t1 == 3) {
    tempf=3; 
    movement(0, 150, 0, 150);
    delay(50);
  }

  else if (t1 == 4) {
    tempf=4;
    int tarr[] = {500, 700, 900, 1000};
    display.drawCircle(50, 12, 12, WHITE);
    display.drawCircle(106, 12, 12, WHITE);
    display.drawLine(64,38,64,30,WHITE);
    display.drawLine(65,38,65,30,WHITE);
    display.drawLine(63,38,63,30,WHITE);    
    display.drawLine(56, 52, 72, 52, WHITE);
    display.drawLine(76,48,52,48,WHITE);
//  display.drawLine(56, 52, 74, 48,WHITE);
    display.drawLine(52, 48, 56, 52, WHITE);
    display.drawLine(74, 48, 72, 52, WHITE);
    display.drawCircle(56, 10, 6, WHITE);
    display.fillCircle(56, 10, 6, WHITE);
    display.drawCircle(112, 10, 6, WHITE);
    display.fillCircle(112, 10, 6, WHITE);
    display.display();
    delay(tarr[random(0, 4)]);
    display.clearDisplay();    
    movement(0, 150, 150, 0);
    delay(50);
  }

  else if (t1 == 5) {
    tempf=5;
    int tarr[] = {500, 700, 900, 1000};
    display.drawCircle(22, 12, 12, WHITE);
    display.drawCircle(78, 12, 12, WHITE);
    display.drawLine(64, 38, 64, 30, WHITE);
    display.drawLine(65, 38, 65, 30, WHITE);
    display.drawLine(63, 38, 63, 30, WHITE);
    display.drawLine(56, 52, 72, 52, WHITE);
    display.drawLine(52, 48, 54, 52, WHITE);
    display.drawLine(76, 48, 52 ,48, WHITE);
//  display.drawLine(52, 48, 72, 52, WHITE);
    display.drawLine(76, 48, 72, 52, WHITE);
    display.drawCircle(16, 10, 6, WHITE);
    display.fillCircle(16, 10, 6, WHITE);
    display.drawCircle(72, 10, 6, WHITE);
    display.fillCircle(72, 10, 6, WHITE);
    display.display();
    delay(tarr[random(0, 4)]);
    display.clearDisplay();      
    movement(150, 0, 0, 150);
    delay(50);
  }

  else if (t1 == 6) {
    tempf=6;
    movement(150, 0, 0, 150);
    delay(50);
  }

  else if (t1 == 7) {
    temp=7;
    movement(0, 175, 0, 175);
  }

  else if(t1==8){
    tempf=8;
    confused();
  }

  Serial.println("End face");
}



int movement(int s1, int s2, int s3, int s4) {
  analogWrite(m1, s1);
  analogWrite(m2, s2);
  analogWrite(m3, s3);
  analogWrite(m4, s4);
}



int blinkeye() {

  Serial.println("Start blink");
  display.clearDisplay();
  display.drawCircle(36, 12, 18, WHITE);
  display.drawCircle(96, 12, 18, WHITE);
    display.drawLine(64,38,64,30,WHITE);
    display.drawLine(65,38,65,30,WHITE);
    display.drawLine(63,38,63,30,WHITE);  
  display.drawLine(56, 52, 72, 52, WHITE);
  display.drawLine(52, 48, 56, 52, WHITE);
  display.drawLine(76, 48, 72, 52, WHITE);
  display.drawCircle(36, 12, 10, WHITE);
  display.fillCircle(36, 12, 10, WHITE);
  display.drawCircle(96, 12, 10, WHITE);
  display.fillCircle(96, 12, 10, WHITE);
  display.display();
  delay(randomtime[random(0, 6)]);
  display.clearDisplay();
  temp=check();
  if(temp!=tempf)
    return;


  display.drawLine(26, 12, 46, 12, WHITE);
  display.drawLine(82, 12, 102, 12, WHITE);
  display.display();
  display.clearDisplay();
  delay(50);
  temp=check();
  if(temp!=tempf)
    return;

  int r = random(1, 15);
  if (r == 5)
    look();
    
  Serial.println("Stop blink");
  return;

}


int look() {
  Serial.println("Start look");
  switch (random(1, 11)) {

    case 1: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);    
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(36, 12, 10, WHITE);
        display.fillCircle(36, 12, 10, WHITE);
        display.drawCircle(96, 12, 10, WHITE);
        display.fillCircle(96, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }

    case 2: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);        
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(40, 12, 10, WHITE);
        display.fillCircle(40, 12, 10, WHITE);
        display.drawCircle(110, 12, 10, WHITE);
        display.fillCircle(110, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }

    case 3: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);        
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(32, 12, 10, WHITE);
        display.fillCircle(32, 12, 10, WHITE);
        display.drawCircle(92, 12, 10, WHITE);
        display.fillCircle(92, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }

    case 4: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(36, 16, 10, WHITE);
        display.fillCircle(36, 16, 10, WHITE);
        display.drawCircle(96, 16, 10, WHITE);
        display.fillCircle(96, 16, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }

    case 5: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(36, 8, 10, WHITE);
        display.fillCircle(36, 8, 10, WHITE);
        display.drawCircle(96, 8, 10, WHITE);
        display.fillCircle(96, 8, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }
      break;
    case 10: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(36, 12, 10, WHITE);
        display.fillCircle(36, 12, 10, WHITE);
        display.drawCircle(96, 12, 10, WHITE);
        display.fillCircle(96, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }

    case 8: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(32, 8, 10, WHITE);
        display.fillCircle(32, 8, 10, WHITE);
        display.drawCircle(92, 8, 10, WHITE);
        display.fillCircle(92, 8, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }

    case 9: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);        
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(40, 12, 10, WHITE);
        display.fillCircle(40, 12, 10, WHITE);
        display.drawCircle(96, 12, 10, WHITE);
        display.fillCircle(96, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }

    case 6: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);     
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(32, 12, 10, WHITE);
        display.fillCircle(32, 12, 10, WHITE);
        display.drawCircle(88, 12, 10, WHITE);
        display.fillCircle(88, 12, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }

    case 7: {
        display.drawCircle(36, 12, 18, WHITE);
        display.drawCircle(96, 12, 18, WHITE);
        display.drawLine(64,38,64,30,WHITE);
        display.drawLine(65,38,65,30,WHITE);
        display.drawLine(63,38,63,30,WHITE);
        display.drawLine(56, 52, 72, 52, WHITE);
        display.drawLine(52, 48, 56, 52, WHITE);
        display.drawLine(76, 48, 72, 52, WHITE);
        display.drawCircle(32, 16, 10, WHITE);
        display.fillCircle(32, 16, 10, WHITE);
        display.drawCircle(88, 16, 10, WHITE);
        display.fillCircle(88, 16, 10, WHITE);
        display.display();
        delay(randomtimed[random(0, 4)]);
        display.clearDisplay();
        temp=check();
        if(temp!=tempf)
          return;
      }
  }
  Serial.println("End Look");
  return;
}


int confused() {

  Serial.println("Strat confused");
  int s = random(1, 4);

  if (s == 2) {
    display.drawCircle(36, 12, 18, WHITE);
    display.drawCircle(96, 12, 18, WHITE);
    display.drawLine(64,38,64,30,WHITE);
    display.drawLine(65,38,65,30,WHITE);
    display.drawLine(63,38,63,30,WHITE);    
    display.drawLine(56, 52, 72, 52, WHITE);
    display.drawLine(52, 48, 56, 52, WHITE);
    display.drawLine(76, 48, 72, 52, WHITE);
    display.drawCircle(36, 12, 10, WHITE);
    display.fillCircle(36, 12, 10, WHITE);
    display.drawCircle(96, 12, 10, WHITE);
    display.fillCircle(96, 12, 10, WHITE);
    display.display();
    delay(randomtimed[random(0, 7)]);
    display.clearDisplay();
    temp=check();
    if(temp!=tempf)
      return;

    display.drawLine(56, 48, 72, 48, WHITE);
    display.drawLine(52, 44, 56, 48, WHITE);
    display.drawLine(76, 44, 72, 48, WHITE);
    display.drawLine(41, 7, 31, 17, WHITE);
    display.drawLine(41, 17, 31, 7, WHITE);
    display.drawLine(101, 7, 91, 17, WHITE);
    display.drawLine(101, 17, 91, 7, WHITE);
    display.display();
    delay(500);
    display.clearDisplay();
    temp=check();
    if(temp!=tempf)
      return;


    display.drawLine(56, 48, 72, 48, WHITE);
    display.drawLine(52, 44, 56, 48, WHITE);
    display.drawLine(76, 44, 72, 48, WHITE);
    display.drawRect(32, 7, 13, 13, WHITE);
    display.drawRect(88, 7, 13, 13, WHITE);
    display.display();
    delay(500);
    display.clearDisplay();
    temp=check();
    if(temp!=tempf)
      return;


    display.drawLine(56, 48, 72, 48, WHITE);
    display.drawLine(52, 44, 56, 48, WHITE);
    display.drawLine(76, 44, 72, 48, WHITE);
    display.drawTriangle(36, 7, 30, 18, 42, 18, WHITE);
    display.drawTriangle(92, 7, 88, 18, 98, 18, WHITE);
    display.display();
    delay(500);
    display.clearDisplay();
    temp=check();
    if(temp!=tempf)
      return;
  }

  else {
    display.drawLine(56, 48, 72, 48, WHITE);
    display.drawLine(52, 44, 56, 48, WHITE);
    display.drawLine(76, 44, 72, 48, WHITE);
    display.drawLine(41, 7, 31, 17, WHITE);
    display.drawLine(41, 17, 31, 7, WHITE);
    display.drawLine(101, 7, 91, 17, WHITE);
    display.drawLine(101, 17, 91, 7, WHITE);
    display.display();
    delay(500);
    display.clearDisplay();
    temp=check();
    if(temp!=tempf)
      return;
  }

  Serial.println("End Confused");
  return;
}
