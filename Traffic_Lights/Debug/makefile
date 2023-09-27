################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/7-Segment/subdir.mk
-include APP/subdir.mk
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
Traffic_Lights.lss \

FLASH_IMAGE += \
Traffic_Lights.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Traffic_Lights.elf secondary-outputs

# Tool invocations
Traffic_Lights.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Traffic_Lights.map -mmcu=atmega32 -o "Traffic_Lights.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Traffic_Lights.lss: Traffic_Lights.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Traffic_Lights.elf  >"Traffic_Lights.lss"
	@echo 'Finished building: $@'
	@echo ' '

Traffic_Lights.hex: Traffic_Lights.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Traffic_Lights.elf  "Traffic_Lights.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Traffic_Lights.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Traffic_Lights.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Traffic_Lights.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
