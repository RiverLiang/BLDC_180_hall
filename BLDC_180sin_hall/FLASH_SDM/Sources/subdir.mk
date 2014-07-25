################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/MC33927.c" \
"../Sources/ParamsControl.c" \
"../Sources/ParamsMotor.c" \
"../Sources/ParamsSystem.c" \
"../Sources/Peripheral.c" \
"../Sources/ProcessorExpert.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/MC33927.c \
../Sources/ParamsControl.c \
../Sources/ParamsMotor.c \
../Sources/ParamsSystem.c \
../Sources/Peripheral.c \
../Sources/ProcessorExpert.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/MC33927_c.obj \
./Sources/ParamsControl_c.obj \
./Sources/ParamsMotor_c.obj \
./Sources/ParamsSystem_c.obj \
./Sources/Peripheral_c.obj \
./Sources/ProcessorExpert_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/MC33927_c.obj" \
"./Sources/ParamsControl_c.obj" \
"./Sources/ParamsMotor_c.obj" \
"./Sources/ParamsSystem_c.obj" \
"./Sources/Peripheral_c.obj" \
"./Sources/ProcessorExpert_c.obj" \

C_DEPS += \
./Sources/Events_c.d \
./Sources/MC33927_c.d \
./Sources/ParamsControl_c.d \
./Sources/ParamsMotor_c.d \
./Sources/ParamsSystem_c.d \
./Sources/Peripheral_c.d \
./Sources/ProcessorExpert_c.d \

C_DEPS_QUOTED += \
"./Sources/Events_c.d" \
"./Sources/MC33927_c.d" \
"./Sources/ParamsControl_c.d" \
"./Sources/ParamsMotor_c.d" \
"./Sources/ParamsSystem_c.d" \
"./Sources/Peripheral_c.d" \
"./Sources/ProcessorExpert_c.d" \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/MC33927_c.obj \
./Sources/ParamsControl_c.obj \
./Sources/ParamsMotor_c.obj \
./Sources/ParamsSystem_c.obj \
./Sources/Peripheral_c.obj \
./Sources/ProcessorExpert_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/Events.args" -o "Sources/Events_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/MC33927_c.obj: ../Sources/MC33927.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/MC33927.args" -o "Sources/MC33927_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ParamsControl_c.obj: ../Sources/ParamsControl.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/ParamsControl.args" -o "Sources/ParamsControl_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ParamsMotor_c.obj: ../Sources/ParamsMotor.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/ParamsMotor.args" -o "Sources/ParamsMotor_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ParamsSystem_c.obj: ../Sources/ParamsSystem.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/ParamsSystem.args" -o "Sources/ParamsSystem_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Peripheral_c.obj: ../Sources/Peripheral.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/Peripheral.args" -o "Sources/Peripheral_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert_c.obj: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/ProcessorExpert.args" -o "Sources/ProcessorExpert_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


