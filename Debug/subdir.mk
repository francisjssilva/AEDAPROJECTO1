################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../client.cpp \
../date.cpp \
../market.cpp \
../order.cpp \
../source.cpp \
../stock.cpp 

OBJS += \
./client.o \
./date.o \
./market.o \
./order.o \
./source.o \
./stock.o 

CPP_DEPS += \
./client.d \
./date.d \
./market.d \
./order.d \
./source.d \
./stock.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


