GREEN  := \033[0;32m
CYAN   := \033[0;36m
YELLOW := \033[0;33m
RESET  := \033[0m
TARGET = benchmark
SRCS := $(shell find . -name "*.c")
# 1. COMPILER & TOOLS DETECTION
CC      := $(shell command -v clang 2> /dev/null || command -v gcc 2> /dev/null)
ifeq ($(CC),)
    $(error "No C compiler found! Please install clang or gcc.")
endif

# 2. FLAG CONFIGURATION
CFLAGS  := -std=c11 -O2 -g -Wall -Wextra -Wpedantic -Wshadow -Wconversion
LDFLAGS := -lm

#LDFLAGS := $(shell echo 'int main(){}' | $(CC) -x c - -lm -o /dev/null > /dev/null 2>&1 && echo "-lm")

# Add color diagnostics based on compiler flavor
ifeq ($(shell $(CC) --version | grep -q clang && echo "clang"), clang)
    CFLAGS += -fcolor-diagnostics
else
    CFLAGS += -fdiagnostics-color=always
endif

ifeq ($(MODULE), mdc)
    HEADER = mdc.h
    SRCS = benchmark.c mdc1.c mdc2.c mdc_mod.c
    REQUIRED = mdc.h mdc1.c mdc2.c mdc_mod.c benchmark.c
    MSG = "Modo: MDC"
else ifeq ($(MODULE), fib)
    HEADER = fib.h
    SRCS = benchmark.c fib1.c fib2.c
    REQUIRED = fib.h fib1.c fib2.c benchmark.c
    MSG = "Modo: Fibonacci"
endif

OBJS = $(SRCS:.c=.o)
.PHONY: all clean check_files

all: check_files $(TARGET)

# Check_files genérico que lê a lista do módulo atual
check_files:
	@echo "A verificar ficheiros para [$(MSG)]..."
	@for file in $(REQUIRED); do \
		if [ ! -f $$file ]; then \
			echo ">> ERRO: Ficheiro '$$file' em falta para o modulo $(MODULE)!"; \
			exit 1; \
		fi; \
	done
	@echo "Ficheiros OK."

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)s
info: ## Show detected compiler and flags
	@echo "Detected CC:  $(CC)"
	@echo "LDFLAGS:      $(LDFLAGS)"
	@echo "CFLAGS:       $(CFLAGS)"
	@echo "--- System Info ---"
	@uname -a
	@echo "Compiler Version:"
	@$(CC) --version | head -n 1
	@echo "CPU Architecture:"
	@$(CC) -dumpmachine