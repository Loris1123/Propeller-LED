#Author: https://github.com/Loris1123
#Created: 2015-05-19
#Description: CMake File to Build and Upload the project on an ATmega328 on an Arduino uno

#adapted from https://github.com/acristoffers/CMake-AVR/blob/master/Blink/CMakeLists.txt

cmake_minimum_required(VERSION 3.1)
project(PropellerLED C ASM)

SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

set(PROG_TYPE avrispmkII)
set(USBPORT usb)
set(PROG_ARGS -b 9600 -P ${USBPORT})

set(MCU atmega328p)
set(F_CPU 1000000UL)
set(BAUD 9600)
add_definitions(-DF_CPU=${F_CPU})

set(AVRC avr-gcc)
set(OBJCOPY avr-objcopy)
set(AVRDUDE avrdude)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER   ${AVRC})
set(CMAKE_ASM_COMPILER   ${AVRC})

set(SOURCE_FILES main.c)

# Compiler flags
set(CSTANDARD "-std=gnu99")
set(CDEBUG    "-gstabs -g -ggdb")
set(CWARN     "-Wall -Wstrict-prototypes -Wl,--gc-sections -Wl,--relax")
set(CTUNING   "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections")
set(COPT      "-Os -lm -lprintf_flt")
set(CMCU      "-mmcu=${MCU}")
set(CDEFS     "-DF_CPU=${F_CPU} -DBAUD=${BAUD}")

set(CFLAGS   "${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD} ${CTUNING}")

set(CMAKE_C_FLAGS   "${CFLAGS}")
set(CMAKE_ASM_FLAGS   "${CFLAGS}")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")
add_custom_target(hex   ALL     ${OBJCOPY} -R .eeprom -O ihex "${PROJECT_NAME}.elf" "${PROJECT_NAME}.hex")
add_custom_target(flash_arduino ALL ${AVRDUDE} -F -V -c avrispmkII -p ${MCU} -b 9600 -P ${USBPORT} -U flash:w:${PROJECT_NAME}.hex)