CC = gcc
LD = ld
AR = ar
OBJCOPY = objcopy
OBJDUMP = objdump


AFLAGS = 
CFLAGS = -I.. -L..
LDFLAGS = 
ARFLAGS = 
OBJDUMPFLAGS = -b binary -d
OBJCOPYFLAGS = 



displayAllFiles : $(addsuffix .c,$@) ../apue.h
	echo $(CLAG)
	$(CC) $(CFLAGS) $^ -o $@ 

displayAllFiles.bin : $(patsubst %.bin, %, $@)
	$(OBJCOPY) $(OBJCOPYFLAGS) -O binary $< $@

displayAllFiles.dis : $(patsubst %.dis, %.bin, $@)
	$(OBJDUMP) $(OBJDUMPFLAGS) $< > $@

clean:
	rm -f *.dis *.bin
