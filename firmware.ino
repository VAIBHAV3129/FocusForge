#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_VL53L0X.h>
#include <ESP32Encoder.h>


#define ENC_CLK 18
#define ENC_DT  19
#define ENC_SW  4
#define RGB_R   25
#define RGB_G   26
#define RGB_B   27
#define BUZZER  13
#define BUTTON  32
#define SDA_PIN 21
#define SCL_PIN 22


Adafruit_SSD1306 display(128, 64, &Wire, -1);
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
ESP32Encoder encoder;


enum State { IDLE, WORKING, BREAK, ALARM };
State deviceState = IDLE;

struct FocusMode {
  String name;
  int workMin;
  int breakMin;
  int r, g, b; 
};

FocusMode modes[] = {
  {"LIGHT", 25, 5, 0, 255, 150},  
  {"DEEP", 50, 10, 0, 100, 255},  
  {"HYPER", 90, 15, 255, 0, 255}  
};

int currentModeIdx = 0;
long timeLeftSeconds = 0;
long totalSessionSeconds = 0;
unsigned long lastTick = 0;
bool presenceDetected = true;

void setup() {
  Serial.begin(115200);


  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  
 
  Wire.begin(SDA_PIN, SCL_PIN);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) Serial.println("OLED Failed");
  if(!lox.begin()) Serial.println("ToF Failed");
  
  encoder.attachHalfQuad(ENC_CLK, ENC_DT);
  encoder.setCount(0);

  updateRGB(50, 50, 50); 
  showBootMessage();
}

void loop() {
  handleInputs();
  updateLogic();
  updateUI();
}


void handleInputs() {
  
  if (deviceState == IDLE) {
    long newCount = encoder.getCount() / 2; 
    if (newCount != currentModeIdx) {
      currentModeIdx = constrain(newCount, 0, 2);
      encoder.setCount(currentModeIdx * 2);
    }
  }

  
  if (digitalRead(BUTTON) == LOW || digitalRead(ENC_SW) == LOW) {
    delay(200); 
    if (deviceState == IDLE) {
      startSession();
    } else if (deviceState == ALARM || deviceState == BREAK) {
      resetToIdle();
    }
  }
}


void updateLogic() {
  if (deviceState == WORKING || deviceState == BREAK) {
    if (millis() - lastTick >= 1000) {
      lastTick = millis();
      if (timeLeftSeconds > 0) {
        timeLeftSeconds--;
        checkPresence();
      } else {
        triggerAlarm();
      }
    }
  }
}

void checkPresence() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  presenceDetected = (measure.RangeMilliMeter < 1000 && measure.RangeStatus != 4);
  
  if (!presenceDetected && deviceState == WORKING) {
   
    analogWrite(RGB_R, 255); 
  } else {
    updateRGB(modes[currentModeIdx].r, modes[currentModeIdx].g, modes[currentModeIdx].b);
  }
}


void updateUI() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  if (deviceState == IDLE) {
    display.setTextSize(1);
    display.setCursor(35, 0); display.print("SELECT MODE");
    display.setTextSize(2);
    display.setCursor(20, 25); display.print(modes[currentModeIdx].name);
    display.setTextSize(1);
    display.setCursor(25, 50); display.printf("%d min work", modes[currentModeIdx].workMin);
  } 
  else {
    display.setTextSize(1);
    display.setCursor(0, 0); 
    display.print(deviceState == WORKING ? "FOCUSING..." : "BREAK TIME");
    
    
    int m = timeLeftSeconds / 60;
    int s = timeLeftSeconds % 60;
    display.setTextSize(3);
    display.setCursor(20, 20);
    display.printf("%02d:%02d", m, s);
    
   
    int barWidth = map(timeLeftSeconds, 0, totalSessionSeconds, 0, 128);
    display.drawRect(0, 55, 128, 7, WHITE);
    display.fillRect(0, 55, 128 - barWidth, 7, WHITE);
  }
  
  display.display();
}

void startSession() {
  deviceState = WORKING;
  totalSessionSeconds = modes[currentModeIdx].workMin * 60;
  timeLeftSeconds = totalSessionSeconds;
  lastTick = millis();
}

void triggerAlarm() {
  deviceState = (deviceState == WORKING) ? ALARM : IDLE;
  for(int i=0; i<3; i++) {
    tone(BUZZER, 1000, 200);
    delay(300);
  }
}

void resetToIdle() {
  deviceState = IDLE;
  noTone(BUZZER);
}

void updateRGB(int r, int g, int b) {
  analogWrite(RGB_R, r);
  analogWrite(RGB_G, g);
  analogWrite(RGB_B, b);
}

void showBootMessage() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(30, 25);
  display.print("FOCUS FORGE");
  display.display();
  delay(1500);
}
