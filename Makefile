CXX          = g++
OPTIMIZATION = -O3
WARNINGS     = -Wall -Wextra -Wpedantic
PRODUCT      = leet

ifndef N
	N = -1
endif

all:
	$(CXX) leet.cpp -I. -D SOLUTION=\"solutions/$(N).hpp\" $(WARNINGS) $(OPTIMIZATION) -o $(PRODUCT)

clean:
	rm -f $(PRODUCT)