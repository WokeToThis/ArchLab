## ArchLab

### Ερώτημα 1:

Παράδειγμα Hello world!  
Βασικά χαρακτηριστικά που βρήκαμε στο starter_se.py(_Το αρχείο starter_se.py βρίσκεται στον Folder1_):  
Voltage="3.3V"  
Τύπος CPU: 'minor',1 core  
συχνότητα λειτουργίας : '1GHz'  
βασικές μονάδες:   
caches:L1,L2  
μνήμη 'DDR3_1600_8x8',2GB,2 memory channels  



### Ερώτημα 2:  
a)
Επαλήθευση από τα αρχεία config.ini και config.json(_Τα αρχεία βρίσκονται στον Folder1_):
>[system.voltage_domain]  
>type=VoltageDomain  
>eventq_index=0  
>voltage=3.3  
 
 >[system.cpu_cluster.cpus]
 >type=MinorCPU
 >[stats.txt]  
 >sim_freq                                 1000000000000                       # Frequency of simulated ticks  
 
>[system.cpu_cluster.l2]  
>size=1048576  
>assoc=16  
>prefetch_on_access=false  
>write_buffers=8  
>data_latency=12  
 
 b) 
 Τα sim_seconds είναι ο χρόνος που προσομοιώθηκε σε δευτερόλεπτα.  
 >sim_seconds                                  0.000035                       # Number of seconds simulated  
 
 Τα sim_insts είναι οι εντολές που προσομοιώθηκαν.  
 >sim_insts                                        5027                       # Number of instructions simulated  

 Το host_inst_rate είναι οι εντολές που εκτελεί ο gem5 στον host ανά δευτερόλεπτο.  
 >host_inst_rate                                  26663                       # Simulator instruction rate (inst/s)  

 
c)
Ενώ τα commited instructions είναι 5027(όσα και τα sim_insts), τα συνολικό νούμερο των commited εντολών είναι 5831 γιατί περιλαμβάνει και κάποια "micro ops" τα οποία χρησιμοποιούνται για να γίνουν κάποιες εντολές από CISC -> RISC.   
>system.cpu_cluster.cpus.committedInsts           5027                       # Number of instructions committed  
>system.cpu_cluster.cpus.committedOps             5831                       # Number of ops (including micro ops) committed  
>##Micro-ops are basically a way to turn CISC-instructions into RISC-instruction  

d)
Η L2 cache προσπελάστηκε 7804 φορές σύμφωνα με το stats.txt αρχείο.
>system.cpu_cluster.l2.tags.data_accesses         7804                       # Number of data accesses  



### Ερώτημα 3:

Τα βασικά  μοντέλα in-order CPUs είναι τα SimpleCPU και MinorCPU.

**SimpleCPU** (χωρίζονται σε):

* BaseSimpleCPU
* AtomicSimpleCPU
* TimingSimpleCPU

**BaseSimpleCPU**  
Έχει κάποιες βασικές συναρτήσεις που κληρονομεί στους υπόλοιπους τύπους SimpleCPU. Δεν τρέχει μόνο του.

**AtomicSimpleCPU**  
Χρησιμοποιεί atomic προσπελάσεις της μνήμης(γρηγορότερες απο αυτές της timing), σχεδόν άμεσες. Χρησιμοποιεί εκτιμήσεις του latency από αυτές τις προσπελάσιες για να υπολογίσει το συνολικό χρόνο προσπέλασης της cache. Κληρονομεί συναρτήσεις της BaseSimpleCPU.

**TimingSimpleCPU**  
Χρησιμοποιεί προσπελάσεις της μνήμης, πιο ρεαλιστικές, οι οποίες παίρνουν χρόνο να φτάσουν στον επεξεργαστή καθυστερώντας τα υπόλοιπα memory requests.  

Οι SimpleCPUs δεν χρησιμοποιούν pipeline.  

