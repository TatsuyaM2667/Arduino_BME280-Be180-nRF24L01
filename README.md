# Arduino_BME280-Be180-nRF24L01
Arduino Unoを用いてBME280（温湿度気圧）とBE-180（GPS）のデータを収集し、nRF24L01を使用して遠距離に送信する。
受信機の例として[このリポジトリ](https://github.com/TatsuyaM2667/nRF24L01_Receiver-I2C)を参照。
各種配線は以下の通り

## BME280(I2C接続）                    

|Arduino UNO |  BME280     | 
|:-----------|------------:|           
| 3.3V       | VCC         |            
| GND        | GND         |                   
| A5         | SCL         |                            
| A4         | SDA         | 

## BE-180(UART通信）

|Arduino UNO |  BE-180     | 
|:-----------|------------:|
| 3.3V       | VCC         |
| GND        | GND         |
| D4         | TX          |
| D5         | RX          |            

## nRF24L01(SPI通信）

|Arduino UNO |  nRF24L01   | 
|:-----------|------------:|
| 3.3V※1    | VCC         |   
| GND        | GND         |
| D7         | CE          |
| D8         | CSN         |
| D13        | SCK         |
| D11        | MOSI        |  
| D12        | MISO        |      

※1 絶対に5V接続禁止
nRF24L01について、電源ノイズ対策用にnRF24L01のVCC-GND間へ10μF程度のコンデンサ推奨




