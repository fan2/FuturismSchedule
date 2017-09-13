- Pipeline stages  
- stage pipeline  

# ARM
## pipeline stage
参考 wiki [List of ARM microarchitectures](https://en.wikipedia.org/wiki/List_of_ARM_microarchitectures)：

ARM7T/ARMv4T/ARM7TDMI(-S)：3-stage pipeline  
ARM7EJ/ARMv5TEJ/ARM7EJ-S：5-stage pipeline  
ARM10E/ARMv5TE/ARM1020E：6-stage pipeline  
ARM11/ARMv6/ARM1136J(F)-S：8-stage pipeline  
ARM11/ARMv6T2/ARM1156T2(F)-S：9-stage pipeline  
Cortex-R/ARMv7-R/Cortex-R7：9-stage pipeline  
Cortex-A(32-bit)/ARMv7-A/Cortex-A7：8–10 stage pipeline  
Cortex-A(32-bit)/ARMv7-A/Cortex-A8：13-stage superscalar pipeline  
Cortex-A(32-bit)/ARMv7-A/Cortex-A15：15–24 stage pipeline  
Cortex-A(32-bit)/ARMv8-A/Cortex-A32：dual issue, in-order pipeline  
Cortex-A(64-bit)/ARMv8-A/Cortex-A57：3-way superscalar, deeply out-of-order pipeline  

参考 `DEN0013D_cortex_a_series_PG.pdf` 的 Table 2-3 Some properties of Cortex-A series processors 中的 **Pipeline stages** 行。

## misc.etc
`The ARM Instruction Set Architecture.ppt.pdf`

- P14 - The Original Instruction Pipeline  
- P15 - Pipeline changes for ARM9TDMI  
- P16 - Pipeline changes for  ARM10 vs. ARM11 Pipelines  

# MIPS
## MIPS_Architecture_MIPS32_InstructionSet_AFP_P_MD00086_06.05.pdf

### 2.1 Understanding the Instruction Fields
> Order of instructions necessary to guarantee correct execution. These ordering constraints avoid pipeline hazards for which some processors do not have hardware interlocks

### instruction
#### EHB
**Purpose**: Execution Hazard Barrier
To stop instruction execution until all execution hazards have been cleared.

This instruction alters the instruction issue behavior on a pipelined processor by stopping execution until all execution hazards have been cleared.

#### SYNC
Synchronize Sha

**Load/Store Datapath**: The portion of the processor which handles the load/store data requests coming from the processor pipeline and processes those requests within the cache and memory system hierarchy.

#### WAIT
The WAIT instruction is implemented by stalling the pipeline at the completion of the instruction and entering a lower power mode. The pipeline is restarted when an external event, such as an interrupt or external request occurs, and executi
on continues with the instruction following the WAIT instruction.

## MD00082-2B-MIPS32INT-AFP-06.01.pdf
***Appendix A: Pipeline Architecture.***

- A.1: Pipeline Stages and Execution Rates  
- A.2: Parallel Pipeline  
- A.3: Superpipeline  
- A.4: Superscalar Pipeline  