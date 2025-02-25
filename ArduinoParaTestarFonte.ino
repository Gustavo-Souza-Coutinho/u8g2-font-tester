#include <Adafruit_ILI9341.h>
#include "U8g2_for_Adafruit_GFX.h"  // Inclui a biblioteca U8g2 para Adafruit GFX

// Definições dos pinos SPI
#define TFT_DC 7   // PA8
#define TFT_CS 4   // PB5
#define TFT_RST 2  // PA10

#define TFT_MOSI 11  // PA7
#define TFT_CLK 13   // PA5
#define TFT_MISO 12  // PA6

// Inicializa o display ILI9341
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// Inicializa a biblioteca U8g2 para Adafruit GFX
U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;

void setup() {
  // Inicializa o display
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);  // Limpa a tela com fundo preto

  // Inicializa a biblioteca U8g2
  u8g2_for_adafruit_gfx.begin(tft);

  // Configura a fonte de 7 segmentos
  u8g2_for_adafruit_gfx.setFont(u8g2_font_7Segments_26x42_mn);  // Usa a fonte de 7 segmentos
  u8g2_for_adafruit_gfx.setForegroundColor(ILI9341_WHITE);      // Define a cor do texto como branco
  u8g2_for_adafruit_gfx.setBackgroundColor(ILI9341_BLACK);      // Define a cor de fundo como preto

  // Escreve o texto na tela usando a fonte de 7 segmentos
  u8g2_for_adafruit_gfx.setCursor(20, 90);  // Define a posição do cursor
  u8g2_for_adafruit_gfx.print("0.1.2.3.4");  // Escreve números usando a fonte 

  u8g2_for_adafruit_gfx.setCursor(20, 150);  // Define a posição do cursor
  u8g2_for_adafruit_gfx.print("5,6,7,8,9");  // Escreve números usando a fonte 

  u8g2_for_adafruit_gfx.setCursor(20, 210);  // Define a posição do cursor
  u8g2_for_adafruit_gfx.print(". . . . . , , , ,");      
}

void loop() {
}