**MinorCPU**
Χρησιμοποιεί pipeline 4 σταδίων, τα οποία είναι Fetch1, Fetch2, Decode και Execute. Τα στάδια συνδέονται με FIFO buffers ώστε να μοντελοποιούνται οι καθυστερήσεις από stage σε stage. Είναι πιο ρεαλιστική από την TimingSimpleCPU και χρησιμοποιείται αυστηρά για να προσομοιώσει μοντέλα in-order CPU.

a.  
Το πρόγραμμα σε C που χρησιμοποιήσαμε είναι το _myprog.c_ και το εκτελέσαμε με τα μοντέλα TimingSimpleCPU και MinorCPU.  
Τα αποτελέσματα όσον αφορά τους χρόνους εκτέλεσης παραθέτονται παρακάτω:  

* Για το μοντέλο MinorCPU(_από το αρχείο stats.txt στον Folder2(minorcpu)_):  
>host_seconds                                     0.54                       # Real time elapsed on the host  
>sim_seconds                                  0.000126                       # Number of seconds simulated  
>sim_ticks                                   126343000                       # Number of ticks simulated  

* Για το μοντέλο TimingSimpleCPU(_από το αρχείο stats.txt στον Folder3(timingsimplecpu)_):  
>host_seconds                                     0.16                       # Real time elapsed on the host  
>sim_seconds                                  0.000326                       # Number of seconds simulated  
>sim_ticks                                   325873000                       # Number of ticks simulated  

b.  
Αν τα αποτελέσματα που παρατηρείτε διαφέρουν, με βάση όσα περιγράψατε για τα  
χαρακτηριστικά κάθε μοντέλου, δώστε μια εξήγηση των διαφορών που παρατηρείτε.  
Αντίστοιχα, για τα όμοια αποτελέσματα δικαιολογήστε γιατί τα σχετικά μοντέλα  
παράγουν το ίδιο αποτέλεσμα.  


c.  
 
**Πρώτα αλλάξαμε την συχνότητα σε 3GHz**  
* Για MinorCPU(_από το αρχείο stats.txt στον Ερ3,c/Minor_):  
>host_seconds                                     0.48                       # Real time elapsed on the host  
>sim_seconds                                  0.000088                       # Number of seconds simulated  
>sim_ticks                                    88223022                       # Number of ticks simulated  
Αυξάνοντας τη συχνότητα μειώνεται ο χρόνος της προσομοίωσης(εκτελείται πιο γρήγορα), από 0.000126 σε 0.000088 s.

* Για TimingSimpleCPU(_από το αρχείο stats.txt στον Ερ3,c/TimingSimple_):  
>host_seconds                                     0.16                       # Real time elapsed on the host  
>sim_seconds                                  0.000221                       # Number of seconds simulated  
>sim_ticks                                   220597515                       # Number of ticks simulated  
Αυξάνοντας τη συχνότητα μειώνεται ο χρόνος της προσομοίωσης(εκτελείται πιο γρήγορα), από 0.000326 σε 0.000221 s.

**Μετά αλλάξαμε την μνήμη σε DDR4_2400_8x8**
*  Για MinorCPU(_από το αρχείο stats.txt στον Ερ3,c/Memory/Minor_):  
>host_seconds                                     0.48                       # Real time elapsed on the host  
>sim_seconds                                  0.000126                       # Number of seconds simulated  
>sim_ticks                                   125847000                       # Number of ticks simulated  

*  Για TimingSimpleCPU(_από το αρχείο stats.txt στον Ερ3,c/Memory/TimingSimple_):  
>host_seconds                                     0.16                       # Real time elapsed on the host  
>sim_seconds                                  0.000326                       # Number of seconds simulated  
>sim_ticks                                   325607000                       # Number of ticks simulated  

Τα sim_seconds είναι ίδια με τα αρχικά και στις δυο περιπτώσεις αφού το cpu_clock επανήρθε στo 1GHz. Υπάρχει μία μικρή μείωση στα sim_ticks.
