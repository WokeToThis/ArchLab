## ArchLab

### Ερώτημα 1:

Τύπος CPU: 'minor',1 core  
συχνότητα λειτουργίας : '1GHz'  
βασικές μονάδες:   
caches:L1,L2  
μνήμη 'DDR3_1600_8x8',2GB,2 memory channels  


### Ερώτημα 2:  
a)
>[system.voltage_domain]  
>type=VoltageDomain  
>eventq_index=0  
>voltage=3.3  
 
 >[system.cpu_cluster.cpus]
 >type=MinorCPU
 >[stats.txt]  
 >sim_freq                                 1000000000000                       # Frequency of simulated ticks  
 
 b) 
 
 >sim_seconds                                  0.000035                       # Number of seconds simulated  
 >sim_insts                                        5027                       # Number of instructions simulated  
 >host_inst_rate                                  26663                       # Simulator instruction rate (inst/s)  

 
c)

>system.cpu_cluster.cpus.committedInsts           5027                       # Number of instructions committed  
>system.cpu_cluster.cpus.committedOps             5831                       # Number of ops (including micro ops) committed  
>##Micro-ops are basically a way to turn CISC-instructions into RISC-instruction  

d)

>system.cpu_cluster.l2.tags.data_accesses         7804                       # Number of data accesses  

>[system.cpu_cluster.l2]  
>size=1048576  
>assoc=16  
>prefetch_on_access=false  
>write_buffers=8  
>data_latency=12  

### Ερώτημα 3:




