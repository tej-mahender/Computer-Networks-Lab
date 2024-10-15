a) For Router1 open CLI in router1: 

Router>enable               
Router#configure terminal            
Router(config)#hostname R1             
R1(config)#interface FastEthernet0/0              
R1(config-if)#ip address 10.0.0.1 255.0.0.0            
R1(config-if)#no shutdown           
R1(config-if)#exit             
R1(config)#interface Serial0/0/0             
R1(config-if)#ip address 100.0.0.1 255.0.0.0              
R1(config-if)#clock rate 64000                 
R1(config-if)#bandwidth 64               
R1(config-if)#no shutdown            
R1(config-if)#exit                

b) For Router2 open CLI in router2: 

Router>enable                   
Router#configure terminal             
Router(config)#hostname R2         
R2(config)#interface FastEthernet0/0                  
R2(config-if)#ip address 192.168.1.1 255.255.255.0               
R2(config-if)#no shutdown             
R2(config-if)#exit                 
R2(config)#interface Serial0/0/0                   
R2(config-if)#ip address 100.0.0.2 255.0.0.0             
R2(config-if)#no shutdown               
R2(config-if)#exit                 

c) R1 Static NAT Configuration: 

R1(config)#ip nat inside source static 10.0.0.10 50.0.0.10              
R1(config)#interface FastEthernet0/0                    
R1(config-if)#ip nat inside                  
R1(config-if)#exit                       
R1(config)#interface Serial0/0/0                     
R1(config-if)#ip nat outside                      
R1(config-if)#exit                        

Configure the translation for remaining address:                       
R1(config)#ip nat inside source static 10.0.0.20 50.0.0.20                 
R1(config)#ip nat inside source static 10.0.0.30 50.0.0.30                      

d) R2 Static NAT Configuration: 

R2(config)#ip nat inside source static 192.168.1.10 200.0.0.10                    
R2(config)#interface FastEthernet0/0                   
R2(config-if)#ip nat inside                           
R2(config-if)#exit                     
R2(config)#interface Serial0/0/0                     
R2(config-if)#ip nat outside                       
R2(config-if)#exit                      

e) Configure static routing on R1:                     
R1(config)#ip route 200.0.0.0 255.255.255.0 100.0.0.2                     
Configure static routing on R2:                    
R2(config)#ip route 50.0.0.0 255.0.0.0 100.0.0.1                          

f) Test the configuration by running ipconfig and pinging 200.0.0.10 and 192.168.1.10 from Laptop0.                  
g) Verify NAT translations on routers with the show ip nat translation command.                      
