################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Bloco.cpp \
../Buraco.cpp \
../Cenario.cpp \
../Jogo.cpp \
../Piso.cpp \
../Ponto.cpp \
../Precipicio.cpp \
../principal.cpp 

OBJS += \
./Bloco.o \
./Buraco.o \
./Cenario.o \
./Jogo.o \
./Piso.o \
./Ponto.o \
./Precipicio.o \
./principal.o 

CPP_DEPS += \
./Bloco.d \
./Buraco.d \
./Cenario.d \
./Jogo.d \
./Piso.d \
./Ponto.d \
./Precipicio.d \
./principal.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


