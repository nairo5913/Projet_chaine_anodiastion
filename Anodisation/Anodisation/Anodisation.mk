##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Anodisation
ConfigurationName      :=Debug
WorkspacePath          :=/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation
ProjectPath            :=/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=nairo5913
Date                   :=09/06/2018
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
ObjectsFileList        :="Anodisation.txt"
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
Objects0=$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/BdD_DataAnodisation.cpp$(ObjectSuffix) $(IntermediateDirectory)/BdD_DonneesIHM.cpp$(ObjectSuffix) $(IntermediateDirectory)/Client_Client.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_FramePrincipal.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix): MyApp.cpp $(IntermediateDirectory)/MyApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation/MyApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyApp.cpp$(DependSuffix): MyApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyApp.cpp$(DependSuffix) -MM MyApp.cpp

$(IntermediateDirectory)/MyApp.cpp$(PreprocessSuffix): MyApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyApp.cpp$(PreprocessSuffix) MyApp.cpp

$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(ObjectSuffix): BdD/DataAnodisation.cpp $(IntermediateDirectory)/BdD_DataAnodisation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation/BdD/DataAnodisation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(DependSuffix): BdD/DataAnodisation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(DependSuffix) -MM BdD/DataAnodisation.cpp

$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(PreprocessSuffix): BdD/DataAnodisation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BdD_DataAnodisation.cpp$(PreprocessSuffix) BdD/DataAnodisation.cpp

$(IntermediateDirectory)/BdD_DonneesIHM.cpp$(ObjectSuffix): BdD/DonneesIHM.cpp $(IntermediateDirectory)/BdD_DonneesIHM.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation/BdD/DonneesIHM.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BdD_DonneesIHM.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BdD_DonneesIHM.cpp$(DependSuffix): BdD/DonneesIHM.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BdD_DonneesIHM.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BdD_DonneesIHM.cpp$(DependSuffix) -MM BdD/DonneesIHM.cpp

$(IntermediateDirectory)/BdD_DonneesIHM.cpp$(PreprocessSuffix): BdD/DonneesIHM.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BdD_DonneesIHM.cpp$(PreprocessSuffix) BdD/DonneesIHM.cpp

$(IntermediateDirectory)/Client_Client.cpp$(ObjectSuffix): Client/Client.cpp $(IntermediateDirectory)/Client_Client.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation/Client/Client.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Client_Client.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Client_Client.cpp$(DependSuffix): Client/Client.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Client_Client.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Client_Client.cpp$(DependSuffix) -MM Client/Client.cpp

$(IntermediateDirectory)/Client_Client.cpp$(PreprocessSuffix): Client/Client.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Client_Client.cpp$(PreprocessSuffix) Client/Client.cpp

$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(ObjectSuffix): IHM/EvtFrameAide.cpp $(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation/IHM/EvtFrameAide.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(DependSuffix): IHM/EvtFrameAide.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(DependSuffix) -MM IHM/EvtFrameAide.cpp

$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(PreprocessSuffix): IHM/EvtFrameAide.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(PreprocessSuffix) IHM/EvtFrameAide.cpp

$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(ObjectSuffix): IHM/EvtFramePrincipal.cpp $(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation/IHM/EvtFramePrincipal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(DependSuffix): IHM/EvtFramePrincipal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(DependSuffix) -MM IHM/EvtFramePrincipal.cpp

$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(PreprocessSuffix): IHM/EvtFramePrincipal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(PreprocessSuffix) IHM/EvtFramePrincipal.cpp

$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(ObjectSuffix): IHM/EvtFrameApropos.cpp $(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation/IHM/EvtFrameApropos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(DependSuffix): IHM/EvtFrameApropos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(DependSuffix) -MM IHM/EvtFrameApropos.cpp

$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(PreprocessSuffix): IHM/EvtFrameApropos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(PreprocessSuffix) IHM/EvtFrameApropos.cpp

$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(ObjectSuffix): IHM/FramePrincipal.cpp $(IntermediateDirectory)/IHM_FramePrincipal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/nairo5913/Ozanam/Projet_chaine_anodisation/Git/Anodisation/Anodisation/IHM/FramePrincipal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(DependSuffix): IHM/FramePrincipal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(DependSuffix) -MM IHM/FramePrincipal.cpp

$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(PreprocessSuffix): IHM/FramePrincipal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_FramePrincipal.cpp$(PreprocessSuffix) IHM/FramePrincipal.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


