# directorios
HOME		= .
SRC    		= $(HOME)
BIN 		= $(HOME)

# ficheros
CPP_FILES 	= $(wildcard $(SRC)/*.cpp)
BIN_FILES 	= $(patsubst $(SRC)/%.cpp,$(BIN)/%,$(CPP_FILES))
TARGET		= main

# compilador
CXX			= g++
FLAGS		= -std=c++11 -Wall

# regla principal
all: $(BIN_FILES)

# crear directorio
$(BIN):
	@mkdir -r $(BIN)

# compilar cada fichero
%: %.cpp $(BIN)
	@echo "[+] compilando $@..."
	@$(CXX) -o $@ $< $(FLAGS)

# ejecutar el programa $(TARGET)
run: $(BIN)/$(TARGET)
	@$(BIN)/$(TARGET)

# ayuda
help:
	@echo "make				compila todo"
	@echo "make clean		borra los ejecutables"
	@echo "make run			ejecuta el programa $(TARGET) (ver macro TARGET)"
	@echo "make <nombre>	compila el programa <nombre>"
	@echo "make god			..."
	
god:
	@echo "y diles"
	@echo "que yo me se tus poses favoritas"
	@echo "que te hablo malo y que eso te excita"
	@echo "que te hago todo lo que necesitas"
	@echo "pa hacerte venir"

# limpiar
.PHONY: clean
clean:
	@echo "[-] eliminando..."
	@rm -rf $(BIN_FILES)
