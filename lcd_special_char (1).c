/*! \mainpage Week-4 Challenge Activity 1: Display custom characters on LCD
 *
 * @author     e-Yantra Team
 * @date       2020/04/01
 *
 * \subsection Aim
 * to display custom characters on LCD.
 *
 * \subsection Connections (Proteus Project)
 * LCD Connections:								<br>
 *		 LCD Pins	  Micro-controller Pins     <br>
 *			  RS  --> PB0						<br>
 *			  RW  --> PB2						<br>
 *			  EN  --> PB1						<br>
 *			  DB7 --> PD7						<br>
 *			  DB6 --> PD6						<br>
 *			  DB5 --> PD5						<br>
 *			  DB4 --> PD4						<br>
 *
 */

//---------------------------------- HEADER FILES -----------------------------------------------------

#include "firebird_simulation.h"		// Header file included that contains macro definitions essential for Firebird V robot and Simulation
#include <util/delay.h>					// Standard AVR Delay Library
#include "lcd.h"						// LCD Header file included that contains function definitions essential to deal with LCD

//------------------------------------ Global Variables ---------------------------------------------------

unsigned char pattern_e[8] = {
	0b00011111,						
	0b00010001,
	0b00010011,
	0b00010110,
	0b00011100,
	0b00010000,
	0b00011111,
	0b00000000
};

//------------------------------------ FUNCTIONS ---------------------------------------------------

/**
* @brief      Store the custom characters at CGRAM location.<br>
*		       
* @details    This function stores the 8 byte pattern at the CGRAM memort.<br>
*
* @param[in]  loc  			The address of CGRAM 1 - 7
* 			  *pattern 		Base address of array where the pattern is stored
*/

//<< NOTE >>: You should not change this function in order to get the required output
void lcd_custom_char (unsigned char loc, unsigned char *pattern)
{
	/*
	<< TODO >> :
		Command 0x40 and onwards to force the device to point CGRAM address
	    Write 8 byte for generation of the custom character 
	*/	
}


/**
* @brief      Display the logo "e" using custom character.<br>
*		       
* @details    This function displays the pattern "e".<br>
*
*/		
void Display_logo()
{
	lcd_string(1,3,"Display Logo");
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD
	/*
	<< TODO >> :
		displays the logo on LCD 
		Use the binary pattern stored in pattern_e array<br> 
*		and pass the base address of array to the lcd_custom_char function.
	*/
}

/**
* @brief      Display the sine wave.<br>
*		       
* @details    This function displays the sine wave on LCD.<br>
*
*/		
void Display_sine_wave()
{
	lcd_string(1,3,"Sine Wave");
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD

	/*
	<< TODO >> :
		displays the sine wave on LCD 
		Store the binary patterns for positive and negative cycle of sine wave in an array<br> 
*		and pass the base address of array to the lcd_custom_char function.
	*/
	
}


//---------------------------------- MAIN ----------------------------------------------------------------
/**
 * @brief      Main Function
 *
 * @details    First Initializes the LCD
 *			   and displays the different patterns on LCD on by one. 
 */
 int main(void)
{
	lcd_port_config();					// Initialize the LCD port
	lcd_init();							// Initialize the LCD
	lcd_clear();						// Clear the LCD
    
	Display_logo();
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD
	Display_sine_wave();
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD
	
    while (1);
}
