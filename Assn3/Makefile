CXX = g++
SRCS = game.cpp player.cpp word.cpp
SRCS_NO_HEADER = main.cpp
LOG = log.txt

OBJS = $(SRCS:.cpp=.o)
OBJS_NO_HEADER = $(SRCS_NO_HEADER:.cpp=.o)
OBJS_DEBUG = $(OBJS:.o=.dbg.o)
OBJS_DEBUG_NO_HEADER = $(OBJS_NO_HEADER:.o=.dbg.o)
TARGET_DEBUG = debug.out
TARGET = app.out

all: $(TARGET)

debug: $(TARGET_DEBUG)
	
clean:
	rm -f $(OBJS)
	rm -f $(OBJS_NO_HEADER)
	rm -f $(OBJS_DEBUG)
	rm -f $(OBJS_DEBUG_NO_HEADER)
	rm -f $(TARGET_DEBUG)
	rm -f $(TARGET)
	rm -f $(LOG)

$(TARGET): $(OBJS) $(OBJS_NO_HEADER)
	$(CXX) -o $@ $(OBJS) $(OBJS_NO_HEADER)

$(TARGET_DEBUG): $(OBJS_DEBUG) $(OBJS_DEBUG_NO_HEADER)
	$(CXX) -g -o $(TARGET_DEBUG) $(OBJS_DEBUG) $(OBJS_DEBUG_NO_HEADER)

$(OBJS): %.o:%.cpp %.h 

$(OBJS_NO_HEADER): %.o:%.cpp

$(OBJS_DEBUG): %.dbg.o:%.cpp %.h 
	$(CXX) -c -g -DDEBUG_MODE -o $@ $*.cpp

$(OBJS_DEBUG_NO_HEADER): %.dbg.o:%.cpp
	$(CXX) -c -g -DDEBUG_MODE -o $@ $*.cpp
