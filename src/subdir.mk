################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Board.cpp \
../src/Deck.cpp \
../src/Feature.cpp \
../src/Meeple.cpp \
../src/Player.cpp \
../src/Tile.cpp \
../src/client.cpp

OBJS += \
./src/Board.o \
./src/Deck.o \
./src/Feature.o \
./src/Meeple.o \
./src/Player.o \
./src/Tile.o \
./src/client.o

CPP_DEPS += \
./src/Board.d \
./src/Deck.d \
./src/Feature.d \
./src/Meeple.d \
./src/Player.d \
./src/Tile.d


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


