ROMTITLE := renderer
BUILD    := build
TARGET   := $(notdir $(CURDIR))
SOURCES  := src
INCLUDE  := include
CFLAGS   := -I/usr/local/include/SDL2 -D_THREAD_SAFE -flto
CXXFLAGS := $(CFLAGS) -std=c++20 -msse4.1 -O2 -ffast-math
EXTTOOL  :=
LIBS     := -L/usr/local/lib -lSDL2



OUTPUT   := $(CURDIR)/$(TARGET)

.PHONY: all clean

all: $(ROMTITLE)

#	@[ -d $(BUILD) ] || mkdir -p $(BUILD)
# 	@$(EXTTOOL)
# 	@$(MAKE) --no-print-directory 

$(BUILD):
	@mkdir $(BUILD)

$(INCLUDE):
	@mkdir $(INCLUDE)

$(ROMTITLE): $(patsubst $(SOURCES)/%.cpp,$(BUILD)/%.o,$(wildcard $(SOURCES)/*.cpp)) $(patsubst $(SOURCES)/%.c,$(BUILD)/%.o,$(wildcard $(SOURCES)/*.c))
#	@echo $?
	@$(CXX) -o $(ROMTITLE) $(patsubst $(SOURCES)/%.cpp,$(BUILD)/%.o,$(wildcard $(SOURCES)/*.cpp)) $(LIBS)
	

$(BUILD)/%.o: $(SOURCES)/%.cpp $(INCLUDE) $(BUILD)
	@$(CXX) $(CXXFLAGS) $< -o $@ -I $(INCLUDE) -c
	@echo $(<:$(SOURCES)/%=%)

clean:
	@rm -rf $(BUILD) $(ROMTITLE)
	@echo clean ...