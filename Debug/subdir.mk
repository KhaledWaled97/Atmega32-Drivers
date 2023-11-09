################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Prog.c \
../DC_MOTOR_program.c \
../DIO_prog.c \
../EEPROM_program.c \
../EXTI_Prog.c \
../Interrupt_prog.c \
../LCD_prog.c \
../PWM_Prog.c \
../SPI_program.c \
../Servo_Program.c \
../Sevev_Seg_Prog.c \
../TIMER_program.c \
../TWI_Prog.c \
../UART_Prog.c \
../WDT_Prog.c \
../keypad_prog.c \
../main.c 

OBJS += \
./ADC_Prog.o \
./DC_MOTOR_program.o \
./DIO_prog.o \
./EEPROM_program.o \
./EXTI_Prog.o \
./Interrupt_prog.o \
./LCD_prog.o \
./PWM_Prog.o \
./SPI_program.o \
./Servo_Program.o \
./Sevev_Seg_Prog.o \
./TIMER_program.o \
./TWI_Prog.o \
./UART_Prog.o \
./WDT_Prog.o \
./keypad_prog.o \
./main.o 

C_DEPS += \
./ADC_Prog.d \
./DC_MOTOR_program.d \
./DIO_prog.d \
./EEPROM_program.d \
./EXTI_Prog.d \
./Interrupt_prog.d \
./LCD_prog.d \
./PWM_Prog.d \
./SPI_program.d \
./Servo_Program.d \
./Sevev_Seg_Prog.d \
./TIMER_program.d \
./TWI_Prog.d \
./UART_Prog.d \
./WDT_Prog.d \
./keypad_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


