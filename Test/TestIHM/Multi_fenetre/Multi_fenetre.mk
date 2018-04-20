##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Multi_fenetre
ConfigurationName      :=Debug
WorkspacePath          :=/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Test
ProjectPath            :=/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Test/TestIHM/Multi_fenetre
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Florian PROVOST
Date                   :=20/04/2018
CodeLitePath           :=/home/ir2/fprovost/.codelite
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Multi_fenetre.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell wx-config   --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)IHM 
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
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/EvtFramePrincipal.cpp$(ObjectSuffix) $(IntermediateDirectory)/FramePrincipal.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/EvtDialogTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/EvtFenetre2.cpp$(ObjectSuffix) $(IntermediateDirectory)/EvtMyDialogApropos.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/EvtFramePrincipal.cpp$(ObjectSuffix): EvtFramePrincipal.cpp $(IntermediateDirectory)/EvtFramePrincipal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Test/TestIHM/Multi_fenetre/EvtFramePrincipal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EvtFramePrincipal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EvtFramePrincipal.cpp$(DependSuffix): EvtFramePrincipal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EvtFramePrincipal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EvtFramePrincipal.cpp$(DependSuffix) -MM EvtFramePrincipal.cpp

$(IntermediateDirectory)/EvtFramePrincipal.cpp$(PreprocessSuffix): EvtFramePrincipal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EvtFramePrincipal.cpp$(PreprocessSuffix) EvtFramePrincipal.cpp

$(IntermediateDirectory)/FramePrincipal.cpp$(ObjectSuffix): FramePrincipal.cpp $(IntermediateDirectory)/FramePrincipal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Test/TestIHM/Multi_fenetre/FramePrincipal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FramePrincipal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FramePrincipal.cpp$(DependSuffix): FramePrincipal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FramePrincipal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FramePrincipal.cpp$(DependSuffix) -MM FramePrincipal.cpp

$(IntermediateDirectory)/FramePrincipal.cpp$(PreprocessSuffix): FramePrincipal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FramePrincipal.cpp$(PreprocessSuffix) FramePrincipal.cpp

$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix): MyApp.cpp $(IntermediateDirectory)/MyApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Test/TestIHM/Multi_fenetre/MyApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyApp.cpp$(DependSuffix): MyApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyApp.cpp$(DependSuffix) -MM MyApp.cpp

$(IntermediateDirectory)/MyApp.cpp$(PreprocessSuffix): MyApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyApp.cpp$(PreprocessSuffix) MyApp.cpp

$(IntermediateDirectory)/EvtDialogTest.cpp$(ObjectSuffix): EvtDialogTest.cpp $(IntermediateDirectory)/EvtDialogTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Test/TestIHM/Multi_fenetre/EvtDialogTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EvtDialogTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EvtDialogTest.cpp$(DependSuffix): EvtDialogTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EvtDialogTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EvtDialogTest.cpp$(DependSuffix) -MM EvtDialogTest.cpp

$(IntermediateDirectory)/EvtDialogTest.cpp$(PreprocessSuffix): EvtDialogTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EvtDialogTest.cpp$(PreprocessSuffix) EvtDialogTest.cpp

$(IntermediateDirectory)/EvtFenetre2.cpp$(ObjectSuffix): EvtFenetre2.cpp $(IntermediateDirectory)/EvtFenetre2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Test/TestIHM/Multi_fenetre/EvtFenetre2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EvtFenetre2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EvtFenetre2.cpp$(DependSuffix): EvtFenetre2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EvtFenetre2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EvtFenetre2.cpp$(DependSuffix) -MM EvtFenetre2.cpp

$(IntermediateDirectory)/EvtFenetre2.cpp$(PreprocessSuffix): EvtFenetre2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EvtFenetre2.cpp$(PreprocessSuffix) EvtFenetre2.cpp

$(IntermediateDirectory)/EvtMyDialogApropos.cpp$(ObjectSuffix): EvtMyDialogApropos.cpp $(IntermediateDirectory)/EvtMyDialogApropos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Test/TestIHM/Multi_fenetre/EvtMyDialogApropos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EvtMyDialogApropos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EvtMyDialogApropos.cpp$(DependSuffix): EvtMyDialogApropos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EvtMyDialogApropos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EvtMyDialogApropos.cpp$(DependSuffix) -MM EvtMyDialogApropos.cpp

$(IntermediateDirectory)/EvtMyDialogApropos.cpp$(PreprocessSuffix): EvtMyDialogApropos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EvtMyDialogApropos.cpp$(PreprocessSuffix) EvtMyDialogApropos.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


