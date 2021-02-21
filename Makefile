#CXX=clang++
CXX=g++

CXXFLAGS= -Wall -std=c++14 

BINARIES=dataProj testSort1 testSort2 testSort3 testSort4 testSort5

all: ${BINARIES}

tests: ${BINARIES}
	./testSort1
	./testSort2
	./testSort3
	./testSort4
	./testSort5

dataProj: rating.o dataAQ.o comboHospitalData.o hospitalData.o comboDemogData.o demogData.o parse.o  main.o
	${CXX} $^ -o $@

testSort1: rating.o testSort1.o dataAQ.o comboHospitalData.o hospitalData.o comboDemogData.o demogData.o parse.o  tddFuncs.o
	${CXX} $^ -o $@

testSort2: rating.o testSort2.o dataAQ.o comboHospitalData.o hospitalData.o comboDemogData.o demogData.o  parse.o tddFuncs.o
	${CXX} $^ -o $@

testSort3: rating.o testSort3.o dataAQ.o comboHospitalData.o hospitalData.o comboDemogData.o demogData.o  parse.o tddFuncs.o
	${CXX} $^ -o $@

testSort4: rating.o testSort4.o dataAQ.o comboHospitalData.o hospitalData.o comboDemogData.o demogData.o  parse.o tddFuncs.o
	${CXX} $^ -o $@

testSort5: rating.o testSort5.o dataAQ.o comboHospitalData.o hospitalData.o comboDemogData.o demogData.o  parse.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o 
