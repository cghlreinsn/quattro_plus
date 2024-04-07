CC=g++
#SRCDIR=.\source\
#OBJDIR=.\obj\
#ALLOBJ=$(OBJDIR)qp_quaternion.o

quattro_plus\lib\quattro_plus.lib: .\obj\qp_quaternion.o
	ar rvs -o $@ .\obj\\*.o

.\obj\qp_quaternion.o: .\source\qp_quaternion.cpp .\source\qp_quaternion.h
	$(CC) -c .\source\qp_quaternion.cpp -o $@
