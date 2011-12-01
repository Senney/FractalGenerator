LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
OUTFILE="FractalGenerator"

OBJ = FractalGenerator.o SerpinskiTriangle.o KochSnowflake.o Fern.o

run: all
	./$(OUTFILE)

fractalGen: $(OBJ)
	g++ $(OBJ) $(LIBFLAGS) -o $(OUTFILE)
	
%.o: %.cpp
	g++ -o $@ -c $< $(LIBFLAGS)
	
all: fractalGen

clean:
	rm $(OBJ) $(OUTFILE)
