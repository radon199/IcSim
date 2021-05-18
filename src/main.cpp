#include "chips/constant_value.h"
#include "chips/clock.h"
#include "chips/SN74LS00.h"
#include "chips/SN74LS04.h"
#include "chips/SN74LS08.h"
#include "chips/SN74LS20.h"
#include "chips/SN74LS30.h"
#include "chips/SN74HC42.h"
#include "chips/SN74LS161A.h"
#include "chips/SN74HC163N.h"
#include "chips/SN74HC245.h"
#include "chips/SN74HC373.h"
#include "chips/IDT71256SA.h"

#include <iostream>
#include <cstdio>
#include <bitset>
#include <string>

using namespace IcSim;

void preset_memory(IDT71256SA* memory)
{
    unsigned int count = 0;
    // Solid Black 0
    memory->write_data(count,   0b00000000);
    memory->write_data(count+1, 0b00000000);
    memory->write_data(count+2, 0b00000000);
    memory->write_data(count+3, 0b00000000);
    memory->write_data(count+4, 0b00000000);
    memory->write_data(count+5, 0b00000000);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    memory->write_data(count,   0b00000000);
    memory->write_data(count+1, 0b00000000);
    memory->write_data(count+2, 0b00000000);
    memory->write_data(count+3, 0b00000000);
    memory->write_data(count+4, 0b00000000);
    memory->write_data(count+5, 0b00000000);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    // Solid White 1
    memory->write_data(count,   0b11111111);
    memory->write_data(count+1, 0b11111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b11111111);
    memory->write_data(count+4, 0b11111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    memory->write_data(count,   0b11111111);
    memory->write_data(count+1, 0b11111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b11111111);
    memory->write_data(count+4, 0b11111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    // Brick Block Top 2
    memory->write_data(count+0, 0b11111111);
    memory->write_data(count+1, 0b00000001);
    memory->write_data(count+2, 0b00000001);
    memory->write_data(count+3, 0b11111111);
    memory->write_data(count+4, 0b00010000);
    memory->write_data(count+5, 0b00010000);
    memory->write_data(count+6, 0b00010000);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    memory->write_data(count+0, 0b00000000);
    memory->write_data(count+1, 0b11111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b11111111);
    memory->write_data(count+4, 0b11111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    // Brick Block Bottom 3
    memory->write_data(count+0, 0b00000001);
    memory->write_data(count+1, 0b00000001);
    memory->write_data(count+2, 0b00000001);
    memory->write_data(count+3, 0b11111111);
    memory->write_data(count+4, 0b00010000);
    memory->write_data(count+5, 0b00010000);
    memory->write_data(count+6, 0b00010000);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    memory->write_data(count+0, 0b11111111);
    memory->write_data(count+1, 0b11111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b11111111);
    memory->write_data(count+4, 0b11111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    // Ground Upper Left 4
    memory->write_data(count+0, 0b01111111);
    memory->write_data(count+1, 0b10000000);
    memory->write_data(count+2, 0b10000000);
    memory->write_data(count+3, 0b10000000);
    memory->write_data(count+4, 0b10000000);
    memory->write_data(count+5, 0b10000000);
    memory->write_data(count+6, 0b10000000);
    memory->write_data(count+7, 0b10000000);
    count += 8;

    memory->write_data(count+0, 0b10000000);
    memory->write_data(count+1, 0b01111111);
    memory->write_data(count+2, 0b01111111);
    memory->write_data(count+3, 0b01111111);
    memory->write_data(count+4, 0b01111111);
    memory->write_data(count+5, 0b01111111);
    memory->write_data(count+6, 0b01111111);
    memory->write_data(count+7, 0b01111111);
    count += 8;

    // Ground upper right 5
    memory->write_data(count+0, 0b11011110);
    memory->write_data(count+1, 0b01100001);
    memory->write_data(count+2, 0b01100001);
    memory->write_data(count+3, 0b01100001);
    memory->write_data(count+4, 0b01110001);
    memory->write_data(count+5, 0b01011110);
    memory->write_data(count+6, 0b01111111);
    memory->write_data(count+7, 0b01100001);
    count += 8;

    memory->write_data(count+0, 0b01100001);
    memory->write_data(count+1, 0b11011111);
    memory->write_data(count+2, 0b11011111);
    memory->write_data(count+3, 0b11011111);
    memory->write_data(count+4, 0b11011111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11000001);
    memory->write_data(count+7, 0b11011111);
    count += 8;

    // Ground Lower Left 6
    memory->write_data(count+0, 0b10000000);
    memory->write_data(count+1, 0b10000000);
    memory->write_data(count+2, 0b11000000);
    memory->write_data(count+3, 0b11110000);
    memory->write_data(count+4, 0b10111111);
    memory->write_data(count+5, 0b10001111);
    memory->write_data(count+6, 0b10000001);
    memory->write_data(count+7, 0b01111110);
    count += 8;

    memory->write_data(count+0, 0b01111111);
    memory->write_data(count+1, 0b01111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b00111111);
    memory->write_data(count+4, 0b01001111);
    memory->write_data(count+5, 0b01110001);
    memory->write_data(count+6, 0b01111111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    // Ground Lower Right 7
    memory->write_data(count+0, 0b01100001);
    memory->write_data(count+1, 0b01100001);
    memory->write_data(count+2, 0b11000001);
    memory->write_data(count+3, 0b11000001);
    memory->write_data(count+4, 0b10000001);
    memory->write_data(count+5, 0b10000001);
    memory->write_data(count+6, 0b10000011);
    memory->write_data(count+7, 0b11111110);
    count += 8;

    memory->write_data(count+0, 0b11011111);
    memory->write_data(count+1, 0b11011111);
    memory->write_data(count+2, 0b10111111);
    memory->write_data(count+3, 0b10111111);
    memory->write_data(count+4, 0b01111111);
    memory->write_data(count+5, 0b01111111);
    memory->write_data(count+6, 0b01111111);
    memory->write_data(count+7, 0b01111111);
    count += 8;

    // Mario Upper Left 8
    memory->write_data(count,   0b00000111);
    memory->write_data(count+1, 0b00001111);
    memory->write_data(count+2, 0b00001110);
    memory->write_data(count+3, 0b00010100);
    memory->write_data(count+4, 0b00010110);
    memory->write_data(count+5, 0b00011000);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00111111);
    count += 8;

    memory->write_data(count,   0b00000000);
    memory->write_data(count+1, 0b00000000);
    memory->write_data(count+2, 0b00001111);
    memory->write_data(count+3, 0b00011111);
    memory->write_data(count+4, 0b00011111);
    memory->write_data(count+5, 0b00011111);
    memory->write_data(count+6, 0b00000111);
    memory->write_data(count+7, 0b00111100);
    count += 8;

    // Mario Upper Right 9
    memory->write_data(count,   0b11000000);
    memory->write_data(count+1, 0b11111000);
    memory->write_data(count+2, 0b01000000);
    memory->write_data(count+3, 0b01000000);
    memory->write_data(count+4, 0b00100000);
    memory->write_data(count+5, 0b01111000);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b11000000);
    count += 8;

    memory->write_data(count,   0b00000000);
    memory->write_data(count+1, 0b00000000);
    memory->write_data(count+2, 0b11100000);
    memory->write_data(count+3, 0b11111000);
    memory->write_data(count+4, 0b11111100);
    memory->write_data(count+5, 0b11111000);
    memory->write_data(count+6, 0b11110000);
    memory->write_data(count+7, 0b11000000);
    count += 8;

    // Mario Lower Left 10
    memory->write_data(count,   0b00111111);
    memory->write_data(count+1, 0b00001110);
    memory->write_data(count+2, 0b00001111);
    memory->write_data(count+3, 0b00011111);
    memory->write_data(count+4, 0b00111111);
    memory->write_data(count+5, 0b01111100);
    memory->write_data(count+6, 0b01110000);
    memory->write_data(count+7, 0b00111000);
    count += 8;

    memory->write_data(count,   0b11111100);
    memory->write_data(count+1, 0b11101101);
    memory->write_data(count+2, 0b11000000);
    memory->write_data(count+3, 0b00000000);
    memory->write_data(count+4, 0b00000000);
    memory->write_data(count+5, 0b01100000);
    memory->write_data(count+6, 0b01110000);
    memory->write_data(count+7, 0b00111000);
    count += 8;

    // Mario Lower Right 11
    memory->write_data(count,   0b11110000);
    memory->write_data(count+1, 0b11111000);
    memory->write_data(count+2, 0b11100100);
    memory->write_data(count+3, 0b11111100);
    memory->write_data(count+4, 0b11111100);
    memory->write_data(count+5, 0b01111100);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    memory->write_data(count,   0b01111110);
    memory->write_data(count+1, 0b00011110);
    memory->write_data(count+2, 0b00000100);
    memory->write_data(count+3, 0b00001100);
    memory->write_data(count+4, 0b00001100);
    memory->write_data(count+5, 0b00001100);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    // Mario Jump Upper Left 12
    memory->write_data(count+0, 0b00000000);
    memory->write_data(count+1, 0b00000011);
    memory->write_data(count+2, 0b00000111);
    memory->write_data(count+3, 0b00000111);
    memory->write_data(count+4, 0b00001010);
    memory->write_data(count+5, 0b00001011);
    memory->write_data(count+6, 0b00001100);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    memory->write_data(count+0, 0b00000000);
    memory->write_data(count+1, 0b00000000);
    memory->write_data(count+2, 0b00000000);
    memory->write_data(count+3, 0b00000111);
    memory->write_data(count+4, 0b00001111);
    memory->write_data(count+5, 0b00001111);
    memory->write_data(count+6, 0b00001111);
    memory->write_data(count+7, 0b00000011);
    count += 8;

    // Mario Jump Upper Right 13
    memory->write_data(count+0, 0b00000000);
    memory->write_data(count+1, 0b11100000);
    memory->write_data(count+2, 0b11111100);
    memory->write_data(count+3, 0b00100111);
    memory->write_data(count+4, 0b00100111);
    memory->write_data(count+5, 0b00010001);
    memory->write_data(count+6, 0b00111110);
    memory->write_data(count+7, 0b00000100);
    count += 8;

    memory->write_data(count+0, 0b00000111);
    memory->write_data(count+1, 0b00000111);
    memory->write_data(count+2, 0b00000011);
    memory->write_data(count+3, 0b11110111);
    memory->write_data(count+4, 0b11111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111110);
    memory->write_data(count+7, 0b11111100);
    count += 8;

    // Mario Jump Lower Left 14
    memory->write_data(count+0, 0b00111111);
    memory->write_data(count+1, 0b01111111);
    memory->write_data(count+2, 0b00111111);
    memory->write_data(count+3, 0b00001111);
    memory->write_data(count+4, 0b00011111);
    memory->write_data(count+5, 0b00111111);
    memory->write_data(count+6, 0b01111111);
    memory->write_data(count+7, 0b01001111);
    count += 8;

    memory->write_data(count+0, 0b00111110);
    memory->write_data(count+1, 0b01111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b11100010);
    memory->write_data(count+4, 0b01010000);
    memory->write_data(count+5, 0b00111000);
    memory->write_data(count+6, 0b01110000);
    memory->write_data(count+7, 0b01000000);
    count += 8;

    // Mario Jump Lower Right 15
    memory->write_data(count+0, 0b11111000);
    memory->write_data(count+1, 0b11111001);
    memory->write_data(count+2, 0b11111001);
    memory->write_data(count+3, 0b10110111);
    memory->write_data(count+4, 0b11111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11100000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    memory->write_data(count+0, 0b11101000);
    memory->write_data(count+1, 0b01110001);
    memory->write_data(count+2, 0b00000001);
    memory->write_data(count+3, 0b01001011);
    memory->write_data(count+4, 0b00000011);
    memory->write_data(count+5, 0b00000011);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00000000);
    count += 8;


    // Question Block UL 16
    memory->write_data(count+0, 0b00000000);
    memory->write_data(count+1, 0b01111111);
    memory->write_data(count+2, 0b01111111);
    memory->write_data(count+3, 0b01111000);
    memory->write_data(count+4, 0b01110011);
    memory->write_data(count+5, 0b01110011);
    memory->write_data(count+6, 0b01110011);
    memory->write_data(count+7, 0b01111111);
    count += 8;

    memory->write_data(count+0, 0b01111111);
    memory->write_data(count+1, 0b10000000);
    memory->write_data(count+2, 0b10100000);
    memory->write_data(count+3, 0b10000111);
    memory->write_data(count+4, 0b10001111);
    memory->write_data(count+5, 0b10001110);
    memory->write_data(count+6, 0b10001110);
    memory->write_data(count+7, 0b10000110);
    count += 8;

    // Question Block UR 17
    memory->write_data(count+0, 0b00000000);
    memory->write_data(count+1, 0b11111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b00111111);
    memory->write_data(count+4, 0b10011111);
    memory->write_data(count+5, 0b10011111);
    memory->write_data(count+6, 0b10011111);
    memory->write_data(count+7, 0b00011111);
    count += 8;

    memory->write_data(count+0, 0b11111110);
    memory->write_data(count+1, 0b00000001);
    memory->write_data(count+2, 0b00000101);
    memory->write_data(count+3, 0b11000001);
    memory->write_data(count+4, 0b11100001);
    memory->write_data(count+5, 0b01110001);
    memory->write_data(count+6, 0b01110001);
    memory->write_data(count+7, 0b11110001);
    count += 8;

    // Question Block LL 18
    memory->write_data(count+0, 0b01111110);
    memory->write_data(count+1, 0b01111110);
    memory->write_data(count+2, 0b01111111);
    memory->write_data(count+3, 0b01111110);
    memory->write_data(count+4, 0b01111110);
    memory->write_data(count+5, 0b01111111);
    memory->write_data(count+6, 0b01111111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    memory->write_data(count+0, 0b10000001);
    memory->write_data(count+1, 0b10000001);
    memory->write_data(count+2, 0b10000000);
    memory->write_data(count+3, 0b10000001);
    memory->write_data(count+4, 0b10000001);
    memory->write_data(count+5, 0b10100000);
    memory->write_data(count+6, 0b10000000);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    // Question Block LR 19
    memory->write_data(count+0, 0b01111111);
    memory->write_data(count+1, 0b01111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b01111111);
    memory->write_data(count+4, 0b01111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    memory->write_data(count+0, 0b11110001);
    memory->write_data(count+1, 0b11000001);
    memory->write_data(count+2, 0b11000001);
    memory->write_data(count+3, 0b10000001);
    memory->write_data(count+4, 0b11000001);
    memory->write_data(count+5, 0b11000101);
    memory->write_data(count+6, 0b00000001);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    // Cloud Bush LL 20
    memory->write_data(count+0, 0b00000111);
    memory->write_data(count+1, 0b00001111);
    memory->write_data(count+2, 0b00011111);
    memory->write_data(count+3, 0b00011111);
    memory->write_data(count+4, 0b01111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b01111111);
    count += 8;

    memory->write_data(count+0, 0b00000111);
    memory->write_data(count+1, 0b00001000);
    memory->write_data(count+2, 0b00010000);
    memory->write_data(count+3, 0b00000000);
    memory->write_data(count+4, 0b01100000);
    memory->write_data(count+5, 0b10000000);
    memory->write_data(count+6, 0b10000000);
    memory->write_data(count+7, 0b01000000);
    count += 8;

    // Cloud Bush UL 21
    memory->write_data(count+0, 0b00000011);
    memory->write_data(count+1, 0b00000111);
    memory->write_data(count+2, 0b00011111);
    memory->write_data(count+3, 0b00111111);
    memory->write_data(count+4, 0b00111111);
    memory->write_data(count+5, 0b00111111);
    memory->write_data(count+6, 0b01111001);
    memory->write_data(count+7, 0b11110111);
    count += 8;

    memory->write_data(count+0, 0b00000011);
    memory->write_data(count+1, 0b00000100);
    memory->write_data(count+2, 0b00011000);
    memory->write_data(count+3, 0b00100000);
    memory->write_data(count+4, 0b00100000);
    memory->write_data(count+5, 0b00100000);
    memory->write_data(count+6, 0b01000110);
    memory->write_data(count+7, 0b10001000);
    count += 8;

    // Cloud Bush UR 22
    memory->write_data(count+0, 0b11000000);
    memory->write_data(count+1, 0b11100000);
    memory->write_data(count+2, 0b11110000);
    memory->write_data(count+3, 0b11110100);
    memory->write_data(count+4, 0b11111110);
    memory->write_data(count+5, 0b10111111);
    memory->write_data(count+6, 0b11011111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    memory->write_data(count+0, 0b11000000);
    memory->write_data(count+1, 0b00100000);
    memory->write_data(count+2, 0b00010000);
    memory->write_data(count+3, 0b00010100);
    memory->write_data(count+4, 0b00001010);
    memory->write_data(count+5, 0b01000001);
    memory->write_data(count+6, 0b00100001);
    memory->write_data(count+7, 0b00000001);
    count += 8;

    // Cloud Bush LR 23
    memory->write_data(count+0, 0b10010000);
    memory->write_data(count+1, 0b10111000);
    memory->write_data(count+2, 0b11111000);
    memory->write_data(count+3, 0b11111010);
    memory->write_data(count+4, 0b11111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b11111110);
    count += 8;

    memory->write_data(count+0, 0b10010000);
    memory->write_data(count+1, 0b10101000);
    memory->write_data(count+2, 0b01001000);
    memory->write_data(count+3, 0b00001010);
    memory->write_data(count+4, 0b00000101);
    memory->write_data(count+5, 0b00000001);
    memory->write_data(count+6, 0b00000001);
    memory->write_data(count+7, 0b00000010);
    count += 8;

    // Cloud Bush Core 24
    memory->write_data(count,   0b11111111);
    memory->write_data(count+1, 0b11111111);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b11111111);
    memory->write_data(count+4, 0b11111111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b11111111);
    count += 8;

    memory->write_data(count,   0b00000000);
    memory->write_data(count+1, 0b00000000);
    memory->write_data(count+2, 0b00000000);
    memory->write_data(count+3, 0b00000000);
    memory->write_data(count+4, 0b00000000);
    memory->write_data(count+5, 0b00000000);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    // Cloud LL 25
    memory->write_data(count+0, 0b00111011);
    memory->write_data(count+1, 0b00011101);
    memory->write_data(count+2, 0b00001110);
    memory->write_data(count+3, 0b00001111);
    memory->write_data(count+4, 0b00000111);
    memory->write_data(count+5, 0b00000000);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    memory->write_data(count+0, 0b00100100);
    memory->write_data(count+1, 0b00010010);
    memory->write_data(count+2, 0b00001001);
    memory->write_data(count+3, 0b00001000);
    memory->write_data(count+4, 0b00000111);
    memory->write_data(count+5, 0b00000000);
    memory->write_data(count+6, 0b00000000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    // Cloud ML 26
    memory->write_data(count+0, 0b11111111);
    memory->write_data(count+1, 0b10111111);
    memory->write_data(count+2, 0b00011100);
    memory->write_data(count+3, 0b11000000);
    memory->write_data(count+4, 0b11110011);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b01111110);
    memory->write_data(count+7, 0b00011100);
    count += 8;

    memory->write_data(count+0, 0b00000000);
    memory->write_data(count+1, 0b01000000);
    memory->write_data(count+2, 0b11100011);
    memory->write_data(count+3, 0b00111111);
    memory->write_data(count+4, 0b00001100);
    memory->write_data(count+5, 0b10000001);
    memory->write_data(count+6, 0b01100010);
    memory->write_data(count+7, 0b00011100);
    count += 8;

    // Cloud MR 27
    memory->write_data(count+0, 0b10111111);
    memory->write_data(count+1, 0b01111111);
    memory->write_data(count+2, 0b00111101);
    memory->write_data(count+3, 0b10000011);
    memory->write_data(count+4, 0b11000111);
    memory->write_data(count+5, 0b11111111);
    memory->write_data(count+6, 0b11111111);
    memory->write_data(count+7, 0b00111100);
    count += 8;

    memory->write_data(count+0, 0b01000000);
    memory->write_data(count+1, 0b10000000);
    memory->write_data(count+2, 0b11000010);
    memory->write_data(count+3, 0b01111100);
    memory->write_data(count+4, 0b00111000);
    memory->write_data(count+5, 0b00000000);
    memory->write_data(count+6, 0b11000011);
    memory->write_data(count+7, 0b00111100);
    count += 8;

    // Cloud RR 28
    memory->write_data(count+0, 0b11111100);
    memory->write_data(count+1, 0b11111110);
    memory->write_data(count+2, 0b11111111);
    memory->write_data(count+3, 0b11111110);
    memory->write_data(count+4, 0b11111110);
    memory->write_data(count+5, 0b11111000);
    memory->write_data(count+6, 0b01100000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    memory->write_data(count+0, 0b00000100);
    memory->write_data(count+1, 0b00000010);
    memory->write_data(count+2, 0b00000001);
    memory->write_data(count+3, 0b00000000);
    memory->write_data(count+4, 0b00000110);
    memory->write_data(count+5, 0b10011000);
    memory->write_data(count+6, 0b01100000);
    memory->write_data(count+7, 0b00000000);
    count += 8;

    memory->write_data(0x2000, 0);
    memory->write_data(0x2001, 0);
    memory->write_data(0x2002, 21);
    memory->write_data(0x2003, 22);
    memory->write_data(0x2004, 0);
    memory->write_data(0x2005, 0);
    memory->write_data(0x2006, 0);
    memory->write_data(0x2007, 0);
    memory->write_data(0x2008, 0);
    memory->write_data(0x2009, 0);
    memory->write_data(0x200A, 0);
    memory->write_data(0x200B, 0);
    memory->write_data(0x200C, 0);
    memory->write_data(0x200D, 0);
    memory->write_data(0x200E, 0);
    memory->write_data(0x200F, 0);
    memory->write_data(0x2010, 0);
    memory->write_data(0x2011, 0);
    memory->write_data(0x2012, 0);
    memory->write_data(0x2013, 0);
    memory->write_data(0x2014, 0);
    memory->write_data(0x2015, 0);
    memory->write_data(0x2016, 0);
    memory->write_data(0x2017, 0);
    memory->write_data(0x2018, 0);
    memory->write_data(0x2019, 0);
    memory->write_data(0x201A, 0);
    memory->write_data(0x201B, 0);
    memory->write_data(0x201C, 0);
    memory->write_data(0x201D, 0);
    memory->write_data(0x201E, 0);
    memory->write_data(0x201F, 0);

    memory->write_data(0x2020, 0);
    memory->write_data(0x2021, 20);
    memory->write_data(0x2022, 24);
    memory->write_data(0x2023, 24);
    memory->write_data(0x2024, 23);
    memory->write_data(0x2025, 0);
    memory->write_data(0x2026, 0);
    memory->write_data(0x2027, 0);
    memory->write_data(0x2028, 0);
    memory->write_data(0x2029, 0);
    memory->write_data(0x202A, 0);
    memory->write_data(0x202B, 0);
    memory->write_data(0x202C, 0);
    memory->write_data(0x202D, 0);
    memory->write_data(0x202E, 0);
    memory->write_data(0x202F, 0);
    memory->write_data(0x2030, 0);
    memory->write_data(0x2031, 0);
    memory->write_data(0x2032, 0);
    memory->write_data(0x2033, 0);
    memory->write_data(0x2034, 0);
    memory->write_data(0x2035, 0);
    memory->write_data(0x2036, 0);
    memory->write_data(0x2037, 0);
    memory->write_data(0x2038, 21);
    memory->write_data(0x2039, 22);
    memory->write_data(0x203A, 0);
    memory->write_data(0x203B, 0);
    memory->write_data(0x203C, 0);
    memory->write_data(0x203D, 0);
    memory->write_data(0x203E, 0);
    memory->write_data(0x203F, 0);

    memory->write_data(0x2040, 0);
    memory->write_data(0x2041, 25);
    memory->write_data(0x2042, 26);
    memory->write_data(0x2043, 27);
    memory->write_data(0x2044, 28);
    memory->write_data(0x2045, 0);
    memory->write_data(0x2046, 0);
    memory->write_data(0x2047, 0);
    memory->write_data(0x2048, 0);
    memory->write_data(0x2049, 0);
    memory->write_data(0x204A, 0);
    memory->write_data(0x204B, 0);
    memory->write_data(0x204C, 0);
    memory->write_data(0x204D, 0);
    memory->write_data(0x204E, 0);
    memory->write_data(0x204F, 0);
    memory->write_data(0x2050, 0);
    memory->write_data(0x2051, 0);
    memory->write_data(0x2052, 0);
    memory->write_data(0x2053, 0);
    memory->write_data(0x2054, 0);
    memory->write_data(0x2055, 0);
    memory->write_data(0x2056, 0);
    memory->write_data(0x2057, 20);
    memory->write_data(0x2058, 24);
    memory->write_data(0x2059, 24);
    memory->write_data(0x205A, 23);
    memory->write_data(0x205B, 0);
    memory->write_data(0x205C, 0);
    memory->write_data(0x205D, 0);
    memory->write_data(0x205E, 0);
    memory->write_data(0x205F, 0);

    memory->write_data(0x2060, 0);
    memory->write_data(0x2061, 0);
    memory->write_data(0x2062, 0);
    memory->write_data(0x2063, 0);
    memory->write_data(0x2064, 0);
    memory->write_data(0x2065, 0);
    memory->write_data(0x2066, 0);
    memory->write_data(0x2067, 0);
    memory->write_data(0x2068, 0);
    memory->write_data(0x2069, 0);
    memory->write_data(0x206A, 0);
    memory->write_data(0x206B, 0);
    memory->write_data(0x206C, 0);
    memory->write_data(0x206D, 0);
    memory->write_data(0x206E, 0);
    memory->write_data(0x206F, 0);
    memory->write_data(0x2070, 0);
    memory->write_data(0x2071, 0);
    memory->write_data(0x2072, 0);
    memory->write_data(0x2073, 0);
    memory->write_data(0x2074, 0);
    memory->write_data(0x2075, 0);
    memory->write_data(0x2076, 0);
    memory->write_data(0x2077, 25);
    memory->write_data(0x2078, 26);
    memory->write_data(0x2079, 27);
    memory->write_data(0x207A, 28);
    memory->write_data(0x207B, 0);
    memory->write_data(0x207C, 0);
    memory->write_data(0x207D, 0);
    memory->write_data(0x207E, 0);
    memory->write_data(0x207F, 0);

    // Blocks upper half
    memory->write_data(0x210D, 0);
    memory->write_data(0x210E, 2);
    memory->write_data(0x210F, 2);
    memory->write_data(0x2110, 16);
    memory->write_data(0x2111, 17);
    memory->write_data(0x2112, 2);
    memory->write_data(0x2113, 2);
    memory->write_data(0x2114, 2);
    memory->write_data(0x2115, 2);
    memory->write_data(0x2116, 0);

    memory->write_data(0x2128, 0);
    memory->write_data(0x212B, 0);

    // Blocks lower half
    memory->write_data(0x213D, 0);
    memory->write_data(0x212E, 3);
    memory->write_data(0x212F, 3);
    memory->write_data(0x2130, 18);
    memory->write_data(0x2131, 19);
    memory->write_data(0x2132, 3);
    memory->write_data(0x2133, 3);
    memory->write_data(0x2134, 3);
    memory->write_data(0x2135, 3);
    memory->write_data(0x2136, 0);

    // Mario upper half
    memory->write_data(0x21C6, 8);
    memory->write_data(0x21C6+1, 9);
    memory->write_data(0x21C6+32, 10);
    memory->write_data(0x21C6+33, 11);

    // Bush top half
    memory->write_data(0x21CD, 21);
    memory->write_data(0x21CE, 22);

    // Bush bottom half
    memory->write_data(0x21EC, 20);
    memory->write_data(0x21ED, 24);
    memory->write_data(0x21EE, 24);
    memory->write_data(0x21EF, 23);

    // Ground blocks
    memory->write_data(0x2200, 4);
    memory->write_data(0x2201, 5);
    memory->write_data(0x2202, 4);
    memory->write_data(0x2203, 5);
    memory->write_data(0x2204, 4);
    memory->write_data(0x2205, 5);
    memory->write_data(0x2206, 4);
    memory->write_data(0x2207, 5);
    memory->write_data(0x2208, 4);
    memory->write_data(0x2209, 5);
    memory->write_data(0x220A, 4);
    memory->write_data(0x220B, 5);
    memory->write_data(0x220C, 4);
    memory->write_data(0x220D, 5);
    memory->write_data(0x220E, 4);
    memory->write_data(0x220F, 5);
    memory->write_data(0x2210, 4);
    memory->write_data(0x2211, 5);
    memory->write_data(0x2212, 4);
    memory->write_data(0x2213, 5);
    memory->write_data(0x2214, 4);
    memory->write_data(0x2215, 5);
    memory->write_data(0x2216, 4);
    memory->write_data(0x2217, 5);
    memory->write_data(0x2218, 4);
    memory->write_data(0x2219, 5);
    memory->write_data(0x221A, 4);
    memory->write_data(0x221B, 5);
    memory->write_data(0x221C, 4);
    memory->write_data(0x221D, 5);
    memory->write_data(0x221E, 4);
    memory->write_data(0x221F, 5);

    memory->write_data(0x2220, 6);
    memory->write_data(0x2221, 7);
    memory->write_data(0x2222, 6);
    memory->write_data(0x2223, 7);
    memory->write_data(0x2224, 6);
    memory->write_data(0x2225, 7);
    memory->write_data(0x2226, 6);
    memory->write_data(0x2227, 7);
    memory->write_data(0x2228, 6);
    memory->write_data(0x2229, 7);
    memory->write_data(0x222A, 6);
    memory->write_data(0x222B, 7);
    memory->write_data(0x222C, 6);
    memory->write_data(0x222D, 7);
    memory->write_data(0x222E, 6);
    memory->write_data(0x222F, 7);
    memory->write_data(0x2230, 6);
    memory->write_data(0x2231, 7);
    memory->write_data(0x2232, 6);
    memory->write_data(0x2233, 7);
    memory->write_data(0x2234, 6);
    memory->write_data(0x2235, 7);
    memory->write_data(0x2236, 6);
    memory->write_data(0x2237, 7);
    memory->write_data(0x2238, 6);
    memory->write_data(0x2239, 7);
    memory->write_data(0x223A, 6);
    memory->write_data(0x223B, 7);
    memory->write_data(0x223C, 6);
    memory->write_data(0x223D, 7);
    memory->write_data(0x223E, 6);
    memory->write_data(0x223F, 7);

    // Pallet indexs
    memory->write_data(0x23C0, 0b11111111);
    memory->write_data(0x23C1, 0b11111111);
    memory->write_data(0x23C2, 0b11111111);
    memory->write_data(0x23C3, 0b11111111);
    memory->write_data(0x23C4, 0b11111111);
    memory->write_data(0x23C5, 0b11111111);
    memory->write_data(0x23C6, 0b11111111);
    memory->write_data(0x23C7, 0b11111111);

    memory->write_data(0x23D0, 0b01010101);
    memory->write_data(0x23D1, 0b01010101);
    memory->write_data(0x23D2, 0b01010101);
    memory->write_data(0x23D3, 0b01010101);
    memory->write_data(0x23D4, 0b01010101);
    memory->write_data(0x23D5, 0b01010101);
    memory->write_data(0x23D6, 0b11111111);
    memory->write_data(0x23D7, 0b11111111);

    memory->write_data(0x23D8, 0b00000000);
    memory->write_data(0x23D9, 0b00000000);
    memory->write_data(0x23DA, 0b00000000);
    memory->write_data(0x23DB, 0b10101010);
    memory->write_data(0x23DC, 0b10101010);
    memory->write_data(0x23DD, 0b10101010);
    memory->write_data(0x23DE, 0b10101010);
    memory->write_data(0x23DF, 0b10101010);

    memory->write_data(0x23E0, 0b01010101);
    memory->write_data(0x23E1, 0b01010101);
    memory->write_data(0x23E2, 0b01010101);
    memory->write_data(0x23E3, 0b01010101);
    memory->write_data(0x23E4, 0b01010101);
    memory->write_data(0x23E5, 0b01010101);
    memory->write_data(0x23E6, 0b01010101);
    memory->write_data(0x23E7, 0b01010101);

    memory->write_data(0x27C0, 0b00000000);
    memory->write_data(0x2BC0, 0b00000000);
};

int main(int argc, char **argv)
{
    // Clock
    Clock CLK;

    // Constants
    ConstantValue VCC("VCC", 1);
    ConstantValue GND("GND", 0);
    
    // Horizontal counters
    SN74LS161A ha("HA");
    SN74LS161A hb("HB");
    SN74LS161A hc("HC");
    ha.connect_input(&VCC, "A", {"PE", "CET", "CEP"});
    ha.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    hb.connect_input(&VCC, "A", InputStringVector{"PE", "CEP"});
    hb.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    hc.connect_input(&VCC, "A", InputStringVector{"PE", "CEP"});
    hc.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});

    // Connect counter to clock and chain the count overflow
    ha.connect_input(&CLK, "A", "CP");
    hb.connect_input(&CLK, "A", "CP");
    hc.connect_input(&CLK, "A", "CP");
    hb.connect_input(&ha, "TC", "CET");
    hc.connect_input(&hb, "TC", "CET");

    SN74LS04 count_invert("CountInvert");
    count_invert.connect_input(&hb, "Q1", "6A");

    // Count 262 detection
    SN74LS20 h262_h300("H262_H300");
    h262_h300.connect_input(&hc, "Q0", "A1");
    h262_h300.connect_input(&ha, "Q1", "B1");
    h262_h300.connect_input(&ha, "Q2", "C1");
    h262_h300.connect_input(&count_invert, "6Y", "D1");

    // Count 300 detection
    h262_h300.connect_input(&hc, "Q0", "A2");
    h262_h300.connect_input(&ha, "Q2", "B2");
    h262_h300.connect_input(&hb, "Q1", "C2");
    h262_h300.connect_input(&ha, "Q3", "D2");

    // Count 318 detection
    SN74LS30 h318("H318");
    h318.connect_input(&hc, "Q0", "A");
    h318.connect_input(&ha, "Q1", "B");
    h318.connect_input(&ha, "Q2", "C");
    h318.connect_input(&ha, "Q3", "D");
    h318.connect_input(&hb, "Q0", "E");
    h318.connect_input(&hb, "Q1", "F");
    h318.connect_input(&VCC, "A", InputStringVector{"G", "H"});

    // Connect count 318 to horizontal count reset
    ha.connect_input(&h318, "Y", "MR");
    hb.connect_input(&h318, "Y", "MR");
    hc.connect_input(&h318, "Y", "MR");

    SN74LS00 h_sr_latch("HSrLatch");
    // Hsync detection on 3Y, HsyncB detection on 4Y
    h_sr_latch.connect_input(&h262_h300, "Y2", "3B");
    h_sr_latch.connect_input(&h_sr_latch, "3Y", "4B");
    h_sr_latch.connect_input(&h_sr_latch, "4Y", "3A");
    h_sr_latch.connect_input(&h262_h300, "Y1", "4A");
    // HBlank detection on 1Y
    h_sr_latch.connect_input(&hc, "Q0", "1A");
    h_sr_latch.connect_input(&hc, "Q0", "1B");

    count_invert.connect_input(&ha, "Q0", "4A");
    count_invert.connect_input(&hb, "Q0", "5A");

    SN74LS30 hstart("HStart");
    hstart.connect_input(&ha, "Q1", "A");
    hstart.connect_input(&ha, "Q2", "B");
    hstart.connect_input(&ha, "Q3", "C");
    hstart.connect_input(&count_invert, "4Y", "D");
    hstart.connect_input(&count_invert, "5Y", "E");
    hstart.connect_input(&hb, "Q1", "F");
    hstart.connect_input(&hc, "Q0", "G");
    hstart.connect_input(&VCC, "A", "H");

    // Vertical counters
    SN74LS161A va("VA");
    SN74LS161A vb("VB");
    SN74LS161A vc("VC");
    va.connect_input(&VCC, "A", {"PE", "CET", "CEP"});
    va.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    vb.connect_input(&VCC, "A", InputStringVector{"PE", "CEP"});
    vb.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});
    vc.connect_input(&VCC, "A", InputStringVector{"PE", "CEP"});
    vc.connect_input(&GND, "A", {"P0", "P1", "P2", "P3"});

    // Connect counter to vertical counters
    va.connect_input(&h_sr_latch, "4Y", "CP");
    vb.connect_input(&h_sr_latch, "4Y", "CP");
    vc.connect_input(&h_sr_latch, "4Y", "CP");
    vb.connect_input(&va, "TC", "CET");
    vc.connect_input(&vb, "TC", "CET");

    SN74LS20 v480_v525("V480_V525");
    v480_v525.connect_input(&vc, "Q0", "A1");
    v480_v525.connect_input(&vb, "Q1", "B1");
    v480_v525.connect_input(&vb, "Q2", "C1");
    v480_v525.connect_input(&vb, "Q3", "D1");

    v480_v525.connect_input(&va, "Q0", "A2");
    v480_v525.connect_input(&vc, "Q1", "B2");
    v480_v525.connect_input(&va, "Q2", "C2");
    v480_v525.connect_input(&va, "Q3", "D2");

    count_invert.connect_input(&va, "Q2", "1A");
    count_invert.connect_input(&vb, "Q0", "2A");

    h_sr_latch.connect_input(&count_invert, "1Y", "2A");
    h_sr_latch.connect_input(&count_invert, "2Y", "2B");

    count_invert.connect_input(&h_sr_latch, "2Y", "3A");

    SN74LS30 v490("V490");
    v490.connect_input(&count_invert, "3Y", "A");
    v490.connect_input(&va, "Q1", "B");
    v490.connect_input(&va, "Q3", "C");
    v490.connect_input(&vb, "Q1", "D");
    v490.connect_input(&vb, "Q2", "E");
    v490.connect_input(&vb, "Q3", "F");
    v490.connect_input(&vc, "Q0", "G");
    v490.connect_input(&VCC, "A", "H");

    SN74LS30 v492("V492");
    v492.connect_input(&va, "Q2", "A");
    v492.connect_input(&va, "Q3", "B");
    v492.connect_input(&vb, "Q1", "C");
    v492.connect_input(&vb, "Q2", "D");
    v492.connect_input(&vb, "Q3", "E");
    v492.connect_input(&vc, "Q0", "F");
    v492.connect_input(&VCC, "A", InputStringVector{"G", "H"});

    va.connect_input(&v480_v525, "Y2", "MR");
    vb.connect_input(&v480_v525, "Y2", "MR");
    vc.connect_input(&v480_v525, "Y2", "MR");

    SN74LS00 v_sr_latch("VSrLatch");
    // Vsync detection on 3Y, VsyncB detection on 4Y
    v_sr_latch.connect_input(&v492, "Y", "3B");
    v_sr_latch.connect_input(&v_sr_latch, "4Y", "3A");
    v_sr_latch.connect_input(&v_sr_latch, "3Y", "4B");
    v_sr_latch.connect_input(&v490, "Y", "4A");
    // Vblank detection on 1Y, VblankB detection on 2Y
    v_sr_latch.connect_input(&v480_v525, "Y2", "1A");
    v_sr_latch.connect_input(&v_sr_latch, "2Y", "1B");
    v_sr_latch.connect_input(&v_sr_latch, "1Y", "2A");
    v_sr_latch.connect_input(&v480_v525, "Y1", "2B");

    // PPU Control
    SN74HC373 ppu_control("PPUControl");
    ppu_control.connect_input(&VCC, "A", "LE");
    ppu_control.connect_input(&GND, "A", {"OE", "D3", "D4", "D5", "D6", "D7"});
    ppu_control.connect_input(&GND, "A", InputStringVector{"D0", "D1", "D2"});

    // BG Count H
    SN74HC163N bgha("BGHCount1");
    SN74HC163N bghb("BGHCount2");
    bgha.connect_input(&CLK, "A", "CP");
    bgha.connect_input(&VCC, "A", {"MR", "CEP", "CET"});
    bgha.connect_input(&hstart, "Y", "PE");
    bgha.connect_input(&GND, "A", {"D0", "D1", "D2"});
    bghb.connect_input(&CLK, "A", "CP");
    bghb.connect_input(&VCC, "A", InputStringVector{"MR", "CEP"});
    bghb.connect_input(&bgha, "TC", "CET");
    bghb.connect_input(&hstart, "Y", "PE");

    SN74HC373 bgh_offset("BGHOffsetLatch");
    bgh_offset.connect_input(&VCC, "A", "LE");
    bgh_offset.connect_input(&GND, "A", {"OE", "D0", "D1", "D2", "D3", "D4", "D5", "D6"});
    bgh_offset.connect_input(&VCC, "A", "D7");

    bgha.connect_input(&bgh_offset, "Q3", "D3");
    bghb.connect_input(&bgh_offset, "Q4", "D0");
    bghb.connect_input(&bgh_offset, "Q5", "D1");
    bghb.connect_input(&bgh_offset, "Q6", "D2");
    bghb.connect_input(&bgh_offset, "Q7", "D3");

    // Stage Decoder
    SN74HC42 stage_decoder("StageDecoder1");
    stage_decoder.connect_input(&bgha, "Q0", "A");
    stage_decoder.connect_input(&bgha, "Q1", "B");
    stage_decoder.connect_input(&bgha, "Q2", "C");
    stage_decoder.connect_input(&ppu_control, "Q0", "D");

    // BG Count V
    SN74HC163N bgva("BGVCount1");
    SN74HC163N bgvb("BGVCount2");
    bgva.connect_input(&va, "Q0", "CP");
    bgva.connect_input(&VCC, "A", InputStringVector{"CEP", "CET"});
    bgva.connect_input(&v_sr_latch, "1Y", "PE");
    bgva.connect_input(&GND, "A", {"D0", "D1", "D2"});
    bgvb.connect_input(&va, "Q0", "CP");
    bgvb.connect_input(&VCC, "A", "CEP");
    bgvb.connect_input(&bgva, "TC", "CET");
    bgvb.connect_input(&v_sr_latch, "1Y", "PE");

    SN74HC373 bgv_offset("BGVOffsetLatch");
    bgv_offset.connect_input(&VCC, "A", "LE");
    bgv_offset.connect_input(&GND, "A", {"OE", "D0", "D1", "D2", "D3", "D4", "D5", "D6"});
    bgv_offset.connect_input(&VCC, "A", "D7");

    bgva.connect_input(&bgv_offset, "Q0", "D0");
    bgva.connect_input(&bgv_offset, "Q1", "D1");
    bgva.connect_input(&bgv_offset, "Q2", "D2");
    bgva.connect_input(&bgv_offset, "Q3", "D3");
    bgvb.connect_input(&bgv_offset, "Q4", "D0");
    bgvb.connect_input(&bgv_offset, "Q5", "D1");
    bgvb.connect_input(&bgv_offset, "Q6", "D2");
    bgvb.connect_input(&bgv_offset, "Q7", "D3");

    SN74LS30 bgv_reset("BGVReset");
    bgv_reset.connect_input(&bgvb, "Q0", "A");
    bgv_reset.connect_input(&bgvb, "Q1", "B");
    bgv_reset.connect_input(&bgvb, "Q2", "C");
    bgv_reset.connect_input(&bgvb, "Q3", "D");
    bgv_reset.connect_input(&VCC, "A", {"E", "F", "G", "H"});

    bgva.connect_input(&bgv_reset, "Y", "MR");
    bgvb.connect_input(&bgv_reset, "Y", "MR");

    SN74LS04 bg_invert("BgInvert");
    bg_invert.connect_input(&bghb, "TC", "1A");
    bg_invert.connect_input(&GND, "A", {"2A", "3A", "4A", "5A", "6A"});

    SN74LS00 bg_sr_latch("BgSrLatch");
    bg_sr_latch.connect_input(&h_sr_latch, "3Y", "1A");
    bg_sr_latch.connect_input(&bg_sr_latch, "2Y", "1B");
    bg_sr_latch.connect_input(&bg_sr_latch, "1Y", "2A");
    bg_sr_latch.connect_input(&bg_invert, "1Y", "2B");

    bg_sr_latch.connect_input(&v_sr_latch, "3Y", "3B");
    bg_sr_latch.connect_input(&bg_sr_latch, "4Y", "3A");
    bg_sr_latch.connect_input(&bg_sr_latch, "3Y", "4B");
    bg_sr_latch.connect_input(&bgv_reset, "Y", "4A");

    SN74LS08 bg_and("BgAND");
    bg_and.connect_input(&GND, "A", {"A3", "B3", "A4", "B4"});
    bg_and.connect_input(&bg_sr_latch, "2Y", "A1");
    bg_and.connect_input(&ppu_control, "Q1", "B1");
    bg_and.connect_input(&bg_sr_latch, "4Y", "A2");
    bg_and.connect_input(&ppu_control, "Q2", "B2");

    SN74HC245 nametable_bus1("NametableBus1");
    SN74HC245 nametable_bus2("NametableBus1");
    nametable_bus1.connect_input(&VCC, "A", "DIR");
    nametable_bus2.connect_input(&VCC, "A", "DIR");
    // nametable_bus1.connect_input(&stage_decoder, "1", "OE");
    // nametable_bus2.connect_input(&stage_decoder, "1", "OE");
    nametable_bus1.connect_input(&GND, "A", "OE");
    nametable_bus2.connect_input(&GND, "A", "OE");

    nametable_bus1.connect_input(&bgha, "Q3", "A1");
    nametable_bus1.connect_input(&bghb, "Q0", "A2");
    nametable_bus1.connect_input(&bghb, "Q1", "A3");
    nametable_bus1.connect_input(&bghb, "Q2", "A4");
    nametable_bus1.connect_input(&bghb, "Q3", "A5");
    nametable_bus1.connect_input(&bgva, "Q3", "A6");
    nametable_bus1.connect_input(&bgvb, "Q0", "A7");
    nametable_bus1.connect_input(&bgvb, "Q1", "A8");

    nametable_bus2.connect_input(&bgvb, "Q2", "A1");
    nametable_bus2.connect_input(&bgvb, "Q3", "A2");
    nametable_bus2.connect_input(&bg_and, "Y1", "A3");
    nametable_bus2.connect_input(&bg_and, "Y2", "A4");
    nametable_bus2.connect_input(&GND, "A", {"A5", "A7", "A8"});
    nametable_bus2.connect_input(&VCC, "A", "A6");
    
    IDT71256SA ppu_main_memory("PPUMainMemory");
    preset_memory(&ppu_main_memory);
    ppu_main_memory.connect_input(&VCC, "A", "WE");
    ppu_main_memory.connect_input(&GND, "A", InputStringVector{"OE", "CS"});
    //ppu_main_memory.connect_input(&GND, "A", {"A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11", "A12", "A13", "A14"});
    ppu_main_memory.connect_input(&nametable_bus1, "B1", "A0");
    ppu_main_memory.connect_input(&nametable_bus1, "B2", "A1");
    ppu_main_memory.connect_input(&nametable_bus1, "B3", "A2");
    ppu_main_memory.connect_input(&nametable_bus1, "B4", "A3");
    ppu_main_memory.connect_input(&nametable_bus1, "B5", "A4");
    ppu_main_memory.connect_input(&nametable_bus1, "B6", "A5");
    ppu_main_memory.connect_input(&nametable_bus1, "B7", "A6");
    ppu_main_memory.connect_input(&nametable_bus1, "B8", "A7");

    ppu_main_memory.connect_input(&nametable_bus2, "B1", "A8");
    ppu_main_memory.connect_input(&nametable_bus2, "B2", "A9");
    ppu_main_memory.connect_input(&nametable_bus2, "B3", "A10");
    ppu_main_memory.connect_input(&nametable_bus2, "B4", "A11");
    ppu_main_memory.connect_input(&nametable_bus2, "B5", "A12");
    ppu_main_memory.connect_input(&nametable_bus2, "B6", "A13");
    ppu_main_memory.connect_input(&nametable_bus2, "B7", "A14");

    // Make sure all nodes that connect to VCC and Ground but not CLK
    // are cooked at least once first to set up any internal state
    VCC.propagate();
    GND.propagate();

    // Open output image
    std::freopen("output.ppm", "w", stdout);
    std::cout << "P3\n" << 318 << " " << 525 << "\n255\n";

    int end_count = 166950*2;
    while (CLK.count < end_count)
    {
        // Start propagation from the clock
        bool propagate = false;
        CLK.cook(propagate);
        if (propagate) {
            CLK.propagate();
        }

        if (CLK.count > 166950 && CLK.output_value("A")) {
            int h_sync = h_sr_latch.output_value("3Y")*255;
            int h_blank = h_sr_latch.output_value("1Y")*255;
            int v_sync = v_sr_latch.output_value("3Y")*255;
            int v_blank = v_sr_latch.output_value("1Y")*255;
            int h_nametable = bg_and.output_value("Y1")*255;
            int v_nametable = bg_and.output_value("Y2")*255;
            // std::bitset<8> h_count;
            // std::bitset<8> v_count;

            // h_count[0]  = bgha.output_value("Q0");
            // h_count[1]  = bgha.output_value("Q1");
            // h_count[2]  = bgha.output_value("Q2");
            // h_count[3]  = bgha.output_value("Q3");
            // h_count[4]  = bghb.output_value("Q0");
            // h_count[5]  = bghb.output_value("Q1");
            // h_count[6]  = bghb.output_value("Q2");
            // h_count[7]  = bghb.output_value("Q3");
            // double h_alpha = h_count.to_ullong()/318.0;
            // int h_value = int(255*h_alpha);

            // v_count[0]  = bgva.output_value("Q0");
            // v_count[1]  = bgva.output_value("Q1");
            // v_count[2]  = bgva.output_value("Q2");
            // v_count[3]  = bgva.output_value("Q3");
            // v_count[4]  = bgvb.output_value("Q0");
            // v_count[5]  = bgvb.output_value("Q1");
            // v_count[6]  = bgvb.output_value("Q2");
            // v_count[7]  = bgvb.output_value("Q3");
            // double v_alpha = v_count.to_ullong()/525.0;
            // int v_value = int(255*v_alpha);

            // std::bitset<16> addr;
            // unsigned long raw = 0;
            // if (nametable_bus1.output_value("B1") >= 0) {
            //     addr[0]  = nametable_bus1.output_value("B1");
            //     addr[1]  = nametable_bus1.output_value("B2");
            //     addr[2]  = nametable_bus1.output_value("B3");
            //     addr[3]  = nametable_bus1.output_value("B4");
            //     addr[4]  = nametable_bus1.output_value("B5");
            //     addr[5]  = nametable_bus1.output_value("B6");
            //     addr[6]  = nametable_bus1.output_value("B7");
            //     addr[7]  = nametable_bus1.output_value("B8");
            //     addr[8]  = nametable_bus2.output_value("B1");
            //     addr[9]  = nametable_bus2.output_value("B2");
            //     addr[10] = nametable_bus2.output_value("B3");
            //     addr[11] = nametable_bus2.output_value("B4");
            //     addr[12] = nametable_bus2.output_value("B5");
            //     addr[13] = nametable_bus2.output_value("B6");
            //     addr[14] = nametable_bus2.output_value("B7");
            //     addr[15] = nametable_bus2.output_value("B8");
            //     raw = addr.to_ullong();
            // }
            std::bitset<8> addr;
            unsigned long raw = 0;
            if (nametable_bus1.output_value("B1") >= 0) {
                addr[0]  = ppu_main_memory.output_value("IO0");
                addr[1]  = ppu_main_memory.output_value("IO1");
                addr[2]  = ppu_main_memory.output_value("IO2");
                addr[3]  = ppu_main_memory.output_value("IO3");
                addr[4]  = ppu_main_memory.output_value("IO4");
                addr[5]  = ppu_main_memory.output_value("IO5");
                addr[6]  = ppu_main_memory.output_value("IO6");
                addr[7]  = ppu_main_memory.output_value("IO7");
                raw = addr.to_ullong();
            }
            double alpha = raw/32768.0;
            int value = int(255*alpha);
            std::cout << value << " " << 0 << " " << 0 << "\n";
        }

        // Log the progress
        if (CLK.should_log()) {
            std::cerr << "Percent : " << int((double(CLK.count)/double(end_count))*100.0) << "%" << std::endl;
        }
    }

    std::cerr << "Done" << std::endl;

    return 1;
}