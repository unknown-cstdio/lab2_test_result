# lab2_test_result

bigstack:  
no output, should trigger trap memory.  
My TracePrintf relevent output (addr is actually vpn):  
Kernel   trap_memory_handler TRAP_MEMORY_MAPERR  
Kernel   trap_memory_handler TRAP_MEMORY_MAPERR: addr 501 is a valid brk addr  
Kernel   trap_memory_handler TRAP_MEMORY_MAPERR: brk 16  

blowstack:  
Input 50, got 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21  
and then stack too large and exit with -1  
My TracePrintf relevent output:  
Kernel   trap_memory_handler 1 at 0xaa2c  
Kernel   trap_memory_handler stack_vpn 27  
Kernel   trap_memory_handler TRAP_MEMORY_MAPERR  
Kernel   trap_memory_handler TRAP_MEMORY_MAPERR: addr 10 is not a valid stack addr  
Kernel   Exit called by process 7 with status -1  

brktest:  
sbrk(0) = 0x1d000  

delaytest:  
Starting delay...  
Delay finished!  

exectest:  
no output from exectest   

For all forktests, I think the order of output might change depending on  
Fork()'s implementation (whether contextswitch to child in fork).  

forktest0:  
no output  

forktest1/forktest1b:  
They are basically the same, with forktest1b prints the pid of parent and child  
output for forktest1b:  
FORK1> This program is a simple test of Fork()  
FORK1> BEFORE Fork(): If nothing else is printed, Fork fails   
PARENT 1  
CHILD 2  
FORK1 1> You should have seen "CHILD" and "PARENT" printed  
FORK1 1> in the order in which they were scheduled  
FORK1 1> If you missed one or the other, the kernel  
FORK1 1> does NOT switch contexts!!!  
  
forktest2/forktest2b:  
This program is a test primarily of Fork, Delay, and  
some user process stack growth  
PARENT: child pid = 2  
parent 20  
CHILD  
child 20  
child 19  
parent 19  
parent 18  
child 18  
child 17  
parent 17  
parent 16  
child 16  
child 15  
parent 15  
parent 14  
child 14  
child 13  
parent 13  
parent 12  
child 12  
child 11  
parent 11  
parent 10  
child 10  
child 9  
parent 9  
parent 8  
child 8  
child 7  
parent 7  
parent 6  
child 6  
child 5  
parent 5  
parent 4  
child 4  
child 3  
parent 3  
parent 2  
child 2  
child 1  
parent 1  
parent 0  
child 0  
Done with recursion  
FORK2 done.  
Done with recursion  
FORK2 done.  
  
forktest3:  
BEFORE  
PARENT: child pid = 2  
mem 0x1e008  
CHILD  
mem 0x1e008  
child 33  
mem 0x1e810  
parent 33  
mem 0x1e810  
parent 32  
mem 0x1f018  
child 32  
mem 0x1f018  
child 31    
mem 0x1f820  
parent 31   
mem 0x1f820  
parent 30    
mem 0x20028  
child 30    
mem 0x20028  
child 29    
mem 0x20830  
parent 29    
mem 0x20830  
parent 28    
mem 0x21038  
child 28    
mem 0x21038  
child 27    
mem 0x21840  
parent 27    
mem 0x21840  
parent 26    
mem 0x22048  
child 26    
mem 0x22048  
child 25    
mem 0x22850  
parent 25    
mem 0x22850  
parent 24    
mem 0x23058  
child 24    
mem 0x23058   
child 23    
mem 0x23860   
parent 23    
mem 0x23860   
parent 22   
mem 0x24068  
child 22    
mem 0x24068  
child 21    
mem 0x24870  
parent 21    
mem 0x24870  
parent 20    
mem 0x25078  
child 20    
mem 0x25078  
child 19    
mem 0x25880  
parent 19    
mem 0x25880   
parent 18    
mem 0x26088  
child 18    
mem 0x26088  
child 17    
mem 0x26890  
parent 17    
mem 0x26890  
parent 16    
mem 0x27098  
child 16    
mem 0x27098  
child 15    
mem 0x278a0  
parent 15    
mem 0x278a0  
parent 14    
mem 0x280a8  
child 14    
mem 0x280a8  
child 13    
mem 0x288b0  
parent 13    
mem 0x288b0  
parent 12    
mem 0x290b8  
child 12    
mem 0x290b8  
child 11    
mem 0x298c0   
parent 11    
mem 0x298c0  
parent 10    
mem 0x2a0c8  
child 10     
mem 0x2a0c8    
child 9         
mem 0x2a8d0           
parent 9      
mem 0x2a8d0       
parent 8         
mem 0x2b0d8          
child 8         
mem 0x2b0d8          
child 7        
mem 0x2b8e0        
parent 7           
mem 0x2b8e0         
parent 6         
mem 0x2c0e8         
child 6       
mem 0x2c0e8        
child 5      
mem 0x2c8f0        
parent 5        
mem 0x2c8f0          
parent 4         
mem 0x2d0f8          
child 4         
mem 0x2d0f8          
child 3        
mem 0x2d900          
parent 3       
mem 0x2d900        
parent 2        
mem 0x2e108        
child 2          
mem 0x2e108         
child 1          
mem 0x2e910         
parent 1          
mem 0x2e910          
parent 0         
Done with recursion           
child 0                   
Done with recursion               

