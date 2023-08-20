################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MY\ FUNCTIONS/ADC_CONVERSION.cpp \
../MY\ FUNCTIONS/BUTTONS.cpp \
../MY\ FUNCTIONS/DELAY_ms.cpp \
../MY\ FUNCTIONS/INITIALIZATION.cpp \
../MY\ FUNCTIONS/PREPARE_MESSAGE.cpp \
../MY\ FUNCTIONS/PROCESS_DATA.cpp \
../MY\ FUNCTIONS/TRIGGER.cpp \
../MY\ FUNCTIONS/UART_TRANSMIT_STRING.cpp 

OBJS += \
./MY\ FUNCTIONS/ADC_CONVERSION.o \
./MY\ FUNCTIONS/BUTTONS.o \
./MY\ FUNCTIONS/DELAY_ms.o \
./MY\ FUNCTIONS/INITIALIZATION.o \
./MY\ FUNCTIONS/PREPARE_MESSAGE.o \
./MY\ FUNCTIONS/PROCESS_DATA.o \
./MY\ FUNCTIONS/TRIGGER.o \
./MY\ FUNCTIONS/UART_TRANSMIT_STRING.o 

CPP_DEPS += \
./MY\ FUNCTIONS/ADC_CONVERSION.d \
./MY\ FUNCTIONS/BUTTONS.d \
./MY\ FUNCTIONS/DELAY_ms.d \
./MY\ FUNCTIONS/INITIALIZATION.d \
./MY\ FUNCTIONS/PREPARE_MESSAGE.d \
./MY\ FUNCTIONS/PROCESS_DATA.d \
./MY\ FUNCTIONS/TRIGGER.d \
./MY\ FUNCTIONS/UART_TRANSMIT_STRING.d 


# Each subdirectory must supply rules for building sources it contributes
MY\ FUNCTIONS/ADC_CONVERSION.o: ../MY\ FUNCTIONS/ADC_CONVERSION.cpp MY\ FUNCTIONS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++17 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/DEVICE/STM32F1xx/Include" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/CORE" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/MY FUNCTIONS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -u _printf_float -fstack-usage -MMD -MP -MF"MY FUNCTIONS/ADC_CONVERSION.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY\ FUNCTIONS/BUTTONS.o: ../MY\ FUNCTIONS/BUTTONS.cpp MY\ FUNCTIONS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++17 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/DEVICE/STM32F1xx/Include" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/CORE" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/MY FUNCTIONS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -u _printf_float -fstack-usage -MMD -MP -MF"MY FUNCTIONS/BUTTONS.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY\ FUNCTIONS/DELAY_ms.o: ../MY\ FUNCTIONS/DELAY_ms.cpp MY\ FUNCTIONS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++17 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/DEVICE/STM32F1xx/Include" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/CORE" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/MY FUNCTIONS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -u _printf_float -fstack-usage -MMD -MP -MF"MY FUNCTIONS/DELAY_ms.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY\ FUNCTIONS/INITIALIZATION.o: ../MY\ FUNCTIONS/INITIALIZATION.cpp MY\ FUNCTIONS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++17 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/DEVICE/STM32F1xx/Include" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/CORE" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/MY FUNCTIONS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -u _printf_float -fstack-usage -MMD -MP -MF"MY FUNCTIONS/INITIALIZATION.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY\ FUNCTIONS/PREPARE_MESSAGE.o: ../MY\ FUNCTIONS/PREPARE_MESSAGE.cpp MY\ FUNCTIONS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++17 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/DEVICE/STM32F1xx/Include" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/CORE" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/MY FUNCTIONS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -u _printf_float -fstack-usage -MMD -MP -MF"MY FUNCTIONS/PREPARE_MESSAGE.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY\ FUNCTIONS/PROCESS_DATA.o: ../MY\ FUNCTIONS/PROCESS_DATA.cpp MY\ FUNCTIONS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++17 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/DEVICE/STM32F1xx/Include" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/CORE" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/MY FUNCTIONS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -u _printf_float -fstack-usage -MMD -MP -MF"MY FUNCTIONS/PROCESS_DATA.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY\ FUNCTIONS/TRIGGER.o: ../MY\ FUNCTIONS/TRIGGER.cpp MY\ FUNCTIONS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++17 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/DEVICE/STM32F1xx/Include" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/CORE" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/MY FUNCTIONS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -u _printf_float -fstack-usage -MMD -MP -MF"MY FUNCTIONS/TRIGGER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY\ FUNCTIONS/UART_TRANSMIT_STRING.o: ../MY\ FUNCTIONS/UART_TRANSMIT_STRING.cpp MY\ FUNCTIONS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++17 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/DEVICE/STM32F1xx/Include" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/Inc/CMSIS/CORE" -I"D:/YandexDisk/Projects/STM32/BluePill agony-3/MY FUNCTIONS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -u _printf_float -fstack-usage -MMD -MP -MF"MY FUNCTIONS/UART_TRANSMIT_STRING.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MY-20-FUNCTIONS

clean-MY-20-FUNCTIONS:
	-$(RM) ./MY\ FUNCTIONS/ADC_CONVERSION.d ./MY\ FUNCTIONS/ADC_CONVERSION.o ./MY\ FUNCTIONS/ADC_CONVERSION.su ./MY\ FUNCTIONS/BUTTONS.d ./MY\ FUNCTIONS/BUTTONS.o ./MY\ FUNCTIONS/BUTTONS.su ./MY\ FUNCTIONS/DELAY_ms.d ./MY\ FUNCTIONS/DELAY_ms.o ./MY\ FUNCTIONS/DELAY_ms.su ./MY\ FUNCTIONS/INITIALIZATION.d ./MY\ FUNCTIONS/INITIALIZATION.o ./MY\ FUNCTIONS/INITIALIZATION.su ./MY\ FUNCTIONS/PREPARE_MESSAGE.d ./MY\ FUNCTIONS/PREPARE_MESSAGE.o ./MY\ FUNCTIONS/PREPARE_MESSAGE.su ./MY\ FUNCTIONS/PROCESS_DATA.d ./MY\ FUNCTIONS/PROCESS_DATA.o ./MY\ FUNCTIONS/PROCESS_DATA.su ./MY\ FUNCTIONS/TRIGGER.d ./MY\ FUNCTIONS/TRIGGER.o ./MY\ FUNCTIONS/TRIGGER.su ./MY\ FUNCTIONS/UART_TRANSMIT_STRING.d ./MY\ FUNCTIONS/UART_TRANSMIT_STRING.o ./MY\ FUNCTIONS/UART_TRANSMIT_STRING.su

.PHONY: clean-MY-20-FUNCTIONS

