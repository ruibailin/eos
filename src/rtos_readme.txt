1. Compile without EOS
   Just don't include and compile eos directory
2. Compile with EOS
   Please exclude the following files in STM32CubeIDE->Properties->C/C++ Generals->Paths And Symbols->Soruce Location
   a. /Application
   Src/App.c
   Src/Alarms.c
   b./Core
   Src/main.c