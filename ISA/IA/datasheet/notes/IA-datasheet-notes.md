## 3.4.1 General-Purpose Registers
- **EAX** — Accumulator for operands and results data  
- **EAX** — Pointer to data in the DS segment  
- **EAX** — Counter for string and loop operations  
- **EAX** — I/O pointer  
- **EAX** — Pointer to data in the segment pointed to by the DS register; source pointer for string operations  
- **EAX** — Pointer to data (or destination) in the segment pointed to by the ES register; destination pointer for string operations  
- **EAX** — Stack pointer (in the SS segment)  
- **EAX** — Pointer to data on the stack (in the SS segment)  

## 3.5 INSTRUCTION POINTER
The instruction pointer (**EIP**) register contains the offset in the current code segment for the ***next*** instruction to be executed.

## 6.2.4.2 Return Instruction Pointer
Prior to branching to the first instruction of the called procedure, the CALL instruction pushes the address in the EIP register onto the current stack. This address is then called the return-instruction pointer and it points to the instruction where execution of the calling procedure should resume following a return from the called procedure. Upon returning from a called procedure, the RET instruction pops the return-instruction pointer from the stack back into the EIP register. Execution of the calling procedure then resumes.

The processor does not keep track of the location of the return-instruction pointer. It is thus up to the programmer to insure that stack pointer is pointing to the return-instruction pointer on the stack, prior to issuing a RET instruc-tion. A common way to reset the stack pointer to the point to the return-instruction pointer is to move the contents of the EBP register into the ESP register. If the EBP register is loaded with the stack pointer immediately following a procedure call, it should point to the return instruction pointer on the stack.
