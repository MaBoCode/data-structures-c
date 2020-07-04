CC := gcc
CCFLAG := -lm -w
DBGFLAG := -g
CCOBJFLAG := $(CCFLAG) -c

BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src
DBG_PATH := debug

TARGET_NAME := main
TARGET := $(BIN_PATH)/$(TARGET_NAME)
TARGET_DEBUG := $(DBG_PATH)/$(TARGET_NAME)
MAIN_SRC := src/main.c

BIN := $(addprefix $(BIN_PATH)/, $(notdir $(basename $(BIN_PATH)/*)))
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_DEBUG := $(addprefix $(DBG_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

STACK_T_NAME := stack
STACK_TARGET := $(BIN_PATH)/$(STACK_T_NAME)
STACK_O := obj/stack.o

DISTCLEAN_LIST := $(OBJ) \
                  $(OBJ_DEBUG)
CLEAN_LIST := $(BIN) \
				$(TARGET) \
			  $(TARGET_DEBUG) \
			  $(DISTCLEAN_LIST)

default: all

$(TARGET): $(OBJ)
	@$(CC) $(CCFLAG) -o $@ $?

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	@$(CC) $(CCOBJFLAG) -o $@ $<

$(DBG_PATH)/%.o: $(SRC_PATH)/%.c*
	@$(CC) $(CCOBJFLAG) $(DBGFLAG) -o $@ $<

$(TARGET_DEBUG): $(OBJ_DEBUG)
	@$(CC) $(CCFLAG) $(DBGFLAG) $? -o $@

$(BIN_PATH)/%: $(OBJ_PATH)/%.o $(OBJ_PATH)/main.o
	@$(CC) $(CCFLAG) $(DBGFLAG) $? -o $@

$(STACK_TARGET): $(STACK_SRC)
	$(CC) $(CCFLAG) -o $@ $<

.PHONY: all
all: $(TARGET)

.PHONY: stack
stack: $(BIN_PATH)/stack
	@./$(BIN_PATH)/stack

.PHONY: hashtable
hashtable: $(BIN_PATH)/hashtable
	@./$(BIN_PATH)/hashtable

.PHONY: queue
queue: $(BIN_PATH)/queue
	@./$(BIN_PATH)/queue

.PHONY: rebuild
rebuild: clean all

.PHONY: debug
debug: $(TARGET_DEBUG)

.PHONY: clean
clean:
	@rm -f $(CLEAN_LIST)

.PHONY: distclean
distclean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)
