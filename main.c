/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18346
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    LATC = 0x00;
    unsigned int contador=0;   
    //char run=1;

    while (1)
    {    
    
        /*if (PORTAbits.RA2==1){
            __delay_ms(500);
            
            if (run>=0x80){
                run=1;                               
            }else{
                run *= 2;
            }
            LATC=run;
        }*/
        
    if ((PORTAbits.RA0 == 1)||(PORTAbits.RA1 == 1)){
        
        if (PORTAbits.RA0 == 1){
                
                __delay_ms(500);
                if(contador<8){contador++;}
                else           {contador=0;}
            }
        
        else if  (PORTAbits.RA1 == 1){   
                
                __delay_ms(500);
                if(contador>0){contador--;}
                else           {contador=8;}
            }
        
                   
        switch (contador){
            
                    case 0:
                    LATC = 0x00;              
                    break;

                    case 1:
                    LATC = 0x01;                
                    break;

                    case 2:
                    LATC = 0x02;        
                    break;

                    case 3:
                    LATC = 0x04;       
                    break;

                    case 4:
                    LATC = 0x08;            
                    break;  

                    case 5:
                    LATC = 0x10;  
                    break;

                    case 6:
                    LATC = 0x20;
                    break; 

                    case 7:
                    LATC = 0x40;
                    break;

                    case 8:
                    LATC = 0x80;         
                    break;          
             }
        }
    
    else{contador=contador;}
   
    } //del while(1)
}//del main
/**
 End of File
*/