forkwait0c:  
testing Wait before Exit  
parent Fork returned 2          
parent calling Wait               
child calling Delay(10)             
child calling Exit(123)               
wait returned pid2 2 status 123             

forkwait0p:              
testing Exit before Wait              
parent Fork returned 2            
parent calling Delay(10)            
child calling Exit(123)           
parent calling Wait                       
wait returned pid2 2 status 123               

forkwait1:                    
FORKWAIT> This program tests that Wait collects zombie processes         
FORKWAIT> If no more FORKWAIT output, Fork does not work         
FORKWAIT> PARENT: child pid = 2, &status = 0x1fae24          
FORKWAIT> CHILD about to exit with 1234567              
FORKWAIT> ABout to call Wait, if no further outpuit,            
FORKWAIT> then Wait failed ungracefully              
FORKWAIT> Wait returned pid 2 status 1234567            
FORKWAIT> GOOD!            

forwait2b:             
FORKWAIT> This program tests that Wait collects zombie processes          
FORKWAIT> If no more FORKWAIT output, Fork does not work          
FORKWAIT> PARENT: child pid = 2, &status = 0x1fae20          
FORKWAIT> CHILD about to exit with 1234567          
FORKWAIT> Wait returned pid 2 status 1234567        
FORKWAIT> GOOD!                                          
FORKWAIT> PARENT: child pid = 3, &status = 0x1fae20          
FORKWAIT> CHILD about to exit with 1234567      
FORKWAIT> Wait returned pid 3 status 1234567        
FORKWAIT> GOOD!       
FORKWAIT> PARENT: child pid = 4, &status = 0x1fae20  
FORKWAIT> CHILD about to exit with 1234567  
FORKWAIT> Wait returned pid 4 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> PARENT: child pid = 5, &status = 0x1fae20  
FORKWAIT> CHILD about to exit with 1234567  
FORKWAIT> Wait returned pid 5 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> PARENT: child pid = 6, &status = 0x1fae20  
FORKWAIT> CHILD about to exit with 1234567  
FORKWAIT> Wait returned pid 6 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> PARENT: child pid = 7, &status = 0x1fae20  
FORKWAIT> CHILD about to exit with 1234567  
FORKWAIT> Wait returned pid 7 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> PARENT: child pid = 8, &status = 0x1fae20  
FORKWAIT> CHILD about to exit with 1234567  
FORKWAIT> Wait returned pid 8 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> PARENT: child pid = 9, &status = 0x1fae20  
FORKWAIT> CHILD about to exit with 1234567  
FORKWAIT> Wait returned pid 9 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> PARENT: child pid = 10, &status = 0x1fae20  
FORKWAIT> CHILD about to exit with 1234567  
FORKWAIT> Wait returned pid 10 status 1234567  
FORKWAIT> GOOD!   
FORKWAIT> PARENT: child pid = 11, &status = 0x1fae20  
FORKWAIT> CHILD about to exit with 1234567  
FORKWAIT> Wait returned pid 11 status 1234567   
FORKWAIT> GOOD!    

