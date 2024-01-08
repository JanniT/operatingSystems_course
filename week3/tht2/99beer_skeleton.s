.section .rodata
msg1: .string " bottles of beer on the wall, "
msg2: .string " bottles of beer.\n"
msg9: .string "Take one down and pass it around, %ld "
msg3: .string " bottles of beer on the wall.\n"
msg4: .string "%ld"
msg5: .string "\n"

.data
bottlesCount: .quad 99

.text
.global main
.type main, @function

main:
  pushq %rbp
  movq %rsp, %rbp

  beer_loop:
    leaq msg4(%rip), %rdi
    movq bottlesCount(%rip), %rsi
    movq $0, %rax
    call printf@PLT

    leaq msg1(%rip), %rdi
    movq bottlesCount(%rip), %rsi
    movq $0, %rax
    call printf@PLT

    leaq msg4(%rip), %rdi
    movq bottlesCount(%rip), %rsi
    movq $0, %rax
    call printf@PLT

    leaq msg2(%rip), %rdi
    call printf@PLT

    leaq msg9(%rip), %rdi
    subq $1, bottlesCount(%rip)
    movq bottlesCount(%rip), %rsi
    movq $0, %rax
    call printf@PLT

    leaq msg3(%rip), %rdi
    call printf@PLT

    cmpq $95, bottlesCount(%rip)
    jge beer_loop

  end_program:
    movl $0, %eax
    leave
    ret $0
