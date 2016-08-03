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
Text Label 5650 4600 2    60   ~ 0
COL1
Text Label 5650 4700 2    60   ~ 0
COL2
Text Label 5650 4800 2    60   ~ 0
COL3
Text Label 5650 4900 2    60   ~ 0
COL4
Text Label 5650 5000 2    60   ~ 0
COL5
Text Label 5650 5100 2    60   ~ 0
COL6
Text Label 5650 5200 2    60   ~ 0
COL7
Text Label 5650 5300 2    60   ~ 0
COL8
Text Label 3700 4600 0    60   ~ 0
ROW1
Text Label 3700 4700 0    60   ~ 0
ROW2
Text Label 3700 4800 0    60   ~ 0
ROW3
Text Label 3700 4900 0    60   ~ 0
ROW4
Text Label 3700 5000 0    60   ~ 0
ROW5
Text Label 3700 5100 0    60   ~ 0
ROW6
Text Label 3700 5200 0    60   ~ 0
ROW7
Text Label 3700 5300 0    60   ~ 0
ROW8
$Comp
L CONN_01X02 P1
U 1 1 579A841D
P 8200 4750
F 0 "P1" H 8200 4900 50  0000 C CNN
F 1 "CONN_01X02" V 8300 4750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 8200 4750 50  0001 C CNN
F 3 "" H 8200 4750 50  0000 C CNN
	1    8200 4750
	1    0    0    -1  
$EndComp
Text GLabel 7500 4600 0    60   Input ~ 0
VCC
Text GLabel 7500 4900 0    60   Input ~ 0
GND
$Comp
L ATMEGA328-P IC1
U 1 1 57A2427A
P 4750 2700
F 0 "IC1" H 4000 3950 50  0000 L BNN
F 1 "ATMEGA328-P" H 5150 1300 50  0000 L BNN
F 2 "Housings_DIP:DIP-28_W7.62mm_LongPads" H 4750 2700 50  0000 C CIN
F 3 "" H 4750 2700 50  0000 C CNN
	1    4750 2700
	1    0    0    -1  
$EndComp
Text Label 6050 2650 2    60   ~ 0
COL1
Text Label 6050 3400 2    60   ~ 0
COL2
Text Label 6050 3500 2    60   ~ 0
COL3
Text Label 6050 1800 2    60   ~ 0
COL4
Text Label 6050 3800 2    60   ~ 0
COL5
Text Label 6050 2450 2    60   ~ 0
COL6
Text Label 6050 2850 2    60   ~ 0
COL7
Text Label 6050 2950 2    60   ~ 0
COL8
Text Label 6050 1700 2    60   ~ 0
ROW1
Text Label 6050 2750 2    60   ~ 0
ROW2
Text Label 6050 1600 2    60   ~ 0
ROW3
Text Label 6050 2550 2    60   ~ 0
ROW4
Text Label 6050 3200 2    60   ~ 0
ROW5
Text Label 6050 3900 2    60   ~ 0
ROW6
Text Label 6050 3300 2    60   ~ 0
ROW7
Text Label 6050 3700 2    60   ~ 0
ROW8
Text GLabel 3650 3700 0    60   Input ~ 0
GND
$Comp
L CP C2
U 1 1 57A24D52
P 3700 3200
F 0 "C2" H 3725 3300 50  0000 L CNN
F 1 "100uF" H 3725 3100 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L6_P2.5" H 3738 3050 50  0001 C CNN
F 3 "" H 3700 3200 50  0000 C CNN
	1    3700 3200
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 57A24E82
P 6300 3050
F 0 "R1" V 6380 3050 50  0000 C CNN
F 1 "10k" V 6300 3050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 6230 3050 50  0001 C CNN
F 3 "" H 6300 3050 50  0000 C CNN
	1    6300 3050
	0    1    1    0   
$EndComp
Text GLabel 6600 3050 2    60   Input ~ 0
VCC
$Comp
L Crystal Y1
U 1 1 57A250DA
P 6700 2300
F 0 "Y1" H 6700 2450 50  0000 C CNN
F 1 "16MHz" H 6700 2150 50  0000 C CNN
F 2 "Crystals:Crystal_HC50-U_Vertical" H 6700 2300 50  0001 C CNN
F 3 "" H 6700 2300 50  0000 C CNN
	1    6700 2300
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 57A25154
P 6450 2450
F 0 "C1" H 6475 2550 50  0000 L CNN
F 1 "22pF" H 6475 2350 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 6488 2300 50  0001 C CNN
F 3 "" H 6450 2450 50  0000 C CNN
	1    6450 2450
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 57A251BC
P 6950 2450
F 0 "C3" H 6975 2550 50  0000 L CNN
F 1 "22pF" H 6975 2350 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 6988 2300 50  0001 C CNN
F 3 "" H 6950 2450 50  0000 C CNN
	1    6950 2450
	1    0    0    -1  
$EndComp
Text GLabel 7600 2600 2    60   Input ~ 0
VCC
Text GLabel 3550 2000 0    60   Input ~ 0
VCC
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
Wire Wire Line
	8000 4600 8000 4700
Wire Wire Line
	8000 4900 8000 4800
Wire Wire Line
	7500 4600 8000 4600
Wire Wire Line
	5750 2950 6050 2950
Wire Wire Line
	5750 2850 6050 2850
Wire Wire Line
	5750 2450 6050 2450
Wire Wire Line
	5750 3800 6050 3800
Wire Wire Line
	5750 1800 6050 1800
Wire Wire Line
	5750 3500 6050 3500
Wire Wire Line
	5750 3400 6050 3400
Wire Wire Line
	5750 2650 6050 2650
Wire Wire Line
	6050 3700 5750 3700
Wire Wire Line
	6050 3300 5750 3300
Wire Wire Line
	6050 3900 5750 3900
Wire Wire Line
	6050 3200 5750 3200
Wire Wire Line
	6050 2550 5750 2550
Wire Wire Line
	6050 1600 5750 1600
Wire Wire Line
	6050 2750 5750 2750
Wire Wire Line
	6050 1700 5750 1700
Wire Wire Line
	3850 3700 3850 3900
Wire Wire Line
	7500 4900 8000 4900
Wire Wire Line
	5750 3050 6150 3050
Wire Wire Line
	6600 3050 6450 3050
Wire Wire Line
	6950 2300 6850 2300
Wire Wire Line
	5750 2300 6550 2300
Wire Wire Line
	6450 2600 7600 2600
Connection ~ 6450 2300
Wire Wire Line
	5750 2200 6450 2200
Wire Wire Line
	6450 2200 6450 2100
Wire Wire Line
	6450 2100 6950 2100
Wire Wire Line
	6950 2100 6950 2300
Connection ~ 6950 2600
Wire Wire Line
	3850 1600 3850 2000
Wire Wire Line
	3850 2000 3550 2000
Connection ~ 3850 1900
Wire Wire Line
	3650 3700 3850 3700
Connection ~ 3850 3800
Wire Wire Line
	3700 3350 3700 3700
Connection ~ 3700 3700
Wire Wire Line
	3700 3050 3700 2000
Connection ~ 3700 2000
$EndSCHEMATC
