HOME		= .
SRC			= $(HOME)
BIN			= $(HOME)
CPP_FILES 	= $(wildcard $(SRC)/*.cpp)
BIN_FILES 	= $(patsubst %.cpp, %, $(CPP_FILES))

all: $(BIN_FILES)
	@echo "[+] terminado!"

%: %.cpp
	@echo "- compilando $@..."
	@g++ -o $@ $<

.PHONY: clean
clean:
	@echo "[-] eliminando..."
	@rm -rf $(BIN_FILES)
