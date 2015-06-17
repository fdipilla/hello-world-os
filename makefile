all:
	nasm -f aout kernel_start.asm -o ks.o
	gcc -m32 -c kernel.c -o kernel.o
	ld -melf_i386 -T linker.ld -o kernel.bin ks.o kernel.o
clean:
	rm *.o
	rm kernel.bin
run:
	qemu-system-i386 -kernel kernel.bin