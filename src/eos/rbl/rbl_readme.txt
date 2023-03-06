RTOS Basic Layer (RBL)
The purpose is to build up a platform layer up to SOC baremental software or any RTOS/Linux. Any embedded software based on RBL can be easily ported and tested in windows or Linux envionment. 

The basic idea of RBL is to avoid name polution when an embedded system is compiled in PC-based OS such as Linux or Cygwin. For example: The embedded system will have its own printf which output char though UART, But when compile and run the embedded system on Cygwin, there is another version of printf from PC-based OS. When you really want the printf to output to screen, you need to differenciate those two kinds of printf. To do so, you can call rbl_printf which comes from RBL. 
RBL is a series of libaries in which rbl_printf will call the real printf from PC-based OS. In that way, you don't need to change the embeded version of printf.

The second idea is to replace all BSP API which to manipulate with CPU and SOC hardware with software stub function. The stub function will emulate all hardware behavior.In this way, you can derectly debug embedded software in PC-based OS

Why do we need to run embeded software on Cygwin? It's related to efficiency. The usally ways to debug are :

1.use simulator and hardware
2.use emulator such as Qemu

Both ways to debug is not convienent and quick as PC-based OS's application debug.