forkwait1c:   
FORKWAIT> This program tests that Wait collects zombie processes   
FORKWAIT> If no more FORKWAIT output, Fork does not work   
FORKWAIT> PARENT: child pid = 2, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 3, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 4, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 5, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 6, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 7, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 8, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 9, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 10, &status = 0x1fae1c  
FORKWAIT> PARENT: child pid = 11, &status = 0x1fae1c  
FORKWAIT> CHILD 2 about to exit with 1234567  
FORKWAIT> CHILD 3 about to exit with 1234567  
FORKWAIT> CHILD 4 about to exit with 1234567  
FORKWAIT> CHILD 5 about to exit with 1234567  
FORKWAIT> CHILD 6 about to exit with 1234567  
FORKWAIT> CHILD 7 about to exit with 1234567  
FORKWAIT> CHILD 8 about to exit with 1234567  
FORKWAIT> CHILD 9 about to exit with 1234567  
FORKWAIT> CHILD 10 about to exit with 1234567  
FORKWAIT> CHILD 11 about to exit with 1234567  
FORKWAIT> Wait returned pid 2 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 3 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 4 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 5 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 6 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 7 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 8 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 9 status 1234567   
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 10 status 1234567  
FORKWAIT> GOOD!  
FORKWAIT> Wait returned pid 11 status 1234567  
FORKWAIT> GOOD!  
DONE!  

forkwait1d:   
FORKWAIT> This program tests that Wait collects zombie processes  
FORKWAIT> If no more FORKWAIT output, Fork does not work  
FORKWAIT 0> PARENT: child pid = 2, &status = 0x1fae20  
FORKWAIT 0> CHILD about to exit with 1234567  
FORKWAIT 0> Wait returned pid 2 status 1234567  
FORKWAIT 0> GOOD!  
FORKWAIT 1> PARENT: child pid = 3, &status = 0x1fae20  
FORKWAIT 1> CHILD about to exit with 1234567  
FORKWAIT 1> Wait returned pid 3 status 1234567  
FORKWAIT 1> GOOD!  
FORKWAIT 2> PARENT: child pid = 4, &status = 0x1fae20  
FORKWAIT 2> CHILD about to exit with 1234567  
FORKWAIT 2> Wait returned pid 4 status 1234567  
FORKWAIT 2> GOOD!  
FORKWAIT 3> PARENT: child pid = 5, &status = 0x1fae20  
FORKWAIT 3> CHILD about to exit with 1234567  
FORKWAIT 3> Wait returned pid 5 status 1234567  
FORKWAIT 3> GOOD!  
FORKWAIT 4> PARENT: child pid = 6, &status = 0x1fae20  
FORKWAIT 4> CHILD about to exit with 1234567  
FORKWAIT 4> Wait returned pid 6 status 1234567  
FORKWAIT 4> GOOD!  
FORKWAIT 5> PARENT: child pid = 7, &status = 0x1fae20  
FORKWAIT 5> CHILD about to exit with 1234567  
FORKWAIT 5> Wait returned pid 7 status 1234567  
FORKWAIT 5> GOOD!  
FORKWAIT 6> PARENT: child pid = 8, &status = 0x1fae20  
FORKWAIT 6> CHILD about to exit with 1234567  
FORKWAIT 6> Wait returned pid 8 status 1234567  
FORKWAIT 6> GOOD!  
FORKWAIT 7> PARENT: child pid = 9, &status = 0x1fae20  
FORKWAIT 7> CHILD about to exit with 1234567  
FORKWAIT 7> Wait returned pid 9 status 1234567  
FORKWAIT 7> GOOD!  
FORKWAIT 8> PARENT: child pid = 10, &status = 0x1fae20  
FORKWAIT 8> CHILD about to exit with 1234567  
FORKWAIT 8> Wait returned pid 10 status 1234567  
FORKWAIT 8> GOOD!  
FORKWAIT 9> PARENT: child pid = 11, &status = 0x1fae20  
FORKWAIT 9> CHILD about to exit with 1234567  
FORKWAIT 9> Wait returned pid 11 status 1234567  
FORKWAIT 9> GOOD!  

init:  
starts a console on terminal0 and 3 shell on other terminals  

init1:  
init!  

init2:  
(delay for some time)  
hello world  
this 5 is 10 a 15 test 20  

init3:  
hello world  
this 5 is 10 a 15 test 20  

trapillegal/trapmemory/trapmath:  
no output  

ttyread1:  
Doing TtyRead...  
Done with TtyRead: len 5  
line '<your input on terminal 0>  
'  
ttywrite1:  
On terminal 0:  
Hello World  

ttywrite2:  
On terminal0:  
Hello World  
Hello World  
Hello World  
Hello World  
Hello World  
Hello World  
Hello World  
Hello World  
Hello World  
Hello World  

ttywrite3:  
Parent line 0  
Child line 0  
Child line 1  
Parent line 1  
Child line 2  
Child line 3  
Parent line 2  
Child line 4  
Child line 5  
Parent line 3  
Child line 6  
Child line 7  
Parent line 4  
Child line 8  
Child line 9  
Parent line 5  
Parent line 6  
Parent line 7  
Parent line 8  
Parent line 9  
