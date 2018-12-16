CXX ?= g++
CXXFLAGS = -Wall


all: test libwrappedU64.so

analytic.o: analytic.cpp analytic.h
	$(CXX) $(CXXFLAGS) -fPIC -o $@ -c $<

libanalytic.so: analytic.o
	$(CXX) $(CXXFLAGS) -fPIC -shared -o $@ $<

libwrappedU64.so: wrappedU.cpp wrappedUcclibql.c libanalytic.so
	$(CXX) $(CXXFLAGS) -fPIC -nostartfiles -shared -pthread -o $@ wrappedU.cpp wrappedUcclibql.c -L. -lanalytic -m64 -lm -ldl -lstdc++

test: test.cpp libanalytic.so
	$(CXX) $(CXXFLAGS) -o $@ $< -L. -lanalytic

clean:
	rm -rf analytic.o libanalytic.so libwrappedU64.so test
