################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include freertos/src/subdir.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: mutex_one_task_freertos_blinky_.axf

# Tool invocations
mutex_one_task_freertos_blinky_.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/zain/Documents/MCUXpresso_11.1.1_3241/workspace/lpc_chip_175x_6x/Debug" -L"/home/zain/Documents/MCUXpresso_11.1.1_3241/workspace/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="mutex_one_task_freertos_blinky_.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "freertos_blinky_Debug.ld" -o "mutex_one_task_freertos_blinky_.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) mutex_one_task_freertos_blinky_.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "mutex_one_task_freertos_blinky_.axf"; # arm-none-eabi-objcopy -v -O binary "mutex_one_task_freertos_blinky_.axf" "mutex_one_task_freertos_blinky_.bin" ; # checksum -p LPC1769 -d "mutex_one_task_freertos_blinky_.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
