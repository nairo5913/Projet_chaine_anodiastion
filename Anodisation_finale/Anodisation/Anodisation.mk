##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Anodisation
ConfigurationName      :=Release
WorkspacePath          :=/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale
ProjectPath            :=/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Florian PROVOST
Date                   :=12/06/2018
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
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Anodisation.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -s $(shell wx-config --debug=no --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). 
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
CXXFLAGS :=  -O2 -Wall $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/BdD_DataAnodisation.cpp$(ObjectSuffix) $(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(ObjectSuffix) $(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(ObjectSuffix) $(IntermediateDirectory)/Client_Client.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_PanelRegleur.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_PanelResponsable.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(ObjectSuffix) $(IntermediateDirectory)/IHM_FramePrincipal.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix): MyApp.cpp $(IntermediateDirectory)/MyApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/MyApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyApp.cpp$(DependSuffix): MyApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyApp.cpp$(DependSuffix) -MM MyApp.cpp

$(IntermediateDirectory)/MyApp.cpp$(PreprocessSuffix): MyApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyApp.cpp$(PreprocessSuffix) MyApp.cpp

$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(ObjectSuffix): BdD/DataAnodisation.cpp $(IntermediateDirectory)/BdD_DataAnodisation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/BdD/DataAnodisation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(DependSuffix): BdD/DataAnodisation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(DependSuffix) -MM BdD/DataAnodisation.cpp

$(IntermediateDirectory)/BdD_DataAnodisation.cpp$(PreprocessSuffix): BdD/DataAnodisation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BdD_DataAnodisation.cpp$(PreprocessSuffix) BdD/DataAnodisation.cpp

$(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(ObjectSuffix): BdD/DonneesIHMregleur.cpp $(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/BdD/DonneesIHMregleur.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(DependSuffix): BdD/DonneesIHMregleur.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(DependSuffix) -MM BdD/DonneesIHMregleur.cpp

$(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(PreprocessSuffix): BdD/DonneesIHMregleur.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BdD_DonneesIHMregleur.cpp$(PreprocessSuffix) BdD/DonneesIHMregleur.cpp

$(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(ObjectSuffix): BdD/DonneesIHMresponsable.cpp $(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/BdD/DonneesIHMresponsable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(DependSuffix): BdD/DonneesIHMresponsable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(DependSuffix) -MM BdD/DonneesIHMresponsable.cpp

$(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(PreprocessSuffix): BdD/DonneesIHMresponsable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BdD_DonneesIHMresponsable.cpp$(PreprocessSuffix) BdD/DonneesIHMresponsable.cpp

$(IntermediateDirectory)/Client_Client.cpp$(ObjectSuffix): Client/Client.cpp $(IntermediateDirectory)/Client_Client.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/Client/Client.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Client_Client.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Client_Client.cpp$(DependSuffix): Client/Client.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Client_Client.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Client_Client.cpp$(DependSuffix) -MM Client/Client.cpp

$(IntermediateDirectory)/Client_Client.cpp$(PreprocessSuffix): Client/Client.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Client_Client.cpp$(PreprocessSuffix) Client/Client.cpp

$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(ObjectSuffix): IHM/EvtFrameAide.cpp $(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/IHM/EvtFrameAide.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(DependSuffix): IHM/EvtFrameAide.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(DependSuffix) -MM IHM/EvtFrameAide.cpp

$(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(PreprocessSuffix): IHM/EvtFrameAide.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_EvtFrameAide.cpp$(PreprocessSuffix) IHM/EvtFrameAide.cpp

$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(ObjectSuffix): IHM/EvtFrameApropos.cpp $(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/IHM/EvtFrameApropos.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(DependSuffix): IHM/EvtFrameApropos.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(DependSuffix) -MM IHM/EvtFrameApropos.cpp

$(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(PreprocessSuffix): IHM/EvtFrameApropos.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_EvtFrameApropos.cpp$(PreprocessSuffix) IHM/EvtFrameApropos.cpp

$(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(ObjectSuffix): IHM/EvtPanelRegleur.cpp $(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/IHM/EvtPanelRegleur.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(DependSuffix): IHM/EvtPanelRegleur.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(DependSuffix) -MM IHM/EvtPanelRegleur.cpp

$(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(PreprocessSuffix): IHM/EvtPanelRegleur.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_EvtPanelRegleur.cpp$(PreprocessSuffix) IHM/EvtPanelRegleur.cpp

$(IntermediateDirectory)/IHM_PanelRegleur.cpp$(ObjectSuffix): IHM/PanelRegleur.cpp $(IntermediateDirectory)/IHM_PanelRegleur.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/IHM/PanelRegleur.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_PanelRegleur.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_PanelRegleur.cpp$(DependSuffix): IHM/PanelRegleur.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_PanelRegleur.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_PanelRegleur.cpp$(DependSuffix) -MM IHM/PanelRegleur.cpp

$(IntermediateDirectory)/IHM_PanelRegleur.cpp$(PreprocessSuffix): IHM/PanelRegleur.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_PanelRegleur.cpp$(PreprocessSuffix) IHM/PanelRegleur.cpp

$(IntermediateDirectory)/IHM_PanelResponsable.cpp$(ObjectSuffix): IHM/PanelResponsable.cpp $(IntermediateDirectory)/IHM_PanelResponsable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/IHM/PanelResponsable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_PanelResponsable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_PanelResponsable.cpp$(DependSuffix): IHM/PanelResponsable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_PanelResponsable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_PanelResponsable.cpp$(DependSuffix) -MM IHM/PanelResponsable.cpp

$(IntermediateDirectory)/IHM_PanelResponsable.cpp$(PreprocessSuffix): IHM/PanelResponsable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_PanelResponsable.cpp$(PreprocessSuffix) IHM/PanelResponsable.cpp

$(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(ObjectSuffix): IHM/EvtPanelResponsable.cpp $(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/IHM/EvtPanelResponsable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(DependSuffix): IHM/EvtPanelResponsable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(DependSuffix) -MM IHM/EvtPanelResponsable.cpp

$(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(PreprocessSuffix): IHM/EvtPanelResponsable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_EvtPanelResponsable.cpp$(PreprocessSuffix) IHM/EvtPanelResponsable.cpp

$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(ObjectSuffix): IHM/EvtFramePrincipal.cpp $(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/IHM/EvtFramePrincipal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(DependSuffix): IHM/EvtFramePrincipal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(DependSuffix) -MM IHM/EvtFramePrincipal.cpp

$(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(PreprocessSuffix): IHM/EvtFramePrincipal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_EvtFramePrincipal.cpp$(PreprocessSuffix) IHM/EvtFramePrincipal.cpp

$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(ObjectSuffix): IHM/FramePrincipal.cpp $(IntermediateDirectory)/IHM_FramePrincipal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/fprovost/Documents/Projet_chaine_anodisation/Git/Anodisation_finale/Anodisation/IHM/FramePrincipal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(DependSuffix): IHM/FramePrincipal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(DependSuffix) -MM IHM/FramePrincipal.cpp

$(IntermediateDirectory)/IHM_FramePrincipal.cpp$(PreprocessSuffix): IHM/FramePrincipal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IHM_FramePrincipal.cpp$(PreprocessSuffix) IHM/FramePrincipal.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


