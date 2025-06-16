# Arduino_BME280-Be180-nRF24L01
Arduino Unoを用いてBME280（温湿度気圧）とBE-180（GPS）のデータを収集し、nRF24L01を使用して遠距離に送信する。
各種配線は以下の通り

## BME280(I2C接続）                    ## BE-180(UART通信）

|Arduino UNO |  BME280     |           |Arduino UNO |  BE-180     | 
|:-----------|------------:|           |:-----------|------------:|
| 3.3V       | VCC         |           | 3.3V       | VCC         | 
| GND        | GND         |           | GND        | GND         |        
| A5         | SCL         |           | D4         | TX          |                 
| A4         | SDA         |           | D5         | RX          |            



