
#include <WiFi.h>
#include <time.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1); 

const char* ssid = "RCCIIT";//Replace with your ssid name
const char* password = "RCCIIT24";//Replace with your ssid password 
 
int GMTOffset = 19800;  //Replace with your GMT Offset in seconds
int daylightOffset = 0;  // Replace with your daylight savings offset in seconds
 
void setup() { 
  Serial.begin(115200); 

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,28);
  display.println("Connecting...");
  display.display();
  display.clearDisplay();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("ssid:RCCIIT");
    display.setTextSize(2);
    display.setTextWrap(false);
    display.setCursor(0,25);
    display.println("password: ");
    display.setTextSize(2);
    display.setCursor(0,50);
    display.println("RCCIIT24");
    display.display();
    display.clearDisplay();
  }

  Serial.println("Connected to Wi-Fi!");


  configTime(GMTOffset, daylightOffset, "pool.ntp.org","time.nist.gov");
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.println("RCCIIT");
  display.setTextSize(2);
  display.setTextWrap(false);
  display.setCursor(0,45);
  display.println("DEPT OF ECE");
  display.display();
  delay(2000);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  display.setCursor(0,0);
  display.println("Ranajit Das");
  display.setCursor(2,45);
  display.println("ECE2020018");
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  // Display.setFont(&FreeSansBoldOblique12pt7b);
  display.setCursor(0,0);
  display.println("Dipankar");
  display.println("Roy");
  display.setCursor(2,45);
  display.println("ECE2020046");
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  display.setCursor(0,0);
  display.println("Suhana Das");
  display.setCursor(2,45);
  display.println("ECE2020021");
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  display.setCursor(25,0);
  display.println("GUIDE");
  display.setCursor(2,25);
  display.println("Sujoy");
  display.println("Mondal");
  display.display();
  delay(2000);
  
}

 
void loop() {
  time_t rawtime = time(nullptr);
  struct tm* timeinfo = localtime(&rawtime);

  Serial.print("Time:");
  Serial.print(timeinfo->tm_hour);
  Serial.print(":");
  Serial.print(timeinfo->tm_min);
  Serial.print(":");
  Serial.println(timeinfo->tm_sec);

  display.clearDisplay();
  display.setTextSize(3);
  display.setTextWrap(false);
  display.setTextColor(WHITE);
  display.setCursor(0,25);
  display.print(timeinfo->tm_hour);
  display.print(":");
  if( timeinfo->tm_min <10)
  display.print("0");
  display.print(timeinfo->tm_min);
 
  display.setTextSize(2);
  display.setCursor(90,30);
  display.print(":");
  if( timeinfo->tm_sec <10)
  display.print("0");
  display.print(timeinfo->tm_sec); 
  display.display();
 
  delay(1000);

 
}

