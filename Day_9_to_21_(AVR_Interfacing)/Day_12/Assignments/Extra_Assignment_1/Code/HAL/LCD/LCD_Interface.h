#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInitDisplay(void);
void LCD_voidSendCMD(u8 copy_u8Command);
void LCD_voidClrDisplay(void);
void LCD_voidReturnHome(void);
void LCD_voidDisplayChar(u8 copy_u8Char);
void LCD_voidDisplayStr(u8 *copy_u8Str);
void LCD_voidSetCursorPosition(u8 copy_u8XPosition, u8 copy_u8YPosition);
void LCD_voidDisplayInt(u32 copy_u32Number);
void LCD_voidSendSpecChar(u8 copy_u8CharIndex, u8 *copy_u8SpecialChar);
void LCD_voidDisplaySpecChar(u8 copy_u8CharIndex);

#endif