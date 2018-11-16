CXX = g++
SRCS = food.cpp simulator.cpp
SRCS_NO_HEADER = main.cpp

OBJS = $(SRCS:.cpp=.o)
OBJS_NO_HEADER = $(SRCS_NO_HEADER:.cpp=.o)
TARGET = app.out

all: $(TARGET)

debug: $(TARGET_DEBUG)
	
clean:
	rm -f $(OBJS)
	rm -f $(OBJS_NO_HEADER)
	rm -f $(TARGET)

$(TARGET): $(OBJS) $(OBJS_NO_HEADER)
	$(CXX) -o $@ $(OBJS) $(OBJS_NO_HEADER)


$(OBJS): %.o:%.cpp %.h 

$(OBJS_NO_HEADER): %.o:%.cpp

