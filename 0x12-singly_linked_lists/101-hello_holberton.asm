global main
extern printf

section .data
    hello db "Hello, Holberton", 0
    format db "%s\n", 0

section .text
main:
    ; Set up stack frame
    push rbp
    mov rbp, rsp
    
    ; Pass the format string and hello string as arguments to printf
    mov rdi, format
    mov rsi, hello
    xor rax, rax
    call printf
    
    ; Clean up and return
    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret
