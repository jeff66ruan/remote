#---------
#
# cli Makefile
#
#
#----------
IDIR = -I. \
       -I../applib

remote: remote.c
	gcc -o remote remote.c -lremotecontrol -L../lib $(IDIR)

.PHONY: clean

clean:
	rm -f remote
