##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Responsable_production
ConfigurationName      :=Debug
WorkspacePath          :=/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian
ProjectPath            :=/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=nairo5913
Date                   :=29/05/2018
CodeLitePath           :=/home/nairo5913/.codelite
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
ObjectsFileList        :="Responsable_production.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell wx-config   --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)IHM 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)PocoDataODBC $(LibrarySwitch)PocoData $(LibrarySwitch)PocoFoundation 
ArLibs                 :=  "PocoDataODBC" "PocoData" "PocoFoundation" 
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
Objects0=$(IntermediateDirectory)/EvtFramePrincipal.cpp$(ObjectSuffix) $(IntermediateDirectory)/FramePrincipal.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/Client.cpp$(ObjectSuffix) $(IntermediateDirectory)/DataAnodisation.cpp$(ObjectSuffix) $(IntermediateDirectory)/EvtFrameApropos.cpp$(ObjectSuffix) $(IntermediateDirectory)/EvtFrameAide.cpp$(ObjectSuffix) $(IntermediateDirectory)/DonneesIHM.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production/EvtFramePrincipal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EvtFramePrincipal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EvtFramePrincipal.cpp$(DependSuffix): EvtFramePrincipal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EvtFramePrincipal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EvtFramePrincipal.cpp$(DependSuffix) -MM EvtFramePrincipal.cpp

$(IntermediateDirectory)/EvtFramePrincipal.cpp$(PreprocessSuffix): EvtFramePrincipal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EvtFramePrincipal.cpp$(PreprocessSuffix) EvtFramePrincipal.cpp

$(IntermediateDirectory)/FramePrincipal.cpp$(ObjectSuffix): FramePrincipal.cpp $(IntermediateDirectory)/FramePrincipal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production/FramePrincipal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FramePrincipal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FramePrincipal.cpp$(DependSuffix): FramePrincipal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FramePrincipal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FramePrincipal.cpp$(DependSuffix) -MM FramePrincipal.cpp

$(IntermediateDirectory)/FramePrincipal.cpp$(PreprocessSuffix): FramePrincipal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FramePrincipal.cpp$(PreprocessSuffix) FramePrincipal.cpp

$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix): MyApp.cpp $(IntermediateDirectory)/MyApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production/MyApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyApp.cpp$(DependSuffix): MyApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyApp.cpp$(DependSuffix) -MM MyApp.cpp

$(IntermediateDirectory)/MyApp.cpp$(PreprocessSuffix): MyApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyApp.cpp$(PreprocessSuffix) MyApp.cpp

$(IntermediateDirectory)/Client.cpp$(ObjectSuffix): Client.cpp $(IntermediateDirectory)/Client.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production/Client.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Client.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Client.cpp$(DependSuffix): Client.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Client.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Client.cpp$(DependSuffix) -MM Client.cpp

$(IntermediateDirectory)/Client.cpp$(PreprocessSuffix): Client.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Client.cpp$(PreprocessSuffix) Client.cpp

$(IntermediateDirectory)/DataAnodisation.cpp$(ObjectSuffix): DataAnodisation.cpp $(IntermediateDirectory)/DataAnodisation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production/DataAnodisation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DataAnodisation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DataAnodisation.cpp$(DependSuffix): DataAnodisation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DataAnodisation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DataAnodisation.cpp$(DependSuffix) -MM DataAnodisation.cpp

$(IntermediateDirectory)/DataAnodisation.cpp$(PreprocessSuffix): DataAnodisation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DataAnodisation.cpp$(PreprocessSuffix) DataAnodisation.cpp

$(IntermediateDirectory)/EvtFrameApropos.cpp$(ObjectSuffix): EvtFrameApropos.cpp $(IntermediateDirectory)/EvtFrameApropos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production/EvtFrameApropos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EvtFrameApropos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EvtFrameApropos.cpp$(DependSuffix): EvtFrameApropos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EvtFrameApropos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EvtFrameApropos.cpp$(DependSuffix) -MM EvtFrameApropos.cpp

$(IntermediateDirectory)/EvtFrameApropos.cpp$(PreprocessSuffix): EvtFrameApropos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EvtFrameApropos.cpp$(PreprocessSuffix) EvtFrameApropos.cpp

$(IntermediateDirectory)/EvtFrameAide.cpp$(ObjectSuffix): EvtFrameAide.cpp $(IntermediateDirectory)/EvtFrameAide.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production/EvtFrameAide.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EvtFrameAide.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EvtFrameAide.cpp$(DependSuffix): EvtFrameAide.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EvtFrameAide.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EvtFrameAide.cpp$(DependSuffix) -MM EvtFrameAide.cpp

$(IntermediateDirectory)/EvtFrameAide.cpp$(PreprocessSuffix): EvtFrameAide.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EvtFrameAide.cpp$(PreprocessSuffix) EvtFrameAide.cpp

$(IntermediateDirectory)/DonneesIHM.cpp$(ObjectSuffix): DonneesIHM.cpp $(IntermediateDirectory)/DonneesIHM.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Codage_Florian/Responsable_production/DonneesIHM.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DonneesIHM.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DonneesIHM.cpp$(DependSuffix): DonneesIHM.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DonneesIHM.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DonneesIHM.cpp$(DependSuffix) -MM DonneesIHM.cpp

$(IntermediateDirectory)/DonneesIHM.cpp$(PreprocessSuffix): DonneesIHM.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DonneesIHM.cpp$(PreprocessSuffix) DonneesIHM.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


