all:
	nasm -f aout kernel_start.asm -o ks.o
	gcc -c kernel.c -o kernel.o
	ld -T linker.ld -o kernel.bin ks.o kernel.o
clean:
	rm *.o
run:
	qemu-system-i386 -kernel kernel.bin