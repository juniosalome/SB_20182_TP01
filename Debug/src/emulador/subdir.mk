################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/emulador/func.c \
../src/emulador/main.c 

OBJS += \
./src/emulador/func.o \
./src/emulador/main.o 

C_DEPS += \
./src/emulador/func.d \
./src/emulador/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/emulador/%.o: ../src/emulador/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


