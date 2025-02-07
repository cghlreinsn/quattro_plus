CC=g++
#SRCDIR=.\source\
#OBJDIR=.\obj\
#ALLOBJ=$(OBJDIR)qp_quaternion.o

.\lib\quattro_plus.lib: .\obj\qp_quaternion.o .\lib
	ar rvs -o $@ .\obj\\*.o

.\obj\qp_quaternion.o: .\source\qp_quaternion.cpp .\source\qp_quaternion.h .\obj
	$(CC) -c .\source\qp_quaternion.cpp -o $@

.\obj:
	mkdir .\obj

.\lib:
	mkdir .\lib