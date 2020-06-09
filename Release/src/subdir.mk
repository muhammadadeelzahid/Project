################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bullet.cpp \
../src/Collision.cpp \
../src/Interface.cpp \
../src/Mines.cpp \
../src/Shape.cpp \
../src/Tank.cpp \
../src/TankDestroyed.cpp \
../src/Timer.cpp \
../src/Wall.cpp \
../src/main.cpp \
../src/stats.cpp 

OBJS += \
./src/Bullet.o \
./src/Collision.o \
./src/Interface.o \
./src/Mines.o \
./src/Shape.o \
./src/Tank.o \
./src/TankDestroyed.o \
./src/Timer.o \
./src/Wall.o \
./src/main.o \
./src/stats.o 

CPP_DEPS += \
./src/Bullet.d \
./src/Collision.d \
./src/Interface.d \
./src/Mines.d \
./src/Shape.d \
./src/Tank.d \
./src/TankDestroyed.d \
./src/Timer.d \
./src/Wall.d \
./src/main.d \
./src/stats.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


