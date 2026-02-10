GREEN  := \033[0;32m
CYAN   := \033[0;36m
YELLOW := \033[0;33m
RESET  := \033[0m
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

# 3. PROGRAMS TO COMPILE
ALL := \
	71a
ASMS := $(addsuffix .s, $(ALL))

test-%: %
	@printf "  $(YELLOW)[TEST]$(RESET) Testing $<... "
	@# Executa, filtra o output para remover prompts e códigos do 'clear'
	@./varios < varios.in | tr -d '\r' | grep -E "Quantidade|Maior|Soma|Média" > varios.tmp
	@# Compara o resultado filtrado com o esperado
	@diff -u $<.expected $<.tmp > /dev/null; \
	if [ $$? -eq 0 ]; then \
		printf "$(GREEN)PASSOU$(RESET)\n"; \
		rm $<.tmp; \
	else \
		printf "$(RED)FALHOU$(RESET)\n"; \
		printf "  $(CYAN)Diferenças encontradas:$(RESET)\n"; \
		diff -u --color $<.expected $<.tmp; \
		exit 1; \
	fi
# 4. BUILD RULES
.PHONY: all print-all clean info

all: $(ALL) $(ASMS)

print-all:
	@echo $(ALL)

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
# Special case: Compile without strict warnings to observe Undefined Behavior
t1_undefined: t1_undefined.c
	$(CC) -std=c11 -O2 -g $(LDFLAGS) -o $@ $<

# Generic compilation rule
$(ALL): %: %.c
	@printf "  $(CYAN)[CC]$(RESET)  Compiling $<...\n"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<
	@printf "  $(GREEN)[OK]$(RESET)  Created $@\n"

#$(ASMS): %.s: %.c
#	@printf "  $(CYAN)[ASM]$(RESET)  Generating Assembly for $<...\n"
#	$(CC) $(CFLAGS) -S -fverbose-asm $< -o $@
#	@printf "  $(GREEN)[OK]$(RESET)  Created $@\n"

clean: ## Remove executables and backup files
	$(RM) -f $(ALL) *.o *~

# 5. FORMATTING & ANALYSIS TOOLS
ALL_INDENT := $(addprefix indent-, $(ALL))
ALL_TIDY   := $(addprefix tidy-, $(ALL))
ALL_CHECK  := $(addprefix check-, $(ALL))

.PHONY: indent-all tidy-all check-all

indent-all: $(ALL_INDENT)
$(ALL_INDENT): indent-%:
	indent -kr -nut -i2 $*.c
	$(RM) -f $*.c~

tidy-all: $(ALL_TIDY)
$(ALL_TIDY): tidy-%:
	clang-tidy $*.c -- $(CFLAGS)

check-all: $(ALL_CHECK)
$(ALL_CHECK): check-%:
	cppcheck --enable=warning,style,performance,portability --std=c11 --quiet $*.c

help: ## Show this help message
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-15s\033[0m %s\n", $$1, $$2}'
