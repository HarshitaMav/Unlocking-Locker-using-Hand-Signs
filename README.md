# Unlocking-Locker-using-Hand-Signs

 **1. Aim:**  
 
   This project aims for unlocking the safe using specific series of hands and will have authentication for the same.  
   
 
 
 **2. Working:**  

  This system comprises of two parts transmitter and the reciever part.  
  
  **A. Transmitter:**  
  
   In this part of the system user need to wear gloves and will have to perform specific hand signs.
   This data is transmitted using RFID sensor. Also we have sensing unit which consist of MPU 6050 and flex sensor present on glove.
   Collected data will be transmitted towards receiver through NRF24L01 
      
  **B. Receiver:**  
  
   In this part of the system Receiver will collect data(Hand signs) send by Transmitter module and compare with existing provided data.
   If the sign is matched, Microcontroller will give command to open a safe.If it doesn’t,Microcontroller will trigger an alarm.
   This trigger can be turn off only by authenticated user only.

  In this system the data for comparison i.e. handsigns for authentication will already be feeded to the system, once the data is recieved
  system just has to compare with this data.
  
  
  
  
  **3. Components Used:**
       
   **Transmitter:**  
   
       i. Arduino Nano  
       ii. NRF24L01 RF Transceiver  
       iii. MPU 6050  
       iv. Flex sensor  
       
   **Receiver:**  
   
        i. Arduino Uno
        ii. NRF24L01 RF Transceiver
        iii. Solenoid Lock
        iv. Piezoelectric Alarm    
       
  
  
  
  **4. Circuit diagram:**  
  
  ![Image](https://github.com/aneeshKM/Unlocking-Locker-using-Hand-Signs/blob/main/Arduino%20FLex%20LCD%20Tilt%20Interface.png)
  
  


## Simulation for our project is in the link below:

[Link](https://www.tinkercad.com/embed/6cQAeb9IcAR?editbtn=1 "")


### Description of simulation:  

In the actual model we would be using RFID sensor, since that was not available for simulation we have made direct connections in the above simulation.
Also Flex sensor was also not available so we replaced that tilt sensor.


**Working of simulation:**  

1. Takes inputs from the tilt sensor and flex sensor.
2. This values are checked with the value already provided to simulation if it matches the system displays "Authenticated" otherwise displays "wrong sign"
3. If user gives wrong inputs 3 times in a row then buzzer starts beeping.
4. After buzzer beeping whole simulation need to be started from the beginning.
