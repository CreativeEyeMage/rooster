#include "Narcoleptic.h"
#include "TimeLord.h"



int year;
int month;
int day;


TimeLord myLord;

long time_wake_up;
long time_done;
long sleep_time_msecs;


void setup()
{
  Serial.begin(9600);
  myLord.Position(47.6, -122.3);
  myLord.TimeZone(-8 * 60);
  myLord.DstRules(3,2,11,1, 60);
}



void get_date_tomorrow(byte today[]) {
  
  Serial.println("today: ");
  Serial.print(today[0]);
  Serial.print(" ");
  Serial.print(today[1]);
  Serial.print(" ");
  Serial.print(today[2]);
  Serial.print(" ");
  Serial.print(today[3]);
  Serial.print(" ");
  Serial.print(today[4]);
  Serial.print(" ");
  Serial.print(today[5]);
  Serial.println(" ");
  
  byte month_length = myLord.LengthOfMonth(today);
  if (today[3]<month_length) today[3]++;
  else if (today[4]==12) {
    today[3] = 1;
    today[4] = 1;
    today[5] ++;
  }
  else {
    today[3] = 1;
    today[4] ++;
  }
  
  Serial.println("tomorrow: ");
  Serial.print(today[0]);
  Serial.print(" ");
  Serial.print(today[1]);
  Serial.print(" ");
  Serial.print(today[2]);
  Serial.print(" ");
  Serial.print(today[3]);
  Serial.print(" ");
  Serial.print(today[4]);
  Serial.print(" ");
  Serial.print(today[5]);
  Serial.println(" ");
}
  

void loop()
{
  time_wake_up = millis();
  
  // take some pictures
  
  // done taking pictures
  
  // figure out when sunrise is tomorrow:
  
  year = 12;
  month = 7;
  day = 31;
  byte sunRise[]  = {0, 0, 0, day, month, year};
  myLord.SunRise(sunRise);
  
  get_date_tomorrow(sunRise);
  
  Serial.print(sunRise[0]);
  Serial.print(" ");
  Serial.print(sunRise[1]);
  Serial.print(" ");
  Serial.print(sunRise[2]);
  Serial.print(" ");
  Serial.print(sunRise[3]);
  Serial.print(" ");
  Serial.print(sunRise[4]);
  Serial.print(" ");
  Serial.print(sunRise[5]);
  Serial.println(" ");
  
  time_done = millis();
  
  // how many hours until next sunrise?
  
  sleep_time_msecs = 500;
  
  delay(1000);
  
  // Narcoleptic.delay(sleep_time_msecs);
}
