#include <RTClib.h>
#include <SdFat.h>
#include <sdios.h>

#define SEGMENT_CS 6
#define SEGMENT_DIN 7
#define SEGMENT_CLK 8
#define SD_CS 10

//rest of the segment uses SPI
RTC_DS1307 rtc;
SdFat SD;


void send_seg(int address, int data);
void write_card(int reading, DateTime dt);
int DP = 0;
bool use_card = true;

File fileHandler;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //* ------------------------------------------------ RTC
  rtc.begin();
  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //do NOT call this in every sketch, otherwise you'll get a bit of groundhog day.
  }

  //* ------------------------------------------------ SD CARD
  if(!SD.begin(SD_CS)){
    Serial.println("SDCARD init failed");
    use_card = false;
  }
  //* ----------------------------------------------- 7 SEGMENTS
  pinMode(SEGMENT_CS,OUTPUT);
  pinMode(SEGMENT_DIN,OUTPUT);  
  pinMode(SEGMENT_CLK,OUTPUT);
  
  //init display module
  send_seg(0x09,0xff);  //decode mode - decode everything, 
  send_seg(0x0A,0x0f);  //intensity - fully bright
  send_seg(0x0B,7);     //scan limit - all digits
  send_seg(0x0C,1);     //shutdown - power on.
  send_seg(0x0F,0);     //test

  send_seg(8,12);  //H
  send_seg(7,11);  //E
  send_seg(6,13);  //L
  send_seg(5,14);  //P
  
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
   
  int reading = analogRead(A0);
  int minutes = now.minute();
  int hours = now.hour();  
  

   if(DP){
     DP = 0;
   } else { 
     DP = 128;
     //as we want to write to card every second, we can do so here.
     if(use_card) { write_card(reading,now); } 
   }

   
   //update screen
  send_seg(8, (reading/1000)%10 );
  send_seg(7, (reading/100)%10  );
  send_seg(6, (reading/10)%10 );
  send_seg(5, (reading%10)   );
  send_seg(4,(hours/10) | DP);
  send_seg(3,(hours%10) | DP);
  send_seg(2,(minutes/10)|DP);
  send_seg(1,(minutes%10)|DP);

  delay(500);
}
void send_seg(int address, int data) {
  
  digitalWrite(SEGMENT_CS,LOW);
  digitalWrite(SEGMENT_CLK,LOW);
  shiftOut(SEGMENT_DIN,SEGMENT_CLK, MSBFIRST, address);
  shiftOut(SEGMENT_DIN,SEGMENT_CLK, MSBFIRST, data);
  digitalWrite(SEGMENT_CS,HIGH);

}

void write_card(int reading, DateTime dt){
  ofstream logfile("UVMETER_data.txt", ios::out | ios::app);

  logfile << dt.year() << dt.month() << dt.day() 
  << " " << dt.hour() << ":" << dt.minute()<< ":" << dt.second() 
  << "," << reading << endl;
  
  if (!logfile){
    Serial.println("err writing log");
  } else { 
    Serial.println("log success!");
  }

  logfile.close();
}

