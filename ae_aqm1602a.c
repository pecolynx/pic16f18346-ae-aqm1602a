#include <xc.h>
#include "common.h"
#include "i2c.h"
#include "ae_aqm1602a.h"

static void lcd_i2c_write(unsigned char cont, char data) {
    i2c_start();
    i2c_write_data(AE_AQM1602A_I2C_ADDRESS);
    i2c_write_data(cont);
    i2c_write_data(data);
    SSP1IF = 0;
    i2c_stop();
    __delay_us(50);
}

void lcd_i2c_init() {
    lcd_i2c_write(0x00, 0x38);
    __delay_ms(20);
    lcd_i2c_write(0x00, 0x39);
    __delay_ms(20);
    lcd_i2c_write(0x00, 0x14);
    __delay_ms(20);
    lcd_i2c_write(0x00, 0x73);
    __delay_ms(20);    
    lcd_i2c_write(0x00, 0x52);
    __delay_ms(20);
    lcd_i2c_write(0x00, 0x6C);
    __delay_ms(300);
    lcd_i2c_write(0x00, 0x38);
    __delay_ms(20);
    lcd_i2c_write(0x00, 0x01);
    __delay_ms(20);    
    lcd_i2c_write(0x00, 0x0C); // display:on, cursor:off, blink:off
//    lcd_i2c_write(0x00, 0x0E); // display:on, cursor:on, blink:off
//    lcd_i2c_write(0x00, 0x0F); // display:on, cursor:on, blink:on
    __delay_ms(20);       
}

void lcd_i2c_print_char(char ch) {
    lcd_i2c_write(0x40, ch);
    __delay_us(50);   
}

void lcd_i2c_print_str(const char * str) {
    while (*str) {
        lcd_i2c_print_char(*str++);
    }    
}

void lcd_i2c_set_cursor(char row, char col) {
    char pos = row * 0x40 + col;
    lcd_i2c_write(0x00, 0x80 | pos);
    __delay_us(50);   
}
