.global main

delay:
addi s5,s5,1;
bne s4,s5,delay;
jr x1;

.equ GPIO_BASE, 0x10012000


main:
li s5,0;
li s4,200000;
li t0,0x1;
la s1,GPIO_BASE;
slli s2,t0,22;
sw s2,8(s1); // enable gpio output on pin 19
slli s3,zero,22;
and s3,s3,s2;
loop:
    sw s2,0xc(s1); //write 1 to pin 19
    jal x1,delay;
    sw s3,0xc(s1);//write 0 to pin 19
    jal  delay;
    j loop;

