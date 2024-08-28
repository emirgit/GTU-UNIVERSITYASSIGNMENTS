OUT_DIR := out
SRCS := $(wildcard *.java)
CLS := $(SRCS:%.java=$(OUT_DIR)/%.class)
JC := javac
JCFLAGS := -d $(OUT_DIR)

.PHONY: all clean execute

all: $(OUT_DIR) $(CLS)
	@echo "All targets: $(CLS)"

$(OUT_DIR):
	@echo "Creating directory: $(OUT_DIR)"
	mkdir -p $(OUT_DIR)

$(OUT_DIR)/%.class: %.java | $(OUT_DIR)
	@echo "Compiling $< to $@"
	$(JC) $(JCFLAGS) $<

clean:
	@echo "Cleaning up..."
	rm -f $(OUT_DIR)/*.class
	rmdir $(OUT_DIR)

execute: $(OUT_DIR) $(CLS)
	@echo "Executing Java classes..."
	java -cp $(OUT_DIR) Main



