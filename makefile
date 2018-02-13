CC = g++  
# 可执行文件  
TARGET = test
#编译规则
CLAFF= -Wall
# C文件  
SRCS = main.cpp  ./image/Image.cpp ./serial/Serial.cpp ./PID/pid.cpp ./led/led.cpp
# 
INC= -I./serial -I./image -I./PID -I./led
VPATH =./serial:./image:./PID:./led
# 目标文件  
OBJS = $(SRCS:.cpp=.o)  
# 库文件  
DLIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -larmadillo -lwiringPi 
# 链接为可执行文件  
$(TARGET):$(OBJS)  
	$(CC) -o $@ $^ $(DLIBS)  
clean:  
	rm -rf $(OBJS) test 
# 编译规则 $@代表目标文件 $< 代表第一个依赖文件  
%.o:%.cpp  
	$(CC) $(CALFF) $(INC) -o $@ -c $<
