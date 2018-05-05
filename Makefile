# --------------------------------------------------------
# USER SETTING
# --------------------------------------------------------

# コンパイラ
CXX := g++

# ターゲット名
TARGET := $(shell pwd | awk -F '/' '{print $$NF}').out

# ディレクトリ名
SRCDIR   := src
BUILDDIR := obj
BINDIR   := bin

# 拡張子名
SRCEXT := cpp
DEPEXT := d
OBJEXT := o

# コンパイル、リンクのオプション
CXXFLAGS  := -Wall -std=c++11
LDFLAGS   := -lSDL2 -lDxPortLib
INCFLAGS  := -I/usr/local/include
LINKFLAGS := -L/usr/local/lib -Wl,-rpath,/usr/local/lib

# --------------------------------------------------------
# DO NOT EDIT BELLOW THIS LINE
# --------------------------------------------------------

sources      := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
objects      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(subst $(SRCEXT),$(OBJEXT),$(sources)))
dependencies := $(subst .$(OBJEXT),.$(DEPEXT),$(objects))

# Default Make
all: $(BINDIR)/$(TARGET)

# clean
clean:
	@rm -rf $(BUILDDIR) $(BINDIR)

# 実行コマンド
go:
	@./$(BINDIR)/$(TARGET)

# オブジェクトファイルをリンクしてバイナリを生成
$(BINDIR)/$(TARGET): $(objects)
	@[ -d $(BINDIR) ] || mkdir -p $(BINDIR)
	$(strip $(CXX) -o $@ $^ $(LINKFLAGS) $(LDFLAGS))

# ソースファイルをコンパイルしてオブジェクトファイルを作成
# 同時に依存関係を自動抽出して.dファイルを保存
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@[ -d $(BUILDDIR) ] || mkdir -p $(BUILDDIR)
	$(strip $(CXX) $(CXXFLAGS) $(INCFLAGS) -c -MMD -o $@ $<)

# 依存関係が記述された.dファイルを読み込む
-include $(dependencies)

.PHONY: all clean go
