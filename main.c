#include <xc.h>
#include "common.h"
#include "i2c.h"
#include "ae_aqm1602a.h"

int main() {
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB6 = 1;
    RB5PPS = 0b11001; // RB5 source is SDO1/SDA1
    RB6PPS = 0b11000; // RB6 source is SCK1/SCL1
    ANSELB = 0x00;
    
    SSP1CLKPPS = 0b01110; // Peripheral input is RB6
    SSP1DATPPS = 0b01101; // Peripheral input is RB5
    
    SSP1CON1 = 0b00101000; // WCOL:0, SSPOV:0, SSPEN:1, CKP:0, SSPM<3:0>:1000
    SSP1CON2 = 0x00;
    SSP1CON3 = 0x00;
    SSP1STAT = 0b10000000;
    SSP1ADD = 0x27; // Baudrate: 200kHz(32MHz / (0x27+1) / 4)
//    SSP1ADD = 0x13; // Baudrate: 400kHz(32MHz / (0x13+1) / 4)
    SSP1DATPPS = 0b01100;
    
    lcd_i2c_init();
    lcd_i2c_print_str("Hello");
    
    __delay_ms(1000);
    
    lcd_i2c_set_cursor(1, 0); // row = 1, col = 0
    lcd_i2c_print_str("World");
    while(1) {
    }
        
    return 0;
}
