CC = cc
CFLAGS = -g

CXX = c++
CXXFLAGS = 

all: emb1.o	emb2

%.o : %.c
	$(CC) -c $(CFLAGS) $^ -o $@

% : %.cxx
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o emb1 emb2
 
