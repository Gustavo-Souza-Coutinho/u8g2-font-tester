# U8g2 Font Tester para ILI9341

## Sobre o Projeto
Este projeto é um **teste modular de fontes** da biblioteca **U8g2** para displays TFT, utilizando um **display ILI9341** e a biblioteca **Adafruit GFX**. Ele permite visualizar diferentes fontes da U8g2, sendo altamente personalizável para atender diversas aplicações.

O código foi desenvolvido para a **placa STM32 Nucleo-64 F446RE**, mas pode ser facilmente adaptado para outros microcontroladores compatíveis.

## Tecnologias Utilizadas
- **Linguagem:** C++ (Arduino Framework)
- **Microcontrolador:** STM32 Nucleo-64 (F446RE)
- **Display:** ILI9341
- **Bibliotecas:**
  - `Adafruit_ILI9341` (para comunicação com o display)
  - `U8g2_for_Adafruit_GFX` (para renderização de fontes U8g2)

## Configuração de Hardware
As conexões entre o **STM32 Nucleo-64 F446RE** e o **display ILI9341** são as seguintes:

| Função | Pino no STM32  |
|--------|----------------|
| **TFT_DC**  | PA8  (7)  |
| **TFT_CS**  | PB5  (4)  |
| **TFT_RST** | PA10 (2)  |
| **TFT_MOSI**| PA7  (11) |
| **TFT_CLK** | PA5  (13) |
| **TFT_MISO**| PA6  (12) |

## Como Usar
### Instale as bibliotecas necessárias:
Certifique-se de ter as bibliotecas instaladas no seu ambiente Arduino:
- `Adafruit GFX Library`
- `Adafruit ILI9341`
- `U8g2 for Adafruit GFX`

### Faça o upload do código para a placa

### Personalize a fonte (Opcional)
O código é **modular**, permitindo a troca de fontes facilmente. Para usar outra fonte, altere a linha:

```cpp
u8g2_for_adafruit_gfx.setFont(u8g2_font_7Segments_26x42_mn);
```

Para qualquer outra fonte disponível na biblioteca **U8g2**. A lista completa de fontes pode ser encontrada [aqui](https://github.com/olikraus/u8g2/wiki/fntlistall).

## Código Fonte

```cpp
#include <Adafruit_ILI9341.h>
#include "U8g2_for_Adafruit_GFX.h"  // Biblioteca U8g2 para Adafruit GFX

// Definição dos pinos
#define TFT_DC 7   // PA8
#define TFT_CS 4   // PB5
#define TFT_RST 2  // PA10
#define TFT_MOSI 11  // PA7
#define TFT_CLK 13   // PA5
#define TFT_MISO 12  // PA6

// Inicialização do display
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;

void setup() {
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  u8g2_for_adafruit_gfx.begin(tft);
  u8g2_for_adafruit_gfx.setFont(u8g2_font_7Segments_26x42_mn);
  u8g2_for_adafruit_gfx.setForegroundColor(ILI9341_WHITE);
  u8g2_for_adafruit_gfx.setBackgroundColor(ILI9341_BLACK);

  u8g2_for_adafruit_gfx.setCursor(20, 90);
  u8g2_for_adafruit_gfx.print("0.1.2.3.4");
  u8g2_for_adafruit_gfx.setCursor(20, 150);
  u8g2_for_adafruit_gfx.print("5,6,7,8,9");
  u8g2_for_adafruit_gfx.setCursor(20, 210);
  u8g2_for_adafruit_gfx.print(". . . . . , , , ,");
}

void loop() {}
```

