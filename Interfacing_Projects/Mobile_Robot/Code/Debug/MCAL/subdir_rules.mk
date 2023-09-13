################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO.obj: ../MCAL/DIO.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="MCAL/DIO.d_raw" --obj_directory="MCAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MCAL/GPTM_Program.obj: ../MCAL/GPTM_Program.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="MCAL/GPTM_Program.d_raw" --obj_directory="MCAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MCAL/NVIC.obj: ../MCAL/NVIC.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="MCAL/NVIC.d_raw" --obj_directory="MCAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MCAL/PWM.obj: ../MCAL/PWM.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="MCAL/PWM.d_raw" --obj_directory="MCAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MCAL/Systick_program.obj: ../MCAL/Systick_program.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="MCAL/Systick_program.d_raw" --obj_directory="MCAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MCAL/adc.obj: ../MCAL/adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/OS" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/HAL" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/LIB" --include_path="C:/Users/ZYZ/ccs_workspace/Car_Project_v2/MCAL" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.11.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="MCAL/adc.d_raw" --obj_directory="MCAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


