EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:akn_misc
LIBS:max
LIBS:brochehacker-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATTINY85-P IC1
U 1 1 579A7C66
P 7350 3050
F 0 "IC1" H 6200 3450 50  0000 C CNN
F 1 "ATTINY85-P" H 8350 2650 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 8350 3050 50  0000 C CIN
F 3 "" H 7350 3050 50  0000 C CNN
	1    7350 3050
	1    0    0    -1  
$EndComp
$Comp
L DISP_LED_MAT_8x8_COM_CAT D1
U 1 1 579A7CAA
P 4000 5400
F 0 "D1" H 4200 5350 60  0000 C CNN
F 1 "DISP_LED_MAT_8x8_COM_CAT" H 4650 6350 60  0000 C CNN
F 2 "akn_misc:LED_8x8_3MM_32x32MM" H 4100 5350 60  0001 C CNN
F 3 "" H 4100 5350 60  0000 C CNN
	1    4000 5400
	1    0    0    -1  
$EndComp
$Comp
L MAX7219 U1
U 1 1 579A7D01
P 4200 2750
F 0 "U1" H 4200 2050 60  0000 C CNN
F 1 "MAX7219" H 4200 3450 60  0000 C CNN
F 2 "Housings_DIP:DIP-24_W7.62mm" H 4800 2750 60  0001 C CNN
F 3 "" H 4800 2750 60  0000 C CNN
	1    4200 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3300 5650 3300
Wire Wire Line
	5650 3300 5650 3200
Wire Wire Line
	5650 3200 6000 3200
Wire Wire Line
	6000 2800 6000 1900
Wire Wire Line
	6000 1900 3600 1900
Wire Wire Line
	3600 1900 3600 2200
Wire Wire Line
	3600 3300 3600 3550
Wire Wire Line
	3600 3550 5750 3550
Wire Wire Line
	5750 3550 5750 3100
Wire Wire Line
	5750 3100 6000 3100
Wire Wire Line
	4800 2800 5100 2800
$Comp
L R R1
U 1 1 579A7E18
P 5250 2800
F 0 "R1" V 5330 2800 50  0000 C CNN
F 1 "10k" V 5250 2800 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5180 2800 50  0001 C CNN
F 3 "" H 5250 2800 50  0000 C CNN
	1    5250 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 2800 5400 2700
Wire Wire Line
	5400 2700 4800 2700
Text GLabel 5400 2700 2    60   Input ~ 0
VCC
Text GLabel 3250 3000 0    60   Input ~ 0
GND
Text GLabel 3250 2500 0    60   Input ~ 0
GND
Wire Wire Line
	3250 2500 3600 2500
Wire Wire Line
	3250 3000 3600 3000
Text GLabel 8800 2800 2    60   Input ~ 0
VCC
Text GLabel 8800 3300 2    60   Input ~ 0
GND
Wire Wire Line
	8700 2800 8800 2800
Wire Wire Line
	8700 3300 8800 3300
Wire Wire Line
	5350 5300 5650 5300
Wire Wire Line
	5350 5200 5650 5200
Wire Wire Line
	5350 5100 5650 5100
Wire Wire Line
	5350 5000 5650 5000
Wire Wire Line
	5350 4900 5650 4900
Wire Wire Line
	5350 4800 5650 4800
Wire Wire Line
	5350 4700 5650 4700
Wire Wire Line
	5350 4600 5650 4600
Wire Wire Line
	3700 5300 4000 5300
Wire Wire Line
	3700 5200 4000 5200
Wire Wire Line
	3700 5100 4000 5100
Wire Wire Line
	3700 5000 4000 5000
Wire Wire Line
	3700 4900 4000 4900
Wire Wire Line
	3700 4800 4000 4800
Wire Wire Line
	3700 4700 4000 4700
Wire Wire Line
	3700 4600 4000 4600
