- Endianness  
- endian  
- little-endian and big-endian  

## datasheet
### IA
`325462-sdm-vol-1-2abcd-3abcd.pdf`

- 1.3.1 Bit and Byte Order  

> Figure 1-1. Bit and Byte Order  

- 12.13.1 Little-Endian Architecture and Big-Endian Specification (FIPS 197)

指令：BSWAP—Byte Swap

> The MOVBE instruction is provided for swapping the bytes on a read from memory or on a write to memory; thus providing support for converting little-endian values to big-endian format and vice versa.

### ARM
`DDI0406C_c_armv7(A&R)_arm.pdf`

- A2.5.3 Endianness mapping register, ENDIANSTATE

> ARMv7-A and ARMv7-R support configuration between little-endian and big-endian interpretations of data memory.  
> The endianness is controlled by **ENDIANSTATE**.  

- A3.3 **Endian support**  

`DEN0013D_cortex_a_series_PG.pdf`

- 14.1 Endianness 

### MIPS
`MD00082-2B-MIPS32INT-AFP-06.01.pdf`

- 4.4 Byte Ordering and Endianness
