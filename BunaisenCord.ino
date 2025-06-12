#include <Wire.h>
#include <Adafruit_BME280.h>
#include <SPI.h>
#include <RF24.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

// BME280
Adafruit_BME280 bme;

// BE-180 (GPS)
SoftwareSerial gpsSerial(4, 5); // RX, TX
TinyGPSPlus gps;

// nRF24L01
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

struct SensorData {
  float temperature;
  float humidity;
  float pressure;
  float latitude;
  float longitude;
};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  bme.begin(0x77); // or 0x77
  
  gpsSerial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  // GPSデータ受信
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  SensorData data;
  data.temperature = bme.readTemperature();
  data.humidity = bme.readHumidity();
  data.pressure = bme.readPressure() / 100.0F;
  data.latitude = gps.location.isValid() ? gps.location.lat() : 0.0;
  data.longitude = gps.location.isValid() ? gps.location.lng() : 0.0;

  // データ送信
  radio.write(&data, sizeof(data));

  delay(2000); // 1秒ごと送信
}