Text Label 5650 4600 2    60   ~ 0
SEGDP
Text Label 5650 4700 2    60   ~ 0
SEGA
Text Label 5650 4800 2    60   ~ 0
SEGB
Text Label 5650 4900 2    60   ~ 0
SEGC
Text Label 5650 5000 2    60   ~ 0
SEGD
Text Label 5650 5100 2    60   ~ 0
SEGE
Text Label 5650 5200 2    60   ~ 0
SEGF
Text Label 5650 5300 2    60   ~ 0
SEGG
Text Label 3700 4600 0    60   ~ 0
DIG0
Text Label 3700 4700 0    60   ~ 0
DIG1
Text Label 3700 4800 0    60   ~ 0
DIG2
Text Label 3700 4900 0    60   ~ 0
DIG3
Text Label 3700 5000 0    60   ~ 0
DIG4
Text Label 3700 5100 0    60   ~ 0
DIG5
Text Label 3700 5200 0    60   ~ 0
DIG6
Text Label 3700 5300 0    60   ~ 0
DIG7
Wire Wire Line
	3300 2900 3600 2900
Wire Wire Line
	3300 2600 3600 2600
Wire Wire Line
	3300 3100 3600 3100
Wire Wire Line
	3300 2400 3600 2400
Wire Wire Line
	3300 2800 3600 2800
Wire Wire Line
	3300 2700 3600 2700
Wire Wire Line
	3300 3200 3600 3200
Wire Wire Line
	3300 2300 3600 2300
Text Label 3300 2300 0    60   ~ 0
DIG0
Text Label 3300 3200 0    60   ~ 0
DIG1
Text Label 3300 2700 0    60   ~ 0
DIG2
Text Label 3300 2800 0    60   ~ 0
DIG3
Text Label 3300 2400 0    60   ~ 0
DIG4
Text Label 3300 3100 0    60   ~ 0
DIG5
Text Label 3300 2600 0    60   ~ 0
DIG6
Text Label 3300 2900 0    60   ~ 0
DIG7
Wire Wire Line
	4800 2900 5100 2900
Wire Wire Line
	4800 3100 5100 3100
Wire Wire Line
	4800 2500 5100 2500
Wire Wire Line
	4800 2300 5100 2300
Wire Wire Line
	4800 2600 5100 2600
Wire Wire Line
	4800 3000 5100 3000
Wire Wire Line
	4800 3200 5100 3200
Wire Wire Line
	4800 2400 5100 2400
Text Label 5100 2400 2    60   ~ 0
SEGDP
Text Label 5100 3200 2    60   ~ 0
SEGA
Text Label 5100 3000 2    60   ~ 0
SEGB
Text Label 5100 2600 2    60   ~ 0
SEGC
Text Label 5100 2300 2    60   ~ 0
SEGD
Text Label 5100 2500 2    60   ~ 0
SEGE
Text Label 5100 3100 2    60   ~ 0
SEGF
Text Label 5100 2900 2    60   ~ 0
SEGG
$Comp
L CONN_01X02 P1
U 1 1 579A841D
P 7650 4800
F 0 "P1" H 7650 4950 50  0000 C CNN
F 1 "CONN_01X02" V 7750 4800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 7650 4800 50  0001 C CNN
F 3 "" H 7650 4800 50  0000 C CNN
	1    7650 4800
	1    0    0    -1  
$EndComp
Text GLabel 7250 4750 0    60   Input ~ 0
VCC
Text GLabel 7250 4850 0    60   Input ~ 0
GND
Wire Wire Line
	7250 4750 7450 4750
Wire Wire Line
	7250 4850 7450 4850
Wire Wire Line
	7350 4850 7350 4950
Connection ~ 7350 4850
Wire Wire Line
	7350 4750 7350 4650
Connection ~ 7350 4750
$Comp
L VCC #PWR01
U 1 1 579A854E
P 7350 4650
F 0 "#PWR01" H 7350 4500 50  0001 C CNN
F 1 "VCC" H 7350 4800 50  0000 C CNN
F 2 "" H 7350 4650 50  0000 C CNN
F 3 "" H 7350 4650 50  0000 C CNN
	1    7350 4650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 579A856C
P 7350 4950
F 0 "#PWR02" H 7350 4700 50  0001 C CNN
F 1 "GND" H 7350 4800 50  0000 C CNN
F 2 "" H 7350 4950 50  0000 C CNN
F 3 "" H 7350 4950 50  0000 C CNN
	1    7350 4950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
