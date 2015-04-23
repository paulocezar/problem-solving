
THRIFT_DIR = /opt/local/include/thrift
INC_DIR = /opt/local/include
LIB_DIR = /opt/local/lib

GEN_SRC = gen/simonsays_constants.cpp gen/simonsays_types.cpp gen/SimonSays.cpp

default: client

client: SSClient.cpp
	g++ -o game -I${INC_DIR} -I${THRIFT_DIR} -L${LIB_DIR} -lthrift SSClient.cpp ${GEN_SRC}

clean:
	$(RM) -r game