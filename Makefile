CC=g++
#SRCDIR=.\source\
#OBJDIR=.\obj\
#ALLOBJ=$(OBJDIR)qp_quaternion.o

.\lib\quattro_plus.lib: .\obj\qp_quaternion.o .\lib
	ar rvs -o $@ .\obj\qp_quaternion.o

.\obj\qp_quaternion.o: .\source\qp_quaternion.cpp .\include\qp_quaternion.h .\obj
	$(CC) -c .\source\qp_quaternion.cpp -o $@

.\obj:
	mkdir .\obj

.\lib:
	mkdir .\lib