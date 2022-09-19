#include <stdio.h>
#include <stdint.h>
uint8_t PORTA = 0b00000000; 
// dung enum low = 0 , High = 1
enum {
    LOW,
    HIGH,
};
// DUNG KIEU enum de tao cac gia tri bit cho cac pin
enum {
    PIN0 = 0b00000001 << 0,
    PIN1 = 0b00000001 << 1,
    PIN2 = 0b00000001 << 2,
    PIN3 = 0b00000001 << 3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
};
// Viết 1 hàm set chân digitalWrite
void digitalWrite (PIN , set){
    if (set == 1) { // SET la high = 1 se dung enum
        PORTA |= PIN ; //set bit
    }
    if (set == 0 ){
        PORTA &= ~PIN;
    }
}
// Ham delay
void delay (){
    for (int i = 0; i<1000; i++){}
}
 // viet ham chop nhau led
void BlinkLed (PIN){
   for(int i=0;;i++){
   PORTA |= PIN ; // bật led pin thứ x
   delay();
   PORTA &= ~PIN; // tắt led pin thứ x
   delay();
   } 
}

// Gỉa sử bật Led 3 và chớp tắt led 5
int main (){
    digitalWrite (PIN3,HIGH); // BẬT LED 3
    digitalWrite (PIN3,LOW); // tắt led 3
    BlinkLed (PIN5); // CHỚP NHÁY LED 5;

}