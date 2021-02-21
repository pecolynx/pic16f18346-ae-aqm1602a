#ifndef AE_AQM1602A_H_INCLUDED
#define	AE_AQM1602A_H_INCLUDED

#define AE_AQM1602A_I2C_ADDRESS 0x7C

#include <xc.h>

void lcd_i2c_init(void);
void lcd_i2c_print_char(char ch);
void lcd_i2c_print_str(const char * str);
void lcd_i2c_set_cursor(char row, char col);

#endif
