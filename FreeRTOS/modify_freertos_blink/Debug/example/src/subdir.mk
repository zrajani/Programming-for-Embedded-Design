################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/cr_startup_lpc175x_6x.c \
../example/src/modify_freertos_blink.c \
../example/src/sysinit.c 

OBJS += \
./example/src/cr_startup_lpc175x_6x.o \
./example/src/modify_freertos_blink.o \
./example/src/sysinit.o 

C_DEPS += \
./example/src/cr_startup_lpc175x_6x.d \
./example/src/modify_freertos_blink.d \
./example/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -I"/home/zain/Documents/MCUXpresso_11.1.1_3241/workspace/lpc_chip_175x_6x/inc" -I"/home/zain/Documents/MCUXpresso_11.1.1_3241/workspace/lpc_board_nxp_lpcxpresso_1769/inc" -I"/home/zain/Documents/MCUXpresso_11.1.1_3241/workspace/modify_freertos_blink/example/inc" -I"/home/zain/Documents/MCUXpresso_11.1.1_3241/workspace/modify_freertos_blink/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


