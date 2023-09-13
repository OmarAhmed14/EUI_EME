################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
HAL/LDR.obj: ../HAL/LDR.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="HAL/LDR.d_raw" --obj_directory="HAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/Ultrasonic.obj: ../HAL/Ultrasonic.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="HAL/Ultrasonic.d_raw" --obj_directory="HAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/dc_motor.obj: ../HAL/dc_motor.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="HAL/dc_motor.d_raw" --obj_directory="HAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/internal_temp_sensor.obj: ../HAL/internal_temp_sensor.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="HAL/internal_temp_sensor.d_raw" --obj_directory="HAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/lcd.obj: ../HAL/lcd.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="HAL/lcd.d_raw" --obj_directory="HAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/push_button.obj: ../HAL/push_button.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="HAL/push_button.d_raw" --obj_directory="HAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


