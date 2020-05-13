CXX=g++
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXXFLAGS=-Wall -pedantic

OBJDIR=obj
SRCDIR=src
INCDIR=include

TARGET=knight_rider
CORES=main Manager Drawer Faction Piece Pawn Rook Bishop Knight Queen King Button Stats AudioPlayer
SRCS=$(patsubst %,$(SRCDIR)/%.cpp,$(CORES))
OBJS=$(patsubst %,$(OBJDIR)/%.o,$(CORES))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I/$(INCDIR) $(LIBFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJDIR)/*.o ./*.txt $(TARGET)
