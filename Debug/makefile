################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer\ 1/subdir.mk
-include MCAL/Timer\ 0/subdir.mk
-include MCAL/Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/Ultrasonic\ Sensor/subdir.mk
-include HAL/Servo\ Motor/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/IR_Sensor/subdir.mk
-include HAL/H_Bridge/subdir.mk
-include HAL/Buzzer/subdir.mk
-include Application/Control_Car/subdir.mk
-include Application/Autonomous_Car/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Robot_Car.lss \

FLASH_IMAGE += \
Robot_Car.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Robot_Car.elf secondary-outputs

# Tool invocations
Robot_Car.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Robot_Car.map -mmcu=atmega32 -o "Robot_Car.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Robot_Car.lss: Robot_Car.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Robot_Car.elf  >"Robot_Car.lss"
	@echo 'Finished building: $@'
	@echo ' '

Robot_Car.hex: Robot_Car.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Robot_Car.elf  "Robot_Car.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Robot_Car.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Robot_Car.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Robot_Car.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
