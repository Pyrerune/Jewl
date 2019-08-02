##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Jewl
ConfigurationName      :=Release
WorkspacePath          :=/home/sk/workspace/C++
ProjectPath            :=/home/sk/workspace/C++/Jewl
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=07/30/19
CodeLitePath           :=/home/sk/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Jewl.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_Interpreter.cc$(ObjectSuffix) $(IntermediateDirectory)/src_main.cc$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_Interpreter.cc$(ObjectSuffix): src/Interpreter.cc $(IntermediateDirectory)/src_Interpreter.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sk/workspace/C++/Jewl/src/Interpreter.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Interpreter.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Interpreter.cc$(DependSuffix): src/Interpreter.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Interpreter.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Interpreter.cc$(DependSuffix) -MM src/Interpreter.cc

$(IntermediateDirectory)/src_Interpreter.cc$(PreprocessSuffix): src/Interpreter.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Interpreter.cc$(PreprocessSuffix) src/Interpreter.cc

$(IntermediateDirectory)/src_main.cc$(ObjectSuffix): src/main.cc $(IntermediateDirectory)/src_main.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/sk/workspace/C++/Jewl/src/main.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cc$(DependSuffix): src/main.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cc$(DependSuffix) -MM src/main.cc

$(IntermediateDirectory)/src_main.cc$(PreprocessSuffix): src/main.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cc$(PreprocessSuffix) src/main.cc


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/
install:
	mv ./Release/Jewl ~/bin/jewl

